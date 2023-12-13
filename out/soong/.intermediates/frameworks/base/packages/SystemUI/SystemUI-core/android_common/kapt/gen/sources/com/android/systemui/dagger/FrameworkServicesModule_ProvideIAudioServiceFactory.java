package com.android.systemui.dagger;

import android.media.IAudioService;
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
public final class FrameworkServicesModule_ProvideIAudioServiceFactory implements Factory<IAudioService> {
  @Override
  public IAudioService get() {
    return provideIAudioService();
  }

  public static FrameworkServicesModule_ProvideIAudioServiceFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IAudioService provideIAudioService() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIAudioService());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIAudioServiceFactory INSTANCE = new FrameworkServicesModule_ProvideIAudioServiceFactory();
  }
}
