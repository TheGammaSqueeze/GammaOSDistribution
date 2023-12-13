package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.content.Context;
import android.hardware.fingerprint.FingerprintManager;
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
public final class FrameworkServicesModule_ProvidesFingerprintManagerFactory implements Factory<FingerprintManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvidesFingerprintManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  @Nullable
  public FingerprintManager get() {
    return providesFingerprintManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvidesFingerprintManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvidesFingerprintManagerFactory(contextProvider);
  }

  @Nullable
  public static FingerprintManager providesFingerprintManager(Context context) {
    return FrameworkServicesModule.providesFingerprintManager(context);
  }
}
