package com.android.systemui.controls;

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
public final class CustomIconCache_Factory implements Factory<CustomIconCache> {
  @Override
  public CustomIconCache get() {
    return newInstance();
  }

  public static CustomIconCache_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static CustomIconCache newInstance() {
    return new CustomIconCache();
  }

  private static final class InstanceHolder {
    private static final CustomIconCache_Factory INSTANCE = new CustomIconCache_Factory();
  }
}
