package com.android.systemui.qs.tiles;

import android.content.ComponentName;
import android.content.Intent;
import android.os.Handler;
import android.os.Looper;
import android.service.quicksettings.Tile;
import android.view.View;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.internal.logging.MetricsLogger;
import com.android.systemui.R;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.controls.dagger.ControlsComponent;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.ui.ControlsActivity;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.qs.QSTile;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.QSHost;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.qs.tileimpl.QSTileImpl;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import java.util.concurrent.atomic.AtomicBoolean;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u008c\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B[\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0001\u0010\u0005\u001a\u00020\u0006\u0012\b\b\u0001\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\u0006\u0010\u0011\u001a\u00020\u0012\u0012\u0006\u0010\u0013\u001a\u00020\u0014\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u00a2\u0006\u0002\u0010\u0017J\n\u0010\u001f\u001a\u0004\u0018\u00010 H\u0016J\b\u0010!\u001a\u00020\"H\u0016J\b\u0010#\u001a\u00020$H\u0016J\u0012\u0010%\u001a\u00020&2\b\u0010\'\u001a\u0004\u0018\u00010(H\u0014J\u0012\u0010)\u001a\u00020&2\b\u0010\'\u001a\u0004\u0018\u00010(H\u0014J\u001a\u0010*\u001a\u00020&2\u0006\u0010+\u001a\u00020\u00022\b\u0010,\u001a\u0004\u0018\u00010-H\u0014J\b\u0010.\u001a\u00020/H\u0016J\b\u00100\u001a\u00020\u0002H\u0016R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0018\u001a\u00020\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001a\u001a\n \u001c*\u0004\u0018\u00010\u001b0\u001bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tiles/DeviceControlsTile;", "Lcom/android/systemui/qs/tileimpl/QSTileImpl;", "Lcom/android/systemui/plugins/qs/QSTile$State;", "host", "Lcom/android/systemui/qs/QSHost;", "backgroundLooper", "Landroid/os/Looper;", "mainHandler", "Landroid/os/Handler;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "metricsLogger", "Lcom/android/internal/logging/MetricsLogger;", "statusBarStateController", "Lcom/android/systemui/plugins/statusbar/StatusBarStateController;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "qsLogger", "Lcom/android/systemui/qs/logging/QSLogger;", "controlsComponent", "Lcom/android/systemui/controls/dagger/ControlsComponent;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "(Lcom/android/systemui/qs/QSHost;Landroid/os/Looper;Landroid/os/Handler;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/internal/logging/MetricsLogger;Lcom/android/systemui/plugins/statusbar/StatusBarStateController;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/qs/logging/QSLogger;Lcom/android/systemui/controls/dagger/ControlsComponent;Lcom/android/systemui/statusbar/policy/KeyguardStateController;)V", "hasControlsApps", "Ljava/util/concurrent/atomic/AtomicBoolean;", "icon", "Lcom/android/systemui/plugins/qs/QSTile$Icon;", "kotlin.jvm.PlatformType", "listingCallback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "getLongClickIntent", "Landroid/content/Intent;", "getMetricsCategory", "", "getTileLabel", "", "handleClick", "", "view", "Landroid/view/View;", "handleLongClick", "handleUpdateState", "state", "arg", "", "isAvailable", "", "newTileState"})
public final class DeviceControlsTile extends com.android.systemui.qs.tileimpl.QSTileImpl<com.android.systemui.plugins.qs.QSTile.State> {
    private java.util.concurrent.atomic.AtomicBoolean hasControlsApps;
    private final com.android.systemui.plugins.qs.QSTile.Icon icon = null;
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listingCallback = null;
    private final com.android.systemui.controls.dagger.ControlsComponent controlsComponent = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    
    @java.lang.Override()
    public boolean isAvailable() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.plugins.qs.QSTile.State newTileState() {
        return null;
    }
    
    @java.lang.Override()
    protected void handleClick(@org.jetbrains.annotations.Nullable()
    android.view.View view) {
    }
    
    @java.lang.Override()
    protected void handleUpdateState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state, @org.jetbrains.annotations.Nullable()
    java.lang.Object arg) {
    }
    
    @java.lang.Override()
    public int getMetricsCategory() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.content.Intent getLongClickIntent() {
        return null;
    }
    
    @java.lang.Override()
    protected void handleLongClick(@org.jetbrains.annotations.Nullable()
    android.view.View view) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getTileLabel() {
        return null;
    }
    
    @javax.inject.Inject()
    public DeviceControlsTile(@org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.QSHost host, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    android.os.Looper backgroundLooper, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler mainHandler, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.MetricsLogger metricsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.statusbar.StatusBarStateController statusBarStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.logging.QSLogger qsLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.dagger.ControlsComponent controlsComponent, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController) {
        super(null, null, null, null, null, null, null, null);
    }
}