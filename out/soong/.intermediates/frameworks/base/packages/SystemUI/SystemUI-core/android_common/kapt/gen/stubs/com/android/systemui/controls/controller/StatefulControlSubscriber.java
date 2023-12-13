package com.android.systemui.controls.controller;

import android.os.IBinder;
import android.service.controls.Control;
import android.service.controls.IControlsSubscriber;
import android.service.controls.IControlsSubscription;
import android.util.Log;
import com.android.systemui.util.concurrency.DelayableExecutor;

/**
 * A single subscriber, supporting stateful controls for publishers created by
 * {@link ControlsProviderService#createPublisherFor}. In general, this subscription will remain
 * active until the SysUi chooses to cancel it.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000V\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\u0018\u0000 \u001f2\u00020\u0001:\u0001\u001fB%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0006\u0010\u000f\u001a\u00020\u0010J\u0010\u0010\u0011\u001a\u00020\u00102\u0006\u0010\u0012\u001a\u00020\u0013H\u0016J\u0018\u0010\u0014\u001a\u00020\u00102\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0015\u001a\u00020\u0016H\u0016J\u0018\u0010\u0017\u001a\u00020\u00102\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0018\u001a\u00020\u0019H\u0016J\u0018\u0010\u001a\u001a\u00020\u00102\u0006\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u001b\u001a\u00020\fH\u0016J\u001e\u0010\u001c\u001a\u00020\u00102\u0006\u0010\u0012\u001a\u00020\u00132\f\u0010\u001d\u001a\b\u0012\u0004\u0012\u00020\u00100\u001eH\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/StatefulControlSubscriber;", "Landroid/service/controls/IControlsSubscriber$Stub;", "controller", "Lcom/android/systemui/controls/controller/ControlsController;", "provider", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "bgExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "requestLimit", "", "(Lcom/android/systemui/controls/controller/ControlsController;Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;Lcom/android/systemui/util/concurrency/DelayableExecutor;J)V", "subscription", "Landroid/service/controls/IControlsSubscription;", "subscriptionOpen", "", "cancel", "", "onComplete", "token", "Landroid/os/IBinder;", "onError", "error", "", "onNext", "control", "Landroid/service/controls/Control;", "onSubscribe", "subs", "run", "f", "Lkotlin/Function0;", "Companion"})
public final class StatefulControlSubscriber extends android.service.controls.IControlsSubscriber.Stub {
    private boolean subscriptionOpen = false;
    private android.service.controls.IControlsSubscription subscription;
    private final com.android.systemui.controls.controller.ControlsController controller = null;
    private final com.android.systemui.controls.controller.ControlsProviderLifecycleManager provider = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor bgExecutor = null;
    private final long requestLimit = 0L;
    private static final java.lang.String TAG = "StatefulControlSubscriber";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.StatefulControlSubscriber.Companion Companion = null;
    
    private final void run(android.os.IBinder token, kotlin.jvm.functions.Function0<kotlin.Unit> f) {
    }
    
    @java.lang.Override()
    public void onSubscribe(@org.jetbrains.annotations.NotNull()
    android.os.IBinder token, @org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscription subs) {
    }
    
    @java.lang.Override()
    public void onNext(@org.jetbrains.annotations.NotNull()
    android.os.IBinder token, @org.jetbrains.annotations.NotNull()
    android.service.controls.Control control) {
    }
    
    @java.lang.Override()
    public void onError(@org.jetbrains.annotations.NotNull()
    android.os.IBinder token, @org.jetbrains.annotations.NotNull()
    java.lang.String error) {
    }
    
    @java.lang.Override()
    public void onComplete(@org.jetbrains.annotations.NotNull()
    android.os.IBinder token) {
    }
    
    public final void cancel() {
    }
    
    public StatefulControlSubscriber(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsController controller, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsProviderLifecycleManager provider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor bgExecutor, long requestLimit) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/StatefulControlSubscriber$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}