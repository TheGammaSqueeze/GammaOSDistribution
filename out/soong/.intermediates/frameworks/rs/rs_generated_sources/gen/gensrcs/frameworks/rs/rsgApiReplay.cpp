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
 * rsgApiReplay.cpp
 * This file implements the functions responsible for reading messages
 * sent to the RS driver layer.
 */

#include "rsDevice.h"
#include "rsContext.h"
#include "rsThreadIO.h"
#include "rsgApiStructs.h"
#include "rsgApiFuncDecl.h"

namespace android {
namespace renderscript {

void rsp_ContextSendMessage(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextSendMessage *cmd = static_cast<const RS_CMD_ContextSendMessage *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_ContextSendMessage)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_ContextSendMessage(con,
           cmd->id,
           cmd->data_length == 0 ? NULL : (const uint8_t *)&baseData[(intptr_t)cmd->data],
           cmd->data_length);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_ContextSendMessage))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_AllocationSetupBufferQueue(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationSetupBufferQueue *cmd = static_cast<const RS_CMD_AllocationSetupBufferQueue *>(vp);
    rsi_AllocationSetupBufferQueue(con,
           cmd->alloc,
           cmd->numAlloc);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AllocationShareBufferQueue(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationShareBufferQueue *cmd = static_cast<const RS_CMD_AllocationShareBufferQueue *>(vp);
    rsi_AllocationShareBufferQueue(con,
           cmd->alloc1,
           cmd->alloc2);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AllocationGetSurface(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationGetSurface *cmd = static_cast<const RS_CMD_AllocationGetSurface *>(vp);
    
    RsNativeWindow ret = rsi_AllocationGetSurface(con,
           cmd->alloc);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_AllocationSetSurface(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationSetSurface *cmd = static_cast<const RS_CMD_AllocationSetSurface *>(vp);
    rsi_AllocationSetSurface(con,
           cmd->alloc,
           cmd->sur);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AllocationAdapterOffset(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationAdapterOffset *cmd = static_cast<const RS_CMD_AllocationAdapterOffset *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_AllocationAdapterOffset)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_AllocationAdapterOffset(con,
           cmd->alloc,
           cmd->offsets_length == 0 ? NULL : (const uint32_t *)&baseData[(intptr_t)cmd->offsets],
           cmd->offsets_length);
    size_t totalSize = 0;
    totalSize += cmd->offsets_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_AllocationAdapterOffset))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ContextFinish(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextFinish *cmd = static_cast<const RS_CMD_ContextFinish *>(vp);
    rsi_ContextFinish(con);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_ContextDump(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextDump *cmd = static_cast<const RS_CMD_ContextDump *>(vp);
    rsi_ContextDump(con,
           cmd->bits);
};

void rsp_ContextSetPriority(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextSetPriority *cmd = static_cast<const RS_CMD_ContextSetPriority *>(vp);
    rsi_ContextSetPriority(con,
           cmd->priority);
};

void rsp_ContextDestroyWorker(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextDestroyWorker *cmd = static_cast<const RS_CMD_ContextDestroyWorker *>(vp);
    rsi_ContextDestroyWorker(con);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AssignName(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AssignName *cmd = static_cast<const RS_CMD_AssignName *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_AssignName)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_AssignName(con,
           cmd->obj,
           cmd->name_length == 0 ? NULL : (const char *)&baseData[(intptr_t)cmd->name],
           cmd->name_length);
    size_t totalSize = 0;
    totalSize += cmd->name_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_AssignName))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ObjDestroy(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ObjDestroy *cmd = static_cast<const RS_CMD_ObjDestroy *>(vp);
    rsi_ObjDestroy(con,
           cmd->objPtr);
};

void rsp_AllocationCopyToBitmap(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationCopyToBitmap *cmd = static_cast<const RS_CMD_AllocationCopyToBitmap *>(vp);
    rsi_AllocationCopyToBitmap(con,
           cmd->alloc,
           cmd->data,
           cmd->data_length);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AllocationGetPointer(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationGetPointer *cmd = static_cast<const RS_CMD_AllocationGetPointer *>(vp);
    
    void * ret = rsi_AllocationGetPointer(con,
           cmd->va,
           cmd->lod,
           cmd->face,
           cmd->z,
           cmd->array,
           cmd->stride,
           cmd->stride_length);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_Allocation1DData(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation1DData *cmd = static_cast<const RS_CMD_Allocation1DData *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_Allocation1DData)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_Allocation1DData(con,
           cmd->va,
           cmd->xoff,
           cmd->lod,
           cmd->count,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_Allocation1DData))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_Allocation1DElementData(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation1DElementData *cmd = static_cast<const RS_CMD_Allocation1DElementData *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_Allocation1DElementData)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_Allocation1DElementData(con,
           cmd->va,
           cmd->x,
           cmd->lod,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length,
           cmd->comp_offset);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_Allocation1DElementData))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_AllocationElementData(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationElementData *cmd = static_cast<const RS_CMD_AllocationElementData *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_AllocationElementData)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_AllocationElementData(con,
           cmd->va,
           cmd->x,
           cmd->y,
           cmd->z,
           cmd->lod,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length,
           cmd->comp_offset);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_AllocationElementData))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_Allocation2DData(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation2DData *cmd = static_cast<const RS_CMD_Allocation2DData *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_Allocation2DData)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_Allocation2DData(con,
           cmd->va,
           cmd->xoff,
           cmd->yoff,
           cmd->lod,
           cmd->face,
           cmd->w,
           cmd->h,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length,
           cmd->stride);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_Allocation2DData))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_Allocation3DData(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation3DData *cmd = static_cast<const RS_CMD_Allocation3DData *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_Allocation3DData)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_Allocation3DData(con,
           cmd->va,
           cmd->xoff,
           cmd->yoff,
           cmd->zoff,
           cmd->lod,
           cmd->w,
           cmd->h,
           cmd->d,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length,
           cmd->stride);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_Allocation3DData))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_AllocationGenerateMipmaps(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationGenerateMipmaps *cmd = static_cast<const RS_CMD_AllocationGenerateMipmaps *>(vp);
    rsi_AllocationGenerateMipmaps(con,
           cmd->va);
};

void rsp_AllocationRead(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationRead *cmd = static_cast<const RS_CMD_AllocationRead *>(vp);
    rsi_AllocationRead(con,
           cmd->va,
           cmd->data,
           cmd->data_length);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_Allocation1DRead(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation1DRead *cmd = static_cast<const RS_CMD_Allocation1DRead *>(vp);
    rsi_Allocation1DRead(con,
           cmd->va,
           cmd->xoff,
           cmd->lod,
           cmd->count,
           cmd->data,
           cmd->data_length);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AllocationElementRead(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationElementRead *cmd = static_cast<const RS_CMD_AllocationElementRead *>(vp);
    rsi_AllocationElementRead(con,
           cmd->va,
           cmd->x,
           cmd->y,
           cmd->z,
           cmd->lod,
           cmd->data,
           cmd->data_length,
           cmd->comp_offset);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_Allocation2DRead(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation2DRead *cmd = static_cast<const RS_CMD_Allocation2DRead *>(vp);
    rsi_Allocation2DRead(con,
           cmd->va,
           cmd->xoff,
           cmd->yoff,
           cmd->lod,
           cmd->face,
           cmd->w,
           cmd->h,
           cmd->data,
           cmd->data_length,
           cmd->stride);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_Allocation3DRead(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_Allocation3DRead *cmd = static_cast<const RS_CMD_Allocation3DRead *>(vp);
    rsi_Allocation3DRead(con,
           cmd->va,
           cmd->xoff,
           cmd->yoff,
           cmd->zoff,
           cmd->lod,
           cmd->w,
           cmd->h,
           cmd->d,
           cmd->data,
           cmd->data_length,
           cmd->stride);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_AllocationSyncAll(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationSyncAll *cmd = static_cast<const RS_CMD_AllocationSyncAll *>(vp);
    rsi_AllocationSyncAll(con,
           cmd->va,
           cmd->src);
};

void rsp_AllocationResize1D(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationResize1D *cmd = static_cast<const RS_CMD_AllocationResize1D *>(vp);
    rsi_AllocationResize1D(con,
           cmd->va,
           cmd->dimX);
};

void rsp_AllocationCopy2DRange(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationCopy2DRange *cmd = static_cast<const RS_CMD_AllocationCopy2DRange *>(vp);
    rsi_AllocationCopy2DRange(con,
           cmd->dest,
           cmd->destXoff,
           cmd->destYoff,
           cmd->destMip,
           cmd->destFace,
           cmd->width,
           cmd->height,
           cmd->src,
           cmd->srcXoff,
           cmd->srcYoff,
           cmd->srcMip,
           cmd->srcFace);
};

void rsp_AllocationCopy3DRange(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationCopy3DRange *cmd = static_cast<const RS_CMD_AllocationCopy3DRange *>(vp);
    rsi_AllocationCopy3DRange(con,
           cmd->dest,
           cmd->destXoff,
           cmd->destYoff,
           cmd->destZoff,
           cmd->destMip,
           cmd->width,
           cmd->height,
           cmd->depth,
           cmd->src,
           cmd->srcXoff,
           cmd->srcYoff,
           cmd->srcZoff,
           cmd->srcMip);
};

void rsp_ClosureSetArg(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ClosureSetArg *cmd = static_cast<const RS_CMD_ClosureSetArg *>(vp);
    rsi_ClosureSetArg(con,
           cmd->closureID,
           cmd->index,
           cmd->value,
           cmd->valueSize);
};

void rsp_ClosureSetGlobal(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ClosureSetGlobal *cmd = static_cast<const RS_CMD_ClosureSetGlobal *>(vp);
    rsi_ClosureSetGlobal(con,
           cmd->closureID,
           cmd->fieldID,
           cmd->value,
           cmd->valueSize);
};

void rsp_ScriptBindAllocation(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptBindAllocation *cmd = static_cast<const RS_CMD_ScriptBindAllocation *>(vp);
    rsi_ScriptBindAllocation(con,
           cmd->vtm,
           cmd->va,
           cmd->slot);
};

void rsp_ScriptSetTimeZone(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetTimeZone *cmd = static_cast<const RS_CMD_ScriptSetTimeZone *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_ScriptSetTimeZone)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_ScriptSetTimeZone(con,
           cmd->s,
           cmd->timeZone_length == 0 ? NULL : (const char *)&baseData[(intptr_t)cmd->timeZone],
           cmd->timeZone_length);
    size_t totalSize = 0;
    totalSize += cmd->timeZone_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_ScriptSetTimeZone))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ScriptInvokeIDCreate(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptInvokeIDCreate *cmd = static_cast<const RS_CMD_ScriptInvokeIDCreate *>(vp);
    
    RsScriptInvokeID ret = rsi_ScriptInvokeIDCreate(con,
           cmd->s,
           cmd->slot);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_ScriptInvoke(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptInvoke *cmd = static_cast<const RS_CMD_ScriptInvoke *>(vp);
    rsi_ScriptInvoke(con,
           cmd->s,
           cmd->slot);
};

void rsp_ScriptInvokeV(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptInvokeV *cmd = static_cast<const RS_CMD_ScriptInvokeV *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_ScriptInvokeV)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_ScriptInvokeV(con,
           cmd->s,
           cmd->slot,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_ScriptInvokeV))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ScriptForEach(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptForEach *cmd = static_cast<const RS_CMD_ScriptForEach *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_ScriptForEach)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_ScriptForEach(con,
           cmd->s,
           cmd->slot,
           cmd->ain,
           cmd->aout,
           cmd->usr_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->usr],
           cmd->usr_length,
           cmd->sc_length == 0 ? NULL : (const RsScriptCall *)&baseData[(intptr_t)cmd->sc],
           cmd->sc_length);
    size_t totalSize = 0;
    totalSize += cmd->usr_length;
    totalSize += cmd->sc_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_ScriptForEach))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ScriptForEachMulti(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptForEachMulti *cmd = static_cast<const RS_CMD_ScriptForEachMulti *>(vp);
    rsi_ScriptForEachMulti(con,
           cmd->s,
           cmd->slot,
           cmd->ains,
           cmd->ains_length,
           cmd->aout,
           cmd->usr,
           cmd->usr_length,
           cmd->sc,
           cmd->sc_length);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_ScriptReduce(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptReduce *cmd = static_cast<const RS_CMD_ScriptReduce *>(vp);
    rsi_ScriptReduce(con,
           cmd->s,
           cmd->slot,
           cmd->ains,
           cmd->ains_length,
           cmd->aout,
           cmd->sc,
           cmd->sc_length);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_ScriptSetVarI(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarI *cmd = static_cast<const RS_CMD_ScriptSetVarI *>(vp);
    rsi_ScriptSetVarI(con,
           cmd->s,
           cmd->slot,
           cmd->value);
};

void rsp_ScriptSetVarObj(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarObj *cmd = static_cast<const RS_CMD_ScriptSetVarObj *>(vp);
    rsi_ScriptSetVarObj(con,
           cmd->s,
           cmd->slot,
           cmd->value);
};

void rsp_ScriptSetVarJ(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarJ *cmd = static_cast<const RS_CMD_ScriptSetVarJ *>(vp);
    rsi_ScriptSetVarJ(con,
           cmd->s,
           cmd->slot,
           cmd->value);
};

void rsp_ScriptSetVarF(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarF *cmd = static_cast<const RS_CMD_ScriptSetVarF *>(vp);
    rsi_ScriptSetVarF(con,
           cmd->s,
           cmd->slot,
           cmd->value);
};

void rsp_ScriptSetVarD(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarD *cmd = static_cast<const RS_CMD_ScriptSetVarD *>(vp);
    rsi_ScriptSetVarD(con,
           cmd->s,
           cmd->slot,
           cmd->value);
};

void rsp_ScriptSetVarV(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarV *cmd = static_cast<const RS_CMD_ScriptSetVarV *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_ScriptSetVarV)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_ScriptSetVarV(con,
           cmd->s,
           cmd->slot,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_ScriptSetVarV))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ScriptGetVarV(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptGetVarV *cmd = static_cast<const RS_CMD_ScriptGetVarV *>(vp);
    rsi_ScriptGetVarV(con,
           cmd->s,
           cmd->slot,
           cmd->data,
           cmd->data_length);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_ScriptSetVarVE(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptSetVarVE *cmd = static_cast<const RS_CMD_ScriptSetVarVE *>(vp);
    const uint8_t *baseData = 0;
    if (cmdSizeBytes != sizeof(RS_CMD_ScriptSetVarVE)) {
        baseData = &((const uint8_t *)vp)[sizeof(*cmd)];
    }
    rsi_ScriptSetVarVE(con,
           cmd->s,
           cmd->slot,
           cmd->data_length == 0 ? NULL : (const void *)&baseData[(intptr_t)cmd->data],
           cmd->data_length,
           cmd->e,
           cmd->dims_length == 0 ? NULL : (const uint32_t *)&baseData[(intptr_t)cmd->dims],
           cmd->dims_length);
    size_t totalSize = 0;
    totalSize += cmd->data_length;
    totalSize += cmd->dims_length;
    if ((totalSize != 0) && (cmdSizeBytes == sizeof(RS_CMD_ScriptSetVarVE))) {
        con->mIO.coreSetReturn(NULL, 0);
    }
};

void rsp_ScriptCCreate(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptCCreate *cmd = static_cast<const RS_CMD_ScriptCCreate *>(vp);
    
    RsScript ret = rsi_ScriptCCreate(con,
           cmd->resName,
           cmd->resName_length,
           cmd->cacheDir,
           cmd->cacheDir_length,
           cmd->text,
           cmd->text_length);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_ScriptIntrinsicCreate(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptIntrinsicCreate *cmd = static_cast<const RS_CMD_ScriptIntrinsicCreate *>(vp);
    
    RsScript ret = rsi_ScriptIntrinsicCreate(con,
           cmd->id,
           cmd->eid);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_ScriptGroupSetOutput(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptGroupSetOutput *cmd = static_cast<const RS_CMD_ScriptGroupSetOutput *>(vp);
    rsi_ScriptGroupSetOutput(con,
           cmd->group,
           cmd->kernel,
           cmd->alloc);
};

void rsp_ScriptGroupSetInput(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptGroupSetInput *cmd = static_cast<const RS_CMD_ScriptGroupSetInput *>(vp);
    rsi_ScriptGroupSetInput(con,
           cmd->group,
           cmd->kernel,
           cmd->alloc);
};

void rsp_ScriptGroupExecute(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ScriptGroupExecute *cmd = static_cast<const RS_CMD_ScriptGroupExecute *>(vp);
    rsi_ScriptGroupExecute(con,
           cmd->group);
};

void rsp_AllocationIoSend(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationIoSend *cmd = static_cast<const RS_CMD_AllocationIoSend *>(vp);
    rsi_AllocationIoSend(con,
           cmd->alloc);
};

void rsp_AllocationIoReceive(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_AllocationIoReceive *cmd = static_cast<const RS_CMD_AllocationIoReceive *>(vp);
    
    int64_t ret = rsi_AllocationIoReceive(con,
           cmd->alloc);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_ProgramBindConstants(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ProgramBindConstants *cmd = static_cast<const RS_CMD_ProgramBindConstants *>(vp);
    rsi_ProgramBindConstants(con,
           cmd->vp,
           cmd->slot,
           cmd->constants);
};

void rsp_ProgramBindTexture(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ProgramBindTexture *cmd = static_cast<const RS_CMD_ProgramBindTexture *>(vp);
    rsi_ProgramBindTexture(con,
           cmd->pf,
           cmd->slot,
           cmd->a);
};

void rsp_ProgramBindSampler(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ProgramBindSampler *cmd = static_cast<const RS_CMD_ProgramBindSampler *>(vp);
    rsi_ProgramBindSampler(con,
           cmd->pf,
           cmd->slot,
           cmd->s);
};

void rsp_FontCreateFromFile(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_FontCreateFromFile *cmd = static_cast<const RS_CMD_FontCreateFromFile *>(vp);
    
    RsFont ret = rsi_FontCreateFromFile(con,
           cmd->name,
           cmd->name_length,
           cmd->fontSize,
           cmd->dpi);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_FontCreateFromMemory(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_FontCreateFromMemory *cmd = static_cast<const RS_CMD_FontCreateFromMemory *>(vp);
    
    RsFont ret = rsi_FontCreateFromMemory(con,
           cmd->name,
           cmd->name_length,
           cmd->fontSize,
           cmd->dpi,
           cmd->data,
           cmd->data_length);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_MeshCreate(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_MeshCreate *cmd = static_cast<const RS_CMD_MeshCreate *>(vp);
    
    RsMesh ret = rsi_MeshCreate(con,
           cmd->vtx,
           cmd->vtx_length,
           cmd->idx,
           cmd->idx_length,
           cmd->primType,
           cmd->primType_length);
    con->mIO.coreSetReturn(&ret, sizeof(ret));
};

void rsp_ContextBindProgramStore(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextBindProgramStore *cmd = static_cast<const RS_CMD_ContextBindProgramStore *>(vp);
    rsi_ContextBindProgramStore(con,
           cmd->pgm);
};

void rsp_ContextBindProgramFragment(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextBindProgramFragment *cmd = static_cast<const RS_CMD_ContextBindProgramFragment *>(vp);
    rsi_ContextBindProgramFragment(con,
           cmd->pgm);
};

void rsp_ContextBindProgramVertex(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextBindProgramVertex *cmd = static_cast<const RS_CMD_ContextBindProgramVertex *>(vp);
    rsi_ContextBindProgramVertex(con,
           cmd->pgm);
};

void rsp_ContextBindProgramRaster(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextBindProgramRaster *cmd = static_cast<const RS_CMD_ContextBindProgramRaster *>(vp);
    rsi_ContextBindProgramRaster(con,
           cmd->pgm);
};

void rsp_ContextBindFont(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextBindFont *cmd = static_cast<const RS_CMD_ContextBindFont *>(vp);
    rsi_ContextBindFont(con,
           cmd->pgm);
};

void rsp_ContextSetSurface(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextSetSurface *cmd = static_cast<const RS_CMD_ContextSetSurface *>(vp);
    rsi_ContextSetSurface(con,
           cmd->width,
           cmd->height,
           cmd->sur);
    con->mIO.coreSetReturn(NULL, 0);
};

void rsp_ContextBindRootScript(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextBindRootScript *cmd = static_cast<const RS_CMD_ContextBindRootScript *>(vp);
    rsi_ContextBindRootScript(con,
           cmd->sampler);
};

void rsp_ContextPause(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextPause *cmd = static_cast<const RS_CMD_ContextPause *>(vp);
    rsi_ContextPause(con);
};

void rsp_ContextResume(Context *con, const void *vp, size_t cmdSizeBytes) {
    const RS_CMD_ContextResume *cmd = static_cast<const RS_CMD_ContextResume *>(vp);
    rsi_ContextResume(con);
};

RsPlaybackLocalFunc gPlaybackFuncs[95] = {
    NULL,
    NULL,
    NULL,
    NULL,
    rsp_ContextSendMessage,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    rsp_AllocationSetupBufferQueue,
    rsp_AllocationShareBufferQueue,
    rsp_AllocationGetSurface,
    rsp_AllocationSetSurface,
    NULL,
    rsp_AllocationAdapterOffset,
    rsp_ContextFinish,
    rsp_ContextDump,
    rsp_ContextSetPriority,
    rsp_ContextDestroyWorker,
    rsp_AssignName,
    rsp_ObjDestroy,
    NULL,
    NULL,
    rsp_AllocationCopyToBitmap,
    rsp_AllocationGetPointer,
    rsp_Allocation1DData,
    rsp_Allocation1DElementData,
    rsp_AllocationElementData,
    rsp_Allocation2DData,
    rsp_Allocation3DData,
    rsp_AllocationGenerateMipmaps,
    rsp_AllocationRead,
    rsp_Allocation1DRead,
    rsp_AllocationElementRead,
    rsp_Allocation2DRead,
    rsp_Allocation3DRead,
    rsp_AllocationSyncAll,
    rsp_AllocationResize1D,
    rsp_AllocationCopy2DRange,
    rsp_AllocationCopy3DRange,
    NULL,
    NULL,
    rsp_ClosureSetArg,
    rsp_ClosureSetGlobal,
    NULL,
    rsp_ScriptBindAllocation,
    rsp_ScriptSetTimeZone,
    rsp_ScriptInvokeIDCreate,
    rsp_ScriptInvoke,
    rsp_ScriptInvokeV,
    rsp_ScriptForEach,
    rsp_ScriptForEachMulti,
    rsp_ScriptReduce,
    rsp_ScriptSetVarI,
    rsp_ScriptSetVarObj,
    rsp_ScriptSetVarJ,
    rsp_ScriptSetVarF,
    rsp_ScriptSetVarD,
    rsp_ScriptSetVarV,
    rsp_ScriptGetVarV,
    rsp_ScriptSetVarVE,
    rsp_ScriptCCreate,
    rsp_ScriptIntrinsicCreate,
    NULL,
    NULL,
    NULL,
    rsp_ScriptGroupSetOutput,
    rsp_ScriptGroupSetInput,
    rsp_ScriptGroupExecute,
    NULL,
    rsp_AllocationIoSend,
    rsp_AllocationIoReceive,
    NULL,
    NULL,
    rsp_ProgramBindConstants,
    rsp_ProgramBindTexture,
    rsp_ProgramBindSampler,
    NULL,
    NULL,
    rsp_FontCreateFromFile,
    rsp_FontCreateFromMemory,
    rsp_MeshCreate,
    rsp_ContextBindProgramStore,
    rsp_ContextBindProgramFragment,
    rsp_ContextBindProgramVertex,
    rsp_ContextBindProgramRaster,
    rsp_ContextBindFont,
    rsp_ContextSetSurface,
    rsp_ContextBindRootScript,
    rsp_ContextPause,
    rsp_ContextResume,
};
};
};
