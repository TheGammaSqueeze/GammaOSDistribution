package com.android.wm.shell.dagger;

import android.content.pm.PackageManager;
import com.android.internal.logging.UiEventLogger;
import com.android.wm.shell.pip.PipUiEventLogger;
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
public final class WMShellBaseModule_ProvidePipUiEventLoggerFactory implements Factory<PipUiEventLogger> {
  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<PackageManager> packageManagerProvider;

  public WMShellBaseModule_ProvidePipUiEventLoggerFactory(
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<PackageManager> packageManagerProvider) {
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.packageManagerProvider = packageManagerProvider;
  }

  @Override
  public PipUiEventLogger get() {
    return providePipUiEventLogger(uiEventLoggerProvider.get(), packageManagerProvider.get());
  }

  public static WMShellBaseModule_ProvidePipUiEventLoggerFactory create(
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<PackageManager> packageManagerProvider) {
    return new WMShellBaseModule_ProvidePipUiEventLoggerFactory(uiEventLoggerProvider, packageManagerProvider);
  }

  public static PipUiEventLogger providePipUiEventLogger(UiEventLogger uiEventLogger,
      PackageManager packageManager) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providePipUiEventLogger(uiEventLogger, packageManager));
  }
}
