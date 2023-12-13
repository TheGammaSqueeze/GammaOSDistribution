package com.android.systemui.screenshot;

import android.content.Context;
import android.view.IWindowManager;
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
public final class ScrollCaptureClient_Factory implements Factory<ScrollCaptureClient> {
  private final Provider<IWindowManager> windowManagerServiceProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<Context> contextProvider;

  public ScrollCaptureClient_Factory(Provider<IWindowManager> windowManagerServiceProvider,
      Provider<Executor> bgExecutorProvider, Provider<Context> contextProvider) {
    this.windowManagerServiceProvider = windowManagerServiceProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public ScrollCaptureClient get() {
    return newInstance(windowManagerServiceProvider.get(), bgExecutorProvider.get(), contextProvider.get());
  }

  public static ScrollCaptureClient_Factory create(
      Provider<IWindowManager> windowManagerServiceProvider, Provider<Executor> bgExecutorProvider,
      Provider<Context> contextProvider) {
    return new ScrollCaptureClient_Factory(windowManagerServiceProvider, bgExecutorProvider, contextProvider);
  }

  public static ScrollCaptureClient newInstance(IWindowManager windowManagerService,
      Executor bgExecutor, Context context) {
    return new ScrollCaptureClient(windowManagerService, bgExecutor, context);
  }
}
