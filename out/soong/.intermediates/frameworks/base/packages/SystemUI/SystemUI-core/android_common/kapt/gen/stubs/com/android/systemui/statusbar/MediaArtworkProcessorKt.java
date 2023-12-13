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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0014\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"BLUR_RADIUS", "", "COLOR_ALPHA", "", "DOWNSAMPLE", "TAG", ""})
public final class MediaArtworkProcessorKt {
    private static final java.lang.String TAG = "MediaArtworkProcessor";
    private static final int COLOR_ALPHA = 178;
    private static final float BLUR_RADIUS = 25.0F;
    private static final int DOWNSAMPLE = 6;
}