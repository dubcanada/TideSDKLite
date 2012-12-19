/**
* This file has been modified from its orginal sources.
*
* Copyright (c) 2012 Software in the Public Interest Inc (SPI)
* Copyright (c) 2012 David Pratt
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

#include <tideutils/file_utils.h>
#include <tideutils/url_utils.h>
#ifdef OS_WIN32
#include <tideutils/win/win32_utils.h>
#else
#include <tideutils/posix/posix_utils.h>
#endif
using namespace TideUtils;

#include <tide/url_utils.h>
#include <tide/tide.h>
#include <Poco/URI.h>
#include <Poco/TemporaryFile.h>
#include <Poco/FileStream.h>

namespace TideUtils
{
namespace URLUtils
{
    static std::string NormalizeAppURL(const std::string& url)
    {
        size_t appLength = 6; // app://
        std::string id(Host::GetInstance()->GetApplication()->id);
        size_t idLength = id.size();
        std::string idPart(url.substr(appLength, idLength));

        if (idPart == id)
        {
            return url;
        }
        else
        {
            return std::string("app://") + id + "/" + url.substr(appLength);
        }
    }

    std::string& BlankPageURL()
    {
        static std::string url("app://__blank__.html");
        return url;
    }

    static std::string& BlankURLToFilePath()
    {
        static std::string path;
        if (path.empty())
        {
            Poco::TemporaryFile temp;
            temp.keepUntilExit();
            path = temp.path();

            std::string contents("<html><body></body></html>");
            Poco::FileStream stream;
            stream.open(path, std::ios::out);
            stream.write(contents.c_str(), contents.size());
            stream.close();
        }
        return path;
    }

    std::string NormalizeURL(const std::string& url)
    {
        Poco::URI inURI = Poco::URI(url);
        if (url == BlankPageURL())
        {
            return url;
        }
        if (inURI.getScheme() != "app")
        {
            return url;
        }
        else
        {
            return NormalizeAppURL(url);
        }
    }

    std::string URLToPath(const std::string& url)
    {
        Poco::URI inURI = Poco::URI(url);
        try
        {
            if (url == BlankPageURL())
            {
                return BlankURLToFilePath();
            }
            if (inURI.getScheme() == "ti")
            {
                return TiURLToPath(url);
            }
            else if (inURI.getScheme() == "app")
            {
                return AppURLToPath(url);
            }
            else if (inURI.getScheme().empty())
            {
                // There is no scheme for this URL, so we have to/ guess at this point if
                // it's a path or a relative app:// URL. If a file can be found, assume thi
                // is a file path.
                if (FileUtils::IsFile(url))
                    return url;

                // Otherwise treat this like an app:// URL relative to the root.
                std::string newURL("app://");
                newURL.append(url);
                return AppURLToPath(newURL);
            }
        }
        catch (ValueException& e)
        {
            SharedString ss = e.DisplayString();
            Logger* log = Logger::Get("URLUtils");
            log->Error("Could not convert %s to a path: %s", url.c_str(), ss->c_str());
        }
        return url;
    }

    std::string TiURLToPath(const std::string& tiURL)
    {
        try
        {
            Poco::URI inURI = Poco::URI(tiURL);

            if (inURI.getScheme() != "ti")
            {
                return tiURL;
            }

            std::string host(inURI.getHost());
            SharedApplication app = Host::GetInstance()->GetApplication();
            std::string path(app->GetComponentPath(host));

            if (path.empty())
            {
                throw ValueException::FromString("Could not find component "+host);
            }

            std::vector<std::string> segments;
            inURI.getPathSegments(segments);

            for (size_t i = 0; i < segments.size(); i++)
            {
                path = FileUtils::Join(path.c_str(), segments[i].c_str(), NULL);
            }
            return path;
        }
        catch (ValueException& e)
        {
            SharedString ss = e.DisplayString();
            Logger* log = Logger::Get("URLUtils");
            log->Error("Could not convert %s to a path: %s", tiURL.c_str(), ss->c_str());
        }
        catch (...)
        {
            Logger* log = Logger::Get("URLUtils");
            log->Error("Could not convert %s to a path", tiURL.c_str());
        }
        return tiURL;
    }

    std::string AppURLToPath(const std::string& inURL)
    {
        try
        {
            Poco::URI inURI = Poco::URI(inURL);
            if (inURI.getScheme() != "app")
            {
                return inURL;
            }

            std::string appURL(NormalizeAppURL(inURL));
            inURI = Poco::URI(appURL);

            SharedApplication app = Host::GetInstance()->GetApplication();
            std::string path(app->GetResourcesPath());

            std::vector<std::string> segments;
            inURI.getPathSegments(segments);
            for (size_t i = 0; i < segments.size(); i++)
            {
                path = FileUtils::Join(path.c_str(), segments[i].c_str(), NULL);
            }
            return path;
        }
        catch (ValueException& e)
        {
            SharedString ss = e.DisplayString();
            Logger* log = Logger::Get("URLUtils");
            log->Error("Could not convert %s to a path: %s", inURL.c_str(), ss->c_str());
        }
        catch (...)
        {
            Logger* log = Logger::Get("URLUtils");
            log->Error("Could not convert %s to a path", inURL.c_str());
        }

        return inURL;
    }
}
}
