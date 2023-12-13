package com.android.systemui.statusbar.notification.people;

import android.content.Context;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Handler;
import android.os.UserHandle;
import android.provider.Settings;
import android.view.View;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.plugins.ActivityStarter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c2\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0016"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/EmptyViewModelFactory;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactory;", "()V", "createWithAssociatedClickView", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModel;", "view", "Landroid/view/View;"})
final class EmptyViewModelFactory implements com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.people.EmptyViewModelFactory INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.people.PeopleHubViewModel createWithAssociatedClickView(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
        return null;
    }
    
    private EmptyViewModelFactory() {
        super();
    }
}