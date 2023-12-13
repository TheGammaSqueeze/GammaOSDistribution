package com.android.systemui.dagger;

import com.android.internal.app.IBatteryStats;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class FrameworkServicesModule_ProvideIBatteryStatsFactory implements Factory<IBatteryStats> {
  @Override
  public IBatteryStats get() {
    return provideIBatteryStats();
  }

  public static FrameworkServicesModule_ProvideIBatteryStatsFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IBatteryStats provideIBatteryStats() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIBatteryStats());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIBatteryStatsFactory INSTANCE = new FrameworkServicesModule_ProvideIBatteryStatsFactory();
  }
}
