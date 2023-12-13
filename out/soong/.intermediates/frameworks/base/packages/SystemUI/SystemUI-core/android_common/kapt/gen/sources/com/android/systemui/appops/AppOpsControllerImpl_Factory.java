package com.android.systemui.appops;

import android.content.Context;
import android.media.AudioManager;
import android.os.Looper;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
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
public final class AppOpsControllerImpl_Factory implements Factory<AppOpsControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<Looper> bgLooperProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<AudioManager> audioManagerProvider;

  private final Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider;

  private final Provider<BroadcastDispatcher> dispatcherProvider;

  private final Provider<SystemClock> clockProvider;

  public AppOpsControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<Looper> bgLooperProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<AudioManager> audioManagerProvider,
      Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<BroadcastDispatcher> dispatcherProvider, Provider<SystemClock> clockProvider) {
    this.contextProvider = contextProvider;
    this.bgLooperProvider = bgLooperProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.audioManagerProvider = audioManagerProvider;
    this.sensorPrivacyControllerProvider = sensorPrivacyControllerProvider;
    this.dispatcherProvider = dispatcherProvider;
    this.clockProvider = clockProvider;
  }

  @Override
  public AppOpsControllerImpl get() {
    return newInstance(contextProvider.get(), bgLooperProvider.get(), dumpManagerProvider.get(), audioManagerProvider.get(), sensorPrivacyControllerProvider.get(), dispatcherProvider.get(), clockProvider.get());
  }

  public static AppOpsControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<Looper> bgLooperProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<AudioManager> audioManagerProvider,
      Provider<IndividualSensorPrivacyController> sensorPrivacyControllerProvider,
      Provider<BroadcastDispatcher> dispatcherProvider, Provider<SystemClock> clockProvider) {
    return new AppOpsControllerImpl_Factory(contextProvider, bgLooperProvider, dumpManagerProvider, audioManagerProvider, sensorPrivacyControllerProvider, dispatcherProvider, clockProvider);
  }

  public static AppOpsControllerImpl newInstance(Context context, Looper bgLooper,
      DumpManager dumpManager, AudioManager audioManager,
      IndividualSensorPrivacyController sensorPrivacyController, BroadcastDispatcher dispatcher,
      SystemClock clock) {
    return new AppOpsControllerImpl(context, bgLooper, dumpManager, audioManager, sensorPrivacyController, dispatcher, clock);
  }
}
