/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 Mital Vora
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


#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/foreach.hpp>

#include <cassert>
#include <exception>
#include <iostream>
#include <sstream>
#include <string>

#include <tideutils/app_manifest.h>

namespace TideUtils
{
    AppManifest::AppManifest(const std::string& manifestPath_)
      : manifestPath(manifestPath_)
    {
      this->parseManifest();
    }

    AppManifest::~AppManifest()
    {
    }

    void AppManifest::parseManifest()
    {

    }
}
