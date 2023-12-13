package com.android.systemui.statusbar;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Point;
import android.graphics.Rect;
import android.renderscript.Allocation;
import android.renderscript.Element;
import android.renderscript.RenderScript;
import android.renderscript.ScriptIntrinsicBlur;
import android.util.Log;
import android.util.MathUtils;
import com.android.internal.graphics.ColorUtils;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.notification.MediaNotificationProcessor;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\b\u0007\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\u0007\u001a\u00020\bJ\u0018\u0010\t\u001a\u0004\u0018\u00010\u00042\u0006\u0010\n\u001a\u00020\u000b2\u0006\u0010\f\u001a\u00020\u0004R\u0010\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/MediaArtworkProcessor;", "", "()V", "mArtworkCache", "Landroid/graphics/Bitmap;", "mTmpSize", "Landroid/graphics/Point;", "clearCache", "", "processArtwork", "context", "Landroid/content/Context;", "artwork"})
@com.android.systemui.dagger.SysUISingleton()
public final class MediaArtworkProcessor {
    private final android.graphics.Point mTmpSize = null;
    private android.graphics.Bitmap mArtworkCache;
    
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.Bitmap processArtwork(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    android.graphics.Bitmap artwork) {
        return null;
    }
    
    public final void clearCache() {
    }
    
    @javax.inject.Inject()
    public MediaArtworkProcessor() {
        super();
    }
}