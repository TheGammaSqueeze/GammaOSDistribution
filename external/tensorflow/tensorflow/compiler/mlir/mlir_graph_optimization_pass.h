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

#ifndef TENSORFLOW_COMPILER_MLIR_MLIR_GRAPH_OPTIMIZATION_PASS_H_
#define TENSORFLOW_COMPILER_MLIR_MLIR_GRAPH_OPTIMIZATION_PASS_H_

#include <functional>

#include "tensorflow/compiler/mlir/mlir_bridge_rollout_policy.h"
#include "mlir/IR/BuiltinOps.h"  // from @llvm-project
#include "tensorflow/core/common_runtime/function_optimization_registry.h"
#include "tensorflow/core/common_runtime/optimization_registry.h"

namespace tensorflow {

// -------------------------------------------------------------------------- //
// MLIR passes running on Tensorflow function graphs (Tensorflow V2).
// -------------------------------------------------------------------------- //

// Disabled - skip execution of the pass.
// Enabled - execute the pass, propagate errors to the caller if any.
// ShadowEnabled - execute the pass in a shadow mode. The pass should not commit
//   any changes to the MLIR module it's processing. Failures are not propagated
//   to the caller.
// FallbackEnabled - execute the pass and commit all the changes to the MLIR
//   module in case of success. Do not commit any changes in case of failures,
//   let the rest of the pipeline run.
enum class MlirOptimizationPassState {
  Disabled,
  Enabled,
  ShadowEnabled,
  FallbackEnabled
};

// An API for registering MLIR ModulePass with the Tensorflow runtime. These
// passes are running only for function graphs built by Tensorflow V2 and
// instantiated by the process_function_library_runtime (see
// FunctionOptimizationPass for details).
class MlirOptimizationPass {
 public:
  virtual ~MlirOptimizationPass() = default;
  virtual llvm::StringRef name() const = 0;

  // Returns an enum value:
  //   Enabled if the pass is enabled for the given graph with specified config.
  //   Disabled if the pass is disabled.
  //   ShadowEnabled if the pass needs to be executed in shadow mode.
  //
  // When the pass is ShadowEnabled, the pass is executed for metrics collection
  // and reporting purposes only, but none of the changes it makes to the MLIR
  // module will be committed.
  // `device_set` can be nullptr if the devices information is not
  // available or no device specific filtering is required.
  virtual MlirOptimizationPassState GetPassState(
      const DeviceSet* device_set, const ConfigProto& config_proto,
      const Graph& graph) const = 0;

  virtual Status Run(const ConfigProto& config_proto, mlir::ModuleOp module,
                     const Graph& graph) = 0;
};

class MlirOptimizationPassRegistry {
 public:
  struct PassRegistration {
    int priority;
    std::unique_ptr<MlirOptimizationPass> pass;
  };

  struct PriorityComparator {
    bool operator()(const PassRegistration& x,
                    const PassRegistration& y) const {
      return x.priority < y.priority;
    }
  };

  using Passes = std::set<PassRegistration, PriorityComparator>;

  // Returns the global registry of MLIR optimization passes.
  static MlirOptimizationPassRegistry& Global();

  // Register optimization `pass` with the given `priority`.
  void Add(int priority, std::unique_ptr<MlirOptimizationPass> pass) {
    auto inserted = passes_.insert({priority, std::move(pass)});
    CHECK(inserted.second)
        << "Pass priority must be unique. "
        << "Previously registered pass with the same priority: "
        << inserted.first->pass->name().str();
  }

  // Free the memory allocated for all passes.
  void ClearPasses() { passes_.clear(); }

  const Passes& passes() const { return passes_; }

 private:
  Passes passes_;
};

// Function optimization pass that runs all MLIR passes registered in
// MlirOptimizationPassRegistry.
class MlirFunctionOptimizationPass : public FunctionOptimizationPass {
 public:
  explicit MlirFunctionOptimizationPass(
      const MlirOptimizationPassRegistry* registry =
          &MlirOptimizationPassRegistry::Global())
      : registry_(registry) {}

  // Executes all of the underlying registered MlirOptimizationPasses.
  //
  // The MlirFunctionOptimizationPass will be executed in fully shadow mode if
  // all of the underlying registered MlirOptimizationPasses are ShadowEnabled.
  // In this case, no changes should be done to the original TF graph and no
  // failures propagated back to the user. Failures during the conversion
  // of TF graph to MLIR module and back will be treated as a soft
  // failures, e.g., relevant stats will be recorded and no error returned
  // back to the caller.
  //
  // In case some of the passes are shadow enabled while others are enabled,
  // failures in the enabled passes will be treated as real errors and
  // propagated back to the caller. Failure during the shadow pass execution
  // is a soft failure.
  Status Run(const DeviceSet& device_set, const ConfigProto& config_proto,
             std::unique_ptr<Graph>* graph, FunctionLibraryDefinition* flib_def,
             std::vector<std::string>* control_ret_node_names,
             bool* control_rets_updated) override;

 private:
  const MlirOptimizationPassRegistry* registry_;
};

// -------------------------------------------------------------------------- //
// MLIR passes running on Tensorflow V1 graphs.
// -------------------------------------------------------------------------- //

// An API for registering MLIR ModulePass with the Tensorflow runtime. These
// passes are running only for V1 graphs (legacy graphs) executed via Session
// runtime. Graph importer updates legacy graph behavior to V2 constructs (e.g.
// it raises control flow from Switch/Merge nodes to functional control flow
// with If/While operations).
class MlirV1CompatOptimizationPass {
 public:
  virtual ~MlirV1CompatOptimizationPass() = default;
  virtual llvm::StringRef name() const = 0;

  // Returns true if the pass is enabled for the given graph with specified
  // config. `device_set` can be nullptr if the devices information is not
  // available or no device specific filtering is required.
  virtual bool IsEnabled(const DeviceSet* device_set,
                         const ConfigProto& config_proto,
                         const Graph& graph) const = 0;

  virtual Status Run(const GraphOptimizationPassOptions& options,
                     mlir::ModuleOp module) = 0;
};

class MlirV1CompatOptimizationPassRegistry {
 public:
  struct PassRegistration {
    int priority;
    std::unique_ptr<MlirV1CompatOptimizationPass> pass;
  };

  struct PriorityComparator {
    bool operator()(const PassRegistration& x,
                    const PassRegistration& y) const {
      return x.priority < y.priority;
    }
  };

  using Passes = std::set<PassRegistration, PriorityComparator>;

  // Returns the global registry of MLIR optimization passes.
  static MlirV1CompatOptimizationPassRegistry& Global();

  void Add(int priority, std::unique_ptr<MlirV1CompatOptimizationPass> pass) {
    auto inserted = passes_.insert({priority, std::move(pass)});
    CHECK(inserted.second)
        << "Pass priority must be unique. "
        << "Previously registered pass with the same priority: "
        << inserted.first->pass->name().str();
  }

  const Passes& passes() const { return passes_; }

 private:
  Passes passes_;
};

class MlirV1CompatGraphOptimizationPass : public GraphOptimizationPass {
 public:
  explicit MlirV1CompatGraphOptimizationPass(
      const MlirV1CompatOptimizationPassRegistry* registry =
          &MlirV1CompatOptimizationPassRegistry::Global())
      : registry_(registry) {}

  Status Run(const GraphOptimizationPassOptions& options) override;

 private:
  const MlirV1CompatOptimizationPassRegistry* registry_;
};

// -------------------------------------------------------------------------- //
// Helper classes for static registration of MLIR (V1 Compat) passes in the
// corresponding registry.
// -------------------------------------------------------------------------- //

namespace mlir_pass_registration {

class MlirOptimizationPassRegistration {
 public:
  explicit MlirOptimizationPassRegistration(
      int priority, std::unique_ptr<MlirOptimizationPass> pass) {
    MlirOptimizationPassRegistry::Global().Add(priority, std::move(pass));
  }
};

class MlirV1CompatOptimizationPassRegistration {
 public:
  explicit MlirV1CompatOptimizationPassRegistration(
      int priority, std::unique_ptr<MlirV1CompatOptimizationPass> pass) {
    MlirV1CompatOptimizationPassRegistry::Global().Add(priority,
                                                       std::move(pass));
  }
};

}  // namespace mlir_pass_registration

}  // namespace tensorflow

#endif  // TENSORFLOW_COMPILER_MLIR_MLIR_GRAPH_OPTIMIZATION_PASS_H_
