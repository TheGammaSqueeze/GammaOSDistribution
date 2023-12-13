package com.android.systemui.qs.customize;

import android.content.Context;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.qs.QSTileHost;
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
public final class TileAdapter_Factory implements Factory<TileAdapter> {
  private final Provider<Context> contextProvider;

  private final Provider<QSTileHost> qsHostProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  public TileAdapter_Factory(Provider<Context> contextProvider, Provider<QSTileHost> qsHostProvider,
      Provider<UiEventLogger> uiEventLoggerProvider) {
    this.contextProvider = contextProvider;
    this.qsHostProvider = qsHostProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
  }

  @Override
  public TileAdapter get() {
    return newInstance(contextProvider.get(), qsHostProvider.get(), uiEventLoggerProvider.get());
  }

  public static TileAdapter_Factory create(Provider<Context> contextProvider,
      Provider<QSTileHost> qsHostProvider, Provider<UiEventLogger> uiEventLoggerProvider) {
    return new TileAdapter_Factory(contextProvider, qsHostProvider, uiEventLoggerProvider);
  }

  public static TileAdapter newInstance(Context context, QSTileHost qsHost,
      UiEventLogger uiEventLogger) {
    return new TileAdapter(context, qsHost, uiEventLogger);
  }
}
