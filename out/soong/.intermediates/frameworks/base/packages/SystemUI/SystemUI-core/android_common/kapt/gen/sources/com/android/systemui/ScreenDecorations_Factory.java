package com.android.systemui;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.events.PrivacyDotViewController;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.concurrency.ThreadFactory;
import com.android.systemui.util.settings.SecureSettings;
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
public final class ScreenDecorations_Factory implements Factory<ScreenDecorations> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<PrivacyDotViewController> dotViewControllerProvider;

  private final Provider<ThreadFactory> threadFactoryProvider;

  public ScreenDecorations_Factory(Provider<Context> contextProvider,
      Provider<Executor> mainExecutorProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<TunerService> tunerServiceProvider, Provider<UserTracker> userTrackerProvider,
      Provider<PrivacyDotViewController> dotViewControllerProvider,
      Provider<ThreadFactory> threadFactoryProvider) {
    this.contextProvider = contextProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.dotViewControllerProvider = dotViewControllerProvider;
    this.threadFactoryProvider = threadFactoryProvider;
  }

  @Override
  public ScreenDecorations get() {
    return newInstance(contextProvider.get(), mainExecutorProvider.get(), secureSettingsProvider.get(), broadcastDispatcherProvider.get(), tunerServiceProvider.get(), userTrackerProvider.get(), dotViewControllerProvider.get(), threadFactoryProvider.get());
  }

  public static ScreenDecorations_Factory create(Provider<Context> contextProvider,
      Provider<Executor> mainExecutorProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<TunerService> tunerServiceProvider, Provider<UserTracker> userTrackerProvider,
      Provider<PrivacyDotViewController> dotViewControllerProvider,
      Provider<ThreadFactory> threadFactoryProvider) {
    return new ScreenDecorations_Factory(contextProvider, mainExecutorProvider, secureSettingsProvider, broadcastDispatcherProvider, tunerServiceProvider, userTrackerProvider, dotViewControllerProvider, threadFactoryProvider);
  }

  public static ScreenDecorations newInstance(Context context, Executor mainExecutor,
      SecureSettings secureSettings, BroadcastDispatcher broadcastDispatcher,
      TunerService tunerService, UserTracker userTracker,
      PrivacyDotViewController dotViewController, ThreadFactory threadFactory) {
    return new ScreenDecorations(context, mainExecutor, secureSettings, broadcastDispatcher, tunerService, userTracker, dotViewController, threadFactory);
  }
}
