package com.android.systemui.telephony;

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
public final class TelephonyCallback_Factory implements Factory<TelephonyCallback> {
  @Override
  public TelephonyCallback get() {
    return newInstance();
  }

  public static TelephonyCallback_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static TelephonyCallback newInstance() {
    return new TelephonyCallback();
  }

  private static final class InstanceHolder {
    private static final TelephonyCallback_Factory INSTANCE = new TelephonyCallback_Factory();
  }
}
