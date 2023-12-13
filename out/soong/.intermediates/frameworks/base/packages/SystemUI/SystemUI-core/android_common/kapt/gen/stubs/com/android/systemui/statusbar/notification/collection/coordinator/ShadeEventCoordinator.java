package com.android.systemui.statusbar.notification.collection.coordinator;

import android.service.notification.NotificationListenerService;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.ListEntry;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener;
import com.android.systemui.statusbar.notification.collection.render.NotifShadeEventSource;
import javax.inject.Inject;

/**
 * A coordinator which provides callbacks to a view surfaces for various events relevant to the
 * shade, such as when the user removes a notification, or when the shade is emptied.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0007\u0018\u00002\u00020\u00012\u00020\u0002B\u000f\b\u0001\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0010\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0016J\u0016\u0010\u0012\u001a\u00020\u000f2\f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00150\u0014H\u0002J\u0010\u0010\u0016\u001a\u00020\u000f2\u0006\u0010\u0017\u001a\u00020\fH\u0016J\u0010\u0010\u0018\u001a\u00020\u000f2\u0006\u0010\u0017\u001a\u00020\fH\u0016R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000b\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\r\u001a\u0004\u0018\u00010\fX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/ShadeEventCoordinator;", "Lcom/android/systemui/statusbar/notification/collection/coordinator/Coordinator;", "Lcom/android/systemui/statusbar/notification/collection/render/NotifShadeEventSource;", "mLogger", "Lcom/android/systemui/statusbar/notification/collection/coordinator/ShadeEventCoordinatorLogger;", "(Lcom/android/systemui/statusbar/notification/collection/coordinator/ShadeEventCoordinatorLogger;)V", "mEntryRemoved", "", "mEntryRemovedByUser", "mNotifCollectionListener", "Lcom/android/systemui/statusbar/notification/collection/notifcollection/NotifCollectionListener;", "mNotifRemovedByUserCallback", "Ljava/lang/Runnable;", "mShadeEmptiedCallback", "attach", "", "pipeline", "Lcom/android/systemui/statusbar/notification/collection/NotifPipeline;", "onBeforeRenderList", "entries", "", "Lcom/android/systemui/statusbar/notification/collection/ListEntry;", "setNotifRemovedByUserCallback", "callback", "setShadeEmptiedCallback"})
@com.android.systemui.dagger.SysUISingleton()
public final class ShadeEventCoordinator implements com.android.systemui.statusbar.notification.collection.coordinator.Coordinator, com.android.systemui.statusbar.notification.collection.render.NotifShadeEventSource {
    private java.lang.Runnable mNotifRemovedByUserCallback;
    private java.lang.Runnable mShadeEmptiedCallback;
    private boolean mEntryRemoved = false;
    private boolean mEntryRemovedByUser = false;
    private final com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionListener mNotifCollectionListener = null;
    private final com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinatorLogger mLogger = null;
    
    @java.lang.Override()
    public void attach(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotifPipeline pipeline) {
    }
    
    @java.lang.Override()
    public void setNotifRemovedByUserCallback(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable callback) {
    }
    
    @java.lang.Override()
    public void setShadeEmptiedCallback(@org.jetbrains.annotations.NotNull()
    java.lang.Runnable callback) {
    }
    
    private final void onBeforeRenderList(java.util.List<? extends com.android.systemui.statusbar.notification.collection.ListEntry> entries) {
    }
    
    @javax.inject.Inject()
    public ShadeEventCoordinator(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinatorLogger mLogger) {
        super();
    }
}