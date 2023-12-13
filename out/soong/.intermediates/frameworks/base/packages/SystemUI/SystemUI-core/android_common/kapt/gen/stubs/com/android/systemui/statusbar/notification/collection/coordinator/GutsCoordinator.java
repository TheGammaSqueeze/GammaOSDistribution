package com.android.systemui.statusbar.notification.collection.coordinator;

import android.util.ArraySet;
import com.android.systemui.Dumpable;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender.OnEndLifetimeExtensionCallback;
import com.android.systemui.statusbar.notification.collection.render.NotifGutsViewListener;
import com.android.systemui.statusbar.notification.collection.render.NotifGutsViewManager;
import com.android.systemui.statusbar.notification.row.NotificationGuts;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

/**
 * Coordinates the guts displayed by the [NotificationGutsManager] with the pipeline.
 * Specifically, this just adds the lifetime extension necessary to keep guts from disappearing.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000r\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u00012\u00020\u0002B\u001f\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\u0010\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\u0017H\u0016J\u0010\u0010\u0018\u001a\u00020\u00152\u0006\u0010\u0019\u001a\u00020\u001aH\u0002J+\u0010\u001b\u001a\u00020\u00152\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001f2\f\u0010 \u001a\b\u0012\u0004\u0012\u00020\u00100!H\u0016\u00a2\u0006\u0002\u0010\"J\u0010\u0010#\u001a\u00020$2\u0006\u0010\u0019\u001a\u00020%H\u0002R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000e\u001a\b\u0012\u0004\u0012\u00020\u00100\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0011\u001a\b\u0012\u0004\u0012\u00020\u00100\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0012\u001a\u0004\u0018\u00010\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/GutsCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "Lcom/android/systemui/Dumpable;", "notifGutsViewManager", "Lcom/android/systemui/statusbar/notification/collection/render/NotifGutsViewManager;", "logger", "Lcom/android/systemui/statusbar/notification/collection/coordinator/GutsCoordinatorLogger;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Lcom/android/systemui/statusbar/notification/collection/render/NotifGutsViewManager;Lcom/android/systemui/statusbar/notification/collection/coordinator/GutsCoordinatorLogger;Lcom/android/systemui/dump/DumpManager;)V", "mGutsListener", "Lcom/android/systemui/statusbar/notification/collection/render/NotifGutsViewListener;", "mLifetimeExtender", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifLifetimeExtender;", "notifsExtendingLifetime", "Landroid/util/ArraySet;", "", "notifsWithOpenGuts", "onEndLifetimeExtensionCallback", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifLifetimeExtender$OnEndLifetimeExtensionCallback;", "attach", "", "pipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "closeGutsAndEndLifetimeExtension", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "isCurrentlyShowingGuts", "", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;"})
@com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorScope()
public final class GutsCoordinator implements com.android.systemui.statusbar.notification.collection.coordinator.Coordinator, com.android.systemui.Dumpable {
    
    /**
     * Keys of any Notifications for which we've been told the guts are open
     */
    private final android.util.ArraySet<java.lang.String> notifsWithOpenGuts = null;
    
    /**
     * Keys of any Notifications we've extended the lifetime for, based on guts
     */
    private final android.util.ArraySet<java.lang.String> notifsExtendingLifetime = null;
    
    /**
     * Callback for ending lifetime extension
     */
    private com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender.OnEndLifetimeExtensionCallback onEndLifetimeExtensionCallback;
    private final com.android.systemui.statusbar.notification.collection.notifcollection.NotifLifetimeExtender mLifetimeExtender = null;
    private final com.android.systemui.statusbar.notification.collection.render.NotifGutsViewListener mGutsListener = null;
    private final com.android.systemui.statusbar.notification.collection.render.NotifGutsViewManager notifGutsViewManager = null;
    private final com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinatorLogger logger = null;
    
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
    
    private final boolean isCurrentlyShowingGuts(com.android.systemui.statusbar.notification.collection.ListEntry entry) {
        return false;
    }
    
    private final void closeGutsAndEndLifetimeExtension(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    @javax.inject.Inject()
    public GutsCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.NotifGutsViewManager notifGutsViewManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinatorLogger logger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
}