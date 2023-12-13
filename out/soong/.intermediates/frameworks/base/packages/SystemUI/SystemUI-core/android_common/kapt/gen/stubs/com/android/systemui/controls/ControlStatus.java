package com.android.systemui.controls;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import android.service.controls.Control;
import android.service.controls.DeviceTypes;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0007\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\n\n\u0002\u0010\r\n\u0002\b\u000b\n\u0002\u0010\u0000\n\u0002\b\u0002\b\u0086\b\u0018\u00002\u00020\u0001B\'\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\b\b\u0002\u0010\b\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\tJ\t\u0010\'\u001a\u00020\u0003H\u00c6\u0003J\t\u0010(\u001a\u00020\u0005H\u00c6\u0003J\t\u0010)\u001a\u00020\u0007H\u00c6\u0003J\t\u0010*\u001a\u00020\u0007H\u00c6\u0003J1\u0010+\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072\b\b\u0002\u0010\b\u001a\u00020\u0007H\u00c6\u0001J\u0013\u0010,\u001a\u00020\u00072\b\u0010-\u001a\u0004\u0018\u00010.H\u00d6\u0003J\t\u0010/\u001a\u00020\u0017H\u00d6\u0001J\t\u00100\u001a\u00020\u000fH\u00d6\u0001R\u0014\u0010\u0004\u001a\u00020\u0005X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0014\u0010\u000e\u001a\u00020\u000f8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0010\u0010\u0011R\u0016\u0010\u0012\u001a\u0004\u0018\u00010\u00138VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0014\u0010\u0015R\u001a\u0010\u0016\u001a\u00020\u00178VX\u0096\u0004\u00a2\u0006\f\u0012\u0004\b\u0018\u0010\u0019\u001a\u0004\b\u001a\u0010\u001bR\u001a\u0010\u0006\u001a\u00020\u0007X\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u001c\u0010\u001d\"\u0004\b\u001e\u0010\u001fR\u0014\u0010\b\u001a\u00020\u0007X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b \u0010\u001dR\u0014\u0010!\u001a\u00020\"8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b#\u0010$R\u0014\u0010%\u001a\u00020\"8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b&\u0010$"}, d2 = {"Lcom/android/systemui/controls/ControlStatus;", "Lcom/android/systemui/controls/ControlInterface;", "control", "Landroid/service/controls/Control;", "component", "Landroid/content/ComponentName;", "favorite", "", "removed", "(Landroid/service/controls/Control;Landroid/content/ComponentName;ZZ)V", "getComponent", "()Landroid/content/ComponentName;", "getControl", "()Landroid/service/controls/Control;", "controlId", "", "getControlId", "()Ljava/lang/String;", "customIcon", "Landroid/graphics/drawable/Icon;", "getCustomIcon", "()Landroid/graphics/drawable/Icon;", "deviceType", "", "getDeviceType$annotations", "()V", "getDeviceType", "()I", "getFavorite", "()Z", "setFavorite", "(Z)V", "getRemoved", "subtitle", "", "getSubtitle", "()Ljava/lang/CharSequence;", "title", "getTitle", "component1", "component2", "component3", "component4", "copy", "equals", "other", "", "hashCode", "toString"})
public final class ControlStatus implements com.android.systemui.controls.ControlInterface {
    @org.jetbrains.annotations.NotNull()
    private final android.service.controls.Control control = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.ComponentName component = null;
    private boolean favorite;
    private final boolean removed = false;
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getControlId() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getTitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getSubtitle() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.graphics.drawable.Icon getCustomIcon() {
        return null;
    }
    
    @android.service.controls.DeviceTypes.DeviceType()
    @java.lang.Override()
    @java.lang.Deprecated()
    public static void getDeviceType$annotations() {
    }
    
    @java.lang.Override()
    public int getDeviceType() {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.Control getControl() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.ComponentName getComponent() {
        return null;
    }
    
    @java.lang.Override()
    public boolean getFavorite() {
        return false;
    }
    
    public void setFavorite(boolean p0) {
    }
    
    @java.lang.Override()
    public boolean getRemoved() {
        return false;
    }
    
    public ControlStatus(@org.jetbrains.annotations.NotNull()
    android.service.controls.Control control, @org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, boolean favorite, boolean removed) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.service.controls.Control component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName component2() {
        return null;
    }
    
    public final boolean component3() {
        return false;
    }
    
    public final boolean component4() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ControlStatus copy(@org.jetbrains.annotations.NotNull()
    android.service.controls.Control control, @org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, boolean favorite, boolean removed) {
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