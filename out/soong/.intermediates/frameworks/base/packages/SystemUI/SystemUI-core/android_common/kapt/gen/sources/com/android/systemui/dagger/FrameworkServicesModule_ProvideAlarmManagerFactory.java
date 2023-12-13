package com.android.systemui.dagger;

import android.app.AlarmManager;
import android.content.Context;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class FrameworkServicesModule_ProvideAlarmManagerFactory implements Factory<AlarmManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideAlarmManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AlarmManager get() {
    return provideAlarmManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideAlarmManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideAlarmManagerFactory(contextProvider);
  }

  public static AlarmManager provideAlarmManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideAlarmManager(context));
  }
}
