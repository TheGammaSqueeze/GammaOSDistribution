package com.android.systemui.dagger;

import android.content.Context;
import android.media.AudioManager;
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
public final class FrameworkServicesModule_ProvideAudioManagerFactory implements Factory<AudioManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideAudioManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AudioManager get() {
    return provideAudioManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideAudioManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideAudioManagerFactory(contextProvider);
  }

  public static AudioManager provideAudioManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideAudioManager(context));
  }
}
