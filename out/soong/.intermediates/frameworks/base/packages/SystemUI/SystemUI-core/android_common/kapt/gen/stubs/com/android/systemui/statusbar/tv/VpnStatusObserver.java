package com.android.systemui.statusbar.tv;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.Context;
import com.android.internal.messages.nano.SystemMessageProto;
import com.android.internal.net.VpnConfig;
import com.android.systemui.Dependency;
import com.android.systemui.R;
import com.android.systemui.SystemUI;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.policy.SecurityController;
import javax.inject.Inject;

/**
 * Observes if a vpn connection is active and displays a notification to the user
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000T\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0002\b\u0004\b\u0007\u0018\u0000 $2\u00020\u00012\u00020\u0002:\u0001$B\u000f\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\b\u0010\u001b\u001a\u00020\u0007H\u0002J\u0010\u0010\u001c\u001a\n \n*\u0004\u0018\u00010\u00120\u0012H\u0002J\u0010\u0010\u001d\u001a\n \n*\u0004\u0018\u00010\u00100\u0010H\u0002J\u0010\u0010\u001e\u001a\n \n*\u0004\u0018\u00010\u00120\u0012H\u0002J\b\u0010\u001f\u001a\u00020 H\u0002J\b\u0010!\u001a\u00020 H\u0002J\b\u0010\"\u001a\u00020 H\u0016J\b\u0010#\u001a\u00020 H\u0016R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\b\u001a\n \n*\u0004\u0018\u00010\t0\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u000f\u001a\n \n*\u0004\u0018\u00010\u00100\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0011\u001a\n \n*\u0004\u0018\u00010\u00120\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0013\u001a\u00020\u00148BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0015\u0010\u0016R\u0016\u0010\u0017\u001a\u0004\u0018\u00010\u00188BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u001a"}, d2 = {"Lcom/android/systemui/statusbar/tv/VpnStatusObserver;", "Lcom/android/systemui/SystemUI;", "Lcom/android/systemui/statusbar/policy/SecurityController$SecurityControllerCallback;", "context", "Landroid/content/Context;", "(Landroid/content/Context;)V", "notificationChannel", "Landroid/app/NotificationChannel;", "notificationManager", "Landroid/app/NotificationManager;", "kotlin.jvm.PlatformType", "securityController", "Lcom/android/systemui/statusbar/policy/SecurityController;", "vpnConnected", "", "vpnConnectedNotificationBuilder", "Landroid/app/Notification$Builder;", "vpnDisconnectedNotification", "Landroid/app/Notification;", "vpnIconId", "", "getVpnIconId", "()I", "vpnName", "", "getVpnName", "()Ljava/lang/String;", "createNotificationChannel", "createVpnConnectedNotification", "createVpnConnectedNotificationBuilder", "createVpnDisconnectedNotification", "notifyVpnConnected", "", "notifyVpnDisconnected", "onStateChanged", "start", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class VpnStatusObserver extends com.android.systemui.SystemUI implements com.android.systemui.statusbar.policy.SecurityController.SecurityControllerCallback {
    private boolean vpnConnected = false;
    private final com.android.systemui.statusbar.policy.SecurityController securityController = null;
    private final android.app.NotificationManager notificationManager = null;
    private final android.app.NotificationChannel notificationChannel = null;
    private final android.app.Notification.Builder vpnConnectedNotificationBuilder = null;
    private final android.app.Notification vpnDisconnectedNotification = null;
    @org.jetbrains.annotations.NotNull()
    public static final java.lang.String NOTIFICATION_CHANNEL_TV_VPN = "VPN Status";
    @org.jetbrains.annotations.NotNull()
    private static final java.lang.String NOTIFICATION_TAG = null;
    private static final java.lang.String TAG = "TvVpnNotification";
    private static final long VPN_DISCONNECTED_NOTIFICATION_TIMEOUT_MS = 5000L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.tv.VpnStatusObserver.Companion Companion = null;
    
    private final int getVpnIconId() {
        return 0;
    }
    
    private final java.lang.String getVpnName() {
        return null;
    }
    
    @java.lang.Override()
    public void start() {
    }
    
    @java.lang.Override()
    public void onStateChanged() {
    }
    
    private final void notifyVpnConnected() {
    }
    
    private final void notifyVpnDisconnected() {
    }
    
    private final android.app.NotificationChannel createNotificationChannel() {
        return null;
    }
    
    private final android.app.Notification createVpnConnectedNotification() {
        return null;
    }
    
    private final android.app.Notification.Builder createVpnConnectedNotificationBuilder() {
        return null;
    }
    
    private final android.app.Notification createVpnDisconnectedNotification() {
        return null;
    }
    
    @javax.inject.Inject()
    public VpnStatusObserver(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0005\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007R\u000e\u0010\b\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/tv/VpnStatusObserver$Companion;", "", "()V", "NOTIFICATION_CHANNEL_TV_VPN", "", "NOTIFICATION_TAG", "getNOTIFICATION_TAG", "()Ljava/lang/String;", "TAG", "VPN_DISCONNECTED_NOTIFICATION_TIMEOUT_MS", ""})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getNOTIFICATION_TAG() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}