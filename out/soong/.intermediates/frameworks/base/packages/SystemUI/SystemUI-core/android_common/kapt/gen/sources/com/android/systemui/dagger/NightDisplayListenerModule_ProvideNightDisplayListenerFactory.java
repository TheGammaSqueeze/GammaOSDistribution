package com.android.systemui.dagger;

import android.content.Context;
import android.hardware.display.NightDisplayListener;
import android.os.Handler;
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
public final class NightDisplayListenerModule_ProvideNightDisplayListenerFactory implements Factory<NightDisplayListener> {
  private final NightDisplayListenerModule module;

  private final Provider<Context> contextProvider;

  private final Provider<Handler> bgHandlerProvider;

  public NightDisplayListenerModule_ProvideNightDisplayListenerFactory(
      NightDisplayListenerModule module, Provider<Context> contextProvider,
      Provider<Handler> bgHandlerProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  public NightDisplayListener get() {
    return provideNightDisplayListener(module, contextProvider.get(), bgHandlerProvider.get());
  }

  public static NightDisplayListenerModule_ProvideNightDisplayListenerFactory create(
      NightDisplayListenerModule module, Provider<Context> contextProvider,
      Provider<Handler> bgHandlerProvider) {
    return new NightDisplayListenerModule_ProvideNightDisplayListenerFactory(module, contextProvider, bgHandlerProvider);
  }

  public static NightDisplayListener provideNightDisplayListener(
      NightDisplayListenerModule instance, Context context, Handler bgHandler) {
    return Preconditions.checkNotNullFromProvides(instance.provideNightDisplayListener(context, bgHandler));
  }
}
