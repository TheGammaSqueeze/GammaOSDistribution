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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u0007J\u0006\u0010\r\u001a\u00020\u000eJ\u0012\u0010\u000f\u001a\u00020\u000b2\n\u0010\u0010\u001a\u00060\u0005j\u0002`\u0006J\u0012\u0010\u0011\u001a\u00020\u00122\n\u0010\u0010\u001a\u00060\u0005j\u0002`\u0006R\u001e\u0010\u0003\u001a\u0012\u0012\b\u0012\u00060\u0005j\u0002`\u0006\u0012\u0004\u0012\u00020\u00070\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00070\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubManager;", "", "()V", "activePeople", "", "", "Lcom/android/systemui/statusbar/notification/people/PersonKey;", "Lcom/android/systemui/statusbar/notification/people/PersonModel;", "inactivePeople", "Ljava/util/ArrayDeque;", "addActivePerson", "", "person", "getPeopleHubModel", "Lcom/android/systemui/statusbar/notification/people/PeopleHubModel;", "migrateActivePerson", "key", "removeActivePerson", ""})
public final class PeopleHubManager {
    private final java.util.Map<java.lang.String, com.android.systemui.statusbar.notification.people.PersonModel> activePeople = null;
    private final java.util.ArrayDeque<com.android.systemui.statusbar.notification.people.PersonModel> inactivePeople = null;
    
    public final boolean migrateActivePerson(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
        return false;
    }
    
    public final void removeActivePerson(@org.jetbrains.annotations.NotNull()
    java.lang.String key) {
    }
    
    public final boolean addActivePerson(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PersonModel person) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.people.PeopleHubModel getPeopleHubModel() {
        return null;
    }
    
    public PeopleHubManager() {
        super();
    }
}