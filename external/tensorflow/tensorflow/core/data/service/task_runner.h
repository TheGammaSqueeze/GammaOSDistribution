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
#ifndef TENSORFLOW_CORE_DATA_SERVICE_TASK_RUNNER_H_
#define TENSORFLOW_CORE_DATA_SERVICE_TASK_RUNNER_H_

#include "tensorflow/core/data/service/common.pb.h"
#include "tensorflow/core/data/service/worker.pb.h"
#include "tensorflow/core/data/standalone.h"
#include "tensorflow/core/platform/status.h"

namespace tensorflow {
namespace data {

// Iterator over a task's elements.
class TaskIterator {
 public:
  virtual ~TaskIterator() = default;
  // If the iterator is not yet exhausted, `GetNext` stores the next element in
  // `element` and sets `end_of_sequence` to `false`. Otherwise, sets
  // `end_of_sequence to `true`.
  virtual Status GetNext(std::vector<Tensor>& element,
                         bool& end_of_sequence) = 0;
  // Reports the cardinality of the dataset that created this iterator.
  virtual int64 Cardinality() const = 0;
};

// Implementation of TaskIterator wrapping a standalone iterator.
class StandaloneTaskIterator : public TaskIterator {
 public:
  // `dataset` should be the dataset that created `iterator`.
  // StandaloneTaskIterator takes ownership of the dataset to ensures it
  // lives as long as `iterator`.
  StandaloneTaskIterator(std::unique_ptr<standalone::Dataset> dataset,
                         std::unique_ptr<standalone::Iterator> iterator);
  Status GetNext(std::vector<Tensor>& element, bool& end_of_sequence) override;
  int64 Cardinality() const override;

 private:
  std::unique_ptr<standalone::Dataset> dataset_;
  std::unique_ptr<standalone::Iterator> iterator_;
};

// Interface for providing elements to task consumers.
class TaskRunner {
 public:
  // Creates a `TaskRunner` and stores it in `out`.
  static Status Create(const TaskDef& task_def,
                       std::unique_ptr<TaskIterator> iterator,
                       std::unique_ptr<TaskRunner>& out);
  virtual ~TaskRunner() = default;
  // Gets the next element for the given request.
  virtual Status GetNext(const GetElementRequest& req,
                         GetElementResponse& resp) = 0;
};

// A task runner which provides elements on a first-come first-served basis.
// It does not consider which consumer is making the request.
class FirstComeFirstServedTaskRunner : public TaskRunner {
 public:
  explicit FirstComeFirstServedTaskRunner(
      std::unique_ptr<TaskIterator> iterator);
  Status GetNext(const GetElementRequest& req,
                 GetElementResponse& resp) override;

 private:
  std::unique_ptr<TaskIterator> iterator_;
};

// Thread for prefetching a round worth of elements.
class PrefetchThread {
 public:
  explicit PrefetchThread(std::unique_ptr<TaskIterator> iterator,
                          int64 round_size);
  ~PrefetchThread();
  // Runs the prefetch thread. It runs until an error is encountered or the
  // destructor is called.
  void Run();
  // Fills `out` with a round of data. Waits for up to `wait_us` micoseconds
  // before giving up and returning with `out` empty. A negative `wait_us`
  // signals to wait indefinitely.
  Status FillBuffer(int64 wait_us, std::vector<std::vector<Tensor>>& out);
  // Returns the status for any failures encountered by the prefetch thread.
  Status GetStatus();

 private:
  const std::unique_ptr<TaskIterator> iterator_;
  const int64 round_size_;
  mutex mu_;
  // Buffered results for the next round.
  std::vector<std::vector<Tensor>> buffer_ TF_GUARDED_BY(mu_);
  // The status if the prefetch thread fails.
  Status status_ TF_GUARDED_BY(mu_) = Status::OK();
  // Thread which constantly tries to fill `buffer_` up with
  // `num_consumers` elements.
  std::unique_ptr<Thread> thread_;
  // Condition variable notified when elements are added to or removed from
  // `buffer_`, or when `status_` is changed.
  condition_variable cv_;
  bool cancelled_ TF_GUARDED_BY(mu_) = false;
};

// A task runner which enforces round-robin order for consuming a task's
// elements. `RoundRobinTaskRunner` provides elements in a series of "rounds".
// In each successive round, the runner waits to receive requests from all
// consumers. These requests are blocked until all requests arrive. Once all
// requests arrive, the runner hands out elements to consumers in order of their
// consumer indices.
//
// Consumers are expected to successively request consecutive element indices,
// starting at 0. The same element can be requested multiple times by the same
// consumer, as long as the consumer hasn't yet requested the next element (at
// the start of each round we discard elements from the previous round).
//
// If the worker restarts mid-round, a situation arises where some consumers
// are requesting element index `n` while others are requesting element index
// `n + 1`. To remedy this, the first round after restart may be a partial
// round, where we only serve elements to consumers requesting data for element
// index `n`, blocking other consumers until the second round.
class RoundRobinTaskRunner : public TaskRunner {
 public:
  RoundRobinTaskRunner(std::unique_ptr<TaskIterator> iterator,
                       int64 num_consumers);

  Status GetNext(const GetElementRequest& req,
                 GetElementResponse& resp) override;

 private:
  // Prepares a full round of data. `wait_us` indicates how long to wait before
  // skipping if a full round of data is not yet ready.
  Status PrepareFullRound(int64 wait_us) TF_EXCLUSIVE_LOCKS_REQUIRED(mu_);
  // Prepares a partial round to get consumers back in sync.
  Status PreparePartialRound() TF_EXCLUSIVE_LOCKS_REQUIRED(mu_);
  Status ValidateRequest(const GetElementRequest& req);
  // Prepares data for the next round, blocking until the round is ready to
  // start.
  Status PrepareRound(const GetElementRequest& req);
  const int64 num_consumers_;
  mutex mu_;
  // Condition variable notified whenever we start a new round of round-robin.
  condition_variable new_round_cv_;
  // Outstanding requests, indexed by round number and then consumer index.
  absl::flat_hash_map<int64,
                      absl::flat_hash_map<int64, const GetElementRequest*>>
      requests_ TF_GUARDED_BY(mu_);
  // Index of the first round we plan to serve. At startup, this is the minimum
  // of all requested element indices.
  int64 first_round_ TF_GUARDED_BY(mu_) = kint64max;
  int64 current_round_ TF_GUARDED_BY(mu_) = -1;
  bool round_skipped_ TF_GUARDED_BY(mu_) = false;
  // Buffered results for the current round.
  std::vector<std::vector<Tensor>> buffer_ TF_GUARDED_BY(mu_);
  // Thread which constantly tries to prepare `num_consumers` elements for the
  // next round.
  PrefetchThread prefetch_thread_;
};

}  // namespace data
}  // namespace tensorflow

#endif  // TENSORFLOW_CORE_DATA_SERVICE_TASK_RUNNER_H_
