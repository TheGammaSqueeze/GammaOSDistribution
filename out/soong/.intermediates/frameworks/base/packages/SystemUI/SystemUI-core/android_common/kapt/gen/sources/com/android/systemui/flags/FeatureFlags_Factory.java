package com.android.systemui.flags;

import android.content.Context;
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
public final class FeatureFlags_Factory implements Factory<FeatureFlags> {
  private final Provider<FlagReader> flagReaderProvider;

  private final Provider<Context> contextProvider;

  public FeatureFlags_Factory(Provider<FlagReader> flagReaderProvider,
      Provider<Context> contextProvider) {
    this.flagReaderProvider = flagReaderProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public FeatureFlags get() {
    return newInstance(flagReaderProvider.get(), contextProvider.get());
  }

  public static FeatureFlags_Factory create(Provider<FlagReader> flagReaderProvider,
      Provider<Context> contextProvider) {
    return new FeatureFlags_Factory(flagReaderProvider, contextProvider);
  }

  public static FeatureFlags newInstance(FlagReader flagReader, Context context) {
    return new FeatureFlags(flagReader, context);
  }
}
