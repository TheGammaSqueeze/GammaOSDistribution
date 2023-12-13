package com.android.keyguard;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import com.android.systemui.R;
import com.android.systemui.unfold.SysUIUnfoldScope;
import com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
import javax.inject.Inject;

/**
 * Translates items away/towards the hinge when the device is opened/closed. This is controlled by
 * the set of ids, which also dictact which direction to move and when, via a filter function.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000R\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\b\u0007\u0018\u0000 $2\u00020\u0001:\u0001$B\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u001f\u001a\u00020 H\u0002J\u000e\u0010!\u001a\u00020 2\u0006\u0010\u0011\u001a\u00020\u0012J\u0010\u0010\"\u001a\u00020 2\u0006\u0010#\u001a\u00020\u001eH\u0002R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0014\u0010\t\u001a\b\u0012\u0004\u0012\u00020\u000b0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\f\u001a\b\u0012\u0004\u0012\u00020\u000b0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R,\u0010\r\u001a \u0012\u001c\u0012\u001a\u0012\u0004\u0012\u00020\u0010\u0012\u0004\u0012\u00020\u0010\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\u000f0\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0011\u001a\u0004\u0018\u00010\u0012X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0013\u001a\u00020\u000bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0014\u0010\u0015\"\u0004\b\u0016\u0010\u0017R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0019R,\u0010\u001a\u001a \u0012\u001c\u0012\u001a\u0012\u0004\u0012\u00020\u001c\u0012\u0004\u0012\u00020\u0010\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\u000f0\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/keyguard/KeyguardUnfoldTransition;", "", "context", "Landroid/content/Context;", "unfoldProgressProvider", "Lcom/android/systemui/unfold/util/NaturalRotationUnfoldProgressProvider;", "(Landroid/content/Context;Lcom/android/systemui/unfold/util/NaturalRotationUnfoldProgressProvider;)V", "getContext", "()Landroid/content/Context;", "filterNever", "Lkotlin/Function0;", "", "filterSplitShadeOnly", "ids", "", "Lkotlin/Triple;", "", "parent", "Landroid/view/ViewGroup;", "statusViewCentered", "getStatusViewCentered", "()Z", "setStatusViewCentered", "(Z)V", "getUnfoldProgressProvider", "()Lcom/android/systemui/unfold/util/NaturalRotationUnfoldProgressProvider;", "views", "", "Landroid/view/View;", "xTranslationMax", "", "findViews", "", "setup", "translateViews", "progress", "Companion"})
@com.android.systemui.unfold.SysUIUnfoldScope()
public final class KeyguardUnfoldTransition {
    private final kotlin.jvm.functions.Function0<java.lang.Boolean> filterSplitShadeOnly = null;
    private final kotlin.jvm.functions.Function0<java.lang.Boolean> filterNever = null;
    private final java.util.Set<kotlin.Triple<java.lang.Integer, java.lang.Integer, kotlin.jvm.functions.Function0<java.lang.Boolean>>> ids = null;
    private android.view.ViewGroup parent;
    private java.util.List<? extends kotlin.Triple<? extends android.view.View, java.lang.Integer, ? extends kotlin.jvm.functions.Function0<java.lang.Boolean>>> views;
    private float xTranslationMax = 0.0F;
    
    /**
     * Certain views only need to move if they are not currently centered
     */
    private boolean statusViewCentered = false;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider unfoldProgressProvider = null;
    private static final int LEFT = -1;
    private static final int RIGHT = 1;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.keyguard.KeyguardUnfoldTransition.Companion Companion = null;
    
    public final boolean getStatusViewCentered() {
        return false;
    }
    
    public final void setStatusViewCentered(boolean p0) {
    }
    
    /**
     * Relies on the [parent] to locate views to translate
     */
    public final void setup(@org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent) {
    }
    
    /**
     * Manually translate views based on set direction. At the moment
     * [UnfoldMoveFromCenterAnimator] exists but moves all views a dynamic distance
     * from their mid-point. This code instead will only ever translate by a fixed amount.
     */
    private final void translateViews(float progress) {
    }
    
    private final void findViews() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider getUnfoldProgressProvider() {
        return null;
    }
    
    @javax.inject.Inject()
    public KeyguardUnfoldTransition(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider unfoldProgressProvider) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u0014\u0010\u0003\u001a\u00020\u0004X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0005\u0010\u0006R\u0014\u0010\u0007\u001a\u00020\u0004X\u0086D\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\u0006"}, d2 = {"Lcom/android/keyguard/KeyguardUnfoldTransition$Companion;", "", "()V", "LEFT", "", "getLEFT", "()I", "RIGHT", "getRIGHT"})
    public static final class Companion {
        
        public final int getLEFT() {
            return 0;
        }
        
        public final int getRIGHT() {
            return 0;
        }
        
        private Companion() {
            super();
        }
    }
}