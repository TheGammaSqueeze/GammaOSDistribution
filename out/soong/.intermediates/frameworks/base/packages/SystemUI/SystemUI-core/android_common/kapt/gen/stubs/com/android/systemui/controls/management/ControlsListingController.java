package com.android.systemui.controls.management;

import android.content.ComponentName;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.util.UserAwareController;
import com.android.systemui.statusbar.policy.CallbackController;

/**
 * Controller for keeping track of services that can be bound given a particular [ServiceListing].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000(\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\bf\u0018\u00002\b\u0012\u0004\u0012\u00020\u00020\u00012\u00020\u0003:\u0001\u000bJ\u0012\u0010\u0004\u001a\u0004\u0018\u00010\u00052\u0006\u0010\u0006\u001a\u00020\u0007H\u0016J\u000e\u0010\b\u001a\b\u0012\u0004\u0012\u00020\n0\tH&\u00f8\u0001\u0000\u0082\u0002\u0007\n\u0005\b\u0091(0\u0001"}, d2 = {"Lcom/android/systemui/controls/management/ControlsListingController;", "Lcom/android/systemui/statusbar/policy/CallbackController;", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "Lcom/android/systemui/util/UserAwareController;", "getAppLabel", "", "name", "Landroid/content/ComponentName;", "getCurrentServices", "", "Lcom/android/systemui/controls/ControlsServiceInfo;", "ControlsListingCallback"})
public abstract interface ControlsListingController extends com.android.systemui.statusbar.policy.CallbackController<com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback>, com.android.systemui.util.UserAwareController {
    
    /**
     * @return the current list of services that satisfies the [ServiceListing].
     */
    @org.jetbrains.annotations.NotNull()
    public abstract java.util.List<com.android.systemui.controls.ControlsServiceInfo> getCurrentServices();
    
    /**
     * Get the app label for a given component.
     *
     * This call may do Binder calls (to [PackageManager])
     *
     * @param name the component name to retrieve the label
     * @return the label for the component
     */
    @org.jetbrains.annotations.Nullable()
    public abstract java.lang.CharSequence getAppLabel(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName name);
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0018\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\bg\u0018\u00002\u00020\u0001J\u0016\u0010\u0002\u001a\u00020\u00032\f\u0010\u0004\u001a\b\u0012\u0004\u0012\u00020\u00060\u0005H&"}, d2 = {"Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "", "onServicesUpdated", "", "serviceInfos", "", "Lcom/android/systemui/controls/ControlsServiceInfo;"})
    @java.lang.FunctionalInterface()
    public static abstract interface ControlsListingCallback {
        
        public abstract void onServicesUpdated(@org.jetbrains.annotations.NotNull()
        java.util.List<com.android.systemui.controls.ControlsServiceInfo> serviceInfos);
    }
    
    /**
     * Controller for keeping track of services that can be bound given a particular [ServiceListing].
     */
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 3)
    public final class DefaultImpls {
        
        /**
         * Get the app label for a given component.
         *
         * This call may do Binder calls (to [PackageManager])
         *
         * @param name the component name to retrieve the label
         * @return the label for the component
         */
        @org.jetbrains.annotations.Nullable()
        public static java.lang.CharSequence getAppLabel(@org.jetbrains.annotations.NotNull()
        com.android.systemui.controls.management.ControlsListingController $this, @org.jetbrains.annotations.NotNull()
        android.content.ComponentName name) {
            return null;
        }
    }
}