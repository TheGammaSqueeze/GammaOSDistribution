package com.android.systemui.media;

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
public final class SmartspaceMediaDataProvider_Factory implements Factory<SmartspaceMediaDataProvider> {
  @Override
  public SmartspaceMediaDataProvider get() {
    return newInstance();
  }

  public static SmartspaceMediaDataProvider_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static SmartspaceMediaDataProvider newInstance() {
    return new SmartspaceMediaDataProvider();
  }

  private static final class InstanceHolder {
    private static final SmartspaceMediaDataProvider_Factory INSTANCE = new SmartspaceMediaDataProvider_Factory();
  }
}
