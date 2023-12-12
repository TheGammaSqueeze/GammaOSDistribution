package com.android.systemui.statusbar.notification.people;

import android.app.Notification;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.content.pm.UserInfo;
import android.graphics.drawable.Drawable;
import android.os.UserManager;
import android.service.notification.NotificationListenerService;
import android.service.notification.StatusBarNotification;
import android.util.IconDrawableFactory;
import android.util.SparseArray;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import com.android.internal.statusbar.NotificationVisibility;
import com.android.internal.widget.MessagingGroup;
import com.android.settingslib.notification.ConversationIconFactory;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.NotificationPersonExtractorPlugin;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.notification.NotificationEntryListener;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.policy.ExtensionController;
import java.util.ArrayDeque;
import java.util.concurrent.Executor;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a8\u0001\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001Bc\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\u0006\u0010\u000f\u001a\u00020\u0010\u0012\b\b\u0001\u0010\u0011\u001a\u00020\u0012\u0012\b\b\u0001\u0010\u0013\u001a\u00020\u0012\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u0012\u0006\u0010\u0016\u001a\u00020\u0017\u00a2\u0006\u0002\u0010\u0018J\u0010\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020(H\u0002J\n\u0010)\u001a\u0004\u0018\u00010\u0002H\u0002J\u0016\u0010*\u001a\u00020$2\f\u0010+\u001a\b\u0012\u0004\u0012\u00020\u00020\u001bH\u0016J\u0018\u0010,\u001a\u00020&2\u0006\u0010\'\u001a\u00020(2\u0006\u0010-\u001a\u00020.H\u0002J\b\u0010/\u001a\u00020&H\u0002J\u000e\u00100\u001a\u0004\u0018\u000101*\u00020(H\u0002J\u0014\u00102\u001a\n\u0018\u000103j\u0004\u0018\u0001`4*\u00020(H\u0002J\u001e\u00105\u001a\u0004\u0018\u000106*\u0002072\u0006\u0010\u001c\u001a\u00020\u001d2\u0006\u00108\u001a\u000209H\u0002R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0019\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00020\u001b0\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001dX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0013\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0014\u001a\u00020\u0015X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010 \u001a\b\u0012\u0004\u0012\u00020\"0!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0016\u001a\u00020\u0017X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010#\u001a\u0004\u0018\u00010$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubDataSourceImpl;", "Lcom/android/systemui/statusbar/notification/people/DataSource;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubModel;", "notificationEntryManager", "Lcom/android/systemui/statusbar/notification/NotificationEntryManager;", "extractor", "Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractor;", "userManager", "Landroid/os/UserManager;", "launcherApps", "Landroid/content/pm/LauncherApps;", "packageManager", "Landroid/content/pm/PackageManager;", "context", "Landroid/content/Context;", "notificationListener", "Lcom/android/systemui/statusbar/NotificationListener;", "bgExecutor", "Ljava/util/concurrent/Executor;", "mainExecutor", "notifLockscreenUserMgr", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "peopleNotificationIdentifier", "Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;", "(Lcom/android/systemui/statusbar/notification/NotificationEntryManager;Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractor;Landroid/os/UserManager;Landroid/content/pm/LauncherApps;Landroid/content/pm/PackageManager;Landroid/content/Context;Lcom/android/systemui/statusbar/NotificationListener;Ljava/util/concurrent/Executor;Ljava/util/concurrent/Executor;Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;)V", "dataListeners", "", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "iconFactory", "Lcom/android/settingslib/notification/ConversationIconFactory;", "notificationEntryListener", "Lcom/android/systemui/statusbar/notification/NotificationEntryListener;", "peopleHubManagerForUser", "Landroid/util/SparseArray;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubManager;", "userChangeSubscription", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "addVisibleEntry", "", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "getPeopleHubModelForCurrentUser", "registerListener", "listener", "removeVisibleEntry", "reason", "", "updateUi", "extractPerson", "Lcom/android/systemui/statusbar/notification/people/PersonModel;", "extractPersonKey", "", "Lcom/android/systemui/statusbar/notification/people/PersonKey;", "getIcon", "Landroid/graphics/drawable/Drawable;", "Landroid/service/notification/NotificationListenerService$Ranking;", "sbn", "Landroid/service/notification/StatusBarNotification;"})
@com.android.systemui.dagger.SysUISingleton()
public final class PeopleHubDataSourceImpl implements com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubModel> {
    private com.android.systemui.statusbar.notification.people.Subscription userChangeSubscription;
    private final java.util.List<com.android.systemui.statusbar.notification.people.DataListener<com.android.systemui.statusbar.notification.people.PeopleHubModel>> dataListeners = null;
    private final android.util.SparseArray<com.android.systemui.statusbar.notification.people.PeopleHubManager> peopleHubManagerForUser = null;
    private final com.android.settingslib.notification.ConversationIconFactory iconFactory = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryListener notificationEntryListener = null;
    private final com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager = null;
    private final com.android.systemui.statusbar.notification.people.NotificationPersonExtractor extractor = null;
    private final android.os.UserManager userManager = null;
    private final com.android.systemui.statusbar.NotificationListener notificationListener = null;
    private final java.util.concurrent.Executor bgExecutor = null;
    private final java.util.concurrent.Executor mainExecutor = null;
    private final com.android.systemui.statusbar.NotificationLockscreenUserManager notifLockscreenUserMgr = null;
    private final com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier = null;
    
    private final void removeVisibleEntry(com.android.systemui.statusbar.notification.collection.NotificationEntry entry, int reason) {
    }
    
    private final void addVisibleEntry(com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.people.Subscription registerListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataListener<? super com.android.systemui.statusbar.notification.people.PeopleHubModel> listener) {
        return null;
    }
    
    private final com.android.systemui.statusbar.notification.people.PeopleHubModel getPeopleHubModelForCurrentUser() {
        return null;
    }
    
    private final void updateUi() {
    }
    
    private final com.android.systemui.statusbar.notification.people.PersonModel extractPerson(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$extractPerson) {
        return null;
    }
    
    private final android.graphics.drawable.Drawable getIcon(android.service.notification.NotificationListenerService.Ranking $this$getIcon, com.android.settingslib.notification.ConversationIconFactory iconFactory, android.service.notification.StatusBarNotification sbn) {
        return null;
    }
    
    private final java.lang.String extractPersonKey(com.android.systemui.statusbar.notification.collection.NotificationEntry $this$extractPersonKey) {
        return null;
    }
    
    @javax.inject.Inject()
    public PeopleHubDataSourceImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.NotificationEntryManager notificationEntryManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.NotificationPersonExtractor extractor, @org.jetbrains.annotations.NotNull()
    android.os.UserManager userManager, @org.jetbrains.annotations.NotNull()
    android.content.pm.LauncherApps launcherApps, @org.jetbrains.annotations.NotNull()
    android.content.pm.PackageManager packageManager, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationListener notificationListener, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor bgExecutor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor mainExecutor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.NotificationLockscreenUserManager notifLockscreenUserMgr, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier) {
        super();
    }
}