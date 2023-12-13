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

package com.android.systemui.car.hvac;

import android.content.Context;
import android.content.res.Resources;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowInsets;

import com.android.systemui.R;
import com.android.systemui.car.CarDeviceProvisionedController;
import com.android.systemui.car.window.OverlayPanelViewController;
import com.android.systemui.car.window.OverlayViewGlobalStateController;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.wm.shell.animation.FlingAnimationUtils;

import javax.inject.Inject;

/**
 *  An {@link OverlayPanelViewController} implementation for HvacPanelOverlayView.
 */
@SysUISingleton
public class HvacPanelOverlayViewController extends OverlayPanelViewController {

    private final Resources mResources;
    private final HvacController mHvacController;

    private HvacPanelView mHvacPanelView;

    @Inject
    public HvacPanelOverlayViewController(Context context,
            @Main Resources resources,
            HvacController hvacController,
            OverlayViewGlobalStateController overlayViewGlobalStateController,
            FlingAnimationUtils.Builder flingAnimationUtilsBuilder,
            CarDeviceProvisionedController carDeviceProvisionedController) {
        super(context, resources, R.id.hvac_panel_stub, overlayViewGlobalStateController,
                flingAnimationUtilsBuilder, carDeviceProvisionedController);
        mResources = resources;
        mHvacController = hvacController;
    }

    @Override
    protected void onFinishInflate() {
        super.onFinishInflate();

        View closeButton = getLayout().findViewById(R.id.hvac_panel_close_button);
        if (closeButton != null) {
            closeButton.setOnClickListener(v -> toggle());
        }

        mHvacPanelView = getLayout().findViewById(R.id.hvac_panel);
        mHvacController.registerHvacViews(mHvacPanelView);

        mHvacPanelView.setKeyEventHandler((event) -> {
            if (event.getKeyCode() != KeyEvent.KEYCODE_BACK) {
                return false;
            }

            if (event.getAction() == KeyEvent.ACTION_UP && isPanelExpanded()) {
                toggle();
            }
            return true;
        });
    }

    @Override
    protected int getInsetTypesToFit() {
        return WindowInsets.Type.systemBars();
    }

    @Override
    protected boolean shouldShowStatusBarInsets() {
        return true;
    }

    @Override
    protected boolean shouldShowNavigationBarInsets() {
        return true;
    }

    @Override
    protected boolean shouldAnimateCollapsePanel() {
        return true;
    }

    @Override
    protected boolean shouldAnimateExpandPanel() {
        return true;
    }

    @Override
    protected boolean shouldAllowClosingScroll() {
        return true;
    }

    @Override
    protected Integer getHandleBarViewId() {
        return R.id.handle_bar;
    }

    @Override
    protected int getFocusAreaViewId() {
        return R.id.hvac_panel_container;
    }

    @Override
    protected int getSettleClosePercentage() {
        return mResources.getInteger(R.integer.hvac_panel_settle_close_percentage);
    }

    @Override
    protected void onAnimateCollapsePanel() {
        // no-op.
    }

    @Override
    protected void onAnimateExpandPanel() {
        // no-op.
    }

    @Override
    protected void onCollapseAnimationEnd() {
        // no-op.
    }

    @Override
    protected void onExpandAnimationEnd() {
        // no-op.
    }

    @Override
    protected void onOpenScrollStart() {
        // no-op.
    }
}
