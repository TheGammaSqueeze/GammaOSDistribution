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
public final class WakeLock_Builder_Factory implements Factory<WakeLock.Builder> {
  private final Provider<Context> contextProvider;

  public WakeLock_Builder_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public WakeLock.Builder get() {
    return newInstance(contextProvider.get());
  }

  public static WakeLock_Builder_Factory create(Provider<Context> contextProvider) {
    return new WakeLock_Builder_Factory(contextProvider);
  }

  public static WakeLock.Builder newInstance(Context context) {
    return new WakeLock.Builder(context);
  }
}
