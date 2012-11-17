/**
 * Appcelerator - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */

#include "properties_binding.h"
#include <Poco/StringTokenizer.h>
#include <Poco/File.h>

using Poco::Util::TidePropertyFileConfiguration;

namespace ti
{

PropertiesBinding::PropertiesBinding(const std::string& filePath) :
	StaticBoundObject("App.Properties"),
	logger(Logger::Get("App.Properties")),
	filePath(filePath)
{
	if (!filePath.empty())
	{
		Poco::File file(filePath);
		if (!file.exists()) 
			file.createFile();

		config = new TidePropertyFileConfiguration(filePath);
	}
	else
	{
		config = new TidePropertyFileConfiguration();
	}

	SetMethod("getBool", &PropertiesBinding::GetBool);
	SetMethod("getDouble", &PropertiesBinding::GetDouble);
	SetMethod("getInt", &PropertiesBinding::GetInt);
	SetMethod("getString", &PropertiesBinding::GetString);
	SetMethod("getList", &PropertiesBinding::GetList);
	SetMethod("setBool", &PropertiesBinding::SetBool);
	SetMethod("setDouble", &PropertiesBinding::SetDouble);
	SetMethod("setInt", &PropertiesBinding::SetInt);
	SetMethod("setString", &PropertiesBinding::SetString);
	SetMethod("setList", &PropertiesBinding::SetList);
	SetMethod("hasProperty", &PropertiesBinding::HasProperty);
	SetMethod("removeProperty", &PropertiesBinding::RemoveProperty);
	SetMethod("listProperties", &PropertiesBinding::ListProperties);
	SetMethod("saveTo", &PropertiesBinding::SaveTo);
}

void PropertiesBinding::SaveConfig()
{
	if (!filePath.empty())
		config->save(filePath);
}

void PropertiesBinding::Getter(const ValueList& args, ValueRef result, Type type)
{
	std::string eprefix = "PropertiesBinding::Get: ";
	try
	{
		std::string property = args.at(0)->ToString();
		if (args.size() == 1)
		{
			switch (type)
			{
				case Bool: 
					result->SetBool(config->getBool(property));
					break;
				case Double:
					result->SetDouble(config->getDouble(property));
					break;
				case Int:
					result->SetInt(config->getInt(property));
					break;
				case String:
					result->SetString(config->getString(property).c_str());
					break;
				default:
					break;
			}
			return;
		}
		else if (args.size() >= 2)
		{
			switch (type)
			{
				case Bool:
					result->SetBool(config->getBool(property, args.at(1)->ToBool()));
					break;
				case Double:
					result->SetDouble(config->getDouble(property, args.at(1)->ToDouble()));
					break;
				case Int:
					result->SetInt(config->getInt(property, args.at(1)->ToInt()));
					break;
				case String:
					result->SetString(config->getString(property, args.at(1)->ToString()).c_str());
					break;
				default: break;
			}
			return;
		}
	}
	catch(Poco::Exception &e)
	{
		throw ValueException::FromString(eprefix + e.displayText());
	}
}

void PropertiesBinding::Setter(const ValueList& args, Type type)
{
	std::string eprefix = "PropertiesBinding::Set: ";
	try
	{
		std::string property = args.at(0)->ToString();
		switch (type)
		{
			case Bool:
				config->setBool(property, args.at(1)->ToBool());
				break;
			case Double:
				config->setDouble(property, args.at(1)->ToDouble());
				break;
			case Int:
				config->setInt(property, args.at(1)->ToInt());
				break;
			case String:
				config->setString(property, args.at(1)->ToString());
				break;
			case List: {
				ValueRef result;
				this->SetList(args, result);
			}
			default: break;
		}

		this->SaveConfig();
	}
	catch(Poco::Exception &e)
	{
		throw ValueException::FromString(eprefix + e.displayText());
	}
}

void PropertiesBinding::GetBool(const ValueList& args, ValueRef result)
{
	args.VerifyException("getBool", "s");
	Getter(args, result, Bool);
}

void PropertiesBinding::GetDouble(const ValueList& args, ValueRef result)
{
	args.VerifyException("getDouble", "s");
	Getter(args, result, Double);
}

void PropertiesBinding::GetInt(const ValueList& args, ValueRef result)
{
	args.VerifyException("getInt", "s");
	Getter(args, result, Int);
}

void PropertiesBinding::GetString(const ValueList& args, ValueRef result)
{
	args.VerifyException("getString", "s");
	Getter(args, result, String);
}

void PropertiesBinding::GetList(const ValueList& args, ValueRef result)
{
	args.VerifyException("getList", "s");
	ValueRef stringValue = Value::Null;
	GetString(args, stringValue);

	if (!stringValue->IsNull())
	{
		TiListRef list = new StaticBoundList();
		std::string string = stringValue->ToString();
		Poco::StringTokenizer t(string, ",", Poco::StringTokenizer::TOK_TRIM);
		for (size_t i = 0; i < t.count(); i++)
		{
			ValueRef token = Value::NewString(t[i].c_str());
			list->Append(token);
		}

		TiListRef list2 = list;
		result->SetList(list2);
	}
}

void PropertiesBinding::SetBool(const ValueList& args, ValueRef result)
{
	args.VerifyException("setBool", "s b");
	Setter(args, Bool);
}

void PropertiesBinding::SetDouble(const ValueList& args, ValueRef result)
{
	args.VerifyException("setDouble", "s n");
	Setter(args, Double);
}

void PropertiesBinding::SetInt(const ValueList& args, ValueRef result)
{
	args.VerifyException("setInt", "s n");
	Setter(args, Int);
}

void PropertiesBinding::SetString(const ValueList& args, ValueRef result)
{
	args.VerifyException("setString", "s s");
	Setter(args, String);
}

void PropertiesBinding::SetList(const ValueList& args, ValueRef result)
{
	args.VerifyException("setList", "s l");

	std::string property = args.at(0)->ToString();
	TiListRef list = args.at(1)->ToList();

	std::string value = "";
	for (unsigned int i = 0; i < list->Size(); i++)
	{
		ValueRef arg = list->At(i);
		if (arg->IsString())
		{
			value += list->At(i)->ToString();
			if (i < list->Size() - 1)
			{
				value += ",";
			}
		}
		else
		{
			logger->Warn("Skipping list entry %ui, not a string", i);
		}
	}
	config->setString(property, value);
	this->SaveConfig();
	
}

void PropertiesBinding::HasProperty(const ValueList& args, ValueRef result)
{
	args.VerifyException("hasProperty", "s");
	result->SetBool(config->hasProperty(args.GetString(0)));
}

void PropertiesBinding::RemoveProperty(const ValueList& args, ValueRef result)
{
	args.VerifyException("removeProperty", "s");
	result->SetBool(config->removeProperty(args.GetString(0)));
}

void PropertiesBinding::ListProperties(const ValueList& args, ValueRef result)
{
	std::vector<std::string> keys;
	config->keys(keys);

	TiListRef property_list = new StaticBoundList();
	for (size_t i = 0; i < keys.size(); i++)
	{
		std::string property_name = keys.at(i);
		ValueRef name_value = Value::NewString(property_name.c_str());
		property_list->Append(name_value);
	}
	result->SetList(property_list);
}

void PropertiesBinding::SaveTo(const ValueList& args, ValueRef result)
{
	args.VerifyException("saveTo", "s");

	this->filePath = args.at(0)->ToString();
	this->SaveConfig();
}

}
