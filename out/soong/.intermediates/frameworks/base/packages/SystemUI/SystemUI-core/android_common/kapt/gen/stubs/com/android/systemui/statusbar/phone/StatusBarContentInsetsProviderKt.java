package com.android.systemui.statusbar.phone;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Point;
import android.graphics.Rect;
import android.util.LruCache;
import android.util.Pair;
import android.view.DisplayCutout;
import android.os.SystemProperties;
import androidx.annotation.VisibleForTesting;
import com.android.internal.policy.SystemBarUtils;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.CallbackController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.util.leak.RotationUtils.Rotation;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000<\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0011\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0002\u001aP\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u00012\u0006\u0010\u0007\u001a\u00020\u00012\b\u0010\b\u001a\u0004\u0018\u00010\t2\u0006\u0010\n\u001a\u00020\u00052\u0006\u0010\u000b\u001a\u00020\u00012\u0006\u0010\f\u001a\u00020\u00012\u0006\u0010\r\u001a\u00020\u00012\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0001\u001a(\u0010\u0011\u001a\u00020\u00052\u0006\u0010\u0012\u001a\u00020\u00052\u0006\u0010\u0010\u001a\u00020\u00012\u0006\u0010\u0013\u001a\u00020\u00012\u0006\u0010\u000e\u001a\u00020\u000fH\u0007\u001a\u0018\u0010\u0014\u001a\u00020\u00052\u0006\u0010\u0015\u001a\u00020\u00052\u0006\u0010\u0016\u001a\u00020\u0001H\u0002\u001aj\u0010\u0017\u001a\u00020\u00052\b\u0010\u0018\u001a\u0004\u0018\u00010\t2\u0006\u0010\u0019\u001a\u00020\u00012\u0006\u0010\u001a\u001a\u00020\u00012\u0006\u0010\u001b\u001a\u00020\u00012\u0006\u0010\u001c\u001a\u00020\u00012\u0006\u0010\u001d\u001a\u00020\u00012\u0006\u0010\f\u001a\u00020\u00012\u0006\u0010\r\u001a\u00020\u00012\u0006\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00012\u0006\u0010\u0007\u001a\u00020\u00012\u0006\u0010\u0006\u001a\u00020\u0001H\u0002\u001a,\u0010\u001e\u001a\u00020\u00052\u0006\u0010\u001f\u001a\u00020\u00012\u0006\u0010\u0019\u001a\u00020\u00012\u0012\u0010 \u001a\u000e\u0012\u0004\u0012\u00020\u0001\u0012\u0004\u0012\u00020\u00010!H\u0002\u001a(\u0010\"\u001a\u00020\u000f2\u0006\u0010\u001e\u001a\u00020\u00052\u0006\u0010#\u001a\u00020\u00052\u0006\u0010$\u001a\u00020\u00012\u0006\u0010%\u001a\u00020\u0001H\u0002\u001a\f\u0010&\u001a\u00020\u000f*\u00020\u0001H\u0002\u001a\u0014\u0010\'\u001a\u00020\u0001*\u00020\u00052\u0006\u0010(\u001a\u00020\u0001H\u0002\u001a\u0014\u0010)\u001a\u00020\u0001*\u00020\u00052\u0006\u0010(\u001a\u00020\u0001H\u0002\u001a\u0014\u0010*\u001a\u00020\u0001*\u00020\u00052\u0006\u0010(\u001a\u00020\u0001H\u0002\u001a\u0014\u0010+\u001a\u00020\u0001*\u00020,2\u0006\u0010(\u001a\u00020\u0001H\u0002\u001a\u0014\u0010+\u001a\u00020\u0001*\u00020\u00052\u0006\u0010(\u001a\u00020\u0001H\u0002\u001a\u0014\u0010-\u001a\u00020.*\u00020,2\u0006\u0010(\u001a\u00020\u0001H\u0002\u001a$\u0010/\u001a\u00020\u000f*\u00020\u00052\u0006\u0010(\u001a\u00020\u00012\u0006\u0010\u001a\u001a\u00020\u00012\u0006\u0010\u001b\u001a\u00020\u0001H\u0002\u001a$\u00100\u001a\u00020\u000f*\u00020\u00052\u0006\u0010(\u001a\u00020\u00012\u0006\u0010\u001a\u001a\u00020\u00012\u0006\u0010\u001b\u001a\u00020\u0001H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"MAX_CACHE_SIZE", "", "TAG", "", "calculateInsetsForRotationWithRotatedResources", "Landroid/graphics/Rect;", "currentRotation", "targetRotation", "displayCutout", "Landroid/view/DisplayCutout;", "maxBounds", "statusBarHeight", "minLeft", "minRight", "isRtl", "", "dotWidth", "getPrivacyChipBoundingRectForInsets", "contentRect", "chipWidth", "getRotationZeroDisplayBounds", "bounds", "exactRotation", "getStatusBarLeftRight", "dc", "sbHeight", "width", "height", "cWidth", "cHeight", "sbRect", "relativeRotation", "displaySize", "Landroid/util/Pair;", "shareShortEdge", "cutoutRect", "currentWidth", "currentHeight", "isHorizontal", "logicalLeft", "rot", "logicalRight", "logicalTop", "logicalWidth", "Landroid/graphics/Point;", "orientToRotZero", "", "touchesLeftEdge", "touchesRightEdge"})
public final class StatusBarContentInsetsProviderKt {
    private static final java.lang.String TAG = "StatusBarInsetsProvider";
    private static final int MAX_CACHE_SIZE = 16;
    
    private static final android.graphics.Rect getRotationZeroDisplayBounds(android.graphics.Rect bounds, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int exactRotation) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    public static final android.graphics.Rect getPrivacyChipBoundingRectForInsets(@org.jetbrains.annotations.NotNull()
    android.graphics.Rect contentRect, int dotWidth, int chipWidth, boolean isRtl) {
        return null;
    }
    
    /**
     * Calculates the exact left and right positions for the status bar contents for the given
     * rotation
     *
     * @param currentRotation current device rotation
     * @param targetRotation rotation for which to calculate the status bar content rect
     * @param displayCutout [DisplayCutout] for the current display. possibly null
     * @param maxBounds the display bounds in our current rotation
     * @param statusBarHeight height of the status bar for the target rotation
     * @param minLeft the minimum padding to enforce on the left
     * @param minRight the minimum padding to enforce on the right
     * @param isRtl current layout direction is Right-To-Left or not
     * @param dotWidth privacy dot image width (0 if privacy dot is disabled)
     *
     * @see [RotationUtils#getResourcesForRotation]
     */
    @org.jetbrains.annotations.NotNull()
    public static final android.graphics.Rect calculateInsetsForRotationWithRotatedResources(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int currentRotation, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int targetRotation, @org.jetbrains.annotations.Nullable()
    android.view.DisplayCutout displayCutout, @org.jetbrains.annotations.NotNull()
    android.graphics.Rect maxBounds, int statusBarHeight, int minLeft, int minRight, boolean isRtl, int dotWidth) {
        return null;
    }
    
    /**
     * Calculate the insets needed from the left and right edges for the given rotation.
     *
     * @param dc Device display cutout
     * @param sbHeight appropriate status bar height for this rotation
     * @param width display width calculated for ROTATION_NONE
     * @param height display height calculated for ROTATION_NONE
     * @param cWidth display width in our current rotation
     * @param cHeight display height in our current rotation
     * @param minLeft the minimum padding to enforce on the left
     * @param minRight the minimum padding to enforce on the right
     * @param isRtl current layout direction is Right-To-Left or not
     * @param dotWidth privacy dot image width (0 if privacy dot is disabled)
     * @param targetRotation the rotation for which to calculate margins
     * @param currentRotation the rotation from which the display cutout was generated
     *
     * @return a Rect which exactly calculates the Status Bar's content rect relative to the target
     * rotation
     */
    private static final android.graphics.Rect getStatusBarLeftRight(android.view.DisplayCutout dc, int sbHeight, int width, int height, int cWidth, int cHeight, int minLeft, int minRight, boolean isRtl, int dotWidth, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int targetRotation, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int currentRotation) {
        return null;
    }
    
    private static final android.graphics.Rect sbRect(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int relativeRotation, int sbHeight, android.util.Pair<java.lang.Integer, java.lang.Integer> displaySize) {
        return null;
    }
    
    private static final boolean shareShortEdge(android.graphics.Rect sbRect, android.graphics.Rect cutoutRect, int currentWidth, int currentHeight) {
        return false;
    }
    
    private static final boolean touchesRightEdge(android.graphics.Rect $this$touchesRightEdge, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot, int width, int height) {
        return false;
    }
    
    private static final boolean touchesLeftEdge(android.graphics.Rect $this$touchesLeftEdge, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot, int width, int height) {
        return false;
    }
    
    private static final int logicalTop(android.graphics.Rect $this$logicalTop, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
        return 0;
    }
    
    private static final int logicalRight(android.graphics.Rect $this$logicalRight, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
        return 0;
    }
    
    private static final int logicalLeft(android.graphics.Rect $this$logicalLeft, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
        return 0;
    }
    
    private static final int logicalWidth(android.graphics.Rect $this$logicalWidth, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
        return 0;
    }
    
    private static final boolean isHorizontal(int $this$isHorizontal) {
        return false;
    }
    
    private static final void orientToRotZero(android.graphics.Point $this$orientToRotZero, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
    }
    
    private static final int logicalWidth(android.graphics.Point $this$logicalWidth, @com.android.systemui.util.leak.RotationUtils.Rotation()
    int rot) {
        return 0;
    }
}