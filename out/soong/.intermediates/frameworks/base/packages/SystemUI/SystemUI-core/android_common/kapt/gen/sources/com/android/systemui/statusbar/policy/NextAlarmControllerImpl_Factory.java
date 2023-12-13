package com.android.systemui.statusbar.policy;

import android.app.AlarmManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
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
public final class NextAlarmControllerImpl_Factory implements Factory<NextAlarmControllerImpl> {
  private final Provider<AlarmManager> alarmManagerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NextAlarmControllerImpl_Factory(Provider<AlarmManager> alarmManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.alarmManagerProvider = alarmManagerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NextAlarmControllerImpl get() {
    return newInstance(alarmManagerProvider.get(), broadcastDispatcherProvider.get(), dumpManagerProvider.get());
  }

  public static NextAlarmControllerImpl_Factory create(Provider<AlarmManager> alarmManagerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NextAlarmControllerImpl_Factory(alarmManagerProvider, broadcastDispatcherProvider, dumpManagerProvider);
  }

  public static NextAlarmControllerImpl newInstance(AlarmManager alarmManager,
      BroadcastDispatcher broadcastDispatcher, DumpManager dumpManager) {
    return new NextAlarmControllerImpl(alarmManager, broadcastDispatcher, dumpManager);
  }
}
