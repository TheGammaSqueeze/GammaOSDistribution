package com.android.systemui.dagger;

import android.content.Context;
import android.os.PowerManager;
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
public final class FrameworkServicesModule_ProvidePowerManagerFactory implements Factory<PowerManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvidePowerManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public PowerManager get() {
    return providePowerManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvidePowerManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvidePowerManagerFactory(contextProvider);
  }

  public static PowerManager providePowerManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.providePowerManager(context));
  }
}
