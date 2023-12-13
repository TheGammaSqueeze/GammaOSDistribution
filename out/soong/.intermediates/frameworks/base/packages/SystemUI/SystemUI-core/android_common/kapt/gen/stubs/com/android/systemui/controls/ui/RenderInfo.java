package com.android.systemui.controls.ui;

import android.annotation.ColorRes;
import android.annotation.MainThread;
import android.content.ComponentName;
import android.content.Context;
import android.graphics.drawable.Drawable;
import android.service.controls.DeviceTypes;
import android.service.controls.templates.TemperatureControlTemplate;
import android.util.ArrayMap;
import android.util.SparseArray;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\f\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0000\b\u0086\b\u0018\u0000 \u00172\u00020\u0001:\u0001\u0017B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0007J\t\u0010\r\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000e\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u000f\u001a\u00020\u0005H\u00c6\u0003J\'\u0010\u0010\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u0005H\u00c6\u0001J\u0013\u0010\u0011\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0014\u001a\u00020\u0005H\u00d6\u0001J\t\u0010\u0015\u001a\u00020\u0016H\u00d6\u0001R\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\tR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/systemui/controls/ui/RenderInfo;", "", "icon", "Landroid/graphics/drawable/Drawable;", "foreground", "", "enabledBackground", "(Landroid/graphics/drawable/Drawable;II)V", "getEnabledBackground", "()I", "getForeground", "getIcon", "()Landroid/graphics/drawable/Drawable;", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "toString", "", "Companion"})
public final class RenderInfo {
    @org.jetbrains.annotations.NotNull()
    private final android.graphics.drawable.Drawable icon = null;
    private final int foreground = 0;
    private final int enabledBackground = 0;
    public static final int APP_ICON_ID = -1;
    public static final int ERROR_ICON = -1000;
    private static final android.util.SparseArray<android.graphics.drawable.Drawable> iconMap = null;
    private static final android.util.ArrayMap<android.content.ComponentName, android.graphics.drawable.Drawable> appIconMap = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.ui.RenderInfo.Companion Companion = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable getIcon() {
        return null;
    }
    
    public final int getForeground() {
        return 0;
    }
    
    public final int getEnabledBackground() {
        return 0;
    }
    
    public RenderInfo(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable icon, int foreground, @android.annotation.ColorRes()
    int enabledBackground) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.graphics.drawable.Drawable component1() {
        return null;
    }
    
    public final int component2() {
        return 0;
    }
    
    public final int component3() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ui.RenderInfo copy(@org.jetbrains.annotations.NotNull()
    android.graphics.drawable.Drawable icon, int foreground, @android.annotation.ColorRes()
    int enabledBackground) {
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
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u0006\u0010\f\u001a\u00020\rJ(\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\b2\u0006\u0010\u0013\u001a\u00020\u00042\b\b\u0002\u0010\u0014\u001a\u00020\u0004J\u0016\u0010\u0015\u001a\u00020\r2\u0006\u0010\u0012\u001a\u00020\b2\u0006\u0010\u0016\u001a\u00020\tR\u000e\u0010\u0003\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u0006\u001a\u000e\u0012\u0004\u0012\u00020\b\u0012\u0004\u0012\u00020\t0\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\b\u0012\u0004\u0012\u00020\t0\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/ui/RenderInfo$Companion;", "", "()V", "APP_ICON_ID", "", "ERROR_ICON", "appIconMap", "Landroid/util/ArrayMap;", "Landroid/content/ComponentName;", "Landroid/graphics/drawable/Drawable;", "iconMap", "Landroid/util/SparseArray;", "clearCache", "", "lookup", "Lcom/android/systemui/controls/ui/RenderInfo;", "context", "Landroid/content/Context;", "componentName", "deviceType", "offset", "registerComponentIcon", "icon"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        @android.annotation.MainThread()
        public final com.android.systemui.controls.ui.RenderInfo lookup(@org.jetbrains.annotations.NotNull()
        android.content.Context context, @org.jetbrains.annotations.NotNull()
        android.content.ComponentName componentName, int deviceType, int offset) {
            return null;
        }
        
        public final void registerComponentIcon(@org.jetbrains.annotations.NotNull()
        android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
        android.graphics.drawable.Drawable icon) {
        }
        
        public final void clearCache() {
        }
        
        private Companion() {
            super();
        }
    }
}