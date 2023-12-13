package com.android.systemui.media;

import android.graphics.Outline;
import android.util.MathUtils;
import android.view.GestureDetector;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.ViewOutlineProvider;
import androidx.core.view.GestureDetectorCompat;
import androidx.dynamicanimation.animation.FloatPropertyCompat;
import androidx.dynamicanimation.animation.SpringForce;
import com.android.settingslib.Utils;
import com.android.systemui.Gefingerpoken;
import com.android.systemui.R;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.PageIndicator;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.wm.shell.animation.PhysicsAnimator;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u001a\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0003\n\u0002\u0018\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0006\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0007\u001a\u00020\u0005X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"DISMISS_DELAY", "", "FLING_SLOP", "", "RUBBERBAND_FACTOR", "", "SCROLL_DELAY", "SETTINGS_BUTTON_TRANSLATION_FRACTION", "translationConfig", "Lcom/android/wm/shell/animation/PhysicsAnimator$SpringConfig;"})
public final class MediaCarouselScrollHandlerKt {
    private static final int FLING_SLOP = 1000000;
    private static final long DISMISS_DELAY = 100L;
    private static final long SCROLL_DELAY = 100L;
    private static final float RUBBERBAND_FACTOR = 0.2F;
    private static final float SETTINGS_BUTTON_TRANSLATION_FRACTION = 0.3F;
    
    /**
     * Default spring configuration to use for animations where stiffness and/or damping ratio
     * were not provided, and a default spring was not set via [PhysicsAnimator.setDefaultSpringConfig].
     */
    private static final com.android.wm.shell.animation.PhysicsAnimator.SpringConfig translationConfig = null;
}