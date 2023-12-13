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
 * Converts [PeopleHubModel]s into [PeopleHubViewModelFactory]s.
 *
 * This class serves as the glue between the View layer (which depends on
 * [PeopleHubViewBoundary]) and the Data layer (which produces [PeopleHubModel]s).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\"\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0011\u0010\u0005\u001a\r\u0012\t\u0012\u00070\u0006\u00a2\u0006\u0002\b\u00070\u0001\u00a2\u0006\u0002\u0010\bJ\u0016\u0010\t\u001a\u00020\n2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\u00020\fH\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0019\u0010\u0005\u001a\r\u0012\t\u0012\u00070\u0006\u00a2\u0006\u0002\b\u00070\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactoryDataSourceImpl;", "Lcom/android/systemui/statusbar/notification/people/DataSource;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactory;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "dataSource", "Lcom/android/systemui/statusbar/notification/people/PeopleHubModel;", "Lkotlin/jvm/JvmSuppressWildcards;", "(Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/statusbar/notification/people/DataSource;)V", "registerListener", "Lcom/android/systemui/statusbar/notification/people/Subscription;", "listener", "Lcom/android/systemui/statusbar/notification/people/DataListener;"})
@com.android.systemui.dagger.SysUISingleton()
public final class PeopleHubViewModelFactoryDataSourceImpl implements com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory> {
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubModel> dataSource = null;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.statusbar.notification.people.Subscription registerListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataListener<? super com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory> listener) {
        return null;
    }
    
    @javax.inject.Inject()
    public PeopleHubViewModelFactoryDataSourceImpl(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubModel> dataSource) {
        super();
    }
}