package com.android.systemui.util;

import android.content.pm.ActivityInfo;
import android.content.res.Resources;
import android.graphics.Rect;
import android.graphics.drawable.Drawable;
import android.graphics.drawable.DrawableWrapper;
import android.graphics.drawable.InsetDrawable;

/**
 * [DrawableWrapper] to use in the progress of a slider.
 *
 * This drawable is used to change the bounds of the enclosed drawable depending on the level to
 * simulate a sliding progress, instead of using clipping or scaling. That way, the shape of the
 * edges is maintained.
 *
 * Meant to be used with a rounded ends background, it will also prevent deformation when the slider
 * is meant to be smaller than the rounded corner. The background should have rounded corners that
 * are half of the height.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u0000 \u00132\u00020\u0001:\u0002\u0013\u0014B\u0013\b\u0007\u0012\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\u0002\u0010\u0004J\b\u0010\u0005\u001a\u00020\u0006H\u0016J\b\u0010\u0007\u001a\u00020\bH\u0016J\b\u0010\t\u001a\u00020\nH\u0016J\u0010\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eH\u0014J\u0010\u0010\u000f\u001a\u00020\u00062\u0006\u0010\u0010\u001a\u00020\bH\u0016J\u0010\u0010\u0011\u001a\u00020\u00062\u0006\u0010\u0012\u001a\u00020\bH\u0014"}, d2 = {"Lcom/android/systemui/util/RoundedCornerProgressDrawable;", "Landroid/graphics/drawable/InsetDrawable;", "drawable", "Landroid/graphics/drawable/Drawable;", "(Landroid/graphics/drawable/Drawable;)V", "canApplyTheme", "", "getChangingConfigurations", "", "getConstantState", "Landroid/graphics/drawable/Drawable$ConstantState;", "onBoundsChange", "", "bounds", "Landroid/graphics/Rect;", "onLayoutDirectionChanged", "layoutDirection", "onLevelChange", "level", "Companion", "RoundedCornerState"})
public final class RoundedCornerProgressDrawable extends android.graphics.drawable.InsetDrawable {
    private static final int MAX_LEVEL = 10000;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.util.RoundedCornerProgressDrawable.Companion Companion = null;
    
    @java.lang.Override()
    public boolean onLayoutDirectionChanged(int layoutDirection) {
        return false;
    }
    
    @java.lang.Override()
    protected void onBoundsChange(@org.jetbrains.annotations.NotNull()
    android.graphics.Rect bounds) {
    }
    
    @java.lang.Override()
    protected boolean onLevelChange(int level) {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.graphics.drawable.Drawable.ConstantState getConstantState() {
        return null;
    }
    
    @java.lang.Override()
    public int getChangingConfigurations() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean canApplyTheme() {
        return false;
    }
    
    public RoundedCornerProgressDrawable(@org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Drawable drawable) {
        super(null, 0);
    }
    
    public RoundedCornerProgressDrawable() {
        super(null, 0);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0002\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0001\u00a2\u0006\u0002\u0010\u0003J\b\u0010\u0004\u001a\u00020\u0005H\u0016J\b\u0010\u0006\u001a\u00020\u0007H\u0016J\b\u0010\b\u001a\u00020\tH\u0016J \u0010\b\u001a\u00020\t2\b\u0010\n\u001a\u0004\u0018\u00010\u000b2\f\u0010\f\u001a\b\u0018\u00010\rR\u00020\u000bH\u0016R\u000e\u0010\u0002\u001a\u00020\u0001X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/RoundedCornerProgressDrawable$RoundedCornerState;", "Landroid/graphics/drawable/Drawable$ConstantState;", "wrappedState", "(Landroid/graphics/drawable/Drawable$ConstantState;)V", "canApplyTheme", "", "getChangingConfigurations", "", "newDrawable", "Landroid/graphics/drawable/Drawable;", "res", "Landroid/content/res/Resources;", "theme", "Landroid/content/res/Resources$Theme;"})
    static final class RoundedCornerState extends android.graphics.drawable.Drawable.ConstantState {
        private final android.graphics.drawable.Drawable.ConstantState wrappedState = null;
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public android.graphics.drawable.Drawable newDrawable() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public android.graphics.drawable.Drawable newDrawable(@org.jetbrains.annotations.Nullable()
        android.content.res.Resources res, @org.jetbrains.annotations.Nullable()
        android.content.res.Resources.Theme theme) {
            return null;
        }
        
        @java.lang.Override()
        public int getChangingConfigurations() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean canApplyTheme() {
            return false;
        }
        
        public RoundedCornerState(@org.jetbrains.annotations.NotNull()
        android.graphics.drawable.Drawable.ConstantState wrappedState) {
            super();
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/RoundedCornerProgressDrawable$Companion;", "", "()V", "MAX_LEVEL", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}