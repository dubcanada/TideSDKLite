/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
***
* Copyright (c) 2008-2012 Appcelerator Inc.
* 
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*   http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
**/

#include "../tide.h"

namespace tide
{
    EventObject::EventObject(const char *type) :
        AccessorObject(type)
    {
        this->SetMethod("on", &EventObject::_AddEventListener);
        this->SetMethod("addEventListener", &EventObject::_AddEventListener);
        this->SetMethod("removeEventListener", &EventObject::_RemoveEventListener);

        Event::SetEventConstants(this);
    }

    EventObject::~EventObject()
    {
        this->RemoveAllEventListeners();
    }

    AutoPtr<Event> EventObject::CreateEvent(const std::string& eventName)
    {
        return new Event(AutoPtr<EventObject>(this, true), eventName);
    }

    void EventObject::AddEventListener(const char* event, KMethodRef callback)
    {
        Poco::FastMutex::ScopedLock lock(this->listenersMutex);
        listeners.push_back(new EventListener(event, callback));
    }

    void EventObject::AddEventListener(std::string& event, KMethodRef callback)
    {
        Poco::FastMutex::ScopedLock lock(this->listenersMutex);
        listeners.push_back(new EventListener(event, callback));
    }

    void EventObject::RemoveEventListener(std::string& event, KMethodRef callback)
    {
        Poco::FastMutex::ScopedLock lock(this->listenersMutex);

        EventListenerList::iterator i = this->listeners.begin();
        while (i != this->listeners.end())
        {
            EventListener* listener = *i;
            if (listener->Handles(event.c_str()) && listener->Callback()->Equals(callback))
            {
                this->listeners.erase(i);
                delete listener;
                break;
            }
            i++;
        }
    }

    void EventObject::RemoveAllEventListeners()
    {
        Poco::FastMutex::ScopedLock lock(this->listenersMutex);

        EventListenerList::iterator i = this->listeners.begin();
        while (i != this->listeners.end())
        {
            delete *i++;
        }

        this->listeners.clear();
    }

    void EventObject::FireEvent(const char* event)
    {
        FireEvent(event, ValueList());
    }

    void EventObject::FireEvent(const char* event, const ValueList& args)
    {
        // Make a copy of the listeners map here, because firing the event might
        // take a while and we don't want to block other threads that just need
        // too add event listeners.
        EventListenerList listenersCopy;
        {
            Poco::FastMutex::ScopedLock lock(this->listenersMutex);
            listenersCopy = listeners;
        }

        KObjectRef thisObject(this, true);
        EventListenerList::iterator li = listenersCopy.begin();
        while (li != listenersCopy.end())
        {
            EventListener* listener = *li++;
            if (listener->Handles(event))
            {
                try
                {
                    if (!listener->Dispatch(thisObject, args, true))
                    {
                        // Stop event dispatch if callback tells us
                        break;
                    }
                }
                catch (ValueException& e)
                {
                    this->ReportDispatchError(e.ToString());
                    break;
                }
            }
        }    
    }

    bool EventObject::FireEvent(std::string& eventName, bool synchronous)
    {
        AutoPtr<Event> event(this->CreateEvent(eventName));
        return this->FireEvent(event);
    }

    bool EventObject::FireEvent(AutoPtr<Event> event, bool synchronous)
    {
        // Make a copy of the listeners map here, because firing the event might
        // take a while and we don't want to block other threads that just need
        // too add event listeners.
        EventListenerList listenersCopy;
        {
            Poco::FastMutex::ScopedLock lock(listenersMutex);
            listenersCopy = listeners;
        }

        KObjectRef thisObject(this, true);
        EventListenerList::iterator li = listenersCopy.begin();
        while (li != listenersCopy.end())
        {
            EventListener* listener = *li++;
            if (listener->Handles(event->eventName.c_str()))
            {
                ValueList args(Value::NewObject(event));
                bool result = false;

                try
                {
                    result = listener->Dispatch(thisObject, args, synchronous);
                }
                catch (ValueException& e)
                {
                    this->ReportDispatchError(e.ToString());
                }

                if (synchronous && (event->stopped || !result))
                    return !event->preventedDefault;
            }
        }

        if (this != GlobalObject::GetInstance().get())
            GlobalObject::GetInstance()->FireEvent(event, synchronous);

        return !synchronous || !event->preventedDefault;
    }

    void EventObject::FireErrorEvent(std::exception& e)
    {
        FireEvent("error", ValueList(Value::NewString(e.what())));
    }

    void EventObject::_AddEventListener(const ValueList& args, KValueRef result)
    {
        std::string event;
        KMethodRef callback;

        if (args.size() > 1 && args.at(0)->IsString() && args.at(1)->IsMethod())
        {
            event = args.GetString(0);
            callback = args.GetMethod(1);
        }
        else if (args.size() > 0 && args.at(0)->IsMethod())
        {
            event = Event::ALL;
            callback = args.GetMethod(0);
        }
        else
        {
            throw ValueException::FromString("Incorrect arguments passed to addEventListener");
        }

        this->AddEventListener(event, callback);
        result->SetMethod(callback);
    }

    void EventObject::_RemoveEventListener(const ValueList& args, KValueRef result)
    {
        args.VerifyException("removeEventListener", "s m");

        std::string event(args.GetString(0));
        this->RemoveEventListener(event, args.GetMethod(1));
    }

    void EventObject::ReportDispatchError(std::string& reason)
    {
        this->logger()->Error("Failed to fire event: target=%s reason=%s",
            this->GetType().c_str(), reason.c_str());
    }

    EventListener::EventListener(std::string& targetedEvent, KMethodRef callback) :
        targetedEvent(targetedEvent),
        callback(callback)
    {
    }

    EventListener::EventListener(const char* targetedEvent, KMethodRef callback) :
        targetedEvent(targetedEvent),
        callback(callback)
    {
    }

    inline bool EventListener::Handles(const char* event)
    {
        return targetedEvent.compare(event) == 0 || targetedEvent == Event::ALL;
    }

    inline KMethodRef EventListener::Callback()
    {
        return this->callback;
    }

    bool EventListener::Dispatch(KObjectRef thisObject, const ValueList& args, bool synchronous)
    {
        KValueRef result = RunOnMainThread(this->callback, thisObject, args, synchronous);
        if (result->IsBool())
            return result->ToBool();
        return true;
    }
}
