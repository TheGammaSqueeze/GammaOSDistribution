package com.android.systemui.statusbar.notification.collection.coordinator.dagger;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators;
import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinatorsImpl;
import com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinatorModule;
import dagger.Binds;
import dagger.Module;
import dagger.Provides;
import dagger.Subcomponent;
import javax.inject.Qualifier;
import javax.inject.Scope;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u00c7\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0007"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/dagger/CoordinatorsModule;", "", "()V", "notifCoordinators", "Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinators;", "factory", "Lcom/android/systemui/statusbar/notification/collection/coordinator/dagger/CoordinatorsSubcomponent$Factory;"})
@dagger.Module(subcomponents = {com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorsSubcomponent.class})
public final class CoordinatorsModule {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorsModule INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Provides()
    @com.android.systemui.dagger.SysUISingleton()
    public static final com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators notifCoordinators(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorsSubcomponent.Factory factory) {
        return null;
    }
    
    private CoordinatorsModule() {
        super();
    }
}