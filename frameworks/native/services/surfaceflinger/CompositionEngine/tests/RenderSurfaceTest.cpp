/*
 * Copyright 2019 The Android Open Source Project
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

#include <cstdarg>
#include <cstdint>

#include <compositionengine/RenderSurfaceCreationArgs.h>
#include <compositionengine/impl/OutputCompositionState.h>
#include <compositionengine/impl/RenderSurface.h>
#include <compositionengine/mock/CompositionEngine.h>
#include <compositionengine/mock/Display.h>
#include <compositionengine/mock/DisplaySurface.h>
#include <compositionengine/mock/NativeWindow.h>
#include <compositionengine/mock/OutputLayer.h>
#include <gtest/gtest.h>
#include <renderengine/ExternalTexture.h>
#include <renderengine/mock/RenderEngine.h>
#include <ui/GraphicBuffer.h>

namespace android::compositionengine {
namespace {

constexpr int32_t DEFAULT_DISPLAY_WIDTH = 1920;
constexpr int32_t DEFAULT_DISPLAY_HEIGHT = 1080;
constexpr DisplayId DEFAULT_DISPLAY_ID = PhysicalDisplayId(123u);
const std::string DEFAULT_DISPLAY_NAME = "Mock Display";

using testing::_;
using testing::ByMove;
using testing::DoAll;
using testing::Ref;
using testing::Return;
using testing::ReturnRef;
using testing::SetArgPointee;
using testing::StrictMock;

class RenderSurfaceTest : public testing::Test {
public:
    RenderSurfaceTest() {
        EXPECT_CALL(mDisplay, getId()).WillRepeatedly(Return(DEFAULT_DISPLAY_ID));
        EXPECT_CALL(mDisplay, getName()).WillRepeatedly(ReturnRef(DEFAULT_DISPLAY_NAME));
        EXPECT_CALL(mCompositionEngine, getRenderEngine).WillRepeatedly(ReturnRef(mRenderEngine));
        EXPECT_CALL(*mNativeWindow, disconnect(NATIVE_WINDOW_API_EGL))
                .WillRepeatedly(Return(NO_ERROR));
    }

    StrictMock<renderengine::mock::RenderEngine> mRenderEngine;
    StrictMock<mock::CompositionEngine> mCompositionEngine;
    StrictMock<mock::Display> mDisplay;
    sp<mock::NativeWindow> mNativeWindow = new StrictMock<mock::NativeWindow>();
    sp<mock::DisplaySurface> mDisplaySurface = new StrictMock<mock::DisplaySurface>();
    impl::RenderSurface mSurface{mCompositionEngine, mDisplay,
                                 RenderSurfaceCreationArgsBuilder()
                                         .setDisplayWidth(DEFAULT_DISPLAY_WIDTH)
                                         .setDisplayHeight(DEFAULT_DISPLAY_HEIGHT)
                                         .setNativeWindow(mNativeWindow)
                                         .setDisplaySurface(mDisplaySurface)
                                         .build()};
};

/*
 * Basic construction
 */

TEST_F(RenderSurfaceTest, canInstantiate) {
    EXPECT_TRUE(mSurface.isValid());
}

/*
 * RenderSurface::initialize()
 */

TEST_F(RenderSurfaceTest, initializeConfiguresNativeWindow) {
    EXPECT_CALL(*mNativeWindow, connect(NATIVE_WINDOW_API_EGL)).WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mNativeWindow, setBuffersFormat(HAL_PIXEL_FORMAT_RGBA_8888))
            .WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mNativeWindow, setUsage(GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE))
            .WillOnce(Return(NO_ERROR));

    mSurface.initialize();
}

/*
 * RenderSurface::getSize()
 */

TEST_F(RenderSurfaceTest, sizeReturnsConstructedSize) {
    const ui::Size expected{DEFAULT_DISPLAY_WIDTH, DEFAULT_DISPLAY_HEIGHT};

    EXPECT_EQ(expected, mSurface.getSize());
}

/*
 * RenderSurface::getClientTargetAcquireFence()
 */

TEST_F(RenderSurfaceTest, getClientTargetAcquireFenceForwardsCall) {
    sp<Fence> fence = new Fence();

    EXPECT_CALL(*mDisplaySurface, getClientTargetAcquireFence()).WillOnce(ReturnRef(fence));

    EXPECT_EQ(fence.get(), mSurface.getClientTargetAcquireFence().get());
}

/*
 * RenderSurface::setDisplaySize()
 */

TEST_F(RenderSurfaceTest, setDisplaySizeAppliesChange) {
    const ui::Size size(640, 480);
    EXPECT_CALL(*mDisplaySurface, resizeBuffers(size)).Times(1);

    mSurface.setDisplaySize(size);
}

/*
 * RenderSurface::setBufferDataspace()
 */

TEST_F(RenderSurfaceTest, setBufferDataspaceAppliesChange) {
    EXPECT_CALL(*mNativeWindow, setBuffersDataSpace(ui::Dataspace::DISPLAY_P3))
            .WillOnce(Return(NO_ERROR));

    mSurface.setBufferDataspace(ui::Dataspace::DISPLAY_P3);
}

/*
 * RenderSurface::setProtected()
 */

TEST_F(RenderSurfaceTest, setProtectedTrueEnablesProtection) {
    EXPECT_FALSE(mSurface.isProtected());
    EXPECT_CALL(*mNativeWindow,
                setUsage(GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE |
                         GRALLOC_USAGE_PROTECTED))
            .WillOnce(Return(NO_ERROR));

    mSurface.setProtected(true);
    EXPECT_TRUE(mSurface.isProtected());
}

TEST_F(RenderSurfaceTest, setProtectedFalseDisablesProtection) {
    EXPECT_FALSE(mSurface.isProtected());
    EXPECT_CALL(*mNativeWindow, setUsage(GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE))
            .WillOnce(Return(NO_ERROR));

    mSurface.setProtected(false);
    EXPECT_FALSE(mSurface.isProtected());
}

TEST_F(RenderSurfaceTest, setProtectedEnableAndDisable) {
    EXPECT_FALSE(mSurface.isProtected());
    EXPECT_CALL(*mNativeWindow,
                setUsage(GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE |
                         GRALLOC_USAGE_PROTECTED))
            .WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mNativeWindow, setUsage(GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE))
            .WillOnce(Return(NO_ERROR));

    mSurface.setProtected(true);
    EXPECT_TRUE(mSurface.isProtected());
    mSurface.setProtected(false);
    EXPECT_FALSE(mSurface.isProtected());
}

TEST_F(RenderSurfaceTest, setProtectedEnableWithError) {
    EXPECT_FALSE(mSurface.isProtected());
    EXPECT_CALL(*mNativeWindow,
                setUsage(GRALLOC_USAGE_HW_RENDER | GRALLOC_USAGE_HW_TEXTURE |
                         GRALLOC_USAGE_PROTECTED))
            .WillOnce(Return(INVALID_OPERATION));
    mSurface.setProtected(true);
    EXPECT_FALSE(mSurface.isProtected());
}

/*
 * RenderSurface::beginFrame()
 */

TEST_F(RenderSurfaceTest, beginFrameAppliesChange) {
    EXPECT_CALL(*mDisplaySurface, beginFrame(true)).WillOnce(Return(NO_ERROR));

    EXPECT_EQ(NO_ERROR, mSurface.beginFrame(true));
}

/*
 * RenderSurface::prepareFrame()
 */

TEST_F(RenderSurfaceTest, prepareFrameHandlesMixedComposition) {
    EXPECT_CALL(*mDisplaySurface, prepareFrame(DisplaySurface::COMPOSITION_MIXED))
            .WillOnce(Return(NO_ERROR));

    mSurface.prepareFrame(true, true);
}

TEST_F(RenderSurfaceTest, prepareFrameHandlesOnlyGpuComposition) {
    EXPECT_CALL(*mDisplaySurface, prepareFrame(DisplaySurface::COMPOSITION_GPU))
            .WillOnce(Return(NO_ERROR));

    mSurface.prepareFrame(true, false);
}

TEST_F(RenderSurfaceTest, prepareFrameHandlesOnlyHwcComposition) {
    EXPECT_CALL(*mDisplaySurface, prepareFrame(DisplaySurface::COMPOSITION_HWC))
            .WillOnce(Return(NO_ERROR));

    mSurface.prepareFrame(false, true);
}

TEST_F(RenderSurfaceTest, prepareFrameHandlesNoComposition) {
    EXPECT_CALL(*mDisplaySurface, prepareFrame(DisplaySurface::COMPOSITION_HWC))
            .WillOnce(Return(NO_ERROR));

    mSurface.prepareFrame(false, false);
}

/*
 * RenderSurface::dequeueBuffer()
 */

TEST_F(RenderSurfaceTest, dequeueBufferObtainsABuffer) {
    sp<GraphicBuffer> buffer = new GraphicBuffer();

    EXPECT_CALL(*mNativeWindow, dequeueBuffer(_, _))
            .WillOnce(
                    DoAll(SetArgPointee<0>(buffer.get()), SetArgPointee<1>(-1), Return(NO_ERROR)));

    base::unique_fd fence;
    EXPECT_EQ(buffer.get(), mSurface.dequeueBuffer(&fence)->getBuffer().get());

    EXPECT_EQ(buffer.get(), mSurface.mutableTextureForTest()->getBuffer().get());
}

/*
 * RenderSurface::queueBuffer()
 */

TEST_F(RenderSurfaceTest, queueBufferHandlesNoClientComposition) {
    const auto buffer = std::make_shared<
            renderengine::ExternalTexture>(new GraphicBuffer(), mRenderEngine,
                                           renderengine::ExternalTexture::Usage::READABLE |
                                                   renderengine::ExternalTexture::Usage::WRITEABLE);
    mSurface.mutableTextureForTest() = buffer;

    impl::OutputCompositionState state;
    state.usesClientComposition = false;
    state.flipClientTarget = false;

    EXPECT_CALL(mDisplay, getState()).WillOnce(ReturnRef(state));
    EXPECT_CALL(*mDisplaySurface, advanceFrame()).Times(1);

    mSurface.queueBuffer(base::unique_fd());

    EXPECT_EQ(buffer.get(), mSurface.mutableTextureForTest().get());
}

TEST_F(RenderSurfaceTest, queueBufferHandlesClientComposition) {
    const auto buffer = std::make_shared<renderengine::ExternalTexture>(new GraphicBuffer(),
                                                                        mRenderEngine, false);
    mSurface.mutableTextureForTest() = buffer;

    impl::OutputCompositionState state;
    state.usesClientComposition = true;
    state.flipClientTarget = false;

    EXPECT_CALL(mDisplay, getState()).WillOnce(ReturnRef(state));
    EXPECT_CALL(*mNativeWindow, queueBuffer(buffer->getBuffer()->getNativeBuffer(), -1))
            .WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mDisplaySurface, advanceFrame()).Times(1);

    mSurface.queueBuffer(base::unique_fd());

    EXPECT_EQ(nullptr, mSurface.mutableTextureForTest().get());
}

TEST_F(RenderSurfaceTest, queueBufferHandlesFlipClientTargetRequest) {
    const auto buffer = std::make_shared<renderengine::ExternalTexture>(new GraphicBuffer(),
                                                                        mRenderEngine, false);
    mSurface.mutableTextureForTest() = buffer;

    impl::OutputCompositionState state;
    state.usesClientComposition = false;
    state.flipClientTarget = true;

    EXPECT_CALL(mDisplay, getState()).WillOnce(ReturnRef(state));
    EXPECT_CALL(*mNativeWindow, queueBuffer(buffer->getBuffer()->getNativeBuffer(), -1))
            .WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mDisplaySurface, advanceFrame()).Times(1);

    mSurface.queueBuffer(base::unique_fd());

    EXPECT_EQ(nullptr, mSurface.mutableTextureForTest().get());
}

TEST_F(RenderSurfaceTest, queueBufferHandlesFlipClientTargetRequestWithNoBufferYetDequeued) {
    sp<GraphicBuffer> buffer = new GraphicBuffer();

    impl::OutputCompositionState state;
    state.usesClientComposition = false;
    state.flipClientTarget = true;

    EXPECT_CALL(mDisplay, getState()).WillOnce(ReturnRef(state));
    EXPECT_CALL(*mNativeWindow, dequeueBuffer(_, _))
            .WillOnce(
                    DoAll(SetArgPointee<0>(buffer.get()), SetArgPointee<1>(-1), Return(NO_ERROR)));
    EXPECT_CALL(*mNativeWindow, queueBuffer(buffer->getNativeBuffer(), -1))
            .WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mDisplaySurface, advanceFrame()).Times(1);

    mSurface.queueBuffer(base::unique_fd());

    EXPECT_EQ(nullptr, mSurface.mutableTextureForTest().get());
}

TEST_F(RenderSurfaceTest, queueBufferHandlesNativeWindowQueueBufferFailureOnVirtualDisplay) {
    const auto buffer = std::make_shared<renderengine::ExternalTexture>(new GraphicBuffer(),
                                                                        mRenderEngine, false);
    mSurface.mutableTextureForTest() = buffer;

    impl::OutputCompositionState state;
    state.usesClientComposition = true;

    EXPECT_CALL(mDisplay, getState()).WillOnce(ReturnRef(state));
    EXPECT_CALL(*mNativeWindow, queueBuffer(buffer->getBuffer()->getNativeBuffer(), -1))
            .WillOnce(Return(INVALID_OPERATION));
    EXPECT_CALL(mDisplay, isVirtual()).WillOnce(Return(true));
    EXPECT_CALL(*mNativeWindow, cancelBuffer(buffer->getBuffer()->getNativeBuffer(), -1))
            .WillOnce(Return(NO_ERROR));
    EXPECT_CALL(*mDisplaySurface, advanceFrame()).Times(1);

    mSurface.queueBuffer(base::unique_fd());

    EXPECT_EQ(nullptr, mSurface.mutableTextureForTest().get());
}

/*
 * RenderSurface::onPresentDisplayCompleted()
 */

TEST_F(RenderSurfaceTest, onPresentDisplayCompletedForwardsSignal) {
    EXPECT_CALL(*mDisplaySurface, onFrameCommitted()).Times(1);

    mSurface.onPresentDisplayCompleted();
}

/*
 * RenderSurface::flip()
 */

TEST_F(RenderSurfaceTest, flipForwardsSignal) {
    mSurface.setPageFlipCountForTest(500);

    mSurface.flip();

    EXPECT_EQ(501u, mSurface.getPageFlipCount());
}

} // namespace
} // namespace android::compositionengine
