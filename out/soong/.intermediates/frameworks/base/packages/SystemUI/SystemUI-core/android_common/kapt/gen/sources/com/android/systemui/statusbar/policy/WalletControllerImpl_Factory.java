package com.android.systemui.statusbar.policy;

import android.service.quickaccesswallet.QuickAccessWalletClient;
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
public final class WalletControllerImpl_Factory implements Factory<WalletControllerImpl> {
  private final Provider<QuickAccessWalletClient> quickAccessWalletClientProvider;

  public WalletControllerImpl_Factory(
      Provider<QuickAccessWalletClient> quickAccessWalletClientProvider) {
    this.quickAccessWalletClientProvider = quickAccessWalletClientProvider;
  }

  @Override
  public WalletControllerImpl get() {
    return newInstance(quickAccessWalletClientProvider.get());
  }

  public static WalletControllerImpl_Factory create(
      Provider<QuickAccessWalletClient> quickAccessWalletClientProvider) {
    return new WalletControllerImpl_Factory(quickAccessWalletClientProvider);
  }

  public static WalletControllerImpl newInstance(QuickAccessWalletClient quickAccessWalletClient) {
    return new WalletControllerImpl(quickAccessWalletClient);
  }
}
