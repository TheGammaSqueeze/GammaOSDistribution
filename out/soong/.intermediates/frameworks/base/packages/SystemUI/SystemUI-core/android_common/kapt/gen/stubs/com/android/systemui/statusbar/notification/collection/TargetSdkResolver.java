package com.android.systemui.statusbar.notification.collection;

import android.content.Context;
import android.content.pm.PackageManager;
import android.service.notification.StatusBarNotification;
import android.util.Log;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.statusbar.phone.StatusBar;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nJ\u0010\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eH\u0002R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/TargetSdkResolver;", "", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "TAG", "", "initialize", "", "collection", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/CommonNotifCollection;", "resolveNotificationSdk", "", "sbn", "Landroid/service/notification/StatusBarNotification;"})
@com.android.systemui.dagger.SysUISingleton()
public final class TargetSdkResolver {
    private final java.lang.String TAG = "TargetSdkResolver";
    private final android.content.Context context = null;
    
    public final void initialize(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection collection) {
    }
    
    private final int resolveNotificationSdk(android.service.notification.StatusBarNotification sbn) {
        return 0;
    }
    
    @javax.inject.Inject()
    public TargetSdkResolver(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super();
    }
}