package com.android.systemui.controls.ui;

import android.annotation.MainThread;
import android.app.Dialog;
import android.app.PendingIntent;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.os.VibrationEffect;
import android.os.Vibrator;
import android.service.controls.Control;
import android.service.controls.actions.BooleanAction;
import android.service.controls.actions.CommandAction;
import android.service.controls.actions.FloatAction;
import android.util.Log;
import android.view.HapticFeedbackConstants;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.ControlsMetricsLogger;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.globalactions.GlobalActionsComponent;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.wm.shell.TaskViewFactory;
import dagger.Lazy;
import java.util.Optional;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00aa\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010#\n\u0002\u0010\u000e\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u0000 H2\u00020\u0001:\u0002GHBe\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0001\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\f\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000f0\u000e\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\f\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00140\u0013\u0012\u0006\u0010\u0015\u001a\u00020\u0016\u00a2\u0006\u0002\u0010\u0017J\u0014\u0010\'\u001a\u00020(2\n\u0010)\u001a\u00060*R\u00020\u0000H\u0007J\b\u0010+\u001a\u00020(H\u0016J*\u0010,\u001a\u00060*R\u00020\u00002\u0006\u0010-\u001a\u00020\u001a2\f\u0010.\u001a\b\u0012\u0004\u0012\u00020(0/2\u0006\u00100\u001a\u00020#H\u0007J\u0010\u00101\u001a\u00020(2\u0006\u00102\u001a\u00020#H\u0016J\u0010\u00103\u001a\u00020(2\u0006\u0010-\u001a\u00020\u001aH\u0016J\u0010\u00104\u001a\u00020(2\u0006\u00105\u001a\u000206H\u0016J \u00107\u001a\u00020(2\u0006\u00105\u001a\u0002062\u0006\u00108\u001a\u00020\u001a2\u0006\u00109\u001a\u00020:H\u0016J\u0010\u0010;\u001a\u00020#2\u0006\u0010-\u001a\u00020\u001aH\u0002J\u0018\u0010<\u001a\u00020(2\u0006\u00105\u001a\u0002062\u0006\u0010=\u001a\u00020>H\u0002J \u0010?\u001a\u00020(2\u0006\u00105\u001a\u0002062\u0006\u00108\u001a\u00020\u001a2\u0006\u0010@\u001a\u00020#H\u0016J \u0010A\u001a\u00020(2\u0006\u00105\u001a\u0002062\u0006\u00108\u001a\u00020\u001a2\u0006\u0010B\u001a\u00020CH\u0016J\u0010\u0010D\u001a\u00020(2\u0006\u0010E\u001a\u00020FH\u0002R\u0014\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u001a0\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u001b\u001a\u00020\u0003X\u0096.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0015\u001a\u00020\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010 \u001a\u0004\u0018\u00010!X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\"\u001a\u00020#8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\"\u0010$R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00140\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000f0\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010%\u001a\u00020&X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ControlActionCoordinatorImpl;", "Lcom/android/systemui/controls/ui/ControlActionCoordinator;", "context", "Landroid/content/Context;", "bgExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "uiExecutor", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "keyguardStateController", "Lcom/android/systemui/statusbar/policy/KeyguardStateController;", "globalActionsComponent", "Lcom/android/systemui/globalactions/GlobalActionsComponent;", "taskViewFactory", "Ljava/util/Optional;", "Lcom/android/wm/shell/TaskViewFactory;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "lazyUiController", "Ldagger/Lazy;", "Lcom/android/systemui/controls/ui/ControlsUiController;", "controlsMetricsLogger", "Lcom/android/systemui/controls/ControlsMetricsLogger;", "(Landroid/content/Context;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/statusbar/policy/KeyguardStateController;Lcom/android/systemui/globalactions/GlobalActionsComponent;Ljava/util/Optional;Lcom/android/systemui/broadcast/BroadcastDispatcher;Ldagger/Lazy;Lcom/android/systemui/controls/ControlsMetricsLogger;)V", "actionsInProgress", "", "", "activityContext", "getActivityContext", "()Landroid/content/Context;", "setActivityContext", "(Landroid/content/Context;)V", "dialog", "Landroid/app/Dialog;", "isLocked", "", "()Z", "vibrator", "Landroid/os/Vibrator;", "bouncerOrRun", "", "action", "Lcom/android/systemui/controls/ui/ControlActionCoordinatorImpl$Action;", "closeDialogs", "createAction", "controlId", "f", "Lkotlin/Function0;", "blockable", "drag", "isEdge", "enableActionOnTouch", "longPress", "cvh", "Lcom/android/systemui/controls/ui/ControlViewHolder;", "setValue", "templateId", "newValue", "", "shouldRunAction", "showDetail", "pendingIntent", "Landroid/app/PendingIntent;", "toggle", "isChecked", "touch", "control", "Landroid/service/controls/Control;", "vibrate", "effect", "Landroid/os/VibrationEffect;", "Action", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class ControlActionCoordinatorImpl implements com.android.systemui.controls.ui.ControlActionCoordinator {
    private android.app.Dialog dialog;
    private final android.os.Vibrator vibrator = null;
    private java.util.Set<java.lang.String> actionsInProgress;
    public android.content.Context activityContext;
    private final android.content.Context context = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor bgExecutor = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor uiExecutor = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController = null;
    private final com.android.systemui.globalactions.GlobalActionsComponent globalActionsComponent = null;
    private final java.util.Optional<com.android.wm.shell.TaskViewFactory> taskViewFactory = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final dagger.Lazy<com.android.systemui.controls.ui.ControlsUiController> lazyUiController = null;
    private final com.android.systemui.controls.ControlsMetricsLogger controlsMetricsLogger = null;
    private static final long RESPONSE_TIMEOUT_IN_MILLIS = 3000L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.ControlActionCoordinatorImpl.Companion Companion = null;
    
    private final boolean isLocked() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.Context getActivityContext() {
        return null;
    }
    
    @java.lang.Override()
    public void setActivityContext(@org.jetbrains.annotations.NotNull()
    android.content.Context p0) {
    }
    
    @java.lang.Override()
    public void closeDialogs() {
    }
    
    @java.lang.Override()
    public void toggle(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    java.lang.String templateId, boolean isChecked) {
    }
    
    @java.lang.Override()
    public void touch(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    java.lang.String templateId, @org.jetbrains.annotations.NotNull()
    android.service.controls.Control control) {
    }
    
    @java.lang.Override()
    public void drag(boolean isEdge) {
    }
    
    @java.lang.Override()
    public void setValue(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh, @org.jetbrains.annotations.NotNull()
    java.lang.String templateId, float newValue) {
    }
    
    @java.lang.Override()
    public void longPress(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlViewHolder cvh) {
    }
    
    @android.annotation.MainThread()
    @java.lang.Override()
    public void enableActionOnTouch(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId) {
    }
    
    private final boolean shouldRunAction(java.lang.String controlId) {
        return false;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public final void bouncerOrRun(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlActionCoordinatorImpl.Action action) {
    }
    
    private final void vibrate(android.os.VibrationEffect effect) {
    }
    
    private final void showDetail(com.android.systemui.controls.ui.ControlViewHolder cvh, android.app.PendingIntent pendingIntent) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @com.android.internal.annotations.VisibleForTesting()
    public final com.android.systemui.controls.ui.ControlActionCoordinatorImpl.Action createAction(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function0<kotlin.Unit> f, boolean blockable) {
        return null;
    }
    
    @javax.inject.Inject()
    public ControlActionCoordinatorImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor bgExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    com.android.systemui.util.concurrency.DelayableExecutor uiExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.KeyguardStateController keyguardStateController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.globalactions.GlobalActionsComponent globalActionsComponent, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.wm.shell.TaskViewFactory> taskViewFactory, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.ui.ControlsUiController> lazyUiController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ControlsMetricsLogger controlsMetricsLogger) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\b\b\u0086\u0004\u0018\u00002\u00020\u0001B#\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u0006\u0010\u0010\u001a\u00020\u0006R\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0017\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000f"}, d2 = {"Lcom/android/systemui/controls/ui/ControlActionCoordinatorImpl$Action;", "", "controlId", "", "f", "Lkotlin/Function0;", "", "blockable", "", "(Lcom/android/systemui/controls/ui/ControlActionCoordinatorImpl;Ljava/lang/String;Lkotlin/jvm/functions/Function0;Z)V", "getBlockable", "()Z", "getControlId", "()Ljava/lang/String;", "getF", "()Lkotlin/jvm/functions/Function0;", "invoke"})
    public final class Action {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String controlId = null;
        @org.jetbrains.annotations.NotNull()
        private final kotlin.jvm.functions.Function0<kotlin.Unit> f = null;
        private final boolean blockable = false;
        
        public final void invoke() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getControlId() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final kotlin.jvm.functions.Function0<kotlin.Unit> getF() {
            return null;
        }
        
        public final boolean getBlockable() {
            return false;
        }
        
        public Action(@org.jetbrains.annotations.NotNull()
        java.lang.String controlId, @org.jetbrains.annotations.NotNull()
        kotlin.jvm.functions.Function0<kotlin.Unit> f, boolean blockable) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/ControlActionCoordinatorImpl$Companion;", "", "()V", "RESPONSE_TIMEOUT_IN_MILLIS", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}