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

/*
 * rsgApi.cpp
 * This file implements the functions responsible for sending messages
 * to the RS driver layer. The messages are sent through a FIFO that is
 * shared between the process's caller threads and driver thread.
 */

#include "rsDevice.h"
#include "rsContext.h"
#include "rsThreadIO.h"
#include "rsgApiStructs.h"
#include "rsgApiFuncDecl.h"
#include "rsFifo.h"

using namespace android;  // NOLINT
using namespace android::renderscript;  // NOLINT

static void LF_ContextDestroy (RsContext rsc)
{
    rsi_ContextDestroy((Context *)rsc);
};

static RsMessageToClientType LF_ContextGetMessage (RsContext rsc, void * data, size_t data_length, size_t * receiveLen, size_t receiveLen_length, uint32_t * usrID, size_t usrID_length)
{
    return rsi_ContextGetMessage((Context *)rsc, data, data_length, receiveLen, receiveLen_length, usrID, usrID_length);
};

static RsMessageToClientType LF_ContextPeekMessage (RsContext rsc, size_t * receiveLen, size_t receiveLen_length, uint32_t * usrID, size_t usrID_length)
{
    return rsi_ContextPeekMessage((Context *)rsc, receiveLen, receiveLen_length, usrID, usrID_length);
};

static void LF_ContextSendMessage (RsContext rsc, uint32_t id, const uint8_t * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextSendMessage((Context *)rsc, id, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextSendMessage);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_ContextSendMessage *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_ContextSendMessage *>(io->coreHeader(RS_CMD_ID_ContextSendMessage, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_ContextSendMessage *>(io->coreHeader(RS_CMD_ID_ContextSendMessage, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->id = id;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const uint8_t *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_ContextInitToClient (RsContext rsc)
{
    rsi_ContextInitToClient((Context *)rsc);
};

static void LF_ContextDeinitToClient (RsContext rsc)
{
    rsi_ContextDeinitToClient((Context *)rsc);
};

static void LF_ContextSetCacheDir (RsContext rsc, const char * cacheDir, size_t cacheDir_length)
{
    rsi_ContextSetCacheDir((Context *)rsc, cacheDir, cacheDir_length);
};

static RsType LF_TypeCreate (RsContext rsc, RsElement e, uint32_t dimX, uint32_t dimY, uint32_t dimZ, bool mipmaps, bool faces, uint32_t yuv)
{
    return rsi_TypeCreate((Context *)rsc, e, dimX, dimY, dimZ, mipmaps, faces, yuv);
};

static RsType LF_TypeCreate2 (RsContext rsc, const RsTypeCreateParams * dat, size_t dat_length)
{
    return rsi_TypeCreate2((Context *)rsc, dat, dat_length);
};

static RsAllocation LF_AllocationCreateTyped (RsContext rsc, RsType vtype, RsAllocationMipmapControl mipmaps, uint32_t usages, uintptr_t ptr)
{
    return rsi_AllocationCreateTyped((Context *)rsc, vtype, mipmaps, usages, ptr);
};

static RsAllocation LF_AllocationCreateFromBitmap (RsContext rsc, RsType vtype, RsAllocationMipmapControl mipmaps, const void * data, size_t data_length, uint32_t usages)
{
    return rsi_AllocationCreateFromBitmap((Context *)rsc, vtype, mipmaps, data, data_length, usages);
};

static RsAllocation LF_AllocationCubeCreateFromBitmap (RsContext rsc, RsType vtype, RsAllocationMipmapControl mipmaps, const void * data, size_t data_length, uint32_t usages)
{
    return rsi_AllocationCubeCreateFromBitmap((Context *)rsc, vtype, mipmaps, data, data_length, usages);
};

static void LF_AllocationSetupBufferQueue (RsContext rsc, RsAllocation alloc, uint32_t numAlloc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationSetupBufferQueue((Context *)rsc, alloc, numAlloc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationSetupBufferQueue);
    RS_CMD_AllocationSetupBufferQueue *cmd = static_cast<RS_CMD_AllocationSetupBufferQueue *>(io->coreHeader(RS_CMD_ID_AllocationSetupBufferQueue, size));
    cmd->alloc = alloc;
    cmd->numAlloc = numAlloc;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_AllocationShareBufferQueue (RsContext rsc, RsAllocation alloc1, RsAllocation alloc2)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationShareBufferQueue((Context *)rsc, alloc1, alloc2);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationShareBufferQueue);
    RS_CMD_AllocationShareBufferQueue *cmd = static_cast<RS_CMD_AllocationShareBufferQueue *>(io->coreHeader(RS_CMD_ID_AllocationShareBufferQueue, size));
    cmd->alloc1 = alloc1;
    cmd->alloc2 = alloc2;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static RsNativeWindow LF_AllocationGetSurface (RsContext rsc, RsAllocation alloc)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_AllocationGetSurface((Context *)rsc, alloc);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationGetSurface);
    RS_CMD_AllocationGetSurface *cmd = static_cast<RS_CMD_AllocationGetSurface *>(io->coreHeader(RS_CMD_ID_AllocationGetSurface, size));
    cmd->alloc = alloc;
    io->coreCommit();

    RsNativeWindow ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static void LF_AllocationSetSurface (RsContext rsc, RsAllocation alloc, RsNativeWindow sur)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationSetSurface((Context *)rsc, alloc, sur);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationSetSurface);
    RS_CMD_AllocationSetSurface *cmd = static_cast<RS_CMD_AllocationSetSurface *>(io->coreHeader(RS_CMD_ID_AllocationSetSurface, size));
    cmd->alloc = alloc;
    cmd->sur = sur;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static RsAllocation LF_AllocationAdapterCreate (RsContext rsc, RsType vtype, RsAllocation baseAlloc)
{
    return rsi_AllocationAdapterCreate((Context *)rsc, vtype, baseAlloc);
};

static void LF_AllocationAdapterOffset (RsContext rsc, RsAllocation alloc, const uint32_t * offsets, size_t offsets_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationAdapterOffset((Context *)rsc, alloc, offsets, offsets_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationAdapterOffset);
    size_t dataSize = 0;
    dataSize += offsets_length;
    RS_CMD_AllocationAdapterOffset *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_AllocationAdapterOffset *>(io->coreHeader(RS_CMD_ID_AllocationAdapterOffset, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_AllocationAdapterOffset *>(io->coreHeader(RS_CMD_ID_AllocationAdapterOffset, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->alloc = alloc;
    if (offsets_length == 0) {
        cmd->offsets = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, offsets, offsets_length);
        cmd->offsets = (const uint32_t *)(payload - ((uint8_t *)&cmd[1]));
        payload += offsets_length;
    } else {
        cmd->offsets = offsets;
    }
    cmd->offsets_length = offsets_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_ContextFinish (RsContext rsc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextFinish((Context *)rsc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextFinish);
    RS_CMD_ContextFinish *cmd = static_cast<RS_CMD_ContextFinish *>(io->coreHeader(RS_CMD_ID_ContextFinish, size));
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_ContextDump (RsContext rsc, int32_t bits)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextDump((Context *)rsc, bits);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextDump);
    RS_CMD_ContextDump *cmd = static_cast<RS_CMD_ContextDump *>(io->coreHeader(RS_CMD_ID_ContextDump, size));
    cmd->bits = bits;
    io->coreCommit();
};

static void LF_ContextSetPriority (RsContext rsc, int32_t priority)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextSetPriority((Context *)rsc, priority);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextSetPriority);
    RS_CMD_ContextSetPriority *cmd = static_cast<RS_CMD_ContextSetPriority *>(io->coreHeader(RS_CMD_ID_ContextSetPriority, size));
    cmd->priority = priority;
    io->coreCommit();
};

static void LF_ContextDestroyWorker (RsContext rsc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextDestroyWorker((Context *)rsc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextDestroyWorker);
    RS_CMD_ContextDestroyWorker *cmd = static_cast<RS_CMD_ContextDestroyWorker *>(io->coreHeader(RS_CMD_ID_ContextDestroyWorker, size));
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_AssignName (RsContext rsc, RsObjectBase obj, const char * name, size_t name_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AssignName((Context *)rsc, obj, name, name_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AssignName);
    size_t dataSize = 0;
    dataSize += name_length;
    RS_CMD_AssignName *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_AssignName *>(io->coreHeader(RS_CMD_ID_AssignName, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_AssignName *>(io->coreHeader(RS_CMD_ID_AssignName, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->obj = obj;
    if (name_length == 0) {
        cmd->name = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, name, name_length);
        cmd->name = (const char *)(payload - ((uint8_t *)&cmd[1]));
        payload += name_length;
    } else {
        cmd->name = name;
    }
    cmd->name_length = name_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_ObjDestroy (RsContext rsc, RsAsyncVoidPtr objPtr)
{
    LF_ObjDestroy_handcode((Context *)rsc, objPtr);
};

static RsElement LF_ElementCreate (RsContext rsc, RsDataType mType, RsDataKind mKind, bool mNormalized, uint32_t mVectorSize)
{
    return rsi_ElementCreate((Context *)rsc, mType, mKind, mNormalized, mVectorSize);
};

static RsElement LF_ElementCreate2 (RsContext rsc, const RsElement * elements, size_t elements_length, const char ** names, size_t names_length_length, const size_t * names_length, const uint32_t * arraySize, size_t arraySize_length)
{
    return rsi_ElementCreate2((Context *)rsc, elements, elements_length, names, names_length_length, names_length, arraySize, arraySize_length);
};

static void LF_AllocationCopyToBitmap (RsContext rsc, RsAllocation alloc, void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationCopyToBitmap((Context *)rsc, alloc, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationCopyToBitmap);
    RS_CMD_AllocationCopyToBitmap *cmd = static_cast<RS_CMD_AllocationCopyToBitmap *>(io->coreHeader(RS_CMD_ID_AllocationCopyToBitmap, size));
    cmd->alloc = alloc;
    cmd->data = data;
    cmd->data_length = data_length;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void * LF_AllocationGetPointer (RsContext rsc, RsAllocation va, uint32_t lod, RsAllocationCubemapFace face, uint32_t z, uint32_t array, size_t * stride, size_t stride_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_AllocationGetPointer((Context *)rsc, va, lod, face, z, array, stride, stride_length);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationGetPointer);
    RS_CMD_AllocationGetPointer *cmd = static_cast<RS_CMD_AllocationGetPointer *>(io->coreHeader(RS_CMD_ID_AllocationGetPointer, size));
    cmd->va = va;
    cmd->lod = lod;
    cmd->face = face;
    cmd->z = z;
    cmd->array = array;
    cmd->stride = stride;
    cmd->stride_length = stride_length;
    io->coreCommit();

    void * ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static void LF_Allocation1DData (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t lod, uint32_t count, const void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation1DData((Context *)rsc, va, xoff, lod, count, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation1DData);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_Allocation1DData *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_Allocation1DData *>(io->coreHeader(RS_CMD_ID_Allocation1DData, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_Allocation1DData *>(io->coreHeader(RS_CMD_ID_Allocation1DData, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->va = va;
    cmd->xoff = xoff;
    cmd->lod = lod;
    cmd->count = count;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_Allocation1DElementData (RsContext rsc, RsAllocation va, uint32_t x, uint32_t lod, const void * data, size_t data_length, size_t comp_offset)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation1DElementData((Context *)rsc, va, x, lod, data, data_length, comp_offset);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation1DElementData);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_Allocation1DElementData *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_Allocation1DElementData *>(io->coreHeader(RS_CMD_ID_Allocation1DElementData, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_Allocation1DElementData *>(io->coreHeader(RS_CMD_ID_Allocation1DElementData, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->va = va;
    cmd->x = x;
    cmd->lod = lod;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    cmd->comp_offset = comp_offset;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_AllocationElementData (RsContext rsc, RsAllocation va, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, const void * data, size_t data_length, size_t comp_offset)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationElementData((Context *)rsc, va, x, y, z, lod, data, data_length, comp_offset);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationElementData);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_AllocationElementData *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_AllocationElementData *>(io->coreHeader(RS_CMD_ID_AllocationElementData, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_AllocationElementData *>(io->coreHeader(RS_CMD_ID_AllocationElementData, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->va = va;
    cmd->x = x;
    cmd->y = y;
    cmd->z = z;
    cmd->lod = lod;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    cmd->comp_offset = comp_offset;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_Allocation2DData (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t lod, RsAllocationCubemapFace face, uint32_t w, uint32_t h, const void * data, size_t data_length, size_t stride)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation2DData((Context *)rsc, va, xoff, yoff, lod, face, w, h, data, data_length, stride);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation2DData);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_Allocation2DData *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_Allocation2DData *>(io->coreHeader(RS_CMD_ID_Allocation2DData, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_Allocation2DData *>(io->coreHeader(RS_CMD_ID_Allocation2DData, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->va = va;
    cmd->xoff = xoff;
    cmd->yoff = yoff;
    cmd->lod = lod;
    cmd->face = face;
    cmd->w = w;
    cmd->h = h;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    cmd->stride = stride;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_Allocation3DData (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, const void * data, size_t data_length, size_t stride)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation3DData((Context *)rsc, va, xoff, yoff, zoff, lod, w, h, d, data, data_length, stride);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation3DData);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_Allocation3DData *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_Allocation3DData *>(io->coreHeader(RS_CMD_ID_Allocation3DData, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_Allocation3DData *>(io->coreHeader(RS_CMD_ID_Allocation3DData, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->va = va;
    cmd->xoff = xoff;
    cmd->yoff = yoff;
    cmd->zoff = zoff;
    cmd->lod = lod;
    cmd->w = w;
    cmd->h = h;
    cmd->d = d;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    cmd->stride = stride;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_AllocationGenerateMipmaps (RsContext rsc, RsAllocation va)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationGenerateMipmaps((Context *)rsc, va);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationGenerateMipmaps);
    RS_CMD_AllocationGenerateMipmaps *cmd = static_cast<RS_CMD_AllocationGenerateMipmaps *>(io->coreHeader(RS_CMD_ID_AllocationGenerateMipmaps, size));
    cmd->va = va;
    io->coreCommit();
};

static void LF_AllocationRead (RsContext rsc, RsAllocation va, void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationRead((Context *)rsc, va, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationRead);
    RS_CMD_AllocationRead *cmd = static_cast<RS_CMD_AllocationRead *>(io->coreHeader(RS_CMD_ID_AllocationRead, size));
    cmd->va = va;
    cmd->data = data;
    cmd->data_length = data_length;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_Allocation1DRead (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t lod, uint32_t count, void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation1DRead((Context *)rsc, va, xoff, lod, count, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation1DRead);
    RS_CMD_Allocation1DRead *cmd = static_cast<RS_CMD_Allocation1DRead *>(io->coreHeader(RS_CMD_ID_Allocation1DRead, size));
    cmd->va = va;
    cmd->xoff = xoff;
    cmd->lod = lod;
    cmd->count = count;
    cmd->data = data;
    cmd->data_length = data_length;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_AllocationElementRead (RsContext rsc, RsAllocation va, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, void * data, size_t data_length, size_t comp_offset)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationElementRead((Context *)rsc, va, x, y, z, lod, data, data_length, comp_offset);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationElementRead);
    RS_CMD_AllocationElementRead *cmd = static_cast<RS_CMD_AllocationElementRead *>(io->coreHeader(RS_CMD_ID_AllocationElementRead, size));
    cmd->va = va;
    cmd->x = x;
    cmd->y = y;
    cmd->z = z;
    cmd->lod = lod;
    cmd->data = data;
    cmd->data_length = data_length;
    cmd->comp_offset = comp_offset;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_Allocation2DRead (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t lod, RsAllocationCubemapFace face, uint32_t w, uint32_t h, void * data, size_t data_length, size_t stride)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation2DRead((Context *)rsc, va, xoff, yoff, lod, face, w, h, data, data_length, stride);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation2DRead);
    RS_CMD_Allocation2DRead *cmd = static_cast<RS_CMD_Allocation2DRead *>(io->coreHeader(RS_CMD_ID_Allocation2DRead, size));
    cmd->va = va;
    cmd->xoff = xoff;
    cmd->yoff = yoff;
    cmd->lod = lod;
    cmd->face = face;
    cmd->w = w;
    cmd->h = h;
    cmd->data = data;
    cmd->data_length = data_length;
    cmd->stride = stride;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_Allocation3DRead (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, void * data, size_t data_length, size_t stride)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_Allocation3DRead((Context *)rsc, va, xoff, yoff, zoff, lod, w, h, d, data, data_length, stride);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_Allocation3DRead);
    RS_CMD_Allocation3DRead *cmd = static_cast<RS_CMD_Allocation3DRead *>(io->coreHeader(RS_CMD_ID_Allocation3DRead, size));
    cmd->va = va;
    cmd->xoff = xoff;
    cmd->yoff = yoff;
    cmd->zoff = zoff;
    cmd->lod = lod;
    cmd->w = w;
    cmd->h = h;
    cmd->d = d;
    cmd->data = data;
    cmd->data_length = data_length;
    cmd->stride = stride;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_AllocationSyncAll (RsContext rsc, RsAllocation va, RsAllocationUsageType src)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationSyncAll((Context *)rsc, va, src);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationSyncAll);
    RS_CMD_AllocationSyncAll *cmd = static_cast<RS_CMD_AllocationSyncAll *>(io->coreHeader(RS_CMD_ID_AllocationSyncAll, size));
    cmd->va = va;
    cmd->src = src;
    io->coreCommit();
};

static void LF_AllocationResize1D (RsContext rsc, RsAllocation va, uint32_t dimX)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationResize1D((Context *)rsc, va, dimX);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationResize1D);
    RS_CMD_AllocationResize1D *cmd = static_cast<RS_CMD_AllocationResize1D *>(io->coreHeader(RS_CMD_ID_AllocationResize1D, size));
    cmd->va = va;
    cmd->dimX = dimX;
    io->coreCommit();
};

static void LF_AllocationCopy2DRange (RsContext rsc, RsAllocation dest, uint32_t destXoff, uint32_t destYoff, uint32_t destMip, uint32_t destFace, uint32_t width, uint32_t height, RsAllocation src, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcMip, uint32_t srcFace)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationCopy2DRange((Context *)rsc, dest, destXoff, destYoff, destMip, destFace, width, height, src, srcXoff, srcYoff, srcMip, srcFace);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationCopy2DRange);
    RS_CMD_AllocationCopy2DRange *cmd = static_cast<RS_CMD_AllocationCopy2DRange *>(io->coreHeader(RS_CMD_ID_AllocationCopy2DRange, size));
    cmd->dest = dest;
    cmd->destXoff = destXoff;
    cmd->destYoff = destYoff;
    cmd->destMip = destMip;
    cmd->destFace = destFace;
    cmd->width = width;
    cmd->height = height;
    cmd->src = src;
    cmd->srcXoff = srcXoff;
    cmd->srcYoff = srcYoff;
    cmd->srcMip = srcMip;
    cmd->srcFace = srcFace;
    io->coreCommit();
};

static void LF_AllocationCopy3DRange (RsContext rsc, RsAllocation dest, uint32_t destXoff, uint32_t destYoff, uint32_t destZoff, uint32_t destMip, uint32_t width, uint32_t height, uint32_t depth, RsAllocation src, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcZoff, uint32_t srcMip)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationCopy3DRange((Context *)rsc, dest, destXoff, destYoff, destZoff, destMip, width, height, depth, src, srcXoff, srcYoff, srcZoff, srcMip);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationCopy3DRange);
    RS_CMD_AllocationCopy3DRange *cmd = static_cast<RS_CMD_AllocationCopy3DRange *>(io->coreHeader(RS_CMD_ID_AllocationCopy3DRange, size));
    cmd->dest = dest;
    cmd->destXoff = destXoff;
    cmd->destYoff = destYoff;
    cmd->destZoff = destZoff;
    cmd->destMip = destMip;
    cmd->width = width;
    cmd->height = height;
    cmd->depth = depth;
    cmd->src = src;
    cmd->srcXoff = srcXoff;
    cmd->srcYoff = srcYoff;
    cmd->srcZoff = srcZoff;
    cmd->srcMip = srcMip;
    io->coreCommit();
};

static RsClosure LF_ClosureCreate (RsContext rsc, RsScriptKernelID kernelID, RsAllocation returnValue, RsScriptFieldID * fieldIDs, size_t fieldIDs_length, const int64_t * values, size_t values_length, const int * sizes, size_t sizes_length, RsClosure * depClosures, size_t depClosures_length, RsScriptFieldID * depFieldIDs, size_t depFieldIDs_length)
{
    return rsi_ClosureCreate((Context *)rsc, kernelID, returnValue, fieldIDs, fieldIDs_length, values, values_length, sizes, sizes_length, depClosures, depClosures_length, depFieldIDs, depFieldIDs_length);
};

static RsClosure LF_InvokeClosureCreate (RsContext rsc, RsScriptInvokeID invokeID, const void * params, size_t params_length, const RsScriptFieldID * fieldIDs, size_t fieldIDs_length, const int64_t * values, size_t values_length, const int * sizes, size_t sizes_length)
{
    return rsi_InvokeClosureCreate((Context *)rsc, invokeID, params, params_length, fieldIDs, fieldIDs_length, values, values_length, sizes, sizes_length);
};

static void LF_ClosureSetArg (RsContext rsc, RsClosure closureID, uint32_t index, uintptr_t value, int valueSize)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ClosureSetArg((Context *)rsc, closureID, index, value, valueSize);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ClosureSetArg);
    RS_CMD_ClosureSetArg *cmd = static_cast<RS_CMD_ClosureSetArg *>(io->coreHeader(RS_CMD_ID_ClosureSetArg, size));
    cmd->closureID = closureID;
    cmd->index = index;
    cmd->value = value;
    cmd->valueSize = valueSize;
    io->coreCommit();
};

static void LF_ClosureSetGlobal (RsContext rsc, RsClosure closureID, RsScriptFieldID fieldID, int64_t value, int valueSize)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ClosureSetGlobal((Context *)rsc, closureID, fieldID, value, valueSize);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ClosureSetGlobal);
    RS_CMD_ClosureSetGlobal *cmd = static_cast<RS_CMD_ClosureSetGlobal *>(io->coreHeader(RS_CMD_ID_ClosureSetGlobal, size));
    cmd->closureID = closureID;
    cmd->fieldID = fieldID;
    cmd->value = value;
    cmd->valueSize = valueSize;
    io->coreCommit();
};

static RsSampler LF_SamplerCreate (RsContext rsc, RsSamplerValue magFilter, RsSamplerValue minFilter, RsSamplerValue wrapS, RsSamplerValue wrapT, RsSamplerValue wrapR, float mAniso)
{
    return rsi_SamplerCreate((Context *)rsc, magFilter, minFilter, wrapS, wrapT, wrapR, mAniso);
};

static void LF_ScriptBindAllocation (RsContext rsc, RsScript vtm, RsAllocation va, uint32_t slot)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptBindAllocation((Context *)rsc, vtm, va, slot);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptBindAllocation);
    RS_CMD_ScriptBindAllocation *cmd = static_cast<RS_CMD_ScriptBindAllocation *>(io->coreHeader(RS_CMD_ID_ScriptBindAllocation, size));
    cmd->vtm = vtm;
    cmd->va = va;
    cmd->slot = slot;
    io->coreCommit();
};

static void LF_ScriptSetTimeZone (RsContext rsc, RsScript s, const char * timeZone, size_t timeZone_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetTimeZone((Context *)rsc, s, timeZone, timeZone_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetTimeZone);
    size_t dataSize = 0;
    dataSize += timeZone_length;
    RS_CMD_ScriptSetTimeZone *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_ScriptSetTimeZone *>(io->coreHeader(RS_CMD_ID_ScriptSetTimeZone, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_ScriptSetTimeZone *>(io->coreHeader(RS_CMD_ID_ScriptSetTimeZone, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->s = s;
    if (timeZone_length == 0) {
        cmd->timeZone = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, timeZone, timeZone_length);
        cmd->timeZone = (const char *)(payload - ((uint8_t *)&cmd[1]));
        payload += timeZone_length;
    } else {
        cmd->timeZone = timeZone;
    }
    cmd->timeZone_length = timeZone_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static RsScriptInvokeID LF_ScriptInvokeIDCreate (RsContext rsc, RsScript s, uint32_t slot)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_ScriptInvokeIDCreate((Context *)rsc, s, slot);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptInvokeIDCreate);
    RS_CMD_ScriptInvokeIDCreate *cmd = static_cast<RS_CMD_ScriptInvokeIDCreate *>(io->coreHeader(RS_CMD_ID_ScriptInvokeIDCreate, size));
    cmd->s = s;
    cmd->slot = slot;
    io->coreCommit();

    RsScriptInvokeID ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static void LF_ScriptInvoke (RsContext rsc, RsScript s, uint32_t slot)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptInvoke((Context *)rsc, s, slot);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptInvoke);
    RS_CMD_ScriptInvoke *cmd = static_cast<RS_CMD_ScriptInvoke *>(io->coreHeader(RS_CMD_ID_ScriptInvoke, size));
    cmd->s = s;
    cmd->slot = slot;
    io->coreCommit();
};

static void LF_ScriptInvokeV (RsContext rsc, RsScript s, uint32_t slot, const void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptInvokeV((Context *)rsc, s, slot, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptInvokeV);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_ScriptInvokeV *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_ScriptInvokeV *>(io->coreHeader(RS_CMD_ID_ScriptInvokeV, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_ScriptInvokeV *>(io->coreHeader(RS_CMD_ID_ScriptInvokeV, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->s = s;
    cmd->slot = slot;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_ScriptForEach (RsContext rsc, RsScript s, uint32_t slot, RsAllocation ain, RsAllocation aout, const void * usr, size_t usr_length, const RsScriptCall * sc, size_t sc_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptForEach((Context *)rsc, s, slot, ain, aout, usr, usr_length, sc, sc_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptForEach);
    size_t dataSize = 0;
    dataSize += usr_length;
    dataSize += sc_length;
    RS_CMD_ScriptForEach *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_ScriptForEach *>(io->coreHeader(RS_CMD_ID_ScriptForEach, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_ScriptForEach *>(io->coreHeader(RS_CMD_ID_ScriptForEach, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->s = s;
    cmd->slot = slot;
    cmd->ain = ain;
    cmd->aout = aout;
    if (usr_length == 0) {
        cmd->usr = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, usr, usr_length);
        cmd->usr = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += usr_length;
    } else {
        cmd->usr = usr;
    }
    cmd->usr_length = usr_length;
    if (sc_length == 0) {
        cmd->sc = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, sc, sc_length);
        cmd->sc = (const RsScriptCall *)(payload - ((uint8_t *)&cmd[1]));
        payload += sc_length;
    } else {
        cmd->sc = sc;
    }
    cmd->sc_length = sc_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_ScriptForEachMulti (RsContext rsc, RsScript s, uint32_t slot, RsAllocation * ains, size_t ains_length, RsAllocation aout, const void * usr, size_t usr_length, const RsScriptCall * sc, size_t sc_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptForEachMulti((Context *)rsc, s, slot, ains, ains_length, aout, usr, usr_length, sc, sc_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptForEachMulti);
    RS_CMD_ScriptForEachMulti *cmd = static_cast<RS_CMD_ScriptForEachMulti *>(io->coreHeader(RS_CMD_ID_ScriptForEachMulti, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->ains = ains;
    cmd->ains_length = ains_length;
    cmd->aout = aout;
    cmd->usr = usr;
    cmd->usr_length = usr_length;
    cmd->sc = sc;
    cmd->sc_length = sc_length;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_ScriptReduce (RsContext rsc, RsScript s, uint32_t slot, RsAllocation * ains, size_t ains_length, RsAllocation aout, const RsScriptCall * sc, size_t sc_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptReduce((Context *)rsc, s, slot, ains, ains_length, aout, sc, sc_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptReduce);
    RS_CMD_ScriptReduce *cmd = static_cast<RS_CMD_ScriptReduce *>(io->coreHeader(RS_CMD_ID_ScriptReduce, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->ains = ains;
    cmd->ains_length = ains_length;
    cmd->aout = aout;
    cmd->sc = sc;
    cmd->sc_length = sc_length;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_ScriptSetVarI (RsContext rsc, RsScript s, uint32_t slot, int value)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarI((Context *)rsc, s, slot, value);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarI);
    RS_CMD_ScriptSetVarI *cmd = static_cast<RS_CMD_ScriptSetVarI *>(io->coreHeader(RS_CMD_ID_ScriptSetVarI, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->value = value;
    io->coreCommit();
};

static void LF_ScriptSetVarObj (RsContext rsc, RsScript s, uint32_t slot, RsObjectBase value)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarObj((Context *)rsc, s, slot, value);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarObj);
    RS_CMD_ScriptSetVarObj *cmd = static_cast<RS_CMD_ScriptSetVarObj *>(io->coreHeader(RS_CMD_ID_ScriptSetVarObj, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->value = value;
    io->coreCommit();
};

static void LF_ScriptSetVarJ (RsContext rsc, RsScript s, uint32_t slot, int64_t value)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarJ((Context *)rsc, s, slot, value);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarJ);
    RS_CMD_ScriptSetVarJ *cmd = static_cast<RS_CMD_ScriptSetVarJ *>(io->coreHeader(RS_CMD_ID_ScriptSetVarJ, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->value = value;
    io->coreCommit();
};

static void LF_ScriptSetVarF (RsContext rsc, RsScript s, uint32_t slot, float value)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarF((Context *)rsc, s, slot, value);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarF);
    RS_CMD_ScriptSetVarF *cmd = static_cast<RS_CMD_ScriptSetVarF *>(io->coreHeader(RS_CMD_ID_ScriptSetVarF, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->value = value;
    io->coreCommit();
};

static void LF_ScriptSetVarD (RsContext rsc, RsScript s, uint32_t slot, double value)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarD((Context *)rsc, s, slot, value);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarD);
    RS_CMD_ScriptSetVarD *cmd = static_cast<RS_CMD_ScriptSetVarD *>(io->coreHeader(RS_CMD_ID_ScriptSetVarD, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->value = value;
    io->coreCommit();
};

static void LF_ScriptSetVarV (RsContext rsc, RsScript s, uint32_t slot, const void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarV((Context *)rsc, s, slot, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarV);
    size_t dataSize = 0;
    dataSize += data_length;
    RS_CMD_ScriptSetVarV *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_ScriptSetVarV *>(io->coreHeader(RS_CMD_ID_ScriptSetVarV, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_ScriptSetVarV *>(io->coreHeader(RS_CMD_ID_ScriptSetVarV, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->s = s;
    cmd->slot = slot;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static void LF_ScriptGetVarV (RsContext rsc, RsScript s, uint32_t slot, void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptGetVarV((Context *)rsc, s, slot, data, data_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptGetVarV);
    RS_CMD_ScriptGetVarV *cmd = static_cast<RS_CMD_ScriptGetVarV *>(io->coreHeader(RS_CMD_ID_ScriptGetVarV, size));
    cmd->s = s;
    cmd->slot = slot;
    cmd->data = data;
    cmd->data_length = data_length;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_ScriptSetVarVE (RsContext rsc, RsScript s, uint32_t slot, const void * data, size_t data_length, RsElement e, const uint32_t * dims, size_t dims_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptSetVarVE((Context *)rsc, s, slot, data, data_length, e, dims, dims_length);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptSetVarVE);
    size_t dataSize = 0;
    dataSize += data_length;
    dataSize += dims_length;
    RS_CMD_ScriptSetVarVE *cmd = NULL;
    if (dataSize < io->getMaxInlineSize()) {;
        cmd = static_cast<RS_CMD_ScriptSetVarVE *>(io->coreHeader(RS_CMD_ID_ScriptSetVarVE, dataSize + size));
    } else {
        cmd = static_cast<RS_CMD_ScriptSetVarVE *>(io->coreHeader(RS_CMD_ID_ScriptSetVarVE, size));
    }
    uint8_t *payload = (uint8_t *)&cmd[1];
    cmd->s = s;
    cmd->slot = slot;
    if (data_length == 0) {
        cmd->data = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, data, data_length);
        cmd->data = (const void *)(payload - ((uint8_t *)&cmd[1]));
        payload += data_length;
    } else {
        cmd->data = data;
    }
    cmd->data_length = data_length;
    cmd->e = e;
    if (dims_length == 0) {
        cmd->dims = NULL;
    } else if (dataSize < io->getMaxInlineSize()) {
        memcpy(payload, dims, dims_length);
        cmd->dims = (const uint32_t *)(payload - ((uint8_t *)&cmd[1]));
        payload += dims_length;
    } else {
        cmd->dims = dims;
    }
    cmd->dims_length = dims_length;
    io->coreCommit();
    if (dataSize >= io->getMaxInlineSize()) {
        io->coreGetReturn(NULL, 0);
    }
};

static RsScript LF_ScriptCCreate (RsContext rsc, const char * resName, size_t resName_length, const char * cacheDir, size_t cacheDir_length, const char * text, size_t text_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_ScriptCCreate((Context *)rsc, resName, resName_length, cacheDir, cacheDir_length, text, text_length);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptCCreate);
    RS_CMD_ScriptCCreate *cmd = static_cast<RS_CMD_ScriptCCreate *>(io->coreHeader(RS_CMD_ID_ScriptCCreate, size));
    cmd->resName = resName;
    cmd->resName_length = resName_length;
    cmd->cacheDir = cacheDir;
    cmd->cacheDir_length = cacheDir_length;
    cmd->text = text;
    cmd->text_length = text_length;
    io->coreCommit();

    RsScript ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static RsScript LF_ScriptIntrinsicCreate (RsContext rsc, uint32_t id, RsElement eid)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_ScriptIntrinsicCreate((Context *)rsc, id, eid);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptIntrinsicCreate);
    RS_CMD_ScriptIntrinsicCreate *cmd = static_cast<RS_CMD_ScriptIntrinsicCreate *>(io->coreHeader(RS_CMD_ID_ScriptIntrinsicCreate, size));
    cmd->id = id;
    cmd->eid = eid;
    io->coreCommit();

    RsScript ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static RsScriptKernelID LF_ScriptKernelIDCreate (RsContext rsc, RsScript sid, int slot, int sig)
{
    return rsi_ScriptKernelIDCreate((Context *)rsc, sid, slot, sig);
};

static RsScriptFieldID LF_ScriptFieldIDCreate (RsContext rsc, RsScript sid, int slot)
{
    return rsi_ScriptFieldIDCreate((Context *)rsc, sid, slot);
};

static RsScriptGroup LF_ScriptGroupCreate (RsContext rsc, RsScriptKernelID * kernels, size_t kernels_length, RsScriptKernelID * src, size_t src_length, RsScriptKernelID * dstK, size_t dstK_length, RsScriptFieldID * dstF, size_t dstF_length, const RsType * type, size_t type_length)
{
    return rsi_ScriptGroupCreate((Context *)rsc, kernels, kernels_length, src, src_length, dstK, dstK_length, dstF, dstF_length, type, type_length);
};

static void LF_ScriptGroupSetOutput (RsContext rsc, RsScriptGroup group, RsScriptKernelID kernel, RsAllocation alloc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptGroupSetOutput((Context *)rsc, group, kernel, alloc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptGroupSetOutput);
    RS_CMD_ScriptGroupSetOutput *cmd = static_cast<RS_CMD_ScriptGroupSetOutput *>(io->coreHeader(RS_CMD_ID_ScriptGroupSetOutput, size));
    cmd->group = group;
    cmd->kernel = kernel;
    cmd->alloc = alloc;
    io->coreCommit();
};

static void LF_ScriptGroupSetInput (RsContext rsc, RsScriptGroup group, RsScriptKernelID kernel, RsAllocation alloc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptGroupSetInput((Context *)rsc, group, kernel, alloc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptGroupSetInput);
    RS_CMD_ScriptGroupSetInput *cmd = static_cast<RS_CMD_ScriptGroupSetInput *>(io->coreHeader(RS_CMD_ID_ScriptGroupSetInput, size));
    cmd->group = group;
    cmd->kernel = kernel;
    cmd->alloc = alloc;
    io->coreCommit();
};

static void LF_ScriptGroupExecute (RsContext rsc, RsScriptGroup group)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ScriptGroupExecute((Context *)rsc, group);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ScriptGroupExecute);
    RS_CMD_ScriptGroupExecute *cmd = static_cast<RS_CMD_ScriptGroupExecute *>(io->coreHeader(RS_CMD_ID_ScriptGroupExecute, size));
    cmd->group = group;
    io->coreCommit();
};

static RsScriptGroup2 LF_ScriptGroup2Create (RsContext rsc, const char * name, size_t name_length, const char * cacheDir, size_t cacheDir_length, RsClosure * closures, size_t closures_length)
{
    return rsi_ScriptGroup2Create((Context *)rsc, name, name_length, cacheDir, cacheDir_length, closures, closures_length);
};

static void LF_AllocationIoSend (RsContext rsc, RsAllocation alloc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_AllocationIoSend((Context *)rsc, alloc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationIoSend);
    RS_CMD_AllocationIoSend *cmd = static_cast<RS_CMD_AllocationIoSend *>(io->coreHeader(RS_CMD_ID_AllocationIoSend, size));
    cmd->alloc = alloc;
    io->coreCommit();
};

static int64_t LF_AllocationIoReceive (RsContext rsc, RsAllocation alloc)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_AllocationIoReceive((Context *)rsc, alloc);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_AllocationIoReceive);
    RS_CMD_AllocationIoReceive *cmd = static_cast<RS_CMD_AllocationIoReceive *>(io->coreHeader(RS_CMD_ID_AllocationIoReceive, size));
    cmd->alloc = alloc;
    io->coreCommit();

    int64_t ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static RsProgramStore LF_ProgramStoreCreate (RsContext rsc, bool colorMaskR, bool colorMaskG, bool colorMaskB, bool colorMaskA, bool depthMask, bool ditherEnable, RsBlendSrcFunc srcFunc, RsBlendDstFunc destFunc, RsDepthFunc depthFunc)
{
    return rsi_ProgramStoreCreate((Context *)rsc, colorMaskR, colorMaskG, colorMaskB, colorMaskA, depthMask, ditherEnable, srcFunc, destFunc, depthFunc);
};

static RsProgramRaster LF_ProgramRasterCreate (RsContext rsc, bool pointSprite, RsCullMode cull)
{
    return rsi_ProgramRasterCreate((Context *)rsc, pointSprite, cull);
};

static void LF_ProgramBindConstants (RsContext rsc, RsProgram vp, uint32_t slot, RsAllocation constants)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ProgramBindConstants((Context *)rsc, vp, slot, constants);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ProgramBindConstants);
    RS_CMD_ProgramBindConstants *cmd = static_cast<RS_CMD_ProgramBindConstants *>(io->coreHeader(RS_CMD_ID_ProgramBindConstants, size));
    cmd->vp = vp;
    cmd->slot = slot;
    cmd->constants = constants;
    io->coreCommit();
};

static void LF_ProgramBindTexture (RsContext rsc, RsProgramFragment pf, uint32_t slot, RsAllocation a)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ProgramBindTexture((Context *)rsc, pf, slot, a);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ProgramBindTexture);
    RS_CMD_ProgramBindTexture *cmd = static_cast<RS_CMD_ProgramBindTexture *>(io->coreHeader(RS_CMD_ID_ProgramBindTexture, size));
    cmd->pf = pf;
    cmd->slot = slot;
    cmd->a = a;
    io->coreCommit();
};

static void LF_ProgramBindSampler (RsContext rsc, RsProgramFragment pf, uint32_t slot, RsSampler s)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ProgramBindSampler((Context *)rsc, pf, slot, s);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ProgramBindSampler);
    RS_CMD_ProgramBindSampler *cmd = static_cast<RS_CMD_ProgramBindSampler *>(io->coreHeader(RS_CMD_ID_ProgramBindSampler, size));
    cmd->pf = pf;
    cmd->slot = slot;
    cmd->s = s;
    io->coreCommit();
};

static RsProgramFragment LF_ProgramFragmentCreate (RsContext rsc, const char * shaderText, size_t shaderText_length, const char ** textureNames, size_t textureNames_length_length, const size_t * textureNames_length, const uintptr_t * params, size_t params_length)
{
    return rsi_ProgramFragmentCreate((Context *)rsc, shaderText, shaderText_length, textureNames, textureNames_length_length, textureNames_length, params, params_length);
};

static RsProgramVertex LF_ProgramVertexCreate (RsContext rsc, const char * shaderText, size_t shaderText_length, const char ** textureNames, size_t textureNames_length_length, const size_t * textureNames_length, const uintptr_t * params, size_t params_length)
{
    return rsi_ProgramVertexCreate((Context *)rsc, shaderText, shaderText_length, textureNames, textureNames_length_length, textureNames_length, params, params_length);
};

static RsFont LF_FontCreateFromFile (RsContext rsc, const char * name, size_t name_length, float fontSize, uint32_t dpi)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_FontCreateFromFile((Context *)rsc, name, name_length, fontSize, dpi);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_FontCreateFromFile);
    RS_CMD_FontCreateFromFile *cmd = static_cast<RS_CMD_FontCreateFromFile *>(io->coreHeader(RS_CMD_ID_FontCreateFromFile, size));
    cmd->name = name;
    cmd->name_length = name_length;
    cmd->fontSize = fontSize;
    cmd->dpi = dpi;
    io->coreCommit();

    RsFont ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static RsFont LF_FontCreateFromMemory (RsContext rsc, const char * name, size_t name_length, float fontSize, uint32_t dpi, const void * data, size_t data_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_FontCreateFromMemory((Context *)rsc, name, name_length, fontSize, dpi, data, data_length);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_FontCreateFromMemory);
    RS_CMD_FontCreateFromMemory *cmd = static_cast<RS_CMD_FontCreateFromMemory *>(io->coreHeader(RS_CMD_ID_FontCreateFromMemory, size));
    cmd->name = name;
    cmd->name_length = name_length;
    cmd->fontSize = fontSize;
    cmd->dpi = dpi;
    cmd->data = data;
    cmd->data_length = data_length;
    io->coreCommit();

    RsFont ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static RsMesh LF_MeshCreate (RsContext rsc, RsAllocation * vtx, size_t vtx_length, RsAllocation * idx, size_t idx_length, uint32_t * primType, size_t primType_length)
{
    if (((Context *)rsc)->isSynchronous()) {
        return rsi_MeshCreate((Context *)rsc, vtx, vtx_length, idx, idx_length, primType, primType_length);
    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_MeshCreate);
    RS_CMD_MeshCreate *cmd = static_cast<RS_CMD_MeshCreate *>(io->coreHeader(RS_CMD_ID_MeshCreate, size));
    cmd->vtx = vtx;
    cmd->vtx_length = vtx_length;
    cmd->idx = idx;
    cmd->idx_length = idx_length;
    cmd->primType = primType;
    cmd->primType_length = primType_length;
    io->coreCommit();

    RsMesh ret;
    io->coreGetReturn(&ret, sizeof(ret));
    return ret;
};

static void LF_ContextBindProgramStore (RsContext rsc, RsProgramStore pgm)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextBindProgramStore((Context *)rsc, pgm);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextBindProgramStore);
    RS_CMD_ContextBindProgramStore *cmd = static_cast<RS_CMD_ContextBindProgramStore *>(io->coreHeader(RS_CMD_ID_ContextBindProgramStore, size));
    cmd->pgm = pgm;
    io->coreCommit();
};

static void LF_ContextBindProgramFragment (RsContext rsc, RsProgramFragment pgm)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextBindProgramFragment((Context *)rsc, pgm);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextBindProgramFragment);
    RS_CMD_ContextBindProgramFragment *cmd = static_cast<RS_CMD_ContextBindProgramFragment *>(io->coreHeader(RS_CMD_ID_ContextBindProgramFragment, size));
    cmd->pgm = pgm;
    io->coreCommit();
};

static void LF_ContextBindProgramVertex (RsContext rsc, RsProgramVertex pgm)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextBindProgramVertex((Context *)rsc, pgm);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextBindProgramVertex);
    RS_CMD_ContextBindProgramVertex *cmd = static_cast<RS_CMD_ContextBindProgramVertex *>(io->coreHeader(RS_CMD_ID_ContextBindProgramVertex, size));
    cmd->pgm = pgm;
    io->coreCommit();
};

static void LF_ContextBindProgramRaster (RsContext rsc, RsProgramRaster pgm)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextBindProgramRaster((Context *)rsc, pgm);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextBindProgramRaster);
    RS_CMD_ContextBindProgramRaster *cmd = static_cast<RS_CMD_ContextBindProgramRaster *>(io->coreHeader(RS_CMD_ID_ContextBindProgramRaster, size));
    cmd->pgm = pgm;
    io->coreCommit();
};

static void LF_ContextBindFont (RsContext rsc, RsFont pgm)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextBindFont((Context *)rsc, pgm);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextBindFont);
    RS_CMD_ContextBindFont *cmd = static_cast<RS_CMD_ContextBindFont *>(io->coreHeader(RS_CMD_ID_ContextBindFont, size));
    cmd->pgm = pgm;
    io->coreCommit();
};

static void LF_ContextSetSurface (RsContext rsc, uint32_t width, uint32_t height, RsNativeWindow sur)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextSetSurface((Context *)rsc, width, height, sur);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextSetSurface);
    RS_CMD_ContextSetSurface *cmd = static_cast<RS_CMD_ContextSetSurface *>(io->coreHeader(RS_CMD_ID_ContextSetSurface, size));
    cmd->width = width;
    cmd->height = height;
    cmd->sur = sur;
    io->coreCommit();
    io->coreGetReturn(NULL, 0);
};

static void LF_ContextBindRootScript (RsContext rsc, RsScript sampler)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextBindRootScript((Context *)rsc, sampler);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextBindRootScript);
    RS_CMD_ContextBindRootScript *cmd = static_cast<RS_CMD_ContextBindRootScript *>(io->coreHeader(RS_CMD_ID_ContextBindRootScript, size));
    cmd->sampler = sampler;
    io->coreCommit();
};

static void LF_ContextPause (RsContext rsc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextPause((Context *)rsc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextPause);
    RS_CMD_ContextPause *cmd = static_cast<RS_CMD_ContextPause *>(io->coreHeader(RS_CMD_ID_ContextPause, size));
    io->coreCommit();
};

static void LF_ContextResume (RsContext rsc)
{
    if (((Context *)rsc)->isSynchronous()) {
        rsi_ContextResume((Context *)rsc);
    return;    }

    ThreadIO *io = &((Context *)rsc)->mIO;
    const size_t size = sizeof(RS_CMD_ContextResume);
    RS_CMD_ContextResume *cmd = static_cast<RS_CMD_ContextResume *>(io->coreHeader(RS_CMD_ID_ContextResume, size));
    io->coreCommit();
};


extern "C" void rsContextDestroy (RsContext rsc)
{
    LF_ContextDestroy((Context *)rsc);
}

extern "C" RsMessageToClientType rsContextGetMessage (RsContext rsc, void * data, size_t data_length, size_t * receiveLen, size_t receiveLen_length, uint32_t * usrID, size_t usrID_length)
{
    return LF_ContextGetMessage((Context *)rsc, data, data_length, receiveLen, receiveLen_length, usrID, usrID_length);
}

extern "C" RsMessageToClientType rsContextPeekMessage (RsContext rsc, size_t * receiveLen, size_t receiveLen_length, uint32_t * usrID, size_t usrID_length)
{
    return LF_ContextPeekMessage((Context *)rsc, receiveLen, receiveLen_length, usrID, usrID_length);
}

extern "C" void rsContextSendMessage (RsContext rsc, uint32_t id, const uint8_t * data, size_t data_length)
{
    LF_ContextSendMessage((Context *)rsc, id, data, data_length);
}

extern "C" void rsContextInitToClient (RsContext rsc)
{
    LF_ContextInitToClient((Context *)rsc);
}

extern "C" void rsContextDeinitToClient (RsContext rsc)
{
    LF_ContextDeinitToClient((Context *)rsc);
}

extern "C" void rsContextSetCacheDir (RsContext rsc, const char * cacheDir, size_t cacheDir_length)
{
    LF_ContextSetCacheDir((Context *)rsc, cacheDir, cacheDir_length);
}

extern "C" RsType rsTypeCreate (RsContext rsc, RsElement e, uint32_t dimX, uint32_t dimY, uint32_t dimZ, bool mipmaps, bool faces, uint32_t yuv)
{
    return LF_TypeCreate((Context *)rsc, e, dimX, dimY, dimZ, mipmaps, faces, yuv);
}

extern "C" RsType rsTypeCreate2 (RsContext rsc, const RsTypeCreateParams * dat, size_t dat_length)
{
    return LF_TypeCreate2((Context *)rsc, dat, dat_length);
}

extern "C" RsAllocation rsAllocationCreateTyped (RsContext rsc, RsType vtype, RsAllocationMipmapControl mipmaps, uint32_t usages, uintptr_t ptr)
{
    return LF_AllocationCreateTyped((Context *)rsc, vtype, mipmaps, usages, ptr);
}

extern "C" RsAllocation rsAllocationCreateFromBitmap (RsContext rsc, RsType vtype, RsAllocationMipmapControl mipmaps, const void * data, size_t data_length, uint32_t usages)
{
    return LF_AllocationCreateFromBitmap((Context *)rsc, vtype, mipmaps, data, data_length, usages);
}

extern "C" RsAllocation rsAllocationCubeCreateFromBitmap (RsContext rsc, RsType vtype, RsAllocationMipmapControl mipmaps, const void * data, size_t data_length, uint32_t usages)
{
    return LF_AllocationCubeCreateFromBitmap((Context *)rsc, vtype, mipmaps, data, data_length, usages);
}

extern "C" void rsAllocationSetupBufferQueue (RsContext rsc, RsAllocation alloc, uint32_t numAlloc)
{
    LF_AllocationSetupBufferQueue((Context *)rsc, alloc, numAlloc);
}

extern "C" void rsAllocationShareBufferQueue (RsContext rsc, RsAllocation alloc1, RsAllocation alloc2)
{
    LF_AllocationShareBufferQueue((Context *)rsc, alloc1, alloc2);
}

extern "C" RsNativeWindow rsAllocationGetSurface (RsContext rsc, RsAllocation alloc)
{
    return LF_AllocationGetSurface((Context *)rsc, alloc);
}

extern "C" void rsAllocationSetSurface (RsContext rsc, RsAllocation alloc, RsNativeWindow sur)
{
    LF_AllocationSetSurface((Context *)rsc, alloc, sur);
}

extern "C" RsAllocation rsAllocationAdapterCreate (RsContext rsc, RsType vtype, RsAllocation baseAlloc)
{
    return LF_AllocationAdapterCreate((Context *)rsc, vtype, baseAlloc);
}

extern "C" void rsAllocationAdapterOffset (RsContext rsc, RsAllocation alloc, const uint32_t * offsets, size_t offsets_length)
{
    LF_AllocationAdapterOffset((Context *)rsc, alloc, offsets, offsets_length);
}

extern "C" void rsContextFinish (RsContext rsc)
{
    LF_ContextFinish((Context *)rsc);
}

extern "C" void rsContextDump (RsContext rsc, int32_t bits)
{
    LF_ContextDump((Context *)rsc, bits);
}

extern "C" void rsContextSetPriority (RsContext rsc, int32_t priority)
{
    LF_ContextSetPriority((Context *)rsc, priority);
}

extern "C" void rsContextDestroyWorker (RsContext rsc)
{
    LF_ContextDestroyWorker((Context *)rsc);
}

extern "C" void rsAssignName (RsContext rsc, RsObjectBase obj, const char * name, size_t name_length)
{
    LF_AssignName((Context *)rsc, obj, name, name_length);
}

extern "C" void rsObjDestroy (RsContext rsc, RsAsyncVoidPtr objPtr)
{
    LF_ObjDestroy((Context *)rsc, objPtr);
}

extern "C" RsElement rsElementCreate (RsContext rsc, RsDataType mType, RsDataKind mKind, bool mNormalized, uint32_t mVectorSize)
{
    return LF_ElementCreate((Context *)rsc, mType, mKind, mNormalized, mVectorSize);
}

extern "C" RsElement rsElementCreate2 (RsContext rsc, const RsElement * elements, size_t elements_length, const char ** names, size_t names_length_length, const size_t * names_length, const uint32_t * arraySize, size_t arraySize_length)
{
    return LF_ElementCreate2((Context *)rsc, elements, elements_length, names, names_length_length, names_length, arraySize, arraySize_length);
}

extern "C" void rsAllocationCopyToBitmap (RsContext rsc, RsAllocation alloc, void * data, size_t data_length)
{
    LF_AllocationCopyToBitmap((Context *)rsc, alloc, data, data_length);
}

extern "C" void * rsAllocationGetPointer (RsContext rsc, RsAllocation va, uint32_t lod, RsAllocationCubemapFace face, uint32_t z, uint32_t array, size_t * stride, size_t stride_length)
{
    return LF_AllocationGetPointer((Context *)rsc, va, lod, face, z, array, stride, stride_length);
}

extern "C" void rsAllocation1DData (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t lod, uint32_t count, const void * data, size_t data_length)
{
    LF_Allocation1DData((Context *)rsc, va, xoff, lod, count, data, data_length);
}

extern "C" void rsAllocation1DElementData (RsContext rsc, RsAllocation va, uint32_t x, uint32_t lod, const void * data, size_t data_length, size_t comp_offset)
{
    LF_Allocation1DElementData((Context *)rsc, va, x, lod, data, data_length, comp_offset);
}

extern "C" void rsAllocationElementData (RsContext rsc, RsAllocation va, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, const void * data, size_t data_length, size_t comp_offset)
{
    LF_AllocationElementData((Context *)rsc, va, x, y, z, lod, data, data_length, comp_offset);
}

extern "C" void rsAllocation2DData (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t lod, RsAllocationCubemapFace face, uint32_t w, uint32_t h, const void * data, size_t data_length, size_t stride)
{
    LF_Allocation2DData((Context *)rsc, va, xoff, yoff, lod, face, w, h, data, data_length, stride);
}

extern "C" void rsAllocation3DData (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, const void * data, size_t data_length, size_t stride)
{
    LF_Allocation3DData((Context *)rsc, va, xoff, yoff, zoff, lod, w, h, d, data, data_length, stride);
}

extern "C" void rsAllocationGenerateMipmaps (RsContext rsc, RsAllocation va)
{
    LF_AllocationGenerateMipmaps((Context *)rsc, va);
}

extern "C" void rsAllocationRead (RsContext rsc, RsAllocation va, void * data, size_t data_length)
{
    LF_AllocationRead((Context *)rsc, va, data, data_length);
}

extern "C" void rsAllocation1DRead (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t lod, uint32_t count, void * data, size_t data_length)
{
    LF_Allocation1DRead((Context *)rsc, va, xoff, lod, count, data, data_length);
}

extern "C" void rsAllocationElementRead (RsContext rsc, RsAllocation va, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, void * data, size_t data_length, size_t comp_offset)
{
    LF_AllocationElementRead((Context *)rsc, va, x, y, z, lod, data, data_length, comp_offset);
}

extern "C" void rsAllocation2DRead (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t lod, RsAllocationCubemapFace face, uint32_t w, uint32_t h, void * data, size_t data_length, size_t stride)
{
    LF_Allocation2DRead((Context *)rsc, va, xoff, yoff, lod, face, w, h, data, data_length, stride);
}

extern "C" void rsAllocation3DRead (RsContext rsc, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, void * data, size_t data_length, size_t stride)
{
    LF_Allocation3DRead((Context *)rsc, va, xoff, yoff, zoff, lod, w, h, d, data, data_length, stride);
}

extern "C" void rsAllocationSyncAll (RsContext rsc, RsAllocation va, RsAllocationUsageType src)
{
    LF_AllocationSyncAll((Context *)rsc, va, src);
}

extern "C" void rsAllocationResize1D (RsContext rsc, RsAllocation va, uint32_t dimX)
{
    LF_AllocationResize1D((Context *)rsc, va, dimX);
}

extern "C" void rsAllocationCopy2DRange (RsContext rsc, RsAllocation dest, uint32_t destXoff, uint32_t destYoff, uint32_t destMip, uint32_t destFace, uint32_t width, uint32_t height, RsAllocation src, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcMip, uint32_t srcFace)
{
    LF_AllocationCopy2DRange((Context *)rsc, dest, destXoff, destYoff, destMip, destFace, width, height, src, srcXoff, srcYoff, srcMip, srcFace);
}

extern "C" void rsAllocationCopy3DRange (RsContext rsc, RsAllocation dest, uint32_t destXoff, uint32_t destYoff, uint32_t destZoff, uint32_t destMip, uint32_t width, uint32_t height, uint32_t depth, RsAllocation src, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcZoff, uint32_t srcMip)
{
    LF_AllocationCopy3DRange((Context *)rsc, dest, destXoff, destYoff, destZoff, destMip, width, height, depth, src, srcXoff, srcYoff, srcZoff, srcMip);
}

extern "C" RsClosure rsClosureCreate (RsContext rsc, RsScriptKernelID kernelID, RsAllocation returnValue, RsScriptFieldID * fieldIDs, size_t fieldIDs_length, const int64_t * values, size_t values_length, const int * sizes, size_t sizes_length, RsClosure * depClosures, size_t depClosures_length, RsScriptFieldID * depFieldIDs, size_t depFieldIDs_length)
{
    return LF_ClosureCreate((Context *)rsc, kernelID, returnValue, fieldIDs, fieldIDs_length, values, values_length, sizes, sizes_length, depClosures, depClosures_length, depFieldIDs, depFieldIDs_length);
}

extern "C" RsClosure rsInvokeClosureCreate (RsContext rsc, RsScriptInvokeID invokeID, const void * params, size_t params_length, const RsScriptFieldID * fieldIDs, size_t fieldIDs_length, const int64_t * values, size_t values_length, const int * sizes, size_t sizes_length)
{
    return LF_InvokeClosureCreate((Context *)rsc, invokeID, params, params_length, fieldIDs, fieldIDs_length, values, values_length, sizes, sizes_length);
}

extern "C" void rsClosureSetArg (RsContext rsc, RsClosure closureID, uint32_t index, uintptr_t value, int valueSize)
{
    LF_ClosureSetArg((Context *)rsc, closureID, index, value, valueSize);
}

extern "C" void rsClosureSetGlobal (RsContext rsc, RsClosure closureID, RsScriptFieldID fieldID, int64_t value, int valueSize)
{
    LF_ClosureSetGlobal((Context *)rsc, closureID, fieldID, value, valueSize);
}

extern "C" RsSampler rsSamplerCreate (RsContext rsc, RsSamplerValue magFilter, RsSamplerValue minFilter, RsSamplerValue wrapS, RsSamplerValue wrapT, RsSamplerValue wrapR, float mAniso)
{
    return LF_SamplerCreate((Context *)rsc, magFilter, minFilter, wrapS, wrapT, wrapR, mAniso);
}

extern "C" void rsScriptBindAllocation (RsContext rsc, RsScript vtm, RsAllocation va, uint32_t slot)
{
    LF_ScriptBindAllocation((Context *)rsc, vtm, va, slot);
}

extern "C" void rsScriptSetTimeZone (RsContext rsc, RsScript s, const char * timeZone, size_t timeZone_length)
{
    LF_ScriptSetTimeZone((Context *)rsc, s, timeZone, timeZone_length);
}

extern "C" RsScriptInvokeID rsScriptInvokeIDCreate (RsContext rsc, RsScript s, uint32_t slot)
{
    return LF_ScriptInvokeIDCreate((Context *)rsc, s, slot);
}

extern "C" void rsScriptInvoke (RsContext rsc, RsScript s, uint32_t slot)
{
    LF_ScriptInvoke((Context *)rsc, s, slot);
}

extern "C" void rsScriptInvokeV (RsContext rsc, RsScript s, uint32_t slot, const void * data, size_t data_length)
{
    LF_ScriptInvokeV((Context *)rsc, s, slot, data, data_length);
}

extern "C" void rsScriptForEach (RsContext rsc, RsScript s, uint32_t slot, RsAllocation ain, RsAllocation aout, const void * usr, size_t usr_length, const RsScriptCall * sc, size_t sc_length)
{
    LF_ScriptForEach((Context *)rsc, s, slot, ain, aout, usr, usr_length, sc, sc_length);
}

extern "C" void rsScriptForEachMulti (RsContext rsc, RsScript s, uint32_t slot, RsAllocation * ains, size_t ains_length, RsAllocation aout, const void * usr, size_t usr_length, const RsScriptCall * sc, size_t sc_length)
{
    LF_ScriptForEachMulti((Context *)rsc, s, slot, ains, ains_length, aout, usr, usr_length, sc, sc_length);
}

extern "C" void rsScriptReduce (RsContext rsc, RsScript s, uint32_t slot, RsAllocation * ains, size_t ains_length, RsAllocation aout, const RsScriptCall * sc, size_t sc_length)
{
    LF_ScriptReduce((Context *)rsc, s, slot, ains, ains_length, aout, sc, sc_length);
}

extern "C" void rsScriptSetVarI (RsContext rsc, RsScript s, uint32_t slot, int value)
{
    LF_ScriptSetVarI((Context *)rsc, s, slot, value);
}

extern "C" void rsScriptSetVarObj (RsContext rsc, RsScript s, uint32_t slot, RsObjectBase value)
{
    LF_ScriptSetVarObj((Context *)rsc, s, slot, value);
}

extern "C" void rsScriptSetVarJ (RsContext rsc, RsScript s, uint32_t slot, int64_t value)
{
    LF_ScriptSetVarJ((Context *)rsc, s, slot, value);
}

extern "C" void rsScriptSetVarF (RsContext rsc, RsScript s, uint32_t slot, float value)
{
    LF_ScriptSetVarF((Context *)rsc, s, slot, value);
}

extern "C" void rsScriptSetVarD (RsContext rsc, RsScript s, uint32_t slot, double value)
{
    LF_ScriptSetVarD((Context *)rsc, s, slot, value);
}

extern "C" void rsScriptSetVarV (RsContext rsc, RsScript s, uint32_t slot, const void * data, size_t data_length)
{
    LF_ScriptSetVarV((Context *)rsc, s, slot, data, data_length);
}

extern "C" void rsScriptGetVarV (RsContext rsc, RsScript s, uint32_t slot, void * data, size_t data_length)
{
    LF_ScriptGetVarV((Context *)rsc, s, slot, data, data_length);
}

extern "C" void rsScriptSetVarVE (RsContext rsc, RsScript s, uint32_t slot, const void * data, size_t data_length, RsElement e, const uint32_t * dims, size_t dims_length)
{
    LF_ScriptSetVarVE((Context *)rsc, s, slot, data, data_length, e, dims, dims_length);
}

extern "C" RsScript rsScriptCCreate (RsContext rsc, const char * resName, size_t resName_length, const char * cacheDir, size_t cacheDir_length, const char * text, size_t text_length)
{
    return LF_ScriptCCreate((Context *)rsc, resName, resName_length, cacheDir, cacheDir_length, text, text_length);
}

extern "C" RsScript rsScriptIntrinsicCreate (RsContext rsc, uint32_t id, RsElement eid)
{
    return LF_ScriptIntrinsicCreate((Context *)rsc, id, eid);
}

extern "C" RsScriptKernelID rsScriptKernelIDCreate (RsContext rsc, RsScript sid, int slot, int sig)
{
    return LF_ScriptKernelIDCreate((Context *)rsc, sid, slot, sig);
}

extern "C" RsScriptFieldID rsScriptFieldIDCreate (RsContext rsc, RsScript sid, int slot)
{
    return LF_ScriptFieldIDCreate((Context *)rsc, sid, slot);
}

extern "C" RsScriptGroup rsScriptGroupCreate (RsContext rsc, RsScriptKernelID * kernels, size_t kernels_length, RsScriptKernelID * src, size_t src_length, RsScriptKernelID * dstK, size_t dstK_length, RsScriptFieldID * dstF, size_t dstF_length, const RsType * type, size_t type_length)
{
    return LF_ScriptGroupCreate((Context *)rsc, kernels, kernels_length, src, src_length, dstK, dstK_length, dstF, dstF_length, type, type_length);
}

extern "C" void rsScriptGroupSetOutput (RsContext rsc, RsScriptGroup group, RsScriptKernelID kernel, RsAllocation alloc)
{
    LF_ScriptGroupSetOutput((Context *)rsc, group, kernel, alloc);
}

extern "C" void rsScriptGroupSetInput (RsContext rsc, RsScriptGroup group, RsScriptKernelID kernel, RsAllocation alloc)
{
    LF_ScriptGroupSetInput((Context *)rsc, group, kernel, alloc);
}

extern "C" void rsScriptGroupExecute (RsContext rsc, RsScriptGroup group)
{
    LF_ScriptGroupExecute((Context *)rsc, group);
}

extern "C" RsScriptGroup2 rsScriptGroup2Create (RsContext rsc, const char * name, size_t name_length, const char * cacheDir, size_t cacheDir_length, RsClosure * closures, size_t closures_length)
{
    return LF_ScriptGroup2Create((Context *)rsc, name, name_length, cacheDir, cacheDir_length, closures, closures_length);
}

extern "C" void rsAllocationIoSend (RsContext rsc, RsAllocation alloc)
{
    LF_AllocationIoSend((Context *)rsc, alloc);
}

extern "C" int64_t rsAllocationIoReceive (RsContext rsc, RsAllocation alloc)
{
    return LF_AllocationIoReceive((Context *)rsc, alloc);
}

extern "C" RsProgramStore rsProgramStoreCreate (RsContext rsc, bool colorMaskR, bool colorMaskG, bool colorMaskB, bool colorMaskA, bool depthMask, bool ditherEnable, RsBlendSrcFunc srcFunc, RsBlendDstFunc destFunc, RsDepthFunc depthFunc)
{
    return LF_ProgramStoreCreate((Context *)rsc, colorMaskR, colorMaskG, colorMaskB, colorMaskA, depthMask, ditherEnable, srcFunc, destFunc, depthFunc);
}

extern "C" RsProgramRaster rsProgramRasterCreate (RsContext rsc, bool pointSprite, RsCullMode cull)
{
    return LF_ProgramRasterCreate((Context *)rsc, pointSprite, cull);
}

extern "C" void rsProgramBindConstants (RsContext rsc, RsProgram vp, uint32_t slot, RsAllocation constants)
{
    LF_ProgramBindConstants((Context *)rsc, vp, slot, constants);
}

extern "C" void rsProgramBindTexture (RsContext rsc, RsProgramFragment pf, uint32_t slot, RsAllocation a)
{
    LF_ProgramBindTexture((Context *)rsc, pf, slot, a);
}

extern "C" void rsProgramBindSampler (RsContext rsc, RsProgramFragment pf, uint32_t slot, RsSampler s)
{
    LF_ProgramBindSampler((Context *)rsc, pf, slot, s);
}

extern "C" RsProgramFragment rsProgramFragmentCreate (RsContext rsc, const char * shaderText, size_t shaderText_length, const char ** textureNames, size_t textureNames_length_length, const size_t * textureNames_length, const uintptr_t * params, size_t params_length)
{
    return LF_ProgramFragmentCreate((Context *)rsc, shaderText, shaderText_length, textureNames, textureNames_length_length, textureNames_length, params, params_length);
}

extern "C" RsProgramVertex rsProgramVertexCreate (RsContext rsc, const char * shaderText, size_t shaderText_length, const char ** textureNames, size_t textureNames_length_length, const size_t * textureNames_length, const uintptr_t * params, size_t params_length)
{
    return LF_ProgramVertexCreate((Context *)rsc, shaderText, shaderText_length, textureNames, textureNames_length_length, textureNames_length, params, params_length);
}

extern "C" RsFont rsFontCreateFromFile (RsContext rsc, const char * name, size_t name_length, float fontSize, uint32_t dpi)
{
    return LF_FontCreateFromFile((Context *)rsc, name, name_length, fontSize, dpi);
}

extern "C" RsFont rsFontCreateFromMemory (RsContext rsc, const char * name, size_t name_length, float fontSize, uint32_t dpi, const void * data, size_t data_length)
{
    return LF_FontCreateFromMemory((Context *)rsc, name, name_length, fontSize, dpi, data, data_length);
}

extern "C" RsMesh rsMeshCreate (RsContext rsc, RsAllocation * vtx, size_t vtx_length, RsAllocation * idx, size_t idx_length, uint32_t * primType, size_t primType_length)
{
    return LF_MeshCreate((Context *)rsc, vtx, vtx_length, idx, idx_length, primType, primType_length);
}

extern "C" void rsContextBindProgramStore (RsContext rsc, RsProgramStore pgm)
{
    LF_ContextBindProgramStore((Context *)rsc, pgm);
}

extern "C" void rsContextBindProgramFragment (RsContext rsc, RsProgramFragment pgm)
{
    LF_ContextBindProgramFragment((Context *)rsc, pgm);
}

extern "C" void rsContextBindProgramVertex (RsContext rsc, RsProgramVertex pgm)
{
    LF_ContextBindProgramVertex((Context *)rsc, pgm);
}

extern "C" void rsContextBindProgramRaster (RsContext rsc, RsProgramRaster pgm)
{
    LF_ContextBindProgramRaster((Context *)rsc, pgm);
}

extern "C" void rsContextBindFont (RsContext rsc, RsFont pgm)
{
    LF_ContextBindFont((Context *)rsc, pgm);
}

extern "C" void rsContextSetSurface (RsContext rsc, uint32_t width, uint32_t height, RsNativeWindow sur)
{
    LF_ContextSetSurface((Context *)rsc, width, height, sur);
}

extern "C" void rsContextBindRootScript (RsContext rsc, RsScript sampler)
{
    LF_ContextBindRootScript((Context *)rsc, sampler);
}

extern "C" void rsContextPause (RsContext rsc)
{
    LF_ContextPause((Context *)rsc);
}

extern "C" void rsContextResume (RsContext rsc)
{
    LF_ContextResume((Context *)rsc);
}

