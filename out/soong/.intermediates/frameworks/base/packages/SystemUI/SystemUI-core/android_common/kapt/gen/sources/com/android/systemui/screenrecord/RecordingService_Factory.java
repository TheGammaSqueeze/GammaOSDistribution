package com.android.systemui.screenrecord;

import android.app.NotificationManager;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.settings.UserContextProvider;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
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
public final class RecordingService_Factory implements Factory<RecordingService> {
  private final Provider<RecordingController> controllerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<NotificationManager> notificationManagerProvider;

  private final Provider<UserContextProvider> userContextTrackerProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  public RecordingService_Factory(Provider<RecordingController> controllerProvider,
      Provider<Executor> executorProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<UserContextProvider> userContextTrackerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider) {
    this.controllerProvider = controllerProvider;
    this.executorProvider = executorProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.userContextTrackerProvider = userContextTrackerProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
  }

  @Override
  public RecordingService get() {
    return newInstance(controllerProvider.get(), executorProvider.get(), uiEventLoggerProvider.get(), notificationManagerProvider.get(), userContextTrackerProvider.get(), keyguardDismissUtilProvider.get());
  }

  public static RecordingService_Factory create(Provider<RecordingController> controllerProvider,
      Provider<Executor> executorProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<UserContextProvider> userContextTrackerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider) {
    return new RecordingService_Factory(controllerProvider, executorProvider, uiEventLoggerProvider, notificationManagerProvider, userContextTrackerProvider, keyguardDismissUtilProvider);
  }

  public static RecordingService newInstance(RecordingController controller, Executor executor,
      UiEventLogger uiEventLogger, NotificationManager notificationManager,
      UserContextProvider userContextTracker, KeyguardDismissUtil keyguardDismissUtil) {
    return new RecordingService(controller, executor, uiEventLogger, notificationManager, userContextTracker, keyguardDismissUtil);
  }
}
