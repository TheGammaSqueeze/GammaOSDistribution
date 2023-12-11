package com.android.systemui.controls.controller;

import android.content.ComponentName;
import android.content.Context;
import android.os.IBinder;
import android.os.UserHandle;
import android.service.controls.Control;
import android.service.controls.IControlsActionCallback;
import android.service.controls.IControlsSubscriber;
import android.service.controls.IControlsSubscription;
import android.service.controls.actions.ControlAction;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.concurrency.DelayableExecutor;
import dagger.Lazy;
import java.util.concurrent.atomic.AtomicBoolean;
import javax.inject.Inject;

@com.android.internal.annotations.VisibleForTesting()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0082\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\b\n\b\u0017\u0018\u0000 62\u00020\u0001:\b56789:;<B/\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ \u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010\u001a\u001a\u00020 H\u0016J\u0018\u0010!\u001a\u00020\"2\u0006\u0010#\u001a\u00020\u001d2\u0006\u0010$\u001a\u00020%H\u0016J\u0018\u0010&\u001a\u00020\u001b2\u0006\u0010#\u001a\u00020\u001d2\u0006\u0010$\u001a\u00020%H\u0016J\u0010\u0010\'\u001a\u00020\u001b2\u0006\u0010#\u001a\u00020\u001dH\u0016J\u0010\u0010(\u001a\u00020\u001b2\u0006\u0010)\u001a\u00020\u0011H\u0016J\u0015\u0010*\u001a\u00020\u000f2\u0006\u0010#\u001a\u00020\u001dH\u0011\u00a2\u0006\u0002\b+J\u0010\u0010,\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001dH\u0016J\u0010\u0010-\u001a\u00020\u000f2\u0006\u0010#\u001a\u00020\u001dH\u0002J\u0010\u0010.\u001a\u00020\u001b2\u0006\u0010/\u001a\u000200H\u0016J\b\u00101\u001a\u000202H\u0016J\b\u00103\u001a\u00020\u001bH\u0002J\b\u00104\u001a\u00020\u001bH\u0016R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0012\u001a\u00020\u00138VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u0015R\u0014\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0016\u001a\b\u0018\u00010\u0017R\u00020\u0000X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0018\u001a\u0004\u0018\u00010\u0019X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "Lcom/android/systemui/controls/controller/ControlsBindingController;", "context", "Landroid/content/Context;", "backgroundExecutor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "lazyController", "Ldagger/Lazy;", "Lcom/android/systemui/controls/controller/ControlsController;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "(Landroid/content/Context;Lcom/android/systemui/util/concurrency/DelayableExecutor;Ldagger/Lazy;Lcom/android/systemui/settings/UserTracker;)V", "actionCallbackService", "Landroid/service/controls/IControlsActionCallback$Stub;", "currentProvider", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "currentUser", "Landroid/os/UserHandle;", "currentUserId", "", "getCurrentUserId", "()I", "loadSubscriber", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$LoadSubscriber;", "statefulControlSubscriber", "Lcom/android/systemui/controls/controller/StatefulControlSubscriber;", "action", "", "componentName", "Landroid/content/ComponentName;", "controlInfo", "Lcom/android/systemui/controls/controller/ControlInfo;", "Landroid/service/controls/actions/ControlAction;", "bindAndLoad", "Ljava/lang/Runnable;", "component", "callback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "bindAndLoadSuggested", "bindService", "changeUser", "newUser", "createProviderManager", "createProviderManager$main", "onComponentRemoved", "retrieveLifecycleManager", "subscribe", "structureInfo", "Lcom/android/systemui/controls/controller/StructureInfo;", "toString", "", "unbind", "unsubscribe", "CallbackRunnable", "Companion", "LoadSubscriber", "OnActionResponseRunnable", "OnCancelAndLoadRunnable", "OnLoadErrorRunnable", "OnLoadRunnable", "OnSubscribeRunnable"})
@com.android.systemui.dagger.SysUISingleton()
public class ControlsBindingControllerImpl implements com.android.systemui.controls.controller.ControlsBindingController {
    private android.os.UserHandle currentUser;
    private com.android.systemui.controls.controller.ControlsProviderLifecycleManager currentProvider;
    private com.android.systemui.controls.controller.StatefulControlSubscriber statefulControlSubscriber;
    private com.android.systemui.controls.controller.ControlsBindingControllerImpl.LoadSubscriber loadSubscriber;
    private final android.service.controls.IControlsActionCallback.Stub actionCallbackService = null;
    private final android.content.Context context = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor backgroundExecutor = null;
    private final dagger.Lazy<com.android.systemui.controls.controller.ControlsController> lazyController = null;
    private static final java.lang.String TAG = "ControlsBindingControllerImpl";
    private static final long MAX_CONTROLS_REQUEST = 100000L;
    private static final long SUGGESTED_STRUCTURES = 6L;
    private static final long SUGGESTED_CONTROLS_REQUEST = 36L;
    private static final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback emptyCallback = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ControlsBindingControllerImpl.Companion Companion = null;
    
    @java.lang.Override()
    public int getCurrentUserId() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @com.android.internal.annotations.VisibleForTesting()
    public com.android.systemui.controls.controller.ControlsProviderLifecycleManager createProviderManager$main(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component) {
        return null;
    }
    
    private final com.android.systemui.controls.controller.ControlsProviderLifecycleManager retrieveLifecycleManager(android.content.ComponentName component) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.Runnable bindAndLoad(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback) {
        return null;
    }
    
    @java.lang.Override()
    public void bindAndLoadSuggested(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback) {
    }
    
    @java.lang.Override()
    public void subscribe(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structureInfo) {
    }
    
    @java.lang.Override()
    public void unsubscribe() {
    }
    
    @java.lang.Override()
    public void action(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, @org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action) {
    }
    
    @java.lang.Override()
    public void bindService(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component) {
    }
    
    @java.lang.Override()
    public void changeUser(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle newUser) {
    }
    
    private final void unbind() {
    }
    
    @java.lang.Override()
    public void onComponentRemoved(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @javax.inject.Inject()
    public ControlsBindingControllerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    com.android.systemui.util.concurrency.DelayableExecutor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.controls.controller.ControlsController> lazyController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0000\b\u00a2\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\b\u0010\u000b\u001a\u00020\fH&J\b\u0010\r\u001a\u00020\fH\u0016R\u0016\u0010\u0005\u001a\u0004\u0018\u00010\u0006X\u0084\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$CallbackRunnable;", "Ljava/lang/Runnable;", "token", "Landroid/os/IBinder;", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Landroid/os/IBinder;)V", "provider", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "getProvider", "()Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "getToken", "()Landroid/os/IBinder;", "doRun", "", "run"})
    abstract class CallbackRunnable implements java.lang.Runnable {
        @org.jetbrains.annotations.Nullable()
        private final com.android.systemui.controls.controller.ControlsProviderLifecycleManager provider = null;
        @org.jetbrains.annotations.NotNull()
        private final android.os.IBinder token = null;
        
        @org.jetbrains.annotations.Nullable()
        protected final com.android.systemui.controls.controller.ControlsProviderLifecycleManager getProvider() {
            return null;
        }
        
        @java.lang.Override()
        public void run() {
        }
        
        public abstract void doRun();
        
        @org.jetbrains.annotations.NotNull()
        public final android.os.IBinder getToken() {
            return null;
        }
        
        public CallbackRunnable(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B#\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\b\u0010\u000f\u001a\u00020\u0010H\u0016R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$OnLoadRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$CallbackRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "token", "Landroid/os/IBinder;", "list", "", "Landroid/service/controls/Control;", "callback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Landroid/os/IBinder;Ljava/util/List;Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;)V", "getCallback", "()Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "getList", "()Ljava/util/List;", "doRun", ""})
    final class OnLoadRunnable extends com.android.systemui.controls.controller.ControlsBindingControllerImpl.CallbackRunnable {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<android.service.controls.Control> list = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback = null;
        
        @java.lang.Override()
        public void doRun() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<android.service.controls.Control> getList() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback getCallback() {
            return null;
        }
        
        public OnLoadRunnable(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        java.util.List<android.service.controls.Control> list, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010\u0002\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B+\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\f\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\b\u0010\u0013\u001a\u00020\u0014H\u0016R\u0011\u0010\n\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0017\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$OnCancelAndLoadRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$CallbackRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "token", "Landroid/os/IBinder;", "list", "", "Landroid/service/controls/Control;", "subscription", "Landroid/service/controls/IControlsSubscription;", "callback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Landroid/os/IBinder;Ljava/util/List;Landroid/service/controls/IControlsSubscription;Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;)V", "getCallback", "()Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "getList", "()Ljava/util/List;", "getSubscription", "()Landroid/service/controls/IControlsSubscription;", "doRun", ""})
    final class OnCancelAndLoadRunnable extends com.android.systemui.controls.controller.ControlsBindingControllerImpl.CallbackRunnable {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<android.service.controls.Control> list = null;
        @org.jetbrains.annotations.NotNull()
        private final android.service.controls.IControlsSubscription subscription = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback = null;
        
        @java.lang.Override()
        public void doRun() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<android.service.controls.Control> getList() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.service.controls.IControlsSubscription getSubscription() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback getCallback() {
            return null;
        }
        
        public OnCancelAndLoadRunnable(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        java.util.List<android.service.controls.Control> list, @org.jetbrains.annotations.NotNull()
        android.service.controls.IControlsSubscription subscription, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0006\n\u0002\u0010\u0002\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u001d\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\b\u0010\u000e\u001a\u00020\u000fH\u0016R\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$OnSubscribeRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$CallbackRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "token", "Landroid/os/IBinder;", "subscription", "Landroid/service/controls/IControlsSubscription;", "requestLimit", "", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Landroid/os/IBinder;Landroid/service/controls/IControlsSubscription;J)V", "getRequestLimit", "()J", "getSubscription", "()Landroid/service/controls/IControlsSubscription;", "doRun", ""})
    final class OnSubscribeRunnable extends com.android.systemui.controls.controller.ControlsBindingControllerImpl.CallbackRunnable {
        @org.jetbrains.annotations.NotNull()
        private final android.service.controls.IControlsSubscription subscription = null;
        private final long requestLimit = 0L;
        
        @java.lang.Override()
        public void doRun() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.service.controls.IControlsSubscription getSubscription() {
            return null;
        }
        
        public final long getRequestLimit() {
            return 0L;
        }
        
        public OnSubscribeRunnable(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        android.service.controls.IControlsSubscription subscription, long requestLimit) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0010\u0002\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u001d\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\b\u0010\u000e\u001a\u00020\u000fH\u0016R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$OnActionResponseRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$CallbackRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "token", "Landroid/os/IBinder;", "controlId", "", "response", "", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Landroid/os/IBinder;Ljava/lang/String;I)V", "getControlId", "()Ljava/lang/String;", "getResponse", "()I", "doRun", ""})
    final class OnActionResponseRunnable extends com.android.systemui.controls.controller.ControlsBindingControllerImpl.CallbackRunnable {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String controlId = null;
        private final int response = 0;
        
        @java.lang.Override()
        public void doRun() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getControlId() {
            return null;
        }
        
        public final int getResponse() {
            return 0;
        }
        
        public OnActionResponseRunnable(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        java.lang.String controlId, @android.service.controls.actions.ControlAction.ResponseResult()
        int response) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\b\u0082\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u001d\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\b\u0010\u000e\u001a\u00020\u000fH\u0016R\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\r"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$OnLoadErrorRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$CallbackRunnable;", "Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;", "token", "Landroid/os/IBinder;", "error", "", "callback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Landroid/os/IBinder;Ljava/lang/String;Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;)V", "getCallback", "()Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "getError", "()Ljava/lang/String;", "doRun", ""})
    final class OnLoadErrorRunnable extends com.android.systemui.controls.controller.ControlsBindingControllerImpl.CallbackRunnable {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String error = null;
        @org.jetbrains.annotations.NotNull()
        private final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback = null;
        
        @java.lang.Override()
        public void doRun() {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getError() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback getCallback() {
            return null;
        }
        
        public OnLoadErrorRunnable(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        java.lang.String error, @org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback) {
            super(null);
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0004\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\u0019\u001a\u00020\u001aJ\u0010\u0010\u001b\u001a\u00020\t2\u0006\u0010\u001c\u001a\u00020\u001aH\u0002J\u0010\u0010\u001d\u001a\u00020\t2\u0006\u0010\u001e\u001a\u00020\u001fH\u0016J\u0018\u0010 \u001a\u00020\t2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010!\u001a\u00020\"H\u0016J\u0018\u0010#\u001a\u00020\t2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010$\u001a\u00020\u0012H\u0016J\u0018\u0010%\u001a\u00020\t2\u0006\u0010\u001e\u001a\u00020\u001f2\u0006\u0010&\u001a\u00020\u0018H\u0016R\u0016\u0010\u0007\u001a\n\u0012\u0004\u0012\u00020\t\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0002\u001a\u00020\u0003X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0017\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00120\u0011\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0015\u0010\u0016R\u000e\u0010\u0017\u001a\u00020\u0018X\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$LoadSubscriber;", "Landroid/service/controls/IControlsSubscriber$Stub;", "callback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "requestLimit", "", "(Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl;Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;J)V", "_loadCancelInternal", "Lkotlin/Function0;", "", "getCallback", "()Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;", "setCallback", "(Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;)V", "isTerminated", "Ljava/util/concurrent/atomic/AtomicBoolean;", "loadedControls", "Ljava/util/ArrayList;", "Landroid/service/controls/Control;", "getLoadedControls", "()Ljava/util/ArrayList;", "getRequestLimit", "()J", "subscription", "Landroid/service/controls/IControlsSubscription;", "loadCancel", "Ljava/lang/Runnable;", "maybeTerminateAndRun", "postTerminateFn", "onComplete", "token", "Landroid/os/IBinder;", "onError", "s", "", "onNext", "c", "onSubscribe", "subs"})
    final class LoadSubscriber extends android.service.controls.IControlsSubscriber.Stub {
        @org.jetbrains.annotations.NotNull()
        private final java.util.ArrayList<android.service.controls.Control> loadedControls = null;
        private java.util.concurrent.atomic.AtomicBoolean isTerminated;
        private kotlin.jvm.functions.Function0<kotlin.Unit> _loadCancelInternal;
        private android.service.controls.IControlsSubscription subscription;
        @org.jetbrains.annotations.NotNull()
        private com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback;
        private final long requestLimit = 0L;
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.ArrayList<android.service.controls.Control> getLoadedControls() {
            return null;
        }
        
        /**
         * Potentially cancel a subscriber. The subscriber may also have terminated, in which case
         * the request is ignored.
         */
        @org.jetbrains.annotations.NotNull()
        public final java.lang.Runnable loadCancel() {
            return null;
        }
        
        @java.lang.Override()
        public void onSubscribe(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        android.service.controls.IControlsSubscription subs) {
        }
        
        @java.lang.Override()
        public void onNext(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        android.service.controls.Control c) {
        }
        
        @java.lang.Override()
        public void onError(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token, @org.jetbrains.annotations.NotNull()
        java.lang.String s) {
        }
        
        @java.lang.Override()
        public void onComplete(@org.jetbrains.annotations.NotNull()
        android.os.IBinder token) {
        }
        
        private final void maybeTerminateAndRun(java.lang.Runnable postTerminateFn) {
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.controls.controller.ControlsBindingController.LoadCallback getCallback() {
            return null;
        }
        
        public final void setCallback(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.controller.ControlsBindingController.LoadCallback p0) {
        }
        
        public final long getRequestLimit() {
            return 0L;
        }
        
        public LoadSubscriber(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.controller.ControlsBindingController.LoadCallback callback, long requestLimit) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsBindingControllerImpl$Companion;", "", "()V", "MAX_CONTROLS_REQUEST", "", "SUGGESTED_CONTROLS_REQUEST", "SUGGESTED_STRUCTURES", "TAG", "", "emptyCallback", "Lcom/android/systemui/controls/controller/ControlsBindingController$LoadCallback;"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}