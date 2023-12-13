package com.android.systemui.privacy;

import android.content.Context;
import com.android.systemui.R;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0010\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0086\u0001\u0018\u00002\b\u0012\u0004\u0012\u00020\u00000\u0001B\'\b\u0002\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\bJ\u0016\u0010\u000f\u001a\n \u0011*\u0004\u0018\u00010\u00100\u00102\u0006\u0010\u0012\u001a\u00020\u0013J\u0016\u0010\u0014\u001a\n \u0011*\u0004\u0018\u00010\u00060\u00062\u0006\u0010\u0012\u001a\u00020\u0013R\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\t\u0010\nR\u0011\u0010\u0007\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\fR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\nR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\fj\u0002\b\u0015j\u0002\b\u0016j\u0002\b\u0017"}, d2 = {"Lcom/android/systemui/privacy/PrivacyType;", "", "nameId", "", "iconId", "permGroupName", "", "logName", "(Ljava/lang/String;IIILjava/lang/String;Ljava/lang/String;)V", "getIconId", "()I", "getLogName", "()Ljava/lang/String;", "getNameId", "getPermGroupName", "getIcon", "Landroid/graphics/drawable/Drawable;", "kotlin.jvm.PlatformType", "context", "Landroid/content/Context;", "getName", "TYPE_CAMERA", "TYPE_MICROPHONE", "TYPE_LOCATION"})
public enum PrivacyType {
    /*public static final*/ TYPE_CAMERA /* = new TYPE_CAMERA(0, 0, null, null) */,
    /*public static final*/ TYPE_MICROPHONE /* = new TYPE_MICROPHONE(0, 0, null, null) */,
    /*public static final*/ TYPE_LOCATION /* = new TYPE_LOCATION(0, 0, null, null) */;
    private final int nameId = 0;
    private final int iconId = 0;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String permGroupName = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String logName = null;
    
    public final java.lang.String getName(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    public final android.graphics.drawable.Drawable getIcon(@org.jetbrains.annotations.NotNull()
    android.content.Context context) {
        return null;
    }
    
    public final int getNameId() {
        return 0;
    }
    
    public final int getIconId() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPermGroupName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getLogName() {
        return null;
    }
    
    PrivacyType(int nameId, int iconId, java.lang.String permGroupName, java.lang.String logName) {
    }
}