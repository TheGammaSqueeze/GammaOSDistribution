package com.android.systemui.dagger;

import android.content.Context;
import android.os.UserManager;
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
public final class FrameworkServicesModule_ProvideUserManagerFactory implements Factory<UserManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideUserManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public UserManager get() {
    return provideUserManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideUserManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideUserManagerFactory(contextProvider);
  }

  public static UserManager provideUserManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideUserManager(context));
  }
}
