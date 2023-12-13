package com.android.systemui.dagger;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class GlobalModule_ProvideIsTestHarnessFactory implements Factory<Boolean> {
  @Override
  public Boolean get() {
    return provideIsTestHarness();
  }

  public static GlobalModule_ProvideIsTestHarnessFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static boolean provideIsTestHarness() {
    return GlobalModule.provideIsTestHarness();
  }

  private static final class InstanceHolder {
    private static final GlobalModule_ProvideIsTestHarnessFactory INSTANCE = new GlobalModule_ProvideIsTestHarnessFactory();
  }
}
