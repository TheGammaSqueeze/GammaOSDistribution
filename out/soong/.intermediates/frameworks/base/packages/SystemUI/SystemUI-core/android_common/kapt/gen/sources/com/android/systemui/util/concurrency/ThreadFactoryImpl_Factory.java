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
public final class ThreadFactoryImpl_Factory implements Factory<ThreadFactoryImpl> {
  @Override
  public ThreadFactoryImpl get() {
    return newInstance();
  }

  public static ThreadFactoryImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ThreadFactoryImpl newInstance() {
    return new ThreadFactoryImpl();
  }

  private static final class InstanceHolder {
    private static final ThreadFactoryImpl_Factory INSTANCE = new ThreadFactoryImpl_Factory();
  }
}
