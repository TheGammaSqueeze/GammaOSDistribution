package com.android.systemui.statusbar.notification.dagger;

import android.annotation.StringRes;
import android.provider.Settings;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderNodeControllerImpl;
import dagger.Binds;
import dagger.BindsInstance;
import dagger.Module;
import dagger.Provides;
import dagger.Subcomponent;
import javax.inject.Provider;
import javax.inject.Qualifier;
import javax.inject.Scope;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b#\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\'J\u0010\u0010\u0007\u001a\u00020\b2\u0006\u0010\u0005\u001a\u00020\u0006H\'"}, d2 = {"Lcom/android/systemui/statusbar/notification/dagger/SectionHeaderBindingModule;", "", "()V", "bindsNodeController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "impl", "Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderNodeControllerImpl;", "bindsSectionHeaderController", "Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;"})
@dagger.Module()
abstract class SectionHeaderBindingModule {
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.collection.render.NodeController bindsNodeController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.SectionHeaderNodeControllerImpl impl);
    
    @org.jetbrains.annotations.NotNull()
    @dagger.Binds()
    public abstract com.android.systemui.statusbar.notification.collection.render.SectionHeaderController bindsSectionHeaderController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.collection.render.SectionHeaderNodeControllerImpl impl);
    
    public SectionHeaderBindingModule() {
        super();
    }
}