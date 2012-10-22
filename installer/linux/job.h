/**
* This file has been modified from its orginal sources.
*
* (c) 2012 Software in the Public Interest Inc (SPI)
* (c) 2012 David Pratt
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
* (c) 2008-2012 Appcelerator Inc.
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

#include <curl/curl.h>
#define COMPONENT_JOB 0
#define APPLICATION_JOB 1

class Job
{
    public:
    Job(std::string url, int type = COMPONENT_JOB);
    void Fetch();
    void Unzip();
    std::string GetFilename();
    int GetIndex();
    void SetProgress(double progress);
    double GetProgress();
    void ParseURL(std::string url);
    void ParseFile(std::string url);
    Installer* GetInstaller();

    static int total;
    static void InitDownloader();
    static void ShutdownDownloader();

    static std::string temporaryDirectory;
    static std::string installDirectory;

    int Index()
    {
        return this->index;
    }

    private:
    std::string url;
    int type;
    int index;
    std::string out_filename;
    double progress;
    KComponentType componentType;
    std::string name;
    std::string version;
    bool download;

    static CURL *curl;
    static char* curl_error;
    void UnzipComponent();
    void UnzipApplication();
};
