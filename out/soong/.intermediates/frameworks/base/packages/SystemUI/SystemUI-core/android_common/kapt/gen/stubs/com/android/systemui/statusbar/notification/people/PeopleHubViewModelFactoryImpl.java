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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactoryImpl;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactory;", "model", "Lcom/android/systemui/statusbar/notification/people/PeopleHubModel;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "(Lcom/android/systemui/statusbar/notification/people/PeopleHubModel;Lcom/android/systemui/plugins/ActivityStarter;)V", "createWithAssociatedClickView", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModel;", "view", "Landroid/view/View;"})
final class PeopleHubViewModelFactoryImpl implements com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory {
    private final com.android.systemui.statusbar.notification.people.PeopleHubModel model = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.people.PeopleHubViewModel createWithAssociatedClickView(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
        return null;
    }
    
    public PeopleHubViewModelFactoryImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubModel model, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter) {
        super();
    }
}