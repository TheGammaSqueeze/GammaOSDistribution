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

/**
 * Boundary between the View and PeopleHub, as seen by the View.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubViewAdapter;", "", "bindView", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "viewBoundary", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewBoundary;"})
public abstract interface PeopleHubViewAdapter {
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.notification.people.Subscription bindView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubViewBoundary viewBoundary);
}