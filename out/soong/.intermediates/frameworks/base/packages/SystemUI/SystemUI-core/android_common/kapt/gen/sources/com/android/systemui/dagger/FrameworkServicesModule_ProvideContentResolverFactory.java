package com.android.systemui.dagger;

import android.content.ContentResolver;
import android.content.Context;
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
public final class FrameworkServicesModule_ProvideContentResolverFactory implements Factory<ContentResolver> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideContentResolverFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ContentResolver get() {
    return provideContentResolver(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideContentResolverFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideContentResolverFactory(contextProvider);
  }

  public static ContentResolver provideContentResolver(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideContentResolver(context));
  }
}
