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
 * Factory for a ReviewOngoingUsageViewModel
 *
 * @param extraDurationMillis The number of milliseconds old usages are considered for
 * @param owner The owner of this saved state
 * @param defaultArgs The default args to pass
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\t\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000e\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\u0018\u00002\u00020\u0001B\u001d\u0012\u0006\u0010\u0002\u001a\u00020\u0003\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u00a2\u0006\u0002\u0010\bJ7\u0010\t\u001a\u0002H\n\"\n\b\u0000\u0010\n*\u0004\u0018\u00010\u000b2\u0006\u0010\f\u001a\u00020\r2\f\u0010\u000e\u001a\b\u0012\u0004\u0012\u0002H\n0\u000f2\u0006\u0010\u0010\u001a\u00020\u0011H\u0014\u00a2\u0006\u0002\u0010\u0012R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/ui/model/ReviewOngoingUsageViewModelFactory;", "Landroidx/lifecycle/AbstractSavedStateViewModelFactory;", "extraDurationMillis", "", "owner", "Landroidx/savedstate/SavedStateRegistryOwner;", "defaultArgs", "Landroid/os/Bundle;", "(JLandroidx/savedstate/SavedStateRegistryOwner;Landroid/os/Bundle;)V", "create", "T", "Landroidx/lifecycle/ViewModel;", "p0", "", "p1", "Ljava/lang/Class;", "state", "Landroidx/lifecycle/SavedStateHandle;", "(Ljava/lang/String;Ljava/lang/Class;Landroidx/lifecycle/SavedStateHandle;)Landroidx/lifecycle/ViewModel;"})
public final class ReviewOngoingUsageViewModelFactory extends androidx.lifecycle.AbstractSavedStateViewModelFactory {
    private final long extraDurationMillis = 0L;
    
    @java.lang.Override()
    protected <T extends androidx.lifecycle.ViewModel>T create(@org.jetbrains.annotations.NotNull()
    java.lang.String p0, @org.jetbrains.annotations.NotNull()
    java.lang.Class<T> p1, @org.jetbrains.annotations.NotNull()
    androidx.lifecycle.SavedStateHandle state) {
        return null;
    }
    
    public ReviewOngoingUsageViewModelFactory(long extraDurationMillis, @org.jetbrains.annotations.NotNull()
    androidx.savedstate.SavedStateRegistryOwner owner, @org.jetbrains.annotations.NotNull()
    android.os.Bundle defaultArgs) {
        super(null, null);
    }
}