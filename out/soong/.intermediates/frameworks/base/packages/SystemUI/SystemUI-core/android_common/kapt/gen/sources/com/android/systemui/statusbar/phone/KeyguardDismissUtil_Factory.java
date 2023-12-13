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
public final class KeyguardDismissUtil_Factory implements Factory<KeyguardDismissUtil> {
  @Override
  public KeyguardDismissUtil get() {
    return newInstance();
  }

  public static KeyguardDismissUtil_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static KeyguardDismissUtil newInstance() {
    return new KeyguardDismissUtil();
  }

  private static final class InstanceHolder {
    private static final KeyguardDismissUtil_Factory INSTANCE = new KeyguardDismissUtil_Factory();
  }
}
