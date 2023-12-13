/*
 * Copyright (C) 2019 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#include <private/bionic_ifuncs.h>
#include <stddef.h>
#include <sys/auxv.h>

extern "C" {

typedef void* memchr_func(const void*, int, size_t);
DEFINE_IFUNC_FOR(memchr) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(memchr_func, __memchr_aarch64_mte);
    } else {
        RETURN_FUNC(memchr_func, __memchr_aarch64);
    }
}

typedef int stpcpy_func(char*, const char*);
DEFINE_IFUNC_FOR(stpcpy) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(stpcpy_func, __stpcpy_aarch64_mte);
    } else {
        RETURN_FUNC(stpcpy_func, __stpcpy_aarch64);
    }
}

typedef char* strchr_func(const char*, int);
DEFINE_IFUNC_FOR(strchr) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strchr_func, __strchr_aarch64_mte);
    } else {
        RETURN_FUNC(strchr_func, __strchr_aarch64);
    }
}

typedef char* strchrnul_func(const char*, int);
DEFINE_IFUNC_FOR(strchrnul) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strchrnul_func, __strchrnul_aarch64_mte);
    } else {
        RETURN_FUNC(strchrnul_func, __strchrnul_aarch64);
    }
}

typedef int strcmp_func(const char*, const char*);
DEFINE_IFUNC_FOR(strcmp) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strcmp_func, __strcmp_aarch64_mte);
    } else {
        RETURN_FUNC(strcmp_func, __strcmp_aarch64);
    }
}

typedef int strcpy_func(char*, const char*);
DEFINE_IFUNC_FOR(strcpy) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strcpy_func, __strcpy_aarch64_mte);
    } else {
        RETURN_FUNC(strcpy_func, __strcpy_aarch64);
    }
}

typedef size_t strlen_func(const char*);
DEFINE_IFUNC_FOR(strlen) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strlen_func, __strlen_aarch64_mte);
    } else {
        RETURN_FUNC(strlen_func, __strlen_aarch64);
    }
}

typedef int strncmp_func(const char*, const char*, int);
DEFINE_IFUNC_FOR(strncmp) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strncmp_func, __strncmp_aarch64_mte);
    } else {
        RETURN_FUNC(strncmp_func, __strncmp_aarch64);
    }
}

typedef char* strrchr_func(const char*, int);
DEFINE_IFUNC_FOR(strrchr) {
    if (arg->_hwcap2 & HWCAP2_MTE) {
        RETURN_FUNC(strrchr_func, __strrchr_aarch64_mte);
    } else {
        RETURN_FUNC(strrchr_func, __strrchr_aarch64);
    }
}

}  // extern "C"
