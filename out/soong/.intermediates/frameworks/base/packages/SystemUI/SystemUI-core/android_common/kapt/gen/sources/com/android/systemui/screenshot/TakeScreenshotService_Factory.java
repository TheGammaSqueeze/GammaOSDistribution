package com.android.systemui.screenshot;

import android.os.UserManager;
import com.android.internal.logging.UiEventLogger;
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
public final class TakeScreenshotService_Factory implements Factory<TakeScreenshotService> {
  private final Provider<ScreenshotController> screenshotControllerProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ScreenshotNotificationsController> notificationsControllerProvider;

  public TakeScreenshotService_Factory(Provider<ScreenshotController> screenshotControllerProvider,
      Provider<UserManager> userManagerProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<ScreenshotNotificationsController> notificationsControllerProvider) {
    this.screenshotControllerProvider = screenshotControllerProvider;
    this.userManagerProvider = userManagerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.notificationsControllerProvider = notificationsControllerProvider;
  }

  @Override
  public TakeScreenshotService get() {
    return newInstance(screenshotControllerProvider.get(), userManagerProvider.get(), uiEventLoggerProvider.get(), notificationsControllerProvider.get());
  }

  public static TakeScreenshotService_Factory create(
      Provider<ScreenshotController> screenshotControllerProvider,
      Provider<UserManager> userManagerProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<ScreenshotNotificationsController> notificationsControllerProvider) {
    return new TakeScreenshotService_Factory(screenshotControllerProvider, userManagerProvider, uiEventLoggerProvider, notificationsControllerProvider);
  }

  public static TakeScreenshotService newInstance(ScreenshotController screenshotController,
      UserManager userManager, UiEventLogger uiEventLogger,
      ScreenshotNotificationsController notificationsController) {
    return new TakeScreenshotService(screenshotController, userManager, uiEventLogger, notificationsController);
  }
}
