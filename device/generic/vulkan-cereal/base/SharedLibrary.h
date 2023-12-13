// Copyright (C) 2014 The Android Open Source Project
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

#ifndef EMUGL_COMMON_SHARED_LIBRARY_H
#define EMUGL_COMMON_SHARED_LIBRARY_H

#include <stddef.h>
#include <memory>
#include <string>
#include <unordered_map>

#ifdef _WIN32
#include <windows.h>
#endif

#ifdef _MSC_VER
# ifdef BUILDING_EMUGL_COMMON_SHARED
#  define EMUGL_COMMON_API __declspec(dllexport)
# else
#  define EMUGL_COMMON_API __declspec(dllimport)
#endif
#else
# define EMUGL_COMMON_API
#endif

namespace android {
namespace base {

// A class used to open a platform-specific shared library, and probe
// it for symbols. Usage is the following:
//
//    // Open the library.
//    SharedLibrary* library = SharedLibrary::open("libFoo");
//    if (!library) {
//        ... could not find / open library!
//    }
//
//    //Probe for function symbol.
//    FunctionPtr my_func = library->findSymbol("my_func");
//
//  A shared library will be unloaded on program exit.
class EMUGL_COMMON_API SharedLibrary {
private:
    struct Deleter {
        void operator()(SharedLibrary* lib) const { delete lib; }
    };

public:
    typedef std::unordered_map<
            std::string,
            std::unique_ptr<SharedLibrary, SharedLibrary::Deleter>>
            LibraryMap;

    // Open a given library.  If |libraryName| has no extension, a
    // platform-appropriate extension is added and that path is opened.
    // If the |libraryName| has an extension, that form is opened.
    //
    // On OSX, some libraries don't include an extension (notably OpenGL)
    // On OSX we try to open |libraryName| first.  If that doesn't exist,
    // we try |libraryName|.dylib
    //
    // On success, returns a new SharedLibrary instance that must be
    // deleted by the caller.
    static SharedLibrary* open(const char* libraryName);

    // A variant of open() that can report a human-readable error if loading
    // the library fails. |error| is a caller-provided buffer of |errorSize|
    // bytes that will be filled with snprintf() and always zero terminated.
    //
    // On success, return a new SharedLibrary instance, and do not touch
    // the content of |error|. On failure, return NULL, and sets the content
    // of |error|.
    static SharedLibrary* open(const char* libraryName,
                               char* error,
                               size_t errorSize);

    // Adds an extra path to search for libraries.
    static void addLibrarySearchPath(const char* path);

    // Generic function pointer type, for values returned by the
    // findSymbol() method.
    typedef void (*FunctionPtr)(void);

    // Probe a given SharedLibrary instance to find a symbol named
    // |symbolName| in it. Return its address as a FunctionPtr, or
    // NULL if the symbol is not found.
    FunctionPtr findSymbol(const char* symbolName) const;

private:

    static SharedLibrary* do_open(const char* libraryName,
                               char* error,
                               size_t errorSize);
#ifdef _WIN32
    typedef HMODULE HandleType;
#else
    typedef void* HandleType;
#endif

    // Constructor intentionally hidden.
    SharedLibrary(HandleType);

    // Closes an existing SharedLibrary hidden so nobody
    // starts accidently cleaning up these libraries.
    ~SharedLibrary();


    HandleType mLib;
};

#  define EMUGL_LIBNAME(name) "lib" name

}  // namespace base
}  // namespace android

#undef EMUGL_COMMON_API
#endif  // EMUGL_COMMON_SHARED_LIBRARY_H
