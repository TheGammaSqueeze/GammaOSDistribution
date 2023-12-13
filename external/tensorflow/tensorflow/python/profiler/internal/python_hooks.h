/* Copyright 2020 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#ifndef TENSORFLOW_PYTHON_PROFILER_INTERNAL_PYTHON_HOOKS_H_
#define TENSORFLOW_PYTHON_PROFILER_INTERNAL_PYTHON_HOOKS_H_

#include <memory>
#include <stack>
#include <vector>

#include "absl/container/flat_hash_map.h"
#include "absl/memory/memory.h"
#include "pybind11/cast.h"
#include "pybind11/pybind11.h"
#include "pybind11/pytypes.h"
#include "tensorflow/core/platform/macros.h"
#include "tensorflow/core/platform/types.h"
#include "tensorflow/core/profiler/protobuf/xplane.pb.h"

namespace tensorflow {
namespace profiler {

namespace py = ::pybind11;

struct PythonHooksOptions {
  bool enable_trace_python_function = false;
  bool enable_python_traceme = true;
  bool end_to_end_mode = false;
  // Incomplete events are defined as those python calls which we only see
  // either start or end, but not both. If we want to include them in the final
  // result, profiler start, end time are used respectively to the absent
  // timestamps.
  bool include_incomplete_events = true;
};

struct PythonTraceEntry {
  PythonTraceEntry(uint64 start, uint64 end, PyCodeObject* code,
                   PyCFunctionObject* func)
      : start_time_ns(start),
        end_time_ns(end),
        code_object(code),
        function_object(func) {
    Py_XINCREF(code_object);
    Py_XINCREF(function_object);
  }
  ~PythonTraceEntry() {
    Py_XDECREF(code_object);
    Py_XDECREF(function_object);
  }
  PythonTraceEntry(PythonTraceEntry&& other) {
    start_time_ns = other.start_time_ns;
    end_time_ns = other.end_time_ns;
    code_object = other.code_object;
    function_object = other.function_object;
    other.code_object = nullptr;
    other.function_object = nullptr;
  }

  std::string Name() const;

  uint64 start_time_ns;
  uint64 end_time_ns;
  PyCodeObject* code_object;
  PyCFunctionObject* function_object;

  PythonTraceEntry(const PythonTraceEntry& other) = delete;
  void operator=(const PythonTraceEntry&) = delete;
  void operator=(PythonTraceEntry&&) = delete;
};

struct PerThreadEvents {
  std::deque<PythonTraceEntry> completed;
  std::stack<PythonTraceEntry> active;
};

class PythonHookContext {
 public:
  void Start(const PythonHooksOptions& option);
  void Stop();
  void Finalize(XSpace* space);
  void ProfileFast(PyFrameObject* frame, int what, PyObject* arg);

 private:
  void CollectData(XPlane* raw_plane);
  static void EnableTraceMe(bool enable);

  void SetProfilerInAllThreads();
  static void ClearProfilerInAllThreads();

  void operator=(const PythonHookContext&) = delete;
  void operator=(PythonHookContext&&) = delete;

  absl::flat_hash_map<int64, PerThreadEvents> entries_;
  uint64 start_timestamp_ns_;
  PythonHooksOptions options_;
  // In end to end mode, Python get uninitialized before Stop()/Finalize(), we
  // need to buffer the result.
  absl::optional<XPlane> end_to_end_xplane_;
};

// Singleton for tracing python function calls.
class PythonHooks {
 public:
  static PythonHooks* GetSingleton();

  void Start(const PythonHooksOptions& option) {
    if (active_context_) return;
    active_context_ = std::make_unique<PythonHookContext>();
    active_context_->Start(option);
  }

  std::unique_ptr<PythonHookContext> Stop() {
    if (e2e_context_) {
      auto* e2e_context = e2e_context_;
      e2e_context_ = nullptr;
      return absl::WrapUnique(e2e_context);
    }

    if (!active_context_) return nullptr;
    active_context_->Stop();
    std::unique_ptr<PythonHookContext> output = std::move(active_context_);
    active_context_.reset();
    return output;
  }

  void ProfileSlow(const py::object& frame, const string& event,
                   const py::object& arg);

  void ProfileFast(PyFrameObject* frame, int what, PyObject* arg) {
    if (TF_PREDICT_TRUE(active_context_)) {
      active_context_->ProfileFast(frame, what, arg);
    }
  }

  static void set_e2e_context(PythonHookContext* e2e_context) {
    e2e_context_ = e2e_context;
  }

  static PythonHookContext* e2e_context() { return e2e_context_; }

 private:
  // active_context_ are accessed when GIL is held, therefore no race
  // conditions.
  std::unique_ptr<PythonHookContext> active_context_;
  static PythonHookContext* e2e_context_;
};

}  // namespace profiler
}  // namespace tensorflow

#endif  // TENSORFLOW_PYTHON_PROFILER_INTERNAL_PYTHON_HOOKS_H_
