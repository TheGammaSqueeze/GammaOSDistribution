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
 * Wraps a [PeopleHubViewBoundary] in a [DataListener], and connects it to the data
 * pipeline.
 *
 * @param dataSource PeopleHub data pipeline.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u001a\b\u0007\u0012\u0011\u0010\u0002\u001a\r\u0012\t\u0012\u00070\u0004\u00a2\u0006\u0002\b\u00050\u0003\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\nH\u0016R\u0019\u0010\u0002\u001a\r\u0012\t\u0012\u00070\u0004\u00a2\u0006\u0002\b\u00050\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubViewAdapterImpl;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewAdapter;", "dataSource", "Lcom/android/systemui/statusbar/notification/people/DataSource;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactory;", "Lkotlin/jvm/JvmSuppressWildcards;", "(Lcom/android/systemui/statusbar/notification/people/DataSource;)V", "bindView", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "viewBoundary", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewBoundary;"})
@com.android.systemui.dagger.SysUISingleton()
public final class PeopleHubViewAdapterImpl implements com.android.systemui.statusbar.notification.people.PeopleHubViewAdapter {
    private final com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory> dataSource = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.people.Subscription bindView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubViewBoundary viewBoundary) {
        return null;
    }
    
    @javax.inject.Inject()
    public PeopleHubViewAdapterImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory> dataSource) {
        super();
    }
}