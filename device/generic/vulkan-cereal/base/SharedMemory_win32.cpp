// Copyright 2020 The Android Open Source Project
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
#include "base/SharedMemory.h"

#include <shlwapi.h>
#include <cassert>
#include <string>

#include "base/PathUtils.h"
#include "base/Win32UnicodeString.h"

namespace android {
namespace base {

SharedMemory::SharedMemory(const std::string& name, size_t size) : mSize(size) {
    const std::string kFileUri = "file://";
    if (name.find(kFileUri, 0) == 0) {
        // Convert URI to path using win32 api.
        const Win32UnicodeString srcUri(name);
        WCHAR path[MAX_PATH];
        DWORD cPath = MAX_PATH;
        auto HR = PathCreateFromUrlW(srcUri.c_str(), path, &cPath, NULL);
        assert(HR == S_OK);
        const Win32UnicodeString destPath(path);
        mName = PathUtils::recompose(PathUtils::decompose(destPath.toString()));
        mShareType = ShareType::FILE_BACKED;
    } else {
        mShareType = ShareType::SHARED_MEMORY;
        mName = "SHM_" + name;
    }
}

// Creates a shared region, you will be considered the owner, and will have
// write access. Returns 0 on success, or an error code otheriwse.
int SharedMemory::create(mode_t mode) {
    return openInternal(AccessMode::READ_WRITE);
}

int SharedMemory::createNoMapping(mode_t mode) {
    return openInternal(AccessMode::READ_WRITE, false /* no mapping */);
}

// Opens the shared memory object, returns 0 on success
// or the error code.
int SharedMemory::open(AccessMode access) {
    return openInternal(access);
}

int SharedMemory::openInternal(AccessMode access, bool doMapping) {
    if (mCreate) {
        return EEXIST;
    }
    LARGE_INTEGER memory;
    memory.QuadPart = (LONGLONG)mSize;

    // Allows views to be mapped for read-only or copy-on-write access.
    DWORD protection = PAGE_READONLY;

    if (access == AccessMode::READ_WRITE) {
        // Allows views to be mapped for read-only, copy-on-write, or read/write
        // access.
        protection = PAGE_READWRITE;
    }
    const Win32UnicodeString name(mName);
    auto objectName = name.c_str();

    if (mShareType == ShareType::FILE_BACKED) {
        auto fileOptions = GENERIC_READ;
        // File sharing permissions must be the same for readers/writers.
        // otherwise readers will not be able to open the file.
        auto fileShare = FILE_SHARE_READ | FILE_SHARE_WRITE;
        auto openMode = OPEN_EXISTING;
        if (access == AccessMode::READ_WRITE) {
            fileOptions = GENERIC_READ | GENERIC_WRITE;
            openMode = OPEN_ALWAYS;
        }
        mFile = CreateFileW(objectName, fileOptions, fileShare, NULL, openMode,
                            FILE_FLAG_RANDOM_ACCESS, NULL);
        if (mFile == INVALID_HANDLE_VALUE) {
            int err = -GetLastError();
            close();
            return err;
        }
        objectName = nullptr;
    }

    HANDLE hMapFile = CreateFileMappingW(
            mFile,
            NULL,             // default security
            protection,       // read/write access
            memory.HighPart,  // maximum object size (high-order DWORD)
            memory.LowPart,   // maximum object size (low-order DWORD)
            objectName);      // name of mapping object

    if (hMapFile == NULL) {
        int err = -GetLastError();
        close();
        return err;
    }

    if (doMapping) {
        // MapViewOfFile has a slightly different way of naming protection.
        protection = FILE_MAP_READ;
        if (access == AccessMode::READ_WRITE) {
            protection = FILE_MAP_WRITE;
        }

        mAddr = MapViewOfFile(hMapFile, protection, 0, 0, mSize);

        if (mAddr == NULL) {
            int err = -GetLastError();
            close();
            return err;
        }
    }

    mFd = hMapFile;
    mCreate = true;
    return 0;
}

void SharedMemory::close(bool forceDestroy) {
    if (mAddr != unmappedMemory()) {
        UnmapViewOfFile(mAddr);
        mAddr = unmappedMemory();
    }
    if (mFd) {
        CloseHandle(mFd);
        mFd = invalidHandle();
    }
    if (mFile) {
        CloseHandle(mFile);
        mFile = invalidHandle();
        if ((forceDestroy || mCreate) && mShareType == ShareType::FILE_BACKED) {
            const Win32UnicodeString name(mName);
            DeleteFileW(name.c_str());
        }
    }

    assert(!isOpen());
}

bool SharedMemory::isOpen() const {
    return mFd != invalidHandle();
}

}  // namespace base
}  // namespace android
