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

# quick and dirty hack to generate markdown

import os, sys
import simplejson as json

data = open(sys.argv[1],'r').read()
data = json.loads(data)

c = 0

for module in sorted(data):
    print "* \"Titanium.%s\":#C%i" % (module,c)
    c+=1

print "\n"

c = 0
x = 0

for module in sorted(data):
    print "h1(#C%i). Titanium.%s" % (c,module)
    print "\n"
    c+=1

    for api in sorted(data[module]):
        api_data = data[module][api]
        print "* \"Titanium.%s.%s\":#X%i" % (module,api,x)
        x+=1
    
    x = 0
    print "\n"
    
    for api in sorted(data[module]):
        api_data = data[module][api]
        print "h2(#X%i). Titanium.%s.%s" % (x,module,api)
        print "\n"
        x+=1
        print "%s\n" % api_data['description']
        if api_data.has_key('method'):
            print "\narguments:\n"
            if api_data.has_key('arguments') and len(api_data['arguments'])>0:
                for arg in api_data['arguments']:
                    print "* %s (%s) - %s" % (arg['name'],arg['type'],arg['description'])
            else:
                print "none\n"
        print "\n"
        if api_data.has_key('returns') and api_data['returns']!=None:
            returns = api_data['returns']
            print "returns:\n\n%s - %s" % (returns['type'],returns['description'])
        else:
            print "returns:\n\nvoid"
            
        print "\n"
        print "since: %s" % api_data['since']
        print "\n"