/*
 * Copyright (C) 2020 The Android Open Source Project
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

#ifndef ANDROID_VIDEO_TRACK_TRANSCODER_H
#define ANDROID_VIDEO_TRACK_TRANSCODER_H

#include <android/native_window.h>
#include <media/MediaTrackTranscoder.h>
#include <media/NdkMediaCodecPlatform.h>
#include <media/NdkMediaFormat.h>

#include <condition_variable>
#include <deque>
#include <mutex>

namespace android {

/**
 * Track transcoder for video tracks. VideoTrackTranscoder uses AMediaCodec from the Media NDK
 * internally. The two media codecs are run in asynchronous mode and shares uncompressed buffers
 * using a native surface (ANativeWindow). Codec callback events are placed on a message queue and
 * serviced in order on the transcoding thread managed by MediaTrackTranscoder.
 */
class VideoTrackTranscoder : public std::enable_shared_from_this<VideoTrackTranscoder>,
                             public MediaTrackTranscoder {
public:
    static std::shared_ptr<VideoTrackTranscoder> create(
            const std::weak_ptr<MediaTrackTranscoderCallback>& transcoderCallback,
            pid_t pid = AMEDIACODEC_CALLING_PID, uid_t uid = AMEDIACODEC_CALLING_UID);

    virtual ~VideoTrackTranscoder() override;

private:
    friend struct AsyncCodecCallbackDispatch;
    friend class VideoTrackTranscoderTests;

    // Minimal blocking queue used as a message queue by VideoTrackTranscoder.
    template <typename T>
    class BlockingQueue {
    public:
        void push(T const& value, bool front = false);
        T pop();
        void abort();

    private:
        std::mutex mMutex;
        std::condition_variable mCondition;
        std::deque<T> mQueue;
        bool mAborted = false;
    };
    class CodecWrapper;

    VideoTrackTranscoder(const std::weak_ptr<MediaTrackTranscoderCallback>& transcoderCallback,
                         pid_t pid, uid_t uid)
          : MediaTrackTranscoder(transcoderCallback), mPid(pid), mUid(uid){};

    // MediaTrackTranscoder
    media_status_t runTranscodeLoop(bool* stopped) override;
    void abortTranscodeLoop() override;
    media_status_t configureDestinationFormat(
            const std::shared_ptr<AMediaFormat>& destinationFormat) override;
    std::shared_ptr<AMediaFormat> getOutputFormat() const override;
    // ~MediaTrackTranscoder

    // Enqueues an input sample with the decoder.
    void enqueueInputSample(int32_t bufferIndex);

    // Moves a decoded buffer from the decoder's output to the encoder's input.
    void transferBuffer(int32_t bufferIndex, AMediaCodecBufferInfo bufferInfo);

    // Dequeues an encoded buffer from the encoder and adds it to the output queue.
    void dequeueOutputSample(int32_t bufferIndex, AMediaCodecBufferInfo bufferInfo);

    // Updates the video track's actual format based on encoder and decoder output format.
    void updateTrackFormat(AMediaFormat* outputFormat, bool fromDecoder);

    AMediaCodec* mDecoder = nullptr;
    std::shared_ptr<CodecWrapper> mEncoder;
    ANativeWindow* mSurface = nullptr;
    bool mEosFromSource = false;
    bool mEosFromEncoder = false;
    bool mLastSampleWasSync = false;
    media_status_t mStatus = AMEDIA_OK;
    MediaSampleInfo mSampleInfo;
    BlockingQueue<std::function<void()>> mCodecMessageQueue;
    std::shared_ptr<AMediaFormat> mDestinationFormat;
    std::shared_ptr<AMediaFormat> mActualOutputFormat;
    pid_t mPid;
    uid_t mUid;
    uint64_t mInputFrameCount = 0;
    uint64_t mOutputFrameCount = 0;
    int32_t mConfiguredBitrate = 0;
};

}  // namespace android
#endif  // ANDROID_VIDEO_TRACK_TRANSCODER_H
