package com.android.systemui.statusbar.notification.stack;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.LinearLayout;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController;
import com.android.systemui.statusbar.notification.NotificationEntryListener;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.row.DungeonRow;
import com.android.systemui.util.Assert;
import javax.inject.Inject;

/**
 * Controller for the bottom area of NotificationStackScrollLayout. It owns swiped-away foreground
 * service notifications and can reinstantiate them when requested.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\b\n\u0000\b\u0007\u0018\u00002\u00020\u0001B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u0014\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\rH\u0002J\u000e\u0010\u0017\u001a\u00020\u000f2\u0006\u0010\u0018\u001a\u00020\u0019J\u000e\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u0016\u001a\u00020\rJ\u000e\u0010\u001c\u001a\u00020\u00152\u0006\u0010\t\u001a\u00020\nJ\u0010\u0010\u001d\u001a\u00020\u00152\u0006\u0010\u0016\u001a\u00020\rH\u0002J\"\u0010\u001e\u001a\u00020\u001b2\u0006\u0010\u001f\u001a\u00020\b2\b\u0010\u0016\u001a\u0004\u0018\u00010\r2\u0006\u0010 \u001a\u00020!H\u0002J\b\u0010\"\u001a\u00020\u0015H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R\u0010\u0010\t\u001a\u0004\u0018\u00010\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\r0\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u000e\u001a\u0004\u0018\u00010\u000fX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0012\u0010\u0013"}, d2 = {"Lcom/android/systemui/statusbar/notification/stack/ForegroundServiceSectionController;", "", "entryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "featureController", "Lcom/android/systemui/statusbar/notification/ForegroundServiceDismissalFeatureController;", "(Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/statusbar/notification/ForegroundServiceDismissalFeatureController;)V", "TAG", "", "context", "Landroid/content/Context;", "entries", "", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "entriesView", "Landroid/view/View;", "getEntryManager", "()Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "getFeatureController", "()Lcom/android/systemui/statusbar/notification/ForegroundServiceDismissalFeatureController;", "addEntry", "", "entry", "createView", "li", "Landroid/view/LayoutInflater;", "hasEntry", "", "initialize", "removeEntry", "shouldInterceptRemoval", "key", "reason", "", "update"})
@com.android.systemui.dagger.SysUISingleton()
public final class ForegroundServiceSectionController {
    private final java.lang.String TAG = "FgsSectionController";
    private android.content.Context context;
    private final java.util.Set<com.android.systemui.statusbar.notification.collection.NotificationEntry> entries = null;
    private android.view.View entriesView;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.NotificationEntryManager entryManager = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController featureController = null;
    
    private final boolean shouldInterceptRemoval(java.lang.String key, com.android.systemui.statusbar.notification.collection.NotificationEntry entry, int reason) {
        return false;
    }
    
    private final void removeEntry(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    private final void addEntry(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    public final boolean hasEntry(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return false;
    }
    
    public final void initialize(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.View createView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater li) {
        return null;
    }
    
    private final void update() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.NotificationEntryManager getEntryManager() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController getFeatureController() {
        return null;
    }
    
    @javax.inject.Inject()
    public ForegroundServiceSectionController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager entryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController featureController) {
        super();
    }
}