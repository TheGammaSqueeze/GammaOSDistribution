package com.android.systemui;

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
public final class BootCompleteCacheImpl_Factory implements Factory<BootCompleteCacheImpl> {
  private final Provider<DumpManager> dumpManagerProvider;

  public BootCompleteCacheImpl_Factory(Provider<DumpManager> dumpManagerProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public BootCompleteCacheImpl get() {
    return newInstance(dumpManagerProvider.get());
  }

  public static BootCompleteCacheImpl_Factory create(Provider<DumpManager> dumpManagerProvider) {
    return new BootCompleteCacheImpl_Factory(dumpManagerProvider);
  }

  public static BootCompleteCacheImpl newInstance(DumpManager dumpManager) {
    return new BootCompleteCacheImpl(dumpManager);
  }
}
