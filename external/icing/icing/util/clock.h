// Copyright (C) 2019 Google LLC
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef ICING_UTIL_CLOCK_H_
#define ICING_UTIL_CLOCK_H_

#include <cstdint>
#include <memory>

namespace icing {
namespace lib {

// Returns the current steady time in nanoseconds. The steady clock is different
// from the system clock. It's monotonic and never returns a lower value than a
// previous call, while a system clock can be occasionally adjusted.
int64_t GetSteadyTimeNanoseconds();

// Returns the current steady time in Milliseconds. The steady clock is
// different from the system clock. It's monotonic and never returns a lower
// value than a previous call, while a system clock can be occasionally
// adjusted.
int64_t GetSteadyTimeMilliseconds();

// Used to calculate the elapsed time.
class Timer {
 public:
  // Creates and starts the timer.
  Timer() : start_timestamp_nanoseconds_(GetSteadyTimeNanoseconds()) {}

  virtual ~Timer() = default;

  // Returns the elapsed time from when timer started.
  virtual int64_t GetElapsedMilliseconds() {
    return GetElapsedNanoseconds() / 1000000;
  }

  // Returns the elapsed time from when timer started.
  virtual int64_t GetElapsedNanoseconds() {
    return GetSteadyTimeNanoseconds() - start_timestamp_nanoseconds_;
  }

 private:
  int64_t start_timestamp_nanoseconds_;
};

// Wrapper around real-time clock functions. This is separated primarily so
// tests can override this clock and inject it into the class under test.
class Clock {
 public:
  virtual ~Clock() = default;

  // Returns the current time in milliseconds, it's guaranteed that the return
  // value is non-negative.
  virtual int64_t GetSystemTimeMilliseconds() const;

  // Returns a timer used to calculate the elapsed time. The timer starts when
  // the method returns.
  virtual std::unique_ptr<Timer> GetNewTimer() const;
};

}  // namespace lib
}  // namespace icing

#endif  // ICING_UTIL_CLOCK_H_
