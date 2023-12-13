package com.android.systemui.dagger;

import android.app.trust.TrustManager;
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
public final class FrameworkServicesModule_ProvideTrustManagerFactory implements Factory<TrustManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideTrustManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public TrustManager get() {
    return provideTrustManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideTrustManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideTrustManagerFactory(contextProvider);
  }

  public static TrustManager provideTrustManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideTrustManager(context));
  }
}
