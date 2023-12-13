package com.android.wm.shell.dagger;

import com.android.wm.shell.common.FloatingContentCoordinator;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class WMShellBaseModule_ProvideFloatingContentCoordinatorFactory implements Factory<FloatingContentCoordinator> {
  @Override
  public FloatingContentCoordinator get() {
    return provideFloatingContentCoordinator();
  }

  public static WMShellBaseModule_ProvideFloatingContentCoordinatorFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static FloatingContentCoordinator provideFloatingContentCoordinator() {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideFloatingContentCoordinator());
  }

  private static final class InstanceHolder {
    private static final WMShellBaseModule_ProvideFloatingContentCoordinatorFactory INSTANCE = new WMShellBaseModule_ProvideFloatingContentCoordinatorFactory();
  }
}
