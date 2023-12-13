package com.android.systemui.qs.customize;

import android.content.Context;
import android.text.TextUtils;
import com.android.systemui.plugins.qs.QSIconView;
import com.android.systemui.plugins.qs.QSTile;
import com.android.systemui.qs.tileimpl.QSTileViewImpl;

/**
 * Class for displaying tiles in [QSCustomizer] with the new design (labels on the side).
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000:\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000b\n\u0002\b\n\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0010\r\n\u0002\b\u0002\u0018\u00002\u00020\u0001B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\b\u0010\u0011\u001a\u00020\bH\u0014J\u000e\u0010\u0012\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0015J\u0012\u0010\u0016\u001a\u00020\u00172\b\u0010\u0018\u001a\u0004\u0018\u00010\u0019H\u0002J\u0010\u0010\u001a\u001a\u00020\u00132\u0006\u0010\u0014\u001a\u00020\u0015H\u0014J\b\u0010\u001b\u001a\u00020\bH\u0016R$\u0010\t\u001a\u00020\b2\u0006\u0010\u0007\u001a\u00020\b@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\n\u0010\u000b\"\u0004\b\f\u0010\rR$\u0010\u000e\u001a\u00020\b2\u0006\u0010\u0007\u001a\u00020\b@FX\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u000f\u0010\u000b\"\u0004\b\u0010\u0010\r"}, d2 = {"Lcom/android/systemui/qs/customize/CustomizeTileView;", "Lcom/android/systemui/qs/tileimpl/QSTileViewImpl;", "context", "Landroid/content/Context;", "icon", "Lcom/android/systemui/plugins/qs/QSIconView;", "(Landroid/content/Context;Lcom/android/systemui/plugins/qs/QSIconView;)V", "value", "", "showAppLabel", "getShowAppLabel", "()Z", "setShowAppLabel", "(Z)V", "showSideView", "getShowSideView", "setShowSideView", "animationsEnabled", "changeState", "", "state", "Lcom/android/systemui/plugins/qs/QSTile$State;", "getVisibilityState", "", "text", "", "handleStateChanged", "isLongClickable"})
public final class CustomizeTileView extends com.android.systemui.qs.tileimpl.QSTileViewImpl {
    private boolean showAppLabel = false;
    private boolean showSideView = true;
    
    public final boolean getShowAppLabel() {
        return false;
    }
    
    public final void setShowAppLabel(boolean value) {
    }
    
    public final boolean getShowSideView() {
        return false;
    }
    
    public final void setShowSideView(boolean value) {
    }
    
    @java.lang.Override()
    protected void handleStateChanged(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state) {
    }
    
    private final int getVisibilityState(java.lang.CharSequence text) {
        return 0;
    }
    
    @java.lang.Override()
    protected boolean animationsEnabled() {
        return false;
    }
    
    @java.lang.Override()
    public boolean isLongClickable() {
        return false;
    }
    
    public final void changeState(@org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSTile.State state) {
    }
    
    public CustomizeTileView(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.qs.QSIconView icon) {
        super(null, null, false);
    }
}