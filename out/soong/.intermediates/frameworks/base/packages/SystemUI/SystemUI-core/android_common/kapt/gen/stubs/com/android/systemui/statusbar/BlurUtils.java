package com.android.systemui.statusbar;

import android.app.ActivityManager;
import android.content.res.Resources;
import android.os.SystemProperties;
import android.util.IndentingPrintWriter;
import android.util.MathUtils;
import android.view.CrossWindowBlurListeners;
import android.view.SurfaceControl;
import android.view.ViewRootImpl;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Main;
import com.android.systemui.dump.DumpManager;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000b\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0007\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0004\b\u0017\u0018\u00002\u00020\u0001B!\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ \u0010\u0010\u001a\u00020\u00112\b\u0010\u0012\u001a\u0004\u0018\u00010\u00132\u0006\u0010\u0014\u001a\u00020\n2\u0006\u0010\u0015\u001a\u00020\u0016J\u000e\u0010\u0017\u001a\u00020\u00182\u0006\u0010\u0019\u001a\u00020\u0018J\b\u0010\u001a\u001a\u00020\u001bH\u0017J-\u0010\u001c\u001a\u00020\u00112\u0006\u0010\u001d\u001a\u00020\u001e2\u0006\u0010\u001f\u001a\u00020 2\u000e\u0010!\u001a\n\u0012\u0006\b\u0001\u0012\u00020#0\"H\u0016\u00a2\u0006\u0002\u0010$J\u000e\u0010%\u001a\u00020\u00182\u0006\u0010&\u001a\u00020\u0018J\b\u0010\'\u001a\u00020\u0016H\u0016R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0011\u0010\u000b\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u000e\u001a\u00020\n\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\rR\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/BlurUtils;", "Lcom/android/systemui/Dumpable;", "resources", "Landroid/content/res/Resources;", "crossWindowBlurListeners", "Landroid/view/CrossWindowBlurListeners;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "(Landroid/content/res/Resources;Landroid/view/CrossWindowBlurListeners;Lcom/android/systemui/dump/DumpManager;)V", "lastAppliedBlur", "", "maxBlurRadius", "getMaxBlurRadius", "()I", "minBlurRadius", "getMinBlurRadius", "applyBlur", "", "viewRootImpl", "Landroid/view/ViewRootImpl;", "radius", "opaque", "", "blurRadiusOfRatio", "", "ratio", "createTransaction", "Landroid/view/SurfaceControl$Transaction;", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "ratioOfBlurRadius", "blur", "supportsBlursOnWindows"})
@com.android.systemui.dagger.SysUISingleton()
public class BlurUtils implements com.android.systemui.Dumpable {
    private final int minBlurRadius = 0;
    private final int maxBlurRadius = 0;
    private int lastAppliedBlur = 0;
    private final android.content.res.Resources resources = null;
    private final android.view.CrossWindowBlurListeners crossWindowBlurListeners = null;
    
    public final int getMinBlurRadius() {
        return 0;
    }
    
    public final int getMaxBlurRadius() {
        return 0;
    }
    
    /**
     * Translates a ratio from 0 to 1 to a blur radius in pixels.
     */
    public final float blurRadiusOfRatio(float ratio) {
        return 0.0F;
    }
    
    /**
     * Translates a blur radius in pixels to a ratio between 0 to 1.
     */
    public final float ratioOfBlurRadius(float blur) {
        return 0.0F;
    }
    
    /**
     * Applies background blurs to a {@link ViewRootImpl}.
     *
     * @param viewRootImpl The window root.
     * @param radius blur radius in pixels.
     * @param opaque if surface is opaque, regardless or having blurs or no.
     */
    public final void applyBlur(@org.jetbrains.annotations.Nullable()
    android.view.ViewRootImpl viewRootImpl, int radius, boolean opaque) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @androidx.annotation.VisibleForTesting()
    public android.view.SurfaceControl.Transaction createTransaction() {
        return null;
    }
    
    /**
     * If this device can render blurs.
     *
     * @see android.view.SurfaceControl.Transaction#setBackgroundBlurRadius(SurfaceControl, int)
     * @return {@code true} when supported.
     */
    public boolean supportsBlursOnWindows() {
        return false;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public BlurUtils(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.content.res.Resources resources, @org.jetbrains.annotations.NotNull()
    android.view.CrossWindowBlurListeners crossWindowBlurListeners, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager) {
        super();
    }
}