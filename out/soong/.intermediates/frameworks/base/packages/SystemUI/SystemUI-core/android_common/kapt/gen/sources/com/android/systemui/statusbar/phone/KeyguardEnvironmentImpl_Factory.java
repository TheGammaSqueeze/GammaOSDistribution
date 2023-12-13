package com.android.systemui.statusbar.phone;

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
public final class KeyguardEnvironmentImpl_Factory implements Factory<KeyguardEnvironmentImpl> {
  @Override
  public KeyguardEnvironmentImpl get() {
    return newInstance();
  }

  public static KeyguardEnvironmentImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static KeyguardEnvironmentImpl newInstance() {
    return new KeyguardEnvironmentImpl();
  }

  private static final class InstanceHolder {
    private static final KeyguardEnvironmentImpl_Factory INSTANCE = new KeyguardEnvironmentImpl_Factory();
  }
}
