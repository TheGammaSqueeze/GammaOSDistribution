package com.android.systemui.keyguard;

import com.android.systemui.dump.DumpManager;
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
public final class ScreenLifecycle_Factory implements Factory<ScreenLifecycle> {
  private final Provider<DumpManager> dumpManagerProvider;

  public ScreenLifecycle_Factory(Provider<DumpManager> dumpManagerProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public ScreenLifecycle get() {
    return newInstance(dumpManagerProvider.get());
  }

  public static ScreenLifecycle_Factory create(Provider<DumpManager> dumpManagerProvider) {
    return new ScreenLifecycle_Factory(dumpManagerProvider);
  }

  public static ScreenLifecycle newInstance(DumpManager dumpManager) {
    return new ScreenLifecycle(dumpManager);
  }
}
