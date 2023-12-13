package com.android.systemui.unfold;

import android.content.Context;
import android.hardware.SensorManager;
import android.hardware.devicestate.DeviceStateManager;
import android.os.Handler;
import android.view.IWindowManager;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.keyguard.LifecycleScreenStatusProvider;
import com.android.systemui.unfold.config.UnfoldTransitionConfig;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import dagger.Lazy;
import dagger.Module;
import dagger.Provides;
import java.util.Optional;
import java.util.concurrent.Executor;
import javax.inject.Named;
import javax.inject.Singleton;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000`\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002JJ\u0010\u0003\u001a&\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00050\u0005 \u0006*\u0012\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00050\u0005\u0018\u00010\u00040\u00042\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\f\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\u0004H\u0007J\u001e\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u00102\f\u0010\u0011\u001a\b\u0012\u0004\u0012\u00020\f0\u0004H\u0007J:\u0010\u0012\u001a&\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00130\u0013 \u0006*\u0012\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00130\u0013\u0018\u00010\u00040\u00042\f\u0010\u0014\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004H\u0007J\u0010\u0010\u0015\u001a\u00020\u00102\u0006\u0010\u0007\u001a\u00020\bH\u0007JP\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\f0\u00042\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\u000f\u001a\u00020\u00102\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00190\u00182\u0006\u0010\u001a\u001a\u00020\u001b2\u0006\u0010\u001c\u001a\u00020\u001d2\b\b\u0001\u0010\u001e\u001a\u00020\u001f2\b\b\u0001\u0010 \u001a\u00020!H\u0007"}, d2 = {"Lcom/android/systemui/unfold/UnfoldTransitionModule;", "", "()V", "provideNaturalRotationProgressProvider", "Ljava/util/Optional;", "Lcom/android/systemui/unfold/util/NaturalRotationUnfoldProgressProvider;", "kotlin.jvm.PlatformType", "context", "Landroid/content/Context;", "windowManager", "Landroid/view/IWindowManager;", "unfoldTransitionProgressProvider", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;", "provideShellProgressProvider", "Lcom/android/wm/shell/unfold/ShellUnfoldProgressProvider;", "config", "Lcom/android/systemui/unfold/config/UnfoldTransitionConfig;", "provider", "provideStatusBarScopedTransitionProvider", "Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;", "source", "provideUnfoldTransitionConfig", "provideUnfoldTransitionProgressProvider", "screenStatusProvider", "Ldagger/Lazy;", "Lcom/android/systemui/keyguard/LifecycleScreenStatusProvider;", "deviceStateManager", "Landroid/hardware/devicestate/DeviceStateManager;", "sensorManager", "Landroid/hardware/SensorManager;", "executor", "Ljava/util/concurrent/Executor;", "handler", "Landroid/os/Handler;"})
@dagger.Module()
public final class UnfoldTransitionModule {
    
    @org.jetbrains.annotations.NotNull()
    @javax.inject.Singleton()
    @dagger.Provides()
    public final java.util.Optional<com.android.systemui.unfold.UnfoldTransitionProgressProvider> provideUnfoldTransitionProgressProvider(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.config.UnfoldTransitionConfig config, @org.jetbrains.annotations.NotNull()
    dagger.Lazy<com.android.systemui.keyguard.LifecycleScreenStatusProvider> screenStatusProvider, @org.jetbrains.annotations.NotNull()
    android.hardware.devicestate.DeviceStateManager deviceStateManager, @org.jetbrains.annotations.NotNull()
    android.hardware.SensorManager sensorManager, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @javax.inject.Singleton()
    @dagger.Provides()
    public final com.android.systemui.unfold.config.UnfoldTransitionConfig provideUnfoldTransitionConfig(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    @javax.inject.Singleton()
    @dagger.Provides()
    public final java.util.Optional<com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider> provideNaturalRotationProgressProvider(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.view.IWindowManager windowManager, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.unfold.UnfoldTransitionProgressProvider> unfoldTransitionProgressProvider) {
        return null;
    }
    
    @javax.inject.Singleton()
    @javax.inject.Named(value = "unfold_status_bar")
    @dagger.Provides()
    public final java.util.Optional<com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider> provideStatusBarScopedTransitionProvider(@org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider> source) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @javax.inject.Singleton()
    @dagger.Provides()
    public final com.android.wm.shell.unfold.ShellUnfoldProgressProvider provideShellProgressProvider(@org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.config.UnfoldTransitionConfig config, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.unfold.UnfoldTransitionProgressProvider> provider) {
        return null;
    }
    
    public UnfoldTransitionModule() {
        super();
    }
}