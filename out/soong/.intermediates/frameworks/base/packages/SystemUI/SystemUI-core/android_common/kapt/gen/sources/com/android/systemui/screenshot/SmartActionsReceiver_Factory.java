package com.android.systemui.screenshot;

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
public final class SmartActionsReceiver_Factory implements Factory<SmartActionsReceiver> {
  private final Provider<ScreenshotSmartActions> screenshotSmartActionsProvider;

  public SmartActionsReceiver_Factory(
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider) {
    this.screenshotSmartActionsProvider = screenshotSmartActionsProvider;
  }

  @Override
  public SmartActionsReceiver get() {
    return newInstance(screenshotSmartActionsProvider.get());
  }

  public static SmartActionsReceiver_Factory create(
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider) {
    return new SmartActionsReceiver_Factory(screenshotSmartActionsProvider);
  }

  public static SmartActionsReceiver newInstance(ScreenshotSmartActions screenshotSmartActions) {
    return new SmartActionsReceiver(screenshotSmartActions);
  }
}
