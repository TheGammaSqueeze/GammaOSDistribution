/*
 * Copyright (C) 2021 The Android Open Source Project
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

package android.mediapc.cts;

import android.media.MediaCodec;
import android.media.MediaExtractor;
import android.media.MediaFormat;
import android.view.Surface;

import java.io.File;
import java.nio.ByteBuffer;
import java.util.ArrayList;

import static android.mediapc.cts.FrameDropTestBase.DECODE_31S;

/**
 * The following class calculates the frame drops for the given array of testFiles playback.
 * It will do playback for at least 30 seconds worth of input data or for utmost 31 seconds.
 * If input reaches eos, it will rewind the input to start position.
 */
public class PlaybackFrameDrop extends CodecDecoderTestBase {
    private final String mDecoderName;
    private final String[] mTestFiles;
    private final int mEachFrameTimeIntervalUs;
    private final boolean mIsAsync;

    private int mFrameDropCount;
    private ByteBuffer mBuffer;
    private ArrayList<MediaCodec.BufferInfo> mBufferInfos;

    private long mInputMaxPtsUs;
    private long mRenderStartTimeUs;
    private long mBasePts;
    private long mMaxPts;
    private long mDecodeStartTimeMs;
    private int mSampleIndex;
    private int mMaxNumFrames;

    PlaybackFrameDrop(String mime, String decoderName, String[] testFiles, Surface surface,
            int frameRate, boolean isAsync) {
        super(mime, null);
        mDecoderName = decoderName;
        mTestFiles = testFiles;
        mSurface = surface;
        mEachFrameTimeIntervalUs = 1000000 / frameRate;
        mIsAsync = isAsync;
        mInputMaxPtsUs = 0;
        mBasePts = 0;
        mMaxPts = 0;
        mSampleIndex = 0;
        mFrameDropCount = 0;
        // Decode for 30 seconds
        mMaxNumFrames = frameRate * 30;
        mBufferInfos = new ArrayList<>();
    }

    private MediaFormat createInputList(MediaFormat format, ByteBuffer buffer,
            ArrayList<MediaCodec.BufferInfo> list, int offset, long ptsOffset) {
        int csdBuffersSize = 0;
        if (hasCSD(format)) {
            MediaCodec.BufferInfo bufferInfo = new MediaCodec.BufferInfo();
            bufferInfo.offset = offset;
            bufferInfo.size = 0;
            bufferInfo.presentationTimeUs = 0;
            bufferInfo.flags = MediaCodec.BUFFER_FLAG_CODEC_CONFIG;
            for (int i = 0; ; i++) {
                String csdKey = "csd-" + i;
                if (format.containsKey(csdKey)) {
                    ByteBuffer csdBuffer = format.getByteBuffer(csdKey);
                    bufferInfo.size += csdBuffer.limit();
                    buffer.put(csdBuffer);
                    format.removeKey(csdKey);
                } else break;
            }
            list.add(bufferInfo);
            offset += bufferInfo.size;
        }
        while (true) {
            MediaCodec.BufferInfo bufferInfo = new MediaCodec.BufferInfo();
            bufferInfo.size = mExtractor.readSampleData(buffer, offset);
            if (bufferInfo.size < 0) {
                break;
            }
            bufferInfo.offset = offset;
            bufferInfo.presentationTimeUs = ptsOffset + mExtractor.getSampleTime();
            mInputMaxPtsUs = Math.max(mInputMaxPtsUs, bufferInfo.presentationTimeUs);
            int flags = mExtractor.getSampleFlags();
            bufferInfo.flags = 0;
            if ((flags & MediaExtractor.SAMPLE_FLAG_SYNC) != 0) {
                bufferInfo.flags |= MediaCodec.BUFFER_FLAG_KEY_FRAME;
            }
            list.add(bufferInfo);
            mExtractor.advance();
            offset += bufferInfo.size;
        }
        buffer.clear();
        buffer.position(offset);
        return format;
    }

    public ArrayList<MediaFormat> setUpSourceFiles() throws Exception {
        ArrayList<MediaFormat> formats = new ArrayList<>();
        for (String file : mTestFiles) {
            formats.add(setUpSource(file));
            mExtractor.release();
        }
        int totalSize = 0;
        for (String srcFile : mTestFiles) {
            File file = new File(mInpPrefix + srcFile);
            totalSize += (int) file.length();
        }
        totalSize <<= 1;
        long ptsOffset = 0;
        int buffOffset = 0;
        mBuffer = ByteBuffer.allocate(totalSize);
        for (String file : mTestFiles) {
            formats.add(createInputList(setUpSource(file), mBuffer, mBufferInfos, buffOffset,
                    ptsOffset));
            mExtractor.release();
            ptsOffset = mInputMaxPtsUs + 1000000L;
            buffOffset = (mBufferInfos.get(mBufferInfos.size() - 1).offset) +
                    (mBufferInfos.get(mBufferInfos.size() - 1).size);
        }
        return formats;
    }

    public int getFrameDropCount() throws Exception {
        ArrayList<MediaFormat> formats = setUpSourceFiles();
        mCodec = MediaCodec.createByCodecName(mDecoderName);
        configureCodec(formats.get(0), mIsAsync, false, false);
        mCodec.start();
        mDecodeStartTimeMs = System.currentTimeMillis();
        doWork(Integer.MAX_VALUE);
        queueEOS();
        waitForAllOutputs();
        mCodec.stop();
        mCodec.release();
        return mFrameDropCount;
    }

    @Override
    void enqueueInput(int bufferIndex) {
        if (mSampleIndex >= mBufferInfos.size() ||
                // Decode for mMaxNumFrames samples or for utmost 31 seconds
                mInputCount >= mMaxNumFrames ||
                (System.currentTimeMillis() - mDecodeStartTimeMs > DECODE_31S)) {
            enqueueEOS(bufferIndex);
        } else {
            MediaCodec.BufferInfo info = mBufferInfos.get(mSampleIndex++);
            if (info.size > 0) {
                ByteBuffer dstBuf = mCodec.getInputBuffer(bufferIndex);
                dstBuf.put(mBuffer.array(), info.offset, info.size);
                mInputCount++;
            }
            if ((info.flags & MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
                mSawInputEOS = true;
            }
            long pts = info.presentationTimeUs;
            mMaxPts = Math.max(mMaxPts, mBasePts + pts);
            mCodec.queueInputBuffer(bufferIndex, 0, info.size, mBasePts + pts, info.flags);
            // If input reaches the end of samples, rewind to start position.
            if (mSampleIndex == mBufferInfos.size()) {
                mSampleIndex = 0;
                mBasePts = mMaxPts + 1000000L;
            }
        }
    }

    private long getRenderTimeUs(int frameIndex) {
        return mRenderStartTimeUs + frameIndex * mEachFrameTimeIntervalUs;
    }

    @Override
    void dequeueOutput(int bufferIndex, MediaCodec.BufferInfo info) {
        if ((info.flags & MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
            mSawOutputEOS = true;
        }
        // We will limit the playback to 60 fps using the system timestamps.
        long nowUs = System.nanoTime() / 1000;
        if (mOutputCount == 0) {
            mRenderStartTimeUs = nowUs;
            mCodec.releaseOutputBuffer(bufferIndex, true);
        } else if (nowUs > getRenderTimeUs(mOutputCount + 1)) {
            // If the current sample timeStamp is greater than the actual presentation timeStamp
            // of the next sample, we will consider it as a frame drop and don't render.
            mFrameDropCount++;
            mCodec.releaseOutputBuffer(bufferIndex, false);
        } else if (nowUs > getRenderTimeUs(mOutputCount)) {
            // If the current sample timeStamp is greater than the actual presentation timeStamp
            // of the current sample, we can render it.
            mCodec.releaseOutputBuffer(bufferIndex, true);
        } else {
            // If the current sample timestamp is less than the actual presentation timeStamp,
            // We are okay with directly rendering the sample if we are less by not more than
            // half of one sample duration. Otherwise we sleep for how much more we are less
            // than the half of one sample duration.
            if ((getRenderTimeUs(mOutputCount) - nowUs) > (mEachFrameTimeIntervalUs / 2)) {
                try {
                    Thread.sleep(((getRenderTimeUs(mOutputCount) - nowUs) -
                            (mEachFrameTimeIntervalUs / 2)) / 1000);
                } catch (InterruptedException e) {
                    // Do nothing.
                }
            }
            mCodec.releaseOutputBuffer(bufferIndex, true);
        }
        if (info.size > 0 && (info.flags & MediaCodec.BUFFER_FLAG_CODEC_CONFIG) == 0) {
            mOutputCount++;
        }
    }
}
