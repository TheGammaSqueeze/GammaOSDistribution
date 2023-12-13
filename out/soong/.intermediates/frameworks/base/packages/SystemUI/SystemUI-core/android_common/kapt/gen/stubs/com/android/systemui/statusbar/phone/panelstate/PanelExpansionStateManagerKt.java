package com.android.systemui.statusbar.phone.panelstate;

import android.annotation.IntDef;
import android.util.Log;
import androidx.annotation.FloatRange;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u0016\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000e\n\u0000\u001a\f\u0010\b\u001a\u00020\u0007*\u00020\u0003H\u0002\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0003X\u0086T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0005\u001a\u00020\u0003X\u0086T\u00a2\u0006\u0002\n\u0000\"\u0010\u0010\u0006\u001a\u0004\u0018\u00010\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"DEBUG", "", "STATE_CLOSED", "", "STATE_OPEN", "STATE_OPENING", "TAG", "", "stateToString"})
public final class PanelExpansionStateManagerKt {
    public static final int STATE_CLOSED = 0;
    public static final int STATE_OPENING = 1;
    public static final int STATE_OPEN = 2;
    private static final boolean DEBUG = false;
    private static final java.lang.String TAG = null;
    
    @PanelState()
    private static final java.lang.String stateToString(int $this$stateToString) {
        return null;
    }
}