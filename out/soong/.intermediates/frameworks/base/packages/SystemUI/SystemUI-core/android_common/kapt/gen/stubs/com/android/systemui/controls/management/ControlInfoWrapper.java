package com.android.systemui.controls.management;

import android.content.ComponentName;
import android.graphics.drawable.Icon;
import androidx.recyclerview.widget.RecyclerView;
import com.android.systemui.controls.ControlInterface;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.controls.controller.ControlInfo;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000H\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000e\n\u0002\u0018\u0002\n\u0002\b\u0010\n\u0002\u0010\b\n\u0002\b\u0007\n\u0002\u0010\r\n\u0002\b\n\n\u0002\u0010\u0000\n\u0002\b\u0002\b\u0086\b\u0018\u00002\u00020\u00012\u00020\u0002B;\b\u0016\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u001a\u0010\t\u001a\u0016\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u000b\u0012\u0006\u0012\u0004\u0018\u00010\f0\n\u00a2\u0006\u0002\u0010\rB\u001d\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\u000eJ\t\u0010*\u001a\u00020\u0004H\u00c6\u0003J\t\u0010+\u001a\u00020\u0006H\u00c6\u0003J\t\u0010,\u001a\u00020\bH\u00c6\u0003J\'\u0010-\u001a\u00020\u00002\b\b\u0002\u0010\u0003\u001a\u00020\u00042\b\b\u0002\u0010\u0005\u001a\u00020\u00062\b\b\u0002\u0010\u0007\u001a\u00020\bH\u00c6\u0001J\u0013\u0010.\u001a\u00020\b2\b\u0010/\u001a\u0004\u0018\u000100H\u00d6\u0003J\t\u00101\u001a\u00020\u001dH\u00d6\u0001J\t\u00102\u001a\u00020\u000bH\u00d6\u0001R\u0014\u0010\u0003\u001a\u00020\u0004X\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R\u0014\u0010\u0011\u001a\u00020\u000b8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0012\u0010\u0013R\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0014\u0010\u0015R\u0016\u0010\u0016\u001a\u0004\u0018\u00010\f8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u0017\u0010\u0018RF\u0010\t\u001a\u0016\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u000b\u0012\u0006\u0012\u0004\u0018\u00010\f0\n2\u001a\u0010\u0019\u001a\u0016\u0012\u0004\u0012\u00020\u0004\u0012\u0004\u0012\u00020\u000b\u0012\u0006\u0012\u0004\u0018\u00010\f0\n@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001a\u0010\u001bR\u0014\u0010\u001c\u001a\u00020\u001d8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\u001e\u0010\u001fR\u001a\u0010\u0007\u001a\u00020\bX\u0096\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b \u0010!\"\u0004\b\"\u0010#R\u0014\u0010$\u001a\u00020%8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b&\u0010\'R\u0014\u0010(\u001a\u00020%8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b)\u0010\'"}, d2 = {"Lcom/android/systemui/controls/management/ControlInfoWrapper;", "Lcom/android/systemui/controls/management/ElementWrapper;", "Lcom/android/systemui/controls/ControlInterface;", "component", "Landroid/content/ComponentName;", "controlInfo", "Lcom/android/systemui/controls/controller/ControlInfo;", "favorite", "", "customIconGetter", "Lkotlin/Function2;", "", "Landroid/graphics/drawable/Icon;", "(Landroid/content/ComponentName;Lcom/android/systemui/controls/controller/ControlInfo;ZLkotlin/jvm/functions/Function2;)V", "(Landroid/content/ComponentName;Lcom/android/systemui/controls/controller/ControlInfo;Z)V", "getComponent", "()Landroid/content/ComponentName;", "controlId", "getControlId", "()Ljava/lang/String;", "getControlInfo", "()Lcom/android/systemui/controls/controller/ControlInfo;", "customIcon", "getCustomIcon", "()Landroid/graphics/drawable/Icon;", "<set-?>", "getCustomIconGetter", "()Lkotlin/jvm/functions/Function2;", "deviceType", "", "getDeviceType", "()I", "getFavorite", "()Z", "setFavorite", "(Z)V", "subtitle", "", "getSubtitle", "()Ljava/lang/CharSequence;", "title", "getTitle", "component1", "component2", "component3", "copy", "equals", "other", "", "hashCode", "toString"})
public final class ControlInfoWrapper extends com.android.systemui.controls.management.ElementWrapper implements com.android.systemui.controls.ControlInterface {
    @org.jetbrains.annotations.NotNull()
    private kotlin.jvm.functions.Function2<? super android.content.ComponentName, ? super java.lang.String, android.graphics.drawable.Icon> customIconGetter;
    @org.jetbrains.annotations.NotNull()
    private final android.content.ComponentName component = null;
    @org.jetbrains.annotations.NotNull()
    private final com.android.systemui.controls.controller.ControlInfo controlInfo = null;
    private boolean favorite;
    
    @org.jetbrains.annotations.NotNull()
    public final kotlin.jvm.functions.Function2<android.content.ComponentName, java.lang.String, android.graphics.drawable.Icon> getCustomIconGetter() {
        return null;
    }
    
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
    
    @java.lang.Override()
    public int getDeviceType() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    @java.lang.Override()
    public android.graphics.drawable.Icon getCustomIcon() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public android.content.ComponentName getComponent() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.controller.ControlInfo getControlInfo() {
        return null;
    }
    
    @java.lang.Override()
    public boolean getFavorite() {
        return false;
    }
    
    public void setFavorite(boolean p0) {
    }
    
    public ControlInfoWrapper(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, boolean favorite) {
    }
    
    public ControlInfoWrapper(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, boolean favorite, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super android.content.ComponentName, ? super java.lang.String, android.graphics.drawable.Icon> customIconGetter) {
    }
    
    public boolean getRemoved() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.controller.ControlInfo component2() {
        return null;
    }
    
    public final boolean component3() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.management.ControlInfoWrapper copy(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName component, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, boolean favorite) {
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