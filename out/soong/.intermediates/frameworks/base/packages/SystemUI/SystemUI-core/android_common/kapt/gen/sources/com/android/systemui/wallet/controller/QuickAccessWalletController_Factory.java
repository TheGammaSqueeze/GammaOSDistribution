package com.android.systemui.wallet.controller;

import android.content.Context;
import android.service.quickaccesswallet.QuickAccessWalletClient;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.util.time.SystemClock;
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
public final class QuickAccessWalletController_Factory implements Factory<QuickAccessWalletController> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<QuickAccessWalletClient> quickAccessWalletClientProvider;

  private final Provider<SystemClock> clockProvider;

  public QuickAccessWalletController_Factory(Provider<Context> contextProvider,
      Provider<Executor> executorProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<QuickAccessWalletClient> quickAccessWalletClientProvider,
      Provider<SystemClock> clockProvider) {
    this.contextProvider = contextProvider;
    this.executorProvider = executorProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.quickAccessWalletClientProvider = quickAccessWalletClientProvider;
    this.clockProvider = clockProvider;
  }

  @Override
  public QuickAccessWalletController get() {
    return newInstance(contextProvider.get(), executorProvider.get(), secureSettingsProvider.get(), quickAccessWalletClientProvider.get(), clockProvider.get());
  }

  public static QuickAccessWalletController_Factory create(Provider<Context> contextProvider,
      Provider<Executor> executorProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<QuickAccessWalletClient> quickAccessWalletClientProvider,
      Provider<SystemClock> clockProvider) {
    return new QuickAccessWalletController_Factory(contextProvider, executorProvider, secureSettingsProvider, quickAccessWalletClientProvider, clockProvider);
  }

  public static QuickAccessWalletController newInstance(Context context, Executor executor,
      SecureSettings secureSettings, QuickAccessWalletClient quickAccessWalletClient,
      SystemClock clock) {
    return new QuickAccessWalletController(context, executor, secureSettings, quickAccessWalletClient, clock);
  }
}
