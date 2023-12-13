package com.android.systemui.screenshot;

import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.statusbar.phone.StatusBar;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class ActionProxyReceiver_Factory implements Factory<ActionProxyReceiver> {
  private final Provider<Optional<StatusBar>> statusBarProvider;

  private final Provider<ActivityManagerWrapper> activityManagerWrapperProvider;

  private final Provider<ScreenshotSmartActions> screenshotSmartActionsProvider;

  public ActionProxyReceiver_Factory(Provider<Optional<StatusBar>> statusBarProvider,
      Provider<ActivityManagerWrapper> activityManagerWrapperProvider,
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider) {
    this.statusBarProvider = statusBarProvider;
    this.activityManagerWrapperProvider = activityManagerWrapperProvider;
    this.screenshotSmartActionsProvider = screenshotSmartActionsProvider;
  }

  @Override
  public ActionProxyReceiver get() {
    return newInstance(statusBarProvider.get(), activityManagerWrapperProvider.get(), screenshotSmartActionsProvider.get());
  }

  public static ActionProxyReceiver_Factory create(Provider<Optional<StatusBar>> statusBarProvider,
      Provider<ActivityManagerWrapper> activityManagerWrapperProvider,
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider) {
    return new ActionProxyReceiver_Factory(statusBarProvider, activityManagerWrapperProvider, screenshotSmartActionsProvider);
  }

  public static ActionProxyReceiver newInstance(Optional<StatusBar> statusBar,
      ActivityManagerWrapper activityManagerWrapper,
      ScreenshotSmartActions screenshotSmartActions) {
    return new ActionProxyReceiver(statusBar, activityManagerWrapper, screenshotSmartActions);
  }
}
