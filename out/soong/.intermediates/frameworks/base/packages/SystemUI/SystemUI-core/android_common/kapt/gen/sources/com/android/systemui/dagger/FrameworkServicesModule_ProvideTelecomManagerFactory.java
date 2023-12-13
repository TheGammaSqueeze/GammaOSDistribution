package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.content.Context;
import android.telecom.TelecomManager;
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
public final class FrameworkServicesModule_ProvideTelecomManagerFactory implements Factory<TelecomManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideTelecomManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  @Nullable
  public TelecomManager get() {
    return provideTelecomManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideTelecomManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideTelecomManagerFactory(contextProvider);
  }

  @Nullable
  public static TelecomManager provideTelecomManager(Context context) {
    return FrameworkServicesModule.provideTelecomManager(context);
  }
}
