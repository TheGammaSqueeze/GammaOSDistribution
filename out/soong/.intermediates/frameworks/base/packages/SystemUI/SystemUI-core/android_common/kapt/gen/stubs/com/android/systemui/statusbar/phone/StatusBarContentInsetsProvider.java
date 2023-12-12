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

/**
 * Encapsulates logic that can solve for the left/right insets required for the status bar contents.
 * Takes into account:
 * 1. rounded_corner_content_padding
 * 2. status_bar_padding_start, status_bar_padding_end
 * 2. display cutout insets from left or right
 * 3. waterfall insets
 *
 *
 * Importantly, these functions can determine status bar content left/right insets for any rotation
 * before having done a layout pass in that rotation.
 *
 * NOTE: This class is not threadsafe
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000|\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0004\n\u0002\u0010#\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\n\u0002\b\b\n\u0002\u0018\u0002\n\u0002\b\t\b\u0007\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u00032\u00020\u0004:\u0001AB\u001f\b\u0007\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bJ\u0010\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u0002H\u0016J\b\u0010 \u001a\u00020\u001eH\u0002J\u0006\u0010!\u001a\u00020\u0017J-\u0010\"\u001a\u00020\u001e2\u0006\u0010#\u001a\u00020$2\u0006\u0010%\u001a\u00020&2\u000e\u0010\'\u001a\n\u0012\u0006\b\u0001\u0012\u00020)0(H\u0016\u00a2\u0006\u0002\u0010*J \u0010+\u001a\u00020\u00152\u0006\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020/2\u0006\u00100\u001a\u00020\u0014H\u0002J\u000e\u00101\u001a\u00020\u00152\u0006\u00102\u001a\u00020-J\u0010\u00103\u001a\u00020\u00142\u0006\u00102\u001a\u00020-H\u0002J\u0018\u00104\u001a\u00020\u00152\u0006\u0010,\u001a\u00020-2\u0006\u0010.\u001a\u00020/H\u0002J\u0006\u00105\u001a\u00020\u0015J\u0010\u00106\u001a\u00020\u00152\u0006\u00102\u001a\u00020-H\u0007J\u0012\u00107\u001a\u000e\u0012\u0004\u0012\u00020-\u0012\u0004\u0012\u00020-08J\u001a\u00109\u001a\u000e\u0012\u0004\u0012\u00020-\u0012\u0004\u0012\u00020-082\u0006\u00102\u001a\u00020-J\u0017\u0010:\u001a\u00020-2\n\b\u0002\u00102\u001a\u0004\u0018\u00010-\u00a2\u0006\u0002\u0010;J\b\u0010<\u001a\u00020\u001eH\u0002J\b\u0010=\u001a\u00020\u001eH\u0016J\b\u0010>\u001a\u00020\u001eH\u0016J\b\u0010?\u001a\u00020\u001eH\u0016J\u0010\u0010@\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020\u0002H\u0016R\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0011\u0010\t\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0010\u0010\u0011R\u001a\u0010\u0012\u001a\u000e\u0012\u0004\u0012\u00020\u0014\u0012\u0004\u0012\u00020\u00150\u0013X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001b\u0010\u0016\u001a\u00020\u00178BX\u0082\u0084\u0002\u00a2\u0006\f\n\u0004\b\u0019\u0010\u001a\u001a\u0004\b\u0016\u0010\u0018R\u0014\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u00020\u001cX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarContentInsetsProvider;", "Lcom/android/systemui/statusbar/policy/CallbackController;", "Lcom/android/systemui/statusbar/phone/StatusBarContentInsetsChangedListener;", "Lcom/android/systemui/statusbar/policy/ConfigurationController$ConfigurationListener;", "Lcom/android/systemui/Dumpable;", "context", "Landroid/content/Context;", "configurationController", "Lcom/android/systemui/statusbar/policy/ConfigurationController;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Landroid/content/Context;Lcom/android/systemui/statusbar/policy/ConfigurationController;Lcom/android/systemui/dump/DumpManager;)V", "getConfigurationController", "()Lcom/android/systemui/statusbar/policy/ConfigurationController;", "getContext", "()Landroid/content/Context;", "getDumpManager", "()Lcom/android/systemui/dump/DumpManager;", "insetsCache", "Landroid/util/LruCache;", "Lcom/android/systemui/statusbar/phone/StatusBarContentInsetsProvider$CacheKey;", "Landroid/graphics/Rect;", "isPrivacyDotEnabled", "", "()Z", "isPrivacyDotEnabled$delegate", "Lkotlin/Lazy;", "listeners", "", "addCallback", "", "listener", "clearCachedInsets", "currentRotationHasCornerCutout", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "getAndSetCalculatedAreaForRotation", "targetRotation", "", "rotatedResources", "Landroid/content/res/Resources;", "key", "getBoundingRectForPrivacyChipForRotation", "rotation", "getCacheKey", "getCalculatedAreaForRotation", "getStatusBarContentAreaForCurrentRotation", "getStatusBarContentAreaForRotation", "getStatusBarContentInsetsForCurrentRotation", "Landroid/util/Pair;", "getStatusBarContentInsetsForRotation", "getStatusBarPaddingTop", "(Ljava/lang/Integer;)I", "notifyInsetsChanged", "onDensityOrFontScaleChanged", "onMaxBoundsChanged", "onThemeChanged", "removeCallback", "CacheKey"})
@com.android.systemui.dagger.SysUISingleton()
public final class StatusBarContentInsetsProvider implements com.android.systemui.statusbar.policy.CallbackController<com.android.systemui.statusbar.phone.StatusBarContentInsetsChangedListener>, com.android.systemui.statusbar.policy.ConfigurationController.ConfigurationListener, com.android.systemui.Dumpable {
    private final android.util.LruCache<com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider.CacheKey, android.graphics.Rect> insetsCache = null;
    private final java.util.Set<com.android.systemui.statusbar.phone.StatusBarContentInsetsChangedListener> listeners = null;
    private final kotlin.Lazy isPrivacyDotEnabled$delegate = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.Context context = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.statusbar.policy.ConfigurationController configurationController = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.dump.DumpManager dumpManager = null;
    
    private final boolean isPrivacyDotEnabled() {
        return false;
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarContentInsetsChangedListener listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarContentInsetsChangedListener listener) {
    }
    
    @java.lang.Override()
    public void onDensityOrFontScaleChanged() {
    }
    
    @java.lang.Override()
    public void onThemeChanged() {
    }
    
    @java.lang.Override()
    public void onMaxBoundsChanged() {
    }
    
    private final void clearCachedInsets() {
    }
    
    private final void notifyInsetsChanged() {
    }
    
    /**
     * Some views may need to care about whether or not the current top display cutout is located
     * in the corner rather than somewhere in the center. In the case of a corner cutout, the
     * status bar area is contiguous.
     */
    public final boolean currentRotationHasCornerCutout() {
        return false;
    }
    
    /**
     * Calculates the maximum bounding rectangle for the privacy chip animation + ongoing privacy
     * dot in the coordinates relative to the given rotation.
     *
     * @param rotation the rotation for which the bounds are required. This is an absolute value
     *     (i.e., ROTATION_NONE will always return the same bounds regardless of the context
     *     from which this method is called)
     */
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Rect getBoundingRectForPrivacyChipForRotation(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int rotation) {
        return null;
    }
    
    /**
     * Calculate the distance from the left and right edges of the screen to the status bar
     * content area. This differs from the content area rects in that these values can be used
     * directly as padding.
     *
     * @param rotation the target rotation for which to calculate insets
     */
    @org.jetbrains.annotations.NotNull()
    public final android.util.Pair<java.lang.Integer, java.lang.Integer> getStatusBarContentInsetsForRotation(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int rotation) {
        return null;
    }
    
    /**
     * Calculate the left and right insets for the status bar content in the device's current
     * rotation
     * @see getStatusBarContentAreaForRotation
     */
    @org.jetbrains.annotations.NotNull()
    public final android.util.Pair<java.lang.Integer, java.lang.Integer> getStatusBarContentInsetsForCurrentRotation() {
        return null;
    }
    
    /**
     * Calculates the area of the status bar contents invariant of  the current device rotation,
     * in the target rotation's coordinates
     *
     * @param rotation the rotation for which the bounds are required. This is an absolute value
     *     (i.e., ROTATION_NONE will always return the same bounds regardless of the context
     *     from which this method is called)
     */
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Rect getStatusBarContentAreaForRotation(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int rotation) {
        return null;
    }
    
    /**
     * Get the status bar content area for the given rotation, in absolute bounds
     */
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.Rect getStatusBarContentAreaForCurrentRotation() {
        return null;
    }
    
    private final android.graphics.Rect getAndSetCalculatedAreaForRotation(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int targetRotation, android.content.res.Resources rotatedResources, com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider.CacheKey key) {
        return null;
    }
    
    private final android.graphics.Rect getCalculatedAreaForRotation(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int targetRotation, android.content.res.Resources rotatedResources) {
        return null;
    }
    
    public final int getStatusBarPaddingTop(@org.jetbrains.annotations.Nullable()
    @com.android.systemui.util.leak.RotationUtils.Rotation()
    java.lang.Integer rotation) {
        return 0;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    private final com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider.CacheKey getCacheKey(@com.android.systemui.util.leak.RotationUtils.Rotation()
    int rotation) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.Context getContext() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.statusbar.policy.ConfigurationController getConfigurationController() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.dump.DumpManager getDumpManager() {
        return null;
    }
    
    @javax.inject.Inject()
    public StatusBarContentInsetsProvider(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.ConfigurationController configurationController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000 \n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\t\n\u0002\u0010\u000b\n\u0002\b\u0003\b\u0082\b\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\t\u0010\u000b\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\f\u001a\u00020\u0005H\u00c6\u0003J\u001d\u0010\r\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u000e\u001a\u00020\u000f2\b\u0010\u0010\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0011\u001a\u00020\u0005H\u00d6\u0001J\t\u0010\u0012\u001a\u00020\u0003H\u00d6\u0001R\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0007\u0010\bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\n"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarContentInsetsProvider$CacheKey;", "", "uniqueDisplayId", "", "rotation", "", "(Ljava/lang/String;I)V", "getRotation", "()I", "getUniqueDisplayId", "()Ljava/lang/String;", "component1", "component2", "copy", "equals", "", "other", "hashCode", "toString"})
    static final class CacheKey {
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String uniqueDisplayId = null;
        private final int rotation = 0;
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getUniqueDisplayId() {
            return null;
        }
        
        public final int getRotation() {
            return 0;
        }
        
        public CacheKey(@org.jetbrains.annotations.NotNull()
        java.lang.String uniqueDisplayId, @com.android.systemui.util.leak.RotationUtils.Rotation()
        int rotation) {
            super();
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component1() {
            return null;
        }
        
        public final int component2() {
            return 0;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider.CacheKey copy(@org.jetbrains.annotations.NotNull()
        java.lang.String uniqueDisplayId, @com.android.systemui.util.leak.RotationUtils.Rotation()
        int rotation) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}