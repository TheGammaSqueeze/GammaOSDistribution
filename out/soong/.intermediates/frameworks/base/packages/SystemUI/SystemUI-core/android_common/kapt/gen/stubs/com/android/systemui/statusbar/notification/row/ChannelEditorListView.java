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

/**
 * Half-shelf for notification channel controls
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010\u000b\n\u0000\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0018\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u00192\u0006\u0010(\u001a\u00020)H\u0002J\u000e\u0010*\u001a\u00020&2\u0006\u0010\'\u001a\u00020\u0019J\b\u0010+\u001a\u00020&H\u0014J\u0010\u0010,\u001a\u00020&2\u0006\u0010-\u001a\u00020.H\u0002J\b\u0010/\u001a\u00020&H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082.\u00a2\u0006\u0002\n\u0000R\u001c\u0010\t\u001a\u0004\u0018\u00010\nX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000b\u0010\f\"\u0004\b\r\u0010\u000eR\u001c\u0010\u000f\u001a\u0004\u0018\u00010\u0010X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u0014\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00170\u0016X\u0082\u0004\u00a2\u0006\u0002\n\u0000R0\u0010\u001a\u001a\b\u0012\u0004\u0012\u00020\u00190\u00162\f\u0010\u0018\u001a\b\u0012\u0004\u0012\u00020\u00190\u0016@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001eR\u001a\u0010\u001f\u001a\u00020 X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\"\"\u0004\b#\u0010$"}, d2 = {"Lcom/android/systemui/statusbar/notification/row/ChannelEditorListView;", "Landroid/widget/LinearLayout;", "c", "Landroid/content/Context;", "attrs", "Landroid/util/AttributeSet;", "(Landroid/content/Context;Landroid/util/AttributeSet;)V", "appControlRow", "Lcom/android/systemui/statusbar/notification/row/AppControlView;", "appIcon", "Landroid/graphics/drawable/Drawable;", "getAppIcon", "()Landroid/graphics/drawable/Drawable;", "setAppIcon", "(Landroid/graphics/drawable/Drawable;)V", "appName", "", "getAppName", "()Ljava/lang/String;", "setAppName", "(Ljava/lang/String;)V", "channelRows", "", "Lcom/android/systemui/statusbar/notification/row/ChannelRow;", "newValue", "Landroid/app/NotificationChannel;", "channels", "getChannels", "()Ljava/util/List;", "setChannels", "(Ljava/util/List;)V", "controller", "Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;", "getController", "()Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;", "setController", "(Lcom/android/systemui/statusbar/notification/row/ChannelEditorDialogController;)V", "addChannelRow", "", "channel", "inflater", "Landroid/view/LayoutInflater;", "highlightChannel", "onFinishInflate", "updateAppControlRow", "enabled", "", "updateRows"})
public final class ChannelEditorListView extends android.widget.LinearLayout {
    public com.android.systemui.statusbar.notification.row.ChannelEditorDialogController controller;
    @org.jetbrains.annotations.Nullable()
    private android.graphics.drawable.Drawable appIcon;
    @org.jetbrains.annotations.Nullable()
    private java.lang.String appName;
    @org.jetbrains.annotations.NotNull()
    private java.util.List<android.app.NotificationChannel> channels;
    private com.android.systemui.statusbar.notification.row.AppControlView appControlRow;
    private final java.util.List<com.android.systemui.statusbar.notification.row.ChannelRow> channelRows = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.notification.row.ChannelEditorDialogController getController() {
        return null;
    }
    
    public final void setController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.notification.row.ChannelEditorDialogController p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Drawable getAppIcon() {
        return null;
    }
    
    public final void setAppIcon(@org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Drawable p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String getAppName() {
        return null;
    }
    
    public final void setAppName(@org.jetbrains.annotations.Nullable()
    java.lang.String p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.app.NotificationChannel> getChannels() {
        return null;
    }
    
    public final void setChannels(@org.jetbrains.annotations.NotNull()
    java.util.List<android.app.NotificationChannel> newValue) {
    }
    
    @java.lang.Override()
    protected void onFinishInflate() {
    }
    
    /**
     * Play a highlight animation for the given channel (it really should exist but this will just
     * fail silently if it doesn't)
     */
    public final void highlightChannel(@org.jetbrains.annotations.NotNull()
    android.app.NotificationChannel channel) {
    }
    
    private final void updateRows() {
    }
    
    private final void addChannelRow(android.app.NotificationChannel channel, android.view.LayoutInflater inflater) {
    }
    
    private final void updateAppControlRow(boolean enabled) {
    }
    
    public ChannelEditorListView(@org.jetbrains.annotations.NotNull()
    android.content.Context c, @org.jetbrains.annotations.NotNull()
    android.util.AttributeSet attrs) {
        super(null);
    }
}