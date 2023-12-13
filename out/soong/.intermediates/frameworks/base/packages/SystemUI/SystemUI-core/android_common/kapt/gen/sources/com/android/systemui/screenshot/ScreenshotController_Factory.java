package com.android.systemui.screenshot;

import android.app.ActivityManager;
import android.content.Context;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.statusbar.IStatusBarService;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class ScreenshotController_Factory implements Factory<ScreenshotController> {
  private final Provider<Context> contextProvider;

  private final Provider<ScreenshotSmartActions> screenshotSmartActionsProvider;

  private final Provider<ScreenshotNotificationsController> screenshotNotificationsControllerProvider;

  private final Provider<ScrollCaptureClient> scrollCaptureClientProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ImageExporter> imageExporterProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<ScrollCaptureController> scrollCaptureControllerProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<LongScreenshotData> longScreenshotHolderProvider;

  private final Provider<ActivityManager> activityManagerProvider;

  public ScreenshotController_Factory(Provider<Context> contextProvider,
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider,
      Provider<ScreenshotNotificationsController> screenshotNotificationsControllerProvider,
      Provider<ScrollCaptureClient> scrollCaptureClientProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ImageExporter> imageExporterProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<ScrollCaptureController> scrollCaptureControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<LongScreenshotData> longScreenshotHolderProvider,
      Provider<ActivityManager> activityManagerProvider) {
    this.contextProvider = contextProvider;
    this.screenshotSmartActionsProvider = screenshotSmartActionsProvider;
    this.screenshotNotificationsControllerProvider = screenshotNotificationsControllerProvider;
    this.scrollCaptureClientProvider = scrollCaptureClientProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.imageExporterProvider = imageExporterProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.scrollCaptureControllerProvider = scrollCaptureControllerProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.longScreenshotHolderProvider = longScreenshotHolderProvider;
    this.activityManagerProvider = activityManagerProvider;
  }

  @Override
  public ScreenshotController get() {
    return newInstance(contextProvider.get(), screenshotSmartActionsProvider.get(), screenshotNotificationsControllerProvider.get(), scrollCaptureClientProvider.get(), uiEventLoggerProvider.get(), imageExporterProvider.get(), mainExecutorProvider.get(), scrollCaptureControllerProvider.get(), statusBarServiceProvider.get(), longScreenshotHolderProvider.get(), activityManagerProvider.get());
  }

  public static ScreenshotController_Factory create(Provider<Context> contextProvider,
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider,
      Provider<ScreenshotNotificationsController> screenshotNotificationsControllerProvider,
      Provider<ScrollCaptureClient> scrollCaptureClientProvider,
      Provider<UiEventLogger> uiEventLoggerProvider, Provider<ImageExporter> imageExporterProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<ScrollCaptureController> scrollCaptureControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<LongScreenshotData> longScreenshotHolderProvider,
      Provider<ActivityManager> activityManagerProvider) {
    return new ScreenshotController_Factory(contextProvider, screenshotSmartActionsProvider, screenshotNotificationsControllerProvider, scrollCaptureClientProvider, uiEventLoggerProvider, imageExporterProvider, mainExecutorProvider, scrollCaptureControllerProvider, statusBarServiceProvider, longScreenshotHolderProvider, activityManagerProvider);
  }

  public static ScreenshotController newInstance(Context context,
      ScreenshotSmartActions screenshotSmartActions,
      ScreenshotNotificationsController screenshotNotificationsController,
      ScrollCaptureClient scrollCaptureClient, UiEventLogger uiEventLogger, Object imageExporter,
      Executor mainExecutor, ScrollCaptureController scrollCaptureController,
      IStatusBarService statusBarService, LongScreenshotData longScreenshotHolder,
      ActivityManager activityManager) {
    return new ScreenshotController(context, screenshotSmartActions, screenshotNotificationsController, scrollCaptureClient, uiEventLogger, (ImageExporter) imageExporter, mainExecutor, scrollCaptureController, statusBarService, longScreenshotHolder, activityManager);
  }
}
