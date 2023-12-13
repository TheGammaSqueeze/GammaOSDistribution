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

@SectionHeaderScope()
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001a\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\bg\u0018\u00002\u00020\u0001:\u0001\nR\u0012\u0010\u0002\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u0012\u0010\u0006\u001a\u00020\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\t"}, d2 = {"Lcom/android/systemui/statusbar/notification/dagger/SectionHeaderControllerSubcomponent;", "", "headerController", "Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;", "getHeaderController", "()Lcom/android/systemui/statusbar/notification/collection/render/SectionHeaderController;", "nodeController", "Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "getNodeController", "()Lcom/android/systemui/statusbar/notification/collection/render/NodeController;", "Builder"})
@dagger.Subcomponent(modules = {com.android.systemui.statusbar.notification.dagger.SectionHeaderBindingModule.class})
public abstract interface SectionHeaderControllerSubcomponent {
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.notification.collection.render.NodeController getNodeController();
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.notification.collection.render.SectionHeaderController getHeaderController();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\bg\u0018\u00002\u00020\u0001J\b\u0010\u0002\u001a\u00020\u0003H&J\u0012\u0010\u0004\u001a\u00020\u00002\b\b\u0001\u0010\u0004\u001a\u00020\u0005H\'J\u0012\u0010\u0006\u001a\u00020\u00002\b\b\u0001\u0010\u0006\u001a\u00020\u0007H\'J\u0012\u0010\b\u001a\u00020\u00002\b\b\u0001\u0010\b\u001a\u00020\u0005H\'"}, d2 = {"Lcom/android/systemui/statusbar/notification/dagger/SectionHeaderControllerSubcomponent$Builder;", "", "build", "Lcom/android/systemui/statusbar/notification/dagger/SectionHeaderControllerSubcomponent;", "clickIntentAction", "", "headerText", "", "nodeLabel"})
    @dagger.Subcomponent.Builder()
    public static abstract interface Builder {
        
        @org.jetbrains.annotations.NotNull()
        public abstract com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent build();
        
        @org.jetbrains.annotations.NotNull()
        @dagger.BindsInstance()
        public abstract com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder nodeLabel(@org.jetbrains.annotations.NotNull()
        @NodeLabel()
        java.lang.String nodeLabel);
        
        @org.jetbrains.annotations.NotNull()
        @dagger.BindsInstance()
        public abstract com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder headerText(@android.annotation.StringRes()
        @HeaderText()
        int headerText);
        
        @org.jetbrains.annotations.NotNull()
        @dagger.BindsInstance()
        public abstract com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent.Builder clickIntentAction(@org.jetbrains.annotations.NotNull()
        @HeaderClickAction()
        java.lang.String clickIntentAction);
    }
}