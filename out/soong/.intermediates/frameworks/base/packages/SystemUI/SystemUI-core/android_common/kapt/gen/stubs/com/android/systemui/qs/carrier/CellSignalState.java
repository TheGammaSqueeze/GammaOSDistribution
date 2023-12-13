package com.android.systemui.qs.carrier;

import java.lang.System;

/**
 * Represents the state of cell signal for a particular slot.
 *
 * To be used between [QSCarrierGroupController] and [QSCarrier].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0010\b\u0086\b\u0018\u00002\u00020\u0001BE\u0012\b\b\u0002\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0002\u0010\u0004\u001a\u00020\u0005\u0012\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u0007\u0012\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\u0007\u0012\b\b\u0002\u0010\t\u001a\u00020\u0003\u0012\b\b\u0002\u0010\n\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u000bJ\u000e\u0010\f\u001a\u00020\u00002\u0006\u0010\u0002\u001a\u00020\u0003J\t\u0010\r\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000e\u001a\u00020\u0005H\u00c6\u0003J\u000b\u0010\u000f\u001a\u0004\u0018\u00010\u0007H\u00c6\u0003J\u000b\u0010\u0010\u001a\u0004\u0018\u00010\u0007H\u00c6\u0003J\t\u0010\u0011\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u0012\u001a\u00020\u0003H\u00c6\u0003JI\u0010\u0013\u001a\u00020\u00002\b\b\u0002\u0010\u0002\u001a\u00020\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00052\n\b\u0002\u0010\u0006\u001a\u0004\u0018\u00010\u00072\n\b\u0002\u0010\b\u001a\u0004\u0018\u00010\u00072\b\b\u0002\u0010\t\u001a\u00020\u00032\b\b\u0002\u0010\n\u001a\u00020\u0003H\u00c6\u0001J\u0013\u0010\u0014\u001a\u00020\u00032\b\u0010\u0015\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0016\u001a\u00020\u0005H\u00d6\u0001J\t\u0010\u0017\u001a\u00020\u0007H\u00d6\u0001R\u0012\u0010\u0006\u001a\u0004\u0018\u00010\u00078\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0004\u001a\u00020\u00058\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\n\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\t\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\b\u001a\u0004\u0018\u00010\u00078\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0002\u001a\u00020\u00038\u0006X\u0087\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/carrier/CellSignalState;", "", "visible", "", "mobileSignalIconId", "", "contentDescription", "", "typeContentDescription", "roaming", "providerModelBehavior", "(ZILjava/lang/String;Ljava/lang/String;ZZ)V", "changeVisibility", "component1", "component2", "component3", "component4", "component5", "component6", "copy", "equals", "other", "hashCode", "toString"})
public final class CellSignalState {
    public final boolean visible = false;
    public final int mobileSignalIconId = 0;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String contentDescription = null;
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String typeContentDescription = null;
    public final boolean roaming = false;
    public final boolean providerModelBehavior = false;
    
    /**
     * Changes the visibility of this state by returning a copy with the visibility changed.
     *
     * If the visibility would not change, the same state is returned.
     *
     * @param visible the new visibility state
     * @return `this` if `this.visible == visible`. Else, a new copy with the visibility changed.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.qs.carrier.CellSignalState changeVisibility(boolean visible) {
        return null;
    }
    
    public CellSignalState(boolean visible, int mobileSignalIconId, @org.jetbrains.annotations.Nullable()
    java.lang.String contentDescription, @org.jetbrains.annotations.Nullable()
    java.lang.String typeContentDescription, boolean roaming, boolean providerModelBehavior) {
        super();
    }
    
    public CellSignalState() {
        super();
    }
    
    public final boolean component1() {
        return false;
    }
    
    public final int component2() {
        return 0;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component3() {
        return null;
    }
    
    @org.jetbrains.annotations.Nullable()
    public final java.lang.String component4() {
        return null;
    }
    
    public final boolean component5() {
        return false;
    }
    
    public final boolean component6() {
        return false;
    }
    
    /**
     * Represents the state of cell signal for a particular slot.
     *
     * To be used between [QSCarrierGroupController] and [QSCarrier].
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.qs.carrier.CellSignalState copy(boolean visible, int mobileSignalIconId, @org.jetbrains.annotations.Nullable()
    java.lang.String contentDescription, @org.jetbrains.annotations.Nullable()
    java.lang.String typeContentDescription, boolean roaming, boolean providerModelBehavior) {
        return null;
    }
    
    /**
     * Represents the state of cell signal for a particular slot.
     *
     * To be used between [QSCarrierGroupController] and [QSCarrier].
     */
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.lang.String toString() {
        return null;
    }
    
    /**
     * Represents the state of cell signal for a particular slot.
     *
     * To be used between [QSCarrierGroupController] and [QSCarrier].
     */
    @java.lang.Override()
    public int hashCode() {
        return 0;
    }
    
    /**
     * Represents the state of cell signal for a particular slot.
     *
     * To be used between [QSCarrierGroupController] and [QSCarrier].
     */
    @java.lang.Override()
    public boolean equals(@org.jetbrains.annotations.Nullable()
    java.lang.Object p0) {
        return false;
    }
}