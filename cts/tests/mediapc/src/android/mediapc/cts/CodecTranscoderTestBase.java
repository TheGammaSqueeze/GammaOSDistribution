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
import android.media.MediaCodecInfo;
import android.media.MediaExtractor;
import android.media.MediaFormat;
import android.util.Log;
import android.util.Pair;
import android.view.Surface;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.util.concurrent.Callable;

import static org.junit.Assert.assertTrue;
import static org.junit.Assert.fail;

public class CodecTranscoderTestBase {
    private static final String LOG_TAG = CodecTranscoderTestBase.class.getSimpleName();
    private static final boolean ENABLE_LOGS = false;
    static final String mInpPrefix = WorkDir.getMediaDirString();
    String mMime;
    String mTestFile;
    int mBitrate;
    int mFrameRate;
    MediaExtractor mExtractor;
    int mMaxBFrames;
    int mLatency;

    MediaCodec mEncoder;
    CodecAsyncHandler mAsyncHandleEncoder;
    MediaCodec mDecoder;
    CodecAsyncHandler mAsyncHandleDecoder;
    Surface mSurface;

    boolean mSawDecInputEOS;
    boolean mSawDecOutputEOS;
    boolean mSawEncOutputEOS;
    boolean mIsCodecInAsyncMode;
    boolean mSignalEOSWithLastFrame;
    boolean mReviseLatency;
    int mDecInputCount;
    int mDecOutputCount;
    int mEncOutputCount;

    CodecTranscoderTestBase(String mime, String testfile, int bitrate, int frameRate) {
        mMime = mime;
        mTestFile = testfile;
        mBitrate = bitrate;
        mFrameRate = frameRate;
        mMaxBFrames = 0;
        mLatency = mMaxBFrames;
        mReviseLatency = false;
        mAsyncHandleDecoder = new CodecAsyncHandler();
        mAsyncHandleEncoder = new CodecAsyncHandler();
    }

    boolean hasSeenError() {
        return mAsyncHandleDecoder.hasSeenError() || mAsyncHandleEncoder.hasSeenError();
    }

    MediaFormat setUpSource(String srcFile) throws IOException {
        mExtractor = new MediaExtractor();
        mExtractor.setDataSource(mInpPrefix + srcFile);
        for (int trackID = 0; trackID < mExtractor.getTrackCount(); trackID++) {
            MediaFormat format = mExtractor.getTrackFormat(trackID);
            String mime = format.getString(MediaFormat.KEY_MIME);
            if (mime.startsWith("video/")) {
                mExtractor.selectTrack(trackID);
                format.setInteger(MediaFormat.KEY_COLOR_FORMAT,
                        MediaCodecInfo.CodecCapabilities.COLOR_FormatSurface);
                format.setInteger(MediaFormat.KEY_PRIORITY, 1); // Best effort
                return format;
            }
        }
        mExtractor.release();
        fail("No video track found in file: " + srcFile);
        return null;
    }

    void resetContext(boolean isAsync, boolean signalEOSWithLastFrame) {
        mAsyncHandleDecoder.resetContext();
        mAsyncHandleEncoder.resetContext();
        mIsCodecInAsyncMode = isAsync;
        mSignalEOSWithLastFrame = signalEOSWithLastFrame;
        mSawDecInputEOS = false;
        mSawDecOutputEOS = false;
        mSawEncOutputEOS = false;
        mDecInputCount = 0;
        mDecOutputCount = 0;
        mEncOutputCount = 0;
    }

    void configureCodec(MediaFormat decFormat, MediaFormat encFormat, boolean isAsync,
            boolean signalEOSWithLastFrame) {
        resetContext(isAsync, signalEOSWithLastFrame);
        mAsyncHandleEncoder.setCallBack(mEncoder, isAsync);
        mEncoder.configure(encFormat, null, MediaCodec.CONFIGURE_FLAG_ENCODE, null);
        if (mEncoder.getInputFormat().containsKey(MediaFormat.KEY_LATENCY)) {
            mReviseLatency = true;
            mLatency = mEncoder.getInputFormat().getInteger(MediaFormat.KEY_LATENCY);
        }
        mSurface = mEncoder.createInputSurface();
        assertTrue("Surface is not valid", mSurface.isValid());
        mAsyncHandleDecoder.setCallBack(mDecoder, isAsync);
        mDecoder.configure(decFormat, mSurface, null, 0);
        if (ENABLE_LOGS) {
            Log.v(LOG_TAG, "codec configured");
        }
    }

    void enqueueDecoderEOS(int bufferIndex) {
        if (!mSawDecInputEOS) {
            mDecoder.queueInputBuffer(bufferIndex, 0, 0, 0, MediaCodec.BUFFER_FLAG_END_OF_STREAM);
            mSawDecInputEOS = true;
            if (ENABLE_LOGS) {
                Log.v(LOG_TAG, "Queued End of Stream");
            }
        }
    }

    void enqueueDecoderInput(int bufferIndex) {
        if (mExtractor.getSampleSize() < 0) {
            enqueueDecoderEOS(bufferIndex);
        } else {
            ByteBuffer inputBuffer = mDecoder.getInputBuffer(bufferIndex);
            int size = mExtractor.readSampleData(inputBuffer, 0);
            long pts = mExtractor.getSampleTime();
            int extractorFlags = mExtractor.getSampleFlags();
            int codecFlags = 0;
            if ((extractorFlags & MediaExtractor.SAMPLE_FLAG_SYNC) != 0) {
                codecFlags |= MediaCodec.BUFFER_FLAG_KEY_FRAME;
            }
            if (!mExtractor.advance() && mSignalEOSWithLastFrame) {
                codecFlags |= MediaCodec.BUFFER_FLAG_END_OF_STREAM;
                mSawDecInputEOS = true;
            }
            mDecoder.queueInputBuffer(bufferIndex, 0, size, pts, codecFlags);
            if (size > 0 && (codecFlags & MediaCodec.BUFFER_FLAG_CODEC_CONFIG) == 0) {
                mDecInputCount++;
            }
        }
    }

    void dequeueDecoderOutput(int bufferIndex, MediaCodec.BufferInfo info) {
        if ((info.flags & MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
            mSawDecOutputEOS = true;
        }
        if (info.size > 0 && (info.flags & MediaCodec.BUFFER_FLAG_CODEC_CONFIG) == 0) {
            mDecOutputCount++;
        }
        mDecoder.releaseOutputBuffer(bufferIndex, mSurface != null);
    }

    void dequeueEncoderOutput(int bufferIndex, MediaCodec.BufferInfo info) {
        if ((info.flags & MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
            mSawEncOutputEOS = true;
        }
        if (info.size > 0 && (info.flags & MediaCodec.BUFFER_FLAG_CODEC_CONFIG) == 0) {
            mEncOutputCount++;
        }
        mEncoder.releaseOutputBuffer(bufferIndex, false);
    }

    void tryEncoderOutput(long timeOutUs) throws InterruptedException {
        if (mIsCodecInAsyncMode) {
            if (!hasSeenError() && !mSawEncOutputEOS) {
                int retry = 0;
                while (mReviseLatency) {
                    if (mAsyncHandleEncoder.hasOutputFormatChanged()) {
                        mReviseLatency = false;
                        int actualLatency = mAsyncHandleEncoder.getOutputFormat()
                                .getInteger(MediaFormat.KEY_LATENCY, mLatency);
                        if (mLatency < actualLatency) {
                            mLatency = actualLatency;
                            return;
                        }
                    } else {
                        if (retry > CodecTestBase.RETRY_LIMIT) throw new InterruptedException(
                                "did not receive output format changed for encoder after " +
                                        CodecTestBase.Q_DEQ_TIMEOUT_US * CodecTestBase.RETRY_LIMIT +
                                        " us");
                        Thread.sleep(CodecTestBase.Q_DEQ_TIMEOUT_US / 1000);
                        retry ++;
                    }
                }
                Pair<Integer, MediaCodec.BufferInfo> element = mAsyncHandleEncoder.getOutput();
                if (element != null) {
                    dequeueEncoderOutput(element.first, element.second);
                }
            }
        } else {
            MediaCodec.BufferInfo outInfo = new MediaCodec.BufferInfo();
            if (!mSawEncOutputEOS) {
                int outputBufferId = mEncoder.dequeueOutputBuffer(outInfo, timeOutUs);
                if (outputBufferId >= 0) {
                    dequeueEncoderOutput(outputBufferId, outInfo);
                } else if (outputBufferId == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
                    mLatency = mEncoder.getOutputFormat()
                            .getInteger(MediaFormat.KEY_LATENCY, mLatency);
                }
            }
        }
    }

    void waitForAllEncoderOutputs() throws InterruptedException {
        if (mIsCodecInAsyncMode) {
            while (!hasSeenError() && !mSawEncOutputEOS) {
                tryEncoderOutput(CodecTestBase.Q_DEQ_TIMEOUT_US);
            }
        } else {
            while (!mSawEncOutputEOS) {
                tryEncoderOutput(CodecTestBase.Q_DEQ_TIMEOUT_US);
            }
        }
    }

    void queueEOS() throws InterruptedException {
        if (mIsCodecInAsyncMode) {
            while (!mAsyncHandleDecoder.hasSeenError() && !mSawDecInputEOS) {
                Pair<Integer, MediaCodec.BufferInfo> element = mAsyncHandleDecoder.getWork();
                if (element != null) {
                    int bufferID = element.first;
                    MediaCodec.BufferInfo info = element.second;
                    if (info != null) {
                        dequeueDecoderOutput(bufferID, info);
                    } else {
                        enqueueDecoderEOS(element.first);
                    }
                }
            }
        } else {
            MediaCodec.BufferInfo outInfo = new MediaCodec.BufferInfo();
            while (!mSawDecInputEOS) {
                int outputBufferId =
                        mDecoder.dequeueOutputBuffer(outInfo, CodecTestBase.Q_DEQ_TIMEOUT_US);
                if (outputBufferId >= 0) {
                    dequeueDecoderOutput(outputBufferId, outInfo);
                }
                int inputBufferId = mDecoder.dequeueInputBuffer(CodecTestBase.Q_DEQ_TIMEOUT_US);
                if (inputBufferId != -1) {
                    enqueueDecoderEOS(inputBufferId);
                }
            }
        }
        if (mIsCodecInAsyncMode) {
            while (!hasSeenError() && !mSawDecOutputEOS) {
                Pair<Integer, MediaCodec.BufferInfo> decOp = mAsyncHandleDecoder.getOutput();
                if (decOp != null) dequeueDecoderOutput(decOp.first, decOp.second);
                if (mSawDecOutputEOS) mEncoder.signalEndOfInputStream();
                if (mDecOutputCount - mEncOutputCount > mLatency) {
                    tryEncoderOutput(-1);
                }
            }
        } else {
            MediaCodec.BufferInfo outInfo = new MediaCodec.BufferInfo();
            while (!mSawDecOutputEOS) {
                int outputBufferId =
                        mDecoder.dequeueOutputBuffer(outInfo, CodecTestBase.Q_DEQ_TIMEOUT_US);
                if (outputBufferId >= 0) {
                    dequeueDecoderOutput(outputBufferId, outInfo);
                }
                if (mSawDecOutputEOS) mEncoder.signalEndOfInputStream();
                if (mDecOutputCount - mEncOutputCount > mLatency) {
                    tryEncoderOutput(-1);
                }
            }
        }
    }

    void doWork(int frameLimit) throws InterruptedException {
        int frameCnt = 0;
        if (mIsCodecInAsyncMode) {
            // dequeue output after inputEOS is expected to be done in waitForAllOutputs()
            while (!hasSeenError() && !mSawDecInputEOS && frameCnt < frameLimit) {
                Pair<Integer, MediaCodec.BufferInfo> element = mAsyncHandleDecoder.getWork();
                if (element != null) {
                    int bufferID = element.first;
                    MediaCodec.BufferInfo info = element.second;
                    if (info != null) {
                        // <id, info> corresponds to output callback. Handle it accordingly
                        dequeueDecoderOutput(bufferID, info);
                    } else {
                        // <id, null> corresponds to input callback. Handle it accordingly
                        enqueueDecoderInput(bufferID);
                        frameCnt++;
                    }
                }
                // check decoder EOS
                if (mSawDecOutputEOS) mEncoder.signalEndOfInputStream();
                // encoder output
                if (mDecOutputCount - mEncOutputCount > mLatency) {
                    tryEncoderOutput(-1);
                }
            }
        } else {
            MediaCodec.BufferInfo outInfo = new MediaCodec.BufferInfo();
            while (!mSawDecInputEOS && frameCnt < frameLimit) {
                // decoder input
                int inputBufferId = mDecoder.dequeueInputBuffer(CodecTestBase.Q_DEQ_TIMEOUT_US);
                if (inputBufferId != -1) {
                    enqueueDecoderInput(inputBufferId);
                    frameCnt++;
                }
                // decoder output
                int outputBufferId =
                        mDecoder.dequeueOutputBuffer(outInfo, CodecTestBase.Q_DEQ_TIMEOUT_US);
                if (outputBufferId >= 0) {
                    dequeueDecoderOutput(outputBufferId, outInfo);
                }
                // check decoder EOS
                if (mSawDecOutputEOS) mEncoder.signalEndOfInputStream();
                // encoder output
                if (mDecOutputCount - mEncOutputCount > mLatency) {
                    tryEncoderOutput(-1);
                }
            }
        }
    }

    MediaFormat setUpEncoderFormat(MediaFormat decoderFormat) {
        MediaFormat encoderFormat = new MediaFormat();
        encoderFormat.setString(MediaFormat.KEY_MIME, mMime);
        encoderFormat.setInteger(MediaFormat.KEY_WIDTH,
                decoderFormat.getInteger(MediaFormat.KEY_WIDTH));
        encoderFormat.setInteger(MediaFormat.KEY_HEIGHT,
                decoderFormat.getInteger(MediaFormat.KEY_HEIGHT));
        encoderFormat.setInteger(MediaFormat.KEY_FRAME_RATE, mFrameRate);
        encoderFormat.setInteger(MediaFormat.KEY_BIT_RATE, mBitrate);
        encoderFormat.setFloat(MediaFormat.KEY_I_FRAME_INTERVAL, 1.0f);
        encoderFormat.setInteger(MediaFormat.KEY_COLOR_FORMAT,
                MediaCodecInfo.CodecCapabilities.COLOR_FormatSurface);
        encoderFormat.setInteger(MediaFormat.KEY_MAX_B_FRAMES, mMaxBFrames);
        encoderFormat.setInteger(MediaFormat.KEY_PRIORITY,
                decoderFormat.getInteger(MediaFormat.KEY_PRIORITY));
        return encoderFormat;
    }
}

/**
 * The following class transcodes the given testFile and returns the achieved fps for transcoding.
 */
class Transcode extends CodecTranscoderTestBase implements Callable<Double> {
    private static final String LOG_TAG = Transcode.class.getSimpleName();

    private final String mDecoderName;
    private final String mEncoderName;
    private final boolean mIsAsync;

    Transcode(String mime, String testFile, String decoderName, String encoderName,
            boolean isAsync) {
        super(mime, testFile, 3000000, 30);
        mDecoderName = decoderName;
        mEncoderName = encoderName;
        mIsAsync = isAsync;
    }

    public Double doTranscode() throws Exception {
        MediaFormat decoderFormat = setUpSource(mTestFile);
        mDecoder = MediaCodec.createByCodecName(mDecoderName);
        MediaFormat encoderFormat = setUpEncoderFormat(decoderFormat);
        mEncoder = MediaCodec.createByCodecName(mEncoderName);
        mExtractor.seekTo(0, MediaExtractor.SEEK_TO_CLOSEST_SYNC);
        configureCodec(decoderFormat, encoderFormat, mIsAsync, false);
        mEncoder.start();
        mDecoder.start();
        long start = System.currentTimeMillis();
        doWork(Integer.MAX_VALUE);
        queueEOS();
        waitForAllEncoderOutputs();
        long end = System.currentTimeMillis();
        mSurface.release();
        mDecoder.stop();
        mDecoder.release();
        mEncoder.stop();
        mEncoder.release();
        mExtractor.release();
        double fps = mEncOutputCount / ((end - start) / 1000.0);
        Log.d(LOG_TAG, "Mime: " + mMime + " Decoder: " + mDecoderName + " Encoder: " +
                mEncoderName + " Achieved fps: " + fps);
        return fps;
    }

    @Override
    public Double call() throws Exception {
        return doTranscode();
    }
}

/**
 * The following class transcodes the given testFile until loadStatus is finished.
 * If input reaches eos, it will rewind the input to start position.
 */
class TranscodeLoad extends Transcode {
    private final LoadStatus mLoadStatus;

    private long mMaxPts;
    private long mBasePts;

    TranscodeLoad(String mime, String testFile, String decoderName, String encoderName,
            LoadStatus loadStatus) {
        super(mime, testFile, decoderName, encoderName, false);
        mLoadStatus = loadStatus;
        mMaxPts = 0;
        mBasePts = 0;
    }

    @Override
    void configureCodec(MediaFormat decFormat, MediaFormat encFormat, boolean isAsync,
            boolean signalEOSWithLastFrame) {
        decFormat.setInteger(MediaFormat.KEY_PRIORITY, 1);
        encFormat.setInteger(MediaFormat.KEY_PRIORITY, 1);
        resetContext(isAsync, signalEOSWithLastFrame);
        mAsyncHandleEncoder.setCallBack(mEncoder, isAsync);
        mEncoder.configure(encFormat, null, MediaCodec.CONFIGURE_FLAG_ENCODE, null);
        if (mEncoder.getInputFormat().containsKey(MediaFormat.KEY_LATENCY)) {
            mReviseLatency = true;
            mLatency = mEncoder.getInputFormat().getInteger(MediaFormat.KEY_LATENCY);
        }
        mSurface = mEncoder.createInputSurface();
        assertTrue("Surface is not valid", mSurface.isValid());
        mAsyncHandleDecoder.setCallBack(mDecoder, isAsync);
        mDecoder.configure(decFormat, mSurface, null, 0);
    }

    @Override
    void enqueueDecoderInput(int bufferIndex) {
        if (mExtractor.getSampleSize() < 0 || mLoadStatus.isLoadFinished()) {
            enqueueDecoderEOS(bufferIndex);
        } else {
            ByteBuffer inputBuffer = mDecoder.getInputBuffer(bufferIndex);
            int size = mExtractor.readSampleData(inputBuffer, 0);
            long pts = mExtractor.getSampleTime();
            mMaxPts = Math.max(mMaxPts, mBasePts + pts);
            int extractorFlags = mExtractor.getSampleFlags();
            int codecFlags = 0;
            if ((extractorFlags & MediaExtractor.SAMPLE_FLAG_SYNC) != 0) {
                codecFlags |= MediaCodec.BUFFER_FLAG_KEY_FRAME;
            }
            mDecoder.queueInputBuffer(bufferIndex, 0, size, mBasePts + pts, codecFlags);
            if (size > 0 && (codecFlags & MediaCodec.BUFFER_FLAG_CODEC_CONFIG) == 0) {
                mDecInputCount++;
            }
            // If eos is reached, seek to start position.
            if (!mExtractor.advance()) {
                mExtractor.seekTo(0, MediaExtractor.SEEK_TO_CLOSEST_SYNC);
                mBasePts = mMaxPts + 1000000L;
            }
        }
    }
}

/**
 * The following class tells the status of the load whether it is finished or not.
 */
class LoadStatus {
    private boolean mLoadFinished;

    public LoadStatus() { mLoadFinished = false; }

    public synchronized void setLoadFinished() { mLoadFinished = true; }

    public synchronized boolean isLoadFinished() { return mLoadFinished; }
}
