package com.android.systemui.wallet.dagger;

import android.content.Context;
import android.service.quickaccesswallet.QuickAccessWalletClient;
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
public final class WalletModule_ProvideQuickAccessWalletClientFactory implements Factory<QuickAccessWalletClient> {
  private final Provider<Context> contextProvider;

  public WalletModule_ProvideQuickAccessWalletClientFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public QuickAccessWalletClient get() {
    return provideQuickAccessWalletClient(contextProvider.get());
  }

  public static WalletModule_ProvideQuickAccessWalletClientFactory create(
      Provider<Context> contextProvider) {
    return new WalletModule_ProvideQuickAccessWalletClientFactory(contextProvider);
  }

  public static QuickAccessWalletClient provideQuickAccessWalletClient(Context context) {
    return Preconditions.checkNotNullFromProvides(WalletModule.provideQuickAccessWalletClient(context));
  }
}
