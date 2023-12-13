package com.android.systemui.screenshot;

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
public final class DeleteScreenshotReceiver_Factory implements Factory<DeleteScreenshotReceiver> {
  private final Provider<ScreenshotSmartActions> screenshotSmartActionsProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  public DeleteScreenshotReceiver_Factory(
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider,
      Provider<Executor> backgroundExecutorProvider) {
    this.screenshotSmartActionsProvider = screenshotSmartActionsProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
  }

  @Override
  public DeleteScreenshotReceiver get() {
    return newInstance(screenshotSmartActionsProvider.get(), backgroundExecutorProvider.get());
  }

  public static DeleteScreenshotReceiver_Factory create(
      Provider<ScreenshotSmartActions> screenshotSmartActionsProvider,
      Provider<Executor> backgroundExecutorProvider) {
    return new DeleteScreenshotReceiver_Factory(screenshotSmartActionsProvider, backgroundExecutorProvider);
  }

  public static DeleteScreenshotReceiver newInstance(ScreenshotSmartActions screenshotSmartActions,
      Executor backgroundExecutor) {
    return new DeleteScreenshotReceiver(screenshotSmartActions, backgroundExecutor);
  }
}
