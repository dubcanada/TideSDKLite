#!/usr/bin/env python

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

import os, sys, simplejson, platform
platforms = { 'Darwin': 'osx', 'Windows': 'win32', 'Linux': 'linux' }
cwd = os.path.abspath(os.path.dirname(__file__))
json = os.path.join(cwd, '..', 'build', platforms[platform.system()], 'testcoverage.json')

if not os.path.exists(json):
    print >>sys.stderr, "Error: testcoverage.json doesn't exist. Please run drillbit with all tests, and then run scons testcoverage"
    exit(-1)

c = simplejson.loads(open(json,'r').read())

coverage = c['coverage']
total = c['total']
p = ((coverage/float(total)) * 100)
print 'Total Coverage: %d of %d (%d%%) API' % (coverage,total,p)
print 'Module Coverage'
for module in c['modules'].keys():
    m = c['modules'][module]
    coverage = m['coverage']
    total = m['total']
    p = ((coverage/float(total)) * 100)
    print '  %s: %d of %d (%d%%) API' % (module,coverage,total,p)