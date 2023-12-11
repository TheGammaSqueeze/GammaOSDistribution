/*
 * Copyright (C) 2019 The Android Open Source Project
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

// TODO(b/129481165): remove the #pragma below and fix conversion issues
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wconversion"

#include "LayerTransactionTest.h"

namespace android {

using android::hardware::graphics::common::V1_1::BufferUsage;

::testing::Environment* const binderEnv =
        ::testing::AddGlobalTestEnvironment(new BinderEnvironment());

class LayerUpdateTest : public LayerTransactionTest {
protected:
    virtual void SetUp() {
        LayerTransactionTest::SetUp();
        ASSERT_EQ(NO_ERROR, mClient->initCheck());

        const auto display = SurfaceComposerClient::getInternalDisplayToken();
        ASSERT_FALSE(display == nullptr);

        ui::DisplayMode mode;
        ASSERT_EQ(NO_ERROR, SurfaceComposerClient::getActiveDisplayMode(display, &mode));
        const ui::Size& resolution = mode.resolution;

        // Background surface
        mBGSurfaceControl = createLayer(String8("BG Test Surface"), resolution.getWidth(),
                                        resolution.getHeight(), 0);
        ASSERT_TRUE(mBGSurfaceControl != nullptr);
        ASSERT_TRUE(mBGSurfaceControl->isValid());
        TransactionUtils::fillSurfaceRGBA8(mBGSurfaceControl, 63, 63, 195);

        // Foreground surface
        mFGSurfaceControl = createLayer(String8("FG Test Surface"), 64, 64, 0);

        ASSERT_TRUE(mFGSurfaceControl != nullptr);
        ASSERT_TRUE(mFGSurfaceControl->isValid());

        TransactionUtils::fillSurfaceRGBA8(mFGSurfaceControl, 195, 63, 63);

        // Synchronization surface
        mSyncSurfaceControl = createLayer(String8("Sync Test Surface"), 1, 1, 0);
        ASSERT_TRUE(mSyncSurfaceControl != nullptr);
        ASSERT_TRUE(mSyncSurfaceControl->isValid());

        TransactionUtils::fillSurfaceRGBA8(mSyncSurfaceControl, 31, 31, 31);

        asTransaction([&](Transaction& t) {
            t.setDisplayLayerStack(display, 0);

            t.setLayer(mBGSurfaceControl, INT32_MAX - 2).show(mBGSurfaceControl);

            t.setLayer(mFGSurfaceControl, INT32_MAX - 1)
                    .setPosition(mFGSurfaceControl, 64, 64)
                    .show(mFGSurfaceControl);

            t.setLayer(mSyncSurfaceControl, INT32_MAX - 1)
                    .setPosition(mSyncSurfaceControl, resolution.getWidth() - 2,
                                 resolution.getHeight() - 2)
                    .show(mSyncSurfaceControl);
        });
    }

    virtual void TearDown() {
        LayerTransactionTest::TearDown();
        mBGSurfaceControl = 0;
        mFGSurfaceControl = 0;
        mSyncSurfaceControl = 0;
    }

    void waitForPostedBuffers() {
        // Since the sync surface is in synchronous mode (i.e. double buffered)
        // posting three buffers to it should ensure that at least two
        // SurfaceFlinger::handlePageFlip calls have been made, which should
        // guaranteed that a buffer posted to another Surface has been retired.
        TransactionUtils::fillSurfaceRGBA8(mSyncSurfaceControl, 31, 31, 31);
        TransactionUtils::fillSurfaceRGBA8(mSyncSurfaceControl, 31, 31, 31);
        TransactionUtils::fillSurfaceRGBA8(mSyncSurfaceControl, 31, 31, 31);
    }

    sp<SurfaceControl> mBGSurfaceControl;
    sp<SurfaceControl> mFGSurfaceControl;

    // This surface is used to ensure that the buffers posted to
    // mFGSurfaceControl have been picked up by SurfaceFlinger.
    sp<SurfaceControl> mSyncSurfaceControl;
};

class GeometryLatchingTest : public LayerUpdateTest {
protected:
    void EXPECT_INITIAL_STATE(const char* trace) {
        SCOPED_TRACE(trace);
        ScreenCapture::captureScreen(&sc);
        // We find the leading edge of the FG surface.
        sc->expectFGColor(127, 127);
        sc->expectBGColor(128, 128);
    }

    void lockAndFillFGBuffer() {
        TransactionUtils::fillSurfaceRGBA8(mFGSurfaceControl, 195, 63, 63, false);
    }

    void unlockFGBuffer() {
        sp<Surface> s = mFGSurfaceControl->getSurface();
        ASSERT_EQ(NO_ERROR, s->unlockAndPost());
        waitForPostedBuffers();
    }

    void completeFGResize() {
        TransactionUtils::fillSurfaceRGBA8(mFGSurfaceControl, 195, 63, 63);
        waitForPostedBuffers();
    }

    std::unique_ptr<ScreenCapture> sc;
};

class CropLatchingTest : public GeometryLatchingTest {
protected:
    void EXPECT_CROPPED_STATE(const char* trace) {
        SCOPED_TRACE(trace);
        ScreenCapture::captureScreen(&sc);
        // The edge should be moved back one pixel by our crop.
        sc->expectFGColor(126, 126);
        sc->expectBGColor(127, 127);
        sc->expectBGColor(128, 128);
    }

    void EXPECT_RESIZE_STATE(const char* trace) {
        SCOPED_TRACE(trace);
        ScreenCapture::captureScreen(&sc);
        // The FG is now resized too 128,128 at 64,64
        sc->expectFGColor(64, 64);
        sc->expectFGColor(191, 191);
        sc->expectBGColor(192, 192);
    }
};

TEST_F(LayerUpdateTest, LayerWithNoBuffersResizesImmediately) {
    std::unique_ptr<ScreenCapture> sc;

    sp<SurfaceControl> childNoBuffer =
            createSurface(mClient, "Bufferless child", 0 /* buffer width */, 0 /* buffer height */,
                          PIXEL_FORMAT_RGBA_8888, 0, mFGSurfaceControl.get());
    sp<SurfaceControl> childBuffer = createSurface(mClient, "Buffered child", 20, 20,
                                                   PIXEL_FORMAT_RGBA_8888, 0, childNoBuffer.get());
    TransactionUtils::fillSurfaceRGBA8(childBuffer, 200, 200, 200);
    SurfaceComposerClient::Transaction{}
            .setCrop(childNoBuffer, Rect(0, 0, 10, 10))
            .show(childNoBuffer)
            .show(childBuffer)
            .apply(true);
    {
        ScreenCapture::captureScreen(&sc);
        sc->expectChildColor(73, 73);
        sc->expectFGColor(74, 74);
    }
    SurfaceComposerClient::Transaction{}.setCrop(childNoBuffer, Rect(0, 0, 20, 20)).apply(true);
    {
        ScreenCapture::captureScreen(&sc);
        sc->expectChildColor(73, 73);
        sc->expectChildColor(74, 74);
    }
}

TEST_F(LayerUpdateTest, MergingTransactions) {
    std::unique_ptr<ScreenCapture> sc;
    {
        SCOPED_TRACE("before move");
        ScreenCapture::captureScreen(&sc);
        sc->expectBGColor(0, 12);
        sc->expectFGColor(75, 75);
        sc->expectBGColor(145, 145);
    }

    Transaction t1, t2;
    t1.setPosition(mFGSurfaceControl, 128, 128);
    t2.setPosition(mFGSurfaceControl, 0, 0);
    // We expect that the position update from t2 now
    // overwrites the position update from t1.
    t1.merge(std::move(t2));
    t1.apply();

    {
        ScreenCapture::captureScreen(&sc);
        sc->expectFGColor(1, 1);
    }
}

TEST_F(LayerUpdateTest, MergingTransactionFlags) {
    Transaction().hide(mFGSurfaceControl).apply();
    std::unique_ptr<ScreenCapture> sc;
    {
        SCOPED_TRACE("before merge");
        ScreenCapture::captureScreen(&sc);
        sc->expectBGColor(0, 12);
        sc->expectBGColor(75, 75);
        sc->expectBGColor(145, 145);
    }

    Transaction t1, t2;
    t1.show(mFGSurfaceControl);
    t2.setFlags(mFGSurfaceControl, 0 /* flags */, layer_state_t::eLayerSecure /* mask */);
    t1.merge(std::move(t2));
    t1.apply();

    {
        SCOPED_TRACE("after merge");
        ScreenCapture::captureScreen(&sc);
        sc->expectFGColor(75, 75);
    }
}

class ChildLayerTest : public LayerUpdateTest {
protected:
    void SetUp() override {
        LayerUpdateTest::SetUp();
        mChild = createSurface(mClient, "Child surface", 10, 15, PIXEL_FORMAT_RGBA_8888, 0,
                               mFGSurfaceControl.get());
        TransactionUtils::fillSurfaceRGBA8(mChild, 200, 200, 200);
        waitForPostedBuffers();

        {
            SCOPED_TRACE("before anything");
            mCapture = screenshot();
            mCapture->expectChildColor(64, 64);
        }
    }
    void TearDown() override {
        LayerUpdateTest::TearDown();
        mChild = 0;
    }

    sp<SurfaceControl> mChild;
    std::unique_ptr<ScreenCapture> mCapture;
};

TEST_F(ChildLayerTest, ChildLayerPositioning) {
    asTransaction([&](Transaction& t) {
        t.show(mChild);
        t.setPosition(mChild, 10, 10);
        t.setPosition(mFGSurfaceControl, 64, 64);
    });

    {
        mCapture = screenshot();
        // Top left of foreground must now be visible
        mCapture->expectFGColor(64, 64);
        // But 10 pixels in we should see the child surface
        mCapture->expectChildColor(74, 74);
        // And 10 more pixels we should be back to the foreground surface
        mCapture->expectFGColor(84, 84);
    }

    asTransaction([&](Transaction& t) { t.setPosition(mFGSurfaceControl, 0, 0); });

    {
        mCapture = screenshot();
        // Top left of foreground should now be at 0, 0
        mCapture->expectFGColor(0, 0);
        // But 10 pixels in we should see the child surface
        mCapture->expectChildColor(10, 10);
        // And 10 more pixels we should be back to the foreground surface
        mCapture->expectFGColor(20, 20);
    }
}

TEST_F(ChildLayerTest, ChildLayerCropping) {
    asTransaction([&](Transaction& t) {
        t.show(mChild);
        t.setPosition(mChild, 0, 0);
        t.setPosition(mFGSurfaceControl, 0, 0);
        t.setCrop(mFGSurfaceControl, Rect(0, 0, 5, 5));
    });

    {
        mCapture = screenshot();
        mCapture->expectChildColor(0, 0);
        mCapture->expectChildColor(4, 4);
        mCapture->expectBGColor(5, 5);
    }
}

TEST_F(ChildLayerTest, ChildLayerConstraints) {
    asTransaction([&](Transaction& t) {
        t.show(mChild);
        t.setPosition(mFGSurfaceControl, 0, 0);
        t.setPosition(mChild, 63, 63);
    });

    {
        mCapture = screenshot();
        mCapture->expectFGColor(0, 0);
        // Last pixel in foreground should now be the child.
        mCapture->expectChildColor(63, 63);
        // But the child should be constrained and the next pixel
        // must be the background
        mCapture->expectBGColor(64, 64);
    }
}

TEST_F(ChildLayerTest, ChildLayerScaling) {
    asTransaction([&](Transaction& t) { t.setPosition(mFGSurfaceControl, 0, 0); });

    // Find the boundary between the parent and child
    {
        mCapture = screenshot();
        mCapture->expectChildColor(9, 9);
        mCapture->expectFGColor(10, 10);
    }

    asTransaction([&](Transaction& t) { t.setMatrix(mFGSurfaceControl, 2.0, 0, 0, 2.0); });

    // The boundary should be twice as far from the origin now.
    // The pixels from the last test should all be child now
    {
        mCapture = screenshot();
        mCapture->expectChildColor(9, 9);
        mCapture->expectChildColor(10, 10);
        mCapture->expectChildColor(19, 19);
        mCapture->expectFGColor(20, 20);
    }
}

// A child with a scale transform should be cropped by its parent bounds.
TEST_F(ChildLayerTest, ChildLayerScalingCroppedByParent) {
    asTransaction([&](Transaction& t) {
        t.setPosition(mFGSurfaceControl, 0, 0);
        t.setPosition(mChild, 0, 0);
    });

    // Find the boundary between the parent and child.
    {
        mCapture = screenshot();
        mCapture->expectChildColor(0, 0);
        mCapture->expectChildColor(9, 9);
        mCapture->expectFGColor(10, 10);
    }

    asTransaction([&](Transaction& t) { t.setMatrix(mChild, 10.0, 0, 0, 10.0); });

    // The child should fill its parent bounds and be cropped by it.
    {
        mCapture = screenshot();
        mCapture->expectChildColor(0, 0);
        mCapture->expectChildColor(63, 63);
        mCapture->expectBGColor(64, 64);
    }
}

TEST_F(ChildLayerTest, ChildLayerAlpha) {
    TransactionUtils::fillSurfaceRGBA8(mBGSurfaceControl, 0, 0, 254);
    TransactionUtils::fillSurfaceRGBA8(mFGSurfaceControl, 254, 0, 0);
    TransactionUtils::fillSurfaceRGBA8(mChild, 0, 254, 0);
    waitForPostedBuffers();

    asTransaction([&](Transaction& t) {
        t.show(mChild);
        t.setPosition(mChild, 0, 0);
        t.setPosition(mFGSurfaceControl, 0, 0);
    });

    {
        mCapture = screenshot();
        // Unblended child color
        mCapture->checkPixel(0, 0, 0, 254, 0);
    }

    asTransaction([&](Transaction& t) { t.setAlpha(mChild, 0.5); });

    {
        mCapture = screenshot();
        // Child and BG blended. See b/175352694 for tolerance.
        mCapture->expectColor(Rect(0, 0, 1, 1), Color{127, 127, 0, 255}, 1);
    }

    asTransaction([&](Transaction& t) { t.setAlpha(mFGSurfaceControl, 0.5); });

    {
        mCapture = screenshot();
        // Child and BG blended. See b/175352694 for tolerance.
        mCapture->expectColor(Rect(0, 0, 1, 1), Color{95, 64, 95, 255}, 1);
    }
}

TEST_F(ChildLayerTest, ChildrenSurviveParentDestruction) {
    sp<SurfaceControl> mGrandChild =
            createSurface(mClient, "Grand Child", 10, 10, PIXEL_FORMAT_RGBA_8888, 0, mChild.get());
    TransactionUtils::fillSurfaceRGBA8(mGrandChild, 111, 111, 111);

    {
        SCOPED_TRACE("Grandchild visible");
        ScreenCapture::captureScreen(&mCapture);
        mCapture->checkPixel(64, 64, 111, 111, 111);
    }

    Transaction().reparent(mChild, nullptr).apply();
    mChild.clear();

    {
        SCOPED_TRACE("After destroying child");
        ScreenCapture::captureScreen(&mCapture);
        mCapture->expectFGColor(64, 64);
    }

    asTransaction([&](Transaction& t) { t.reparent(mGrandChild, mFGSurfaceControl); });

    {
        SCOPED_TRACE("After reparenting grandchild");
        ScreenCapture::captureScreen(&mCapture);
        mCapture->checkPixel(64, 64, 111, 111, 111);
    }
}

TEST_F(ChildLayerTest, ChildrenRelativeZSurvivesParentDestruction) {
    sp<SurfaceControl> mGrandChild =
            createSurface(mClient, "Grand Child", 10, 10, PIXEL_FORMAT_RGBA_8888, 0, mChild.get());
    TransactionUtils::fillSurfaceRGBA8(mGrandChild, 111, 111, 111);

    // draw grand child behind the foreground surface
    asTransaction([&](Transaction& t) { t.setRelativeLayer(mGrandChild, mFGSurfaceControl, -1); });

    {
        SCOPED_TRACE("Child visible");
        ScreenCapture::captureScreen(&mCapture);
        mCapture->checkPixel(64, 64, 200, 200, 200);
    }

    asTransaction([&](Transaction& t) {
        t.reparent(mChild, nullptr);
        t.reparent(mGrandChild, mFGSurfaceControl);
    });

    {
        SCOPED_TRACE("foreground visible reparenting grandchild");
        ScreenCapture::captureScreen(&mCapture);
        mCapture->checkPixel(64, 64, 195, 63, 63);
    }
}

TEST_F(ChildLayerTest, Reparent) {
    asTransaction([&](Transaction& t) {
        t.show(mChild);
        t.setPosition(mChild, 10, 10);
        t.setPosition(mFGSurfaceControl, 64, 64);
    });

    {
        mCapture = screenshot();
        // Top left of foreground must now be visible
        mCapture->expectFGColor(64, 64);
        // But 10 pixels in we should see the child surface
        mCapture->expectChildColor(74, 74);
        // And 10 more pixels we should be back to the foreground surface
        mCapture->expectFGColor(84, 84);
    }

    asTransaction([&](Transaction& t) { t.reparent(mChild, mBGSurfaceControl); });

    {
        mCapture = screenshot();
        mCapture->expectFGColor(64, 64);
        // In reparenting we should have exposed the entire foreground surface.
        mCapture->expectFGColor(74, 74);
        // And the child layer should now begin at 10, 10 (since the BG
        // layer is at (0, 0)).
        mCapture->expectBGColor(9, 9);
        mCapture->expectChildColor(10, 10);
    }
}

TEST_F(ChildLayerTest, ReparentToNoParent) {
    asTransaction([&](Transaction& t) {
        t.show(mChild);
        t.setPosition(mChild, 10, 10);
        t.setPosition(mFGSurfaceControl, 64, 64);
    });

    {
        mCapture = screenshot();
        // Top left of foreground must now be visible
        mCapture->expectFGColor(64, 64);
        // But 10 pixels in we should see the child surface
        mCapture->expectChildColor(74, 74);
        // And 10 more pixels we should be back to the foreground surface
        mCapture->expectFGColor(84, 84);
    }
    asTransaction([&](Transaction& t) { t.reparent(mChild, nullptr); });
    {
        mCapture = screenshot();
        // The surface should now be offscreen.
        mCapture->expectFGColor(64, 64);
        mCapture->expectFGColor(74, 74);
        mCapture->expectFGColor(84, 84);
    }
}

TEST_F(ChildLayerTest, ReparentFromNoParent) {
    sp<SurfaceControl> newSurface = createLayer(String8("New Surface"), 10, 10, 0);
    ASSERT_TRUE(newSurface != nullptr);
    ASSERT_TRUE(newSurface->isValid());

    TransactionUtils::fillSurfaceRGBA8(newSurface, 63, 195, 63);
    asTransaction([&](Transaction& t) {
        t.hide(mChild);
        t.show(newSurface);
        t.setPosition(newSurface, 10, 10);
        t.setLayer(newSurface, INT32_MAX - 2);
        t.setPosition(mFGSurfaceControl, 64, 64);
    });

    {
        mCapture = screenshot();
        // Top left of foreground must now be visible
        mCapture->expectFGColor(64, 64);
        // At 10, 10 we should see the new surface
        mCapture->checkPixel(10, 10, 63, 195, 63);
    }

    asTransaction([&](Transaction& t) { t.reparent(newSurface, mFGSurfaceControl); });

    {
        mCapture = screenshot();
        // newSurface will now be a child of mFGSurface so it will be 10, 10 offset from
        // mFGSurface, putting it at 74, 74.
        mCapture->expectFGColor(64, 64);
        mCapture->checkPixel(74, 74, 63, 195, 63);
        mCapture->expectFGColor(84, 84);
    }
}

TEST_F(ChildLayerTest, NestedChildren) {
    sp<SurfaceControl> grandchild = createSurface(mClient, "Grandchild surface", 10, 10,
                                                  PIXEL_FORMAT_RGBA_8888, 0, mChild.get());
    TransactionUtils::fillSurfaceRGBA8(grandchild, 50, 50, 50);

    {
        mCapture = screenshot();
        // Expect the grandchild to begin at 64, 64 because it's a child of mChild layer
        // which begins at 64, 64
        mCapture->checkPixel(64, 64, 50, 50, 50);
    }
}

TEST_F(ChildLayerTest, ChildLayerRelativeLayer) {
    sp<SurfaceControl> relative = createLayer(String8("Relative surface"), 128, 128, 0);
    TransactionUtils::fillSurfaceRGBA8(relative, 255, 255, 255);

    Transaction t;
    t.setLayer(relative, INT32_MAX)
            .setRelativeLayer(mChild, relative, 1)
            .setPosition(mFGSurfaceControl, 0, 0)
            .apply(true);

    // We expect that the child should have been elevated above our
    // INT_MAX layer even though it's not a child of it.
    {
        mCapture = screenshot();
        mCapture->expectChildColor(0, 0);
        mCapture->expectChildColor(9, 9);
        mCapture->checkPixel(10, 10, 255, 255, 255);
    }
}

class BoundlessLayerTest : public LayerUpdateTest {
protected:
    std::unique_ptr<ScreenCapture> mCapture;
};

// Verify setting a size on a buffer layer has no effect.
TEST_F(BoundlessLayerTest, BufferLayerIgnoresSize) {
    sp<SurfaceControl> bufferLayer =
            createSurface(mClient, "BufferLayer", 45, 45, PIXEL_FORMAT_RGBA_8888, 0,
                          mFGSurfaceControl.get());
    ASSERT_TRUE(bufferLayer->isValid());
    ASSERT_NO_FATAL_FAILURE(fillBufferQueueLayerColor(bufferLayer, Color::BLACK, 30, 30));
    asTransaction([&](Transaction& t) { t.show(bufferLayer); });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Foreground Surface bounds must be color layer
        mCapture->expectColor(Rect(64, 64, 94, 94), Color::BLACK);
        // Buffer layer should not extend past buffer bounds
        mCapture->expectFGColor(95, 95);
    }
}

// Verify a boundless color layer will fill its parent bounds. The parent has a buffer size
// which will crop the color layer.
TEST_F(BoundlessLayerTest, BoundlessColorLayerFillsParentBufferBounds) {
    sp<SurfaceControl> colorLayer =
            createSurface(mClient, "ColorLayer", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          ISurfaceComposerClient::eFXSurfaceEffect, mFGSurfaceControl.get());
    ASSERT_TRUE(colorLayer->isValid());
    asTransaction([&](Transaction& t) {
        t.setColor(colorLayer, half3{0, 0, 0});
        t.show(colorLayer);
    });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Foreground Surface bounds must be color layer
        mCapture->expectColor(Rect(64, 64, 128, 128), Color::BLACK);
        // Color layer should not extend past foreground bounds
        mCapture->expectBGColor(129, 129);
    }
}

// Verify a boundless color layer will fill its parent bounds. The parent has no buffer but has
// a crop which will be used to crop the color layer.
TEST_F(BoundlessLayerTest, BoundlessColorLayerFillsParentCropBounds) {
    sp<SurfaceControl> cropLayer = createSurface(mClient, "CropLayer", 0, 0, PIXEL_FORMAT_RGBA_8888,
                                                 0 /* flags */, mFGSurfaceControl.get());
    ASSERT_TRUE(cropLayer->isValid());
    sp<SurfaceControl> colorLayer =
            createSurface(mClient, "ColorLayer", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          ISurfaceComposerClient::eFXSurfaceEffect, cropLayer.get());
    ASSERT_TRUE(colorLayer->isValid());
    asTransaction([&](Transaction& t) {
        t.setCrop(cropLayer, Rect(5, 5, 10, 10));
        t.setColor(colorLayer, half3{0, 0, 0});
        t.show(cropLayer);
        t.show(colorLayer);
    });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Top left of foreground must now be visible
        mCapture->expectFGColor(64, 64);
        // 5 pixels from the foreground we should see the child surface
        mCapture->expectColor(Rect(69, 69, 74, 74), Color::BLACK);
        // 10 pixels from the foreground we should be back to the foreground surface
        mCapture->expectFGColor(74, 74);
    }
}

// Verify for boundless layer with no children, their transforms have no effect.
TEST_F(BoundlessLayerTest, BoundlessColorLayerTransformHasNoEffect) {
    sp<SurfaceControl> colorLayer =
            createSurface(mClient, "ColorLayer", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          ISurfaceComposerClient::eFXSurfaceEffect, mFGSurfaceControl.get());
    ASSERT_TRUE(colorLayer->isValid());
    asTransaction([&](Transaction& t) {
        t.setPosition(colorLayer, 320, 320);
        t.setMatrix(colorLayer, 2, 0, 0, 2);
        t.setColor(colorLayer, half3{0, 0, 0});
        t.show(colorLayer);
    });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Foreground Surface bounds must be color layer
        mCapture->expectColor(Rect(64, 64, 128, 128), Color::BLACK);
        // Color layer should not extend past foreground bounds
        mCapture->expectBGColor(129, 129);
    }
}

// Verify for boundless layer with children, their transforms have an effect.
TEST_F(BoundlessLayerTest, IntermediateBoundlessLayerCanSetTransform) {
    sp<SurfaceControl> boundlessLayerRightShift =
            createSurface(mClient, "BoundlessLayerRightShift", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          0 /* flags */, mFGSurfaceControl.get());
    ASSERT_TRUE(boundlessLayerRightShift->isValid());
    sp<SurfaceControl> boundlessLayerDownShift =
            createSurface(mClient, "BoundlessLayerLeftShift", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          0 /* flags */, boundlessLayerRightShift.get());
    ASSERT_TRUE(boundlessLayerDownShift->isValid());
    sp<SurfaceControl> colorLayer =
            createSurface(mClient, "ColorLayer", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          ISurfaceComposerClient::eFXSurfaceEffect, boundlessLayerDownShift.get());
    ASSERT_TRUE(colorLayer->isValid());
    asTransaction([&](Transaction& t) {
        t.setPosition(boundlessLayerRightShift, 32, 0);
        t.show(boundlessLayerRightShift);
        t.setPosition(boundlessLayerDownShift, 0, 32);
        t.show(boundlessLayerDownShift);
        t.setCrop(colorLayer, Rect(0, 0, 64, 64));
        t.setColor(colorLayer, half3{0, 0, 0});
        t.show(colorLayer);
    });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Top left of foreground must now be visible
        mCapture->expectFGColor(64, 64);
        // Foreground Surface bounds must be color layer
        mCapture->expectColor(Rect(96, 96, 128, 128), Color::BLACK);
        // Color layer should not extend past foreground bounds
        mCapture->expectBGColor(129, 129);
    }
}

// Verify child layers do not get clipped if they temporarily move into the negative
// coordinate space as the result of an intermediate transformation.
TEST_F(BoundlessLayerTest, IntermediateBoundlessLayerDoNotCrop) {
    sp<SurfaceControl> boundlessLayer =
            mClient->createSurface(String8("BoundlessLayer"), 0, 0, PIXEL_FORMAT_RGBA_8888,
                                   0 /* flags */, mFGSurfaceControl->getHandle());
    ASSERT_TRUE(boundlessLayer != nullptr);
    ASSERT_TRUE(boundlessLayer->isValid());
    sp<SurfaceControl> colorLayer =
            mClient->createSurface(String8("ColorLayer"), 0, 0, PIXEL_FORMAT_RGBA_8888,
                                   ISurfaceComposerClient::eFXSurfaceEffect,
                                   boundlessLayer->getHandle());
    ASSERT_TRUE(colorLayer != nullptr);
    ASSERT_TRUE(colorLayer->isValid());
    asTransaction([&](Transaction& t) {
        // shift child layer off bounds. If this layer was not boundless, we will
        // expect the child layer to be cropped.
        t.setPosition(boundlessLayer, 32, 32);
        t.show(boundlessLayer);
        t.setCrop(colorLayer, Rect(0, 0, 64, 64));
        // undo shift by parent
        t.setPosition(colorLayer, -32, -32);
        t.setColor(colorLayer, half3{0, 0, 0});
        t.show(colorLayer);
    });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Foreground Surface bounds must be color layer
        mCapture->expectColor(Rect(64, 64, 128, 128), Color::BLACK);
        // Color layer should not extend past foreground bounds
        mCapture->expectBGColor(129, 129);
    }
}

// Verify for boundless root layers with children, their transforms have an effect.
TEST_F(BoundlessLayerTest, RootBoundlessLayerCanSetTransform) {
    sp<SurfaceControl> rootBoundlessLayer = createSurface(mClient, "RootBoundlessLayer", 0, 0,
                                                          PIXEL_FORMAT_RGBA_8888, 0 /* flags */);
    ASSERT_TRUE(rootBoundlessLayer->isValid());
    sp<SurfaceControl> colorLayer =
            createSurface(mClient, "ColorLayer", 0, 0, PIXEL_FORMAT_RGBA_8888,
                          ISurfaceComposerClient::eFXSurfaceEffect, rootBoundlessLayer.get());

    ASSERT_TRUE(colorLayer->isValid());
    asTransaction([&](Transaction& t) {
        t.setLayer(rootBoundlessLayer, INT32_MAX - 1);
        t.setPosition(rootBoundlessLayer, 32, 32);
        t.show(rootBoundlessLayer);
        t.setCrop(colorLayer, Rect(0, 0, 64, 64));
        t.setColor(colorLayer, half3{0, 0, 0});
        t.show(colorLayer);
        t.hide(mFGSurfaceControl);
    });
    {
        mCapture = screenshot();
        // Top left of background must now be visible
        mCapture->expectBGColor(0, 0);
        // Top left of foreground must now be visible
        mCapture->expectBGColor(31, 31);
        // Foreground Surface bounds must be color layer
        mCapture->expectColor(Rect(32, 32, 96, 96), Color::BLACK);
        // Color layer should not extend past foreground bounds
        mCapture->expectBGColor(97, 97);
    }
}

} // namespace android

// TODO(b/129481165): remove the #pragma below and fix conversion issues
#pragma clang diagnostic pop // ignored "-Wconversion"
