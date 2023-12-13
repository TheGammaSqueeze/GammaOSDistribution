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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u00004\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\u001a\u0010\u0010\b\u001a\u0004\u0018\u00010\t2\u0006\u0010\n\u001a\u00020\u000b\u001a\u001a\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003*\u00020\u00052\u0006\u0010\r\u001a\u00020\u0001H\u0002\u001a\u0014\u0010\u000e\u001a\u00020\u000f*\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u0012H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u001e\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003*\u00020\u00058BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0006\u0010\u0007"}, d2 = {"MAX_STORED_INACTIVE_PEOPLE", "", "children", "Lkotlin/sequences/Sequence;", "Landroid/view/View;", "Landroid/view/ViewGroup;", "getChildren", "(Landroid/view/ViewGroup;)Lkotlin/sequences/Sequence;", "extractAvatarFromRow", "Landroid/graphics/drawable/Drawable;", "entry", "Lcom/android/systemui/statusbar/notification/collection/NotificationEntry;", "childrenWithId", "id", "registerListener", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager;", "listener", "Lcom/android/systemui/statusbar/NotificationLockscreenUserManager$UserChangedListener;"})
public final class PeopleHubNotificationListenerKt {
    private static final int MAX_STORED_INACTIVE_PEOPLE = 10;
    
    private static final com.android.systemui.statusbar.notification.people.Subscription registerListener(com.android.systemui.statusbar.NotificationLockscreenUserManager $this$registerListener, com.android.systemui.statusbar.NotificationLockscreenUserManager.UserChangedListener listener) {
        return null;
    }
    
    private static final kotlin.sequences.Sequence<android.view.View> getChildren(android.view.ViewGroup $this$children) {
        return null;
    }
    
    private static final kotlin.sequences.Sequence<android.view.View> childrenWithId(android.view.ViewGroup $this$childrenWithId, int id) {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public static final android.graphics.drawable.Drawable extractAvatarFromRow(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.NotificationEntry entry) {
        return null;
    }
}