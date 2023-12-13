package com.android.systemui.dagger;

import android.content.Context;
import android.net.ConnectivityManager;
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
public final class FrameworkServicesModule_ProvideConnectivityManagagerFactory implements Factory<ConnectivityManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideConnectivityManagagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ConnectivityManager get() {
    return provideConnectivityManagager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideConnectivityManagagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideConnectivityManagagerFactory(contextProvider);
  }

  public static ConnectivityManager provideConnectivityManagager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideConnectivityManagager(context));
  }
}
