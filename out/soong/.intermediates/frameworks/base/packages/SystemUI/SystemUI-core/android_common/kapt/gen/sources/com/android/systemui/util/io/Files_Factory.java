package com.android.systemui.util.io;

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
public final class Files_Factory implements Factory<Files> {
  @Override
  public Files get() {
    return newInstance();
  }

  public static Files_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Files newInstance() {
    return new Files();
  }

  private static final class InstanceHolder {
    private static final Files_Factory INSTANCE = new Files_Factory();
  }
}
