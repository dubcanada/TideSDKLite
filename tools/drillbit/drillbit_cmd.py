#!/usr/bin/env python
"""
(c) 2008-2012 Appcelerator Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
"""

import os
import sys
import shutil
import platform
import subprocess


def run(args,env=None,cwd=None):
    return subprocess.call(args, cwd=cwd)
    #args = [arg.replace(" ", "\\ ") for arg in args]
    #p = subprocess.Popen(" ".join(args), cwd=cwd, shell=True)
    #return os.waitpid(p.pid, 0)

contents_dir = os.path.dirname(os.path.abspath(__file__))

manifest = os.path.join(contents_dir,'manifest')
manifest_cmdline = os.path.join(contents_dir,'manifest_cmdline')
manifest_backup = os.path.join(contents_dir,'manifest_backup')

shutil.copy(manifest, manifest_backup)
shutil.copy(manifest_cmdline, manifest)

open(os.path.join(contents_dir, '.installed'),'w').write('#')

exe = None
if platform.system() == "Windows":
    exe = os.path.join(contents_dir, 'Drillbit.exe')
elif platform.system() == "Darwin":
    exe = os.path.join(contents_dir, 'MacOS', 'Drillbit')
else:
    exe = os.path.join(contents_dir, 'Drillbit')

args = [exe]
args.extend(sys.argv[1:])
run(args, cwd=os.getcwd())

shutil.copy(manifest_backup, manifest)
