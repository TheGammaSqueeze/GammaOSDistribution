package com.android.systemui.statusbar.notification.row;

import android.animation.ArgbEvaluator;
import android.animation.ValueAnimator;
import android.app.NotificationChannel;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.text.TextUtils;
import android.transition.AutoTransition;
import android.transition.Transition;
import android.transition.TransitionManager;
import android.util.AttributeSet;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.Switch;
import android.widget.TextView;
import com.android.settingslib.Utils;
import com.android.systemui.R;
import com.android.systemui.util.Assert;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000L\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0003\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010!\u001a\u00020\"H\u0014J\u0006\u0010#\u001a\u00020\"J\b\u0010$\u001a\u00020\"H\u0002J\b\u0010%\u001a\u00020\"H\u0002R(\u0010\t\u001a\u0004\u0018\u00010\b2\b\u0010\u0007\u001a\u0004\u0018\u00010\b@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR\u000e\u0010\u000e\u001a\u00020\u000fX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0010\u001a\u00020\u000fX\u0082.\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0011\u001a\u00020\u0012X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016R\u001a\u0010\u0017\u001a\u00020\u0018X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0019\u0010\u001a\"\u0004\b\u001b\u0010\u001cR\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001f\u001a\u00020 X\u0082.\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/notification/row/ChannelRow;", "Landroid/widget/LinearLayout;", "c", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "newValue", "Landroid/app/NotificationChannel;", "channel", "getChannel", "()Landroid/app/NotificationChannel;", "setChannel", "(Landroid/app/NotificationChannel;)V", "channelDescription", "Landroid/widget/TextView;", "channelName", "controller", "Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;", "getController", "()Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;", "setController", "(Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;)V", "gentle", "", "getGentle", "()Z", "setGentle", "(Z)V", "highlightColor", "", "switch", "Landroid/widget/Switch;", "onFinishInflate", "", "playHighlight", "updateImportance", "updateViews"})
public final class ChannelRow extends android.widget.LinearLayout {
    public com.android.systemui.statusbar.notification.row.ChannelEditorDialogController controller;
    private android.widget.TextView channelName;
    private android.widget.TextView channelDescription;
    private final int highlightColor = 0;
    private boolean gentle = false;
    @org.jetbrains.annotations.Nullable()
    private android.app.NotificationChannel channel;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.row.ChannelEditorDialogController getController() {
        return null;
    }
    
    public final void setController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ChannelEditorDialogController p0) {
    }
    
    public final boolean getGentle() {
        return false;
    }
    
    public final void setGentle(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.app.NotificationChannel getChannel() {
        return null;
    }
    
    public final void setChannel(@org.jetbrains.annotations.Nullable()
    android.app.NotificationChannel newValue) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    /**
     * Play an animation that highlights this row
     */
    public final void playHighlight() {
    }
    
    private final void updateViews() {
    }
    
    private final void updateImportance() {
    }
    
    public ChannelRow(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet attrs) {
        super(null);
    }
}