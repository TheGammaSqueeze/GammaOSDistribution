package com.android.systemui.dagger;

import com.android.systemui.ActivityStarterDelegate;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.PluginDependencyProvider;
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
public final class PluginModule_ProvideActivityStarterFactory implements Factory<ActivityStarter> {
  private final Provider<ActivityStarterDelegate> delegateProvider;

  private final Provider<PluginDependencyProvider> dependencyProvider;

  public PluginModule_ProvideActivityStarterFactory(
      Provider<ActivityStarterDelegate> delegateProvider,
      Provider<PluginDependencyProvider> dependencyProvider) {
    this.delegateProvider = delegateProvider;
    this.dependencyProvider = dependencyProvider;
  }

  @Override
  public ActivityStarter get() {
    return provideActivityStarter(delegateProvider.get(), dependencyProvider.get());
  }

  public static PluginModule_ProvideActivityStarterFactory create(
      Provider<ActivityStarterDelegate> delegateProvider,
      Provider<PluginDependencyProvider> dependencyProvider) {
    return new PluginModule_ProvideActivityStarterFactory(delegateProvider, dependencyProvider);
  }

  public static ActivityStarter provideActivityStarter(ActivityStarterDelegate delegate,
      PluginDependencyProvider dependencyProvider) {
    return Preconditions.checkNotNullFromProvides(PluginModule.provideActivityStarter(delegate, dependencyProvider));
  }
}
