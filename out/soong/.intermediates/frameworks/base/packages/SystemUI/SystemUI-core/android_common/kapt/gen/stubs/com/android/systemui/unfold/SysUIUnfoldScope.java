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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0087\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/unfold/SysUIUnfoldScope;", ""})
@java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.RUNTIME)
@java.lang.annotation.Documented()
@kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.RUNTIME)
@kotlin.annotation.MustBeDocumented()
@javax.inject.Scope()
public abstract @interface SysUIUnfoldScope {
}