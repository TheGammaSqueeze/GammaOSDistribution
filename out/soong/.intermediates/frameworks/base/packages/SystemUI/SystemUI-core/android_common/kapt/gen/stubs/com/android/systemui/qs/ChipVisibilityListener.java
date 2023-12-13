package com.android.systemui.qs;

import android.view.View;
import com.android.internal.R;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.privacy.OngoingPrivacyChip;
import com.android.systemui.privacy.PrivacyChipEvent;
import com.android.systemui.privacy.PrivacyDialogController;
import com.android.systemui.privacy.PrivacyItem;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.statusbar.phone.StatusIconContainer;
import javax.inject.Inject;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/qs/ChipVisibilityListener;", "", "onChipVisibilityRefreshed", "", "visible", ""})
public abstract interface ChipVisibilityListener {
    
    public abstract void onChipVisibilityRefreshed(boolean visible);
}