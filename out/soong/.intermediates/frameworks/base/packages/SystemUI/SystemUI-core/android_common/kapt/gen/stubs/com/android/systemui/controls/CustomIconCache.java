package com.android.systemui.controls;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import androidx.annotation.GuardedBy;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * Icon cache for custom icons sent with controls.
 *
 * It assumes that only one component can be current at the time, to minimize the number of icons
 * stored at a given time.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010%\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0005\b\u0007\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\b\u0010\t\u001a\u00020\nH\u0002J\u0018\u0010\u000b\u001a\u0004\u0018\u00010\u00062\u0006\u0010\f\u001a\u00020\b2\u0006\u0010\r\u001a\u00020\u0005J \u0010\u000e\u001a\u00020\n2\u0006\u0010\f\u001a\u00020\b2\u0006\u0010\r\u001a\u00020\u00052\b\u0010\u000f\u001a\u0004\u0018\u00010\u0006R\u001c\u0010\u0003\u001a\u000e\u0012\u0004\u0012\u00020\u0005\u0012\u0004\u0012\u00020\u00060\u00048\u0002X\u0083\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/CustomIconCache;", "", "()V", "cache", "", "", "Landroid/graphics/drawable/Icon;", "currentComponent", "Landroid/content/ComponentName;", "clear", "", "retrieve", "component", "controlId", "store", "icon"})
@com.android.systemui.dagger.SysUISingleton()
public final class CustomIconCache {
    private android.content.ComponentName currentComponent;
    @androidx.annotation.GuardedBy(value = "cache")
    private final java.util.Map<java.lang.String, android.graphics.drawable.Icon> cache = null;
    
    /**
     * Store an icon in the cache.
     *
     * If the icons currently stored do not correspond to the component to be stored, the cache is
     * cleared first.
     */
    public final void store(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @org.jetbrains.annotations.Nullable()
    android.graphics.drawable.Icon icon) {
    }
    
    /**
     * Retrieves a custom icon stored in the cache.
     *
     * It will return null if the component requested is not the one whose icons are stored, or if
     * there is no icon cached for that id.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Icon retrieve(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    java.lang.String controlId) {
        return null;
    }
    
    private final void clear() {
    }
    
    @javax.inject.Inject()
    public CustomIconCache() {
        super();
    }
}