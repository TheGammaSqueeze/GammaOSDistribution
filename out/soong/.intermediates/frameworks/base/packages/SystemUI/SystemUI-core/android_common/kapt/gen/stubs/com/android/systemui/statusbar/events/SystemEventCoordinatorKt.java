package com.android.systemui.statusbar.events;

import android.content.Context;
import android.provider.DeviceConfig;
import com.android.systemui.R;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.privacy.PrivacyChipBuilder;
import com.android.systemui.privacy.PrivacyItem;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.util.time.SystemClock;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\u000e\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\t\n\u0000\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0003X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"CHIP_ANIMATION_ENABLED", "", "DEBOUNCE_TIME", "", "TAG"})
public final class SystemEventCoordinatorKt {
    private static final long DEBOUNCE_TIME = 3000L;
    private static final java.lang.String CHIP_ANIMATION_ENABLED = "privacy_chip_animation_enabled";
    private static final java.lang.String TAG = "SystemEventCoordinator";
}