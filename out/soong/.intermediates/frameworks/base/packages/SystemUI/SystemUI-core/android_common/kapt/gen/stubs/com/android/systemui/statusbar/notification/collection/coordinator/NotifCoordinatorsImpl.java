package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.Dumpable;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.ArrayList;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00ba\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0002\b\u0007\u0018\u0000 =2\u00020\u0001:\u0001=B\u00a7\u0001\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u0012\u0006\u0010\u0010\u001a\u00020\u0011\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u0012\u0006\u0010\u0018\u001a\u00020\u0019\u0012\u0006\u0010\u001a\u001a\u00020\u001b\u0012\u0006\u0010\u001c\u001a\u00020\u001d\u0012\u0006\u0010\u001e\u001a\u00020\u001f\u0012\u0006\u0010 \u001a\u00020!\u0012\u0006\u0010\"\u001a\u00020#\u0012\u0006\u0010$\u001a\u00020%\u0012\u0006\u0010&\u001a\u00020\'\u0012\u0006\u0010(\u001a\u00020)\u00a2\u0006\u0002\u0010*J\u0010\u00100\u001a\u0002012\u0006\u00102\u001a\u000203H\u0016J+\u00104\u001a\u0002012\u0006\u00105\u001a\u0002062\u0006\u00107\u001a\u0002082\f\u00109\u001a\b\u0012\u0004\u0012\u00020;0:H\u0016\u00a2\u0006\u0002\u0010<R\u0014\u0010+\u001a\b\u0012\u0004\u0012\u00020-0,X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010.\u001a\b\u0012\u0004\u0012\u00020/0,X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinatorsImpl;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinators;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "featureFlags", "Lcom/android/systemui/flags/FeatureFlags;", "hideLocallyDismissedNotifsCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/HideLocallyDismissedNotifsCoordinator;", "hideNotifsForOtherUsersCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/HideNotifsForOtherUsersCoordinator;", "keyguardCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/KeyguardCoordinator;", "rankingCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/RankingCoordinator;", "appOpsCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/AppOpsCoordinator;", "deviceProvisionedCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/DeviceProvisionedCoordinator;", "bubbleCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/BubbleCoordinator;", "headsUpCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/HeadsUpCoordinator;", "gutsCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/GutsCoordinator;", "conversationCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/ConversationCoordinator;", "preparationCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/PreparationCoordinator;", "mediaCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/MediaCoordinator;", "remoteInputCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator;", "shadeEventCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/ShadeEventCoordinator;", "smartspaceDedupingCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/SmartspaceDedupingCoordinator;", "viewConfigCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/ViewConfigCoordinator;", "visualStabilityCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/VisualStabilityCoordinator;", "sensitiveContentCoordinator", "Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinator;", "(Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/flags/FeatureFlags;Lcom/android/systemui/statusbar/notification/collection/coordinator/HideLocallyDismissedNotifsCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/HideNotifsForOtherUsersCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/KeyguardCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/RankingCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/AppOpsCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/DeviceProvisionedCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/BubbleCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/HeadsUpCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/GutsCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/ConversationCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/PreparationCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/MediaCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/RemoteInputCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/ShadeEventCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/SmartspaceDedupingCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/ViewConfigCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/VisualStabilityCoordinator;Lcom/android/systemui/statusbar/notification/collection/coordinator/SensitiveContentCoordinator;)V", "mCoordinators", "", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "mOrderedSections", "Lcom/android/systemui/statusbar/notification/collection/listbuilder/pluggable/NotifSectioner;", "attach", "", "pipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "Companion"})
@com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope()
public final class NotifCoordinatorsImpl implements com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators {
    private final java.util.List<com.android.systemui.statusbar.notification.collection.coordinator.Coordinator> mCoordinators = null;
    private final java.util.List<com.android.systemui.statusbar.notification.collection.listbuilder.pluggable.NotifSectioner> mOrderedSections = null;
    private static final java.lang.String TAG = "NotifCoordinators";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinatorsImpl.Companion Companion = null;
    
    /**
     * Sends the pipeline to each coordinator when the pipeline is ready to accept
     * [Pluggable]s, [NotifCollectionListener]s and [NotifLifetimeExtender]s.
     */
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public NotifCoordinatorsImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.flags.FeatureFlags featureFlags, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.HideLocallyDismissedNotifsCoordinator hideLocallyDismissedNotifsCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.HideNotifsForOtherUsersCoordinator hideNotifsForOtherUsersCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.KeyguardCoordinator keyguardCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.RankingCoordinator rankingCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.AppOpsCoordinator appOpsCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.DeviceProvisionedCoordinator deviceProvisionedCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.BubbleCoordinator bubbleCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.HeadsUpCoordinator headsUpCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinator gutsCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.ConversationCoordinator conversationCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.PreparationCoordinator preparationCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.MediaCoordinator mediaCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator remoteInputCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinator shadeEventCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.SmartspaceDedupingCoordinator smartspaceDedupingCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.ViewConfigCoordinator viewConfigCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.VisualStabilityCoordinator visualStabilityCoordinator, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinator sensitiveContentCoordinator) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinatorsImpl$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}