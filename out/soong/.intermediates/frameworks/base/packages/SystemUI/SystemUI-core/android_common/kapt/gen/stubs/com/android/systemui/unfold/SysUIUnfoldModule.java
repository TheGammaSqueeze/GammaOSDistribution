package com.android.systemui.unfold;

import com.android.keyguard.KeyguardUnfoldTransition;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController;
import dagger.BindsInstance;
import dagger.Module;
import dagger.Provides;
import dagger.Subcomponent;
import java.util.Optional;
import javax.inject.Named;
import javax.inject.Scope;

/**
 * Creates an injectable [SysUIUnfoldComponent] that provides objects that have been scoped with
 * [@SysUIUnfoldScope]. Since [SysUIUnfoldComponent] depends upon:
 * * [Optional<UnfoldTransitionProgressProvider>]
 * * [Optional<ScopedUnfoldTransitionProgressProvider>]
 * * [Optional<NaturalRotationProgressProvider>]
 * no objects will get constructed if these parameters are empty.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000.\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0007\u0018\u00002\u00020\u0001B\u0007\b\u0016\u00a2\u0006\u0002\u0010\u0002J`\u0010\u0003\u001a&\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00050\u0005 \u0006*\u0012\u0012\f\u0012\n \u0006*\u0004\u0018\u00010\u00050\u0005\u0018\u00010\u00040\u00042\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\b0\u00042\f\u0010\t\u001a\b\u0012\u0004\u0012\u00020\n0\u00042\u000e\b\u0001\u0010\u000b\u001a\b\u0012\u0004\u0012\u00020\f0\u00042\u0006\u0010\r\u001a\u00020\u000eH\u0007"}, d2 = {"Lcom/android/systemui/unfold/SysUIUnfoldModule;", "", "()V", "provideSysUIUnfoldComponent", "Ljava/util/Optional;", "Lcom/android/systemui/unfold/SysUIUnfoldComponent;", "kotlin.jvm.PlatformType", "provider", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;", "rotationProvider", "Lcom/android/systemui/unfold/util/NaturalRotationUnfoldProgressProvider;", "scopedProvider", "Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;", "factory", "Lcom/android/systemui/unfold/SysUIUnfoldComponent$Factory;"})
@dagger.Module(subcomponents = {com.android.systemui.unfold.SysUIUnfoldComponent.class})
public final class SysUIUnfoldModule {
    
    @com.android.systemui.dagger.SysUISingleton()
    @dagger.Provides()
    public final java.util.Optional<com.android.systemui.unfold.SysUIUnfoldComponent> provideSysUIUnfoldComponent(@org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.unfold.UnfoldTransitionProgressProvider> provider, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider> rotationProvider, @org.jetbrains.annotations.NotNull()
    @javax.inject.Named(value = "unfold_status_bar")
    java.util.Optional<com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider> scopedProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.SysUIUnfoldComponent.Factory factory) {
        return null;
    }
    
    public SysUIUnfoldModule() {
        super();
    }
}