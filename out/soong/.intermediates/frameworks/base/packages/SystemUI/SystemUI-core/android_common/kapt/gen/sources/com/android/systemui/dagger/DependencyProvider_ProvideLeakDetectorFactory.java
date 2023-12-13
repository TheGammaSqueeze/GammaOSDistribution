package com.android.systemui.dagger;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.leak.LeakDetector;
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
public final class DependencyProvider_ProvideLeakDetectorFactory implements Factory<LeakDetector> {
  private final DependencyProvider module;

  private final Provider<DumpManager> dumpManagerProvider;

  public DependencyProvider_ProvideLeakDetectorFactory(DependencyProvider module,
      Provider<DumpManager> dumpManagerProvider) {
    this.module = module;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public LeakDetector get() {
    return provideLeakDetector(module, dumpManagerProvider.get());
  }

  public static DependencyProvider_ProvideLeakDetectorFactory create(DependencyProvider module,
      Provider<DumpManager> dumpManagerProvider) {
    return new DependencyProvider_ProvideLeakDetectorFactory(module, dumpManagerProvider);
  }

  public static LeakDetector provideLeakDetector(DependencyProvider instance,
      DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(instance.provideLeakDetector(dumpManager));
  }
}
