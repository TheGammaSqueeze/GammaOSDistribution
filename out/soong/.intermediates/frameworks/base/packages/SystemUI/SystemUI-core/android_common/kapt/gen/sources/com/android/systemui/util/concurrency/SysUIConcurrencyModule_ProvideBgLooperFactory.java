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
public final class SysUIConcurrencyModule_ProvideBgLooperFactory implements Factory<Looper> {
  @Override
  public Looper get() {
    return provideBgLooper();
  }

  public static SysUIConcurrencyModule_ProvideBgLooperFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Looper provideBgLooper() {
    return Preconditions.checkNotNullFromProvides(SysUIConcurrencyModule.provideBgLooper());
  }

  private static final class InstanceHolder {
    private static final SysUIConcurrencyModule_ProvideBgLooperFactory INSTANCE = new SysUIConcurrencyModule_ProvideBgLooperFactory();
  }
}
