package com.android.systemui.statusbar.phone.panelstate;

import android.annotation.IntDef;
import android.util.Log;
import androidx.annotation.FloatRange;
import com.android.systemui.dagger.SysUISingleton;
import javax.inject.Inject;

/**
 * Enum for the current state of the panel.
 */
@android.annotation.IntDef(value = {0, 1, 2})
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\b\n\u0002\u0018\u0002\n\u0002\u0010\u001b\b\u0081\u0002\u0018\u00002\u00020\u0001B\u0000"}, d2 = {"Lcom/android/systemui/statusbar/phone/panelstate/PanelState;", ""})
@java.lang.annotation.Retention(value = java.lang.annotation.RetentionPolicy.SOURCE)
@kotlin.annotation.Retention(value = kotlin.annotation.AnnotationRetention.SOURCE)
public abstract @interface PanelState {
}