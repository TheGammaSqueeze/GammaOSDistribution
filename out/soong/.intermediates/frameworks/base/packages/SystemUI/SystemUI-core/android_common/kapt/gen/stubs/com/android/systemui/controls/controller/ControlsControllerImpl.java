package com.android.systemui.controls.controller;

import android.app.PendingIntent;
import android.app.backup.BackupManager;
import android.content.BroadcastReceiver;
import android.content.ComponentName;
import android.content.ContentResolver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.database.ContentObserver;
import android.net.Uri;
import android.os.Environment;
import android.os.UserHandle;
import android.service.controls.Control;
import android.service.controls.actions.ControlAction;
import android.util.ArrayMap;
import android.util.Log;
import com.android.internal.annotations.VisibleForTesting;
import com.android.systemui.Dumpable;
import com.android.systemui.backup.BackupHelper;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.ControlStatus;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.controls.management.ControlsListingController;
import com.android.systemui.controls.ui.ControlsUiController;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.util.concurrency.DelayableExecutor;
import java.io.FileDescriptor;
import java.io.PrintWriter;
import java.util.Optional;
import java.util.concurrent.TimeUnit;
import java.util.function.Consumer;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0088\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\n\u0002\u0010!\n\u0002\u0018\u0002\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0011\n\u0002\u0010\u000e\n\u0002\b\u0004\n\u0002\u0010\"\n\u0002\b\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0005\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\n\n\u0002\u0018\u0002\n\u0002\b\b\b\u0007\u0018\u0000 \u007f2\u00020\u00012\u00020\u0002:\u0001\u007fBW\b\u0007\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\b\b\u0001\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0006\u0010\u000b\u001a\u00020\f\u0012\u0006\u0010\r\u001a\u00020\u000e\u0012\f\u0010\u000f\u001a\b\u0012\u0004\u0012\u00020\u00110\u0010\u0012\u0006\u0010\u0012\u001a\u00020\u0013\u0012\u0006\u0010\u0014\u001a\u00020\u0015\u00a2\u0006\u0002\u0010\u0016J \u0010?\u001a\u00020@2\u0006\u0010A\u001a\u00020B2\u0006\u0010C\u001a\u00020D2\u0006\u0010?\u001a\u00020EH\u0016J \u0010F\u001a\u00020@2\u0006\u0010A\u001a\u00020B2\u0006\u0010G\u001a\u00020H2\u0006\u0010C\u001a\u00020DH\u0016J\u0016\u0010I\u001a\u0002042\f\u0010J\u001a\b\u0012\u0004\u0012\u00020403H\u0016J\b\u0010K\u001a\u000204H\u0002J\u0010\u0010L\u001a\u00020&2\u0006\u0010A\u001a\u00020BH\u0016J*\u0010M\u001a\u00020N2\u0006\u0010A\u001a\u00020B2\u0006\u0010C\u001a\u00020D2\u0006\u0010O\u001a\u00020H2\b\b\u0002\u0010P\u001a\u000204H\u0002J\u0006\u0010Q\u001a\u00020@J-\u0010R\u001a\u00020@2\u0006\u0010S\u001a\u00020T2\u0006\u0010U\u001a\u00020V2\u000e\u0010W\u001a\n\u0012\u0006\b\u0001\u0012\u00020Y0XH\u0016\u00a2\u0006\u0002\u0010ZJ\u0010\u0010[\u001a\u00020@2\u0006\u0010\\\u001a\u000204H\u0002J*\u0010]\u001a\b\u0012\u0004\u0012\u00020Y0^2\f\u0010_\u001a\b\u0012\u0004\u0012\u00020Y0^2\f\u0010`\u001a\b\u0012\u0004\u0012\u00020b0aH\u0002J\u000e\u0010c\u001a\b\u0012\u0004\u0012\u00020d0aH\u0016J\u0016\u0010e\u001a\b\u0012\u0004\u0012\u00020d0a2\u0006\u0010A\u001a\u00020BH\u0016J\u001e\u0010f\u001a\b\u0012\u0004\u0012\u00020D0a2\u0006\u0010A\u001a\u00020B2\u0006\u0010G\u001a\u00020HH\u0016J\b\u0010g\u001a\u00020dH\u0016J,\u0010h\u001a\u00020@2\u0006\u0010A\u001a\u00020B2\f\u0010i\u001a\b\u0012\u0004\u0012\u00020j032\f\u0010k\u001a\b\u0012\u0004\u0012\u00020l03H\u0016J \u0010m\u001a\u00020@2\u0006\u0010A\u001a\u00020B2\u0006\u0010n\u001a\u00020Y2\u0006\u0010o\u001a\u00020&H\u0016J\u0018\u0010p\u001a\u00020@2\u0006\u0010A\u001a\u00020B2\u0006\u0010q\u001a\u00020bH\u0016J\u0010\u0010r\u001a\u00020@2\u0006\u0010s\u001a\u00020dH\u0016J\b\u0010t\u001a\u00020@H\u0002J$\u0010u\u001a\u00020@2\f\u0010v\u001a\b\u0012\u0004\u0012\u00020B0a2\f\u0010J\u001a\b\u0012\u0004\u0012\u00020w03H\u0016J\u0010\u0010x\u001a\u00020@2\u0006\u0010y\u001a\u00020$H\u0002J,\u0010z\u001a\u00020@2\f\u0010{\u001a\b\u0012\u0004\u0012\u00020B0a2\f\u0010J\u001a\b\u0012\u0004\u0012\u00020w032\u0006\u0010|\u001a\u000204H\u0002J\u0010\u0010}\u001a\u00020@2\u0006\u0010s\u001a\u00020dH\u0016J\b\u0010~\u001a\u00020@H\u0016R$\u0010\u0017\u001a\u00020\u00188\u0000@\u0000X\u0081\u000e\u00a2\u0006\u0014\n\u0000\u0012\u0004\b\u0019\u0010\u001a\u001a\u0004\b\u001b\u0010\u001c\"\u0004\b\u001d\u0010\u001eR\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u001f\u001a\u00020 8BX\u0082\u0004\u00a2\u0006\u0006\u001a\u0004\b!\u0010\"R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010#\u001a\u00020$X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u0014\u0010%\u001a\u00020&8VX\u0096\u0004\u00a2\u0006\u0006\u001a\u0004\b\'\u0010(R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010)\u001a\u00020*X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010+\u001a\u00020\u0011X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001c\u0010,\u001a\u00020-8\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b.\u0010\u001a\u001a\u0004\b/\u00100R\u001a\u00101\u001a\u000e\u0012\n\u0012\b\u0012\u0004\u0012\u0002040302X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u00105\u001a\u000204X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u001c\u00106\u001a\u0002078\u0000X\u0081\u0004\u00a2\u0006\u000e\n\u0000\u0012\u0004\b8\u0010\u001a\u001a\u0004\b9\u0010:R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010;\u001a\u000204X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010<\u001a\u00020=X\u0082\u000e\u00a2\u0006\u0002\n\u0000R\u000e\u0010>\u001a\u00020-X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsControllerImpl;", "Lcom/android/systemui/Dumpable;", "Lcom/android/systemui/controls/controller/ControlsController;", "context", "Landroid/content/Context;", "executor", "Lcom/android/systemui/util/concurrency/DelayableExecutor;", "uiController", "Lcom/android/systemui/controls/ui/ControlsUiController;", "bindingController", "Lcom/android/systemui/controls/controller/ControlsBindingController;", "listingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "optionalWrapper", "Ljava/util/Optional;", "Lcom/android/systemui/controls/controller/ControlsFavoritePersistenceWrapper;", "dumpManager", "Lcom/android/systemui/dump/DumpManager;", "userTracker", "Lcom/android/systemui/settings/UserTracker;", "(Landroid/content/Context;Lcom/android/systemui/util/concurrency/DelayableExecutor;Lcom/android/systemui/controls/ui/ControlsUiController;Lcom/android/systemui/controls/controller/ControlsBindingController;Lcom/android/systemui/controls/management/ControlsListingController;Lcom/android/systemui/broadcast/BroadcastDispatcher;Ljava/util/Optional;Lcom/android/systemui/dump/DumpManager;Lcom/android/systemui/settings/UserTracker;)V", "auxiliaryPersistenceWrapper", "Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper;", "getAuxiliaryPersistenceWrapper$main$annotations", "()V", "getAuxiliaryPersistenceWrapper$main", "()Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper;", "setAuxiliaryPersistenceWrapper$main", "(Lcom/android/systemui/controls/controller/AuxiliaryPersistenceWrapper;)V", "contentResolver", "Landroid/content/ContentResolver;", "getContentResolver", "()Landroid/content/ContentResolver;", "currentUser", "Landroid/os/UserHandle;", "currentUserId", "", "getCurrentUserId", "()I", "listingCallback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "persistenceWrapper", "restoreFinishedReceiver", "Landroid/content/BroadcastReceiver;", "getRestoreFinishedReceiver$main$annotations", "getRestoreFinishedReceiver$main", "()Landroid/content/BroadcastReceiver;", "seedingCallbacks", "", "Ljava/util/function/Consumer;", "", "seedingInProgress", "settingObserver", "Landroid/database/ContentObserver;", "getSettingObserver$main$annotations", "getSettingObserver$main", "()Landroid/database/ContentObserver;", "userChanging", "userStructure", "Lcom/android/systemui/controls/controller/UserStructure;", "userSwitchReceiver", "action", "", "componentName", "Landroid/content/ComponentName;", "controlInfo", "Lcom/android/systemui/controls/controller/ControlInfo;", "Landroid/service/controls/actions/ControlAction;", "addFavorite", "structureName", "", "addSeedingFavoritesCallback", "callback", "confirmAvailability", "countFavoritesForComponent", "createRemovedStatus", "Lcom/android/systemui/controls/ControlStatus;", "structure", "setRemoved", "destroy", "dump", "fd", "Ljava/io/FileDescriptor;", "pw", "Ljava/io/PrintWriter;", "args", "", "", "(Ljava/io/FileDescriptor;Ljava/io/PrintWriter;[Ljava/lang/String;)V", "endSeedingCall", "state", "findRemoved", "", "favoriteKeys", "list", "", "Landroid/service/controls/Control;", "getFavorites", "Lcom/android/systemui/controls/controller/StructureInfo;", "getFavoritesForComponent", "getFavoritesForStructure", "getPreferredStructure", "loadForComponent", "dataCallback", "Lcom/android/systemui/controls/controller/ControlsController$LoadData;", "cancelWrapper", "Ljava/lang/Runnable;", "onActionResponse", "controlId", "response", "refreshStatus", "control", "replaceFavoritesForStructure", "structureInfo", "resetFavorites", "seedFavoritesForComponents", "componentNames", "Lcom/android/systemui/controls/controller/SeedResponse;", "setValuesForUser", "newUser", "startSeeding", "remainingComponentNames", "didAnyFail", "subscribeToFavorites", "unsubscribe", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class ControlsControllerImpl implements com.android.systemui.Dumpable, com.android.systemui.controls.controller.ControlsController {
    private boolean userChanging = true;
    private com.android.systemui.controls.controller.UserStructure userStructure;
    private boolean seedingInProgress = false;
    private final java.util.List<java.util.function.Consumer<java.lang.Boolean>> seedingCallbacks = null;
    private android.os.UserHandle currentUser;
    private final com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper persistenceWrapper = null;
    @org.jetbrains.annotations.NotNull()
    private com.android.systemui.controls.controller.AuxiliaryPersistenceWrapper auxiliaryPersistenceWrapper;
    private final android.content.BroadcastReceiver userSwitchReceiver = null;
    @org.jetbrains.annotations.NotNull()
    private final android.content.BroadcastReceiver restoreFinishedReceiver = null;
    @org.jetbrains.annotations.NotNull()
    private final android.database.ContentObserver settingObserver = null;
    
    /**
     * Check if any component has been removed and if so, remove all its favorites.
     *
     * If some component has been removed, the new set of favorites will also be saved.
     */
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback listingCallback = null;
    private final android.content.Context context = null;
    private final com.android.systemui.util.concurrency.DelayableExecutor executor = null;
    private final com.android.systemui.controls.ui.ControlsUiController uiController = null;
    private final com.android.systemui.controls.controller.ControlsBindingController bindingController = null;
    private final com.android.systemui.controls.management.ControlsListingController listingController = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private static final java.lang.String TAG = "ControlsControllerImpl";
    private static final long USER_CHANGE_RETRY_DELAY = 500L;
    private static final int DEFAULT_ENABLED = 1;
    private static final java.lang.String PERMISSION_SELF = "com.android.systemui.permission.SELF";
    public static final int SUGGESTED_CONTROLS_PER_STRUCTURE = 6;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.ControlsControllerImpl.Companion Companion = null;
    
    @java.lang.Override()
    public int getCurrentUserId() {
        return 0;
    }
    
    private final android.content.ContentResolver getContentResolver() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getAuxiliaryPersistenceWrapper$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final com.android.systemui.controls.controller.AuxiliaryPersistenceWrapper getAuxiliaryPersistenceWrapper$main() {
        return null;
    }
    
    public final void setAuxiliaryPersistenceWrapper$main(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.AuxiliaryPersistenceWrapper p0) {
    }
    
    private final void setValuesForUser(android.os.UserHandle newUser) {
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getRestoreFinishedReceiver$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.content.BroadcastReceiver getRestoreFinishedReceiver$main() {
        return null;
    }
    
    @com.android.internal.annotations.VisibleForTesting()
    @java.lang.Deprecated()
    public static void getSettingObserver$main$annotations() {
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.database.ContentObserver getSettingObserver$main() {
        return null;
    }
    
    public final void destroy() {
    }
    
    private final void resetFavorites() {
    }
    
    private final boolean confirmAvailability() {
        return false;
    }
    
    @java.lang.Override()
    public void loadForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<com.android.systemui.controls.controller.ControlsController.LoadData> dataCallback, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<java.lang.Runnable> cancelWrapper) {
    }
    
    @java.lang.Override()
    public boolean addSeedingFavoritesCallback(@org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<java.lang.Boolean> callback) {
        return false;
    }
    
    @java.lang.Override()
    public void seedFavoritesForComponents(@org.jetbrains.annotations.NotNull()
    java.util.List<android.content.ComponentName> componentNames, @org.jetbrains.annotations.NotNull()
    java.util.function.Consumer<com.android.systemui.controls.controller.SeedResponse> callback) {
    }
    
    private final void startSeeding(java.util.List<android.content.ComponentName> remainingComponentNames, java.util.function.Consumer<com.android.systemui.controls.controller.SeedResponse> callback, boolean didAnyFail) {
    }
    
    private final void endSeedingCall(boolean state) {
    }
    
    private final com.android.systemui.controls.ControlStatus createRemovedStatus(android.content.ComponentName componentName, com.android.systemui.controls.controller.ControlInfo controlInfo, java.lang.CharSequence structure, boolean setRemoved) {
        return null;
    }
    
    private final java.util.Set<java.lang.String> findRemoved(java.util.Set<java.lang.String> favoriteKeys, java.util.List<android.service.controls.Control> list) {
        return null;
    }
    
    @java.lang.Override()
    public void subscribeToFavorites(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structureInfo) {
    }
    
    @java.lang.Override()
    public void unsubscribe() {
    }
    
    @java.lang.Override()
    public void addFavorite(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo) {
    }
    
    @java.lang.Override()
    public void replaceFavoritesForStructure(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structureInfo) {
    }
    
    @java.lang.Override()
    public void refreshStatus(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    android.service.controls.Control control) {
    }
    
    @java.lang.Override()
    public void onActionResponse(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.String controlId, int response) {
    }
    
    @java.lang.Override()
    public void action(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo, @org.jetbrains.annotations.NotNull()
    android.service.controls.actions.ControlAction action) {
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.controls.controller.StructureInfo> getFavorites() {
        return null;
    }
    
    @java.lang.Override()
    public int countFavoritesForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
        return 0;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.controls.controller.StructureInfo> getFavoritesForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public java.util.List<com.android.systemui.controls.controller.ControlInfo> getFavoritesForStructure(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    @java.lang.Override()
    public com.android.systemui.controls.controller.StructureInfo getPreferredStructure() {
        return null;
    }
    
    @java.lang.Override()
    public void dump(@org.jetbrains.annotations.NotNull()
    java.io.FileDescriptor fd, @org.jetbrains.annotations.NotNull()
    java.io.PrintWriter pw, @org.jetbrains.annotations.NotNull()
    java.lang.String[] args) {
    }
    
    @javax.inject.Inject()
    public ControlsControllerImpl(@org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    com.android.systemui.util.concurrency.DelayableExecutor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.ui.ControlsUiController uiController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsBindingController bindingController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController listingController, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    java.util.Optional<com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper> optionalWrapper, @org.jetbrains.annotations.NotNull()
    com.android.systemui.dump.DumpManager dumpManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.settings.UserTracker userTracker) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u001e\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\b\n\u0000\n\u0002\u0010\u000e\n\u0002\b\u0003\n\u0002\u0010\t\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\u0004X\u0086T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\u0006X\u0082T\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/ControlsControllerImpl$Companion;", "", "()V", "DEFAULT_ENABLED", "", "PERMISSION_SELF", "", "SUGGESTED_CONTROLS_PER_STRUCTURE", "TAG", "USER_CHANGE_RETRY_DELAY", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}