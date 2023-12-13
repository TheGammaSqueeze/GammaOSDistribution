package com.android.systemui.controls.controller;

import android.service.controls.Control;
import android.service.controls.DeviceTypes;

/**
 * Stores basic information about a [Control] to persist and keep track of favorites.
 *
 * The identifier of this [Control] is the [controlId], and is only unique per app. The other
 * fields are there for persistence. In this way, basic information can be shown to the user
 * before the service has to report on the status.
 *
 * @property controlId unique identifier for this [Control].
 * @property controlTitle last title reported for this [Control].
 * @property controlSubtitle last subtitle reported for this [Control].
 * @property deviceType last reported type for this [Control].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\r\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u000e\n\u0002\u0010\u000b\n\u0002\b\u0004\b\u0086\b\u0018\u0000 \u001b2\u00020\u0001:\u0001\u001bB%\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0005\u0012\u0006\u0010\u0007\u001a\u00020\b\u00a2\u0006\u0002\u0010\tJ\t\u0010\u0011\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0013\u001a\u00020\u0005H\u00c6\u0003J\t\u0010\u0014\u001a\u00020\bH\u00c6\u0003J1\u0010\u0015\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00052\b\b\u0002\u0010\u0007\u001a\u00020\bH\u00c6\u0001J\u0013\u0010\u0016\u001a\u00020\u00172\b\u0010\u0018\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0019\u001a\u00020\bH\u00d6\u0001J\b\u0010\u001a\u001a\u00020\u0003H\u0016R\u0011\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u0011\u0010\u0006\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\f\u0010\rR\u0011\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\rR\u0011\u0010\u0007\u001a\u00020\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010"}, d2 = {"Lcom/android/systemui/controls/controller/ControlInfo;", "", "controlId", "", "controlTitle", "", "controlSubtitle", "deviceType", "", "(Ljava/lang/String;Ljava/lang/CharSequence;Ljava/lang/CharSequence;I)V", "getControlId", "()Ljava/lang/String;", "getControlSubtitle", "()Ljava/lang/CharSequence;", "getControlTitle", "getDeviceType", "()I", "component1", "component2", "component3", "component4", "copy", "equals", "", "other", "hashCode", "toString", "Companion"})
public final class ControlInfo {
    @org.jetbrains.annotations.NotNull()
    private final java.lang.String controlId = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.CharSequence controlTitle = null;
    @org.jetbrains.annotations.NotNull()
    private final java.lang.CharSequence controlSubtitle = null;
    private final int deviceType = 0;
    private static final java.lang.String SEPARATOR = ":";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ControlInfo.Companion Companion = null;
    
    /**
     * Returns a [String] representation of the fields separated using [SEPARATOR].
     *
     * @return a [String] representation of `this`
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getControlId() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getControlTitle() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getControlSubtitle() {
        return null;
    }
    
    public final int getDeviceType() {
        return 0;
    }
    
    public ControlInfo(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence controlTitle, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence controlSubtitle, @android.service.controls.DeviceTypes.DeviceType()
    int deviceType) {
        super();
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String component1() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence component2() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence component3() {
        return null;
    }
    
    public final int component4() {
        return 0;
    }
    
    /**
     * Stores basic information about a [Control] to persist and keep track of favorites.
     *
     * The identifier of this [Control] is the [controlId], and is only unique per app. The other
     * fields are there for persistence. In this way, basic information can be shown to the user
     * before the service has to report on the status.
     *
     * @property controlId unique identifier for this [Control].
     * @property controlTitle last title reported for this [Control].
     * @property controlSubtitle last subtitle reported for this [Control].
     * @property deviceType last reported type for this [Control].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.controller.ControlInfo copy(@org.jetbrains.annotations.NotNull()
    java.lang.String controlId, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence controlTitle, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence controlSubtitle, @android.service.controls.DeviceTypes.DeviceType()
    int deviceType) {
        return null;
    }
    
    /**
     * Stores basic information about a [Control] to persist and keep track of favorites.
     *
     * The identifier of this [Control] is the [controlId], and is only unique per app. The other
     * fields are there for persistence. In this way, basic information can be shown to the user
     * before the service has to report on the status.
     *
     * @property controlId unique identifier for this [Control].
     * @property controlTitle last title reported for this [Control].
     * @property controlSubtitle last subtitle reported for this [Control].
     * @property deviceType last reported type for this [Control].
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Stores basic information about a [Control] to persist and keep track of favorites.
     *
     * The identifier of this [Control] is the [controlId], and is only unique per app. The other
     * fields are there for persistence. In this way, basic information can be shown to the user
     * before the service has to report on the status.
     *
     * @property controlId unique identifier for this [Control].
     * @property controlTitle last title reported for this [Control].
     * @property controlSubtitle last subtitle reported for this [Control].
     * @property deviceType last reported type for this [Control].
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001c\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\bR\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlInfo$Companion;", "", "()V", "SEPARATOR", "", "fromControl", "Lcom/android/systemui/controls/controller/ControlInfo;", "control", "Landroid/service/controls/Control;"})
    public static final class Companion {
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.systemui.controls.controller.ControlInfo fromControl(@org.jetbrains.annotations.NotNull()
        android.service.controls.Control control) {
            return null;
        }
        
        private Companion() {
            super();
        }
    }
}