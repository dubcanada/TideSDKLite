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

from boto.s3.connection import S3Connection
from boto.s3.key import Key
from progressbar import ProgressBar
import sys
import os
import time

acctid = None
secret = None
if len(sys.argv) < 2:
    print "Usage: upload_thirdparty.py <file.tgz> [<access key> <secret key>]"
    exit()
else:
    fname = sys.argv[1]
    if len(sys.argv) >= 4:
        acctid = sys.argv[2]
        secret = sys.argv[3]

if acctid is None:
    acctid = raw_input("AWS_ACCESS_KEY_ID: ").strip()

if secret is None:
    secret = raw_input("AWS_SECRET_ACCESS_KEY: ").strip()

bucket = "kroll.appcelerator.com"
key = os.path.basename(fname)
conn = S3Connection(acctid, secret)
bucket = conn.get_bucket(bucket)
k = bucket.new_key(key)

pbar = ProgressBar().start()
try:
    def progress_callback(current, total):
        pbar.update(int(100 * (float(current) / float(total))))
    k.set_contents_from_filename(fname, cb=progress_callback, num_cb=100, policy='public-read')
finally:
    pbar.finish()
