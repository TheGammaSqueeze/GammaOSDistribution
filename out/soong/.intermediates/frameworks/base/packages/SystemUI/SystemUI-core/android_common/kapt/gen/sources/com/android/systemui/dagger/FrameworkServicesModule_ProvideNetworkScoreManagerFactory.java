package com.android.systemui.dagger;

import android.content.Context;
import android.net.NetworkScoreManager;
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
public final class FrameworkServicesModule_ProvideNetworkScoreManagerFactory implements Factory<NetworkScoreManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideNetworkScoreManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public NetworkScoreManager get() {
    return provideNetworkScoreManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideNetworkScoreManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideNetworkScoreManagerFactory(contextProvider);
  }

  public static NetworkScoreManager provideNetworkScoreManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideNetworkScoreManager(context));
  }
}
