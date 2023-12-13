package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.launcher3.icons.IconProvider;
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
public final class WMShellBaseModule_ProvideIconProviderFactory implements Factory<IconProvider> {
  private final Provider<Context> contextProvider;

  public WMShellBaseModule_ProvideIconProviderFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public IconProvider get() {
    return provideIconProvider(contextProvider.get());
  }

  public static WMShellBaseModule_ProvideIconProviderFactory create(
      Provider<Context> contextProvider) {
    return new WMShellBaseModule_ProvideIconProviderFactory(contextProvider);
  }

  public static IconProvider provideIconProvider(Context context) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideIconProvider(context));
  }
}
