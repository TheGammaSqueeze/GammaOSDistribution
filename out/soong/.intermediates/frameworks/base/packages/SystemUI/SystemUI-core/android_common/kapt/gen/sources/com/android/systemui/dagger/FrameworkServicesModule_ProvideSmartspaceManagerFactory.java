package com.android.systemui.dagger;

import android.app.smartspace.SmartspaceManager;
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
public final class FrameworkServicesModule_ProvideSmartspaceManagerFactory implements Factory<SmartspaceManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideSmartspaceManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public SmartspaceManager get() {
    return provideSmartspaceManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideSmartspaceManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideSmartspaceManagerFactory(contextProvider);
  }

  public static SmartspaceManager provideSmartspaceManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideSmartspaceManager(context));
  }
}
