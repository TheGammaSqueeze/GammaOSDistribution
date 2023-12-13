package com.android.systemui.controls.management;

import android.app.AlertDialog;
import android.app.Dialog;
import android.content.ComponentName;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.UserHandle;
import android.service.controls.Control;
import android.service.controls.ControlsProviderService;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import com.android.systemui.R;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.controls.ControlsServiceInfo;
import com.android.systemui.controls.controller.ControlInfo;
import com.android.systemui.controls.controller.ControlsController;
import com.android.systemui.controls.ui.RenderInfo;
import com.android.systemui.settings.CurrentUserTracker;
import com.android.systemui.statusbar.phone.SystemUIDialog;
import com.android.systemui.util.LifecycleActivity;
import javax.inject.Inject;

@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000n\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\r\n\u0000\n\u0002\u0010\u000b\n\u0000\n\u0002\u0010\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\b\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0016\u0018\u0000 &2\u00020\u00012\u00020\u00022\u00020\u0003:\u0001&B\u001f\b\u0007\u0012\u0006\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u00a2\u0006\u0002\u0010\nJ\u000e\u0010\u0015\u001a\u00020\u00142\u0006\u0010\u0016\u001a\u00020\u0017J\b\u0010\u0018\u001a\u00020\u0019H\u0002J\u0012\u0010\u001a\u001a\u00020\u001b2\b\u0010\u0013\u001a\u0004\u0018\u00010\u001cH\u0016J\u001a\u0010\u001d\u001a\u00020\u001b2\b\u0010\u0013\u001a\u0004\u0018\u00010\u001c2\u0006\u0010\u001e\u001a\u00020\u001fH\u0016J\u0012\u0010 \u001a\u00020\u001b2\b\u0010!\u001a\u0004\u0018\u00010\"H\u0014J\b\u0010#\u001a\u00020\u001bH\u0014J\b\u0010$\u001a\u00020\u001bH\u0014J\n\u0010%\u001a\u0004\u0018\u00010\u0017H\u0002R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000b\u001a\u00020\fX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\r\u001a\u00020\u000eX\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u000f\u001a\u00020\u0010X\u0082.\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0011\u001a\u00020\u0012X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0010\u0010\u0013\u001a\u0004\u0018\u00010\u0014X\u0082\u000e\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsRequestDialog;", "Lcom/android/systemui/util/LifecycleActivity;", "Landroid/content/DialogInterface$OnClickListener;", "Landroid/content/DialogInterface$OnCancelListener;", "controller", "Lcom/android/systemui/controls/controller/ControlsController;", "broadcastDispatcher", "Lcom/android/systemui/broadcast/BroadcastDispatcher;", "controlsListingController", "Lcom/android/systemui/controls/management/ControlsListingController;", "(Lcom/android/systemui/controls/controller/ControlsController;Lcom/android/systemui/broadcast/BroadcastDispatcher;Lcom/android/systemui/controls/management/ControlsListingController;)V", "callback", "Lcom/android/systemui/controls/management/ControlsListingController$ControlsListingCallback;", "control", "Landroid/service/controls/Control;", "controlComponent", "Landroid/content/ComponentName;", "currentUserTracker", "Lcom/android/systemui/settings/CurrentUserTracker;", "dialog", "Landroid/app/Dialog;", "createDialog", "label", "", "isCurrentFavorite", "", "onCancel", "", "Landroid/content/DialogInterface;", "onClick", "which", "", "onCreate", "savedInstanceState", "Landroid/os/Bundle;", "onDestroy", "onResume", "verifyComponentAndGetLabel", "Companion"})
public class ControlsRequestDialog extends com.android.systemui.util.LifecycleActivity implements android.content.DialogInterface.OnClickListener, android.content.DialogInterface.OnCancelListener {
    private android.content.ComponentName controlComponent;
    private android.service.controls.Control control;
    private android.app.Dialog dialog;
    private final com.android.systemui.controls.management.ControlsListingController.ControlsListingCallback callback = null;
    private final com.android.systemui.settings.CurrentUserTracker currentUserTracker = null;
    private final com.android.systemui.controls.controller.ControlsController controller = null;
    private final com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher = null;
    private final com.android.systemui.controls.management.ControlsListingController controlsListingController = null;
    private static final java.lang.String TAG = "ControlsRequestDialog";
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.controls.management.ControlsRequestDialog.Companion Companion = null;
    
    @java.lang.Override()
    protected void onCreate(@org.jetbrains.annotations.Nullable()
    android.os.Bundle savedInstanceState) {
    }
    
    @java.lang.Override()
    protected void onResume() {
    }
    
    @java.lang.Override()
    protected void onDestroy() {
    }
    
    private final java.lang.CharSequence verifyComponentAndGetLabel() {
        return null;
    }
    
    private final boolean isCurrentFavorite() {
        return false;
    }
    
    @org.jetbrains.annotations.NotNull()
    public final android.app.Dialog createDialog(@org.jetbrains.annotations.NotNull()
    java.lang.CharSequence label) {
        return null;
    }
    
    @java.lang.Override()
    public void onCancel(@org.jetbrains.annotations.Nullable()
    android.content.DialogInterface dialog) {
    }
    
    @java.lang.Override()
    public void onClick(@org.jetbrains.annotations.Nullable()
    android.content.DialogInterface dialog, int which) {
    }
    
    @javax.inject.Inject()
    public ControlsRequestDialog(@org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.controller.ControlsController controller, @org.jetbrains.annotations.NotNull()
    com.android.systemui.broadcast.BroadcastDispatcher broadcastDispatcher, @org.jetbrains.annotations.NotNull()
    com.android.systemui.controls.management.ControlsListingController controlsListingController) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0010\u000e\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082T\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/controls/management/ControlsRequestDialog$Companion;", "", "()V", "TAG", ""})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}