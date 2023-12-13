package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.controls.controller.ControlInfo;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000N\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0010\r\n\u0002\b\b\n\u0002\u0010\u0000\n\u0002\b\u0002\b\u0086\b\u0018\u00002\u00020\u00012\u00020\u0002B\r\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\u0002\u0010\u0005J\t\u0010$\u001a\u00020\u0004H\u00c6\u0003J\u0013\u0010%\u001a\u00020\u00002\b\b\u0002\u0010\u0003\u001a\u00020\u0004H\u00c6\u0001J\u0013\u0010&\u001a\u00020\u00192\b\u0010\'\u001a\u0004\u0018\u00010(H\u00d6\u0003J\t\u0010)\u001a\u00020\u0015H\u00d6\u0001J\t\u0010*\u001a\u00020\u000bH\u00d6\u0001R\u0012\u0010\u0006\u001a\u00020\u0007X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\b\u0010\tR\u0012\u0010\n\u001a\u00020\u000bX\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0003\u001a\u00020\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR\u0014\u0010\u0010\u001a\u0004\u0018\u00010\u0011X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\u0012\u0010\u0013R\u0012\u0010\u0014\u001a\u00020\u0015X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\u0016\u0010\u0017R\u0012\u0010\u0018\u001a\u00020\u0019X\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\u001a\u0010\u001bR\u0014\u0010\u001c\u001a\u00020\u00198VX\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b\u001d\u0010\u001bR\u0012\u0010\u001e\u001a\u00020\u001fX\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b \u0010!R\u0012\u0010\"\u001a\u00020\u001fX\u0096\u0005\u00a2\u0006\u0006\u001a\u0004\b#\u0010!"}, d2 = {"Lcom/android/systemui/controls/management/ControlStatusWrapper;", "Lcom/android/systemui/controls/management/ElementWrapper;", "Lcom/android/systemui/controls/ControlInterface;", "controlStatus", "Lcom/android/systemui/controls/ControlStatus;", "(Lcom/android/systemui/controls/ControlStatus;)V", "component", "Landroid/content/ComponentName;", "getComponent", "()Landroid/content/ComponentName;", "controlId", "", "getControlId", "()Ljava/lang/String;", "getControlStatus", "()Lcom/android/systemui/controls/ControlStatus;", "customIcon", "Landroid/graphics/drawable/Icon;", "getCustomIcon", "()Landroid/graphics/drawable/Icon;", "deviceType", "", "getDeviceType", "()I", "favorite", "", "getFavorite", "()Z", "removed", "getRemoved", "subtitle", "", "getSubtitle", "()Ljava/lang/CharSequence;", "title", "getTitle", "component1", "copy", "equals", "other", "", "hashCode", "toString"})
public final class ControlStatusWrapper extends com.android.systemui.controls.management.ElementWrapper implements com.android.systemui.controls.ControlInterface {
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.ControlStatus controlStatus = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ControlStatus getControlStatus() {
        return null;
    }
    
    public ControlStatusWrapper(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ControlStatus controlStatus) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.ComponentName getComponent() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String getControlId() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.graphics.drawable.Icon getCustomIcon() {
        return null;
    }
    
    @java.lang.Override()
    public int getDeviceType() {
        return 0;
    }
    
    @java.lang.Override()
    public boolean getFavorite() {
        return false;
    }
    
    @java.lang.Override()
    public boolean getRemoved() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getSubtitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.CharSequence getTitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.ControlStatus component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.ControlStatusWrapper copy(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ControlStatus controlStatus) {
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