#! /usr/bin/env python

# (c) 2008-2012 Appcelerator Inc.
# 
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
"Replace CRLF with LF in argument files.  Print names of changed files."

import sys, os

def main():
    for filename in sys.argv[1:]:
        if os.path.isdir(filename):
            print filename, "Directory!"
            continue
        data = open(filename, "rb").read()
        if '\0' in data:
            print filename, "Binary!"
            continue
        newdata = data.replace("\r\n", "\n")
        if newdata != data:
            print filename
            f = open(filename, "wb")
            f.write(newdata)
            f.close()

if __name__ == '__main__':
    main()
