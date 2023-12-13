/*
 * Copyright (C) 2019 The Android Open Source Project
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

#include "palette/palette.h"

#include <dlfcn.h>
#include <stdlib.h>

#include <android/log.h>
#include <android-base/macros.h>

namespace {

// Logging tag.
static constexpr const char* kLogTag = "libartpalette";

// Name of the palette library present in the /system partition.
static constexpr const char* kPaletteSystemLibrary = "libartpalette-system.so";

// Generic method used when a dynamically loaded palette instance does not
// support a method.
palette_status_t PaletteMethodNotSupported() {
  return PALETTE_STATUS_NOT_SUPPORTED;
}

// Declare type aliases for pointers to each function in the interface.
#define PALETTE_METHOD_TYPE_ALIAS(Name, ...) \
  using Name ## Method = palette_status_t(*)(__VA_ARGS__);
PALETTE_METHOD_LIST(PALETTE_METHOD_TYPE_ALIAS)
#undef PALETTE_METHOD_TYPE_ALIAS

// Singleton class responsible for dynamically loading the palette library and
// binding functions there to method pointers.
class PaletteLoader {
 public:
  static PaletteLoader& Instance() {
    static PaletteLoader instance;
    return instance;
  }

  // Accessor methods to get instances of palette methods.
#define PALETTE_LOADER_METHOD_ACCESSOR(Name, ...)                       \
  Name ## Method Get ## Name ## Method() const { return Name ## Method ## _; }
PALETTE_METHOD_LIST(PALETTE_LOADER_METHOD_ACCESSOR)
#undef PALETTE_LOADER_METHOD_ACCESSOR

 private:
  PaletteLoader();

  static void* OpenLibrary();
  static void* GetMethod(void* palette_lib, const char* name);

  // Handle to the palette library from dlopen().
  void* palette_lib_;

  // Fields to store pointers to palette methods.
#define PALETTE_LOADER_METHOD_FIELD(Name, ...) \
  const Name ## Method Name ## Method ## _;
  PALETTE_METHOD_LIST(PALETTE_LOADER_METHOD_FIELD)
#undef PALETTE_LOADER_METHOD_FIELD

  DISALLOW_COPY_AND_ASSIGN(PaletteLoader);
};

void* PaletteLoader::OpenLibrary() {
  void* handle = dlopen(kPaletteSystemLibrary, RTLD_NOW | RTLD_GLOBAL | RTLD_NODELETE);
  if (handle == nullptr) {
    // dlerror message includes details of error and file being opened.
    __android_log_assert(nullptr, kLogTag, "%s", dlerror());
  }
  return handle;
}

void* PaletteLoader::GetMethod(void* palette_lib, const char* name) {
  void* method = nullptr;
  if (palette_lib != nullptr) {
    method = dlsym(palette_lib, name);
  }
  if (method == nullptr) {
    return reinterpret_cast<void*>(PaletteMethodNotSupported);
  }
  // TODO(oth): consider new GetMethodSignature() in the Palette API which
  // would allow checking the validity of the type signatures.
  return method;
}

PaletteLoader::PaletteLoader() :
    palette_lib_(OpenLibrary())
#define PALETTE_LOADER_BIND_METHOD(Name, ...)                           \
    , Name ## Method ## _(reinterpret_cast<Name ## Method>(GetMethod(palette_lib_, #Name)))
    PALETTE_METHOD_LIST(PALETTE_LOADER_BIND_METHOD)
#undef PALETTE_LOADER_BIND_METHOD
{
}

}  // namespace

extern "C" {

palette_status_t PaletteSchedSetPriority(int32_t tid, int32_t java_priority) {
  PaletteSchedSetPriorityMethod m = PaletteLoader::Instance().GetPaletteSchedSetPriorityMethod();
  return m(tid, java_priority);
}

palette_status_t PaletteSchedGetPriority(int32_t tid, /*out*/int32_t* java_priority) {
  PaletteSchedGetPriorityMethod m = PaletteLoader::Instance().GetPaletteSchedGetPriorityMethod();
  return m(tid, java_priority);
}

palette_status_t PaletteWriteCrashThreadStacks(/*in*/const char* stack, size_t stack_len) {
  PaletteWriteCrashThreadStacksMethod m =
      PaletteLoader::Instance().GetPaletteWriteCrashThreadStacksMethod();
  return m(stack, stack_len);
}

palette_status_t PaletteTraceEnabled(/*out*/bool* enabled) {
  PaletteTraceEnabledMethod m = PaletteLoader::Instance().GetPaletteTraceEnabledMethod();
  return m(enabled);
}

palette_status_t PaletteTraceBegin(/*in*/const char* name) {
  PaletteTraceBeginMethod m = PaletteLoader::Instance().GetPaletteTraceBeginMethod();
  return m(name);
}

palette_status_t PaletteTraceEnd() {
  PaletteTraceEndMethod m = PaletteLoader::Instance().GetPaletteTraceEndMethod();
  return m();
}

palette_status_t PaletteTraceIntegerValue(/*in*/const char* name, int32_t value) {
  PaletteTraceIntegerValueMethod m = PaletteLoader::Instance().GetPaletteTraceIntegerValueMethod();
  return m(name, value);
}

palette_status_t PaletteAshmemCreateRegion(const char* name, size_t size, int* fd) {
  PaletteAshmemCreateRegionMethod m =
      PaletteLoader::Instance().GetPaletteAshmemCreateRegionMethod();
  return m(name, size, fd);
}

palette_status_t PaletteAshmemSetProtRegion(int fd, int prot) {
  PaletteAshmemSetProtRegionMethod m =
      PaletteLoader::Instance().GetPaletteAshmemSetProtRegionMethod();
  return m(fd, prot);
}

palette_status_t PaletteCreateOdrefreshStagingDirectory(const char** staging_dir) {
  PaletteCreateOdrefreshStagingDirectoryMethod m =
      PaletteLoader::Instance().GetPaletteCreateOdrefreshStagingDirectoryMethod();
  return m(staging_dir);
}

palette_status_t PaletteShouldReportDex2oatCompilation(bool* value) {
  PaletteShouldReportDex2oatCompilationMethod m =
      PaletteLoader::Instance().GetPaletteShouldReportDex2oatCompilationMethod();
  return m(value);
}

palette_status_t PaletteNotifyStartDex2oatCompilation(int source_fd,
                                                      int art_fd,
                                                      int oat_fd,
                                                      int vdex_fd) {
  PaletteNotifyStartDex2oatCompilationMethod m =
      PaletteLoader::Instance().GetPaletteNotifyStartDex2oatCompilationMethod();
  return m(source_fd, art_fd, oat_fd, vdex_fd);
}

palette_status_t PaletteNotifyEndDex2oatCompilation(int source_fd,
                                                    int art_fd,
                                                    int oat_fd,
                                                    int vdex_fd) {
  PaletteNotifyEndDex2oatCompilationMethod m =
      PaletteLoader::Instance().GetPaletteNotifyEndDex2oatCompilationMethod();
  return m(source_fd, art_fd, oat_fd, vdex_fd);
}

palette_status_t PaletteNotifyDexFileLoaded(const char* path) {
  PaletteNotifyDexFileLoadedMethod m =
      PaletteLoader::Instance().GetPaletteNotifyDexFileLoadedMethod();
  return m(path);
}

palette_status_t PaletteNotifyOatFileLoaded(const char* path) {
  PaletteNotifyOatFileLoadedMethod m =
      PaletteLoader::Instance().GetPaletteNotifyOatFileLoadedMethod();
  return m(path);
}

palette_status_t PaletteShouldReportJniInvocations(bool* value) {
  PaletteShouldReportJniInvocationsMethod m =
      PaletteLoader::Instance().GetPaletteShouldReportJniInvocationsMethod();
  return m(value);
}

palette_status_t PaletteNotifyBeginJniInvocation(JNIEnv* env) {
  PaletteNotifyBeginJniInvocationMethod m =
      PaletteLoader::Instance().GetPaletteNotifyBeginJniInvocationMethod();
  return m(env);
}

palette_status_t PaletteNotifyEndJniInvocation(JNIEnv* env) {
  PaletteNotifyEndJniInvocationMethod m =
      PaletteLoader::Instance().GetPaletteNotifyEndJniInvocationMethod();
  return m(env);
}

palette_status_t PaletteReportLockContention(JNIEnv* env,
                                             int32_t wait_ms,
                                             const char* filename,
                                             int32_t line_number,
                                             const char* method_name,
                                             const char* owner_filename,
                                             int32_t owner_line_number,
                                             const char* owner_method_name,
                                             const char* proc_name,
                                             const char* thread_name) {
  PaletteReportLockContentionMethod m =
      PaletteLoader::Instance().GetPaletteReportLockContentionMethod();
  return m(env,
           wait_ms,
           filename,
           line_number,
           method_name,
           owner_filename,
           owner_line_number,
           owner_method_name,
           proc_name,
           thread_name);
}

}  // extern "C"
