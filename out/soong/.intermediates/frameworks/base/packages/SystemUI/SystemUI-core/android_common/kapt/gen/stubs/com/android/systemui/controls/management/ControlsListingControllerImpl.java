package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.content.Context;
import android.content.pm.ServiceInfo;
import android.os.UserHandle;
import android.service.controls.ControlsProviderService;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.settingslib.applications.ServiceListing;
import com.android.settingslib.widget.CandidateInfo;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.settings.UserTracker;
import java.util.concurrent.Executor;
import java.util.concurrent.atomic.AtomicInteger;
import javax.inject.Inject;

/**
 * Provides a listing of components to be used as ControlsServiceProvider.
 *
 * This controller keeps track of components that satisfy:
 *
 * * Has an intent-filter responding to [ControlsProviderService.CONTROLS_ACTION]
 * * Has the bind permission `android.permission.BIND_CONTROLS`
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000z\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u0000 -2\u00020\u0001:\u0001-B\u001f\b\u0017\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bB5\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\t\u001a\u00020\u0005\u0012\u0012\u0010\n\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\f0\u000b\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\rJ\u0010\u0010!\u001a\u00020\"2\u0006\u0010#\u001a\u00020\u0016H\u0016J\u0010\u0010$\u001a\u00020\"2\u0006\u0010%\u001a\u00020&H\u0016J\u0012\u0010\'\u001a\u0004\u0018\u00010(2\u0006\u0010)\u001a\u00020\u0010H\u0016J\u000e\u0010*\u001a\b\u0012\u0004\u0012\u00020+0\u0012H\u0016J\u0010\u0010,\u001a\u00020\"2\u0006\u0010#\u001a\u00020\u0016H\u0016R\u0014\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00100\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0011\u001a\b\u0012\u0004\u0012\u00020\u00130\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00160\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\u0019\u001a\u00020\u00182\u0006\u0010\u0017\u001a\u00020\u0018@RX\u0096\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u000e\u0010\u001c\u001a\u00020\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\n\u001a\u000e\u0012\u0004\u0012\u00020\u0003\u0012\u0004\u0012\u00020\f0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsListingControllerImpl;", "Lcom/android/systemui/controls/management/ControlsListingController;", "context", "Landroid/content/Context;", "executor", "Ljava/util/concurrent/Executor;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "(Landroid/content/Context;Ljava/util/concurrent/Executor;Lcom/android/systemui/settings/UserTracker;)V", "backgroundExecutor", "serviceListingBuilder", "Lkotlin/Function1;", "Lcom/android/settingslib/applications/ServiceListing;", "(Landroid/content/Context;Ljava/util/concurrent/Executor;Lkotlin/jvm/functions/Function1;Lcom/android/systemui/settings/UserTracker;)V", "availableComponents", "", "Landroid/content/ComponentName;", "availableServices", "", "Landroid/content/pm/ServiceInfo;", "callbacks", "", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "<set-?>", "", "currentUserId", "getCurrentUserId", "()I", "serviceListing", "serviceListingCallback", "Lcom/android/settingslib/applications/ServiceListing$Callback;", "userChangeInProgress", "Ljava/util/concurrent/atomic/AtomicInteger;", "addCallback", "", "listener", "changeUser", "newUser", "Landroid/os/UserHandle;", "getAppLabel", "", "name", "getCurrentServices", "Lcom/android/systemui/controls/ControlsServiceInfo;", "removeCallback", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class ControlsListingControllerImpl implements com.android.systemui.controls.management.ControlsListingController {
    private com.android.settingslib.applications.ServiceListing serviceListing;
    private final java.util.Set<com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback> callbacks = null;
    private java.util.Set<android.content.ComponentName> availableComponents;
    private java.util.List<? extends android.content.pm.ServiceInfo> availableServices;
    private java.util.concurrent.atomic.AtomicInteger userChangeInProgress;
    private int currentUserId;
    private final com.android.settingslib.applications.ServiceListing.Callback serviceListingCallback = null;
    private final android.content.Context context = null;
    private final java.util.concurrent.Executor backgroundExecutor = null;
    private final kotlin.jvm.functions.Function1<android.content.Context, com.android.settingslib.applications.ServiceListing> serviceListingBuilder = null;
    private static final java.lang.String TAG = "ControlsListingControllerImpl";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlsListingControllerImpl.Companion Companion = null;
    
    @java.lang.Override()
    public int getCurrentUserId() {
        return 0;
    }
    
    @java.lang.Override()
    public void changeUser(@org.jetbrains.annotations.NotNull()
    android.os.UserHandle newUser) {
    }
    
    /**
     * Adds a callback to this controller.
     *
     * The callback will be notified after it is added as well as any time that the valid
     * components change.
     *
     * @param listener a callback to be notified
     */
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listener) {
    }
    
    /**
     * Removes a callback from this controller.
     *
     * @param listener the callback to be removed.
     */
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listener) {
    }
    
    /**
     * @return a list of components that satisfy the requirements to be a
     *        [ControlsProviderService]
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.controls.ControlsServiceInfo> getCurrentServices() {
        return null;
    }
    
    /**
     * Get the localized label for the component.
     *
     * @param name the name of the component
     * @return a label as returned by [CandidateInfo.loadLabel] or `null`.
     */
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public java.lang.CharSequence getAppLabel(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName name) {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public ControlsListingControllerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor backgroundExecutor, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.Context, ? extends com.android.settingslib.applications.ServiceListing> serviceListingBuilder, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker) {
        super();
    }
    
    @javax.inject.Inject()
    public ControlsListingControllerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsListingControllerImpl$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}