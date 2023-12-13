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

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000\n\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\"\u000e\u0010\u0000\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0002\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0003\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000\"\u000e\u0010\u0004\u001a\u00020\u0001X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"CALL_OP_USAGE_KEY", "", "FIRST_OPENED_KEY", "MIC_MUTED_KEY", "USAGES_KEY"})
public final class ReviewOngoingUsageViewModelKt {
    private static final java.lang.String FIRST_OPENED_KEY = "FIRST_OPENED";
    private static final java.lang.String CALL_OP_USAGE_KEY = "CALL_OP_USAGE";
    private static final java.lang.String USAGES_KEY = "USAGES_KEY";
    private static final java.lang.String MIC_MUTED_KEY = "MIC_MUTED_KEY";
}