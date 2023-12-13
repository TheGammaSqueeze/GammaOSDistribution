package com.android.systemui.statusbar.phone.panelstate;

import android.annotation.IntDef;
import android.util.Log;
import androidx.annotation.FloatRange;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * A class responsible for managing the notification panel's current state.
 *
 * TODO(b/200063118): Make this class the one source of truth for the state of panel expansion.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000B\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0007\n\u0000\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0004\n\u0002\u0010\u000e\n\u0002\b\u0006\b\u0007\u0018\u00002\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0010\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0007J\u000e\u0010\u0013\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000eJ\u0010\u0010\u0014\u001a\u00020\u00112\u0006\u0010\u0015\u001a\u00020\u0016H\u0002J\u0006\u0010\u0017\u001a\u00020\u0004J \u0010\u0018\u001a\u00020\u00112\b\b\u0001\u0010\b\u001a\u00020\t2\u0006\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u000f\u001a\u00020\u0004J\u000e\u0010\u0019\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u0007J\u000e\u0010\u001a\u001a\u00020\u00112\u0006\u0010\u0012\u001a\u00020\u000eJ\u000e\u0010\u001b\u001a\u00020\u00112\u0006\u0010\n\u001a\u00020\u000bJ\u0010\u0010\u001c\u001a\u00020\u00112\u0006\u0010\n\u001a\u00020\u000bH\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0005\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0012\u0010\b\u001a\u00020\t8\u0002@\u0002X\u0083\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010\n\u001a\u00020\u000bX\u0082\u000e\u00a2\u0006\b\n\u0000\u0012\u0004\b\f\u0010\u0002R\u0014\u0010\r\u001a\b\u0012\u0004\u0012\u00020\u000e0\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/panelstate/PanelExpansionStateManager;", "", "()V", "expanded", "", "expansionListeners", "", "Lcom/android/systemui/statusbar/phone/panelstate/PanelExpansionListener;", "fraction", "", "state", "", "getState$annotations", "stateListeners", "Lcom/android/systemui/statusbar/phone/panelstate/PanelStateListener;", "tracking", "addExpansionListener", "", "listener", "addStateListener", "debugLog", "msg", "", "isClosed", "onPanelExpansionChanged", "removeExpansionListener", "removeStateListener", "updateState", "updateStateInternal"})
@com.android.systemui.dagger.SysUISingleton()
public final class PanelExpansionStateManager {
    private final java.util.List<com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener> expansionListeners = null;
    private final java.util.List<com.android.systemui.statusbar.phone.panelstate.PanelStateListener> stateListeners = null;
    private int state = 0;
    @androidx.annotation.FloatRange(from = 0.0, to = 1.0)
    private float fraction = 0.0F;
    private boolean expanded = false;
    private boolean tracking = false;
    
    @PanelState()
    @java.lang.Deprecated()
    private static void getState$annotations() {
    }
    
    /**
     * Adds a listener that will be notified when the panel expansion fraction has changed.
     *
     * Listener will also be immediately notified with the current values.
     */
    public final void addExpansionListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener listener) {
    }
    
    /**
     * Removes an expansion listener.
     */
    public final void removeExpansionListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.panelstate.PanelExpansionListener listener) {
    }
    
    /**
     * Adds a listener that will be notified when the panel state has changed.
     */
    public final void addStateListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.panelstate.PanelStateListener listener) {
    }
    
    /**
     * Removes a state listener.
     */
    public final void removeStateListener(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.panelstate.PanelStateListener listener) {
    }
    
    /**
     * Returns true if the panel is currently closed and false otherwise.
     */
    public final boolean isClosed() {
        return false;
    }
    
    /**
     * Called when the panel expansion has changed.
     *
     * @param fraction the fraction from the expansion in [0, 1]
     * @param expanded whether the panel is currently expanded; this is independent from the
     * fraction as the panel also might be expanded if the fraction is 0.
     * @param tracking whether we're currently tracking the user's gesture.
     */
    public final void onPanelExpansionChanged(@androidx.annotation.FloatRange(from = 0.0, to = 1.0)
    float fraction, boolean expanded, boolean tracking) {
    }
    
    /**
     * Updates the panel state if necessary.
     */
    public final void updateState(@PanelState()
    int state) {
    }
    
    private final void updateStateInternal(@PanelState()
    int state) {
    }
    
    private final void debugLog(java.lang.String msg) {
    }
    
    @javax.inject.Inject()
    public PanelExpansionStateManager() {
        super();
    }
}