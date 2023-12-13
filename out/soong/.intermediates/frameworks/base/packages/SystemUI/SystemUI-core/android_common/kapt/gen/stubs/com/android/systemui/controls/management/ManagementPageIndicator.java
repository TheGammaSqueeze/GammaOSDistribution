package com.android.systemui.controls.management;

import android.content.Context;
import android.util.AttributeSet;
import android.view.View;
import com.android.systemui.qs.PageIndicator;

/**
 * Page indicator for management screens.
 *
 * Adds RTL support to [PageIndicator]. To be used with [ViewPager2].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\b\n\u0002\u0010\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0007\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0018\u0010\u000f\u001a\u00020\n2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\tH\u0014J\u0010\u0010\u0013\u001a\u00020\n2\u0006\u0010\u0014\u001a\u00020\u0015H\u0016R&\u0010\u0007\u001a\u000e\u0012\u0004\u0012\u00020\t\u0012\u0004\u0012\u00020\n0\bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000e"}, d2 = {"Lcom/android/systemui/controls/management/ManagementPageIndicator;", "Lcom/android/systemui/qs/PageIndicator;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "visibilityListener", "Lkotlin/Function1;", "", "", "getVisibilityListener", "()Lkotlin/jvm/functions/Function1;", "setVisibilityListener", "(Lkotlin/jvm/functions/Function1;)V", "onVisibilityChanged", "changedView", "Landroid/view/View;", "visibility", "setLocation", "location", ""})
public final class ManagementPageIndicator extends com.android.systemui.qs.PageIndicator {
    @org.jetbrains.annotations.NotNull()
    private kotlin.jvm.functions.Function1<? super java.lang.Integer, kotlin.Unit> visibilityListener;
    
    @java.lang.Override()
    public void setLocation(float location) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function1<java.lang.Integer, kotlin.Unit> getVisibilityListener() {
        return null;
    }
    
    public final void setVisibilityListener(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Integer, kotlin.Unit> p0) {
    }
    
    @java.lang.Override()
    protected void onVisibilityChanged(@org.jetbrains.annotations.NotNull()
    android.view.View changedView, int visibility) {
    }
    
    public ManagementPageIndicator(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet attrs) {
        super(null, null);
    }
}