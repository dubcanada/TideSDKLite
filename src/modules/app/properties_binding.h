/**
 * Appcelerator - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008-2010 Appcelerator, Inc. All Rights Reserved.
 */

#ifndef PROPERTIES_BINDING_H_
#define PROPERTIES_BINDING_H_

#include <tide/tide.h>
#include <Poco/AutoPtr.h>
#include "TidePropertyFileConfiguration.h"

namespace ti
{
	class PropertiesBinding : public tide::StaticBoundObject
	{
	public:
		typedef enum { Bool, Double, Int, String, List } Type;

		PropertiesBinding(const std::string& file_path = "");
		virtual ~PropertiesBinding() {}

		void GetBool(const ValueList& args, ValueRef result);
		void GetDouble(const ValueList& args, ValueRef result);
		void GetInt(const ValueList& args, ValueRef result);
		void GetString(const ValueList& args, ValueRef result);
		void GetList(const ValueList& args, ValueRef result);
		void SetBool(const ValueList& args, ValueRef result);
		void SetDouble(const ValueList& args, ValueRef result);
		void SetInt(const ValueList& args, ValueRef result);
		void SetString(const ValueList& args, ValueRef result);
		void SetList(const ValueList& args, ValueRef result);
		void HasProperty(const ValueList& args, ValueRef result);
		void RemoveProperty(const ValueList& args, ValueRef result);
		void ListProperties(const ValueList& args, ValueRef result);
		void SaveTo(const ValueList& args, ValueRef result);
		void Getter(const ValueList& args, ValueRef result, Type type);
		void Setter(const ValueList& args, Type type);
		void SaveConfig();

		Poco::AutoPtr<Poco::Util::TidePropertyFileConfiguration> GetConfig()
		{
			return config;
		}

	protected:
		Logger* logger;
		std::string filePath;
		Poco::AutoPtr<Poco::Util::TidePropertyFileConfiguration> config;
	};
}

#endif
