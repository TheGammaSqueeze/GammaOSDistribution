package com.android.systemui.statusbar.notification.collection.coordinator;

import android.os.Handler;
import android.util.Log;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager.RemoteInputListener;
import com.android.systemui.statusbar.RemoteInputController;
import com.android.systemui.statusbar.RemoteInputNotificationRebuilder;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.notifcollection.SelfTrackingLifetimeExtender;
import com.android.systemui.statusbar.notification.collection.notifcollection.InternalNotifUpdater;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00ae\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u00012\u00020\u00022\u00020\u0003:\u0003EFGB1\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\b\b\u0001\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ\u0010\u0010(\u001a\u00020)2\u0006\u0010*\u001a\u00020+H\u0016J-\u0010,\u001a\u00020)2\u0006\u0010-\u001a\u00020.2\u0006\u0010/\u001a\u0002002\u000e\u00101\u001a\n\u0012\u0006\b\u0001\u0012\u00020302H\u0016\u00a2\u0006\u0002\u00104J\f\u00105\u001a\b\u0012\u0004\u0012\u0002060!J\u0010\u00107\u001a\u0002082\u0006\u00109\u001a\u000203H\u0016J\b\u0010:\u001a\u00020)H\u0016J\u0010\u0010;\u001a\u00020)2\u0006\u0010<\u001a\u00020=H\u0016J\u0018\u0010>\u001a\u00020)2\u0006\u0010<\u001a\u00020=2\u0006\u0010?\u001a\u00020@H\u0002J\u0010\u0010A\u001a\u00020)2\u0006\u0010<\u001a\u00020=H\u0016J\u0010\u0010B\u001a\u00020)2\u0006\u0010C\u001a\u00020DH\u0016R\u0011\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0014X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0015\u001a\u00060\u0016R\u00020\u00008\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u0017\u0010\u0018\u001a\u0004\b\u0019\u0010\u001aR \u0010\u001b\u001a\u00060\u001cR\u00020\u00008\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b\u001d\u0010\u0018\u001a\u0004\b\u001e\u0010\u001fR\u0014\u0010 \u001a\b\u0012\u0004\u0012\u00020\"0!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010#\u001a\u00060$R\u00020\u00008\u0006X\u0087\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b%\u0010\u0018\u001a\u0004\b&\u0010\'"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "Lcom/android/systemui/statusbar/NotificationRemoteInputManager$RemoteInputListener;", "Lcom/android/systemui/Dumpable;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "mRebuilder", "Lcom/android/systemui/statusbar/RemoteInputNotificationRebuilder;", "mNotificationRemoteInputManager", "Lcom/android/systemui/statusbar/NotificationRemoteInputManager;", "mMainHandler", "Landroid/os/Handler;", "mSmartReplyController", "Lcom/android/systemui/statusbar/SmartReplyController;", "(Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/statusbar/RemoteInputNotificationRebuilder;Lcom/android/systemui/statusbar/NotificationRemoteInputManager;Landroid/os/Handler;Lcom/android/systemui/statusbar/SmartReplyController;)V", "mCollectionListener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "getMCollectionListener", "()Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "mNotifUpdater", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/InternalNotifUpdater;", "mRemoteInputActiveExtender", "Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$RemoteInputActiveExtender;", "getMRemoteInputActiveExtender$annotations", "()V", "getMRemoteInputActiveExtender", "()Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$RemoteInputActiveExtender;", "mRemoteInputHistoryExtender", "Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$RemoteInputHistoryExtender;", "getMRemoteInputHistoryExtender$annotations", "getMRemoteInputHistoryExtender", "()Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$RemoteInputHistoryExtender;", "mRemoteInputLifetimeExtenders", "", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/SelfTrackingLifetimeExtender;", "mSmartReplyHistoryExtender", "Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$SmartReplyHistoryExtender;", "getMSmartReplyHistoryExtender$annotations", "getMSmartReplyHistoryExtender", "()Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$SmartReplyHistoryExtender;", "attach", "", "pipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getLifetimeExtenders", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifLifetimeExtender;", "isNotificationKeptForRemoteInputHistory", "", "key", "onPanelCollapsed", "onRemoteInputSent", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "onSmartReplySent", "reply", "", "releaseNotificationIfKeptForRemoteInputHistory", "setRemoteInputController", "remoteInputController", "Lcom/android/systemui/statusbar/RemoteInputController;", "RemoteInputActiveExtender", "RemoteInputHistoryExtender", "SmartReplyHistoryExtender"})
@com.android.systemui.dagger.SysUISingleton()
public final class RemoteInputCoordinator implements com.android.systemui.statusbar.notification.collection.coordinator.Coordinator, com.android.systemui.statusbar.NotificationRemoteInputManager.RemoteInputListener, com.android.systemui.Dumpable {
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator.RemoteInputHistoryExtender mRemoteInputHistoryExtender = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator.SmartReplyHistoryExtender mSmartReplyHistoryExtender = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator.RemoteInputActiveExtender mRemoteInputActiveExtender = null;
    private final java.util.List<com.android.systemui.statusbar.notification.collection.notifcollection.SelfTrackingLifetimeExtender> mRemoteInputLifetimeExtenders = null;
    private com.android.systemui.statusbar.notification.collection.notifcollection.InternalNotifUpdater mNotifUpdater;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener mCollectionListener = null;
    private final com.android.systemui.statusbar.RemoteInputNotificationRebuilder mRebuilder = null;
    private final com.android.systemui.statusbar.NotificationRemoteInputManager mNotificationRemoteInputManager = null;
    private final android.os.Handler mMainHandler = null;
    private final com.android.systemui.statusbar.SmartReplyController mSmartReplyController = null;
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getMRemoteInputHistoryExtender$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator.RemoteInputHistoryExtender getMRemoteInputHistoryExtender() {
        return null;
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getMSmartReplyHistoryExtender$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator.SmartReplyHistoryExtender getMSmartReplyHistoryExtender() {
        return null;
    }
    
    @androidx.annotation.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getMRemoteInputActiveExtender$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator.RemoteInputActiveExtender getMRemoteInputActiveExtender() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender> getLifetimeExtenders() {
        return null;
    }
    
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener getMCollectionListener() {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @java.lang.Override()
    public void onRemoteInputSent(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    private final void onSmartReplySent(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, java.lang.CharSequence reply) {
    }
    
    @java.lang.Override()
    public void onPanelCollapsed() {
    }
    
    @java.lang.Override()
    public boolean isNotificationKeptForRemoteInputHistory(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return false;
    }
    
    @java.lang.Override()
    public void releaseNotificationIfKeptForRemoteInputHistory(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    @java.lang.Override()
    public void setRemoteInputController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.RemoteInputController remoteInputController) {
    }
    
    @javax.inject.Inject()
    public RemoteInputCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.RemoteInputNotificationRebuilder mRebuilder, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationRemoteInputManager mNotificationRemoteInputManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler mMainHandler, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.SmartReplyController mSmartReplyController) {
        super();
    }
    
    @androidx.annotation.VisibleForTesting()
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\b\u0087\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0005\u001a\u00020\u0006H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$RemoteInputHistoryExtender;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/SelfTrackingLifetimeExtender;", "(Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator;)V", "onStartedLifetimeExtension", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "queryShouldExtendLifetime", ""})
    public final class RemoteInputHistoryExtender extends com.android.systemui.statusbar.notification.collection.notifcollection.SelfTrackingLifetimeExtender {
        
        @java.lang.Override()
        public boolean queryShouldExtendLifetime(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
            return false;
        }
        
        @java.lang.Override()
        public void onStartedLifetimeExtension(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        }
        
        public RemoteInputHistoryExtender() {
            super(null, null, false, null);
        }
    }
    
    @androidx.annotation.VisibleForTesting()
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\b\u0087\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016J\u0010\u0010\u0007\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016J\u0010\u0010\b\u001a\u00020\t2\u0006\u0010\u0005\u001a\u00020\u0006H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$SmartReplyHistoryExtender;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/SelfTrackingLifetimeExtender;", "(Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator;)V", "onCanceledLifetimeExtension", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "onStartedLifetimeExtension", "queryShouldExtendLifetime", ""})
    public final class SmartReplyHistoryExtender extends com.android.systemui.statusbar.notification.collection.notifcollection.SelfTrackingLifetimeExtender {
        
        @java.lang.Override()
        public boolean queryShouldExtendLifetime(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
            return false;
        }
        
        @java.lang.Override()
        public void onStartedLifetimeExtension(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        }
        
        @java.lang.Override()
        public void onCanceledLifetimeExtension(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        }
        
        public SmartReplyHistoryExtender() {
            super(null, null, false, null);
        }
    }
    
    @androidx.annotation.VisibleForTesting()
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\b\u0087\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator$RemoteInputActiveExtender;", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/SelfTrackingLifetimeExtender;", "(Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator;)V", "queryShouldExtendLifetime", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;"})
    public final class RemoteInputActiveExtender extends com.android.systemui.statusbar.notification.collection.notifcollection.SelfTrackingLifetimeExtender {
        
        @java.lang.Override()
        public boolean queryShouldExtendLifetime(@org.jetbrains.annotations.NotNull()
        com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
            return false;
        }
        
        public RemoteInputActiveExtender() {
            super(null, null, false, null);
        }
    }
}