package com.android.systemui.statusbar.notification.collection;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.NotificationInteractionTracker;
import com.android.systemui.statusbar.notification.collection.listbuilder.ShadeListBuilderLogger;
import com.android.systemui.util.time.SystemClock;
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
public final class ShadeListBuilder_Factory implements Factory<ShadeListBuilder> {
  private final Provider<SystemClock> systemClockProvider;

  private final Provider<ShadeListBuilderLogger> loggerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<NotificationInteractionTracker> interactionTrackerProvider;

  public ShadeListBuilder_Factory(Provider<SystemClock> systemClockProvider,
      Provider<ShadeListBuilderLogger> loggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<NotificationInteractionTracker> interactionTrackerProvider) {
    this.systemClockProvider = systemClockProvider;
    this.loggerProvider = loggerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.interactionTrackerProvider = interactionTrackerProvider;
  }

  @Override
  public ShadeListBuilder get() {
    return newInstance(systemClockProvider.get(), loggerProvider.get(), dumpManagerProvider.get(), interactionTrackerProvider.get());
  }

  public static ShadeListBuilder_Factory create(Provider<SystemClock> systemClockProvider,
      Provider<ShadeListBuilderLogger> loggerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<NotificationInteractionTracker> interactionTrackerProvider) {
    return new ShadeListBuilder_Factory(systemClockProvider, loggerProvider, dumpManagerProvider, interactionTrackerProvider);
  }

  public static ShadeListBuilder newInstance(SystemClock systemClock, ShadeListBuilderLogger logger,
      DumpManager dumpManager, NotificationInteractionTracker interactionTracker) {
    return new ShadeListBuilder(systemClock, logger, dumpManager, interactionTracker);
  }
}
