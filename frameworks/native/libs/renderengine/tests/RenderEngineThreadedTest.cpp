/*
 * Copyright 2020 The Android Open Source Project
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

#include <cutils/properties.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <renderengine/mock/RenderEngine.h>
#include "../threaded/RenderEngineThreaded.h"

namespace android {

using testing::_;
using testing::Eq;
using testing::Mock;
using testing::Return;

struct RenderEngineThreadedTest : public ::testing::Test {
    ~RenderEngineThreadedTest() {}

    void SetUp() override {
        mThreadedRE = renderengine::threaded::RenderEngineThreaded::create(
                [this]() { return std::unique_ptr<renderengine::RenderEngine>(mRenderEngine); },
                renderengine::RenderEngine::RenderEngineType::THREADED);
    }

    std::unique_ptr<renderengine::threaded::RenderEngineThreaded> mThreadedRE;
    renderengine::mock::RenderEngine* mRenderEngine = new renderengine::mock::RenderEngine();
};

TEST_F(RenderEngineThreadedTest, dump) {
    std::string testString = "XYZ";
    EXPECT_CALL(*mRenderEngine, dump(_));
    mThreadedRE->dump(testString);
}

TEST_F(RenderEngineThreadedTest, primeCache) {
    EXPECT_CALL(*mRenderEngine, primeCache());
    mThreadedRE->primeCache();
    // need to call ANY synchronous function after primeCache to ensure that primeCache has
    // completed asynchronously before the test completes execution.
    mThreadedRE->getContextPriority();
}

TEST_F(RenderEngineThreadedTest, genTextures) {
    uint32_t texName;
    EXPECT_CALL(*mRenderEngine, genTextures(1, &texName));
    mThreadedRE->genTextures(1, &texName);
}

TEST_F(RenderEngineThreadedTest, deleteTextures) {
    uint32_t texName;
    EXPECT_CALL(*mRenderEngine, deleteTextures(1, &texName));
    mThreadedRE->deleteTextures(1, &texName);
}

TEST_F(RenderEngineThreadedTest, getMaxTextureSize_returns20) {
    size_t size = 20;
    EXPECT_CALL(*mRenderEngine, getMaxTextureSize()).WillOnce(Return(size));
    size_t result = mThreadedRE->getMaxTextureSize();
    ASSERT_EQ(size, result);
}

TEST_F(RenderEngineThreadedTest, getMaxTextureSize_returns0) {
    size_t size = 0;
    EXPECT_CALL(*mRenderEngine, getMaxTextureSize()).WillOnce(Return(size));
    size_t result = mThreadedRE->getMaxTextureSize();
    ASSERT_EQ(size, result);
}

TEST_F(RenderEngineThreadedTest, getMaxViewportDims_returns20) {
    size_t dims = 20;
    EXPECT_CALL(*mRenderEngine, getMaxViewportDims()).WillOnce(Return(dims));
    size_t result = mThreadedRE->getMaxViewportDims();
    ASSERT_EQ(dims, result);
}

TEST_F(RenderEngineThreadedTest, getMaxViewportDims_returns0) {
    size_t dims = 0;
    EXPECT_CALL(*mRenderEngine, getMaxViewportDims()).WillOnce(Return(dims));
    size_t result = mThreadedRE->getMaxViewportDims();
    ASSERT_EQ(dims, result);
}

TEST_F(RenderEngineThreadedTest, isProtected_returnsFalse) {
    EXPECT_CALL(*mRenderEngine, isProtected()).WillOnce(Return(false));
    status_t result = mThreadedRE->isProtected();
    ASSERT_EQ(false, result);
}

TEST_F(RenderEngineThreadedTest, isProtected_returnsTrue) {
    EXPECT_CALL(*mRenderEngine, isProtected()).WillOnce(Return(true));
    size_t result = mThreadedRE->isProtected();
    ASSERT_EQ(true, result);
}

TEST_F(RenderEngineThreadedTest, supportsProtectedContent_returnsFalse) {
    EXPECT_CALL(*mRenderEngine, supportsProtectedContent()).WillOnce(Return(false));
    status_t result = mThreadedRE->supportsProtectedContent();
    ASSERT_EQ(false, result);
}

TEST_F(RenderEngineThreadedTest, supportsProtectedContent_returnsTrue) {
    EXPECT_CALL(*mRenderEngine, supportsProtectedContent()).WillOnce(Return(true));
    status_t result = mThreadedRE->supportsProtectedContent();
    ASSERT_EQ(true, result);
}

TEST_F(RenderEngineThreadedTest, useProtectedContext) {
    EXPECT_CALL(*mRenderEngine, useProtectedContext(true));
    auto& ipExpect = EXPECT_CALL(*mRenderEngine, isProtected()).WillOnce(Return(false));
    EXPECT_CALL(*mRenderEngine, supportsProtectedContent()).WillOnce(Return(true));
    EXPECT_CALL(*mRenderEngine, isProtected()).After(ipExpect).WillOnce(Return(true));

    mThreadedRE->useProtectedContext(true);
    ASSERT_EQ(true, mThreadedRE->isProtected());

    // call ANY synchronous function to ensure that useProtectedContext has completed.
    mThreadedRE->getContextPriority();
    ASSERT_EQ(true, mThreadedRE->isProtected());
}

TEST_F(RenderEngineThreadedTest, useProtectedContext_quickReject) {
    EXPECT_CALL(*mRenderEngine, useProtectedContext(false)).Times(0);
    EXPECT_CALL(*mRenderEngine, isProtected()).WillOnce(Return(false));
    mThreadedRE->useProtectedContext(false);
    // call ANY synchronous function to ensure that useProtectedContext has completed.
    mThreadedRE->getContextPriority();
}

TEST_F(RenderEngineThreadedTest, PostRenderCleanup_skipped) {
    EXPECT_CALL(*mRenderEngine, canSkipPostRenderCleanup()).WillOnce(Return(true));
    EXPECT_CALL(*mRenderEngine, cleanupPostRender()).Times(0);
    mThreadedRE->cleanupPostRender();

    // call ANY synchronous function to ensure that cleanupPostRender has completed.
    mThreadedRE->getContextPriority();
}

TEST_F(RenderEngineThreadedTest, PostRenderCleanup_notSkipped) {
    EXPECT_CALL(*mRenderEngine, canSkipPostRenderCleanup()).WillOnce(Return(false));
    EXPECT_CALL(*mRenderEngine, cleanupPostRender()).WillOnce(Return());
    mThreadedRE->cleanupPostRender();

    // call ANY synchronous function to ensure that cleanupPostRender has completed.
    mThreadedRE->getContextPriority();
}

TEST_F(RenderEngineThreadedTest, supportsBackgroundBlur_returnsFalse) {
    EXPECT_CALL(*mRenderEngine, supportsBackgroundBlur()).WillOnce(Return(false));
    status_t result = mThreadedRE->supportsBackgroundBlur();
    ASSERT_EQ(false, result);
}

TEST_F(RenderEngineThreadedTest, supportsBackgroundBlur_returnsTrue) {
    EXPECT_CALL(*mRenderEngine, supportsBackgroundBlur()).WillOnce(Return(true));
    status_t result = mThreadedRE->supportsBackgroundBlur();
    ASSERT_EQ(true, result);
}
TEST_F(RenderEngineThreadedTest, drawLayers) {
    renderengine::DisplaySettings settings;
    std::vector<const renderengine::LayerSettings*> layers;
    std::shared_ptr<renderengine::ExternalTexture> buffer = std::make_shared<
            renderengine::ExternalTexture>(new GraphicBuffer(), *mRenderEngine,
                                           renderengine::ExternalTexture::Usage::READABLE |
                                                   renderengine::ExternalTexture::Usage::WRITEABLE);
    base::unique_fd bufferFence;
    base::unique_fd drawFence;

    EXPECT_CALL(*mRenderEngine, drawLayers)
            .WillOnce([](const renderengine::DisplaySettings&,
                         const std::vector<const renderengine::LayerSettings*>&,
                         const std::shared_ptr<renderengine::ExternalTexture>&, const bool,
                         base::unique_fd&&, base::unique_fd*) -> status_t { return NO_ERROR; });

    status_t result = mThreadedRE->drawLayers(settings, layers, buffer, false,
                                              std::move(bufferFence), &drawFence);
    ASSERT_EQ(NO_ERROR, result);
}

} // namespace android
