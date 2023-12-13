/*
 * Copyright (C) 2016 The Android Open Source Project
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

#include "art_method.h"
#include "base/enums.h"
#include "jit/jit.h"
#include "jit/jit_code_cache.h"
#include "jit/profiling_info.h"
#include "mirror/class.h"
#include "nativehelper/ScopedUtfChars.h"
#include "oat_quick_method_header.h"
#include "scoped_thread_state_change-inl.h"
#include "stack_map.h"

namespace art {

static bool do_checks(ArtMethod* method, ScopedObjectAccess& soa)
    REQUIRES_SHARED(Locks::mutator_lock_) {
  jit::Jit* jit = Runtime::Current()->GetJit();
  jit::JitCodeCache* code_cache = jit->GetCodeCache();

  OatQuickMethodHeader* header = nullptr;
  // Infinite loop... Test harness will have its own timeout.
  while (true) {
    const void* pc = method->GetEntryPointFromQuickCompiledCode();
    if (code_cache->ContainsPc(pc) &&
        !CodeInfo::IsBaseline(
            OatQuickMethodHeader::FromEntryPoint(pc)->GetOptimizedCodeInfoPtr())) {
      header = OatQuickMethodHeader::FromEntryPoint(pc);
      break;
    } else {
      ScopedThreadSuspension sts(soa.Self(), kSuspended);
      // Sleep to yield to the compiler thread.
      usleep(1000);
    }
    // Will either ensure it's compiled or do the compilation itself.
    jit->CompileMethod(method, soa.Self(), CompilationKind::kOptimized, /*prejit=*/ false);
  }

  CodeInfo info(header);
  return info.HasInlineInfo();
}

extern "C" JNIEXPORT bool JNICALL Java_Main_ensureJittedAndPolymorphicInline566(JNIEnv* env,
                                                                                jclass cls,
                                                                                jstring method_name) {
  jit::Jit* jit = Runtime::Current()->GetJit();
  if (jit == nullptr) {
    return true;
  }

  // The test only works when we use tiered JIT.
  if (jit->JitAtFirstUse()) {
    return true;
  }

  ScopedObjectAccess soa(Thread::Current());
  ScopedUtfChars chars(env, method_name);
  ArtMethod* method = soa.Decode<mirror::Class>(cls)->FindDeclaredDirectMethodByName(
      chars.c_str(), kRuntimePointerSize);

  if (method == nullptr) {
    return false;
  }

  return do_checks(method, soa);
}

}  // namespace art
