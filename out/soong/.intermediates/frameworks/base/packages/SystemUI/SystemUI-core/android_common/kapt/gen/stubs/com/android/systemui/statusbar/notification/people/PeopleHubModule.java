package com.android.systemui.statusbar.notification.people;

import dagger.Binds;
import dagger.Module;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\b\'\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\'J\u0016\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\t0\b2\u0006\u0010\n\u001a\u00020\u000bH\'J\u0010\u0010\f\u001a\u00020\r2\u0006\u0010\n\u001a\u00020\u000eH\'J\u0016\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00100\b2\u0006\u0010\n\u001a\u00020\u0011H\'J\u0016\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u00130\b2\u0006\u0010\n\u001a\u00020\u0014H\'J\u0010\u0010\u0015\u001a\u00020\u00162\u0006\u0010\n\u001a\u00020\u0017H\'"}, d2 = {"Lcom/android/systemui/statusbar/notification/people/PeopleHubModule;", "", "()V", "notificationPersonExtractor", "Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractor;", "pluginImpl", "Lcom/android/systemui/statusbar/notification/people/NotificationPersonExtractorPluginBoundary;", "peopleHubDataSource", "Lcom/android/systemui/statusbar/notification/people/DataSource;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubModel;", "impl", "Lcom/android/systemui/statusbar/notification/people/PeopleHubDataSourceImpl;", "peopleHubSectionFooterViewAdapter", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewAdapter;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewAdapterImpl;", "peopleHubSettingChangeDataSource", "", "Lcom/android/systemui/statusbar/notification/people/PeopleHubSettingChangeDataSourceImpl;", "peopleHubViewModelFactoryDataSource", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactory;", "Lcom/android/systemui/statusbar/notification/people/PeopleHubViewModelFactoryDataSourceImpl;", "peopleNotificationIdentifier", "Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifier;", "Lcom/android/systemui/statusbar/notification/people/PeopleNotificationIdentifierImpl;"})
@dagger.Module()
public abstract class PeopleHubModule {
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.people.PeopleHubViewAdapter peopleHubSectionFooterViewAdapter(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubViewAdapterImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubModel> peopleHubDataSource(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubDataSourceImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.people.DataSource<java.lang.Boolean> peopleHubSettingChangeDataSource(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubSettingChangeDataSourceImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.people.DataSource<com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactory> peopleHubViewModelFactoryDataSource(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleHubViewModelFactoryDataSourceImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier peopleNotificationIdentifier(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifierImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.people.NotificationPersonExtractor notificationPersonExtractor(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.people.NotificationPersonExtractorPluginBoundary pluginImpl);
    
    public PeopleHubModule() {
        super();
    }
}