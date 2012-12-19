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

#ifndef _TIDE_APP_MANIFEST_H_
#define _TIDE_APP_MANIFEST_H_

#include <tideutils/base.h>

namespace TideUtils
{
  /**
   * Represents a Tide App Manifest class which holds all manifest data.
   */
  class TIDE_UTILS_API AppManifest
  {
    public:
      AppManifest(const std::string& manifestPath);
      ~AppManifest();

    private:
      void parseManifest();

      const std::string manifestPath;
  };
}

#endif
