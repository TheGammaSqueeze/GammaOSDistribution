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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0012\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\bg\u0018\u00002\u00020\u0001:\u0001\u0006R\u0014\u0010\u0002\u001a\u00020\u00038gX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/dagger/CoordinatorsSubcomponent;", "", "notifCoordinators", "Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinators;", "getNotifCoordinators", "()Lcom/android/systemui/statusbar/notification/collection/coordinator/NotifCoordinators;", "Factory"})
@dagger.Subcomponent(modules = {com.android.systemui.statusbar.notification.collection.coordinator.dagger.InternalCoordinatorsModule.class})
@CoordinatorScope()
public abstract interface CoordinatorsSubcomponent {
    
    @org.jetbrains.annotations.NotNull()
    @Internal()
    public abstract com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators getNotifCoordinators();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u000e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\bg\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&"}, d2 = {"Lcom/android/systemui/statusbar/notification/collection/coordinator/dagger/CoordinatorsSubcomponent$Factory;", "", "create", "Lcom/android/systemui/statusbar/notification/collection/coordinator/dagger/CoordinatorsSubcomponent;"})
    @dagger.Subcomponent.Factory()
    public static abstract interface Factory {
        
        @org.jetbrains.annotations.NotNull()
        public abstract com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorsSubcomponent create();
    }
}