package com.android.systemui.dagger;

import android.app.ActivityManager;
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
public final class FrameworkServicesModule_ProvideActivityManagerFactory implements Factory<ActivityManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideActivityManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ActivityManager get() {
    return provideActivityManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideActivityManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideActivityManagerFactory(contextProvider);
  }

  public static ActivityManager provideActivityManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideActivityManager(context));
  }
}
