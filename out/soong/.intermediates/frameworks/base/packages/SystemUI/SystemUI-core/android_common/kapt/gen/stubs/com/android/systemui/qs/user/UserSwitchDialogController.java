package com.android.systemui.qs.user;

import android.app.Dialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.provider.Settings;
import android.view.LayoutInflater;
import android.view.View;
import androidx.annotation.VisibleForTesting;
import com.android.systemui.R;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.tiles.UserDetailView;
import com.android.systemui.statusbar.phone.SystemUIDialog;
import javax.inject.Inject;
import javax.inject.Provider;

/**
 * Controller for [UserDialog].
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0007\u0018\u0000 \u00152\u00020\u0001:\u0003\u0015\u0016\u0017B-\b\u0017\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u00a2\u0006\u0002\u0010\u000bBA\b\u0007\u0012\f\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u0012\u0006\u0010\u0007\u001a\u00020\b\u0012\u0006\u0010\t\u001a\u00020\n\u0012\u0012\u0010\f\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\u000f0\r\u00a2\u0006\u0002\u0010\u0010J\u000e\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u0014R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u001a\u0010\f\u001a\u000e\u0012\u0004\u0012\u00020\u000e\u0012\u0004\u0012\u00020\u000f0\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\t\u001a\u00020\nX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0007\u001a\u00020\bX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u0014\u0010\u0002\u001a\b\u0012\u0004\u0012\u00020\u00040\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/user/UserSwitchDialogController;", "", "userDetailViewAdapterProvider", "Ljavax/inject/Provider;", "Lcom/android/systemui/qs/tiles/UserDetailView$Adapter;", "activityStarter", "Lcom/android/systemui/plugins/ActivityStarter;", "falsingManager", "Lcom/android/systemui/plugins/FalsingManager;", "dialogLaunchAnimator", "Lcom/android/systemui/animation/DialogLaunchAnimator;", "(Ljavax/inject/Provider;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/animation/DialogLaunchAnimator;)V", "dialogFactory", "Lkotlin/Function1;", "Landroid/content/Context;", "Lcom/android/systemui/statusbar/phone/SystemUIDialog;", "(Ljavax/inject/Provider;Lcom/android/systemui/plugins/ActivityStarter;Lcom/android/systemui/plugins/FalsingManager;Lcom/android/systemui/animation/DialogLaunchAnimator;Lkotlin/jvm/functions/Function1;)V", "showDialog", "", "view", "Landroid/view/View;", "Companion", "DialogShower", "DialogShowerImpl"})
@com.android.systemui.dagger.SysUISingleton()
public final class UserSwitchDialogController {
    private final javax.inject.Provider<com.android.systemui.qs.tiles.UserDetailView.Adapter> userDetailViewAdapterProvider = null;
    private final com.android.systemui.plugins.ActivityStarter activityStarter = null;
    private final com.android.systemui.plugins.FalsingManager falsingManager = null;
    private final com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator = null;
    private final kotlin.jvm.functions.Function1<android.content.Context, com.android.systemui.statusbar.phone.SystemUIDialog> dialogFactory = null;
    private static final android.content.Intent USER_SETTINGS_INTENT = null;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.user.UserSwitchDialogController.Companion Companion = null;
    
    /**
     * Show a [UserDialog].
     *
     * Populate the dialog with information from and adapter obtained from
     * [userDetailViewAdapterProvider] and show it as launched from [view].
     */
    public final void showDialog(@org.jetbrains.annotations.NotNull()
    android.view.View view) {
    }
    
    @androidx.annotation.VisibleForTesting()
    public UserSwitchDialogController(@org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.qs.tiles.UserDetailView.Adapter> userDetailViewAdapterProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator, @org.jetbrains.annotations.NotNull()
    kotlin.jvm.functions.Function1<? super android.content.Context, ? extends com.android.systemui.statusbar.phone.SystemUIDialog> dialogFactory) {
        super();
    }
    
    @javax.inject.Inject()
    public UserSwitchDialogController(@org.jetbrains.annotations.NotNull()
    javax.inject.Provider<com.android.systemui.qs.tiles.UserDetailView.Adapter> userDetailViewAdapterProvider, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.ActivityStarter activityStarter, @org.jetbrains.annotations.NotNull()
    com.android.systemui.plugins.FalsingManager falsingManager, @org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000$\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0002\b\u0003\b\u0002\u0018\u00002\u00020\u00012\u00020\u0002B\u0015\u0012\u0006\u0010\u0003\u001a\u00020\u0004\u0012\u0006\u0010\u0005\u001a\u00020\u0006\u00a2\u0006\u0002\u0010\u0007J\t\u0010\b\u001a\u00020\tH\u0096\u0001J\t\u0010\n\u001a\u00020\tH\u0096\u0001J\u0010\u0010\u000b\u001a\u00020\t2\u0006\u0010\f\u001a\u00020\u0004H\u0016R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0005\u001a\u00020\u0006X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/user/UserSwitchDialogController$DialogShowerImpl;", "Landroid/content/DialogInterface;", "Lcom/android/systemui/qs/user/UserSwitchDialogController$DialogShower;", "animateFrom", "Landroid/app/Dialog;", "dialogLaunchAnimator", "Lcom/android/systemui/animation/DialogLaunchAnimator;", "(Landroid/app/Dialog;Lcom/android/systemui/animation/DialogLaunchAnimator;)V", "cancel", "", "dismiss", "showDialog", "dialog"})
    static final class DialogShowerImpl implements android.content.DialogInterface, com.android.systemui.qs.user.UserSwitchDialogController.DialogShower {
        private final android.app.Dialog animateFrom = null;
        private final com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator = null;
        
        @java.lang.Override()
        public void showDialog(@org.jetbrains.annotations.NotNull()
        android.app.Dialog dialog) {
        }
        
        public DialogShowerImpl(@org.jetbrains.annotations.NotNull()
        android.app.Dialog animateFrom, @org.jetbrains.annotations.NotNull()
        com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator) {
            super();
        }
        
        @java.lang.Override()
        public void cancel() {
        }
        
        @java.lang.Override()
        public void dismiss() {
        }
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\bf\u0018\u00002\u00020\u0001J\u0010\u0010\u0002\u001a\u00020\u00032\u0006\u0010\u0004\u001a\u00020\u0005H&"}, d2 = {"Lcom/android/systemui/qs/user/UserSwitchDialogController$DialogShower;", "Landroid/content/DialogInterface;", "showDialog", "", "dialog", "Landroid/app/Dialog;"})
    public static abstract interface DialogShower extends android.content.DialogInterface {
        
        public abstract void showDialog(@org.jetbrains.annotations.NotNull()
        android.app.Dialog dialog);
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0010\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u000e\u0010\u0003\u001a\u00020\u0004X\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/user/UserSwitchDialogController$Companion;", "", "()V", "USER_SETTINGS_INTENT", "Landroid/content/Intent;"})
    public static final class Companion {
        
        private Companion() {
            super();
        }
    }
}