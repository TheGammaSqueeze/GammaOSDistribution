package com.android.systemui.controls.controller;

import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.ServiceConnection;
import android.os.Binder;
import android.os.Bundle;
import android.os.IBinder;
import android.os.RemoteException;
import android.os.UserHandle;
import android.service.controls.ControlsProviderService;
import android.service.controls.IControlsActionCallback;
import android.service.controls.IControlsProvider;
import android.service.controls.IControlsSubscriber;
import android.service.controls.IControlsSubscription;
import android.service.controls.actions.ControlAction;
import android.util.ArraySet;
import android.util.Log;
import com.android.internal.annotations.GuardedBy;
import com.android.systemui.util.concurrency.DelayableExecutor;
import java.util.concurrent.TimeUnit;

/**
 * Manager for the lifecycle of the connection to a given [ControlsProviderService].
 *
 * This class handles binding and unbinding and requests to the service. The class will queue
 * requests until the service is connected and dispatch them then.
 *
 * @property context A SystemUI context for binding to the services
 * @property executor A delayable executor for posting timeouts
 * @property actionCallbackService a callback interface to hand the remote service for sending
 *                                action responses
 * @property subscriberService an "subscriber" interface for requesting and accepting updates for
 *                            controls from the service.
 * @property user the user for whose this service should be bound.
 * @property componentName the name of the component for the service.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u009e\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\t\n\u0002\b\b\u0018\u0000 E2\u00020\u0001:\u0006DEFGHIB-\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u00a2\u0006\u0002\u0010\fJ\u0006\u0010\'\u001a\u00020(J\u0010\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020\u001cH\u0002J\b\u0010*\u001a\u00020(H\u0016J\u0006\u0010+\u001a\u00020(J\u000e\u0010,\u001a\u00020(2\u0006\u0010-\u001a\u00020.J\b\u0010/\u001a\u00020(H\u0002J\u0014\u00100\u001a\u00020(2\n\u00101\u001a\u00060\u001aR\u00020\u0000H\u0002J\u000e\u00102\u001a\u00020(2\u0006\u00103\u001a\u000204J\u000e\u00105\u001a\u00020(2\u0006\u00103\u001a\u000204J\u0016\u00106\u001a\u00020(2\u0006\u00107\u001a\u00020\u000e2\u0006\u00108\u001a\u000209J\u001c\u0010:\u001a\u00020(2\f\u0010;\u001a\b\u0012\u0004\u0012\u00020\u000e0<2\u0006\u00103\u001a\u00020=J\u0014\u0010>\u001a\u00020(2\n\u00101\u001a\u00060\u001aR\u00020\u0000H\u0002J\u0016\u0010?\u001a\u00020(2\u0006\u0010-\u001a\u00020.2\u0006\u0010@\u001a\u00020AJ\b\u0010B\u001a\u00020\u000eH\u0016J\u0006\u0010C\u001a\u00020(R\u0016\u0010\r\u001a\n \u000f*\u0004\u0018\u00010\u000e0\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u0011X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\n\u001a\u00020\u000b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0016\u001a\u0004\u0018\u00010\u0017X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0018\u001a\f\u0012\b\u0012\u00060\u001aR\u00020\u00000\u00198\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001b\u001a\u00020\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u001f\u001a\u00020 \u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\"R\u0011\u0010\b\u001a\u00020\t\u00a2\u0006\b\n\u0000\u001a\u0004\b#\u0010$R\u0010\u0010%\u001a\u0004\u0018\u00010&X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "Landroid/os/IBinder$DeathRecipient;", "context", "Landroid/content/Context;", "executor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "actionCallbackService", "Landroid/service/controls/IControlsActionCallback$Stub;", "user", "Landroid/os/UserHandle;", "componentName", "Landroid/content/ComponentName;", "(Landroid/content/Context;Lcom/android/systemui/util/concurrency/DelayableExecutor;Landroid/service/controls/IControlsActionCallback$Stub;Landroid/os/UserHandle;Landroid/content/ComponentName;)V", "TAG", "", "kotlin.jvm.PlatformType", "bindTryCount", "", "getComponentName", "()Landroid/content/ComponentName;", "intent", "Landroid/content/Intent;", "onLoadCanceller", "Ljava/lang/Runnable;", "queuedServiceMethods", "", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$ServiceMethod;", "requiresBound", "", "serviceConnection", "Landroid/content/ServiceConnection;", "token", "Landroid/os/IBinder;", "getToken", "()Landroid/os/IBinder;", "getUser", "()Landroid/os/UserHandle;", "wrapper", "Lcom/android/systemui/controls/controller/ServiceWrapper;", "bindService", "", "bind", "binderDied", "cancelLoadTimeout", "cancelSubscription", "subscription", "Landroid/service/controls/IControlsSubscription;", "handlePendingServiceMethods", "invokeOrQueue", "sm", "maybeBindAndLoad", "subscriber", "Landroid/service/controls/IControlsSubscriber$Stub;", "maybeBindAndLoadSuggested", "maybeBindAndSendAction", "controlId", "action", "Landroid/service/controls/actions/ControlAction;", "maybeBindAndSubscribe", "controlIds", "", "Landroid/service/controls/IControlsSubscriber;", "queueServiceMethod", "startSubscription", "requestLimit", "", "toString", "unbindService", "Action", "Companion", "Load", "ServiceMethod", "Subscribe", "Suggest"})
public final class ControlsProviderLifecycleManager implements android.os.IBinder.DeathRecipient {
    @org.jetbrains.annotations.NotNull()
    private final android.os.IBinder token = null;
    private boolean requiresBound = false;
    @com.android.internal.annotations.GuardedBy(value = {"queuedServiceMethods"})
    private final java.util.Set<com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod> queuedServiceMethods = null;
    private com.android.systemui.controls.controller.ServiceWrapper wrapper;
    private int bindTryCount = 0;
    private final java.lang.String TAG = null;
    private java.lang.Runnable onLoadCanceller;
    private final android.content.Intent intent = null;
    private final android.content.ServiceConnection serviceConnection = null;
    private final android.content.Context context = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor executor = null;
    private final android.service.controls.IControlsActionCallback.Stub actionCallbackService = null;
    @org.jetbrains.annotations.NotNull()
    private final android.os.UserHandle user = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.ComponentName componentName = null;
    private static final long BIND_RETRY_DELAY = 1000L;
    private static final long LOAD_TIMEOUT_SECONDS = 20L;
    private static final int MAX_BIND_RETRIES = 5;
    private static final boolean DEBUG = true;
    private static final int BIND_FLAGS = 67109121;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ControlsProviderLifecycleManager.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.IBinder getToken() {
        return null;
    }
    
    private final void bindService(boolean bind) {
    }
    
    private final void handlePendingServiceMethods() {
    }
    
    @java.lang.Override()
    public void binderDied() {
    }
    
    private final void queueServiceMethod(com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod sm) {
    }
    
    private final void invokeOrQueue(com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod sm) {
    }
    
    /**
     * Request a call to [IControlsProvider.load].
     *
     * If the service is not bound, the call will be queued and the service will be bound first.
     * The service will be unbound after the controls are returned or the call times out.
     *
     * @param subscriber the subscriber that manages coordination for loading controls
     */
    public final void maybeBindAndLoad(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscriber.Stub subscriber) {
    }
    
    /**
     * Request a call to [IControlsProvider.loadSuggested].
     *
     * If the service is not bound, the call will be queued and the service will be bound first.
     * The service will be unbound if the call times out.
     *
     * @param subscriber the subscriber that manages coordination for loading controls
     */
    public final void maybeBindAndLoadSuggested(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscriber.Stub subscriber) {
    }
    
    public final void cancelLoadTimeout() {
    }
    
    /**
     * Request a subscription to the [Publisher] returned by [ControlsProviderService.publisherFor]
     *
     * If the service is not bound, the call will be queued and the service will be bound first.
     *
     * @param controlIds a list of the ids of controls to send status back.
     */
    public final void maybeBindAndSubscribe(@org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> controlIds, @org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscriber subscriber) {
    }
    
    /**
     * Request a call to [ControlsProviderService.performControlAction].
     *
     * If the service is not bound, the call will be queued and the service will be bound first.
     *
     * @param controlId the id of the [Control] the action is performed on
     * @param action the action performed
     */
    public final void maybeBindAndSendAction(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action) {
    }
    
    /**
     * Starts the subscription to the [ControlsProviderService] and requests status of controls.
     *
     * @param subscription the subscription to use to request controls
     * @see maybeBindAndLoad
     */
    public final void startSubscription(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscription subscription, long requestLimit) {
    }
    
    /**
     * Cancels the subscription to the [ControlsProviderService].
     *
     * @param subscription the subscription to cancel
     * @see maybeBindAndLoad
     */
    public final void cancelSubscription(@org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsSubscription subscription) {
    }
    
    /**
     * Request bind to the service.
     */
    public final void bindService() {
    }
    
    /**
     * Request unbind from the service.
     */
    public final void unbindService() {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.os.UserHandle getUser() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName getComponentName() {
        return null;
    }
    
    public ControlsProviderLifecycleManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.concurrency.DelayableExecutor executor, @org.jetbrains.annotations.NotNull()
    android.service.controls.IControlsActionCallback.Stub actionCallbackService, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user, @org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
        super();
    }
    
    /**
     * Service methods that can be queued or invoked, and are retryable for failure scenarios
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\u0002\b\u00a6\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\r\u0010\u0003\u001a\u00020\u0004H \u00a2\u0006\u0002\b\u0005J\u0006\u0010\u0006\u001a\u00020\u0007"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$ServiceMethod;", "", "(Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;)V", "callWrapper", "", "callWrapper$main", "run", ""})
    public abstract class ServiceMethod {
        
        public final void run() {
        }
        
        public abstract boolean callWrapper$main();
        
        public ServiceMethod() {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0000\b\u0086\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\r\u0010\b\u001a\u00020\tH\u0010\u00a2\u0006\u0002\b\nR\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$Load;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$ServiceMethod;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "subscriber", "Landroid/service/controls/IControlsSubscriber$Stub;", "(Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;Landroid/service/controls/IControlsSubscriber$Stub;)V", "getSubscriber", "()Landroid/service/controls/IControlsSubscriber$Stub;", "callWrapper", "", "callWrapper$main"})
    public final class Load extends com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod {
        @org.jetbrains.annotations.NotNull()
        private final android.service.controls.IControlsSubscriber.Stub subscriber = null;
        
        @java.lang.Override()
        public boolean callWrapper$main() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.service.controls.IControlsSubscriber.Stub getSubscriber() {
            return null;
        }
        
        public Load(@org.jetbrains.annotations.NotNull()
        android.service.controls.IControlsSubscriber.Stub subscriber) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0000\b\u0086\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\r\u0010\b\u001a\u00020\tH\u0010\u00a2\u0006\u0002\b\nR\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$Suggest;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$ServiceMethod;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "subscriber", "Landroid/service/controls/IControlsSubscriber$Stub;", "(Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;Landroid/service/controls/IControlsSubscriber$Stub;)V", "getSubscriber", "()Landroid/service/controls/IControlsSubscriber$Stub;", "callWrapper", "", "callWrapper$main"})
    public final class Suggest extends com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod {
        @org.jetbrains.annotations.NotNull()
        private final android.service.controls.IControlsSubscriber.Stub subscriber = null;
        
        @java.lang.Override()
        public boolean callWrapper$main() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.service.controls.IControlsSubscriber.Stub getSubscriber() {
            return null;
        }
        
        public Suggest(@org.jetbrains.annotations.NotNull()
        android.service.controls.IControlsSubscriber.Stub subscriber) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\b\u0086\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u001b\u0012\f\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\r\u0010\r\u001a\u00020\u000eH\u0010\u00a2\u0006\u0002\b\u000fR\u0017\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0011\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$Subscribe;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$ServiceMethod;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "list", "", "", "subscriber", "Landroid/service/controls/IControlsSubscriber;", "(Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;Ljava/util/List;Landroid/service/controls/IControlsSubscriber;)V", "getList", "()Ljava/util/List;", "getSubscriber", "()Landroid/service/controls/IControlsSubscriber;", "callWrapper", "", "callWrapper$main"})
    public final class Subscribe extends com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod {
        @org.jetbrains.annotations.NotNull()
        private final java.util.List<java.lang.String> list = null;
        @org.jetbrains.annotations.NotNull()
        private final android.service.controls.IControlsSubscriber subscriber = null;
        
        @java.lang.Override()
        public boolean callWrapper$main() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.List<java.lang.String> getList() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.service.controls.IControlsSubscriber getSubscriber() {
            return null;
        }
        
        public Subscribe(@org.jetbrains.annotations.NotNull()
        java.util.List<java.lang.String> list, @org.jetbrains.annotations.NotNull()
        android.service.controls.IControlsSubscriber subscriber) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u000b\n\u0000\b\u0086\u0004\u0018\u00002\u00060\u0001R\u00020\u0002B\u0015\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\r\u0010\f\u001a\u00020\rH\u0010\u00a2\u0006\u0002\b\u000eR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000b"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$Action;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$ServiceMethod;", "Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;", "id", "", "action", "Landroid/service/controls/actions/ControlAction;", "(Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager;Ljava/lang/String;Landroid/service/controls/actions/ControlAction;)V", "getAction", "()Landroid/service/controls/actions/ControlAction;", "getId", "()Ljava/lang/String;", "callWrapper", "", "callWrapper$main"})
    public final class Action extends com.android.systemui.controls.controller.ControlsProviderLifecycleManager.ServiceMethod {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String id = null;
        @org.jetbrains.annotations.NotNull()
        private final android.service.controls.actions.ControlAction action = null;
        
        @java.lang.Override()
        public boolean callWrapper$main() {
            return false;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getId() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.service.controls.actions.ControlAction getAction() {
            return null;
        }
        
        public Action(@org.jetbrains.annotations.NotNull()
        java.lang.String id, @org.jetbrains.annotations.NotNull()
        android.service.controls.actions.ControlAction action) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsProviderLifecycleManager$Companion;", "", "()V", "BIND_FLAGS", "", "BIND_RETRY_DELAY", "", "DEBUG", "", "LOAD_TIMEOUT_SECONDS", "MAX_BIND_RETRIES"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}