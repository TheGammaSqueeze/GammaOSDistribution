package com.android.systemui.plugins;

import android.content.Context;
import android.content.pm.PackageManager;
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
public final class PluginEnablerImpl_Factory implements Factory<PluginEnablerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<PackageManager> pmProvider;

  public PluginEnablerImpl_Factory(Provider<Context> contextProvider,
      Provider<PackageManager> pmProvider) {
    this.contextProvider = contextProvider;
    this.pmProvider = pmProvider;
  }

  @Override
  public PluginEnablerImpl get() {
    return newInstance(contextProvider.get(), pmProvider.get());
  }

  public static PluginEnablerImpl_Factory create(Provider<Context> contextProvider,
      Provider<PackageManager> pmProvider) {
    return new PluginEnablerImpl_Factory(contextProvider, pmProvider);
  }

  public static PluginEnablerImpl newInstance(Context context, PackageManager pm) {
    return new PluginEnablerImpl(context, pm);
  }
}
