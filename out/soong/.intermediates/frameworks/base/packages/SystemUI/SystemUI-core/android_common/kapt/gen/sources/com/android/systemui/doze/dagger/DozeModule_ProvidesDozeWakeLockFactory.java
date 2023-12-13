package com.android.systemui.doze.dagger;

import android.os.Handler;
import com.android.systemui.util.wakelock.DelayedWakeLock;
import com.android.systemui.util.wakelock.WakeLock;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class DozeModule_ProvidesDozeWakeLockFactory implements Factory<WakeLock> {
  private final Provider<DelayedWakeLock.Builder> delayedWakeLockBuilderProvider;

  private final Provider<Handler> handlerProvider;

  public DozeModule_ProvidesDozeWakeLockFactory(
      Provider<DelayedWakeLock.Builder> delayedWakeLockBuilderProvider,
      Provider<Handler> handlerProvider) {
    this.delayedWakeLockBuilderProvider = delayedWakeLockBuilderProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public WakeLock get() {
    return providesDozeWakeLock(delayedWakeLockBuilderProvider.get(), handlerProvider.get());
  }

  public static DozeModule_ProvidesDozeWakeLockFactory create(
      Provider<DelayedWakeLock.Builder> delayedWakeLockBuilderProvider,
      Provider<Handler> handlerProvider) {
    return new DozeModule_ProvidesDozeWakeLockFactory(delayedWakeLockBuilderProvider, handlerProvider);
  }

  public static WakeLock providesDozeWakeLock(DelayedWakeLock.Builder delayedWakeLockBuilder,
      Handler handler) {
    return Preconditions.checkNotNullFromProvides(DozeModule.providesDozeWakeLock(delayedWakeLockBuilder, handler));
  }
}
