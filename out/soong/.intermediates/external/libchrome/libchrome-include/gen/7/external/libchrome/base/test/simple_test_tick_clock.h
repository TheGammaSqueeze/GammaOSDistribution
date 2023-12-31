// Generated by out/soong/.temp/sbox/a2e09549e303b76f18b1308b8a7f3b593f14660e/tools/src/external/libchrome/libchrome_tools/include_generator.py
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_TEST_SIMPLE_TEST_TICK_CLOCK_H_
#define BASE_TEST_SIMPLE_TEST_TICK_CLOCK_H_

#include "base/compiler_specific.h"
#include "base/synchronization/lock.h"
#include "base/time/tick_clock.h"
#include "base/time/time.h"

namespace base {

// SimpleTestTickClock is a TickClock implementation that gives
// control over the returned TimeTicks objects.  All methods may be
// called from any thread.
class SimpleTestTickClock : public TickClock {
 public:
  // Starts off with a clock set to TimeTicks().
  SimpleTestTickClock();
  ~SimpleTestTickClock() override;

  TimeTicks NowTicks() const override;

  // Advances the clock by |delta|, which must not be negative.
  void Advance(TimeDelta delta);

  // Sets the clock to the given time.
  void SetNowTicks(TimeTicks ticks);

 private:
  // Protects |now_ticks_|.
  mutable Lock lock_;

  TimeTicks now_ticks_;
};

}  // namespace base

#endif  // BASE_TEST_SIMPLE_TEST_TICK_CLOCK_H_
#pragma GCC diagnostic pop
