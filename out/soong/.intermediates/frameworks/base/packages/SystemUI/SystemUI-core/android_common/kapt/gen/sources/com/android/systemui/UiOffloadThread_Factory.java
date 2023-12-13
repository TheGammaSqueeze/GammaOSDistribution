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
public final class UiOffloadThread_Factory implements Factory<UiOffloadThread> {
  @Override
  public UiOffloadThread get() {
    return newInstance();
  }

  public static UiOffloadThread_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static UiOffloadThread newInstance() {
    return new UiOffloadThread();
  }

  private static final class InstanceHolder {
    private static final UiOffloadThread_Factory INSTANCE = new UiOffloadThread_Factory();
  }
}
