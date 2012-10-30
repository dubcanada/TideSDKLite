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

#include <Poco/Semaphore.h>
#include "tide.h"

namespace kroll
{

    MainThreadJob::MainThreadJob(KMethodRef method, KObjectRef thisObject,
        const ValueList& args, bool waitForCompletion) :
        method(method),
        thisObject(thisObject),
        args(args),
        waitForCompletion(waitForCompletion),
        returnValue(NULL),
        exception(ValueException(NULL)),
        semaphore(0, 1)
    {
        // The semaphore starts at 0, meaning that the calling
        // thread can wait for the value to become >0 using wait()
        // and the main thread can call set() after job execution
        // which meets this condition.
    }

    void MainThreadJob::Wait()
    {
        if (this->waitForCompletion)
            this->semaphore.wait();
    }

    void MainThreadJob::Execute()
    {
        try
        {
            if (thisObject.isNull())
                this->returnValue = this->method->Call(this->args);
            else
                this->returnValue = this->method->Call(thisObject, this->args);
        }
        catch (ValueException& e)
        {
            this->exception = e;
        }
        catch (Poco::SystemException& e)
        {
            this->exception = ValueException::FromString(e.displayText());
        }
        catch (std::exception& e)
        {
            this->exception = ValueException::FromString(e.what());
        }
        catch (...)
        {
            this->exception = ValueException::FromString("Unknown Exception from job queue");
        }

        if (this->waitForCompletion)
            this->semaphore.set();
    }

    KValueRef MainThreadJob::GetResult()
    {
        return this->returnValue;
    }

    ValueException MainThreadJob::GetException()
    {
        return this->exception;
    }

    bool MainThreadJob::ShouldWaitForCompletion()
    {
        return this->waitForCompletion;
    }

    void MainThreadJob::PrintException()
    {
        static Logger* logger = Logger::Get("Host");
        if (this->returnValue.isNull())
        {
            logger->Error("Error in the job queue: %s",
                this->exception.ToString().c_str());
        }
    }
}
