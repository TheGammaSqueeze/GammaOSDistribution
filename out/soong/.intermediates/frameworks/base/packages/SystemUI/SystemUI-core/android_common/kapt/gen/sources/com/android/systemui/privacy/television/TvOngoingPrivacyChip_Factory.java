package com.android.systemui.privacy.television;

import android.content.Context;
import com.android.systemui.privacy.PrivacyItemController;
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
public final class TvOngoingPrivacyChip_Factory implements Factory<TvOngoingPrivacyChip> {
  private final Provider<Context> contextProvider;

  private final Provider<PrivacyItemController> privacyItemControllerProvider;

  public TvOngoingPrivacyChip_Factory(Provider<Context> contextProvider,
      Provider<PrivacyItemController> privacyItemControllerProvider) {
    this.contextProvider = contextProvider;
    this.privacyItemControllerProvider = privacyItemControllerProvider;
  }

  @Override
  public TvOngoingPrivacyChip get() {
    return newInstance(contextProvider.get(), privacyItemControllerProvider.get());
  }

  public static TvOngoingPrivacyChip_Factory create(Provider<Context> contextProvider,
      Provider<PrivacyItemController> privacyItemControllerProvider) {
    return new TvOngoingPrivacyChip_Factory(contextProvider, privacyItemControllerProvider);
  }

  public static TvOngoingPrivacyChip newInstance(Context context,
      PrivacyItemController privacyItemController) {
    return new TvOngoingPrivacyChip(context, privacyItemController);
  }
}
