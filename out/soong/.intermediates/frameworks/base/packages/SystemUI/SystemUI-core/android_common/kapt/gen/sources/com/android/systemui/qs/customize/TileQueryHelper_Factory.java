package com.android.systemui.qs.customize;

import android.content.Context;
import com.android.systemui.settings.UserTracker;
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
public final class TileQueryHelper_Factory implements Factory<TileQueryHelper> {
  private final Provider<Context> contextProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<Executor> bgExecutorProvider;

  public TileQueryHelper_Factory(Provider<Context> contextProvider,
      Provider<UserTracker> userTrackerProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> bgExecutorProvider) {
    this.contextProvider = contextProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.bgExecutorProvider = bgExecutorProvider;
  }

  @Override
  public TileQueryHelper get() {
    return newInstance(contextProvider.get(), userTrackerProvider.get(), mainExecutorProvider.get(), bgExecutorProvider.get());
  }

  public static TileQueryHelper_Factory create(Provider<Context> contextProvider,
      Provider<UserTracker> userTrackerProvider, Provider<Executor> mainExecutorProvider,
      Provider<Executor> bgExecutorProvider) {
    return new TileQueryHelper_Factory(contextProvider, userTrackerProvider, mainExecutorProvider, bgExecutorProvider);
  }

  public static TileQueryHelper newInstance(Context context, UserTracker userTracker,
      Executor mainExecutor, Executor bgExecutor) {
    return new TileQueryHelper(context, userTracker, mainExecutor, bgExecutor);
  }
}
