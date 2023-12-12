package com.android.systemui.media;

import android.graphics.Rect;
import android.util.ArraySet;
import android.view.View;
import android.view.View.OnAttachStateChangeListener;
import com.android.systemui.util.animation.DisappearParameters;
import com.android.systemui.util.animation.MeasurementInput;
import com.android.systemui.util.animation.MeasurementOutput;
import com.android.systemui.util.animation.UniqueObjectHostView;
import java.util.Objects;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000|\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0010\u0015\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\b\u0018\u00002\u00020\u0001:\u0001HB%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u001a\u0010A\u001a\u00020@2\u0012\u0010(\u001a\u000e\u0012\u0004\u0012\u00020\u001c\u0012\u0004\u0012\u00020@0?J\t\u0010B\u001a\u00020\u0001H\u0096\u0001J\u000e\u0010C\u001a\u00020@2\u0006\u0010-\u001a\u00020,J\u001a\u0010D\u001a\u00020@2\u0012\u0010(\u001a\u000e\u0012\u0004\u0012\u00020\u001c\u0012\u0004\u0012\u00020@0?J\u0010\u0010E\u001a\u00020@2\u0006\u0010F\u001a\u00020\u001cH\u0002J\b\u0010G\u001a\u00020@H\u0002R\u0013\u0010\u000b\u001a\u00020\f8F\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0018\u0010\u000f\u001a\u00020\u0010X\u0096\u000f\u00a2\u0006\f\u001a\u0004\b\u0011\u0010\u0012\"\u0004\b\u0013\u0010\u0014R\u0018\u0010\u0015\u001a\u00020\u0016X\u0096\u000f\u00a2\u0006\f\u001a\u0004\b\u0017\u0010\u0018\"\u0004\b\u0019\u0010\u001aR\u0018\u0010\u001b\u001a\u00020\u001cX\u0096\u000f\u00a2\u0006\f\u001a\u0004\b\u001d\u0010\u001e\"\u0004\b\u001f\u0010 R\u001a\u0010!\u001a\u00020\"X\u0086.\u00a2\u0006\u000e\n\u0000\u001a\u0004\b#\u0010$\"\u0004\b%\u0010&R\u000e\u0010\'\u001a\u00020\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010(\u001a\u00020)X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010*\u001a\u00020\u001cX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001e\u0010-\u001a\u00020,2\u0006\u0010+\u001a\u00020,@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b.\u0010/R\u001a\u00100\u001a\u0004\u0018\u000101X\u0096\u000f\u00a2\u0006\f\u001a\u0004\b2\u00103\"\u0004\b4\u00105R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0018\u00106\u001a\u00020\u001cX\u0096\u000f\u00a2\u0006\f\u001a\u0004\b7\u0010\u001e\"\u0004\b8\u0010 R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00109\u001a\u00020:X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010;\u001a\u00020\u001cX\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b<\u0010\u001eR \u0010=\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\u001c\u0012\u0004\u0012\u00020@0?0>X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/media/MediaHost;", "Lcom/android/systemui/media/MediaHostState;", "state", "Lcom/android/systemui/media/MediaHost$MediaHostStateHolder;", "mediaHierarchyManager", "Lcom/android/systemui/media/MediaHierarchyManager;", "mediaDataManager", "Lcom/android/systemui/media/MediaDataManager;", "mediaHostStatesManager", "Lcom/android/systemui/media/MediaHostStatesManager;", "(Lcom/android/systemui/media/MediaHost$MediaHostStateHolder;Lcom/android/systemui/media/MediaHierarchyManager;Lcom/android/systemui/media/MediaDataManager;Lcom/android/systemui/media/MediaHostStatesManager;)V", "currentBounds", "Landroid/graphics/Rect;", "getCurrentBounds", "()Landroid/graphics/Rect;", "disappearParameters", "Lcom/android/systemui/util/animation/DisappearParameters;", "getDisappearParameters", "()Lcom/android/systemui/util/animation/DisappearParameters;", "setDisappearParameters", "(Lcom/android/systemui/util/animation/DisappearParameters;)V", "expansion", "", "getExpansion", "()F", "setExpansion", "(F)V", "falsingProtectionNeeded", "", "getFalsingProtectionNeeded", "()Z", "setFalsingProtectionNeeded", "(Z)V", "hostView", "Lcom/android/systemui/util/animation/UniqueObjectHostView;", "getHostView", "()Lcom/android/systemui/util/animation/UniqueObjectHostView;", "setHostView", "(Lcom/android/systemui/util/animation/UniqueObjectHostView;)V", "inited", "listener", "Lcom/android/systemui/media/MediaDataManager$Listener;", "listeningToMediaData", "<set-?>", "", "location", "getLocation", "()I", "measurementInput", "Lcom/android/systemui/util/animation/MeasurementInput;", "getMeasurementInput", "()Lcom/android/systemui/util/animation/MeasurementInput;", "setMeasurementInput", "(Lcom/android/systemui/util/animation/MeasurementInput;)V", "showsOnlyActiveMedia", "getShowsOnlyActiveMedia", "setShowsOnlyActiveMedia", "tmpLocationOnScreen", "", "visible", "getVisible", "visibleChangedListeners", "Landroid/util/ArraySet;", "Lkotlin/Function1;", "", "addVisibilityChangeListener", "copy", "init", "removeVisibilityChangeListener", "setListeningToMediaData", "listen", "updateViewVisibility", "MediaHostStateHolder"})
public final class MediaHost implements com.android.systemui.media.MediaHostState {
    public com.android.systemui.util.animation.UniqueObjectHostView hostView;
    private int location = -1;
    private android.util.ArraySet<kotlin.jvm.functions.Function1<java.lang.Boolean, kotlin.Unit>> visibleChangedListeners;
    private final int[] tmpLocationOnScreen = {0, 0};
    private boolean inited = false;
    
    /**
     * Are we listening to media data changes?
     */
    private boolean listeningToMediaData = false;
    
    /**
     * Get the current bounds on the screen. This makes sure the state is fresh and up to date
     */
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.Rect currentBounds = null;
    private final com.android.systemui.media.MediaDataManager.Listener listener = null;
    private final com.android.systemui.media.MediaHost.MediaHostStateHolder state = null;
    private final com.android.systemui.media.MediaHierarchyManager mediaHierarchyManager = null;
    private final com.android.systemui.media.MediaDataManager mediaDataManager = null;
    private final com.android.systemui.media.MediaHostStatesManager mediaHostStatesManager = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.util.animation.UniqueObjectHostView getHostView() {
        return null;
    }
    
    public final void setHostView(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.UniqueObjectHostView p0) {
    }
    
    public final int getLocation() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Rect getCurrentBounds() {
        return null;
    }
    
    public final void addVisibilityChangeListener(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> listener) {
    }
    
    public final void removeVisibilityChangeListener(@org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super java.lang.Boolean, kotlin.Unit> listener) {
    }
    
    /**
     * Initialize this MediaObject and create a host view.
     * All state should already be set on this host before calling this method in order to avoid
     * unnecessary state changes which lead to remeasurings later on.
     *
     * @param location the location this host name has. Used to identify the host during
     *                transitions.
     */
    public final void init(@MediaLocation()
    int location) {
    }
    
    private final void setListeningToMediaData(boolean listen) {
    }
    
    private final void updateViewVisibility() {
    }
    
    public MediaHost(@org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHost.MediaHostStateHolder state, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHierarchyManager mediaHierarchyManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaDataManager mediaDataManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.media.MediaHostStatesManager mediaHostStatesManager) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.util.animation.DisappearParameters getDisappearParameters() {
        return null;
    }
    
    @java.lang.Override()
    public void setDisappearParameters(@org.jetbrains.annotations.NotNull()
    com.android.systemui.util.animation.DisappearParameters p0) {
    }
    
    @java.lang.Override()
    public float getExpansion() {
        return 0.0F;
    }
    
    @java.lang.Override()
    public void setExpansion(float p0) {
    }
    
    @java.lang.Override()
    public boolean getFalsingProtectionNeeded() {
        return false;
    }
    
    @java.lang.Override()
    public void setFalsingProtectionNeeded(boolean p0) {
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public com.android.systemui.util.animation.MeasurementInput getMeasurementInput() {
        return null;
    }
    
    @java.lang.Override()
    public void setMeasurementInput(@org.jetbrains.annotations.Nullable()
    com.android.systemui.util.animation.MeasurementInput p0) {
    }
    
    @java.lang.Override()
    public boolean getShowsOnlyActiveMedia() {
        return false;
    }
    
    @java.lang.Override()
    public void setShowsOnlyActiveMedia(boolean p0) {
    }
    
    @java.lang.Override()
    public boolean getVisible() {
        return false;
    }
    
    /**
     * Get a copy of this state. This won't copy any listeners it may have set
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.media.MediaHostState copy() {
        return null;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u0007\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0006\n\u0002\u0010\b\n\u0002\u0018\u0002\n\u0002\b\u000e\n\u0002\u0010\u0000\n\u0000\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\b\u0010+\u001a\u00020\u0001H\u0016J\u0013\u0010,\u001a\u00020\u00172\b\u0010-\u001a\u0004\u0018\u00010.H\u0096\u0002J\b\u0010/\u001a\u00020\u001eH\u0016R\"\u0010\u0003\u001a\n\u0012\u0004\u0012\u00020\u0005\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0006\u0010\u0007\"\u0004\b\b\u0010\tR$\u0010\f\u001a\u00020\u000b2\u0006\u0010\n\u001a\u00020\u000b@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\r\u0010\u000e\"\u0004\b\u000f\u0010\u0010R$\u0010\u0012\u001a\u00020\u00112\u0006\u0010\n\u001a\u00020\u0011@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0013\u0010\u0014\"\u0004\b\u0015\u0010\u0016R$\u0010\u0018\u001a\u00020\u00172\u0006\u0010\n\u001a\u00020\u0017@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0019\u0010\u001a\"\u0004\b\u001b\u0010\u001cR\u000e\u0010\u001d\u001a\u00020\u001eX\u0082\u000e\u00a2\u0006\u0002\n\u0000R(\u0010 \u001a\u0004\u0018\u00010\u001f2\b\u0010\n\u001a\u0004\u0018\u00010\u001f@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b!\u0010\"\"\u0004\b#\u0010$R$\u0010%\u001a\u00020\u00172\u0006\u0010\n\u001a\u00020\u0017@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b&\u0010\u001a\"\u0004\b\'\u0010\u001cR$\u0010(\u001a\u00020\u00172\u0006\u0010\n\u001a\u00020\u0017@VX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b)\u0010\u001a\"\u0004\b*\u0010\u001c"}, d2 = {"Lcom/android/systemui/media/MediaHost$MediaHostStateHolder;", "Lcom/android/systemui/media/MediaHostState;", "()V", "changedListener", "Lkotlin/Function0;", "", "getChangedListener", "()Lkotlin/jvm/functions/Function0;", "setChangedListener", "(Lkotlin/jvm/functions/Function0;)V", "value", "Lcom/android/systemui/util/animation/DisappearParameters;", "disappearParameters", "getDisappearParameters", "()Lcom/android/systemui/util/animation/DisappearParameters;", "setDisappearParameters", "(Lcom/android/systemui/util/animation/DisappearParameters;)V", "", "expansion", "getExpansion", "()F", "setExpansion", "(F)V", "", "falsingProtectionNeeded", "getFalsingProtectionNeeded", "()Z", "setFalsingProtectionNeeded", "(Z)V", "lastDisappearHash", "", "Lcom/android/systemui/util/animation/MeasurementInput;", "measurementInput", "getMeasurementInput", "()Lcom/android/systemui/util/animation/MeasurementInput;", "setMeasurementInput", "(Lcom/android/systemui/util/animation/MeasurementInput;)V", "showsOnlyActiveMedia", "getShowsOnlyActiveMedia", "setShowsOnlyActiveMedia", "visible", "getVisible", "setVisible", "copy", "equals", "other", "", "hashCode"})
    public static final class MediaHostStateHolder implements com.android.systemui.media.MediaHostState {
        @org.jetbrains.annotations.Nullable()
        private com.android.systemui.util.animation.MeasurementInput measurementInput;
        private float expansion = 0.0F;
        private boolean showsOnlyActiveMedia = false;
        private boolean visible = true;
        private boolean falsingProtectionNeeded = false;
        @org.jetbrains.annotations.NotNull()
        private com.android.systemui.util.animation.DisappearParameters disappearParameters;
        private int lastDisappearHash;
        
        /**
         * A listener for all changes. This won't be copied over when invoking [copy]
         */
        @org.jetbrains.annotations.Nullable()
        private kotlin.jvm.functions.Function0<kotlin.Unit> changedListener;
        
        @org.jetbrains.annotations.Nullable()
        @java.lang.Override()
        public com.android.systemui.util.animation.MeasurementInput getMeasurementInput() {
            return null;
        }
        
        @java.lang.Override()
        public void setMeasurementInput(@org.jetbrains.annotations.Nullable()
        com.android.systemui.util.animation.MeasurementInput value) {
        }
        
        @java.lang.Override()
        public float getExpansion() {
            return 0.0F;
        }
        
        @java.lang.Override()
        public void setExpansion(float value) {
        }
        
        @java.lang.Override()
        public boolean getShowsOnlyActiveMedia() {
            return false;
        }
        
        @java.lang.Override()
        public void setShowsOnlyActiveMedia(boolean value) {
        }
        
        @java.lang.Override()
        public boolean getVisible() {
            return false;
        }
        
        public void setVisible(boolean value) {
        }
        
        @java.lang.Override()
        public boolean getFalsingProtectionNeeded() {
            return false;
        }
        
        @java.lang.Override()
        public void setFalsingProtectionNeeded(boolean value) {
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public com.android.systemui.util.animation.DisappearParameters getDisappearParameters() {
            return null;
        }
        
        @java.lang.Override()
        public void setDisappearParameters(@org.jetbrains.annotations.NotNull()
        com.android.systemui.util.animation.DisappearParameters value) {
        }
        
        @org.jetbrains.annotations.Nullable()
        public final kotlin.jvm.functions.Function0<kotlin.Unit> getChangedListener() {
            return null;
        }
        
        public final void setChangedListener(@org.jetbrains.annotations.Nullable()
        kotlin.jvm.functions.Function0<kotlin.Unit> p0) {
        }
        
        /**
         * Get a copy of this state. This won't copy any listeners it may have set
         */
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public com.android.systemui.media.MediaHostState copy() {
            return null;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object other) {
            return false;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @javax.inject.Inject()
        public MediaHostStateHolder() {
            super();
        }
    }
}