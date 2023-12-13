package com.android.systemui.screenshot;

import android.content.Context;
import android.view.WindowManager;
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
public final class ScreenshotNotificationsController_Factory implements Factory<ScreenshotNotificationsController> {
  private final Provider<Context> contextProvider;

  private final Provider<WindowManager> windowManagerProvider;

  public ScreenshotNotificationsController_Factory(Provider<Context> contextProvider,
      Provider<WindowManager> windowManagerProvider) {
    this.contextProvider = contextProvider;
    this.windowManagerProvider = windowManagerProvider;
  }

  @Override
  public ScreenshotNotificationsController get() {
    return newInstance(contextProvider.get(), windowManagerProvider.get());
  }

  public static ScreenshotNotificationsController_Factory create(Provider<Context> contextProvider,
      Provider<WindowManager> windowManagerProvider) {
    return new ScreenshotNotificationsController_Factory(contextProvider, windowManagerProvider);
  }

  public static ScreenshotNotificationsController newInstance(Context context,
      WindowManager windowManager) {
    return new ScreenshotNotificationsController(context, windowManager);
  }
}
