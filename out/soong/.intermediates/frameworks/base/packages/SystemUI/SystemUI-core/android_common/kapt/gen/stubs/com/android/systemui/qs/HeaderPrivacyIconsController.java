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

/**
 * Controls privacy icons/chip residing in QS header which show up when app is using camera,
 * microphone or location.
 * Manages their visibility depending on privacy signals coming from [PrivacyItemController].
 *
 * Unlike typical controller extending [com.android.systemui.util.ViewController] this view doesn't
 * observe its attachment state because depending on where it is used, it might be never detached.
 * Instead, parent controller should use [onParentVisible] and [onParentInvisible] to "activate" or
 * "deactivate" this controller.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0010\u000b\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0010\u0002\n\u0002\b\u0006\u0018\u00002\u00020\u0001B?\b\u0007\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u0012\u0006\u0010\u000e\u001a\u00020\u000f\u00a2\u0006\u0002\u0010\u0010J\b\u0010#\u001a\u00020\u001bH\u0002J\u0006\u0010$\u001a\u00020%J\u0006\u0010&\u001a\u00020%J\u0010\u0010\'\u001a\u00020%2\u0006\u0010(\u001a\u00020\u001bH\u0002J\u0006\u0010)\u001a\u00020%J\u0006\u0010*\u001a\u00020%J\b\u0010+\u001a\u00020%H\u0002R\u0016\u0010\u0011\u001a\n \u0013*\u0004\u0018\u00010\u00120\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010\u0014\u001a\u0004\u0018\u00010\u0015X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0016\u0010\u0017\"\u0004\b\u0018\u0010\u0019R\u000e\u0010\u000e\u001a\u00020\u000fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001a\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001c\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001d\u001a\n \u0013*\u0004\u0018\u00010\u00120\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u001e\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0016\u0010\u001f\u001a\n \u0013*\u0004\u0018\u00010\u00120\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010 \u001a\u00020!X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\"\u001a\u00020\u001bX\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/HeaderPrivacyIconsController;", "", "privacyItemController", "Lcom/android/systemui/privacy/PrivacyItemController;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "privacyChip", "Lcom/android/systemui/privacy/OngoingPrivacyChip;", "privacyDialogController", "Lcom/android/systemui/privacy/PrivacyDialogController;", "privacyLogger", "Lcom/android/systemui/privacy/logging/PrivacyLogger;", "iconContainer", "Lcom/android/systemui/statusbar/phone/StatusIconContainer;", "deviceProvisionedController", "Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;", "(Lcom/android/systemui/privacy/PrivacyItemController;Lcom/android/internal/logging/UiEventLogger;Lcom/android/systemui/privacy/OngoingPrivacyChip;Lcom/android/systemui/privacy/PrivacyDialogController;Lcom/android/systemui/privacy/logging/PrivacyLogger;Lcom/android/systemui/statusbar/phone/StatusIconContainer;Lcom/android/systemui/statusbar/policy/DeviceProvisionedController;)V", "cameraSlot", "", "kotlin.jvm.PlatformType", "chipVisibilityListener", "Lcom/android/systemui/qs/ChipVisibilityListener;", "getChipVisibilityListener", "()Lcom/android/systemui/qs/ChipVisibilityListener;", "setChipVisibilityListener", "(Lcom/android/systemui/qs/ChipVisibilityListener;)V", "listening", "", "locationIndicatorsEnabled", "locationSlot", "micCameraIndicatorsEnabled", "micSlot", "picCallback", "Lcom/android/systemui/privacy/PrivacyItemController$Callback;", "privacyChipLogged", "getChipEnabled", "onParentInvisible", "", "onParentVisible", "setChipVisibility", "visible", "startListening", "stopListening", "updatePrivacyIconSlots"})
public final class HeaderPrivacyIconsController {
    @org.jetbrains.annotations.Nullable()
    private com.android.systemui.qs.ChipVisibilityListener chipVisibilityListener;
    private boolean listening = false;
    private boolean micCameraIndicatorsEnabled = false;
    private boolean locationIndicatorsEnabled = false;
    private boolean privacyChipLogged = false;
    private final java.lang.String cameraSlot = null;
    private final java.lang.String micSlot = null;
    private final java.lang.String locationSlot = null;
    private final com.android.systemui.privacy.PrivacyItemController.Callback picCallback = null;
    private final com.android.systemui.privacy.PrivacyItemController privacyItemController = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final com.android.systemui.privacy.OngoingPrivacyChip privacyChip = null;
    private final com.android.systemui.privacy.PrivacyDialogController privacyDialogController = null;
    private final com.android.systemui.privacy.logging.PrivacyLogger privacyLogger = null;
    private final com.android.systemui.statusbar.phone.StatusIconContainer iconContainer = null;
    private final com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController = null;
    
    @org.jetbrains.annotations.Nullable()
    public final com.android.systemui.qs.ChipVisibilityListener getChipVisibilityListener() {
        return null;
    }
    
    public final void setChipVisibilityListener(@org.jetbrains.annotations.Nullable()
    com.android.systemui.qs.ChipVisibilityListener p0) {
    }
    
    private final boolean getChipEnabled() {
        return false;
    }
    
    public final void onParentVisible() {
    }
    
    public final void onParentInvisible() {
    }
    
    public final void startListening() {
    }
    
    public final void stopListening() {
    }
    
    private final void setChipVisibility(boolean visible) {
    }
    
    private final void updatePrivacyIconSlots() {
    }
    
    @javax.inject.Inject()
    public HeaderPrivacyIconsController(@org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyItemController privacyItemController, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.OngoingPrivacyChip privacyChip, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.PrivacyDialogController privacyDialogController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.privacy.logging.PrivacyLogger privacyLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.phone.StatusIconContainer iconContainer, @org.jetbrains.annotations.NotNull()
    com.android.systemui.statusbar.policy.DeviceProvisionedController deviceProvisionedController) {
        super();
    }
}