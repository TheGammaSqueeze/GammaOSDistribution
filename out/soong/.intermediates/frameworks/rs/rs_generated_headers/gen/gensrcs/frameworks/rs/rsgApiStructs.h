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


#include "rsContext.h"
#include "rsFifo.h"

namespace android {
namespace renderscript {
typedef struct RS_CMD_ContextDestroy_rec RS_CMD_ContextDestroy;
typedef struct RS_CMD_ContextGetMessage_rec RS_CMD_ContextGetMessage;
typedef struct RS_CMD_ContextPeekMessage_rec RS_CMD_ContextPeekMessage;
typedef struct RS_CMD_ContextSendMessage_rec RS_CMD_ContextSendMessage;
typedef struct RS_CMD_ContextInitToClient_rec RS_CMD_ContextInitToClient;
typedef struct RS_CMD_ContextDeinitToClient_rec RS_CMD_ContextDeinitToClient;
typedef struct RS_CMD_ContextSetCacheDir_rec RS_CMD_ContextSetCacheDir;
typedef struct RS_CMD_TypeCreate_rec RS_CMD_TypeCreate;
typedef struct RS_CMD_TypeCreate2_rec RS_CMD_TypeCreate2;
typedef struct RS_CMD_AllocationCreateTyped_rec RS_CMD_AllocationCreateTyped;
typedef struct RS_CMD_AllocationCreateFromBitmap_rec RS_CMD_AllocationCreateFromBitmap;
typedef struct RS_CMD_AllocationCubeCreateFromBitmap_rec RS_CMD_AllocationCubeCreateFromBitmap;
typedef struct RS_CMD_AllocationSetupBufferQueue_rec RS_CMD_AllocationSetupBufferQueue;
typedef struct RS_CMD_AllocationShareBufferQueue_rec RS_CMD_AllocationShareBufferQueue;
typedef struct RS_CMD_AllocationGetSurface_rec RS_CMD_AllocationGetSurface;
typedef struct RS_CMD_AllocationSetSurface_rec RS_CMD_AllocationSetSurface;
typedef struct RS_CMD_AllocationAdapterCreate_rec RS_CMD_AllocationAdapterCreate;
typedef struct RS_CMD_AllocationAdapterOffset_rec RS_CMD_AllocationAdapterOffset;
typedef struct RS_CMD_ContextFinish_rec RS_CMD_ContextFinish;
typedef struct RS_CMD_ContextDump_rec RS_CMD_ContextDump;
typedef struct RS_CMD_ContextSetPriority_rec RS_CMD_ContextSetPriority;
typedef struct RS_CMD_ContextDestroyWorker_rec RS_CMD_ContextDestroyWorker;
typedef struct RS_CMD_AssignName_rec RS_CMD_AssignName;
typedef struct RS_CMD_ObjDestroy_rec RS_CMD_ObjDestroy;
typedef struct RS_CMD_ElementCreate_rec RS_CMD_ElementCreate;
typedef struct RS_CMD_ElementCreate2_rec RS_CMD_ElementCreate2;
typedef struct RS_CMD_AllocationCopyToBitmap_rec RS_CMD_AllocationCopyToBitmap;
typedef struct RS_CMD_AllocationGetPointer_rec RS_CMD_AllocationGetPointer;
typedef struct RS_CMD_Allocation1DData_rec RS_CMD_Allocation1DData;
typedef struct RS_CMD_Allocation1DElementData_rec RS_CMD_Allocation1DElementData;
typedef struct RS_CMD_AllocationElementData_rec RS_CMD_AllocationElementData;
typedef struct RS_CMD_Allocation2DData_rec RS_CMD_Allocation2DData;
typedef struct RS_CMD_Allocation3DData_rec RS_CMD_Allocation3DData;
typedef struct RS_CMD_AllocationGenerateMipmaps_rec RS_CMD_AllocationGenerateMipmaps;
typedef struct RS_CMD_AllocationRead_rec RS_CMD_AllocationRead;
typedef struct RS_CMD_Allocation1DRead_rec RS_CMD_Allocation1DRead;
typedef struct RS_CMD_AllocationElementRead_rec RS_CMD_AllocationElementRead;
typedef struct RS_CMD_Allocation2DRead_rec RS_CMD_Allocation2DRead;
typedef struct RS_CMD_Allocation3DRead_rec RS_CMD_Allocation3DRead;
typedef struct RS_CMD_AllocationSyncAll_rec RS_CMD_AllocationSyncAll;
typedef struct RS_CMD_AllocationResize1D_rec RS_CMD_AllocationResize1D;
typedef struct RS_CMD_AllocationCopy2DRange_rec RS_CMD_AllocationCopy2DRange;
typedef struct RS_CMD_AllocationCopy3DRange_rec RS_CMD_AllocationCopy3DRange;
typedef struct RS_CMD_ClosureCreate_rec RS_CMD_ClosureCreate;
typedef struct RS_CMD_InvokeClosureCreate_rec RS_CMD_InvokeClosureCreate;
typedef struct RS_CMD_ClosureSetArg_rec RS_CMD_ClosureSetArg;
typedef struct RS_CMD_ClosureSetGlobal_rec RS_CMD_ClosureSetGlobal;
typedef struct RS_CMD_SamplerCreate_rec RS_CMD_SamplerCreate;
typedef struct RS_CMD_ScriptBindAllocation_rec RS_CMD_ScriptBindAllocation;
typedef struct RS_CMD_ScriptSetTimeZone_rec RS_CMD_ScriptSetTimeZone;
typedef struct RS_CMD_ScriptInvokeIDCreate_rec RS_CMD_ScriptInvokeIDCreate;
typedef struct RS_CMD_ScriptInvoke_rec RS_CMD_ScriptInvoke;
typedef struct RS_CMD_ScriptInvokeV_rec RS_CMD_ScriptInvokeV;
typedef struct RS_CMD_ScriptForEach_rec RS_CMD_ScriptForEach;
typedef struct RS_CMD_ScriptForEachMulti_rec RS_CMD_ScriptForEachMulti;
typedef struct RS_CMD_ScriptReduce_rec RS_CMD_ScriptReduce;
typedef struct RS_CMD_ScriptSetVarI_rec RS_CMD_ScriptSetVarI;
typedef struct RS_CMD_ScriptSetVarObj_rec RS_CMD_ScriptSetVarObj;
typedef struct RS_CMD_ScriptSetVarJ_rec RS_CMD_ScriptSetVarJ;
typedef struct RS_CMD_ScriptSetVarF_rec RS_CMD_ScriptSetVarF;
typedef struct RS_CMD_ScriptSetVarD_rec RS_CMD_ScriptSetVarD;
typedef struct RS_CMD_ScriptSetVarV_rec RS_CMD_ScriptSetVarV;
typedef struct RS_CMD_ScriptGetVarV_rec RS_CMD_ScriptGetVarV;
typedef struct RS_CMD_ScriptSetVarVE_rec RS_CMD_ScriptSetVarVE;
typedef struct RS_CMD_ScriptCCreate_rec RS_CMD_ScriptCCreate;
typedef struct RS_CMD_ScriptIntrinsicCreate_rec RS_CMD_ScriptIntrinsicCreate;
typedef struct RS_CMD_ScriptKernelIDCreate_rec RS_CMD_ScriptKernelIDCreate;
typedef struct RS_CMD_ScriptFieldIDCreate_rec RS_CMD_ScriptFieldIDCreate;
typedef struct RS_CMD_ScriptGroupCreate_rec RS_CMD_ScriptGroupCreate;
typedef struct RS_CMD_ScriptGroupSetOutput_rec RS_CMD_ScriptGroupSetOutput;
typedef struct RS_CMD_ScriptGroupSetInput_rec RS_CMD_ScriptGroupSetInput;
typedef struct RS_CMD_ScriptGroupExecute_rec RS_CMD_ScriptGroupExecute;
typedef struct RS_CMD_ScriptGroup2Create_rec RS_CMD_ScriptGroup2Create;
typedef struct RS_CMD_AllocationIoSend_rec RS_CMD_AllocationIoSend;
typedef struct RS_CMD_AllocationIoReceive_rec RS_CMD_AllocationIoReceive;
typedef struct RS_CMD_ProgramStoreCreate_rec RS_CMD_ProgramStoreCreate;
typedef struct RS_CMD_ProgramRasterCreate_rec RS_CMD_ProgramRasterCreate;
typedef struct RS_CMD_ProgramBindConstants_rec RS_CMD_ProgramBindConstants;
typedef struct RS_CMD_ProgramBindTexture_rec RS_CMD_ProgramBindTexture;
typedef struct RS_CMD_ProgramBindSampler_rec RS_CMD_ProgramBindSampler;
typedef struct RS_CMD_ProgramFragmentCreate_rec RS_CMD_ProgramFragmentCreate;
typedef struct RS_CMD_ProgramVertexCreate_rec RS_CMD_ProgramVertexCreate;
typedef struct RS_CMD_FontCreateFromFile_rec RS_CMD_FontCreateFromFile;
typedef struct RS_CMD_FontCreateFromMemory_rec RS_CMD_FontCreateFromMemory;
typedef struct RS_CMD_MeshCreate_rec RS_CMD_MeshCreate;
typedef struct RS_CMD_ContextBindProgramStore_rec RS_CMD_ContextBindProgramStore;
typedef struct RS_CMD_ContextBindProgramFragment_rec RS_CMD_ContextBindProgramFragment;
typedef struct RS_CMD_ContextBindProgramVertex_rec RS_CMD_ContextBindProgramVertex;
typedef struct RS_CMD_ContextBindProgramRaster_rec RS_CMD_ContextBindProgramRaster;
typedef struct RS_CMD_ContextBindFont_rec RS_CMD_ContextBindFont;
typedef struct RS_CMD_ContextSetSurface_rec RS_CMD_ContextSetSurface;
typedef struct RS_CMD_ContextBindRootScript_rec RS_CMD_ContextBindRootScript;
typedef struct RS_CMD_ContextPause_rec RS_CMD_ContextPause;
typedef struct RS_CMD_ContextResume_rec RS_CMD_ContextResume;

#define RS_CMD_ID_ContextDestroy 1
struct __attribute__((packed)) RS_CMD_ContextDestroy_rec {
};

#define RS_CMD_ID_ContextGetMessage 2
struct __attribute__((packed)) RS_CMD_ContextGetMessage_rec {
    void * data;
    size_t data_length;
    size_t * receiveLen;
    size_t receiveLen_length;
    uint32_t * usrID;
    size_t usrID_length;
};

#define RS_CMD_ID_ContextPeekMessage 3
struct __attribute__((packed)) RS_CMD_ContextPeekMessage_rec {
    size_t * receiveLen;
    size_t receiveLen_length;
    uint32_t * usrID;
    size_t usrID_length;
};

#define RS_CMD_ID_ContextSendMessage 4
struct __attribute__((packed)) RS_CMD_ContextSendMessage_rec {
    uint32_t id;
    const uint8_t * data;
    size_t data_length;
};

#define RS_CMD_ID_ContextInitToClient 5
struct __attribute__((packed)) RS_CMD_ContextInitToClient_rec {
};

#define RS_CMD_ID_ContextDeinitToClient 6
struct __attribute__((packed)) RS_CMD_ContextDeinitToClient_rec {
};

#define RS_CMD_ID_ContextSetCacheDir 7
struct __attribute__((packed)) RS_CMD_ContextSetCacheDir_rec {
    const char * cacheDir;
    size_t cacheDir_length;
};

#define RS_CMD_ID_TypeCreate 8
struct __attribute__((packed)) RS_CMD_TypeCreate_rec {
    RsElement e;
    uint32_t dimX;
    uint32_t dimY;
    uint32_t dimZ;
    bool mipmaps;
    bool faces;
    uint32_t yuv;
};

#define RS_CMD_ID_TypeCreate2 9
struct __attribute__((packed)) RS_CMD_TypeCreate2_rec {
    const RsTypeCreateParams * dat;
    size_t dat_length;
};

#define RS_CMD_ID_AllocationCreateTyped 10
struct __attribute__((packed)) RS_CMD_AllocationCreateTyped_rec {
    RsType vtype;
    RsAllocationMipmapControl mipmaps;
    uint32_t usages;
    uintptr_t ptr;
};

#define RS_CMD_ID_AllocationCreateFromBitmap 11
struct __attribute__((packed)) RS_CMD_AllocationCreateFromBitmap_rec {
    RsType vtype;
    RsAllocationMipmapControl mipmaps;
    const void * data;
    size_t data_length;
    uint32_t usages;
};

#define RS_CMD_ID_AllocationCubeCreateFromBitmap 12
struct __attribute__((packed)) RS_CMD_AllocationCubeCreateFromBitmap_rec {
    RsType vtype;
    RsAllocationMipmapControl mipmaps;
    const void * data;
    size_t data_length;
    uint32_t usages;
};

#define RS_CMD_ID_AllocationSetupBufferQueue 13
struct __attribute__((packed)) RS_CMD_AllocationSetupBufferQueue_rec {
    RsAllocation alloc;
    uint32_t numAlloc;
};

#define RS_CMD_ID_AllocationShareBufferQueue 14
struct __attribute__((packed)) RS_CMD_AllocationShareBufferQueue_rec {
    RsAllocation alloc1;
    RsAllocation alloc2;
};

#define RS_CMD_ID_AllocationGetSurface 15
struct __attribute__((packed)) RS_CMD_AllocationGetSurface_rec {
    RsAllocation alloc;
};

#define RS_CMD_ID_AllocationSetSurface 16
struct __attribute__((packed)) RS_CMD_AllocationSetSurface_rec {
    RsAllocation alloc;
    RsNativeWindow sur;
};

#define RS_CMD_ID_AllocationAdapterCreate 17
struct __attribute__((packed)) RS_CMD_AllocationAdapterCreate_rec {
    RsType vtype;
    RsAllocation baseAlloc;
};

#define RS_CMD_ID_AllocationAdapterOffset 18
struct __attribute__((packed)) RS_CMD_AllocationAdapterOffset_rec {
    RsAllocation alloc;
    const uint32_t * offsets;
    size_t offsets_length;
};

#define RS_CMD_ID_ContextFinish 19
struct __attribute__((packed)) RS_CMD_ContextFinish_rec {
};

#define RS_CMD_ID_ContextDump 20
struct __attribute__((packed)) RS_CMD_ContextDump_rec {
    int32_t bits;
};

#define RS_CMD_ID_ContextSetPriority 21
struct __attribute__((packed)) RS_CMD_ContextSetPriority_rec {
    int32_t priority;
};

#define RS_CMD_ID_ContextDestroyWorker 22
struct __attribute__((packed)) RS_CMD_ContextDestroyWorker_rec {
};

#define RS_CMD_ID_AssignName 23
struct __attribute__((packed)) RS_CMD_AssignName_rec {
    RsObjectBase obj;
    const char * name;
    size_t name_length;
};

#define RS_CMD_ID_ObjDestroy 24
struct __attribute__((packed)) RS_CMD_ObjDestroy_rec {
    RsAsyncVoidPtr objPtr;
};

#define RS_CMD_ID_ElementCreate 25
struct __attribute__((packed)) RS_CMD_ElementCreate_rec {
    RsDataType mType;
    RsDataKind mKind;
    bool mNormalized;
    uint32_t mVectorSize;
};

#define RS_CMD_ID_ElementCreate2 26
struct __attribute__((packed)) RS_CMD_ElementCreate2_rec {
    const RsElement * elements;
    size_t elements_length;
    const char ** names;
    size_t names_length_length;
    const size_t * names_length;
    const uint32_t * arraySize;
    size_t arraySize_length;
};

#define RS_CMD_ID_AllocationCopyToBitmap 27
struct __attribute__((packed)) RS_CMD_AllocationCopyToBitmap_rec {
    RsAllocation alloc;
    void * data;
    size_t data_length;
};

#define RS_CMD_ID_AllocationGetPointer 28
struct __attribute__((packed)) RS_CMD_AllocationGetPointer_rec {
    RsAllocation va;
    uint32_t lod;
    RsAllocationCubemapFace face;
    uint32_t z;
    uint32_t array;
    size_t * stride;
    size_t stride_length;
};

#define RS_CMD_ID_Allocation1DData 29
struct __attribute__((packed)) RS_CMD_Allocation1DData_rec {
    RsAllocation va;
    uint32_t xoff;
    uint32_t lod;
    uint32_t count;
    const void * data;
    size_t data_length;
};

#define RS_CMD_ID_Allocation1DElementData 30
struct __attribute__((packed)) RS_CMD_Allocation1DElementData_rec {
    RsAllocation va;
    uint32_t x;
    uint32_t lod;
    const void * data;
    size_t data_length;
    size_t comp_offset;
};

#define RS_CMD_ID_AllocationElementData 31
struct __attribute__((packed)) RS_CMD_AllocationElementData_rec {
    RsAllocation va;
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t lod;
    const void * data;
    size_t data_length;
    size_t comp_offset;
};

#define RS_CMD_ID_Allocation2DData 32
struct __attribute__((packed)) RS_CMD_Allocation2DData_rec {
    RsAllocation va;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t lod;
    RsAllocationCubemapFace face;
    uint32_t w;
    uint32_t h;
    const void * data;
    size_t data_length;
    size_t stride;
};

#define RS_CMD_ID_Allocation3DData 33
struct __attribute__((packed)) RS_CMD_Allocation3DData_rec {
    RsAllocation va;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t zoff;
    uint32_t lod;
    uint32_t w;
    uint32_t h;
    uint32_t d;
    const void * data;
    size_t data_length;
    size_t stride;
};

#define RS_CMD_ID_AllocationGenerateMipmaps 34
struct __attribute__((packed)) RS_CMD_AllocationGenerateMipmaps_rec {
    RsAllocation va;
};

#define RS_CMD_ID_AllocationRead 35
struct __attribute__((packed)) RS_CMD_AllocationRead_rec {
    RsAllocation va;
    void * data;
    size_t data_length;
};

#define RS_CMD_ID_Allocation1DRead 36
struct __attribute__((packed)) RS_CMD_Allocation1DRead_rec {
    RsAllocation va;
    uint32_t xoff;
    uint32_t lod;
    uint32_t count;
    void * data;
    size_t data_length;
};

#define RS_CMD_ID_AllocationElementRead 37
struct __attribute__((packed)) RS_CMD_AllocationElementRead_rec {
    RsAllocation va;
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t lod;
    void * data;
    size_t data_length;
    size_t comp_offset;
};

#define RS_CMD_ID_Allocation2DRead 38
struct __attribute__((packed)) RS_CMD_Allocation2DRead_rec {
    RsAllocation va;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t lod;
    RsAllocationCubemapFace face;
    uint32_t w;
    uint32_t h;
    void * data;
    size_t data_length;
    size_t stride;
};

#define RS_CMD_ID_Allocation3DRead 39
struct __attribute__((packed)) RS_CMD_Allocation3DRead_rec {
    RsAllocation va;
    uint32_t xoff;
    uint32_t yoff;
    uint32_t zoff;
    uint32_t lod;
    uint32_t w;
    uint32_t h;
    uint32_t d;
    void * data;
    size_t data_length;
    size_t stride;
};

#define RS_CMD_ID_AllocationSyncAll 40
struct __attribute__((packed)) RS_CMD_AllocationSyncAll_rec {
    RsAllocation va;
    RsAllocationUsageType src;
};

#define RS_CMD_ID_AllocationResize1D 41
struct __attribute__((packed)) RS_CMD_AllocationResize1D_rec {
    RsAllocation va;
    uint32_t dimX;
};

#define RS_CMD_ID_AllocationCopy2DRange 42
struct __attribute__((packed)) RS_CMD_AllocationCopy2DRange_rec {
    RsAllocation dest;
    uint32_t destXoff;
    uint32_t destYoff;
    uint32_t destMip;
    uint32_t destFace;
    uint32_t width;
    uint32_t height;
    RsAllocation src;
    uint32_t srcXoff;
    uint32_t srcYoff;
    uint32_t srcMip;
    uint32_t srcFace;
};

#define RS_CMD_ID_AllocationCopy3DRange 43
struct __attribute__((packed)) RS_CMD_AllocationCopy3DRange_rec {
    RsAllocation dest;
    uint32_t destXoff;
    uint32_t destYoff;
    uint32_t destZoff;
    uint32_t destMip;
    uint32_t width;
    uint32_t height;
    uint32_t depth;
    RsAllocation src;
    uint32_t srcXoff;
    uint32_t srcYoff;
    uint32_t srcZoff;
    uint32_t srcMip;
};

#define RS_CMD_ID_ClosureCreate 44
struct __attribute__((packed)) RS_CMD_ClosureCreate_rec {
    RsScriptKernelID kernelID;
    RsAllocation returnValue;
    RsScriptFieldID * fieldIDs;
    size_t fieldIDs_length;
    const int64_t * values;
    size_t values_length;
    const int * sizes;
    size_t sizes_length;
    RsClosure * depClosures;
    size_t depClosures_length;
    RsScriptFieldID * depFieldIDs;
    size_t depFieldIDs_length;
};

#define RS_CMD_ID_InvokeClosureCreate 45
struct __attribute__((packed)) RS_CMD_InvokeClosureCreate_rec {
    RsScriptInvokeID invokeID;
    const void * params;
    size_t params_length;
    const RsScriptFieldID * fieldIDs;
    size_t fieldIDs_length;
    const int64_t * values;
    size_t values_length;
    const int * sizes;
    size_t sizes_length;
};

#define RS_CMD_ID_ClosureSetArg 46
struct __attribute__((packed)) RS_CMD_ClosureSetArg_rec {
    RsClosure closureID;
    uint32_t index;
    uintptr_t value;
    int valueSize;
};

#define RS_CMD_ID_ClosureSetGlobal 47
struct __attribute__((packed)) RS_CMD_ClosureSetGlobal_rec {
    RsClosure closureID;
    RsScriptFieldID fieldID;
    int64_t value;
    int valueSize;
};

#define RS_CMD_ID_SamplerCreate 48
struct __attribute__((packed)) RS_CMD_SamplerCreate_rec {
    RsSamplerValue magFilter;
    RsSamplerValue minFilter;
    RsSamplerValue wrapS;
    RsSamplerValue wrapT;
    RsSamplerValue wrapR;
    float mAniso;
};

#define RS_CMD_ID_ScriptBindAllocation 49
struct __attribute__((packed)) RS_CMD_ScriptBindAllocation_rec {
    RsScript vtm;
    RsAllocation va;
    uint32_t slot;
};

#define RS_CMD_ID_ScriptSetTimeZone 50
struct __attribute__((packed)) RS_CMD_ScriptSetTimeZone_rec {
    RsScript s;
    const char * timeZone;
    size_t timeZone_length;
};

#define RS_CMD_ID_ScriptInvokeIDCreate 51
struct __attribute__((packed)) RS_CMD_ScriptInvokeIDCreate_rec {
    RsScript s;
    uint32_t slot;
};

#define RS_CMD_ID_ScriptInvoke 52
struct __attribute__((packed)) RS_CMD_ScriptInvoke_rec {
    RsScript s;
    uint32_t slot;
};

#define RS_CMD_ID_ScriptInvokeV 53
struct __attribute__((packed)) RS_CMD_ScriptInvokeV_rec {
    RsScript s;
    uint32_t slot;
    const void * data;
    size_t data_length;
};

#define RS_CMD_ID_ScriptForEach 54
struct __attribute__((packed)) RS_CMD_ScriptForEach_rec {
    RsScript s;
    uint32_t slot;
    RsAllocation ain;
    RsAllocation aout;
    const void * usr;
    size_t usr_length;
    const RsScriptCall * sc;
    size_t sc_length;
};

#define RS_CMD_ID_ScriptForEachMulti 55
struct __attribute__((packed)) RS_CMD_ScriptForEachMulti_rec {
    RsScript s;
    uint32_t slot;
    RsAllocation * ains;
    size_t ains_length;
    RsAllocation aout;
    const void * usr;
    size_t usr_length;
    const RsScriptCall * sc;
    size_t sc_length;
};

#define RS_CMD_ID_ScriptReduce 56
struct __attribute__((packed)) RS_CMD_ScriptReduce_rec {
    RsScript s;
    uint32_t slot;
    RsAllocation * ains;
    size_t ains_length;
    RsAllocation aout;
    const RsScriptCall * sc;
    size_t sc_length;
};

#define RS_CMD_ID_ScriptSetVarI 57
struct __attribute__((packed)) RS_CMD_ScriptSetVarI_rec {
    RsScript s;
    uint32_t slot;
    int value;
};

#define RS_CMD_ID_ScriptSetVarObj 58
struct __attribute__((packed)) RS_CMD_ScriptSetVarObj_rec {
    RsScript s;
    uint32_t slot;
    RsObjectBase value;
};

#define RS_CMD_ID_ScriptSetVarJ 59
struct __attribute__((packed)) RS_CMD_ScriptSetVarJ_rec {
    RsScript s;
    uint32_t slot;
    int64_t value;
};

#define RS_CMD_ID_ScriptSetVarF 60
struct __attribute__((packed)) RS_CMD_ScriptSetVarF_rec {
    RsScript s;
    uint32_t slot;
    float value;
};

#define RS_CMD_ID_ScriptSetVarD 61
struct __attribute__((packed)) RS_CMD_ScriptSetVarD_rec {
    RsScript s;
    uint32_t slot;
    double value;
};

#define RS_CMD_ID_ScriptSetVarV 62
struct __attribute__((packed)) RS_CMD_ScriptSetVarV_rec {
    RsScript s;
    uint32_t slot;
    const void * data;
    size_t data_length;
};

#define RS_CMD_ID_ScriptGetVarV 63
struct __attribute__((packed)) RS_CMD_ScriptGetVarV_rec {
    RsScript s;
    uint32_t slot;
    void * data;
    size_t data_length;
};

#define RS_CMD_ID_ScriptSetVarVE 64
struct __attribute__((packed)) RS_CMD_ScriptSetVarVE_rec {
    RsScript s;
    uint32_t slot;
    const void * data;
    size_t data_length;
    RsElement e;
    const uint32_t * dims;
    size_t dims_length;
};

#define RS_CMD_ID_ScriptCCreate 65
struct __attribute__((packed)) RS_CMD_ScriptCCreate_rec {
    const char * resName;
    size_t resName_length;
    const char * cacheDir;
    size_t cacheDir_length;
    const char * text;
    size_t text_length;
};

#define RS_CMD_ID_ScriptIntrinsicCreate 66
struct __attribute__((packed)) RS_CMD_ScriptIntrinsicCreate_rec {
    uint32_t id;
    RsElement eid;
};

#define RS_CMD_ID_ScriptKernelIDCreate 67
struct __attribute__((packed)) RS_CMD_ScriptKernelIDCreate_rec {
    RsScript sid;
    int slot;
    int sig;
};

#define RS_CMD_ID_ScriptFieldIDCreate 68
struct __attribute__((packed)) RS_CMD_ScriptFieldIDCreate_rec {
    RsScript sid;
    int slot;
};

#define RS_CMD_ID_ScriptGroupCreate 69
struct __attribute__((packed)) RS_CMD_ScriptGroupCreate_rec {
    RsScriptKernelID * kernels;
    size_t kernels_length;
    RsScriptKernelID * src;
    size_t src_length;
    RsScriptKernelID * dstK;
    size_t dstK_length;
    RsScriptFieldID * dstF;
    size_t dstF_length;
    const RsType * type;
    size_t type_length;
};

#define RS_CMD_ID_ScriptGroupSetOutput 70
struct __attribute__((packed)) RS_CMD_ScriptGroupSetOutput_rec {
    RsScriptGroup group;
    RsScriptKernelID kernel;
    RsAllocation alloc;
};

#define RS_CMD_ID_ScriptGroupSetInput 71
struct __attribute__((packed)) RS_CMD_ScriptGroupSetInput_rec {
    RsScriptGroup group;
    RsScriptKernelID kernel;
    RsAllocation alloc;
};

#define RS_CMD_ID_ScriptGroupExecute 72
struct __attribute__((packed)) RS_CMD_ScriptGroupExecute_rec {
    RsScriptGroup group;
};

#define RS_CMD_ID_ScriptGroup2Create 73
struct __attribute__((packed)) RS_CMD_ScriptGroup2Create_rec {
    const char * name;
    size_t name_length;
    const char * cacheDir;
    size_t cacheDir_length;
    RsClosure * closures;
    size_t closures_length;
};

#define RS_CMD_ID_AllocationIoSend 74
struct __attribute__((packed)) RS_CMD_AllocationIoSend_rec {
    RsAllocation alloc;
};

#define RS_CMD_ID_AllocationIoReceive 75
struct __attribute__((packed)) RS_CMD_AllocationIoReceive_rec {
    RsAllocation alloc;
};

#define RS_CMD_ID_ProgramStoreCreate 76
struct __attribute__((packed)) RS_CMD_ProgramStoreCreate_rec {
    bool colorMaskR;
    bool colorMaskG;
    bool colorMaskB;
    bool colorMaskA;
    bool depthMask;
    bool ditherEnable;
    RsBlendSrcFunc srcFunc;
    RsBlendDstFunc destFunc;
    RsDepthFunc depthFunc;
};

#define RS_CMD_ID_ProgramRasterCreate 77
struct __attribute__((packed)) RS_CMD_ProgramRasterCreate_rec {
    bool pointSprite;
    RsCullMode cull;
};

#define RS_CMD_ID_ProgramBindConstants 78
struct __attribute__((packed)) RS_CMD_ProgramBindConstants_rec {
    RsProgram vp;
    uint32_t slot;
    RsAllocation constants;
};

#define RS_CMD_ID_ProgramBindTexture 79
struct __attribute__((packed)) RS_CMD_ProgramBindTexture_rec {
    RsProgramFragment pf;
    uint32_t slot;
    RsAllocation a;
};

#define RS_CMD_ID_ProgramBindSampler 80
struct __attribute__((packed)) RS_CMD_ProgramBindSampler_rec {
    RsProgramFragment pf;
    uint32_t slot;
    RsSampler s;
};

#define RS_CMD_ID_ProgramFragmentCreate 81
struct __attribute__((packed)) RS_CMD_ProgramFragmentCreate_rec {
    const char * shaderText;
    size_t shaderText_length;
    const char ** textureNames;
    size_t textureNames_length_length;
    const size_t * textureNames_length;
    const uintptr_t * params;
    size_t params_length;
};

#define RS_CMD_ID_ProgramVertexCreate 82
struct __attribute__((packed)) RS_CMD_ProgramVertexCreate_rec {
    const char * shaderText;
    size_t shaderText_length;
    const char ** textureNames;
    size_t textureNames_length_length;
    const size_t * textureNames_length;
    const uintptr_t * params;
    size_t params_length;
};

#define RS_CMD_ID_FontCreateFromFile 83
struct __attribute__((packed)) RS_CMD_FontCreateFromFile_rec {
    const char * name;
    size_t name_length;
    float fontSize;
    uint32_t dpi;
};

#define RS_CMD_ID_FontCreateFromMemory 84
struct __attribute__((packed)) RS_CMD_FontCreateFromMemory_rec {
    const char * name;
    size_t name_length;
    float fontSize;
    uint32_t dpi;
    const void * data;
    size_t data_length;
};

#define RS_CMD_ID_MeshCreate 85
struct __attribute__((packed)) RS_CMD_MeshCreate_rec {
    RsAllocation * vtx;
    size_t vtx_length;
    RsAllocation * idx;
    size_t idx_length;
    uint32_t * primType;
    size_t primType_length;
};

#define RS_CMD_ID_ContextBindProgramStore 86
struct __attribute__((packed)) RS_CMD_ContextBindProgramStore_rec {
    RsProgramStore pgm;
};

#define RS_CMD_ID_ContextBindProgramFragment 87
struct __attribute__((packed)) RS_CMD_ContextBindProgramFragment_rec {
    RsProgramFragment pgm;
};

#define RS_CMD_ID_ContextBindProgramVertex 88
struct __attribute__((packed)) RS_CMD_ContextBindProgramVertex_rec {
    RsProgramVertex pgm;
};

#define RS_CMD_ID_ContextBindProgramRaster 89
struct __attribute__((packed)) RS_CMD_ContextBindProgramRaster_rec {
    RsProgramRaster pgm;
};

#define RS_CMD_ID_ContextBindFont 90
struct __attribute__((packed)) RS_CMD_ContextBindFont_rec {
    RsFont pgm;
};

#define RS_CMD_ID_ContextSetSurface 91
struct __attribute__((packed)) RS_CMD_ContextSetSurface_rec {
    uint32_t width;
    uint32_t height;
    RsNativeWindow sur;
};

#define RS_CMD_ID_ContextBindRootScript 92
struct __attribute__((packed)) RS_CMD_ContextBindRootScript_rec {
    RsScript sampler;
};

#define RS_CMD_ID_ContextPause 93
struct __attribute__((packed)) RS_CMD_ContextPause_rec {
};

#define RS_CMD_ID_ContextResume 94
struct __attribute__((packed)) RS_CMD_ContextResume_rec {
};

void rsi_ContextDestroy (Context *) __DEPRECATED_IN(31);
RsMessageToClientType rsi_ContextGetMessage (Context *, void * data, size_t data_length, size_t * receiveLen, size_t receiveLen_length, uint32_t * usrID, size_t usrID_length) __DEPRECATED_IN(31);
RsMessageToClientType rsi_ContextPeekMessage (Context *, size_t * receiveLen, size_t receiveLen_length, uint32_t * usrID, size_t usrID_length) __DEPRECATED_IN(31);
void rsi_ContextSendMessage (Context *, uint32_t id, const uint8_t * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_ContextInitToClient (Context *) __DEPRECATED_IN(31);
void rsi_ContextDeinitToClient (Context *) __DEPRECATED_IN(31);
void rsi_ContextSetCacheDir (Context *, const char * cacheDir, size_t cacheDir_length) __DEPRECATED_IN(31);
RsType rsi_TypeCreate (Context *, RsElement e, uint32_t dimX, uint32_t dimY, uint32_t dimZ, bool mipmaps, bool faces, uint32_t yuv) __DEPRECATED_IN(31);
RsType rsi_TypeCreate2 (Context *, const RsTypeCreateParams * dat, size_t dat_length) __DEPRECATED_IN(31);
RsAllocation rsi_AllocationCreateTyped (Context *, RsType vtype, RsAllocationMipmapControl mipmaps, uint32_t usages, uintptr_t ptr) __DEPRECATED_IN(31);
RsAllocation rsi_AllocationCreateFromBitmap (Context *, RsType vtype, RsAllocationMipmapControl mipmaps, const void * data, size_t data_length, uint32_t usages) __DEPRECATED_IN(31);
RsAllocation rsi_AllocationCubeCreateFromBitmap (Context *, RsType vtype, RsAllocationMipmapControl mipmaps, const void * data, size_t data_length, uint32_t usages) __DEPRECATED_IN(31);
void rsi_AllocationSetupBufferQueue (Context *, RsAllocation alloc, uint32_t numAlloc) __DEPRECATED_IN(31);
void rsi_AllocationShareBufferQueue (Context *, RsAllocation alloc1, RsAllocation alloc2) __DEPRECATED_IN(31);
RsNativeWindow rsi_AllocationGetSurface (Context *, RsAllocation alloc) __DEPRECATED_IN(31);
void rsi_AllocationSetSurface (Context *, RsAllocation alloc, RsNativeWindow sur) __DEPRECATED_IN(31);
RsAllocation rsi_AllocationAdapterCreate (Context *, RsType vtype, RsAllocation baseAlloc) __DEPRECATED_IN(31);
void rsi_AllocationAdapterOffset (Context *, RsAllocation alloc, const uint32_t * offsets, size_t offsets_length) __DEPRECATED_IN(31);
void rsi_ContextFinish (Context *) __DEPRECATED_IN(31);
void rsi_ContextDump (Context *, int32_t bits) __DEPRECATED_IN(31);
void rsi_ContextSetPriority (Context *, int32_t priority) __DEPRECATED_IN(31);
void rsi_ContextDestroyWorker (Context *) __DEPRECATED_IN(31);
void rsi_AssignName (Context *, RsObjectBase obj, const char * name, size_t name_length) __DEPRECATED_IN(31);
void rsi_ObjDestroy (Context *, RsAsyncVoidPtr objPtr) __DEPRECATED_IN(31);
RsElement rsi_ElementCreate (Context *, RsDataType mType, RsDataKind mKind, bool mNormalized, uint32_t mVectorSize) __DEPRECATED_IN(31);
RsElement rsi_ElementCreate2 (Context *, const RsElement * elements, size_t elements_length, const char ** names, size_t names_length_length, const size_t * names_length, const uint32_t * arraySize, size_t arraySize_length) __DEPRECATED_IN(31);
void rsi_AllocationCopyToBitmap (Context *, RsAllocation alloc, void * data, size_t data_length) __DEPRECATED_IN(31);
void * rsi_AllocationGetPointer (Context *, RsAllocation va, uint32_t lod, RsAllocationCubemapFace face, uint32_t z, uint32_t array, size_t * stride, size_t stride_length) __DEPRECATED_IN(31);
void rsi_Allocation1DData (Context *, RsAllocation va, uint32_t xoff, uint32_t lod, uint32_t count, const void * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_Allocation1DElementData (Context *, RsAllocation va, uint32_t x, uint32_t lod, const void * data, size_t data_length, size_t comp_offset) __DEPRECATED_IN(31);
void rsi_AllocationElementData (Context *, RsAllocation va, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, const void * data, size_t data_length, size_t comp_offset) __DEPRECATED_IN(31);
void rsi_Allocation2DData (Context *, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t lod, RsAllocationCubemapFace face, uint32_t w, uint32_t h, const void * data, size_t data_length, size_t stride) __DEPRECATED_IN(31);
void rsi_Allocation3DData (Context *, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, const void * data, size_t data_length, size_t stride) __DEPRECATED_IN(31);
void rsi_AllocationGenerateMipmaps (Context *, RsAllocation va) __DEPRECATED_IN(31);
void rsi_AllocationRead (Context *, RsAllocation va, void * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_Allocation1DRead (Context *, RsAllocation va, uint32_t xoff, uint32_t lod, uint32_t count, void * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_AllocationElementRead (Context *, RsAllocation va, uint32_t x, uint32_t y, uint32_t z, uint32_t lod, void * data, size_t data_length, size_t comp_offset) __DEPRECATED_IN(31);
void rsi_Allocation2DRead (Context *, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t lod, RsAllocationCubemapFace face, uint32_t w, uint32_t h, void * data, size_t data_length, size_t stride) __DEPRECATED_IN(31);
void rsi_Allocation3DRead (Context *, RsAllocation va, uint32_t xoff, uint32_t yoff, uint32_t zoff, uint32_t lod, uint32_t w, uint32_t h, uint32_t d, void * data, size_t data_length, size_t stride) __DEPRECATED_IN(31);
void rsi_AllocationSyncAll (Context *, RsAllocation va, RsAllocationUsageType src) __DEPRECATED_IN(31);
void rsi_AllocationResize1D (Context *, RsAllocation va, uint32_t dimX) __DEPRECATED_IN(31);
void rsi_AllocationCopy2DRange (Context *, RsAllocation dest, uint32_t destXoff, uint32_t destYoff, uint32_t destMip, uint32_t destFace, uint32_t width, uint32_t height, RsAllocation src, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcMip, uint32_t srcFace) __DEPRECATED_IN(31);
void rsi_AllocationCopy3DRange (Context *, RsAllocation dest, uint32_t destXoff, uint32_t destYoff, uint32_t destZoff, uint32_t destMip, uint32_t width, uint32_t height, uint32_t depth, RsAllocation src, uint32_t srcXoff, uint32_t srcYoff, uint32_t srcZoff, uint32_t srcMip) __DEPRECATED_IN(31);
RsClosure rsi_ClosureCreate (Context *, RsScriptKernelID kernelID, RsAllocation returnValue, RsScriptFieldID * fieldIDs, size_t fieldIDs_length, const int64_t * values, size_t values_length, const int * sizes, size_t sizes_length, RsClosure * depClosures, size_t depClosures_length, RsScriptFieldID * depFieldIDs, size_t depFieldIDs_length) __DEPRECATED_IN(31);
RsClosure rsi_InvokeClosureCreate (Context *, RsScriptInvokeID invokeID, const void * params, size_t params_length, const RsScriptFieldID * fieldIDs, size_t fieldIDs_length, const int64_t * values, size_t values_length, const int * sizes, size_t sizes_length) __DEPRECATED_IN(31);
void rsi_ClosureSetArg (Context *, RsClosure closureID, uint32_t index, uintptr_t value, int valueSize) __DEPRECATED_IN(31);
void rsi_ClosureSetGlobal (Context *, RsClosure closureID, RsScriptFieldID fieldID, int64_t value, int valueSize) __DEPRECATED_IN(31);
RsSampler rsi_SamplerCreate (Context *, RsSamplerValue magFilter, RsSamplerValue minFilter, RsSamplerValue wrapS, RsSamplerValue wrapT, RsSamplerValue wrapR, float mAniso) __DEPRECATED_IN(31);
void rsi_ScriptBindAllocation (Context *, RsScript vtm, RsAllocation va, uint32_t slot) __DEPRECATED_IN(31);
void rsi_ScriptSetTimeZone (Context *, RsScript s, const char * timeZone, size_t timeZone_length) __DEPRECATED_IN(31);
RsScriptInvokeID rsi_ScriptInvokeIDCreate (Context *, RsScript s, uint32_t slot) __DEPRECATED_IN(31);
void rsi_ScriptInvoke (Context *, RsScript s, uint32_t slot) __DEPRECATED_IN(31);
void rsi_ScriptInvokeV (Context *, RsScript s, uint32_t slot, const void * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_ScriptForEach (Context *, RsScript s, uint32_t slot, RsAllocation ain, RsAllocation aout, const void * usr, size_t usr_length, const RsScriptCall * sc, size_t sc_length) __DEPRECATED_IN(31);
void rsi_ScriptForEachMulti (Context *, RsScript s, uint32_t slot, RsAllocation * ains, size_t ains_length, RsAllocation aout, const void * usr, size_t usr_length, const RsScriptCall * sc, size_t sc_length) __DEPRECATED_IN(31);
void rsi_ScriptReduce (Context *, RsScript s, uint32_t slot, RsAllocation * ains, size_t ains_length, RsAllocation aout, const RsScriptCall * sc, size_t sc_length) __DEPRECATED_IN(31);
void rsi_ScriptSetVarI (Context *, RsScript s, uint32_t slot, int value) __DEPRECATED_IN(31);
void rsi_ScriptSetVarObj (Context *, RsScript s, uint32_t slot, RsObjectBase value) __DEPRECATED_IN(31);
void rsi_ScriptSetVarJ (Context *, RsScript s, uint32_t slot, int64_t value) __DEPRECATED_IN(31);
void rsi_ScriptSetVarF (Context *, RsScript s, uint32_t slot, float value) __DEPRECATED_IN(31);
void rsi_ScriptSetVarD (Context *, RsScript s, uint32_t slot, double value) __DEPRECATED_IN(31);
void rsi_ScriptSetVarV (Context *, RsScript s, uint32_t slot, const void * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_ScriptGetVarV (Context *, RsScript s, uint32_t slot, void * data, size_t data_length) __DEPRECATED_IN(31);
void rsi_ScriptSetVarVE (Context *, RsScript s, uint32_t slot, const void * data, size_t data_length, RsElement e, const uint32_t * dims, size_t dims_length) __DEPRECATED_IN(31);
RsScript rsi_ScriptCCreate (Context *, const char * resName, size_t resName_length, const char * cacheDir, size_t cacheDir_length, const char * text, size_t text_length) __DEPRECATED_IN(31);
RsScript rsi_ScriptIntrinsicCreate (Context *, uint32_t id, RsElement eid) __DEPRECATED_IN(31);
RsScriptKernelID rsi_ScriptKernelIDCreate (Context *, RsScript sid, int slot, int sig) __DEPRECATED_IN(31);
RsScriptFieldID rsi_ScriptFieldIDCreate (Context *, RsScript sid, int slot) __DEPRECATED_IN(31);
RsScriptGroup rsi_ScriptGroupCreate (Context *, RsScriptKernelID * kernels, size_t kernels_length, RsScriptKernelID * src, size_t src_length, RsScriptKernelID * dstK, size_t dstK_length, RsScriptFieldID * dstF, size_t dstF_length, const RsType * type, size_t type_length) __DEPRECATED_IN(31);
void rsi_ScriptGroupSetOutput (Context *, RsScriptGroup group, RsScriptKernelID kernel, RsAllocation alloc) __DEPRECATED_IN(31);
void rsi_ScriptGroupSetInput (Context *, RsScriptGroup group, RsScriptKernelID kernel, RsAllocation alloc) __DEPRECATED_IN(31);
void rsi_ScriptGroupExecute (Context *, RsScriptGroup group) __DEPRECATED_IN(31);
RsScriptGroup2 rsi_ScriptGroup2Create (Context *, const char * name, size_t name_length, const char * cacheDir, size_t cacheDir_length, RsClosure * closures, size_t closures_length) __DEPRECATED_IN(31);
void rsi_AllocationIoSend (Context *, RsAllocation alloc) __DEPRECATED_IN(31);
int64_t rsi_AllocationIoReceive (Context *, RsAllocation alloc) __DEPRECATED_IN(31);
RsProgramStore rsi_ProgramStoreCreate (Context *, bool colorMaskR, bool colorMaskG, bool colorMaskB, bool colorMaskA, bool depthMask, bool ditherEnable, RsBlendSrcFunc srcFunc, RsBlendDstFunc destFunc, RsDepthFunc depthFunc) __DEPRECATED_IN(31);
RsProgramRaster rsi_ProgramRasterCreate (Context *, bool pointSprite, RsCullMode cull) __DEPRECATED_IN(31);
void rsi_ProgramBindConstants (Context *, RsProgram vp, uint32_t slot, RsAllocation constants) __DEPRECATED_IN(31);
void rsi_ProgramBindTexture (Context *, RsProgramFragment pf, uint32_t slot, RsAllocation a) __DEPRECATED_IN(31);
void rsi_ProgramBindSampler (Context *, RsProgramFragment pf, uint32_t slot, RsSampler s) __DEPRECATED_IN(31);
RsProgramFragment rsi_ProgramFragmentCreate (Context *, const char * shaderText, size_t shaderText_length, const char ** textureNames, size_t textureNames_length_length, const size_t * textureNames_length, const uintptr_t * params, size_t params_length) __DEPRECATED_IN(31);
RsProgramVertex rsi_ProgramVertexCreate (Context *, const char * shaderText, size_t shaderText_length, const char ** textureNames, size_t textureNames_length_length, const size_t * textureNames_length, const uintptr_t * params, size_t params_length) __DEPRECATED_IN(31);
RsFont rsi_FontCreateFromFile (Context *, const char * name, size_t name_length, float fontSize, uint32_t dpi) __DEPRECATED_IN(31);
RsFont rsi_FontCreateFromMemory (Context *, const char * name, size_t name_length, float fontSize, uint32_t dpi, const void * data, size_t data_length) __DEPRECATED_IN(31);
RsMesh rsi_MeshCreate (Context *, RsAllocation * vtx, size_t vtx_length, RsAllocation * idx, size_t idx_length, uint32_t * primType, size_t primType_length) __DEPRECATED_IN(31);
void rsi_ContextBindProgramStore (Context *, RsProgramStore pgm) __DEPRECATED_IN(31);
void rsi_ContextBindProgramFragment (Context *, RsProgramFragment pgm) __DEPRECATED_IN(31);
void rsi_ContextBindProgramVertex (Context *, RsProgramVertex pgm) __DEPRECATED_IN(31);
void rsi_ContextBindProgramRaster (Context *, RsProgramRaster pgm) __DEPRECATED_IN(31);
void rsi_ContextBindFont (Context *, RsFont pgm) __DEPRECATED_IN(31);
void rsi_ContextSetSurface (Context *, uint32_t width, uint32_t height, RsNativeWindow sur) __DEPRECATED_IN(31);
void rsi_ContextBindRootScript (Context *, RsScript sampler) __DEPRECATED_IN(31);
void rsi_ContextPause (Context *) __DEPRECATED_IN(31);
void rsi_ContextResume (Context *) __DEPRECATED_IN(31);


void rsp_ContextSendMessage (Context *, const void *);
void rsp_AllocationSetupBufferQueue (Context *, const void *);
void rsp_AllocationShareBufferQueue (Context *, const void *);
void rsp_AllocationGetSurface (Context *, const void *);
void rsp_AllocationSetSurface (Context *, const void *);
void rsp_AllocationAdapterOffset (Context *, const void *);
void rsp_ContextFinish (Context *, const void *);
void rsp_ContextDump (Context *, const void *);
void rsp_ContextSetPriority (Context *, const void *);
void rsp_ContextDestroyWorker (Context *, const void *);
void rsp_AssignName (Context *, const void *);
void rsp_ObjDestroy (Context *, const void *);
void rsp_AllocationCopyToBitmap (Context *, const void *);
void rsp_AllocationGetPointer (Context *, const void *);
void rsp_Allocation1DData (Context *, const void *);
void rsp_Allocation1DElementData (Context *, const void *);
void rsp_AllocationElementData (Context *, const void *);
void rsp_Allocation2DData (Context *, const void *);
void rsp_Allocation3DData (Context *, const void *);
void rsp_AllocationGenerateMipmaps (Context *, const void *);
void rsp_AllocationRead (Context *, const void *);
void rsp_Allocation1DRead (Context *, const void *);
void rsp_AllocationElementRead (Context *, const void *);
void rsp_Allocation2DRead (Context *, const void *);
void rsp_Allocation3DRead (Context *, const void *);
void rsp_AllocationSyncAll (Context *, const void *);
void rsp_AllocationResize1D (Context *, const void *);
void rsp_AllocationCopy2DRange (Context *, const void *);
void rsp_AllocationCopy3DRange (Context *, const void *);
void rsp_ClosureSetArg (Context *, const void *);
void rsp_ClosureSetGlobal (Context *, const void *);
void rsp_ScriptBindAllocation (Context *, const void *);
void rsp_ScriptSetTimeZone (Context *, const void *);
void rsp_ScriptInvokeIDCreate (Context *, const void *);
void rsp_ScriptInvoke (Context *, const void *);
void rsp_ScriptInvokeV (Context *, const void *);
void rsp_ScriptForEach (Context *, const void *);
void rsp_ScriptForEachMulti (Context *, const void *);
void rsp_ScriptReduce (Context *, const void *);
void rsp_ScriptSetVarI (Context *, const void *);
void rsp_ScriptSetVarObj (Context *, const void *);
void rsp_ScriptSetVarJ (Context *, const void *);
void rsp_ScriptSetVarF (Context *, const void *);
void rsp_ScriptSetVarD (Context *, const void *);
void rsp_ScriptSetVarV (Context *, const void *);
void rsp_ScriptGetVarV (Context *, const void *);
void rsp_ScriptSetVarVE (Context *, const void *);
void rsp_ScriptCCreate (Context *, const void *);
void rsp_ScriptIntrinsicCreate (Context *, const void *);
void rsp_ScriptGroupSetOutput (Context *, const void *);
void rsp_ScriptGroupSetInput (Context *, const void *);
void rsp_ScriptGroupExecute (Context *, const void *);
void rsp_AllocationIoSend (Context *, const void *);
void rsp_AllocationIoReceive (Context *, const void *);
void rsp_ProgramBindConstants (Context *, const void *);
void rsp_ProgramBindTexture (Context *, const void *);
void rsp_ProgramBindSampler (Context *, const void *);
void rsp_FontCreateFromFile (Context *, const void *);
void rsp_FontCreateFromMemory (Context *, const void *);
void rsp_MeshCreate (Context *, const void *);
void rsp_ContextBindProgramStore (Context *, const void *);
void rsp_ContextBindProgramFragment (Context *, const void *);
void rsp_ContextBindProgramVertex (Context *, const void *);
void rsp_ContextBindProgramRaster (Context *, const void *);
void rsp_ContextBindFont (Context *, const void *);
void rsp_ContextSetSurface (Context *, const void *);
void rsp_ContextBindRootScript (Context *, const void *);
void rsp_ContextPause (Context *, const void *);
void rsp_ContextResume (Context *, const void *);
typedef void (*RsPlaybackLocalFunc)(Context *, const void *, size_t sizeBytes);
extern RsPlaybackLocalFunc gPlaybackFuncs[95];
}
}
