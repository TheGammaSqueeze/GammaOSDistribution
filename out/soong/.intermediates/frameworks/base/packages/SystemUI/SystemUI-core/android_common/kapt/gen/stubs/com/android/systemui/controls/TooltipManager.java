package com.android.systemui.controls;

import android.annotation.StringRes;
import android.content.Context;
import android.graphics.CornerPathEffect;
import android.graphics.drawable.ShapeDrawable;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AccelerateInterpolator;
import android.view.animation.DecelerateInterpolator;
import android.widget.TextView;
import com.android.systemui.Prefs;
import com.android.systemui.R;
import com.android.systemui.recents.TriangleShape;

/**
 * Manager for showing an onboarding tooltip on screen.
 *
 * The tooltip can be made to appear below or above a point. The number of times it will appear
 * is determined by an shared preference (defined in [Prefs]).
 *
 * @property context A context to use to inflate the views and retrieve shared preferences from
 * @property preferenceName name of the preference to use to track the number of times the tooltip
 *                         has been shown.
 * @property maxTimesShown the maximum number of times to show the tooltip
 * @property below whether the tooltip should appear below (with up pointing arrow) or above (down
 *                pointing arrow) the specified point.
 * @see [TooltipManager.show]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\b\u0018\u0000 \"2\u00020\u0001:\u0001\"B)\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u0010\u0010\u001b\u001a\u00020\u00152\b\b\u0002\u0010\u001c\u001a\u00020\tJ\b\u0010\u001d\u001a\u00020\tH\u0002J\u001e\u0010\u001e\u001a\u00020\u00152\u0006\u0010\u001f\u001a\u00020\u00072\u0006\u0010 \u001a\u00020\u00072\u0006\u0010!\u001a\u00020\u0007R\u0016\u0010\u000b\u001a\n \r*\u0004\u0018\u00010\f0\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u000e\u001a\n \r*\u0004\u0018\u00010\f0\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u000f\u001a\u00020\u0010\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u0012R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001d\u0010\u0013\u001a\u000e\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u00020\u00150\u0014\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\u0017R\u000e\u0010\u0018\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u0019\u001a\n \r*\u0004\u0018\u00010\u001a0\u001aX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/TooltipManager;", "", "context", "Landroid/content/Context;", "preferenceName", "", "maxTimesShown", "", "below", "", "(Landroid/content/Context;Ljava/lang/String;IZ)V", "arrowView", "Landroid/view/View;", "kotlin.jvm.PlatformType", "dismissView", "layout", "Landroid/view/ViewGroup;", "getLayout", "()Landroid/view/ViewGroup;", "preferenceStorer", "Lkotlin/Function1;", "", "getPreferenceStorer", "()Lkotlin/jvm/functions/Function1;", "shown", "textView", "Landroid/widget/TextView;", "hide", "animate", "shouldShow", "show", "stringRes", "x", "y", "Companion"})
public final class TooltipManager {
    private int shown;
    @org.jetbrains.annotations.NotNull()
    private final android.view.ViewGroup layout = null;
    @org.jetbrains.annotations.NotNull()
    private final kotlin.jvm.functions.Function1<java.lang.Integer, kotlin.Unit> preferenceStorer = null;
    private final android.widget.TextView textView = null;
    private final android.view.View dismissView = null;
    private final android.view.View arrowView = null;
    private final java.lang.String preferenceName = null;
    private final int maxTimesShown = 0;
    private final boolean below = false;
    private static final long SHOW_DELAY_MS = 500L;
    private static final long SHOW_DURATION_MS = 300L;
    private static final long HIDE_DURATION_MS = 100L;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.TooltipManager.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.view.ViewGroup getLayout() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function1<java.lang.Integer, kotlin.Unit> getPreferenceStorer() {
        return null;
    }
    
    /**
     * Show the tooltip
     *
     * @param stringRes the id of the string to show in the tooltip
     * @param x horizontal position (w.r.t. screen) for the arrow point
     * @param y vertical position (w.r.t. screen) for the arrow point
     */
    public final void show(@android.annotation.StringRes()
    int stringRes, int x, int y) {
    }
    
    /**
     * Hide the tooltip
     *
     * @param animate whether to animate the fade out
     */
    public final void hide(boolean animate) {
    }
    
    private final boolean shouldShow() {
        return false;
    }
    
    public TooltipManager(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String preferenceName, int maxTimesShown, boolean below) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\t\n\u0002\b\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/TooltipManager$Companion;", "", "()V", "HIDE_DURATION_MS", "", "SHOW_DELAY_MS", "SHOW_DURATION_MS"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}