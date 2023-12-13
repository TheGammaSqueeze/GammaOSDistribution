package com.android.systemui.settings.brightness;

import com.android.systemui.statusbar.policy.BrightnessMirrorController;

/**
 * Indicates controller that has brightness slider and uses [BrightnessMirrorController]
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/settings/brightness/MirroredBrightnessController;", "", "setMirror", "", "controller", "Lcom/android/systemui/statusbar/policy/BrightnessMirrorController;"})
public abstract interface MirroredBrightnessController {
    
    public abstract void setMirror(@org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.BrightnessMirrorController controller);
}