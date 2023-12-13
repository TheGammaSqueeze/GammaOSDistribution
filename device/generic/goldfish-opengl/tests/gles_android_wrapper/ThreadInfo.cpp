/*
* Copyright (C) 2011 The Android Open Source Project
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include "ThreadInfo.h"

#include <pthread.h>

static pthread_key_t s_tls;

static void tlsDestruct(void *ptr)
{
    if (ptr) {
        EGLThreadInfo *ti = (EGLThreadInfo *)ptr;
        delete ti->serverConn;
        delete ti;
    }
}

static void init_key()
{
    pthread_key_create(&s_tls, tlsDestruct);
    pthread_setspecific(s_tls, new EGLThreadInfo);
}

EGLThreadInfo *getEGLThreadInfo()
{
    static pthread_once_t once = PTHREAD_ONCE_INIT;
    pthread_once(&once, init_key);

    return (EGLThreadInfo *) pthread_getspecific(s_tls);
}
