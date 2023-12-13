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
#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include "base/EintrWrapper.h"
#include "base/SharedMemory.h"
#include "base/PathUtils.h"
#ifndef _MSC_VER
#include <unistd.h>
#endif

namespace android {
namespace base {

SharedMemory::SharedMemory(const std::string& name, size_t size) : mSize(size) {
    const std::string& kFileUri = "file://";
    if (name.find(kFileUri, 0) == 0) {
        mShareType = ShareType::FILE_BACKED;
        auto path = name.substr(kFileUri.size());
        mName = PathUtils::recompose(PathUtils::decompose(std::move(path)));
    } else {
        mShareType = ShareType::SHARED_MEMORY;
        mName = name;
    }
}

int SharedMemory::create(mode_t mode) {
    return openInternal(O_CREAT | O_RDWR, mode);
}

int SharedMemory::createNoMapping(mode_t mode) {
    return openInternal(O_CREAT | O_RDWR, mode, false /* no mapping */);
}

int SharedMemory::open(AccessMode access) {
    int oflag = O_RDONLY;
    int mode = 0400;
    if (access == AccessMode::READ_WRITE) {
        oflag = O_RDWR;
        mode = 0600;
    }
    return openInternal(oflag, mode);
}

void SharedMemory::close(bool forceDestroy) {
    if (mAddr != unmappedMemory()) {
        munmap(mAddr, mSize);
        mAddr = unmappedMemory();
    }
    if (mFd) {
        ::close(mFd);
        mFd = invalidHandle();
    }

    assert(!isOpen());
    if (forceDestroy || mCreate) {
        if (mShareType == ShareType::FILE_BACKED) {
            remove(mName.c_str());
        } else {
            shm_unlink(mName.c_str());
        }
    }
}

bool SharedMemory::isOpen() const {
    return mFd != invalidHandle();
}

int SharedMemory::openInternal(int oflag, int mode, bool doMapping) {
    if (isOpen()) {
        return EEXIST;
    }

    int err = 0;
    struct stat sb;
    if (mShareType == ShareType::SHARED_MEMORY) {
        mFd = shm_open(mName.c_str(), oflag, mode);
    } else {
        mFd = ::open(mName.c_str(), oflag, mode);
        // Make sure the file can hold at least mSize bytes..
        struct stat stat;
        if (!fstat(mFd, &stat) && stat.st_size < mSize) {
            ftruncate(mFd, mSize);
        }
    }
    if (mFd == -1) {
        err = -errno;
        close();
        return err;
    }

    if (oflag & O_CREAT) {
        if (HANDLE_EINTR(fstat(mFd, &sb)) == -1) {
            err = -errno;
            close();
            return err;
        }

        // Only increase size, as we don't want to yank away memory
        // from another process.
        if (mSize > sb.st_size && HANDLE_EINTR(ftruncate(mFd, mSize)) == -1) {
            err = -errno;
            close();
            return err;
        }
    }

    if (doMapping) {
        int mapFlags = PROT_READ;
        if (oflag & O_RDWR || oflag & O_CREAT) {
            mapFlags |= PROT_WRITE;
        }

        mAddr = mmap(nullptr, mSize, mapFlags, MAP_SHARED, mFd, 0);
        if (mAddr == unmappedMemory()) {
            err = -errno;
            close();
            return err;
        }
    }

    mCreate |= (oflag & O_CREAT);
    assert(isOpen());
    return 0;
}
}  // namespace base
}  // namespace android
