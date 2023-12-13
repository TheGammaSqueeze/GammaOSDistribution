// Copyright 2021 The Pigweed Authors
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
#pragma once

#include <cstdint>
#include <cstring>
#include <span>

#include "pw_thread_threadx/config.h"
#include "tx_api.h"
#include "tx_thread.h"

namespace pw::thread {

class Thread;  // Forward declare Thread which depends on Context.

}  // namespace pw::thread

namespace pw::thread::threadx {

// Static thread context allocation including the TCB, an event group for
// joining if enabled, and an external statically allocated stack.
//
// Example usage:
//
//   std::array<ULONG, 42> example_thread_stack;
//   pw::thread::threadx::Context example_thread_context(example_thread_stack);
//   void StartExampleThread() {
//      pw::thread::Thread(
//        pw::thread::threadx::Options()
//            .set_name("static_example_thread")
//            .set_priority(kFooPriority)
//            .set_static_context(example_thread_context),
//        example_thread_function).detach();
//   }
class Context {
 public:
  explicit Context(std::span<ULONG> stack_span)
      : tcb_{}, stack_span_(stack_span) {}
  Context(const Context&) = delete;
  Context& operator=(const Context&) = delete;

  // Intended for unit test & Thread use only.
  TX_THREAD& tcb() { return tcb_; }

 private:
  friend Thread;

  std::span<ULONG> stack() { return stack_span_; }

  bool in_use() const { return in_use_; }
  void set_in_use(bool in_use = true) { in_use_ = in_use; }

  const char* name() const { return name_.data(); }
  void set_name(const char* name) {
    strncpy(name_.data(), name, name_.size() - 1);
    // Forcefully NULL terminate as strncpy does not NULL terminate if the count
    // limit is hit.
    name_[name_.size() - 1] = '\0';
  }

  using ThreadRoutine = void (*)(void* arg);
  void set_thread_routine(ThreadRoutine entry, void* arg) {
    entry_ = entry;
    arg_ = arg;
  }

  bool detached() const { return detached_; }
  void set_detached(bool value = true) { detached_ = value; }

  bool thread_done() const { return thread_done_; }
  void set_thread_done(bool value = true) { thread_done_ = value; }

#if PW_THREAD_JOINING_ENABLED
  TX_EVENT_FLAGS_GROUP& join_event_group() { return event_group_; }
#endif  // PW_THREAD_JOINING_ENABLED

  static void RunThread(ULONG void_context_ptr);
  static void DeleteThread(Context& context);

  TX_THREAD tcb_;
  std::span<ULONG> stack_span_;

  ThreadRoutine entry_ = nullptr;
  void* arg_ = nullptr;
#if PW_THREAD_JOINING_ENABLED
  // Note that the ThreadX life cycle of this event group is managed together
  // with the thread life cycle, not this object's life cycle.
  TX_EVENT_FLAGS_GROUP event_group_;
#endif  // PW_THREAD_JOINING_ENABLED
  bool in_use_ = false;
  bool detached_ = false;
  bool thread_done_ = false;

  // The TCB does not have storage for the name, ergo we provide storage for
  // the thread's name which can be truncated down to just a null delimeter.
  std::array<char, config::kMaximumNameLength> name_;
};

// Static thread context allocation including the stack along with the Context.
//
// Example usage:
//
//   pw::thread::threadx::ContextWithStack<42> example_thread_context;
//   void StartExampleThread() {
//      pw::thread::Thread(
//        pw::thread::threadx::Options()
//            .set_name("static_example_thread")
//            .set_priority(kFooPriority)
//            .set_static_context(example_thread_context),
//        example_thread_function).detach();
//   }
template <size_t kStackSizeWords = config::kDefaultStackSizeWords>
class ContextWithStack final : public Context {
 public:
  constexpr ContextWithStack() : Context(stack_storage_) {
    static_assert(kStackSizeWords >= config::kMinimumStackSizeWords);
  }

 private:
  std::array<ULONG, kStackSizeWords> stack_storage_;
};

}  // namespace pw::thread::threadx
