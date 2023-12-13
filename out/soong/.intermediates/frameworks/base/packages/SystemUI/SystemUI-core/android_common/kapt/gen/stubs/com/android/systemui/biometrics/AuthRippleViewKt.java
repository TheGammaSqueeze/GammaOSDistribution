package com.android.systemui.biometrics;

import android.animation.Animator;
import android.animation.AnimatorListenerAdapter;
import android.animation.AnimatorSet;
import android.animation.ValueAnimator;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.PointF;
import android.util.AttributeSet;
import android.view.View;
import android.view.animation.PathInterpolator;
import com.android.internal.graphics.ColorUtils;
import com.android.systemui.animation.Interpolators;
import com.android.systemui.statusbar.charging.DwellRippleShader;
import com.android.systemui.statusbar.charging.RippleShader;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0006\n\u0000\n\u0002\u0010\u0007\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"RIPPLE_SPARKLE_STRENGTH", ""})
public final class AuthRippleViewKt {
    private static final float RIPPLE_SPARKLE_STRENGTH = 0.4F;
}