package com.android.systemui.media.dialog;

import android.content.Context;
import android.media.session.MediaSessionManager;
import com.android.internal.logging.UiEventLogger;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.SystemUIDialogManager;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class MediaOutputController_Factory implements Factory<MediaOutputController> {
  private final Provider<Context> contextProvider;

  private final Provider<String> packageNameProvider;

  private final Provider<Boolean> aboveStatusbarProvider;

  private final Provider<MediaSessionManager> mediaSessionManagerProvider;

  private final Provider<LocalBluetoothManager> lbmProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<ActivityStarter> starterProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  private final Provider<SystemUIDialogManager> dialogManagerProvider;

  public MediaOutputController_Factory(Provider<Context> contextProvider,
      Provider<String> packageNameProvider, Provider<Boolean> aboveStatusbarProvider,
      Provider<MediaSessionManager> mediaSessionManagerProvider,
      Provider<LocalBluetoothManager> lbmProvider,
      Provider<ShadeController> shadeControllerProvider, Provider<ActivityStarter> starterProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider,
      Provider<SystemUIDialogManager> dialogManagerProvider) {
    this.contextProvider = contextProvider;
    this.packageNameProvider = packageNameProvider;
    this.aboveStatusbarProvider = aboveStatusbarProvider;
    this.mediaSessionManagerProvider = mediaSessionManagerProvider;
    this.lbmProvider = lbmProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.starterProvider = starterProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
    this.dialogManagerProvider = dialogManagerProvider;
  }

  @Override
  public MediaOutputController get() {
    return newInstance(contextProvider.get(), packageNameProvider.get(), aboveStatusbarProvider.get(), mediaSessionManagerProvider.get(), lbmProvider.get(), shadeControllerProvider.get(), starterProvider.get(), notificationEntryManagerProvider.get(), uiEventLoggerProvider.get(), dialogLaunchAnimatorProvider.get(), dialogManagerProvider.get());
  }

  public static MediaOutputController_Factory create(Provider<Context> contextProvider,
      Provider<String> packageNameProvider, Provider<Boolean> aboveStatusbarProvider,
      Provider<MediaSessionManager> mediaSessionManagerProvider,
      Provider<LocalBluetoothManager> lbmProvider,
      Provider<ShadeController> shadeControllerProvider, Provider<ActivityStarter> starterProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider,
      Provider<SystemUIDialogManager> dialogManagerProvider) {
    return new MediaOutputController_Factory(contextProvider, packageNameProvider, aboveStatusbarProvider, mediaSessionManagerProvider, lbmProvider, shadeControllerProvider, starterProvider, notificationEntryManagerProvider, uiEventLoggerProvider, dialogLaunchAnimatorProvider, dialogManagerProvider);
  }

  public static MediaOutputController newInstance(Context context, String packageName,
      boolean aboveStatusbar, MediaSessionManager mediaSessionManager, LocalBluetoothManager lbm,
      ShadeController shadeController, ActivityStarter starter,
      NotificationEntryManager notificationEntryManager, UiEventLogger uiEventLogger,
      DialogLaunchAnimator dialogLaunchAnimator, SystemUIDialogManager dialogManager) {
    return new MediaOutputController(context, packageName, aboveStatusbar, mediaSessionManager, lbm, shadeController, starter, notificationEntryManager, uiEventLogger, dialogLaunchAnimator, dialogManager);
  }
}
