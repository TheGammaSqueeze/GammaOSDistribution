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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0012\u0010\u0002\u001a\u0004\u0018\u00010\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0012\u0010\u0006\u001a\u0004\u0018\u00010\u00072\u0006\u0010\u0004\u001a\u00020\u0005H&J\u0010\u0010\b\u001a\u00020\t2\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractor;", "", "extractPerson", "Lcom/android/systemui/statusbar/notification/people/PersonModel;", "sbn", "Landroid/service/notification/StatusBarNotification;", "extractPersonKey", "", "isPersonNotification", ""})
public abstract interface NotificationPersonExtractor {
    
    @org.jetbrains.annotations.Nullable()
    public abstract com.android.systemui.statusbar.notification.people.PersonModel extractPerson(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn);
    
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.String extractPersonKey(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn);
    
    public abstract boolean isPersonNotification(@org.jetbrains.annotations.NotNull()
    android.service.notification.StatusBarNotification sbn);
}