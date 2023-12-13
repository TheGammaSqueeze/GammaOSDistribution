package com.android.systemui.flags;

import android.content.Context;
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
public final class FlagsModule_ProvideFlagManagerFactory implements Factory<FlagManager> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> handlerProvider;

  public FlagsModule_ProvideFlagManagerFactory(Provider<Context> contextProvider,
      Provider<Handler> handlerProvider) {
    this.contextProvider = contextProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public FlagManager get() {
    return provideFlagManager(contextProvider.get(), handlerProvider.get());
  }

  public static FlagsModule_ProvideFlagManagerFactory create(Provider<Context> contextProvider,
      Provider<Handler> handlerProvider) {
    return new FlagsModule_ProvideFlagManagerFactory(contextProvider, handlerProvider);
  }

  public static FlagManager provideFlagManager(Context context, Handler handler) {
    return Preconditions.checkNotNullFromProvides(FlagsModule.provideFlagManager(context, handler));
  }
}
