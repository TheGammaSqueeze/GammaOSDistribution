/*
 * Copyright (C) 2015 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ART_COMPILER_OPTIMIZING_REFERENCE_TYPE_PROPAGATION_H_
#define ART_COMPILER_OPTIMIZING_REFERENCE_TYPE_PROPAGATION_H_

#include "base/arena_containers.h"
#include "mirror/class-inl.h"
#include "nodes.h"
#include "obj_ptr.h"
#include "optimization.h"

namespace art {

/**
 * Propagates reference types to instructions.
 */
class ReferenceTypePropagation : public HOptimization {
 public:
  ReferenceTypePropagation(HGraph* graph,
                           Handle<mirror::ClassLoader> class_loader,
                           Handle<mirror::DexCache> hint_dex_cache,
                           bool is_first_run,
                           const char* name = kReferenceTypePropagationPassName);

  // Visit a single instruction.
  // Used when a pass, such as Inliner or LSE, adds a single instruction.
  void Visit(HInstruction* instruction);

  // Visit instructions and process dependencies between them.
  // Used when a pass, such as LSE, adds multiple dependent instructions, including Phis.
  void Visit(ArrayRef<HInstruction* const> instructions);

  bool Run() override;

  // Returns true if klass is admissible to the propagation: non-null and resolved.
  // For an array type, we also check if the component type is admissible.
  static bool IsAdmissible(ObjPtr<mirror::Class> klass) REQUIRES_SHARED(Locks::mutator_lock_) {
    while (klass != nullptr && klass->IsArrayClass()) {
      DCHECK(klass->IsResolved());
      klass = klass->GetComponentType();
    }
    return klass != nullptr && klass->IsResolved();
  }

  static constexpr const char* kReferenceTypePropagationPassName = "reference_type_propagation";

  // Fix the reference type for an instruction whose inputs have changed.
  // For a select instruction, the reference types of the inputs are merged
  // and the resulting reference type is set on the select instruction.
  static void FixUpInstructionType(HInstruction* instruction, HandleCache* handle_cache);

 private:
  class RTPVisitor;

  static ReferenceTypeInfo MergeTypes(const ReferenceTypeInfo& a,
                                      const ReferenceTypeInfo& b,
                                      HandleCache* handle_cache)
      REQUIRES_SHARED(Locks::mutator_lock_);

  void ValidateTypes();

  Handle<mirror::ClassLoader> class_loader_;

  // Note: hint_dex_cache_ is usually, but not necessarily, the dex cache associated with
  // graph_->GetDexFile(). Since we may look up also in other dex files, it's used only
  // as a hint, to reduce the number of calls to the costly ClassLinker::FindDexCache().
  Handle<mirror::DexCache> hint_dex_cache_;

  // Whether this reference type propagation is the first run we are doing.
  const bool is_first_run_;

  template<typename T>
  friend class ReferenceTypePropagationTestBase;

  DISALLOW_COPY_AND_ASSIGN(ReferenceTypePropagation);
};

}  // namespace art

#endif  // ART_COMPILER_OPTIMIZING_REFERENCE_TYPE_PROPAGATION_H_
