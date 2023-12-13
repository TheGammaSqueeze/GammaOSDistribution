package com.android.systemui.dump;

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
public final class DumpManager_Factory implements Factory<DumpManager> {
  @Override
  public DumpManager get() {
    return newInstance();
  }

  public static DumpManager_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static DumpManager newInstance() {
    return new DumpManager();
  }

  private static final class InstanceHolder {
    private static final DumpManager_Factory INSTANCE = new DumpManager_Factory();
  }
}
