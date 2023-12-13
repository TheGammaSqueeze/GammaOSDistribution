package com.android.systemui.doze;

import android.app.AlarmManager;
import android.os.Handler;
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
public final class DozePauser_Factory implements Factory<DozePauser> {
  private final Provider<Handler> handlerProvider;

  private final Provider<AlarmManager> alarmManagerProvider;

  private final Provider<AlwaysOnDisplayPolicy> policyProvider;

  public DozePauser_Factory(Provider<Handler> handlerProvider,
      Provider<AlarmManager> alarmManagerProvider, Provider<AlwaysOnDisplayPolicy> policyProvider) {
    this.handlerProvider = handlerProvider;
    this.alarmManagerProvider = alarmManagerProvider;
    this.policyProvider = policyProvider;
  }

  @Override
  public DozePauser get() {
    return newInstance(handlerProvider.get(), alarmManagerProvider.get(), policyProvider.get());
  }

  public static DozePauser_Factory create(Provider<Handler> handlerProvider,
      Provider<AlarmManager> alarmManagerProvider, Provider<AlwaysOnDisplayPolicy> policyProvider) {
    return new DozePauser_Factory(handlerProvider, alarmManagerProvider, policyProvider);
  }

  public static DozePauser newInstance(Handler handler, AlarmManager alarmManager,
      AlwaysOnDisplayPolicy policy) {
    return new DozePauser(handler, alarmManager, policy);
  }
}
