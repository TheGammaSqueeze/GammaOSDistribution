// Copyright 2020 The Pigweed Authors
//
// Licensed under the Apache License, Version 2.0 (the "License"); you may not
// use this file except in compliance with the License. You may obtain a copy of
// the License at
//
//     https://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
// License for the specific language governing permissions and limitations under
// the License.

// These tests call the pw_chrono module system_clock API from C. The return
// values are checked in the main C++ tests.

#include "pw_chrono/system_clock.h"

pw_chrono_SystemClock_TimePoint pw_chrono_SystemClock_CallNow(void) {
  return pw_chrono_SystemClock_Now();
}

pw_chrono_SystemClock_Duration pw_chrono_SystemClock_CallTimeElapsed(
    pw_chrono_SystemClock_TimePoint last_time,
    pw_chrono_SystemClock_TimePoint current_time) {
  return pw_chrono_SystemClock_TimeElapsed(last_time, current_time);
}

pw_chrono_SystemClock_Nanoseconds pw_chrono_SystemClock_CallDurationToNsFloor(
    pw_chrono_SystemClock_Duration ticks) {
  return pw_chrono_SystemClock_DurationToNsFloor(ticks);
}
