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
public final class GlobalConcurrencyModule_ProvideMainLooperFactory implements Factory<Looper> {
  @Override
  public Looper get() {
    return provideMainLooper();
  }

  public static GlobalConcurrencyModule_ProvideMainLooperFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static Looper provideMainLooper() {
    return Preconditions.checkNotNullFromProvides(GlobalConcurrencyModule.provideMainLooper());
  }

  private static final class InstanceHolder {
    private static final GlobalConcurrencyModule_ProvideMainLooperFactory INSTANCE = new GlobalConcurrencyModule_ProvideMainLooperFactory();
  }
}
