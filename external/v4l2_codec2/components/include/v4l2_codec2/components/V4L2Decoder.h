// Copyright 2020 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef ANDROID_V4L2_CODEC2_COMPONENTS_V4L2_DECODER_H
#define ANDROID_V4L2_CODEC2_COMPONENTS_V4L2_DECODER_H

#include <stdint.h>

#include <memory>
#include <optional>

#include <base/callback.h>
#include <base/memory/weak_ptr.h>

#include <ui/Rect.h>
#include <ui/Size.h>
#include <v4l2_codec2/common/V4L2Device.h>
#include <v4l2_codec2/common/VideoTypes.h>
#include <v4l2_codec2/components/VideoDecoder.h>
#include <v4l2_codec2/components/VideoFrame.h>
#include <v4l2_codec2/components/VideoFramePool.h>

namespace android {

class V4L2Decoder : public VideoDecoder {
public:
    static std::unique_ptr<VideoDecoder> Create(
            const VideoCodec& codec, const size_t inputBufferSize, const size_t minNumOutputBuffers,
            GetPoolCB getPoolCB, OutputCB outputCb, ErrorCB errorCb,
            scoped_refptr<::base::SequencedTaskRunner> taskRunner);
    ~V4L2Decoder() override;

    void decode(std::unique_ptr<ConstBitstreamBuffer> buffer, DecodeCB decodeCb) override;
    void drain(DecodeCB drainCb) override;
    void flush() override;

private:
    enum class State {
        Idle,  // Not received any decode buffer after initialized, flushed, or drained.
        Decoding,
        Draining,
        Error,
    };
    static const char* StateToString(State state);

    struct DecodeRequest {
        DecodeRequest(std::unique_ptr<ConstBitstreamBuffer> buffer, DecodeCB decodeCb)
              : buffer(std::move(buffer)), decodeCb(std::move(decodeCb)) {}
        DecodeRequest(DecodeRequest&&) = default;
        ~DecodeRequest() = default;

        std::unique_ptr<ConstBitstreamBuffer> buffer;  // nullptr means Drain
        DecodeCB decodeCb;
    };

    V4L2Decoder(scoped_refptr<::base::SequencedTaskRunner> taskRunner);
    bool start(const VideoCodec& codec, const size_t inputBufferSize,
               const size_t minNumOutputBuffers, GetPoolCB getPoolCb, OutputCB outputCb,
               ErrorCB errorCb);
    bool setupInputFormat(const uint32_t inputPixelFormat, const size_t inputBufferSize);
    void pumpDecodeRequest();

    void serviceDeviceTask(bool event);
    bool dequeueResolutionChangeEvent();
    bool changeResolution();
    bool setupOutputFormat(const ui::Size& size);

    void tryFetchVideoFrame();
    void onVideoFrameReady(std::optional<VideoFramePool::FrameWithBlockId> frameWithBlockId);

    std::optional<size_t> getNumOutputBuffers();
    std::optional<struct v4l2_format> getFormatInfo();
    Rect getVisibleRect(const ui::Size& codedSize);
    bool sendV4L2DecoderCmd(bool start);

    void setState(State newState);
    void onError();

    std::unique_ptr<VideoFramePool> mVideoFramePool;

    scoped_refptr<V4L2Device> mDevice;
    scoped_refptr<V4L2Queue> mInputQueue;
    scoped_refptr<V4L2Queue> mOutputQueue;

    std::queue<DecodeRequest> mDecodeRequests;
    std::map<int32_t, DecodeCB> mPendingDecodeCbs;

    size_t mMinNumOutputBuffers = 0;
    GetPoolCB mGetPoolCb;
    OutputCB mOutputCb;
    DecodeCB mDrainCb;
    ErrorCB mErrorCb;

    ui::Size mCodedSize;
    Rect mVisibleRect;

    std::map<size_t, std::unique_ptr<VideoFrame>> mFrameAtDevice;

    // Block IDs can be arbitrarily large, but we only have a limited number of
    // buffers. This maintains an association between a block ID and a specific
    // V4L2 buffer index.
    std::map<size_t, size_t> mBlockIdToV4L2Id;

    State mState = State::Idle;

    scoped_refptr<::base::SequencedTaskRunner> mTaskRunner;

    ::base::WeakPtr<V4L2Decoder> mWeakThis;
    ::base::WeakPtrFactory<V4L2Decoder> mWeakThisFactory{this};
};

}  // namespace android

#endif  // ANDROID_V4L2_CODEC2_COMPONENTS_V4L2_DECODER_H
