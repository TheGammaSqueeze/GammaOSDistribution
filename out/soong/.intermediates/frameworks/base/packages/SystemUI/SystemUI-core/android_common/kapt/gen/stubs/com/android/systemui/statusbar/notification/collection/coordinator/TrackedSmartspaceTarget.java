package com.android.systemui.statusbar.notification.collection.coordinator;

import android.app.smartspace.SmartspaceTarget;
import android.os.Parcelable;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.StatusBarState;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifFilter;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.time.SystemClock;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u000b\n\u0002\b\u0004\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004R\u001a\u0010\u0005\u001a\u00020\u0006X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0007\u0010\b\"\u0004\b\t\u0010\nR\u001c\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u001a\u0010\u0013\u001a\u00020\u0014X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0015\u0010\u0016\"\u0004\b\u0017\u0010\u0018"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/TrackedSmartspaceTarget;", "", "key", "", "(Ljava/lang/String;)V", "alertExceptionExpires", "", "getAlertExceptionExpires", "()J", "setAlertExceptionExpires", "(J)V", "cancelTimeoutRunnable", "Ljava/lang/Runnable;", "getCancelTimeoutRunnable", "()Ljava/lang/Runnable;", "setCancelTimeoutRunnable", "(Ljava/lang/Runnable;)V", "getKey", "()Ljava/lang/String;", "shouldFilter", "", "getShouldFilter", "()Z", "setShouldFilter", "(Z)V"})
final class TrackedSmartspaceTarget {
    @org.jetbrains.annotations.Nullable()
    private java.lang.Runnable cancelTimeoutRunnable;
    private long alertExceptionExpires = 0L;
    private boolean shouldFilter = false;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String key = null;
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Runnable getCancelTimeoutRunnable() {
        return null;
    }
    
    public final void setCancelTimeoutRunnable(@org.jetbrains.annotations.Nullable()
    java.lang.Runnable p0) {
    }
    
    public final long getAlertExceptionExpires() {
        return 0L;
    }
    
    public final void setAlertExceptionExpires(long p0) {
    }
    
    public final boolean getShouldFilter() {
        return false;
    }
    
    public final void setShouldFilter(boolean p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getKey() {
        return null;
    }
    
    public TrackedSmartspaceTarget(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        super();
    }
}