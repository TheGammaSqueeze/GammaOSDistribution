package com.android.systemui.controls.ui;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowInsets;
import android.view.WindowInsets.Type;
import com.android.systemui.R;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.management.ControlsAnimations;
import com.android.systemui.util.LifecycleActivity;
import javax.inject.Inject;

/**
 * Displays Device Controls inside an activity. This activity is available to be displayed over the
 * lockscreen if the user has allowed it via
 * [android.provider.Settings.Secure.LOCKSCREEN_SHOW_CONTROLS]. This activity will be
 * destroyed on SCREEN_OFF events, due to issues with occluded activities over lockscreen as well as
 * user expectations for the activity to not continue running.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u000b\u001a\u00020\fH\u0002J\b\u0010\r\u001a\u00020\fH\u0016J\u0012\u0010\u000e\u001a\u00020\f2\b\u0010\u000f\u001a\u0004\u0018\u00010\u0010H\u0014J\b\u0010\u0011\u001a\u00020\fH\u0014J\b\u0010\u0012\u001a\u00020\fH\u0014J\b\u0010\u0013\u001a\u00020\fH\u0014R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ControlsActivity;", "Lcom/android/systemui/util/LifecycleActivity;", "uiController", "Lcom/android/systemui/controls/ui/ControlsUiController;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "(Lcom/android/systemui/controls/ui/ControlsUiController;Lcom/android/systemui/broadcast/BroadcastDispatcher;)V", "broadcastReceiver", "Landroid/content/BroadcastReceiver;", "parent", "Landroid/view/ViewGroup;", "initBroadcastReceiver", "", "onBackPressed", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onDestroy", "onPause", "onResume"})
public final class ControlsActivity extends com.android.systemui.util.LifecycleActivity {
    private android.view.ViewGroup parent;
    private android.content.BroadcastReceiver broadcastReceiver;
    private final com.android.systemui.controls.ui.ControlsUiController uiController = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    
    @java.lang.Override()
    protected void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    protected void onResume() {
    }
    
    @java.lang.Override()
    public void onBackPressed() {
    }
    
    @java.lang.Override()
    protected void onPause() {
    }
    
    @java.lang.Override()
    protected void onDestroy() {
    }
    
    private final void initBroadcastReceiver() {
    }
    
    @javax.inject.Inject()
    public ControlsActivity(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlsUiController uiController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher) {
        super();
    }
}