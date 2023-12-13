package com.android.systemui.controls;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import android.service.controls.Control;
import android.service.controls.DeviceTypes;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\r\n\u0002\b\u0004\bf\u0018\u00002\u00020\u0001R\u0012\u0010\u0002\u001a\u00020\u0003X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0004\u0010\u0005R\u0012\u0010\u0006\u001a\u00020\u0007X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\tR\u0014\u0010\n\u001a\u0004\u0018\u00010\u000bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u0018\u0010\u000e\u001a\u00020\u000fX\u00a6\u0004\u00a2\u0006\f\u0012\u0004\b\u0010\u0010\u0011\u001a\u0004\b\u0012\u0010\u0013R\u0012\u0010\u0014\u001a\u00020\u0015X\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0016\u0010\u0017R\u0014\u0010\u0018\u001a\u00020\u00158VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0019\u0010\u0017R\u0012\u0010\u001a\u001a\u00020\u001bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001c\u0010\u001dR\u0012\u0010\u001e\u001a\u00020\u001bX\u00a6\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001f\u0010\u001d"}, d2 = {"Lcom/android/systemui/controls/ControlInterface;", "", "component", "Landroid/content/ComponentName;", "getComponent", "()Landroid/content/ComponentName;", "controlId", "", "getControlId", "()Ljava/lang/String;", "customIcon", "Landroid/graphics/drawable/Icon;", "getCustomIcon", "()Landroid/graphics/drawable/Icon;", "deviceType", "", "getDeviceType$annotations", "()V", "getDeviceType", "()I", "favorite", "", "getFavorite", "()Z", "removed", "getRemoved", "subtitle", "", "getSubtitle", "()Ljava/lang/CharSequence;", "title", "getTitle"})
public abstract interface ControlInterface {
    
    public abstract boolean getFavorite();
    
    @org.jetbrains.annotations.NotNull()
    public abstract android.content.ComponentName getComponent();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.String getControlId();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.CharSequence getTitle();
    
    @org.jetbrains.annotations.NotNull()
    public abstract java.lang.CharSequence getSubtitle();
    
    public abstract boolean getRemoved();
    
    @org.jetbrains.annotations.Nullable()
    public abstract android.graphics.drawable.Icon getCustomIcon();
    
    public abstract int getDeviceType();
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        public static boolean getRemoved(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.ControlInterface $this) {
            return false;
        }
        
        @android.service.controls.DeviceTypes.DeviceType()
        @java.lang.Deprecated()
        public static void getDeviceType$annotations() {
        }
    }
}