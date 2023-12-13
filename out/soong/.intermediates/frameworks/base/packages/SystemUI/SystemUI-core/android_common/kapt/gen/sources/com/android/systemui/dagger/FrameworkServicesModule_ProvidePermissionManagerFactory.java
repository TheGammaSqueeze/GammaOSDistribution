package com.android.systemui.dagger;

import android.content.Context;
import android.permission.PermissionManager;
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
public final class FrameworkServicesModule_ProvidePermissionManagerFactory implements Factory<PermissionManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvidePermissionManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public PermissionManager get() {
    return providePermissionManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvidePermissionManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvidePermissionManagerFactory(contextProvider);
  }

  public static PermissionManager providePermissionManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.providePermissionManager(context));
  }
}
