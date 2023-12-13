package com.android.systemui.statusbar.notification;

import android.content.Context;
import android.provider.DeviceConfig;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.util.DeviceConfigProxy;
import com.android.systemui.util.Utils;
import javax.inject.Inject;

/**
 * Feature controller for the NOTIFICATIONS_USE_PEOPLE_FILTERING config.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00000\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u0015\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0000\u0018\u00002\u00020\u0001B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u000b\u001a\u00020\fH\u0007J\u0006\u0010\r\u001a\u00020\u000eJ\u0006\u0010\u000f\u001a\u00020\u0010J\u0006\u0010\u0011\u001a\u00020\u0012J\u0006\u0010\u0013\u001a\u00020\u0012R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/statusbar/notification/NotificationSectionsFeatureManager;", "", "proxy", "Lcom/android/systemui/util/DeviceConfigProxy;", "context", "Landroid/content/Context;", "(Lcom/android/systemui/util/DeviceConfigProxy;Landroid/content/Context;)V", "getContext", "()Landroid/content/Context;", "getProxy", "()Lcom/android/systemui/util/DeviceConfigProxy;", "clearCache", "", "getNotificationBuckets", "", "getNumberOfBuckets", "", "isFilteringEnabled", "", "isMediaControlsEnabled"})
public final class NotificationSectionsFeatureManager {
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.DeviceConfigProxy proxy = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    
    public final boolean isFilteringEnabled() {
        return false;
    }
    
    public final boolean isMediaControlsEnabled() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final int[] getNotificationBuckets() {
        return null;
    }
    
    public final int getNumberOfBuckets() {
        return 0;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    public final void clearCache() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.DeviceConfigProxy getProxy() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @javax.inject.Inject()
    public NotificationSectionsFeatureManager(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.DeviceConfigProxy proxy, @org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}