# This file has been modified from its orginal sources.
#
# (c) 2012 Software in the Public Interest Inc (SPI)
# (c) 2012 David Pratt
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

import os.path as path
import sdk
import distutils.dir_util as dir_util
from tide import BuildConfig

build = BuildConfig(
    PRODUCT_VERSION = sdk.get_version(),
    PRODUCT_NAME = 'Titanium',
    PRODUCT_NAME1 = 'TideSDK',
    GLOBAL_NAMESPACE ='Ti',
    CONFIG_FILENAME = 'tiapp.xml',
    BUILD_DIR = path.abspath('build'),
    THIRD_PARTY_DIR = path.join(path.abspath('src'), 'thirdparty'),
    DISTRIBUTION_URL = 'api.appcelerator.net',
    CRASH_REPORT_URL = 'api.appcelerator.net/p/v1/app-crash-report'
)
EnsureSConsVersion(1,2,0)
EnsurePythonVersion(2,5)

build.set_tide_source_dir(path.abspath('src'))

build.titanium_source_dir = path.abspath('.')
build.titanium_sdk_dir = path.join(build.titanium_source_dir, 'sdk')

# This should only be used for accessing various
# scripts in the tide build directory. All resources
# should instead be built to build.dir
build.tide_build_dir = path.join(build.tide_source_dir, 'build')

build.env.Append(CPPPATH=[
    build.titanium_source_dir,
    build.tide_source_dir,
    build.tide_include_dir
])

# debug build flags
debug = ARGUMENTS.get('debug', 0)
if debug:
    build.env.Append(CPPDEFINES = ('DEBUG', 1))
    if build.is_win32():
        build.env.Append(CCFLAGS=['/Z7'])  # max debug
        build.env.Append(CPPDEFINES=('WIN32_CONSOLE', 1))
    else:
        build.env.Append(CPPFLAGS=['-g'])  # debug
else:
    build.env.Append(CPPDEFINES = ('NDEBUG', 1 ))
    if not build.is_win32():
        build.env.Append(CPPFLAGS = ['-O9']) # max optimizations
if build.is_win32():
    build.env.Append(CCFLAGS=['/EHsc', '/GR', '/MD'])
    build.env.Append(LINKFLAGS=['/DEBUG', '/PDB:${TARGET}.pdb'])

LIBTIDE_NAME = 'tide'

Export('build', 'debug', 'LIBTIDE_NAME')
targets = COMMAND_LINE_TARGETS
clean = 'clean' in targets or ARGUMENTS.get('clean', 0)
build.nopackage = ARGUMENTS.get('nopackage', 0)

if clean:
    print "Obliterating your build directory: %s" % build.dir
    if path.exists(build.dir):
        dir_util.remove_tree(build.dir)
    Exit(0)

# forcing a crash to test crash detection
if ARGUMENTS.get('test_crash', 0):
    build.env.Append(CPPDEFINES = ('TEST_CRASH_DETECTION', 1))

## Kroll *must not be required* for installation
SConscript('SConscript.thirdparty')
SConscript('src/installer/SConscript')

# After libtide builds, the environment will  link 
# against libtide, so anything that should be
# linked against libtide should be above this point.

SConscript('src/boot/SConscript', variant_dir=path.join(build.dir, 'objs', 'boot'), duplicate=0)
SConscript('src/libtide/SConscript', variant_dir=path.join(build.dir,'objs','libtide'), duplicate=0)

# Now that libtide is built add it as a default for
# all the following build steps.
build.env.Append(LIBS=[LIBTIDE_NAME])
build.env.Append(LIBPATH=[build.runtime_build_dir])

SConscript('src/lang/SConscript')

SConscript('src/modules/SConscript')
SConscript('SConscript.dist')
SConscript('SConscript.docs')
SConscript('SConscript.test')

run = ARGUMENTS.get('run', 0)
run_with = ARGUMENTS.get('run_with', 0)

Export('run','run_with')
SConscript('tools/SConscript')
