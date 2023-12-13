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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\b\u0002\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\u0010\u0010\u0006\u001a\u00020\u00072\u0006\u0010\b\u001a\u00020\u0002H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubDataListenerImpl;", "Lcom/android/systemui/statusbar/notification/people/DataListener;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactory;", "viewBoundary", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewBoundary;", "(Lcom/android/systemui/statusbar/notification/people/PeopleHubViewBoundary;)V", "onDataChanged", "", "data"})
final class PeopleHubDataListenerImpl implements com.android.systemui.statusbar.notification.people.DataListener<com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory> {
    private final com.android.systemui.statusbar.notification.people.PeopleHubViewBoundary viewBoundary = null;
    
    @java.lang.Override()
    public void onDataChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory data) {
    }
    
    public PeopleHubDataListenerImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubViewBoundary viewBoundary) {
        super();
    }
}