#!/usr/bin/python

# This file has been modified from its orginal sources.
#
# Copyright (c) 2012 Software in the Public Interest Inc (SPI)
# Copyright (c) 2012 David Pratt
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

# Copyright (c) 2008-2012 Appcelerator Inc.
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

# Simple script that gathers all the test results from drillbit and
# spits out the results on stdout in JSON

import os
import sys

scriptDir = os.path.dirname(__file__)
sys.path.append(os.path.join(scriptDir, "..", "site_scons"))

import simplejson

if len(sys.argv) < 2:
    print >>sys.stderr, "Usage: %s [drillbit-results-dir]" % sys.argv[0]
    sys.exit(-1)

resultsDir = sys.argv[1]

results = {}
for file in os.listdir(resultsDir):
    if file[len(file)-5:] == ".json" and file != "drillbit.json":
        test = file[0:len(file)-5]
        result = simplejson.load(open(os.path.join(resultsDir, file), 'r'))
        results[test] = result

print simplejson.dumps(results)
