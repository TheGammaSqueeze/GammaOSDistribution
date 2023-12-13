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

/**
 * Relies on immutable data for thread safety. When necessary to update favMap, use reassignment to
 * replace it, which will not disrupt any ongoing map traversal.
 *
 * Update/replace calls should use thread isolation to avoid race conditions.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000>\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010$\n\u0002\u0018\u0002\n\u0002\u0010 \n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0002\b\f\n\u0002\u0018\u0002\b\u00c2\u0002\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002J\u001e\u0010\b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u00052\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000eJ\u0006\u0010\u000f\u001a\u00020\u0010J\f\u0010\u0011\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006J\u0014\u0010\u0012\u001a\b\u0012\u0004\u0012\u00020\u000e0\u00062\u0006\u0010\n\u001a\u00020\u0005J\u0014\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u000e0\u00062\u0006\u0010\u0014\u001a\u00020\u0007J\u0014\u0010\u0015\u001a\b\u0012\u0004\u0012\u00020\u00070\u00062\u0006\u0010\n\u001a\u00020\u0005J\u0014\u0010\u0016\u001a\u00020\u00102\f\u0010\u0017\u001a\b\u0012\u0004\u0012\u00020\u00070\u0006J\u000e\u0010\u0018\u001a\u00020\u00102\u0006\u0010\n\u001a\u00020\u0005J\u000e\u0010\u0019\u001a\u00020\u00102\u0006\u0010\u001a\u001a\u00020\u0007J\u001c\u0010\u001b\u001a\u00020\t2\u0006\u0010\n\u001a\u00020\u00052\f\u0010\u001c\u001a\b\u0012\u0004\u0012\u00020\u001d0\u0006R \u0010\u0003\u001a\u0014\u0012\u0004\u0012\u00020\u0005\u0012\n\u0012\b\u0012\u0004\u0012\u00020\u00070\u00060\u0004X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/controller/Favorites;", "", "()V", "favMap", "", "Landroid/content/ComponentName;", "", "Lcom/android/systemui/controls/controller/StructureInfo;", "addFavorite", "", "componentName", "structureName", "", "controlInfo", "Lcom/android/systemui/controls/controller/ControlInfo;", "clear", "", "getAllStructures", "getControlsForComponent", "getControlsForStructure", "structure", "getStructuresForComponent", "load", "structures", "removeStructures", "replaceControls", "updatedStructure", "updateControls", "controls", "Landroid/service/controls/Control;"})
final class Favorites {
    private static java.util.Map<android.content.ComponentName, ? extends java.util.List<com.android.systemui.controls.controller.StructureInfo>> favMap;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.controller.Favorites INSTANCE = null;
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.StructureInfo> getAllStructures() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.StructureInfo> getStructuresForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.ControlInfo> getControlsForStructure(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo structure) {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final java.util.List<com.android.systemui.controls.controller.ControlInfo> getControlsForComponent(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
        return null;
    }
    
    public final void load(@org.jetbrains.annotations.NotNull()
    java.util.List<com.android.systemui.controls.controller.StructureInfo> structures) {
    }
    
    public final boolean updateControls(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.util.List<android.service.controls.Control> controls) {
        return false;
    }
    
    public final void removeStructures(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName) {
    }
    
    public final boolean addFavorite(@org.jetbrains.annotations.NotNull()
    android.content.ComponentName componentName, @org.jetbrains.annotations.NotNull()
    java.lang.CharSequence structureName, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlInfo controlInfo) {
        return false;
    }
    
    public final void replaceControls(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.StructureInfo updatedStructure) {
    }
    
    public final void clear() {
    }
    
    private Favorites() {
        super();
    }
}