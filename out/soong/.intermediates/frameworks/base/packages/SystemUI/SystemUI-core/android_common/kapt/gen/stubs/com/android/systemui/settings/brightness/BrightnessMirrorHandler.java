package com.android.systemui.settings.brightness;

import com.android.systemui.statusbar.policy.BrightnessMirrorController;
import com.android.systemui.statusbar.policy.BrightnessMirrorController.BrightnessMirrorListener;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000&\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\u0004\u0018\u00002\u00020\u0001B\r\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u00a2\u0006\u0002\u0010\u0004J\u0006\u0010\t\u001a\u00020\nJ\u0006\u0010\u000b\u001a\u00020\nJ\u000e\u0010\f\u001a\u00020\n2\u0006\u0010\r\u001a\u00020\bJ\b\u0010\u000e\u001a\u00020\nH\u0002R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0007\u001a\u0004\u0018\u00010\bX\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/settings/brightness/BrightnessMirrorHandler;", "", "brightnessController", "Lcom/android/systemui/settings/brightness/MirroredBrightnessController;", "(Lcom/android/systemui/settings/brightness/MirroredBrightnessController;)V", "brightnessMirrorListener", "Lcom/android/systemui/statusbar/policy/BrightnessMirrorController$BrightnessMirrorListener;", "mirrorController", "Lcom/android/systemui/statusbar/policy/BrightnessMirrorController;", "onQsPanelAttached", "", "onQsPanelDettached", "setController", "controller", "updateBrightnessMirror"})
public final class BrightnessMirrorHandler {
    private com.android.systemui.statusbar.policy.BrightnessMirrorController mirrorController;
    private final com.android.systemui.statusbar.policy.BrightnessMirrorController.BrightnessMirrorListener brightnessMirrorListener = null;
    private final com.android.systemui.settings.brightness.MirroredBrightnessController brightnessController = null;
    
    public final void onQsPanelAttached() {
    }
    
    public final void onQsPanelDettached() {
    }
    
    public final void setController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.BrightnessMirrorController controller) {
    }
    
    private final void updateBrightnessMirror() {
    }
    
    public BrightnessMirrorHandler(@org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.brightness.MirroredBrightnessController brightnessController) {
        super();
    }
}