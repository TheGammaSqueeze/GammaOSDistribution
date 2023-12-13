package com.android.systemui.controls.controller;

import android.content.ComponentName;
import android.service.controls.Control;
import android.service.controls.ControlsProviderService;
import android.service.controls.actions.ControlAction;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.util.UserAwareController;
import com.android.systemui.controls.management.ControlsFavoritingActivity;
import com.android.systemui.controls.ui.ControlsUiController;
import java.util.function.Consumer;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001c\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\u001a,\u0010\u0000\u001a\u00020\u00012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u00032\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00060\u00032\b\b\u0002\u0010\u0007\u001a\u00020\b"}, d2 = {"createLoadDataObject", "Lcom/android/systemui/controls/controller/ControlsController$LoadData;", "allControls", "", "Lcom/android/systemui/controls/ControlStatus;", "favorites", "", "error", ""})
public final class ControlsControllerKt {
    
    /**
     * Creates a basic implementation of a [LoadData].
     */
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ControlsController.LoadData createLoadDataObject(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.ControlStatus> allControls, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> favorites, boolean error) {
        return null;
    }
}