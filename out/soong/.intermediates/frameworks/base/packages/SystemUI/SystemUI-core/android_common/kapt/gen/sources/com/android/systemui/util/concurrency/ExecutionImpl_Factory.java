package com.android.systemui.util.concurrency;

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
public final class ExecutionImpl_Factory implements Factory<ExecutionImpl> {
  @Override
  public ExecutionImpl get() {
    return newInstance();
  }

  public static ExecutionImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ExecutionImpl newInstance() {
    return new ExecutionImpl();
  }

  private static final class InstanceHolder {
    private static final ExecutionImpl_Factory INSTANCE = new ExecutionImpl_Factory();
  }
}
