package com.android.systemui.statusbar.window;

import android.view.LayoutInflater;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import dagger.Module;
import dagger.Provides;
import javax.inject.Qualifier;

/**
 * Module providing dependencies related to the status bar window.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\f\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0003\b\'\u0018\u0000 \u00032\u00020\u0001:\u0002\u0003\u0004B\u0005\u00a2\u0006\u0002\u0010\u0002"}, d2 = {"Lcom/android/systemui/statusbar/window/StatusBarWindowModule;", "", "()V", "Companion", "InternalWindowView"})
@dagger.Module()
public abstract class StatusBarWindowModule {
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.statusbar.window.StatusBarWindowModule.Companion Companion = null;
    
    public StatusBarWindowModule() {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @com.android.systemui.statusbar.window.StatusBarWindowModule.InternalWindowView()
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public static final com.android.systemui.statusbar.window.StatusBarWindowView providesStatusBarWindowView(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater layoutInflater) {
        return null;
    }
    
    /**
     * We want [StatusBarWindowView] to be provided to [StatusBarWindowController]'s constructor via
     * dagger so that we can provide a fake window view when testing the controller. However, we wan
     * want *only* the controller to be able to inject the window view.
     *
     * This protected qualifier annotation achieves this. [StatusBarWindowView] can only be injected
     * if it's annotated with [InternalWindowView], and only classes inside this [statusbar.window]
     * package can access the annotation.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0085\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/statusbar/window/StatusBarWindowModule$InternalWindowView;", ""})
    @java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.CLASS)
    @javax.inject.Qualifier()
    @kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.BINARY)
    public static abstract @interface InternalWindowView {
    }
    
    /**
     * Provides a [StatusBarWindowView].
     *
     * Only [StatusBarWindowController] should inject the view.
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0087\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0010\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u0006H\u0007"}, d2 = {"Lcom/android/systemui/statusbar/window/StatusBarWindowModule$Companion;", "", "()V", "providesStatusBarWindowView", "Lcom/android/systemui/statusbar/window/StatusBarWindowView;", "layoutInflater", "Landroid/view/LayoutInflater;"})
    @dagger.Module()
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        @com.android.systemui.statusbar.window.StatusBarWindowModule.InternalWindowView()
        @com.android.systemui.dagger.SysUISingleton()
        @dagger.Provides()
        public final com.android.systemui.statusbar.window.StatusBarWindowView providesStatusBarWindowView(@org.jetbrains.annotations.NotNull()
        android.view.LayoutInflater layoutInflater) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}