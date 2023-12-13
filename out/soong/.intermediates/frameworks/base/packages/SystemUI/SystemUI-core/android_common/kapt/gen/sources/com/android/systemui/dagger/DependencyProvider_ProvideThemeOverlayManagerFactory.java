package com.android.systemui.dagger;

import android.content.Context;
import android.content.om.OverlayManager;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.theme.ThemeOverlayApplier;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.concurrent.Executor;
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
public final class DependencyProvider_ProvideThemeOverlayManagerFactory implements Factory<ThemeOverlayApplier> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<OverlayManager> overlayManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public DependencyProvider_ProvideThemeOverlayManagerFactory(Provider<Context> contextProvider,
      Provider<Executor> bgExecutorProvider, Provider<Executor> mainExecutorProvider,
      Provider<OverlayManager> overlayManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.overlayManagerProvider = overlayManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public ThemeOverlayApplier get() {
    return provideThemeOverlayManager(contextProvider.get(), bgExecutorProvider.get(), mainExecutorProvider.get(), overlayManagerProvider.get(), dumpManagerProvider.get());
  }

  public static DependencyProvider_ProvideThemeOverlayManagerFactory create(
      Provider<Context> contextProvider, Provider<Executor> bgExecutorProvider,
      Provider<Executor> mainExecutorProvider, Provider<OverlayManager> overlayManagerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new DependencyProvider_ProvideThemeOverlayManagerFactory(contextProvider, bgExecutorProvider, mainExecutorProvider, overlayManagerProvider, dumpManagerProvider);
  }

  public static ThemeOverlayApplier provideThemeOverlayManager(Context context, Executor bgExecutor,
      Executor mainExecutor, OverlayManager overlayManager, DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(DependencyProvider.provideThemeOverlayManager(context, bgExecutor, mainExecutor, overlayManager, dumpManager));
  }
}
