/*
 * Copyright (C) 2018 The Android Open Source Project
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

//#define LOG_NDEBUG 0
#define LOG_TAG "C2BqBuffer"
#include <utils/Log.h>

#include <ui/BufferQueueDefs.h>
#include <ui/GraphicBuffer.h>
#include <ui/Fence.h>

#include <types.h>

#include <hidl/HidlSupport.h>

#include <C2AllocatorGralloc.h>
#include <C2BqBufferPriv.h>
#include <C2BlockInternal.h>
#include <C2FenceFactory.h>
#include <C2SurfaceSyncObj.h>

#include <list>
#include <map>
#include <mutex>

using ::android::BufferQueueDefs::NUM_BUFFER_SLOTS;
using ::android::C2AllocatorGralloc;
using ::android::C2AndroidMemoryUsage;
using ::android::Fence;
using ::android::GraphicBuffer;
using ::android::sp;
using ::android::status_t;
using ::android::wp;
using ::android::hardware::hidl_handle;
using ::android::hardware::Return;

using HBuffer = ::android::hardware::graphics::common::V1_2::HardwareBuffer;
using HStatus = ::android::hardware::graphics::bufferqueue::V2_0::Status;
using ::android::hardware::graphics::bufferqueue::V2_0::utils::b2h;
using ::android::hardware::graphics::bufferqueue::V2_0::utils::h2b;
using ::android::hardware::graphics::bufferqueue::V2_0::utils::HFenceWrapper;

using HGraphicBufferProducer = ::android::hardware::graphics::bufferqueue::V2_0
        ::IGraphicBufferProducer;

bool _C2BlockFactory::GetBufferQueueData(
        const std::shared_ptr<const _C2BlockPoolData>& data,
        uint32_t* generation, uint64_t* bqId, int32_t* bqSlot) {
    if (data && data->getType() == _C2BlockPoolData::TYPE_BUFFERQUEUE) {
        const std::shared_ptr<const C2BufferQueueBlockPoolData> poolData =
                std::static_pointer_cast<const C2BufferQueueBlockPoolData>(data);
        poolData->getBufferQueueData(generation, bqId, bqSlot);
        return true;
    }
    return false;
}

bool _C2BlockFactory::HoldBlockFromBufferQueue(
        const std::shared_ptr<_C2BlockPoolData>& data,
        const std::shared_ptr<int>& owner,
        const sp<HGraphicBufferProducer>& igbp,
        std::shared_ptr<C2SurfaceSyncMemory> syncMem) {
    const std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
            std::static_pointer_cast<C2BufferQueueBlockPoolData>(data);
    return poolData->holdBlockFromBufferQueue(owner, igbp, syncMem);
}

bool _C2BlockFactory::BeginTransferBlockToClient(
        const std::shared_ptr<_C2BlockPoolData>& data) {
    const std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
            std::static_pointer_cast<C2BufferQueueBlockPoolData>(data);
    return poolData->beginTransferBlockToClient();
}

bool _C2BlockFactory::EndTransferBlockToClient(
        const std::shared_ptr<_C2BlockPoolData>& data,
        bool transfer) {
    const std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
            std::static_pointer_cast<C2BufferQueueBlockPoolData>(data);
    return poolData->endTransferBlockToClient(transfer);
}

bool _C2BlockFactory::BeginAttachBlockToBufferQueue(
        const std::shared_ptr<_C2BlockPoolData>& data) {
    const std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
            std::static_pointer_cast<C2BufferQueueBlockPoolData>(data);
    return poolData->beginAttachBlockToBufferQueue();
}

// if display was tried during attach, buffer should be retired ASAP.
bool _C2BlockFactory::EndAttachBlockToBufferQueue(
        const std::shared_ptr<_C2BlockPoolData>& data,
        const std::shared_ptr<int>& owner,
        const sp<HGraphicBufferProducer>& igbp,
        std::shared_ptr<C2SurfaceSyncMemory> syncMem,
        uint32_t generation,
        uint64_t bqId,
        int32_t bqSlot) {
    const std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
            std::static_pointer_cast<C2BufferQueueBlockPoolData>(data);
    return poolData->endAttachBlockToBufferQueue(owner, igbp, syncMem, generation, bqId, bqSlot);
}

bool _C2BlockFactory::DisplayBlockToBufferQueue(
        const std::shared_ptr<_C2BlockPoolData>& data) {
    const std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
            std::static_pointer_cast<C2BufferQueueBlockPoolData>(data);
    return poolData->displayBlockToBufferQueue();
}

std::shared_ptr<C2GraphicBlock> _C2BlockFactory::CreateGraphicBlock(
        const C2Handle *handle) {
    // TODO: get proper allocator? and mutex?
    static std::unique_ptr<C2AllocatorGralloc> sAllocator = std::make_unique<C2AllocatorGralloc>(0);

    std::shared_ptr<C2GraphicAllocation> alloc;
    if (C2AllocatorGralloc::CheckHandle(handle)) {
        uint32_t width;
        uint32_t height;
        uint32_t format;
        uint64_t usage;
        uint32_t stride;
        uint32_t generation;
        uint64_t bqId;
        uint32_t bqSlot;
        android::_UnwrapNativeCodec2GrallocMetadata(
                handle, &width, &height, &format, &usage, &stride, &generation, &bqId, &bqSlot);
        c2_status_t err = sAllocator->priorGraphicAllocation(handle, &alloc);
        if (err == C2_OK) {
            std::shared_ptr<C2GraphicBlock> block;
            if (bqId || bqSlot) {
                // BQBBP
                std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
                        std::make_shared<C2BufferQueueBlockPoolData>(generation,
                                                                     bqId,
                                                                     (int32_t)bqSlot,
                                                                     nullptr,
                                                                     nullptr);
                block = _C2BlockFactory::CreateGraphicBlock(alloc, poolData);
            } else {
                block = _C2BlockFactory::CreateGraphicBlock(alloc);
            }
            return block;
        }
    }
    return nullptr;
}

namespace {

int64_t getTimestampNow() {
    int64_t stamp;
    struct timespec ts;
    // TODO: CLOCK_MONOTONIC_COARSE?
    clock_gettime(CLOCK_MONOTONIC, &ts);
    stamp = ts.tv_nsec / 1000;
    stamp += (ts.tv_sec * 1000000LL);
    return stamp;
}

bool getGenerationNumberAndUsage(const sp<HGraphicBufferProducer> &producer,
                                 uint32_t *generation, uint64_t *usage) {
    status_t status{};
    int slot{};
    bool bufferNeedsReallocation{};
    sp<Fence> fence = new Fence();

    using Input = HGraphicBufferProducer::DequeueBufferInput;
    using Output = HGraphicBufferProducer::DequeueBufferOutput;
    Return<void> transResult = producer->dequeueBuffer(
            Input{640, 480, HAL_PIXEL_FORMAT_YCBCR_420_888, 0},
            [&status, &slot, &bufferNeedsReallocation, &fence]
            (HStatus hStatus, int32_t hSlot, Output const& hOutput) {
                slot = static_cast<int>(hSlot);
                if (!h2b(hStatus, &status) || !h2b(hOutput.fence, &fence)) {
                    status = ::android::BAD_VALUE;
                } else {
                    bufferNeedsReallocation =
                            hOutput.bufferNeedsReallocation;
                }
            });
    if (!transResult.isOk() || status != android::OK) {
        return false;
    }
    HFenceWrapper hFenceWrapper{};
    if (!b2h(fence, &hFenceWrapper)) {
        (void)producer->detachBuffer(static_cast<int32_t>(slot)).isOk();
        ALOGE("Invalid fence received from dequeueBuffer.");
        return false;
    }
    sp<GraphicBuffer> slotBuffer = new GraphicBuffer();
    // N.B. This assumes requestBuffer# returns an existing allocation
    // instead of a new allocation.
    transResult = producer->requestBuffer(
            slot,
            [&status, &slotBuffer, &generation, &usage](
                    HStatus hStatus,
                    HBuffer const& hBuffer,
                    uint32_t generationNumber){
                if (h2b(hStatus, &status) &&
                        h2b(hBuffer, &slotBuffer) &&
                        slotBuffer) {
                    *generation = generationNumber;
                    *usage = slotBuffer->getUsage();
                    slotBuffer->setGenerationNumber(generationNumber);
                } else {
                    status = android::BAD_VALUE;
                }
            });
    if (!transResult.isOk()) {
        return false;
    } else if (status != android::NO_ERROR) {
        (void)producer->detachBuffer(static_cast<int32_t>(slot)).isOk();
        return false;
    }
    (void)producer->detachBuffer(static_cast<int32_t>(slot)).isOk();
    return true;
}

};

class C2BufferQueueBlockPool::Impl
        : public std::enable_shared_from_this<C2BufferQueueBlockPool::Impl> {
private:
    c2_status_t dequeueBuffer(
            uint32_t width,
            uint32_t height,
            uint32_t format,
            C2AndroidMemoryUsage androidUsage,
            int *slot, bool *needsRealloc, sp<Fence> *fence) {
        status_t status{};
        using Input = HGraphicBufferProducer::DequeueBufferInput;
        using Output = HGraphicBufferProducer::DequeueBufferOutput;
        Return<void> transResult = mProducer->dequeueBuffer(
                Input{
                    width,
                    height,
                    format,
                    androidUsage.asGrallocUsage()},
                [&status, slot, needsRealloc,
                 fence](HStatus hStatus,
                         int32_t hSlot,
                         Output const& hOutput) {
                    *slot = static_cast<int>(hSlot);
                    if (!h2b(hStatus, &status) ||
                            !h2b(hOutput.fence, fence)) {
                        status = ::android::BAD_VALUE;
                    } else {
                        *needsRealloc =
                                hOutput.bufferNeedsReallocation;
                    }
                });
        if (!transResult.isOk() || status != android::OK) {
            if (transResult.isOk()) {
                ++mDqFailure;
                if (status == android::INVALID_OPERATION ||
                    status == android::TIMED_OUT ||
                    status == android::WOULD_BLOCK) {
                    // Dequeue buffer is blocked temporarily. Retrying is
                    // required.
                    return C2_BLOCKING;
                }
            }
            ALOGD("cannot dequeue buffer %d", status);
            return C2_BAD_VALUE;
        }
        return C2_OK;
    }

    c2_status_t fetchFromIgbp_l(
            uint32_t width,
            uint32_t height,
            uint32_t format,
            C2MemoryUsage usage,
            std::shared_ptr<C2GraphicBlock> *block /* nonnull */,
            C2Fence *c2Fence) {
        // We have an IGBP now.
        C2AndroidMemoryUsage androidUsage = usage;
        status_t status{};
        int slot{};
        bool bufferNeedsReallocation{};
        sp<Fence> fence = new Fence();
        ALOGV("tries to dequeue buffer");

        C2SyncVariables *syncVar = mSyncMem ? mSyncMem->mem(): nullptr;
        { // Call dequeueBuffer().
            c2_status_t c2Status;
            if (syncVar) {
                uint32_t waitId;
                syncVar->lock();
                if (!syncVar->isDequeueableLocked(&waitId)) {
                    syncVar->unlock();
                    if (c2Fence) {
                        *c2Fence = _C2FenceFactory::CreateSurfaceFence(mSyncMem, waitId);
                    }
                    return C2_BLOCKING;
                }
                if (syncVar->getSyncStatusLocked() != C2SyncVariables::STATUS_ACTIVE) {
                    waitId = syncVar->getWaitIdLocked();
                    syncVar->unlock();
                    if (c2Fence) {
                        *c2Fence = _C2FenceFactory::CreateSurfaceFence(mSyncMem, waitId);
                    }
                    return C2_BLOCKING;
                }
                syncVar->notifyDequeuedLocked();
                syncVar->unlock();
                c2Status = dequeueBuffer(width, height, format, androidUsage,
                              &slot, &bufferNeedsReallocation, &fence);
                if (c2Status != C2_OK) {
                    syncVar->lock();
                    syncVar->notifyQueuedLocked();
                    syncVar->unlock();
                }
            } else {
                c2Status = dequeueBuffer(width, height, format, usage,
                              &slot, &bufferNeedsReallocation, &fence);
            }
            if (c2Status != C2_OK) {
                return c2Status;
            }
            mDqFailure = 0;
            mLastDqTs = getTimestampNow();
        }
        HFenceWrapper hFenceWrapper{};
        if (!b2h(fence, &hFenceWrapper)) {
            ALOGE("Invalid fence received from dequeueBuffer.");
            return C2_BAD_VALUE;
        }
        ALOGV("dequeued a buffer successfully");
        bool dequeueable = false;
        uint32_t waitId;
        if (fence) {
            static constexpr int kFenceWaitTimeMs = 10;

            status_t status = fence->wait(kFenceWaitTimeMs);
            if (status == -ETIME) {
                // fence is not signalled yet.
                if (syncVar) {
                    syncVar->lock();
                    (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                    dequeueable = syncVar->notifyQueuedLocked(&waitId);
                    syncVar->unlock();
                    if (c2Fence) {
                        *c2Fence = dequeueable ? C2Fence() :
                                _C2FenceFactory::CreateSurfaceFence(mSyncMem, waitId);
                    }
                } else {
                    (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                }
                return C2_BLOCKING;
            }
            if (status != android::NO_ERROR) {
                ALOGD("buffer fence wait error %d", status);
                if (syncVar) {
                    syncVar->lock();
                    (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                    syncVar->notifyQueuedLocked();
                    syncVar->unlock();
                    if (c2Fence) {
                        *c2Fence = C2Fence();
                    }
                } else {
                    (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                }
                return C2_BAD_VALUE;
            } else if (mRenderCallback) {
                nsecs_t signalTime = fence->getSignalTime();
                if (signalTime >= 0 && signalTime < INT64_MAX) {
                    mRenderCallback(mProducerId, slot, signalTime);
                } else {
                    ALOGV("got fence signal time of %lld", (long long)signalTime);
                }
            }
        }

        sp<GraphicBuffer> &slotBuffer = mBuffers[slot];
        uint32_t outGeneration;
        if (bufferNeedsReallocation || !slotBuffer) {
            if (!slotBuffer) {
                slotBuffer = new GraphicBuffer();
            }
            // N.B. This assumes requestBuffer# returns an existing allocation
            // instead of a new allocation.
            Return<void> transResult = mProducer->requestBuffer(
                    slot,
                    [&status, &slotBuffer, &outGeneration](
                            HStatus hStatus,
                            HBuffer const& hBuffer,
                            uint32_t generationNumber){
                        if (h2b(hStatus, &status) &&
                                h2b(hBuffer, &slotBuffer) &&
                                slotBuffer) {
                            slotBuffer->setGenerationNumber(generationNumber);
                            outGeneration = generationNumber;
                        } else {
                            status = android::BAD_VALUE;
                        }
                    });
            if (!transResult.isOk()) {
                slotBuffer.clear();
                return C2_BAD_VALUE;
            } else if (status != android::NO_ERROR) {
                slotBuffer.clear();
                if (syncVar) {
                    syncVar->lock();
                    (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                    syncVar->notifyQueuedLocked();
                    syncVar->unlock();
                    if (c2Fence) {
                        *c2Fence = C2Fence();
                    }
                } else {
                    (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                }
                return C2_BAD_VALUE;
            }
            if (mGeneration == 0) {
                // getting generation # lazily due to dequeue failure.
                mGeneration = outGeneration;
            }
        }
        if (slotBuffer) {
            ALOGV("buffer wraps %llu %d", (unsigned long long)mProducerId, slot);
            C2Handle *c2Handle = android::WrapNativeCodec2GrallocHandle(
                    slotBuffer->handle,
                    slotBuffer->width,
                    slotBuffer->height,
                    slotBuffer->format,
                    slotBuffer->usage,
                    slotBuffer->stride,
                    slotBuffer->getGenerationNumber(),
                    mProducerId, slot);
            if (c2Handle) {
                std::shared_ptr<C2GraphicAllocation> alloc;
                c2_status_t err = mAllocator->priorGraphicAllocation(c2Handle, &alloc);
                if (err != C2_OK) {
                    native_handle_close(c2Handle);
                    native_handle_delete(c2Handle);
                    return err;
                }
                std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
                        std::make_shared<C2BufferQueueBlockPoolData>(
                                slotBuffer->getGenerationNumber(),
                                mProducerId, slot,
                                mProducer, mSyncMem, 0);
                mPoolDatas[slot] = poolData;
                *block = _C2BlockFactory::CreateGraphicBlock(alloc, poolData);
                return C2_OK;
            }
            // Block was not created. call requestBuffer# again next time.
            slotBuffer.clear();
            if (syncVar) {
                syncVar->lock();
                (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
                syncVar->notifyQueuedLocked();
                syncVar->unlock();
                if (c2Fence) {
                    *c2Fence = C2Fence();
                }
            } else {
                (void)mProducer->cancelBuffer(slot, hFenceWrapper.getHandle()).isOk();
            }
            return C2_BAD_VALUE;
        }
        if (c2Fence) {
            *c2Fence = C2Fence();
        }
        return C2_BAD_VALUE;
    }

public:
    Impl(const std::shared_ptr<C2Allocator> &allocator)
        : mInit(C2_OK), mProducerId(0), mGeneration(0),
          mDqFailure(0), mLastDqTs(0), mLastDqLogTs(0),
          mAllocator(allocator) {
    }

    ~Impl() {
        bool noInit = false;
        for (int i = 0; i < NUM_BUFFER_SLOTS; ++i) {
            if (!noInit && mProducer) {
                Return<HStatus> transResult =
                        mProducer->detachBuffer(static_cast<int32_t>(i));
                noInit = !transResult.isOk() ||
                         static_cast<HStatus>(transResult) == HStatus::NO_INIT;
            }
            mBuffers[i].clear();
        }
    }

    c2_status_t fetchGraphicBlock(
            uint32_t width,
            uint32_t height,
            uint32_t format,
            C2MemoryUsage usage,
            std::shared_ptr<C2GraphicBlock> *block /* nonnull */,
            C2Fence *fence) {
        block->reset();
        if (mInit != C2_OK) {
            return mInit;
        }

        static int kMaxIgbpRetryDelayUs = 10000;

        std::unique_lock<std::mutex> lock(mMutex);
        if (mLastDqLogTs == 0) {
            mLastDqLogTs = getTimestampNow();
        } else {
            int64_t now = getTimestampNow();
            if (now >= mLastDqLogTs + 5000000) {
                if (now >= mLastDqTs + 1000000 || mDqFailure > 5) {
                    ALOGW("last successful dequeue was %lld us ago, "
                          "%zu consecutive failures",
                          (long long)(now - mLastDqTs), mDqFailure);
                }
                mLastDqLogTs = now;
            }
        }
        if (mProducerId == 0) {
            std::shared_ptr<C2GraphicAllocation> alloc;
            c2_status_t err = mAllocator->newGraphicAllocation(
                    width, height, format, usage, &alloc);
            if (err != C2_OK) {
                return err;
            }
            std::shared_ptr<C2BufferQueueBlockPoolData> poolData =
                    std::make_shared<C2BufferQueueBlockPoolData>(
                            0, (uint64_t)0, ~0, nullptr, nullptr, 0);
            *block = _C2BlockFactory::CreateGraphicBlock(alloc, poolData);
            ALOGV("allocated a buffer successfully");

            return C2_OK;
        }
        c2_status_t status = fetchFromIgbp_l(width, height, format, usage, block, fence);
        if (status == C2_BLOCKING) {
            lock.unlock();
            if (!fence) {
                // in order not to drain cpu from component's spinning
                ::usleep(kMaxIgbpRetryDelayUs);
            }
        }
        return status;
    }

    void setRenderCallback(const OnRenderCallback &renderCallback) {
        std::scoped_lock<std::mutex> lock(mMutex);
        mRenderCallback = renderCallback;
    }

    /* This is for Old HAL request for compatibility */
    void configureProducer(const sp<HGraphicBufferProducer> &producer) {
        uint64_t producerId = 0;
        uint32_t generation = 0;
        uint64_t usage = 0;
        bool bqInformation = false;
        if (producer) {
            Return<uint64_t> transResult = producer->getUniqueId();
            if (!transResult.isOk()) {
                ALOGD("configureProducer -- failed to connect to the producer");
                return;
            }
            producerId = static_cast<uint64_t>(transResult);
            bqInformation = getGenerationNumberAndUsage(producer, &generation, &usage);
            if (!bqInformation) {
                ALOGW("get generationNumber failed %llu",
                      (unsigned long long)producerId);
            }
        }
        configureProducer(producer, nullptr, producerId, generation, usage, bqInformation);
    }

    void configureProducer(const sp<HGraphicBufferProducer> &producer,
                           native_handle_t *syncHandle,
                           uint64_t producerId,
                           uint32_t generation,
                           uint64_t usage,
                           bool bqInformation) {
        std::shared_ptr<C2SurfaceSyncMemory> c2SyncMem;
        if (syncHandle) {
            if (!producer) {
                native_handle_close(syncHandle);
                native_handle_delete(syncHandle);
            } else {
                c2SyncMem = C2SurfaceSyncMemory::Import(syncHandle);
            }
        }
        int migrated = 0;
        std::shared_ptr<C2SurfaceSyncMemory> oldMem;
        // poolDatas dtor should not be called during lock is held.
        std::shared_ptr<C2BufferQueueBlockPoolData>
                poolDatas[NUM_BUFFER_SLOTS];
        {
            sp<GraphicBuffer> buffers[NUM_BUFFER_SLOTS];
            std::scoped_lock<std::mutex> lock(mMutex);
            bool noInit = false;
            for (int i = 0; i < NUM_BUFFER_SLOTS; ++i) {
                if (!noInit && mProducer) {
                    Return<HStatus> transResult =
                            mProducer->detachBuffer(static_cast<int32_t>(i));
                    noInit = !transResult.isOk() ||
                             static_cast<HStatus>(transResult) == HStatus::NO_INIT;
                }
            }
            int32_t oldGeneration = mGeneration;
            if (producer) {
                mProducer = producer;
                mProducerId = producerId;
                mGeneration = bqInformation ? generation : 0;
            } else {
                mProducer = nullptr;
                mProducerId = 0;
                mGeneration = 0;
                ALOGW("invalid producer producer(%d), generation(%d)",
                      (bool)producer, bqInformation);
            }
            oldMem = mSyncMem; // preven destruction while locked.
            mSyncMem = c2SyncMem;
            C2SyncVariables *syncVar = mSyncMem ? mSyncMem->mem() : nullptr;
            if (syncVar) {
                syncVar->lock();
                syncVar->setSyncStatusLocked(C2SyncVariables::STATUS_ACTIVE);
                syncVar->unlock();
            }
            if (mProducer && bqInformation) { // migrate buffers
                for (int i = 0; i < NUM_BUFFER_SLOTS; ++i) {
                    std::shared_ptr<C2BufferQueueBlockPoolData> data =
                            mPoolDatas[i].lock();
                    if (data) {
                        int slot = data->migrate(
                                mProducer, generation, usage,
                                producerId, mBuffers[i], oldGeneration, mSyncMem);
                        if (slot >= 0) {
                            buffers[slot] = mBuffers[i];
                            poolDatas[slot] = data;
                            ++migrated;
                        }
                    }
                }
            }
            for (int i = 0; i < NUM_BUFFER_SLOTS; ++i) {
                mBuffers[i] = buffers[i];
                mPoolDatas[i] = poolDatas[i];
            }
        }
        if (producer && bqInformation) {
            ALOGD("local generation change %u , "
                  "bqId: %llu migrated buffers # %d",
                  generation, (unsigned long long)producerId, migrated);
        }
    }

private:
    friend struct C2BufferQueueBlockPoolData;

    c2_status_t mInit;
    uint64_t mProducerId;
    uint32_t mGeneration;
    OnRenderCallback mRenderCallback;

    size_t mDqFailure;
    int64_t mLastDqTs;
    int64_t mLastDqLogTs;

    const std::shared_ptr<C2Allocator> mAllocator;

    std::mutex mMutex;
    sp<HGraphicBufferProducer> mProducer;
    sp<HGraphicBufferProducer> mSavedProducer;

    sp<GraphicBuffer> mBuffers[NUM_BUFFER_SLOTS];
    std::weak_ptr<C2BufferQueueBlockPoolData> mPoolDatas[NUM_BUFFER_SLOTS];

    std::shared_ptr<C2SurfaceSyncMemory> mSyncMem;
};

C2BufferQueueBlockPoolData::C2BufferQueueBlockPoolData(
        uint32_t generation, uint64_t bqId, int32_t bqSlot,
        const std::shared_ptr<int>& owner,
        const sp<HGraphicBufferProducer>& producer) :
        mLocal(false), mHeld(producer && bqId != 0),
        mGeneration(generation), mBqId(bqId), mBqSlot(bqSlot),
        mCurrentGeneration(generation), mCurrentBqId(bqId),
        mTransfer(false), mAttach(false), mDisplay(false),
        mOwner(owner), mIgbp(producer) {
}

C2BufferQueueBlockPoolData::C2BufferQueueBlockPoolData(
        uint32_t generation, uint64_t bqId, int32_t bqSlot,
        const android::sp<HGraphicBufferProducer>& producer,
        std::shared_ptr<C2SurfaceSyncMemory> syncMem, int noUse) :
        mLocal(true), mHeld(true),
        mGeneration(generation), mBqId(bqId), mBqSlot(bqSlot),
        mCurrentGeneration(generation), mCurrentBqId(bqId),
        mTransfer(false), mAttach(false), mDisplay(false),
        mIgbp(producer), mSyncMem(syncMem) {
            (void)noUse;
}

C2BufferQueueBlockPoolData::~C2BufferQueueBlockPoolData() {
    if (!mHeld || mBqId == 0 || !mIgbp) {
        return;
    }

    if (mLocal) {
        if (mGeneration == mCurrentGeneration && mBqId == mCurrentBqId) {
            C2SyncVariables *syncVar = mSyncMem ? mSyncMem->mem() : nullptr;
            if (syncVar) {
                syncVar->lock();
                if (syncVar->getSyncStatusLocked() == C2SyncVariables::STATUS_ACTIVE) {
                    mIgbp->cancelBuffer(mBqSlot, hidl_handle{}).isOk();
                    syncVar->notifyQueuedLocked();
                }
                syncVar->unlock();
            } else {
                mIgbp->cancelBuffer(mBqSlot, hidl_handle{}).isOk();
            }
        }
    } else if (!mOwner.expired()) {
        C2SyncVariables *syncVar = mSyncMem ? mSyncMem->mem() : nullptr;
        if (syncVar) {
            syncVar->lock();
            if (syncVar->getSyncStatusLocked() != C2SyncVariables::STATUS_SWITCHING) {
                mIgbp->cancelBuffer(mBqSlot, hidl_handle{}).isOk();
                syncVar->notifyQueuedLocked();
            }
            syncVar->unlock();
        } else {
            mIgbp->cancelBuffer(mBqSlot, hidl_handle{}).isOk();
        }
    }
}

C2BufferQueueBlockPoolData::type_t C2BufferQueueBlockPoolData::getType() const {
    return TYPE_BUFFERQUEUE;
}

int C2BufferQueueBlockPoolData::migrate(
        const sp<HGraphicBufferProducer>& producer,
        uint32_t toGeneration, uint64_t toUsage, uint64_t toBqId,
        sp<GraphicBuffer>& graphicBuffer, uint32_t oldGeneration,
        std::shared_ptr<C2SurfaceSyncMemory> syncMem) {
    std::scoped_lock<std::mutex> l(mLock);

    mCurrentBqId = toBqId;
    mCurrentGeneration = toGeneration;

    if (!mHeld || mBqId == 0) {
        ALOGV("buffer is not owned");
        return -1;
    }
    if (!mLocal) {
        ALOGV("pool is not local");
        return -1;
    }
    if (mBqSlot < 0 || mBqSlot >= NUM_BUFFER_SLOTS) {
        ALOGV("slot is not in effect");
        return -1;
    }
    if (!graphicBuffer) {
        ALOGV("buffer is null");
        return -1;
    }
    if (toGeneration == mGeneration && mBqId == toBqId) {
        ALOGV("cannot migrate to same bufferqueue");
        return -1;
    }
    if (oldGeneration != mGeneration) {
        ALOGV("cannot migrate stale buffer");
        return -1;
    }
    if (mTransfer) {
        // either transferred or detached.
        ALOGV("buffer is in transfer");
        return -1;
    }

    if (toUsage != graphicBuffer->getUsage()) {
        sp<GraphicBuffer> newBuffer = new GraphicBuffer(
            graphicBuffer->handle, GraphicBuffer::CLONE_HANDLE,
            graphicBuffer->width, graphicBuffer->height, graphicBuffer->format,
            graphicBuffer->layerCount, toUsage | graphicBuffer->getUsage(), graphicBuffer->stride);
        if (newBuffer->initCheck() == android::NO_ERROR) {
            graphicBuffer = std::move(newBuffer);
        } else {
            ALOGW("%s() failed to update usage, original usage=%" PRIx64 ", toUsage=%" PRIx64,
                  __func__, graphicBuffer->getUsage(), toUsage);
        }
    }
    graphicBuffer->setGenerationNumber(toGeneration);

    HBuffer hBuffer{};
    uint32_t hGenerationNumber{};
    if (!b2h(graphicBuffer, &hBuffer, &hGenerationNumber)) {
        ALOGD("I to O conversion failed");
        return -1;
    }

    bool converted{};
    status_t bStatus{};
    int slot;
    int *outSlot = &slot;
    Return<void> transResult =
            producer->attachBuffer(hBuffer, hGenerationNumber,
                    [&converted, &bStatus, outSlot](
                            HStatus hStatus, int32_t hSlot, bool releaseAll) {
                        converted = h2b(hStatus, &bStatus);
                        *outSlot = static_cast<int>(hSlot);
                        if (converted && releaseAll && bStatus == android::OK) {
                            bStatus = android::INVALID_OPERATION;
                        }
                    });
    if (!transResult.isOk() || !converted || bStatus != android::OK) {
        ALOGD("attach failed %d", static_cast<int>(bStatus));
        return -1;
    }
    ALOGV("local migration from gen %u : %u slot %d : %d",
          mGeneration, toGeneration, mBqSlot, slot);
    mIgbp = producer;
    mGeneration = toGeneration;
    mBqId = toBqId;
    mBqSlot = slot;
    mSyncMem = syncMem;

    C2SyncVariables *syncVar = syncMem ? syncMem->mem() : nullptr;
    if (syncVar) {
        syncVar->lock();
        syncVar->notifyDequeuedLocked();
        syncVar->unlock();
    }
    return slot;
}

void C2BufferQueueBlockPoolData::getBufferQueueData(
        uint32_t* generation, uint64_t* bqId, int32_t* bqSlot) const {
    if (generation) {
        std::scoped_lock<std::mutex> lock(mLock);
        *generation = mGeneration;
        if (bqId) {
            *bqId = mBqId;
        }
        if (bqSlot) {
            *bqSlot = mBqSlot;
        }
    }
}

bool C2BufferQueueBlockPoolData::holdBlockFromBufferQueue(
        const std::shared_ptr<int>& owner,
        const sp<HGraphicBufferProducer>& igbp,
        std::shared_ptr<C2SurfaceSyncMemory> syncMem) {
    std::scoped_lock<std::mutex> lock(mLock);
    if (!mLocal) {
        mOwner = owner;
        mIgbp = igbp;
        mSyncMem = syncMem;
    }
    if (mHeld) {
        return false;
    }
    mHeld = true;
    return true;
}

bool C2BufferQueueBlockPoolData::beginTransferBlockToClient() {
    std::scoped_lock<std::mutex> lock(mLock);
    mTransfer = true;
    return true;
}

bool C2BufferQueueBlockPoolData::endTransferBlockToClient(bool transfer) {
    std::scoped_lock<std::mutex> lock(mLock);
    mTransfer = false;
    if (transfer) {
        mHeld = false;
    }
    return true;
}

bool C2BufferQueueBlockPoolData::beginAttachBlockToBufferQueue() {
    std::scoped_lock<std::mutex> lock(mLock);
    if (mLocal || mDisplay ||
        mAttach || !mHeld) {
        return false;
    }
    if (mBqId == 0) {
        return false;
    }
    mAttach = true;
    return true;
}

bool C2BufferQueueBlockPoolData::endAttachBlockToBufferQueue(
        const std::shared_ptr<int>& owner,
        const sp<HGraphicBufferProducer>& igbp,
        std::shared_ptr<C2SurfaceSyncMemory> syncMem,
        uint32_t generation,
        uint64_t bqId,
        int32_t bqSlot) {
    std::scoped_lock<std::mutex> lock(mLock);
    if (mLocal || !mAttach) {
        return false;
    }
    if (mDisplay) {
        mAttach = false;
        mHeld = false;
        return false;
    }
    mAttach = false;
    mHeld = true;
    mOwner = owner;
    mIgbp = igbp;
    mSyncMem = syncMem;
    mGeneration = generation;
    mBqId = bqId;
    mBqSlot = bqSlot;
    return true;
}

bool C2BufferQueueBlockPoolData::displayBlockToBufferQueue() {
    std::scoped_lock<std::mutex> lock(mLock);
    if (mLocal || mDisplay || !mHeld) {
        return false;
    }
    if (mBqId == 0) {
        return false;
    }
    mDisplay = true;
    if (mAttach) {
        return false;
    }
    mHeld = false;
    return true;
}

C2BufferQueueBlockPool::C2BufferQueueBlockPool(
        const std::shared_ptr<C2Allocator> &allocator, const local_id_t localId)
        : mAllocator(allocator), mLocalId(localId), mImpl(new Impl(allocator)) {}

C2BufferQueueBlockPool::~C2BufferQueueBlockPool() {}

c2_status_t C2BufferQueueBlockPool::fetchGraphicBlock(
        uint32_t width,
        uint32_t height,
        uint32_t format,
        C2MemoryUsage usage,
        std::shared_ptr<C2GraphicBlock> *block /* nonnull */) {
    if (mImpl) {
        return mImpl->fetchGraphicBlock(width, height, format, usage, block, nullptr);
    }
    return C2_CORRUPTED;
}

c2_status_t C2BufferQueueBlockPool::fetchGraphicBlock(
        uint32_t width,
        uint32_t height,
        uint32_t format,
        C2MemoryUsage usage,
        std::shared_ptr<C2GraphicBlock> *block /* nonnull */,
        C2Fence *fence /* nonnull */) {
    if (mImpl) {
        return mImpl->fetchGraphicBlock(width, height, format, usage, block, fence);
    }
    return C2_CORRUPTED;
}

void C2BufferQueueBlockPool::configureProducer(const sp<HGraphicBufferProducer> &producer) {
    if (mImpl) {
        mImpl->configureProducer(producer);
    }
}

void C2BufferQueueBlockPool::configureProducer(
        const sp<HGraphicBufferProducer> &producer,
        native_handle_t *syncMemory,
        uint64_t bqId,
        uint32_t generationId,
        uint64_t consumerUsage) {
    if (mImpl) {
        mImpl->configureProducer(
               producer, syncMemory, bqId, generationId, consumerUsage, true);
    }
}

void C2BufferQueueBlockPool::setRenderCallback(const OnRenderCallback &renderCallback) {
    if (mImpl) {
        mImpl->setRenderCallback(renderCallback);
    }
}
