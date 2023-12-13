package com.android.systemui.dagger;

import android.content.Context;
import com.android.systemui.accessibility.ModeSwitchesController;
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
public final class DependencyProvider_ProvidesModeSwitchesControllerFactory implements Factory<ModeSwitchesController> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvidesModeSwitchesControllerFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public ModeSwitchesController get() {
    return providesModeSwitchesController(module, contextProvider.get());
  }

  public static DependencyProvider_ProvidesModeSwitchesControllerFactory create(
      DependencyProvider module, Provider<Context> contextProvider) {
    return new DependencyProvider_ProvidesModeSwitchesControllerFactory(module, contextProvider);
  }

  public static ModeSwitchesController providesModeSwitchesController(DependencyProvider instance,
      Context context) {
    return Preconditions.checkNotNullFromProvides(instance.providesModeSwitchesController(context));
  }
}
