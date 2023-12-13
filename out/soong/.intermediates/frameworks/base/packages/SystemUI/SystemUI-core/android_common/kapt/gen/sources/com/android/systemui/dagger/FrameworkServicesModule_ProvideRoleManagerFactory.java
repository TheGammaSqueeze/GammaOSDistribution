package com.android.systemui.dagger;

import android.app.role.RoleManager;
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
public final class FrameworkServicesModule_ProvideRoleManagerFactory implements Factory<RoleManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideRoleManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public RoleManager get() {
    return provideRoleManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideRoleManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideRoleManagerFactory(contextProvider);
  }

  public static RoleManager provideRoleManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideRoleManager(context));
  }
}
