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

/**
 * A set of util functions designed to work with kotlin, though they can work with java, as well.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u00a6\u0001\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0010\u000b\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0010\"\n\u0002\b\u0002\n\u0002\u0010\u001e\n\u0000\n\u0002\u0010$\n\u0002\b\u0004\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0010 \n\u0002\b\u0011\n\u0002\u0010\u0002\n\u0002\b\u0003\n\u0002\u0010\u0011\n\u0002\b\u0006\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\b\u00c6\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J \u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J$\u0010\u0011\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u0012\u001a\u00020\u00132\n\b\u0002\u0010\u000f\u001a\u0004\u0018\u00010\u0010H\u0002J \u0010\u0014\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J\"\u0010\u0015\u001a\u0004\u0018\u00010\u00162\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u0017\u001a\u00020\u00042\u0006\u0010\u0018\u001a\u00020\u0019H\u0007JD\u0010\u001a\u001a\u001a\u0012\n\u0012\b\u0012\u0004\u0012\u0002H\u001d0\u001c\u0012\n\u0012\b\u0012\u0004\u0012\u0002H\u001d0\u001c0\u001b\"\u0004\b\u0000\u0010\u001d2\f\u0010\u001e\u001a\b\u0012\u0004\u0012\u0002H\u001d0\u001f2\u0010\u0010 \u001a\f\u0012\u0004\u0012\u0002H\u001d\u0012\u0002\b\u00030!J\u001e\u0010\"\u001a\u00020\u00042\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u0017\u001a\u00020\u00042\u0006\u0010\u0018\u001a\u00020\u0019J%\u0010#\u001a\u0004\u0018\u00010\u00062\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u0017\u001a\u00020\u00042\u0006\u0010\u0018\u001a\u00020\u0019\u00a2\u0006\u0002\u0010$J\u0016\u0010%\u001a\u00020&2\u0006\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020\u0004J\u0018\u0010*\u001a\u0004\u0018\u00010\u00162\u0006\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020\u0004J\u0016\u0010+\u001a\u00020&2\u0006\u0010\'\u001a\u00020(2\u0006\u0010)\u001a\u00020\u0004J\u0016\u0010,\u001a\u00020&2\u0006\u0010\'\u001a\u00020(2\u0006\u0010-\u001a\u00020\u0004J\u0018\u0010.\u001a\u0004\u0018\u00010\u00162\u0006\u0010\'\u001a\u00020(2\u0006\u0010-\u001a\u00020\u0004J\u0016\u0010/\u001a\u00020&2\u0006\u0010\'\u001a\u00020(2\u0006\u0010-\u001a\u00020\u0004J(\u00100\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\u000e\b\u0002\u00101\u001a\b\u0012\u0004\u0012\u00020\u000402H\u0007J2\u00103\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\u000e\b\u0002\u00101\u001a\b\u0012\u0004\u0012\u00020\u0004022\b\b\u0002\u00104\u001a\u00020\nH\u0007J4\u00105\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\n0\u001b2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u00104\u001a\u00020\n2\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J:\u00106\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u00107\u001a\u00020\n2\b\b\u0002\u00104\u001a\u00020\n2\u000e\b\u0002\u00101\u001a\b\u0012\u0004\u0012\u00020\u000402H\u0002J \u00108\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010-\u001a\u00020\u00042\u0006\u00109\u001a\u00020\u0006H\u0002J\u001e\u0010:\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u0017\u001a\u00020\u00042\u0006\u0010\u0018\u001a\u00020\u0019J\u0016\u0010;\u001a\u00020\n2\u0006\u0010\'\u001a\u00020(2\u0006\u0010\u0017\u001a\u00020\u0004J<\u0010<\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\b\b\u0002\u0010=\u001a\u00020\n2\b\b\u0002\u0010>\u001a\u00020\n2\u000e\b\u0002\u00101\u001a\b\u0012\u0004\u0012\u00020\u000402H\u0007J<\u0010?\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\b\b\u0002\u0010=\u001a\u00020\n2\b\b\u0002\u0010>\u001a\u00020\n2\u000e\b\u0002\u00101\u001a\b\u0012\u0004\u0012\u00020\u000402H\u0007J<\u0010@\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\n0\u001b2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010=\u001a\u00020\n2\u0006\u0010>\u001a\u00020\n2\u0006\u0010\u000f\u001a\u00020\u0010H\u0002J>\u0010A\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010B\u001a\u00020\n2\u0006\u0010=\u001a\u00020\n2\u0006\u0010>\u001a\u00020\n2\f\u00101\u001a\b\u0012\u0004\u0012\u00020\u000402H\u0002J\u001e\u0010C\u001a\u00020D2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102\u0006\u0010E\u001a\u00020\nJW\u0010F\u001a\u00020\u00102\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\u000f\u001a\u00020\u00102*\u0010G\u001a\u0016\u0012\u0012\b\u0001\u0012\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\n0\u001b0H\"\u000e\u0012\u0004\u0012\u00020\u0006\u0012\u0004\u0012\u00020\n0\u001b2\u000e\b\u0002\u00101\u001a\b\u0012\u0004\u0012\u00020\u000402\u00a2\u0006\u0002\u0010IJ0\u0010J\u001a\u00020\n2\u0006\u0010K\u001a\u00020\u00042\u0006\u0010L\u001a\u00020\u00062\u0006\u0010\u0017\u001a\u00020\u00042\u0006\u0010M\u001a\u00020\u00062\u0006\u0010N\u001a\u00020OH\u0002JN\u0010P\u001a\u00020D2\u0006\u0010\u000f\u001a\u00020Q26\u0010R\u001a2\u0012\u0013\u0012\u00110T\u00a2\u0006\f\bU\u0012\b\bV\u0012\u0004\b\b(W\u0012\u0013\u0012\u00110T\u00a2\u0006\f\bU\u0012\b\bV\u0012\u0004\b\b(X\u0012\u0004\u0012\u00020\u00060S2\u0006\u0010Y\u001a\u00020\nJ\u0014\u0010Z\u001a\u00020\u0006*\u00020\u00062\u0006\u0010[\u001a\u00020\u0006H\u0002J\u0014\u0010\\\u001a\u00020\u0006*\u00020\u00062\u0006\u0010[\u001a\u00020\u0006H\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0006X\u0082D\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/permissioncontroller/permission/utils/KotlinUtils;", "", "()V", "KILL_REASON_APP_OP_CHANGE", "", "ONE_TIME_PACKAGE_IMPORTANCE_LEVEL_TO_KEEP_SESSION_ALIVE", "", "ONE_TIME_PACKAGE_IMPORTANCE_LEVEL_TO_RESET_TIMER", "PERMISSION_CONTROLLER_CHANGED_FLAG_MASK", "allowAppOp", "", "app", "Landroid/app/Application;", "perm", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPermission;", "group", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "anyPermsOfPackageOneTimeGranted", "packageInfo", "Lcom/android/permissioncontroller/permission/model/livedatatypes/LightPackageInfo;", "disallowAppOp", "getBadgedPackageIcon", "Landroid/graphics/drawable/Drawable;", "packageName", "user", "Landroid/os/UserHandle;", "getMapAndListDifferences", "Lkotlin/Pair;", "", "K", "newValues", "", "oldValues", "", "getPackageLabel", "getPackageUid", "(Landroid/app/Application;Ljava/lang/String;Landroid/os/UserHandle;)Ljava/lang/Integer;", "getPermGroupDescription", "", "context", "Landroid/content/Context;", "groupName", "getPermGroupIcon", "getPermGroupLabel", "getPermInfoDescription", "permName", "getPermInfoIcon", "getPermInfoLabel", "grantBackgroundRuntimePermissions", "filterPermissions", "", "grantForegroundRuntimePermissions", "isOneTime", "grantRuntimePermission", "grantRuntimePermissions", "grantBackground", "isPermissionSplitFromNonRuntime", "targetSdk", "isROrAutoRevokeEnabled", "packageHasLaunchIntent", "revokeBackgroundRuntimePermissions", "userFixed", "oneTime", "revokeForegroundRuntimePermissions", "revokeRuntimePermission", "revokeRuntimePermissions", "revokeBackground", "setFlagsWhenLocationAccuracyChanged", "", "isFineSelected", "setGroupFlags", "flags", "", "(Landroid/app/Application;Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;[Lkotlin/Pair;Ljava/util/List;)Lcom/android/permissioncontroller/permission/model/livedatatypes/LightAppPermGroup;", "setOpMode", "op", "uid", "mode", "manager", "Landroid/app/AppOpsManager;", "sortPreferenceGroup", "Landroidx/preference/PreferenceGroup;", "compare", "Lkotlin/Function2;", "Landroidx/preference/Preference;", "Lkotlin/ParameterName;", "name", "lhs", "rhs", "hasHeader", "clearFlag", "flagToSet", "setFlag"})
public final class KotlinUtils {
    private static final int PERMISSION_CONTROLLER_CHANGED_FLAG_MASK = 196683;
    private static final java.lang.String KILL_REASON_APP_OP_CHANGE = "Permission related app op changed";
    
    /**
     * Importance level to define the threshold for whether a package is in a state which resets the
     * timer on its one-time permission session
     */
    private static final int ONE_TIME_PACKAGE_IMPORTANCE_LEVEL_TO_RESET_TIMER = android.app.ActivityManager.RunningAppProcessInfo.IMPORTANCE_FOREGROUND;
    
    /**
     * Importance level to define the threshold for whether a package is in a state which keeps its
     * one-time permission session alive after the timer ends
     */
    private static final int ONE_TIME_PACKAGE_IMPORTANCE_LEVEL_TO_KEEP_SESSION_ALIVE = android.app.ActivityManager.RunningAppProcessInfo.IMPORTANCE_FOREGROUND_SERVICE;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.permissioncontroller.permission.utils.KotlinUtils INSTANCE = null;
    
    /**
     * Given a Map, and a List, determines which elements are in the list, but not the map, and
     * vice versa. Used primarily for determining which liveDatas are already being watched, and
     * which need to be removed or added
     *
     * @param oldValues A map of key type K, with any value type
     * @param newValues A list of type K
     *
     * @return A pair, where the first value is all items in the list, but not the map, and the
     * second is all keys in the map, but not the list
     */
    @org.jetbrains.annotations.NotNull()
    public final <K extends java.lang.Object>kotlin.Pair<java.util.Set<K>, java.util.Set<K>> getMapAndListDifferences(@org.jetbrains.annotations.NotNull()
    java.util.Collection<? extends K> newValues, @org.jetbrains.annotations.NotNull()
    java.util.Map<K, ?> oldValues) {
        return null;
    }
    
    /**
     * Sort a given PreferenceGroup by the given comparison function.
     *
     * @param compare The function comparing two preferences, which will be used to sort
     * @param hasHeader Whether the group contains a LargeHeaderPreference, which will be kept at
     * the top of the list
     */
    public final void sortPreferenceGroup(@org.jetbrains.annotations.NotNull()
    androidx.preference.PreferenceGroup group, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function2<? super androidx.preference.Preference, ? super androidx.preference.Preference, java.lang.Integer> compare, boolean hasHeader) {
    }
    
    /**
     * Gets a permission group's icon from the system.
     *
     * @param context The context from which to get the icon
     * @param groupName The name of the permission group whose icon we want
     *
     * @return The permission group's icon, the ic_perm_device_info icon if the group has no icon,
     * or the group does not exist
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Drawable getPermGroupIcon(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName) {
        return null;
    }
    
    /**
     * Gets a permission group's label from the system.
     *
     * @param context The context from which to get the label
     * @param groupName The name of the permission group whose label we want
     *
     * @return The permission group's label, or the group name, if the group is invalid
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getPermGroupLabel(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName) {
        return null;
    }
    
    /**
     * Gets a permission group's description from the system.
     *
     * @param context The context from which to get the description
     * @param groupName The name of the permission group whose description we want
     *
     * @return The permission group's description, or an empty string, if the group is invalid, or
     * its description does not exist
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getPermGroupDescription(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String groupName) {
        return null;
    }
    
    /**
     * Gets a permission's label from the system.
     * @param context The context from which to get the label
     * @param permName The name of the permission whose label we want
     *
     * @return The permission's label, or the permission name, if the permission is invalid
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getPermInfoLabel(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String permName) {
        return null;
    }
    
    /**
     * Gets a permission's icon from the system.
     * @param context The context from which to get the icon
     * @param permName The name of the permission whose icon we want
     *
     * @return The permission's icon, or the permission's group icon if the icon isn't set, or
     * the ic_perm_device_info icon if the permission is invalid.
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Drawable getPermInfoIcon(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String permName) {
        return null;
    }
    
    /**
     * Gets a permission's description from the system.
     *
     * @param context The context from which to get the description
     * @param permName The name of the permission whose description we want
     *
     * @return The permission's description, or an empty string, if the group is invalid, or
     * its description does not exist
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.CharSequence getPermInfoDescription(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String permName) {
        return null;
    }
    
    /**
     * Gets a package's badged icon from the system.
     *
     * @param app The current application
     * @param packageName The name of the package whose icon we want
     * @param user The user for whom we want the package icon
     *
     * @return The package's icon, or null, if the package does not exist
     */
    @org.jetbrains.annotations.Nullable()
    public final android.graphics.drawable.Drawable getBadgedPackageIcon(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        return null;
    }
    
    /**
     * Gets a package's badged label from the system.
     *
     * @param app The current application
     * @param packageName The name of the package whose label we want
     * @param user The user for whom we want the package label
     *
     * @return The package's label
     */
    @org.jetbrains.annotations.NotNull()
    public final java.lang.String getPackageLabel(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        return null;
    }
    
    /**
     * Gets a package's uid, using a cached liveData value, if the liveData is currently being
     * observed (and thus has an up-to-date value).
     *
     * @param app The current application
     * @param packageName The name of the package whose uid we want
     * @param user The user we want the package uid for
     *
     * @return The package's UID, or null if the package or user is invalid
     */
    @org.jetbrains.annotations.Nullable()
    public final java.lang.Integer getPackageUid(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        return null;
    }
    
    /**
     * Determines if an app is R or above, or if it is Q-, and has auto revoke enabled
     *
     * @param app The currenct application
     * @param packageName The package name to check
     * @param user The user whose package we want to check
     *
     * @return true if the package is R+ (and not a work profile) or has auto revoke enabled
     */
    public final boolean isROrAutoRevokeEnabled(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName, @org.jetbrains.annotations.NotNull()
    android.os.UserHandle user) {
        return false;
    }
    
    /**
     * Determine if the given permission should be treated as split from a
     * non-runtime permission for an application targeting the given SDK level.
     */
    private final boolean isPermissionSplitFromNonRuntime(android.app.Application app, java.lang.String permName, int targetSdk) {
        return false;
    }
    
    /**
     * Set a list of flags for a set of permissions of a LightAppPermGroup
     *
     * @param app: The current application
     * @param group: The LightAppPermGroup whose permission flags we wish to set
     * @param flags: Pairs of <FlagInt, ShouldSetFlag>
     * @param filterPermissions: A list of permissions to filter by. Only the filtered permissions
     * will be set
     *
     * @return A new LightAppPermGroup with the flags set.
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup setGroupFlags(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, @org.jetbrains.annotations.NotNull()
    kotlin.Pair<java.lang.Integer, java.lang.Boolean>[] flags, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Grant all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also automatically grants all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be granted
     * @param filterPermissions If not specified, all permissions of the group will be granted.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         granted.
     *
     * @return a new LightAppPermGroup, reflecting the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup grantForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> filterPermissions, boolean isOneTime) {
        return null;
    }
    
    /**
     * Grant all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also automatically grants all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be granted
     * @param filterPermissions If not specified, all permissions of the group will be granted.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         granted.
     *
     * @return a new LightAppPermGroup, reflecting the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup grantForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Grant all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also automatically grants all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be granted
     * @param filterPermissions If not specified, all permissions of the group will be granted.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         granted.
     *
     * @return a new LightAppPermGroup, reflecting the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup grantForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    /**
     * Grant all background runtime permissions of a LightAppPermGroup
     *
     * <p>This also automatically grants all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be granted
     * @param filterPermissions If not specified, all permissions of the group will be granted.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         granted.
     *
     * @return a new LightAppPermGroup, reflecting the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup grantBackgroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Grant all background runtime permissions of a LightAppPermGroup
     *
     * <p>This also automatically grants all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be granted
     * @param filterPermissions If not specified, all permissions of the group will be granted.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         granted.
     *
     * @return a new LightAppPermGroup, reflecting the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup grantBackgroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup grantRuntimePermissions(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean grantBackground, boolean isOneTime, java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Grants a single runtime permission
     *
     * @param app The current application
     * @param perm The permission which should be granted.
     * @param group An optional app permission group in which to look for background or foreground
     * permissions
     *
     * @return a LightPermission and boolean pair <permission with updated state (or the original
     * state, if it wasn't changed), should kill app>
     */
    private final kotlin.Pair<com.android.permissioncontroller.permission.model.livedatatypes.LightPermission, java.lang.Boolean> grantRuntimePermission(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission perm, boolean isOneTime, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    /**
     * Revoke all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param oneTime If the permission should be mark as one-time
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean userFixed, boolean oneTime, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Revoke all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param oneTime If the permission should be mark as one-time
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean userFixed, boolean oneTime) {
        return null;
    }
    
    /**
     * Revoke all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param oneTime If the permission should be mark as one-time
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean userFixed) {
        return null;
    }
    
    /**
     * Revoke all foreground runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param oneTime If the permission should be mark as one-time
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeForegroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    /**
     * Revoke all background runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeBackgroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean userFixed, boolean oneTime, @org.jetbrains.annotations.NotNull()
    java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Revoke all background runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeBackgroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean userFixed, boolean oneTime) {
        return null;
    }
    
    /**
     * Revoke all background runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeBackgroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean userFixed) {
        return null;
    }
    
    /**
     * Revoke all background runtime permissions of a LightAppPermGroup
     *
     * <p>This also disallows all app ops for permissions that have app ops.
     *
     * @param app The current application
     * @param group The group whose permissions should be revoked
     * @param userFixed If the user requested that they do not want to be asked again
     * @param filterPermissions If not specified, all permissions of the group will be revoked.
     *                         Otherwise only permissions in {@code filterPermissions} will be
     *                         revoked.
     *
     * @return a LightAppPermGroup representing the new state
     */
    @org.jetbrains.annotations.NotNull()
    public final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeBackgroundRuntimePermissions(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    private final com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup revokeRuntimePermissions(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean revokeBackground, boolean userFixed, boolean oneTime, java.util.List<java.lang.String> filterPermissions) {
        return null;
    }
    
    /**
     * Determines if any permissions of a package are granted for one-time only
     *
     * @param app The current application
     * @param packageInfo The packageInfo we wish to examine
     * @param group Optional, the current app permission group we are examining
     *
     * @return true if any permission in the package is granted for one time, false otherwise
     */
    private final boolean anyPermsOfPackageOneTimeGranted(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightPackageInfo packageInfo, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return false;
    }
    
    /**
     * Revokes a single runtime permission.
     *
     * @param app The current application
     * @param perm The permission which should be revoked.
     * @param userFixed If the user requested that they do not want to be asked again
     * @param group An optional app permission group in which to look for background or foreground
     * permissions
     *
     * @return a LightPermission and boolean pair <permission with updated state (or the original
     * state, if it wasn't changed), should kill app>
     */
    private final kotlin.Pair<com.android.permissioncontroller.permission.model.livedatatypes.LightPermission, java.lang.Boolean> revokeRuntimePermission(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission perm, boolean userFixed, boolean oneTime, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return null;
    }
    
    private final int setFlag(int $this$setFlag, int flagToSet) {
        return 0;
    }
    
    private final int clearFlag(int $this$clearFlag, int flagToSet) {
        return 0;
    }
    
    /**
     * Allow the app op for a permission/uid.
     *
     * <p>There are three cases:
     * <dl>
     * <dt>The permission is not split into foreground/background</dt>
     * <dd>The app op matching the permission will be set to {@link AppOpsManager#MODE_ALLOWED}</dd>
     * <dt>The permission is a foreground permission:</dt>
     * <dd><dl><dt>The background permission permission is granted</dt>
     * <dd>The app op matching the permission will be set to {@link AppOpsManager#MODE_ALLOWED}</dd>
     * <dt>The background permission permission is <u>not</u> granted</dt>
     * <dd>The app op matching the permission will be set to
     * {@link AppOpsManager#MODE_FOREGROUND}</dd>
     * </dl></dd>
     * <dt>The permission is a background permission:</dt>
     * <dd>All granted foreground permissions for this background permission will be set to
     * {@link AppOpsManager#MODE_ALLOWED}</dd>
     * </dl>
     *
     * @param app The current application
     * @param perm The LightPermission whose app op should be allowed
     * @param group The LightAppPermGroup which will be looked in for foreground or
     * background LightPermission objects
     *
     * @return {@code true} iff app-op was changed
     */
    private final boolean allowAppOp(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission perm, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return false;
    }
    
    /**
     * Disallow the app op for a permission/uid.
     *
     * <p>There are three cases:
     * <dl>
     * <dt>The permission is not split into foreground/background</dt>
     * <dd>The app op matching the permission will be set to {@link AppOpsManager#MODE_IGNORED}</dd>
     * <dt>The permission is a foreground permission:</dt>
     * <dd>The app op matching the permission will be set to {@link AppOpsManager#MODE_IGNORED}</dd>
     * <dt>The permission is a background permission:</dt>
     * <dd>All granted foreground permissions for this background permission will be set to
     * {@link AppOpsManager#MODE_FOREGROUND}</dd>
     * </dl>
     *
     * @param app The current application
     * @param perm The LightPermission whose app op should be allowed
     * @param group The LightAppPermGroup which will be looked in for foreground or
     * background LightPermission objects
     *
     * @return {@code true} iff app-op was changed
     */
    private final boolean disallowAppOp(android.app.Application app, com.android.permissioncontroller.permission.model.livedatatypes.LightPermission perm, com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group) {
        return false;
    }
    
    /**
     * Set mode of an app-op if needed.
     *
     * @param op The op to set
     * @param uid The uid the app-op belongs to
     * @param packageName The package the app-op belongs to
     * @param mode The new mode
     * @param manager The app ops manager to use to change the app op
     *
     * @return {@code true} iff app-op was changed
     */
    private final boolean setOpMode(java.lang.String op, int uid, java.lang.String packageName, int mode, android.app.AppOpsManager manager) {
        return false;
    }
    
    /**
     * Determine if a given package has a launch intent. Will function correctly even if called
     * before user is unlocked.
     *
     * @param context: The context from which to retrieve the package
     * @param packageName: The package name to check
     *
     * @return whether or not the given package has a launch intent
     */
    public final boolean packageHasLaunchIntent(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    java.lang.String packageName) {
        return false;
    }
    
    /**
     * Set selected location accuracy flags for COARSE and FINE location permissions.
     *
     * @param app: The current application
     * @param group: The LightAppPermGroup whose permission flags we wish to set
     * @param isFineSelected: Whether fine location is selected
     */
    public final void setFlagsWhenLocationAccuracyChanged(@org.jetbrains.annotations.NotNull()
    android.app.Application app, @org.jetbrains.annotations.NotNull()
    com.android.permissioncontroller.permission.model.livedatatypes.LightAppPermGroup group, boolean isFineSelected) {
    }
    
    private KotlinUtils() {
        super();
    }
}