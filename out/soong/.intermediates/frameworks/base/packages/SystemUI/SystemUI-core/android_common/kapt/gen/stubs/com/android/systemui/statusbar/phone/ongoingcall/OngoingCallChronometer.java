package com.android.systemui.statusbar.phone.ongoingcall;

import android.content.Context;
import android.util.AttributeSet;
import android.widget.Chronometer;
import androidx.annotation.UiThread;

/**
 * A [Chronometer] specifically for the ongoing call chip in the status bar.
 *
 * This class handles:
 *  1) Setting the text width. If we used a basic WRAP_CONTENT for width, the chip width would
 *     change slightly each second because the width of each number is slightly different.
 *
 *     Instead, we save the largest number width seen so far and ensure that the chip is at least
 *     that wide. This means the chip may get larger over time (e.g. in the transition from 59:59
 *     to 1:00:00), but never smaller.
 *
 *  2) Hiding the text if the time gets too long for the space available. Once the text has been
 *     hidden, it remains hidden for the duration of the call.
 *
 * Note that if the text was too big in portrait mode, resulting in the text being hidden, then the
 * text will also be hidden in landscape (even if there is enough space for it in landscape).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010\t\n\u0000\u0018\u00002\u00020\u0001B%\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\n\b\u0002\u0010\u0004\u001a\u0004\u0018\u00010\u0005\u0012\b\b\u0002\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ\u0018\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u00072\u0006\u0010\u000f\u001a\u00020\u0007H\u0014J\u0010\u0010\u0010\u001a\u00020\r2\u0006\u0010\u0011\u001a\u00020\u0012H\u0016J\u0010\u0010\u0013\u001a\u00020\r2\u0006\u0010\n\u001a\u00020\u000bH\u0007R\u000e\u0010\t\u001a\u00020\u0007X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallChronometer;", "Landroid/widget/Chronometer;", "context", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "defStyle", "", "(Landroid/content/Context;Landroid/util/AttributeSet;I)V", "minimumTextWidth", "shouldHideText", "", "onMeasure", "", "widthMeasureSpec", "heightMeasureSpec", "setBase", "base", "", "setShouldHideText"})
public final class OngoingCallChronometer extends android.widget.Chronometer {
    private int minimumTextWidth = 0;
    private boolean shouldHideText = false;
    
    @java.lang.Override()
    public void setBase(long base) {
    }
    
    /**
     * Sets whether this view should hide its text or not.
     */
    @androidx.annotation.UiThread()
    public final void setShouldHideText(boolean shouldHideText) {
    }
    
    @java.lang.Override()
    protected void onMeasure(int widthMeasureSpec, int heightMeasureSpec) {
    }
    
    public OngoingCallChronometer(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs, int defStyle) {
        super(null);
    }
    
    public OngoingCallChronometer(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.Nullable()
    android.util.AttributeSet attrs) {
        super(null);
    }
    
    public OngoingCallChronometer(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        super(null);
    }
}