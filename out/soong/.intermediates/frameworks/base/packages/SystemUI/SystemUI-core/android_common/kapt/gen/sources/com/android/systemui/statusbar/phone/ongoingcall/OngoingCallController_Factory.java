package com.android.systemui.statusbar.phone.ongoingcall;

import android.app.IActivityManager;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureHandler;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.util.time.SystemClock;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class OngoingCallController_Factory implements Factory<OngoingCallController> {
  private final Provider<CommonNotifCollection> notifCollectionProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<SystemClock> systemClockProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<IActivityManager> iActivityManagerProvider;

  private final Provider<OngoingCallLogger> loggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<Optional<StatusBarWindowController>> statusBarWindowControllerProvider;

  private final Provider<Optional<SwipeStatusBarAwayGestureHandler>> swipeStatusBarAwayGestureHandlerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  public OngoingCallController_Factory(Provider<CommonNotifCollection> notifCollectionProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<SystemClock> systemClockProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<Executor> mainExecutorProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<OngoingCallLogger> loggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<Optional<StatusBarWindowController>> statusBarWindowControllerProvider,
      Provider<Optional<SwipeStatusBarAwayGestureHandler>> swipeStatusBarAwayGestureHandlerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    this.notifCollectionProvider = notifCollectionProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.systemClockProvider = systemClockProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.iActivityManagerProvider = iActivityManagerProvider;
    this.loggerProvider = loggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.swipeStatusBarAwayGestureHandlerProvider = swipeStatusBarAwayGestureHandlerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
  }

  @Override
  public OngoingCallController get() {
    return newInstance(notifCollectionProvider.get(), featureFlagsProvider.get(), systemClockProvider.get(), activityStarterProvider.get(), mainExecutorProvider.get(), iActivityManagerProvider.get(), loggerProvider.get(), dumpManagerProvider.get(), statusBarWindowControllerProvider.get(), swipeStatusBarAwayGestureHandlerProvider.get(), statusBarStateControllerProvider.get());
  }

  public static OngoingCallController_Factory create(
      Provider<CommonNotifCollection> notifCollectionProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<SystemClock> systemClockProvider,
      Provider<ActivityStarter> activityStarterProvider, Provider<Executor> mainExecutorProvider,
      Provider<IActivityManager> iActivityManagerProvider,
      Provider<OngoingCallLogger> loggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<Optional<StatusBarWindowController>> statusBarWindowControllerProvider,
      Provider<Optional<SwipeStatusBarAwayGestureHandler>> swipeStatusBarAwayGestureHandlerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider) {
    return new OngoingCallController_Factory(notifCollectionProvider, featureFlagsProvider, systemClockProvider, activityStarterProvider, mainExecutorProvider, iActivityManagerProvider, loggerProvider, dumpManagerProvider, statusBarWindowControllerProvider, swipeStatusBarAwayGestureHandlerProvider, statusBarStateControllerProvider);
  }

  public static OngoingCallController newInstance(CommonNotifCollection notifCollection,
      FeatureFlags featureFlags, SystemClock systemClock, ActivityStarter activityStarter,
      Executor mainExecutor, IActivityManager iActivityManager, OngoingCallLogger logger,
      DumpManager dumpManager, Optional<StatusBarWindowController> statusBarWindowController,
      Optional<SwipeStatusBarAwayGestureHandler> swipeStatusBarAwayGestureHandler,
      StatusBarStateController statusBarStateController) {
    return new OngoingCallController(notifCollection, featureFlags, systemClock, activityStarter, mainExecutor, iActivityManager, logger, dumpManager, statusBarWindowController, swipeStatusBarAwayGestureHandler, statusBarStateController);
  }
}
