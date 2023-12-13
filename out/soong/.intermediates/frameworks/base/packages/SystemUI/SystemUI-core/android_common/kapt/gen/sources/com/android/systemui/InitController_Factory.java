package com.android.systemui;

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
public final class InitController_Factory implements Factory<InitController> {
  @Override
  public InitController get() {
    return newInstance();
  }

  public static InitController_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static InitController newInstance() {
    return new InitController();
  }

  private static final class InstanceHolder {
    private static final InitController_Factory INSTANCE = new InitController_Factory();
  }
}
