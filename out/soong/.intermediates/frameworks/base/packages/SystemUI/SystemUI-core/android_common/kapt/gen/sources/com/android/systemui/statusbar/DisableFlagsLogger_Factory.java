package com.android.systemui.statusbar;

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
public final class DisableFlagsLogger_Factory implements Factory<DisableFlagsLogger> {
  @Override
  public DisableFlagsLogger get() {
    return newInstance();
  }

  public static DisableFlagsLogger_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static DisableFlagsLogger newInstance() {
    return new DisableFlagsLogger();
  }

  private static final class InstanceHolder {
    private static final DisableFlagsLogger_Factory INSTANCE = new DisableFlagsLogger_Factory();
  }
}
