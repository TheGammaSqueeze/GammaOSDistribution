package com.android.systemui.dagger;

import android.content.Context;
import android.telephony.TelephonyManager;
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
public final class FrameworkServicesModule_ProvideTelephonyManagerFactory implements Factory<TelephonyManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideTelephonyManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public TelephonyManager get() {
    return provideTelephonyManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideTelephonyManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideTelephonyManagerFactory(contextProvider);
  }

  public static TelephonyManager provideTelephonyManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideTelephonyManager(context));
  }
}
