package com.android.systemui.media;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;
import androidx.annotation.IntegerRes;
import com.android.systemui.R;
import com.android.systemui.util.animation.TransitionLayout;

/**
 * ViewHolder for a Smartspace media recommendation.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000X\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\t\n\u0000\u0018\u0000 32\u00020\u0001:\u00013B\u000f\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0016\u0010-\u001a\u00020.2\u0006\u0010/\u001a\u0002002\u0006\u00101\u001a\u000202R\u0019\u0010\u0005\u001a\n \u0006*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0019\u0010\t\u001a\n \u0006*\u0004\u0018\u00010\n0\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0019\u0010\r\u001a\n \u0006*\u0004\u0018\u00010\u000e0\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0019\u0010\u0011\u001a\n \u0006*\u0004\u0018\u00010\u00120\u0012\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0013\u0010\u0014R\u0019\u0010\u0015\u001a\n \u0006*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0016\u0010\bR\u0019\u0010\u0017\u001a\n \u0006*\u0004\u0018\u00010\u000e0\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0018\u0010\u0010R\u0017\u0010\u0019\u001a\b\u0012\u0004\u0012\u00020\u00120\u001a\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001b\u0010\u001cR\u001c\u0010\u001d\u001a\r\u0012\t\u0012\u00070\u001e\u00a2\u0006\u0002\b\u001f0\u001a\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u001cR\u0017\u0010!\u001a\b\u0012\u0004\u0012\u00020\n0\u001a\u00a2\u0006\b\n\u0000\u001a\u0004\b\"\u0010\u001cR\u001c\u0010#\u001a\r\u0012\t\u0012\u00070\u001e\u00a2\u0006\u0002\b\u001f0\u001a\u00a2\u0006\b\n\u0000\u001a\u0004\b$\u0010\u001cR\u0011\u0010%\u001a\u00020&\u00a2\u0006\b\n\u0000\u001a\u0004\b\'\u0010(R\u0019\u0010)\u001a\n \u0006*\u0004\u0018\u00010\u00030\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b*\u0010\bR\u0019\u0010+\u001a\n \u0006*\u0004\u0018\u00010\u000e0\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b,\u0010\u0010"}, d2 = {"Lcom/android/systemui/media/RecommendationViewHolder;", "", "itemView", "Landroid/view/View;", "(Landroid/view/View;)V", "cancel", "kotlin.jvm.PlatformType", "getCancel", "()Landroid/view/View;", "cardIcon", "Landroid/widget/ImageView;", "getCardIcon", "()Landroid/widget/ImageView;", "cardText", "Landroid/widget/TextView;", "getCardText", "()Landroid/widget/TextView;", "dismiss", "Landroid/view/ViewGroup;", "getDismiss", "()Landroid/view/ViewGroup;", "dismissLabel", "getDismissLabel", "longPressText", "getLongPressText", "mediaCoverContainers", "", "getMediaCoverContainers", "()Ljava/util/List;", "mediaCoverContainersResIds", "", "Landroidx/annotation/IntegerRes;", "getMediaCoverContainersResIds", "mediaCoverItems", "getMediaCoverItems", "mediaCoverItemsResIds", "getMediaCoverItemsResIds", "recommendations", "Lcom/android/systemui/util/animation/TransitionLayout;", "getRecommendations", "()Lcom/android/systemui/util/animation/TransitionLayout;", "settings", "getSettings", "settingsText", "getSettingsText", "marquee", "", "start", "", "delay", "", "Companion"})
public final class RecommendationViewHolder {
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.util.animation.TransitionLayout recommendations = null;
    private final android.widget.ImageView cardIcon = null;
    private final android.widget.TextView cardText = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<android.widget.ImageView> mediaCoverItems = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<android.view.ViewGroup> mediaCoverContainers = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.Integer> mediaCoverItemsResIds = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<java.lang.Integer> mediaCoverContainersResIds = null;
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
    public static final com.android.systemui.media.RecommendationViewHolder.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.TransitionLayout getRecommendations() {
        return null;
    }
    
    public final android.widget.ImageView getCardIcon() {
        return null;
    }
    
    public final android.widget.TextView getCardText() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.widget.ImageView> getMediaCoverItems() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<android.view.ViewGroup> getMediaCoverContainers() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> getMediaCoverItemsResIds() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<java.lang.Integer> getMediaCoverContainersResIds() {
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
    
    public final void marquee(boolean start, long delay) {
    }
    
    private RecommendationViewHolder(android.view.View itemView) {
        super();
    }
    
    /**
     * Creates a RecommendationViewHolder.
     *
     * @param inflater LayoutInflater to use to inflate the layout.
     * @param parent Parent of inflated view.
     */
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.media.RecommendationViewHolder create(@org.jetbrains.annotations.NotNull()
    android.view.LayoutInflater inflater, @org.jetbrains.annotations.NotNull()
    android.view.ViewGroup parent) {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\"\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0018\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\r2\u0006\u0010\u000e\u001a\u00020\u000fH\u0007R\u0017\u0010\u0003\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0006\u0010\u0007R\u0017\u0010\b\u001a\b\u0012\u0004\u0012\u00020\u00050\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\u0007"}, d2 = {"Lcom/android/systemui/media/RecommendationViewHolder$Companion;", "", "()V", "controlsIds", "", "", "getControlsIds", "()Ljava/util/Set;", "gutsIds", "getGutsIds", "create", "Lcom/android/systemui/media/RecommendationViewHolder;", "inflater", "Landroid/view/LayoutInflater;", "parent", "Landroid/view/ViewGroup;"})
    public static final class Companion {
        
        /**
         * Creates a RecommendationViewHolder.
         *
         * @param inflater LayoutInflater to use to inflate the layout.
         * @param parent Parent of inflated view.
         */
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.media.RecommendationViewHolder create(@org.jetbrains.annotations.NotNull()
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