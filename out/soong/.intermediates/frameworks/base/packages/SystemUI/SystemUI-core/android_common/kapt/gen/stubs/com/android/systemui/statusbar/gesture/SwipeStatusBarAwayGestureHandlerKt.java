package com.android.systemui.statusbar.gesture;

import android.content.Context;
import android.os.Looper;
import android.view.Choreographer;
import android.view.Display;
import android.view.InputEvent;
import android.view.MotionEvent;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.shared.system.InputChannelCompat;
import com.android.systemui.shared.system.InputMonitorCompat;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\f\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0010\u000e\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u0010\u0010\u0002\u001a\u0004\u0018\u00010\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"SWIPE_TIMEOUT_MS", "", "TAG", ""})
public final class SwipeStatusBarAwayGestureHandlerKt {
    private static final long SWIPE_TIMEOUT_MS = 500L;
    private static final java.lang.String TAG = null;
}