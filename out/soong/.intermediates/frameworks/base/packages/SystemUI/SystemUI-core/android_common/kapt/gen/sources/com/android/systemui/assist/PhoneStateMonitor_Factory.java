package com.android.systemui.assist;

import android.content.Context;
import com.android.systemui.BootCompleteCache;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.phone.StatusBar;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class PhoneStateMonitor_Factory implements Factory<PhoneStateMonitor> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<BootCompleteCache> bootCompleteCacheProvider;

  public PhoneStateMonitor_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<BootCompleteCache> bootCompleteCacheProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.bootCompleteCacheProvider = bootCompleteCacheProvider;
  }

  @Override
  public PhoneStateMonitor get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), bootCompleteCacheProvider.get());
  }

  public static PhoneStateMonitor_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<BootCompleteCache> bootCompleteCacheProvider) {
    return new PhoneStateMonitor_Factory(contextProvider, broadcastDispatcherProvider, statusBarOptionalLazyProvider, bootCompleteCacheProvider);
  }

  public static PhoneStateMonitor newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher, Lazy<Optional<StatusBar>> statusBarOptionalLazy,
      BootCompleteCache bootCompleteCache) {
    return new PhoneStateMonitor(context, broadcastDispatcher, statusBarOptionalLazy, bootCompleteCache);
  }
}
