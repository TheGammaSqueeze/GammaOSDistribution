package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.content.Context;
import android.hardware.face.FaceManager;
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
public final class FrameworkServicesModule_ProvideFaceManagerFactory implements Factory<FaceManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideFaceManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  @Nullable
  public FaceManager get() {
    return provideFaceManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideFaceManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideFaceManagerFactory(contextProvider);
  }

  @Nullable
  public static FaceManager provideFaceManager(Context context) {
    return FrameworkServicesModule.provideFaceManager(context);
  }
}
