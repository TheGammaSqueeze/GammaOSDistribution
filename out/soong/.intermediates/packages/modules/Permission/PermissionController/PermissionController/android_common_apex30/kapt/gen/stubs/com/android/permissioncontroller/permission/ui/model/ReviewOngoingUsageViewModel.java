package com.android.permissioncontroller.permission.ui.model;

import android.Manifest;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.media.AudioManager;
import android.os.Bundle;
import android.os.UserHandle;
import android.provider.Settings;
import android.speech.RecognitionService;
import android.speech.RecognizerIntent;
import android.telephony.TelephonyManager;
import android.view.inputmethod.InputMethodManager;
import androidx.lifecycle.AbstractSavedStateViewModelFactory;
import androidx.lifecycle.SavedStateHandle;
import androidx.lifecycle.ViewModel;
import androidx.savedstate.SavedStateRegistryOwner;
import com.android.permissioncontroller.PermissionControllerApplication;
import com.android.permissioncontroller.permission.data.AttributionLabelLiveData;
import com.android.permissioncontroller.permission.data.LoadAndFreezeLifeData;
import com.android.permissioncontroller.permission.data.OpAccess;
import com.android.permissioncontroller.permission.data.OpUsageLiveData;
import com.android.permissioncontroller.permission.data.PermGroupUsageLiveData;
import com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData;
import com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData;
import com.android.permissioncontroller.permission.utils.KotlinUtils;
import com.android.permissioncontroller.permission.utils.Utils;
import java.time.Instant;

/**
 * ViewModel for {@link ReviewOngoingUsageFragment}
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000^\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0000\n\u0002\u0010\u001e\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0006\u0018\u00002\u00020\u0001:\u0002!\"B\u0015\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u00a2\u0006\u0002\u0010\u0006J\u0010\u0010\u001f\u001a\u00020\f2\u0006\u0010 \u001a\u00020\u0015H\u0002R\u000e\u0010\u0007\u001a\u00020\bX\u0082D\u00a2\u0006\u0002\n\u0000R&\u0010\t\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\f\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\r0\u000b0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\u000e\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\b0\u000f0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0010\u001a\b\u0012\u0004\u0012\u00020\u00120\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R&\u0010\u0013\u001a\u001a\u0012\u0016\u0012\u0014\u0012\u0004\u0012\u00020\b\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00150\u00140\u000b0\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0016\u001a\u0014\u0012\u0010\u0012\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00150\u00140\r0\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0017\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R \u0010\u0018\u001a\u0014\u0012\u0010\u0012\u000e\u0012\u0004\u0012\u00020\f\u0012\u0004\u0012\u00020\u001a0\u000b0\u0019X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0017\u0010\u001b\u001a\b\u0012\u0004\u0012\u00020\u001c0\u0019\u00a2\u0006\b\n\u0000\u001a\u0004\b\u001d\u0010\u001e"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModel;", "Landroidx/lifecycle/ViewModel;", "state", "Landroidx/lifecycle/SavedStateHandle;", "extraDurationMills", "", "(Landroidx/lifecycle/SavedStateHandle;J)V", "SYSTEM_PKG", "", "appUsagesLiveData", "Lcom/android/permissioncontroller/permission/data/SmartUpdateMediatorLiveData;", "", "Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModel$PackageAttribution;", "", "callOpUsageLiveData", "", "isMicMuted", "Lcom/android/permissioncontroller/permission/data/LoadAndFreezeLifeData;", "", "permGroupUsages", "", "Lcom/android/permissioncontroller/permission/data/OpAccess;", "proxyChainsLiveData", "startTime", "trustedAttrsLiveData", "Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "", "usages", "Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModel$Usages;", "getUsages", "()Lcom/android/permissioncontroller/permission/data/SmartAsyncMediatorLiveData;", "getPackageAttr", "usage", "PackageAttribution", "Usages"})
public final class ReviewOngoingUsageViewModel extends androidx.lifecycle.ViewModel {
    
    /**
     * Time of oldest usages considered
     */
    private final long startTime = 0L;
    private final java.lang.String SYSTEM_PKG = "android";
    
    /**
     * Base permission usage that will filtered by SystemPermGroupUsages and
     * UserSensitivePermGroupUsages.
     *
     * <p>Note: This does not use a cached live-data to avoid getting stale data
     */
    private final com.android.permissioncontroller.permission.data.LoadAndFreezeLifeData<java.util.Map<java.lang.String, java.util.List<com.android.permissioncontroller.permission.data.OpAccess>>> permGroupUsages = null;
    
    /**
     * Whether the mic is muted
     */
    private final com.android.permissioncontroller.permission.data.LoadAndFreezeLifeData<java.lang.Boolean> isMicMuted = null;
    
    /**
     * App runtime permission usages
     */
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.Set<java.lang.String>>> appUsagesLiveData = null;
    
    /**
     * Gets all trusted proxied voice IME and voice recognition microphone uses, and get the
     * label needed to display with it, as well as information about the proxy whose label is being
     * shown, if applicable.
     */
    private final com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.lang.CharSequence>> trustedAttrsLiveData = null;
    
    /**
     * Get all chains of proxy usages. A proxy chain is defined as one usage at the root, then
     * further proxy usages, where the app and attribution tag of the proxy matches the previous
     * usage in the chain.
     */
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Set<java.util.List<com.android.permissioncontroller.permission.data.OpAccess>>> proxyChainsLiveData = null;
    
    /**
     * Phone call usages
     */
    private final com.android.permissioncontroller.permission.data.SmartUpdateMediatorLiveData<java.util.Collection<java.lang.String>> callOpUsageLiveData = null;
    
    /**
     * App, system, and call usages in a single, nice, handy package
     */
    @org.jetbrains.annotations.NotNull()
    private final com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.Usages> usages = null;
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.data.SmartAsyncMediatorLiveData<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.Usages> getUsages() {
        return null;
    }
    
    private final com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution getPackageAttr(com.android.permissioncontroller.permission.data.OpAccess usage) {
        return null;
    }
    
    public ReviewOngoingUsageViewModel(@org.jetbrains.annotations.NotNull()
    androidx.lifecycle.SavedStateHandle state, long extraDurationMills) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000<\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010 \n\u0002\u0010\r\n\u0002\b\u000b\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\b\u0086\b\u0018\u00002\u00020\u0001BI\u0012\u0018\u0010\u0002\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u0003\u0012\f\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\b\u0012\u001a\b\u0002\u0010\t\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\u0003\u00a2\u0006\u0002\u0010\fJ\u001b\u0010\u0012\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u0003H\u00c6\u0003J\u000f\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00060\bH\u00c6\u0003J\u001b\u0010\u0014\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\u0003H\u00c6\u0003JQ\u0010\u0015\u001a\u00020\u00002\u001a\b\u0002\u0010\u0002\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u00032\u000e\b\u0002\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\b2\u001a\b\u0002\u0010\t\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\u0003H\u00c6\u0001J\u0013\u0010\u0016\u001a\u00020\u00172\b\u0010\u0018\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0019\u001a\u00020\u001aH\u00d6\u0001J\t\u0010\u001b\u001a\u00020\u0006H\u00d6\u0001R#\u0010\u0002\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00060\u00050\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\r\u0010\u000eR\u0017\u0010\u0007\u001a\b\u0012\u0004\u0012\u00020\u00060\b\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000f\u0010\u0010R#\u0010\t\u001a\u0014\u0012\u0004\u0012\u00020\u0004\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u000b0\n0\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\u0011\u0010\u000e"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModel$Usages;", "", "appUsages", "", "Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModel$PackageAttribution;", "", "", "callUsages", "", "shownAttributions", "", "", "(Ljava/util/Map;Ljava/util/Collection;Ljava/util/Map;)V", "getAppUsages", "()Ljava/util/Map;", "getCallUsages", "()Ljava/util/Collection;", "getShownAttributions", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "", "toString"})
    public static final class Usages {
        
        /**
         * attribution-res-id/packageName/user -> perm groups accessed
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.Set<java.lang.String>> appUsages = null;
        
        /**
         * Op-names of phone call accesses
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.Collection<java.lang.String> callUsages = null;
        
        /**
         * A map of attribution, packageName and user -> list of attribution labels to show with
         * microphone
         */
        @org.jetbrains.annotations.NotNull()
        private final java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.List<java.lang.CharSequence>> shownAttributions = null;
        
        /**
         * attribution-res-id/packageName/user -> perm groups accessed
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.Set<java.lang.String>> getAppUsages() {
            return null;
        }
        
        /**
         * Op-names of phone call accesses
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Collection<java.lang.String> getCallUsages() {
            return null;
        }
        
        /**
         * A map of attribution, packageName and user -> list of attribution labels to show with
         * microphone
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.List<java.lang.CharSequence>> getShownAttributions() {
            return null;
        }
        
        public Usages(@org.jetbrains.annotations.NotNull()
        java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, ? extends java.util.Set<java.lang.String>> appUsages, @org.jetbrains.annotations.NotNull()
        java.util.Collection<java.lang.String> callUsages, @org.jetbrains.annotations.NotNull()
        java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, ? extends java.util.List<? extends java.lang.CharSequence>> shownAttributions) {
            super();
        }
        
        /**
         * attribution-res-id/packageName/user -> perm groups accessed
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.Set<java.lang.String>> component1() {
            return null;
        }
        
        /**
         * Op-names of phone call accesses
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Collection<java.lang.String> component2() {
            return null;
        }
        
        /**
         * A map of attribution, packageName and user -> list of attribution labels to show with
         * microphone
         */
        @org.jetbrains.annotations.NotNull()
        public final java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, java.util.List<java.lang.CharSequence>> component3() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.Usages copy(@org.jetbrains.annotations.NotNull()
        java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, ? extends java.util.Set<java.lang.String>> appUsages, @org.jetbrains.annotations.NotNull()
        java.util.Collection<java.lang.String> callUsages, @org.jetbrains.annotations.NotNull()
        java.util.Map<com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution, ? extends java.util.List<? extends java.lang.CharSequence>> shownAttributions) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000*\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u000b\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\b\u0086\b\u0018\u00002\u00020\u0001B\u001f\u0012\b\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\u000b\u0010\r\u001a\u0004\u0018\u00010\u0003H\u00c6\u0003J\t\u0010\u000e\u001a\u00020\u0003H\u00c6\u0003J\t\u0010\u000f\u001a\u00020\u0006H\u00c6\u0003J)\u0010\u0010\u001a\u00020\u00002\n\b\u0002\u0010\u0002\u001a\u0004\u0018\u00010\u00032\b\b\u0002\u0010\u0004\u001a\u00020\u00032\b\b\u0002\u0010\u0005\u001a\u00020\u0006H\u00c6\u0001J\u0013\u0010\u0011\u001a\u00020\u00122\b\u0010\u0013\u001a\u0004\u0018\u00010\u0001H\u00d6\u0003J\t\u0010\u0014\u001a\u00020\u0015H\u00d6\u0001J\u000e\u0010\u0016\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0000J\t\u0010\u0017\u001a\u00020\u0003H\u00d6\u0001R\u0013\u0010\u0002\u001a\u0004\u0018\u00010\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\b\u0010\tR\u0011\u0010\u0004\u001a\u00020\u0003\u00a2\u0006\b\n\u0000\u001a\u0004\b\n\u0010\tR\u0011\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000b\u0010\f"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModel$PackageAttribution;", "", "attributionTag", "", "packageName", "user", "Landroid/os/UserHandle;", "(Ljava/lang/String;Ljava/lang/String;Landroid/os/UserHandle;)V", "getAttributionTag", "()Ljava/lang/String;", "getPackageName", "getUser", "()Landroid/os/UserHandle;", "component1", "component2", "component3", "copy", "equals", "", "other", "hashCode", "", "pkgEq", "toString"})
    public static final class PackageAttribution {
        @org.jetbrains.annotations.Nullable()
        private final java.lang.String attributionTag = null;
        @org.jetbrains.annotations.NotNull()
        private final java.lang.String packageName = null;
        @org.jetbrains.annotations.NotNull()
        private final android.os.UserHandle user = null;
        
        public final boolean pkgEq(@org.jetbrains.annotations.NotNull()
        com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution other) {
            return false;
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String getAttributionTag() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String getPackageName() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.os.UserHandle getUser() {
            return null;
        }
        
        public PackageAttribution(@org.jetbrains.annotations.Nullable()
        java.lang.String attributionTag, @org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user) {
            super();
        }
        
        @org.jetbrains.annotations.Nullable()
        public final java.lang.String component1() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final java.lang.String component2() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final android.os.UserHandle component3() {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        public final com.android.permissioncontroller.permission.ui.model.ReviewOngoingUsageViewModel.PackageAttribution copy(@org.jetbrains.annotations.Nullable()
        java.lang.String attributionTag, @org.jetbrains.annotations.NotNull()
        java.lang.String packageName, @org.jetbrains.annotations.NotNull()
        android.os.UserHandle user) {
            return null;
        }
        
        @org.jetbrains.annotations.NotNull()
        @java.lang.Override()
        public java.lang.String toString() {
            return null;
        }
        
        @java.lang.Override()
        public int hashCode() {
            return 0;
        }
        
        @java.lang.Override()
        public boolean equals(@org.jetbrains.annotations.Nullable()
        java.lang.Object p0) {
            return false;
        }
    }
}