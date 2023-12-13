package com.android.systemui.statusbar.phone.ongoingcall;

import java.lang.System;

/**
 * A listener that's notified when the state of an ongoing call has changed.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/phone/ongoingcall/OngoingCallListener;", "", "onOngoingCallStateChanged", "", "animate", ""})
public abstract interface OngoingCallListener {
    
    /**
     * Called when the state of an ongoing call has changed in any way that may affect view
     * visibility (including call starting, call stopping, application managing the call becoming
     * visible or invisible).
     */
    public abstract void onOngoingCallStateChanged(boolean animate);
}