package com.android.systemui.statusbar.phone;

import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.statusbar.policy.CallbackController;
import java.lang.ref.WeakReference;
import javax.inject.Inject;

/**
 * Publishes updates to the status bar's margins.
 *
 * While the status bar view consumes the entire width of the device, the status bar
 * contents are laid out with margins for rounded corners, padding from the absolute
 * edges, and potentially display cutouts in the corner.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010#\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0006\n\u0002\u0010\u0002\n\u0002\b\u0006\b\u0007\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u0001B\u0007\b\u0007\u00a2\u0006\u0002\u0010\u0003J\u0010\u0010\u000e\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0002H\u0016J\b\u0010\u0011\u001a\u00020\u000fH\u0002J\u0010\u0010\u0012\u001a\u00020\u000f2\u0006\u0010\u0010\u001a\u00020\u0002H\u0016J\u0016\u0010\u0013\u001a\u00020\u000f2\u0006\u0010\u0014\u001a\u00020\b2\u0006\u0010\u0015\u001a\u00020\bR\u001a\u0010\u0004\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00020\u00060\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001e\u0010\t\u001a\u00020\b2\u0006\u0010\u0007\u001a\u00020\b@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\u000bR\u001e\u0010\f\u001a\u00020\b2\u0006\u0010\u0007\u001a\u00020\b@BX\u0086\u000e\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000b"}, d2 = {"Lcom/android/systemui/statusbar/phone/StatusBarLocationPublisher;", "Lcom/android/systemui/statusbar/policy/CallbackController;", "Lcom/android/systemui/statusbar/phone/StatusBarMarginUpdatedListener;", "()V", "listeners", "", "Ljava/lang/ref/WeakReference;", "<set-?>", "", "marginLeft", "getMarginLeft", "()I", "marginRight", "getMarginRight", "addCallback", "", "listener", "notifyListeners", "removeCallback", "updateStatusBarMargin", "left", "right"})
@com.android.systemui.dagger.SysUISingleton()
public final class StatusBarLocationPublisher implements com.android.systemui.statusbar.policy.CallbackController<com.android.systemui.statusbar.phone.StatusBarMarginUpdatedListener> {
    private final java.util.Set<java.lang.ref.WeakReference<com.android.systemui.statusbar.phone.StatusBarMarginUpdatedListener>> listeners = null;
    private int marginLeft = 0;
    private int marginRight = 0;
    
    public final int getMarginLeft() {
        return 0;
    }
    
    public final int getMarginRight() {
        return 0;
    }
    
    @java.lang.Override()
    public void addCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarMarginUpdatedListener listener) {
    }
    
    @java.lang.Override()
    public void removeCallback(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusBarMarginUpdatedListener listener) {
    }
    
    public final void updateStatusBarMargin(int left, int right) {
    }
    
    private final void notifyListeners() {
    }
    
    @javax.inject.Inject()
    public StatusBarLocationPublisher() {
        super();
    }
}