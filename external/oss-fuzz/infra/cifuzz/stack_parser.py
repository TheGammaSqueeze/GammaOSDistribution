# Copyright 2021 Google LLC
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
"""Module for parsing stacks from fuzz targets."""

import logging

# From clusterfuzz: src/python/crash_analysis/crash_analyzer.py
# Used to get the beginning of the stacktrace.
STACKTRACE_TOOL_MARKERS = [
    b'AddressSanitizer',
    b'ASAN:',
    b'CFI: Most likely a control flow integrity violation;',
    b'ERROR: libFuzzer',
    b'KASAN:',
    b'LeakSanitizer',
    b'MemorySanitizer',
    b'ThreadSanitizer',
    b'UndefinedBehaviorSanitizer',
    b'UndefinedSanitizer',
]

# From clusterfuzz: src/python/crash_analysis/crash_analyzer.py
# Used to get the end of the stacktrace.
STACKTRACE_END_MARKERS = [
    b'ABORTING',
    b'END MEMORY TOOL REPORT',
    b'End of process memory map.',
    b'END_KASAN_OUTPUT',
    b'SUMMARY:',
    b'Shadow byte and word',
    b'[end of stack trace]',
    b'\nExiting',
    b'minidump has been written',
]


def parse_fuzzer_output(fuzzer_output, parsed_output_file_path):
  """Parses the fuzzer output from a fuzz target binary.

  Args:
    fuzzer_output: A fuzz target binary output string to be parsed.
    parsed_output_file_path: The location to store the parsed output.
  """
  # Get index of key file points.
  begin_stack = None
  for marker in STACKTRACE_TOOL_MARKERS:
    marker_index = fuzzer_output.find(marker)
    if marker_index != -1:
      begin_stack = marker_index
      break

  if begin_stack is None:
    logging.error(
        b'Could not find a begin stack marker (%s) in fuzzer output:\n%s',
        STACKTRACE_TOOL_MARKERS, fuzzer_output)
    return

  end_stack = None
  for marker in STACKTRACE_END_MARKERS:
    marker_index = fuzzer_output.find(marker)
    if marker_index != -1:
      end_stack = marker_index + len(marker)
      break

  if end_stack is None:
    logging.error(
        b'Could not find an end stack marker (%s) in fuzzer output:\n%s',
        STACKTRACE_END_MARKERS, fuzzer_output)
    return

  summary_str = fuzzer_output[begin_stack:end_stack]

  # Write sections of fuzzer output to specific files.
  with open(parsed_output_file_path, 'ab') as summary_handle:
    summary_handle.write(summary_str)
