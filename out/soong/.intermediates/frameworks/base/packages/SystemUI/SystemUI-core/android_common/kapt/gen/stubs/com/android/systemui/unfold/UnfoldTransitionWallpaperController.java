package com.android.systemui.unfold;

import com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener;
import com.android.systemui.util.WallpaperController;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\b\u0007\u0018\u00002\u00020\u0001:\u0001\tB\u0017\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0006\u0010\u0007\u001a\u00020\bR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/unfold/UnfoldTransitionWallpaperController;", "", "unfoldTransitionProgressProvider", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;", "wallpaperController", "Lcom/android/systemui/util/WallpaperController;", "(Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider;Lcom/android/systemui/util/WallpaperController;)V", "init", "", "TransitionListener"})
@SysUIUnfoldScope()
public final class UnfoldTransitionWallpaperController {
    private final com.android.systemui.unfold.UnfoldTransitionProgressProvider unfoldTransitionProgressProvider = null;
    private final com.android.systemui.util.WallpaperController wallpaperController = null;
    
    public final void init() {
    }
    
    @javax.inject.Inject()
    public UnfoldTransitionWallpaperController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.unfold.UnfoldTransitionProgressProvider unfoldTransitionProgressProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.util.WallpaperController wallpaperController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\b\u0082\u0004\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\b\u0010\u0003\u001a\u00020\u0004H\u0016J\u0010\u0010\u0005\u001a\u00020\u00042\u0006\u0010\u0006\u001a\u00020\u0007H\u0016"}, d2 = {"Lcom/android/systemui/unfold/UnfoldTransitionWallpaperController$TransitionListener;", "Lcom/android/systemui/unfold/UnfoldTransitionProgressProvider$TransitionProgressListener;", "(Lcom/android/systemui/unfold/UnfoldTransitionWallpaperController;)V", "onTransitionFinished", "", "onTransitionProgress", "progress", ""})
    final class TransitionListener implements com.android.systemui.unfold.UnfoldTransitionProgressProvider.TransitionProgressListener {
        
        @java.lang.Override()
        public void onTransitionProgress(float progress) {
        }
        
        @java.lang.Override()
        public void onTransitionFinished() {
        }
        
        public TransitionListener() {
            super();
        }
        
        public void onTransitionStarted() {
        }
    }
}