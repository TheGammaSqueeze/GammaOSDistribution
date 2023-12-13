package com.android.systemui.screenshot;

import com.android.internal.logging.UiEventLogger;
import dagger.internal.Factory;
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
public final class LongScreenshotActivity_Factory implements Factory<LongScreenshotActivity> {
  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<ImageExporter> imageExporterProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<LongScreenshotData> longScreenshotHolderProvider;

  public LongScreenshotActivity_Factory(Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<ImageExporter> imageExporterProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> bgExecutorProvider,
      Provider<LongScreenshotData> longScreenshotHolderProvider) {
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.imageExporterProvider = imageExporterProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.longScreenshotHolderProvider = longScreenshotHolderProvider;
  }

  @Override
  public LongScreenshotActivity get() {
    return newInstance(uiEventLoggerProvider.get(), imageExporterProvider.get(), mainExecutorProvider.get(), bgExecutorProvider.get(), longScreenshotHolderProvider.get());
  }

  public static LongScreenshotActivity_Factory create(Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<ImageExporter> imageExporterProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> bgExecutorProvider,
      Provider<LongScreenshotData> longScreenshotHolderProvider) {
    return new LongScreenshotActivity_Factory(uiEventLoggerProvider, imageExporterProvider, mainExecutorProvider, bgExecutorProvider, longScreenshotHolderProvider);
  }

  public static LongScreenshotActivity newInstance(UiEventLogger uiEventLogger,
      Object imageExporter, Executor mainExecutor, Executor bgExecutor,
      LongScreenshotData longScreenshotHolder) {
    return new LongScreenshotActivity(uiEventLogger, (ImageExporter) imageExporter, mainExecutor, bgExecutor, longScreenshotHolder);
  }
}
