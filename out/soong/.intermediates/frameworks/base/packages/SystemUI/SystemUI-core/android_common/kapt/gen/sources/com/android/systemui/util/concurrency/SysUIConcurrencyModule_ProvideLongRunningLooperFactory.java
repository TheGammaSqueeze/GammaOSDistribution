package com.android.systemui.util.concurrency;

import android.os.Looper;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SysUIConcurrencyModule_ProvideLongRunningLooperFactory implements Factory<Looper> {
  @Override
  public Looper get() {
    return provideLongRunningLooper();
  }

  public static SysUIConcurrencyModule_ProvideLongRunningLooperFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Looper provideLongRunningLooper() {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideLongRunningLooper());
  }

  private static final class InstanceHolder {
    private static final SysUIConcurrencyModule_ProvideLongRunningLooperFactory INSTANCE = new SysUIConcurrencyModule_ProvideLongRunningLooperFactory();
  }
}
