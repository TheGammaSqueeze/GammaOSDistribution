package com.android.systemui.statusbar.gesture;

import android.content.Context;
import com.android.systemui.statusbar.window.StatusBarWindowController;
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
public final class SwipeStatusBarAwayGestureHandler_Factory implements Factory<SwipeStatusBarAwayGestureHandler> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<SwipeStatusBarAwayGestureLogger> loggerProvider;

  public SwipeStatusBarAwayGestureHandler_Factory(Provider<Context> contextProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<SwipeStatusBarAwayGestureLogger> loggerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.loggerProvider = loggerProvider;
  }

  @Override
  public SwipeStatusBarAwayGestureHandler get() {
    return newInstance(contextProvider.get(), statusBarWindowControllerProvider.get(), loggerProvider.get());
  }

  public static SwipeStatusBarAwayGestureHandler_Factory create(Provider<Context> contextProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<SwipeStatusBarAwayGestureLogger> loggerProvider) {
    return new SwipeStatusBarAwayGestureHandler_Factory(contextProvider, statusBarWindowControllerProvider, loggerProvider);
  }

  public static SwipeStatusBarAwayGestureHandler newInstance(Context context,
      StatusBarWindowController statusBarWindowController, SwipeStatusBarAwayGestureLogger logger) {
    return new SwipeStatusBarAwayGestureHandler(context, statusBarWindowController, logger);
  }
}
