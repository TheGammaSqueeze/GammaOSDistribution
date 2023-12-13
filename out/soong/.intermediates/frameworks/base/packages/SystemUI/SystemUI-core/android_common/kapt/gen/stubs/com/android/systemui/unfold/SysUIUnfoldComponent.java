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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\"\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\bg\u0018\u00002\u00020\u0001:\u0001\nJ\b\u0010\u0002\u001a\u00020\u0003H&J\b\u0010\u0004\u001a\u00020\u0005H&J\b\u0010\u0006\u001a\u00020\u0007H&J\b\u0010\b\u001a\u00020\tH&"}, d2 = {"Lcom/android/systemui/unfold/SysUIUnfoldComponent;", "", "getKeyguardUnfoldTransition", "Lcom/android/keyguard/KeyguardUnfoldTransition;", "getStatusBarMoveFromCenterAnimationController", "Lcom/android/systemui/statusbar/phone/StatusBarMoveFromCenterAnimationController;", "getUnfoldLightRevealOverlayAnimation", "Lcom/android/systemui/unfold/UnfoldLightRevealOverlayAnimation;", "getUnfoldTransitionWallpaperController", "Lcom/android/systemui/unfold/UnfoldTransitionWallpaperController;", "Factory"})
@dagger.Subcomponent()
@SysUIUnfoldScope()
public abstract interface SysUIUnfoldComponent {
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.keyguard.KeyguardUnfoldTransition getKeyguardUnfoldTransition();
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController getStatusBarMoveFromCenterAnimationController();
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.unfold.UnfoldTransitionWallpaperController getUnfoldTransitionWallpaperController();
    
    @org.jetbrains.annotations.NotNull()
    public abstract com.android.systemui.unfold.UnfoldLightRevealOverlayAnimation getUnfoldLightRevealOverlayAnimation();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\bg\u0018\u00002\u00020\u0001J&\u0010\u0002\u001a\u00020\u00032\b\b\u0001\u0010\u0004\u001a\u00020\u00052\b\b\u0001\u0010\u0006\u001a\u00020\u00072\b\b\u0001\u0010\b\u001a\u00020\tH&"}, d2 = {"Lcom/android/systemui/unfold/SysUIUnfoldComponent$Factory;", "", "create", "Lcom/android/systemui/unfold/SysUIUnfoldComponent;", "p1", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;", "p2", "Lcom/android/systemui/unfold/util/NaturalRotationUnfoldProgressProvider;", "p3", "Lcom/android/systemui/unfold/util/ScopedUnfoldTransitionProgressProvider;"})
    @dagger.Subcomponent.Factory()
    public static abstract interface Factory {
        
        @org.jetbrains.annotations.NotNull()
        public abstract com.android.systemui.unfold.SysUIUnfoldComponent create(@org.jetbrains.annotations.NotNull()
        @dagger.BindsInstance()
        com.android.systemui.unfold.UnfoldTransitionProgressProvider p1, @org.jetbrains.annotations.NotNull()
        @dagger.BindsInstance()
        com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider p2, @org.jetbrains.annotations.NotNull()
        @dagger.BindsInstance()
        com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider p3);
    }
}