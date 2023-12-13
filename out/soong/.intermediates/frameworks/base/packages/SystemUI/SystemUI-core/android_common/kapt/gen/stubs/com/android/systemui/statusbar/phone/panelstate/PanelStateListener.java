package com.android.systemui.statusbar.phone.panelstate;

import java.lang.System;

/**
 * A listener interface to be notified of state change events for the notification panel.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/phone/panelstate/PanelStateListener;", "", "onPanelStateChanged", "", "state", ""})
public abstract interface PanelStateListener {
    
    /**
     * Called when the panel's expansion state has changed.
     */
    public abstract void onPanelStateChanged(@PanelState()
    int state);
}