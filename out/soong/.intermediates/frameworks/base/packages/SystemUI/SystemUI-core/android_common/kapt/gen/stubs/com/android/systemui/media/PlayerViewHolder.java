package com.android.systemui.media;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;
import com.android.systemui.R;
import com.android.systemui.util.animation.TransitionLayout;

/**
 * ViewHolder for a media player.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000Z\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\r\n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0000\u0018\u0000 L2\u00020\u0001:\u0001LB\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u000e\u0010C\u001a\u00020\u00062\u0006\u0010D\u001a\u00020EJ\u0016\u0010F\u001a\u00020G2\u0006\u0010H\u001a\u00020I2\u0006\u0010J\u001a\u00020KR\u0019\u0010\u0005\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0019\u0010\n\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\tR\u0019\u0010\f\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\tR\u0019\u0010\u000e\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\tR\u0019\u0010\u0010\u001a\n \u0007*\u0004\u0018\u00010\u00060\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\tR\u0019\u0010\u0012\u001a\n \u0007*\u0004\u0018\u00010\u00130\u0013\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0019\u0010\u0016\u001a\n \u0007*\u0004\u0018\u00010\u00130\u0013\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0017\u0010\u0015R\u0019\u0010\u0018\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u0019\u0010\u001c\u001a\n \u0007*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001eR\u0019\u0010\u001f\u001a\n \u0007*\u0004\u0018\u00010 0 \u00a2\u0006\b\n\u0000\u001a\u0004\b!\u0010\"R\u0019\u0010#\u001a\n \u0007*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010\u001eR\u0019\u0010%\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b&\u0010\u001bR\u0019\u0010\'\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b(\u0010\u001bR\u0011\u0010)\u001a\u00020*\u00a2\u0006\b\n\u0000\u001a\u0004\b+\u0010,R\u0019\u0010-\u001a\n \u0007*\u0004\u0018\u00010 0 \u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010\"R\u0019\u0010/\u001a\n \u0007*\u0004\u0018\u00010 0 \u00a2\u0006\b\n\u0000\u001a\u0004\b0\u0010\"R\u0019\u00101\u001a\n \u0007*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b2\u0010\u001eR\u0019\u00103\u001a\n \u0007*\u0004\u0018\u00010\u00130\u0013\u00a2\u0006\b\n\u0000\u001a\u0004\b4\u0010\u0015R\u0019\u00105\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b6\u0010\u001bR\u0019\u00107\u001a\n \u0007*\u0004\u0018\u00010808\u00a2\u0006\b\n\u0000\u001a\u0004\b9\u0010:R\u0019\u0010;\u001a\n \u0007*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b<\u0010\u001eR\u0019\u0010=\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b>\u0010\u001bR\u0019\u0010?\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b@\u0010\u001bR\u0019\u0010A\u001a\n \u0007*\u0004\u0018\u00010\u00190\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\bB\u0010\u001b"}, d2 = {"Lcom/android/systemui/media/PlayerViewHolder;", "", "itemView", "Landroid/view/View;", "(Landroid/view/View;)V", "action0", "Landroid/widget/ImageButton;", "kotlin.jvm.PlatformType", "getAction0", "()Landroid/widget/ImageButton;", "action1", "getAction1", "action2", "getAction2", "action3", "getAction3", "action4", "getAction4", "albumView", "Landroid/widget/ImageView;", "getAlbumView", "()Landroid/widget/ImageView;", "appIcon", "getAppIcon", "artistText", "Landroid/widget/TextView;", "getArtistText", "()Landroid/widget/TextView;", "cancel", "getCancel", "()Landroid/view/View;", "dismiss", "Landroid/view/ViewGroup;", "getDismiss", "()Landroid/view/ViewGroup;", "dismissLabel", "getDismissLabel", "elapsedTimeView", "getElapsedTimeView", "longPressText", "getLongPressText", "player", "Lcom/android/systemui/util/animation/TransitionLayout;", "getPlayer", "()Lcom/android/systemui/util/animation/TransitionLayout;", "progressTimes", "getProgressTimes", "seamless", "getSeamless", "seamlessButton", "getSeamlessButton", "seamlessIcon", "getSeamlessIcon", "seamlessText", "getSeamlessText", "seekBar", "Landroid/widget/SeekBar;", "getSeekBar", "()Landroid/widget/SeekBar;", "settings", "getSettings", "settingsText", "getSettingsText", "titleText", "getTitleText", "totalTimeView", "getTotalTimeView", "getAction", "id", "", "marquee", "", "start", "", "delay", "", "Companion"})
public final class PlayerViewHolder {
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.animation.TransitionLayout player = null;
    private final android.widget.ImageView appIcon = null;
    private final android.widget.ImageView albumView = null;
    private final android.widget.TextView titleText = null;
    private final android.widget.TextView artistText = null;
    private final android.view.ViewGroup seamless = null;
    private final android.widget.ImageView seamlessIcon = null;
    private final android.widget.TextView seamlessText = null;
    private final android.view.View seamlessButton = null;
    private final android.widget.SeekBar seekBar = null;
    private final android.view.ViewGroup progressTimes = null;
    private final android.widget.TextView elapsedTimeView = null;
    private final android.widget.TextView totalTimeView = null;
    private final android.widget.ImageButton action0 = null;
    private final android.widget.ImageButton action1 = null;
    private final android.widget.ImageButton action2 = null;
    private final android.widget.ImageButton action3 = null;
    private final android.widget.ImageButton action4 = null;
    private final android.widget.TextView longPressText = null;
    private final android.view.View cancel = null;
    private final android.view.ViewGroup dismiss = null;
    private final android.view.View dismissLabel = null;
    private final android.view.View settings = null;
    private final android.widget.TextView settingsText = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.util.Set<java.lang.Integer> controlsIds = null;
    @org.jetbrains.annotations.NotNull()
    private static final java.util.Set<java.lang.Integer> gutsIds = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.PlayerViewHolder.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionLayout getPlayer() {
        return null;
    }
    
    public final android.widget.ImageView getAppIcon() {
        return null;
    }
    
    public final android.widget.ImageView getAlbumView() {
        return null;
    }
    
    public final android.widget.TextView getTitleText() {
        return null;
    }
    
    public final android.widget.TextView getArtistText() {
        return null;
    }
    
    public final android.view.ViewGroup getSeamless() {
        return null;
    }
    
    public final android.widget.ImageView getSeamlessIcon() {
        return null;
    }
    
    public final android.widget.TextView getSeamlessText() {
        return null;
    }
    
    public final android.view.View getSeamlessButton() {
        return null;
    }
    
    public final android.widget.SeekBar getSeekBar() {
        return null;
    }
    
    public final android.view.ViewGroup getProgressTimes() {
        return null;
    }
    
    public final android.widget.TextView getElapsedTimeView() {
        return null;
    }
    
    public final android.widget.TextView getTotalTimeView() {
        return null;
    }
    
    public final android.widget.ImageButton getAction0() {
        return null;
    }
    
    public final android.widget.ImageButton getAction1() {
        return null;
    }
    
    public final android.widget.ImageButton getAction2() {
        return null;
    }
    
    public final android.widget.ImageButton getAction3() {
        return null;
    }
    
    public final android.widget.ImageButton getAction4() {
        return null;
    }
    
    public final android.widget.TextView getLongPressText() {
        return null;
    }
    
    public final android.view.View getCancel() {
        return null;
    }
    
    public final android.view.ViewGroup getDismiss() {
        return null;
    }
    
    public final android.view.View getDismissLabel() {
        return null;
    }
    
    public final android.view.View getSettings() {
        return null;
    }
    
    public final android.widget.TextView getSettingsText() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.widget.ImageButton getAction(int id) {
        return null;
    }
    
    public final void marquee(boolean start, long delay) {
    }
    
    private PlayerViewHolder(android.view.View itemView) {
        super();
    }
    
    /**
     * Creates a PlayerViewHolder.
     *
     * @param inflater LayoutInflater to use to inflate the layout.
     * @param parent Parent of inflated view.
     */
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.PlayerViewHolder create(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH\u0007R\u0017\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007R\u0017\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\u0007"}, d2 = {"Lcom/android/systemui/media/PlayerViewHolder$Companion;", "", "()V", "controlsIds", "", "", "getControlsIds", "()Ljava/util/Set;", "gutsIds", "getGutsIds", "create", "Lcom/android/systemui/media/PlayerViewHolder;", "inflater", "Landroid/view/LayoutInflater;", "parent", "Landroid/view/ViewGroup;"})
    public static final class Companion {
        
        /**
         * Creates a PlayerViewHolder.
         *
         * @param inflater LayoutInflater to use to inflate the layout.
         * @param parent Parent of inflated view.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.PlayerViewHolder create(@org.jetbrains.annotations.NotNull()
        android.view.LayoutInflater inflater, @org.jetbrains.annotations.NotNull()
        android.view.ViewGroup parent) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.Set<java.lang.Integer> getControlsIds() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.util.Set<java.lang.Integer> getGutsIds() {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}