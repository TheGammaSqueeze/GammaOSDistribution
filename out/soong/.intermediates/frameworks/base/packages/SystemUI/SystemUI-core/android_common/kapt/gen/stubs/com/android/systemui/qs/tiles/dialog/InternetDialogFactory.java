package com.android.systemui.qs.tiles.dialog;

import android.content.Context;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
import java.util.concurrent.Executor;
import javax.inject.Inject;

/**
 * Factory to create [InternetDialog] objects.
 */
@kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000F\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0010\u0002\n\u0000\n\u0002\u0010\u000b\n\u0002\b\u0003\n\u0002\u0018\u0002\n\u0002\b\u0002\b\u0007\u0018\u0000 \u00182\u00020\u0001:\u0001\u0018B;\b\u0007\u0012\b\b\u0001\u0010\u0002\u001a\u00020\u0003\u0012\b\b\u0001\u0010\u0004\u001a\u00020\u0005\u0012\u0006\u0010\u0006\u001a\u00020\u0007\u0012\u0006\u0010\b\u001a\u00020\t\u0012\u0006\u0010\n\u001a\u00020\u000b\u0012\u0006\u0010\f\u001a\u00020\r\u00a2\u0006\u0002\u0010\u000eJ(\u0010\u000f\u001a\u00020\u00102\u0006\u0010\u0011\u001a\u00020\u00122\u0006\u0010\u0013\u001a\u00020\u00122\u0006\u0010\u0014\u001a\u00020\u00122\b\u0010\u0015\u001a\u0004\u0018\u00010\u0016J\u0006\u0010\u0017\u001a\u00020\u0010R\u000e\u0010\b\u001a\u00020\tX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\f\u001a\u00020\rX\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0004\u001a\u00020\u0005X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0002\u001a\u00020\u0003X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\u0006\u001a\u00020\u0007X\u0082\u0004\u00a2\u0006\u0002\n\u0000R\u000e\u0010\n\u001a\u00020\u000bX\u0082\u0004\u00a2\u0006\u0002\n\u0000"}, d2 = {"Lcom/android/systemui/qs/tiles/dialog/InternetDialogFactory;", "", "handler", "Landroid/os/Handler;", "executor", "Ljava/util/concurrent/Executor;", "internetDialogController", "Lcom/android/systemui/qs/tiles/dialog/InternetDialogController;", "context", "Landroid/content/Context;", "uiEventLogger", "Lcom/android/internal/logging/UiEventLogger;", "dialogLaunchAnimator", "Lcom/android/systemui/animation/DialogLaunchAnimator;", "(Landroid/os/Handler;Ljava/util/concurrent/Executor;Lcom/android/systemui/qs/tiles/dialog/InternetDialogController;Landroid/content/Context;Lcom/android/internal/logging/UiEventLogger;Lcom/android/systemui/animation/DialogLaunchAnimator;)V", "create", "", "aboveStatusBar", "", "canConfigMobileData", "canConfigWifi", "view", "Landroid/view/View;", "destroyDialog", "Companion"})
@com.android.systemui.dagger.SysUISingleton()
public final class InternetDialogFactory {
    private final android.os.Handler handler = null;
    private final java.util.concurrent.Executor executor = null;
    private final com.android.systemui.qs.tiles.dialog.InternetDialogController internetDialogController = null;
    private final android.content.Context context = null;
    private final com.android.internal.logging.UiEventLogger uiEventLogger = null;
    private final com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator = null;
    @org.jetbrains.annotations.Nullable()
    private static com.android.systemui.qs.tiles.dialog.InternetDialog internetDialog;
    @org.jetbrains.annotations.NotNull()
    public static final com.android.systemui.qs.tiles.dialog.InternetDialogFactory.Companion Companion = null;
    
    /**
     * Creates a [InternetDialog]. The dialog will be animated from [view] if it is not null.
     */
    public final void create(boolean aboveStatusBar, boolean canConfigMobileData, boolean canConfigWifi, @org.jetbrains.annotations.Nullable()
    android.view.View view) {
    }
    
    public final void destroyDialog() {
    }
    
    @javax.inject.Inject()
    public InternetDialogFactory(@org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Main()
    android.os.Handler handler, @org.jetbrains.annotations.NotNull()
    @com.android.systemui.dagger.qualifiers.Background()
    java.util.concurrent.Executor executor, @org.jetbrains.annotations.NotNull()
    com.android.systemui.qs.tiles.dialog.InternetDialogController internetDialogController, @org.jetbrains.annotations.NotNull()
    android.content.Context context, @org.jetbrains.annotations.NotNull()
    com.android.internal.logging.UiEventLogger uiEventLogger, @org.jetbrains.annotations.NotNull()
    com.android.systemui.animation.DialogLaunchAnimator dialogLaunchAnimator) {
        super();
    }
    
    @kotlin.Metadata(mv = {1, 4, 2}, bv = {1, 0, 3}, k = 1, d1 = {"\u0000\u0014\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0002\b\u0004\b\u0086\u0003\u0018\u00002\u00020\u0001B\u0007\b\u0002\u00a2\u0006\u0002\u0010\u0002R\u001c\u0010\u0003\u001a\u0004\u0018\u00010\u0004X\u0086\u000e\u00a2\u0006\u000e\n\u0000\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\b"}, d2 = {"Lcom/android/systemui/qs/tiles/dialog/InternetDialogFactory$Companion;", "", "()V", "internetDialog", "Lcom/android/systemui/qs/tiles/dialog/InternetDialog;", "getInternetDialog", "()Lcom/android/systemui/qs/tiles/dialog/InternetDialog;", "setInternetDialog", "(Lcom/android/systemui/qs/tiles/dialog/InternetDialog;)V"})
    public static final class Companion {
        
        @org.jetbrains.annotations.Nullable()
        public final com.android.systemui.qs.tiles.dialog.InternetDialog getInternetDialog() {
            return null;
        }
        
        public final void setInternetDialog(@org.jetbrains.annotations.Nullable()
        com.android.systemui.qs.tiles.dialog.InternetDialog p0) {
        }
        
        private Companion() {
            super();
        }
    }
}