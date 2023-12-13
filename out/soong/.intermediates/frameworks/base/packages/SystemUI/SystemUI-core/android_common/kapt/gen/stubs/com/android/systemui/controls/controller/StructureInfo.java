package com.android.systemui.controls.controller;

import android.content.ComponentName;

/**
 * Stores basic information about a Structure to persist and keep track of favorites.
 *
 * Every [component] [structure] pair uniquely identifies the structure.
 *
 * @property componentName the name of the component that provides the [Control].
 * @property structure common structure name of all underlying [controls], or empty string
 * @property controls all controls in the name structure
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00004\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\f\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\b\u0086\b\u0018\u00002\u00020\u0001B#\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\f\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u00a2\u0006\u0002\u0010\tJ\t\u0010\u0010\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0011\u001a\u00020\u0005H\u00c6\u0003J\u000f\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u00c6\u0003J-\u0010\u0013\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\u000e\b\u0002\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007H\u00c6\u0001J\u0013\u0010\u0014\u001a\u00020\u00152\b\u0010\u0016\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0017\u001a\u00020\u0018H\u00d6\u0001J\t\u0010\u0019\u001a\u00020\u001aH\u00d6\u0001R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0017\u0010\u0006\u001a\b\u0012\u0004\u0012\u00020\b0\u0007\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000f"}, d2 = {"Lcom/android/systemui/controls/controller/StructureInfo;", "", "componentName", "Landroid/content/ComponentName;", "structure", "", "controls", "", "Lcom/android/systemui/controls/controller/ControlInfo;", "(Landroid/content/ComponentName;Ljava/lang/CharSequence;Ljava/util/List;)V", "getComponentName", "()Landroid/content/ComponentName;", "getControls", "()Ljava/util/List;", "getStructure", "()Ljava/lang/CharSequence;", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "", "toString", ""})
public final class StructureInfo {
    @org.jetbrains.annotations.NotNull()
    private final android.content.ComponentName componentName = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.CharSequence structure = null;
    @org.jetbrains.annotations.NotNull()
    private final java.util.List<com.android.systemui.controls.controller.ControlInfo> controls = null;
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName getComponentName() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getStructure() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.ControlInfo> getControls() {
        return null;
    }
    
    public StructureInfo(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structure, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.ControlInfo> controls) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.ComponentName component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.ControlInfo> component3() {
        return null;
    }
    
    /**
     * Stores basic information about a Structure to persist and keep track of favorites.
     *
     * Every [component] [structure] pair uniquely identifies the structure.
     *
     * @property componentName the name of the component that provides the [Control].
     * @property structure common structure name of all underlying [controls], or empty string
     * @property controls all controls in the name structure
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.controller.StructureInfo copy(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structure, @org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.ControlInfo> controls) {
        return null;
    }
    
    /**
     * Stores basic information about a Structure to persist and keep track of favorites.
     *
     * Every [component] [structure] pair uniquely identifies the structure.
     *
     * @property componentName the name of the component that provides the [Control].
     * @property structure common structure name of all underlying [controls], or empty string
     * @property controls all controls in the name structure
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Stores basic information about a Structure to persist and keep track of favorites.
     *
     * Every [component] [structure] pair uniquely identifies the structure.
     *
     * @property componentName the name of the component that provides the [Control].
     * @property structure common structure name of all underlying [controls], or empty string
     * @property controls all controls in the name structure
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Stores basic information about a Structure to persist and keep track of favorites.
     *
     * Every [component] [structure] pair uniquely identifies the structure.
     *
     * @property componentName the name of the component that provides the [Control].
     * @property structure common structure name of all underlying [controls], or empty string
     * @property controls all controls in the name structure
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}