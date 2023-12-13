//
// Copyright 2017 The Android Open Source Project
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#include "test_environment.h"

#include <future>

#include <client/linux/handler/exception_handler.h>

#include <backtrace/Backtrace.h>
#include <backtrace/backtrace_constants.h>

#include <gflags/gflags.h>

#include "os/log.h"

using ::android::bluetooth::root_canal::TestEnvironment;

DEFINE_string(controller_properties_file, "",
              "controller_properties.json file path");
DEFINE_string(default_commands_file, "",
              "commands file which root-canal runs it as default");

constexpr uint16_t kTestPort = 6401;
constexpr uint16_t kHciServerPort = 6402;
constexpr uint16_t kLinkServerPort = 6403;

extern "C" const char* __asan_default_options() {
  return "detect_container_overflow=0";
}

bool crash_callback(const void* crash_context, size_t crash_context_size,
                    __attribute__((unused)) void* context) {
  pid_t tid = BACKTRACE_CURRENT_THREAD;
  if (crash_context_size >=
      sizeof(google_breakpad::ExceptionHandler::CrashContext)) {
    auto* ctx =
        static_cast<const google_breakpad::ExceptionHandler::CrashContext*>(
            crash_context);
    tid = ctx->tid;
    int signal_number = ctx->siginfo.si_signo;
    LOG_ERROR("Process crashed, signal: %s[%d], tid: %d",
              strsignal(signal_number), signal_number, ctx->tid);
  } else {
    LOG_ERROR("Process crashed, signal: unknown, tid: unknown");
  }
  std::unique_ptr<Backtrace> backtrace(
      Backtrace::Create(BACKTRACE_CURRENT_PROCESS, tid));
  if (backtrace == nullptr) {
    LOG_ERROR("Failed to create backtrace object");
    return false;
  }
  if (!backtrace->Unwind(0)) {
    LOG_ERROR("backtrace->Unwind failed");
    return false;
  }
  LOG_ERROR("Backtrace:");
  for (size_t i = 0; i < backtrace->NumFrames(); i++) {
    LOG_ERROR("%s", backtrace->FormatFrameData(i).c_str());
  }
  return true;
}

int main(int argc, char** argv) {
  google_breakpad::MinidumpDescriptor descriptor(
      google_breakpad::MinidumpDescriptor::kMicrodumpOnConsole);
  google_breakpad::ExceptionHandler eh(descriptor, nullptr, nullptr, nullptr,
                                       true, -1);
  eh.set_crash_handler(crash_callback);

  gflags::ParseCommandLineFlags(&argc, &argv, true);

  LOG_INFO("main");
  uint16_t test_port = kTestPort;
  uint16_t hci_server_port = kHciServerPort;
  uint16_t link_server_port = kLinkServerPort;

  for (int arg = 0; arg < argc; arg++) {
    int port = atoi(argv[arg]);
    LOG_INFO("%d: %s (%d)", arg, argv[arg], port);
    if (port < 0 || port > 0xffff) {
      LOG_WARN("%s out of range", argv[arg]);
    } else {
      switch (arg) {
        case 0:  // executable name
          break;
        case 1:
          test_port = port;
          break;
        case 2:
          hci_server_port = port;
          break;
        case 3:
          link_server_port = port;
          break;
        default:
          LOG_WARN("Ignored option %s", argv[arg]);
      }
    }
  }

  TestEnvironment root_canal(test_port, hci_server_port, link_server_port,
                             FLAGS_controller_properties_file,
                             FLAGS_default_commands_file);
  std::promise<void> barrier;
  std::future<void> barrier_future = barrier.get_future();
  root_canal.initialize(std::move(barrier));
  barrier_future.wait();
  root_canal.close();
}
