package com.android.permissioncontroller.permission.utils;

import android.Manifest;
import android.app.ActivityManager;
import android.app.AppOpsManager;
import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.PermissionGroupInfo;
import android.content.pm.PermissionInfo;
import android.graphics.drawable.Drawable;
import android.os.Build;
import android.os.Bundle;
import android.os.UserHandle;
import android.permission.PermissionManager;
import android.text.TextUtils;
import androidx.lifecycle.LiveData;
import androidx.lifecycle.Observer;
import androidx.navigation.NavController;
import androidx.preference.Preference;
import androidx.preference.PreferenceGroup;
import com.android.permissioncontroller.R;
import com.android.permissioncontroller.permission.data.LightPackageInfoLiveData;
import com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo;
import com.android.permissioncontroller.permission.model.livedatatypes.LightPermission;
import com.android.permissioncontroller.permission.model.livedatatypes.PermState;
import com.android.permissioncontroller.permission.service.LocationAccessCheck;
import com.android.permissioncontroller.permission.ui.handheld.SettingsWithLargeHeader;
import kotlinx.coroutines.Dispatchers;
import kotlinx.coroutines.GlobalScope;
import java.util.concurrent.atomic.AtomicReference;
import kotlin.coroutines.CoroutineContext;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 2, d1 = {"\u0000b\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u001c\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0000\n\u0002\u0018\u0002\u001ad\u0010\u0000\u001a\u00020\u0001\"\u0004\b\u0000\u0010\u0002*\b\u0012\u0004\u0012\u0002H\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072/\b\u0004\u0010\b\u001a)\b\u0001\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u0002H\u0002\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00010\n\u0012\u0006\u0012\u0004\u0018\u00010\u000b0\t\u00a2\u0006\u0002\b\fH\u0086H\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\r\u001am\u0010\u000e\u001a\u0002H\u0002\"\u0004\b\u0000\u0010\u0002\"\u000e\b\u0001\u0010\u000f*\b\u0012\u0004\u0012\u0002H\u00020\u0010*\u0002H\u000f2%\b\u0002\u0010\u0011\u001a\u001f\u0012\u0004\u0012\u0002H\u000f\u0012\n\u0012\b\u0012\u0004\u0012\u0002H\u00020\u0013\u0012\u0004\u0012\u00020\u00010\u0012\u00a2\u0006\u0002\b\f2\u0019\b\u0002\u0010\u0014\u001a\u0013\u0012\u0004\u0012\u0002H\u000f\u0012\u0004\u0012\u00020\u00160\u0015\u00a2\u0006\u0002\b\fH\u0086@\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\u0017\u001ap\u0010\u0018\u001a\b\u0012\u0004\u0012\u0002H\u001a0\u0019\"\u0004\b\u0000\u0010\u0002\"\u0004\b\u0001\u0010\u001a*\b\u0012\u0004\u0012\u0002H\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u00052\b\b\u0002\u0010\u0006\u001a\u00020\u00072/\b\u0004\u0010\u001b\u001a)\b\u0001\u0012\u0004\u0012\u00020\u0007\u0012\u0004\u0012\u0002H\u0002\u0012\n\u0012\b\u0012\u0004\u0012\u0002H\u001a0\n\u0012\u0006\u0012\u0004\u0018\u00010\u000b0\t\u00a2\u0006\u0002\b\fH\u0086H\u00f8\u0001\u0000\u00a2\u0006\u0002\u0010\r\u001a\u001e\u0010\u001c\u001a\u00020\u0001*\u00020\u001d2\u0006\u0010\u001e\u001a\u00020\u001f2\n\b\u0002\u0010 \u001a\u0004\u0018\u00010!\u0082\u0002\u0004\n\u0002\b\u0019"}, d2 = {"forEachInParallel", "", "T", "", "context", "Lkotlin/coroutines/CoroutineContext;", "scope", "Lkotlinx/coroutines/CoroutineScope;", "action", "Lkotlin/Function3;", "Lkotlin/coroutines/Continuation;", "", "Lkotlin/ExtensionFunctionType;", "(Ljava/lang/Iterable;Lkotlin/coroutines/CoroutineContext;Lkotlinx/coroutines/CoroutineScope;Lkotlin/jvm/functions/Function3;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "getInitializedValue", "LD", "Landroidx/lifecycle/LiveData;", "observe", "Lkotlin/Function2;", "Landroidx/lifecycle/Observer;", "isInitialized", "Lkotlin/Function1;", "", "(Landroidx/lifecycle/LiveData;Lkotlin/jvm/functions/Function2;Lkotlin/jvm/functions/Function1;Lkotlin/coroutines/Continuation;)Ljava/lang/Object;", "mapInParallel", "", "R", "transform", "navigateSafe", "Landroidx/navigation/NavController;", "destResId", "", "args", "Landroid/os/Bundle;"})
public final class KotlinUtilsKt {
    
    /**
     * Get the [value][LiveData.getValue], suspending until [isInitialized] if not yet so
     */
    @org.jetbrains.annotations.Nullable()
    public static final <T extends java.lang.Object, LD extends androidx.lifecycle.LiveData<T>>java.lang.Object getInitializedValue(@org.jetbrains.annotations.NotNull()
    LD $this$getInitializedValue, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super LD, ? super androidx.lifecycle.Observer<T>, kotlin.Unit> observe, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super LD, java.lang.Boolean> isInitialized, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super T> p3) {
        return null;
    }
    
    /**
     * A parallel equivalent of [map]
     *
     * Starts the given suspending function for each item in the collection without waiting for
     * previous ones to complete, then suspends until all the started operations finish.
     */
    @org.jetbrains.annotations.Nullable()
    public static final <T extends java.lang.Object, R extends java.lang.Object>java.lang.Object mapInParallel(@org.jetbrains.annotations.NotNull()
    java.lang.Iterable<? extends T> $this$mapInParallel, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.CoroutineContext context, @org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.CoroutineScope scope, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function3<? super kotlinx.coroutines.CoroutineScope, ? super T, ? super kotlin.coroutines.Continuation<? super R>, ? extends java.lang.Object> transform, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super java.util.List<? extends R>> p4) {
        return null;
    }
    
    /**
     * A parallel equivalent of [forEach]
     *
     * See [mapInParallel]
     */
    @org.jetbrains.annotations.Nullable()
    public static final <T extends java.lang.Object>java.lang.Object forEachInParallel(@org.jetbrains.annotations.NotNull()
    java.lang.Iterable<? extends T> $this$forEachInParallel, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.CoroutineContext context, @org.jetbrains.annotations.NotNull()
    kotlinx.coroutines.CoroutineScope scope, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function3<? super kotlinx.coroutines.CoroutineScope, ? super T, ? super kotlin.coroutines.Continuation<? super kotlin.Unit>, ? extends java.lang.Object> action, @org.jetbrains.annotations.NotNull()
    kotlin.coroutines.Continuation<? super kotlin.Unit> p4) {
        return null;
    }
    
    /**
     * Check that we haven't already started transitioning to a given destination. If we haven't,
     * start navigating to that destination.
     *
     * @param destResId The ID of the desired destination
     * @param args The optional bundle of args to be passed to the destination
     */
    public static final void navigateSafe(@org.jetbrains.annotations.NotNull()
    androidx.navigation.NavController $this$navigateSafe, int destResId, @org.jetbrains.annotations.Nullable()
    android.os.Bundle args) {
    }
}