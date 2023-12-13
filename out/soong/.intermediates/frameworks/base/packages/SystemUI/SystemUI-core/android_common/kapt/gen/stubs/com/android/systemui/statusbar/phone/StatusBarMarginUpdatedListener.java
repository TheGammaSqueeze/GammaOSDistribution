package com.android.systemui.statusbar.phone;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.policy.CallbackController;
import java.lang.ref.WeakReference;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0016\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\b\n\u0000\bf\u0018\u00002\u00020\u0001J\u0018\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\u0006\u0010\u0006\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarMarginUpdatedListener;", "", "onStatusBarMarginUpdated", "", "marginLeft", "", "marginRight"})
public abstract interface StatusBarMarginUpdatedListener {
    
    public abstract void onStatusBarMarginUpdated(int marginLeft, int marginRight);
}