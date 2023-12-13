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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b#\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\'"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/dagger/InternalCoordinatorsModule;", "", "()V", "bindNotifCoordinators", "Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinators;", "impl", "Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinatorsImpl;"})
@dagger.Module(includes = {com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinatorModule.class})
abstract class InternalCoordinatorsModule {
    
    @org.jetbrains.annotations.NotNull()
    @Internal()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators bindNotifCoordinators(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinatorsImpl impl);
    
    public InternalCoordinatorsModule() {
        super();
    }
}