package com.android.systemui.dagger;

import android.content.Context;
import android.os.Handler;
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
public final class NightDisplayListenerModule_Builder_Factory implements Factory<NightDisplayListenerModule.Builder> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> bgHandlerProvider;

  public NightDisplayListenerModule_Builder_Factory(Provider<Context> contextProvider,
      Provider<Handler> bgHandlerProvider) {
    this.contextProvider = contextProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  public NightDisplayListenerModule.Builder get() {
    return newInstance(contextProvider.get(), bgHandlerProvider.get());
  }

  public static NightDisplayListenerModule_Builder_Factory create(Provider<Context> contextProvider,
      Provider<Handler> bgHandlerProvider) {
    return new NightDisplayListenerModule_Builder_Factory(contextProvider, bgHandlerProvider);
  }

  public static NightDisplayListenerModule.Builder newInstance(Context context, Handler bgHandler) {
    return new NightDisplayListenerModule.Builder(context, bgHandler);
  }
}
