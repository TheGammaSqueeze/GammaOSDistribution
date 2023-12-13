package com.android.systemui.util.wakelock;

import android.content.Context;
import dagger.internal.Factory;
import javax.annotation.processing.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class DelayedWakeLock_Builder_Factory implements Factory<DelayedWakeLock.Builder> {
  private final Provider<Context> contextProvider;

  public DelayedWakeLock_Builder_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public DelayedWakeLock.Builder get() {
    return newInstance(contextProvider.get());
  }

  public static DelayedWakeLock_Builder_Factory create(Provider<Context> contextProvider) {
    return new DelayedWakeLock_Builder_Factory(contextProvider);
  }

  public static DelayedWakeLock.Builder newInstance(Context context) {
    return new DelayedWakeLock.Builder(context);
  }
}
