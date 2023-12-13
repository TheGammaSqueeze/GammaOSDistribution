# Copyright 2020 Google Inc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
################################################################################
"""Utility functions for testing cloud functions."""
import datetime
import os
import subprocess
import threading

import requests

DATASTORE_READY_INDICATOR = b'is now running'
DATASTORE_EMULATOR_PORT = 8432
EMULATOR_TIMEOUT = 20
TEST_PROJECT_ID = 'test-project'


# pylint: disable=arguments-differ
class SpoofedDatetime(datetime.datetime):
  """Mocking Datetime class for now() function."""

  @classmethod
  def now(cls):
    return datetime.datetime(2020, 1, 1, 0, 0, 0)


def start_datastore_emulator():
  """Start Datastore emulator."""
  return subprocess.Popen([
      'gcloud',
      'beta',
      'emulators',
      'datastore',
      'start',
      '--consistency=1.0',
      '--host-port=localhost:' + str(DATASTORE_EMULATOR_PORT),
      '--project=' + TEST_PROJECT_ID,
      '--no-store-on-disk',
  ],
                          stdout=subprocess.PIPE,
                          stderr=subprocess.STDOUT)


def wait_for_emulator_ready(proc,
                            emulator,
                            indicator,
                            timeout=EMULATOR_TIMEOUT):
  """Wait for emulator to be ready."""

  def _read_thread(proc, ready_event):
    """Thread to continuously read from the process stdout."""
    ready = False
    while True:
      line = proc.stdout.readline()
      if not line:
        break
      if not ready and indicator in line:
        ready = True
        ready_event.set()

  # Wait for process to become ready.
  ready_event = threading.Event()
  thread = threading.Thread(target=_read_thread, args=(proc, ready_event))
  thread.daemon = True
  thread.start()
  if not ready_event.wait(timeout):
    raise RuntimeError(
        '{} emulator did not get ready in time.'.format(emulator))
  return thread


def reset_ds_emulator():
  """Reset ds emulator/clean all entities."""
  req = requests.post(
      'http://localhost:{}/reset'.format(DATASTORE_EMULATOR_PORT))
  req.raise_for_status()


def cleanup_emulator(ds_emulator):
  """Cleanup the system processes made by ds emulator."""
  del ds_emulator  #To do, find a better way to cleanup emulator
  os.system('pkill -f datastore')


def set_gcp_environment():
  """Set environment variables for simulating in google cloud platform."""
  os.environ['DATASTORE_EMULATOR_HOST'] = 'localhost:' + str(
      DATASTORE_EMULATOR_PORT)
  os.environ['GOOGLE_CLOUD_PROJECT'] = TEST_PROJECT_ID
  os.environ['DATASTORE_DATASET'] = TEST_PROJECT_ID
  os.environ['GCP_PROJECT'] = TEST_PROJECT_ID
  os.environ['FUNCTION_REGION'] = 'us-central1'
