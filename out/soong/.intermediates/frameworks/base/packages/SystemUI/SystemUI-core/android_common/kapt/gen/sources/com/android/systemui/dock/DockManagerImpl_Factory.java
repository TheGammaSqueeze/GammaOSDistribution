package com.android.systemui.dock;

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
public final class DockManagerImpl_Factory implements Factory<DockManagerImpl> {
  @Override
  public DockManagerImpl get() {
    return newInstance();
  }

  public static DockManagerImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static DockManagerImpl newInstance() {
    return new DockManagerImpl();
  }

  private static final class InstanceHolder {
    private static final DockManagerImpl_Factory INSTANCE = new DockManagerImpl_Factory();
  }
}
