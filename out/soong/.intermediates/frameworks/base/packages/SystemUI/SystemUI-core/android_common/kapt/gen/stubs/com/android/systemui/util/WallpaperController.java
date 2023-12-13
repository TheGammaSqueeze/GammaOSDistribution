package com.android.systemui.util;

import android.app.WallpaperInfo;
import android.app.WallpaperManager;
import android.util.Log;
import android.view.View;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0007\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\b\u0007\u0018\u00002\u00020\u0001B\u000f\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0010\u0010\u0014\u001a\u00020\u00152\b\u0010\u0012\u001a\u0004\u0018\u00010\u0013J\u000e\u0010\u0016\u001a\u00020\u00152\u0006\u0010\u0017\u001a\u00020\u0006J\u000e\u0010\u0018\u001a\u00020\u00152\u0006\u0010\u0017\u001a\u00020\u0006J\u0010\u0010\u0019\u001a\u00020\u00152\u0006\u0010\u0017\u001a\u00020\u0006H\u0002J\b\u0010\u001a\u001a\u00020\u0015H\u0002R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\t\u0010\n\"\u0004\b\u000b\u0010\fR\u0014\u0010\r\u001a\u00020\u000e8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b\u000f\u0010\u0010R\u000e\u0010\u0011\u001a\u00020\u0006X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0012\u001a\u0004\u0018\u00010\u0013X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/util/WallpaperController;", "", "wallpaperManager", "Landroid/app/WallpaperManager;", "(Landroid/app/WallpaperManager;)V", "notificationShadeZoomOut", "", "rootView", "Landroid/view/View;", "getRootView", "()Landroid/view/View;", "setRootView", "(Landroid/view/View;)V", "shouldUseDefaultUnfoldTransition", "", "getShouldUseDefaultUnfoldTransition", "()Z", "unfoldTransitionZoomOut", "wallpaperInfo", "Landroid/app/WallpaperInfo;", "onWallpaperInfoUpdated", "", "setNotificationShadeZoom", "zoomOut", "setUnfoldTransitionZoom", "setWallpaperZoom", "updateZoom"})
@com.android.systemui.dagger.SysUISingleton()
public final class WallpaperController {
    @org.jetbrains.annotations.Nullable()
    private android.view.View rootView;
    private float notificationShadeZoomOut = 0.0F;
    private float unfoldTransitionZoomOut = 0.0F;
    private android.app.WallpaperInfo wallpaperInfo;
    private final android.app.WallpaperManager wallpaperManager = null;
    
    @org.jetbrains.annotations.Nullable()
    public final android.view.View getRootView() {
        return null;
    }
    
    public final void setRootView(@org.jetbrains.annotations.Nullable()
    android.view.View p0) {
    }
    
    public final void onWallpaperInfoUpdated(@org.jetbrains.annotations.Nullable()
    android.app.WallpaperInfo wallpaperInfo) {
    }
    
    private final boolean getShouldUseDefaultUnfoldTransition() {
        return false;
    }
    
    public final void setNotificationShadeZoom(float zoomOut) {
    }
    
    public final void setUnfoldTransitionZoom(float zoomOut) {
    }
    
    private final void updateZoom() {
    }
    
    private final void setWallpaperZoom(float zoomOut) {
    }
    
    @javax.inject.Inject()
    public WallpaperController(@org.jetbrains.annotations.NotNull()
    android.app.WallpaperManager wallpaperManager) {
        super();
    }
}