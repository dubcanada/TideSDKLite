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

#include <iostream>
#include <string>
#include <vector>
#include <gtk/gtk.h>
#include <glib.h>
#include <utils.h>

using namespace KrollUtils;
using KrollUtils::Application;
using KrollUtils::SharedApplication;
using KrollUtils::KComponentType;
using std::string;
using std::vector;
class Installer;
class Job;
#include "job.h"

class Installer
{
    public:
    static Installer* instance;
    static string applicationPath;
    static string systemRuntimeHome;
    static string userRuntimeHome;
    static string updateFilename;

    Installer(vector<Job*>, int);
    ~Installer();
    void ResizeWindow(int width, int height);
    void CreateIntroView();
    void CreateProgressView();
    void CreateInfoBox(GtkWidget*);
    GdkPixbuf* GetApplicationPixbuf(int maxDimension);
    GtkWidget* GetTitaniumIcon();
    GtkWidget* GetApplicationIcon();

    void StartInstallProcess();
    void StartDownloading();
    void StartInstalling();
    void UpdateProgress();
    void ShowError();
    void Finish();

    GtkWidget* GetWindow() { return this->window; }
    void SetWindow(GtkWidget* w) { this->window = w; }
    void Cancel();

    enum Stage
    {
        SUCCESS = 0,
        PREDOWNLOAD,
        DOWNLOADING,
        PREINSTALL,
        INSTALLING,
        CANCEL_REQUEST,
        SUDO_REQUEST,
        CANCELLED,
        ERROR
    };

    Stage GetStage()
    {
        return this->stage;
    }

    void SetStage(Stage stage)
    {
        this->stage = stage;
    }

    void SetError(string error)
    {
        this->error = error;
        this->stage = ERROR;
    }

    Job* CurrentJob()
    {
        return this->currentJob;
    }

    void SetCurrentJob(Job* job)
    {
        this->currentJob = job;
    }

    vector<Job*>& GetJobs()
    {
        return this->jobs;
    }

    int GetType()
    {
        return this->installType;
    }


    private:
    vector<Job*> jobs;
    SharedApplication app;
    int installType;
    Stage stage;

    Job* currentJob;
    string error;
    GtkWidget* window;
    GtkWidget* progressBar;
    GtkWidget* downloadingLabel;
    GtkWidget* installCombo;
    bool running;
    GThread* download_thread;

};
