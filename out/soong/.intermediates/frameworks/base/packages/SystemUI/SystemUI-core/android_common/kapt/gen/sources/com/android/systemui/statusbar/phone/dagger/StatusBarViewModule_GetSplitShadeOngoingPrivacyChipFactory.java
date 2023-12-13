package com.android.systemui.statusbar.phone.dagger;

import android.view.View;
import com.android.systemui.privacy.OngoingPrivacyChip;
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
public final class StatusBarViewModule_GetSplitShadeOngoingPrivacyChipFactory implements Factory<OngoingPrivacyChip> {
  private final Provider<View> headerProvider;

  public StatusBarViewModule_GetSplitShadeOngoingPrivacyChipFactory(Provider<View> headerProvider) {
    this.headerProvider = headerProvider;
  }

  @Override
  public OngoingPrivacyChip get() {
    return getSplitShadeOngoingPrivacyChip(headerProvider.get());
  }

  public static StatusBarViewModule_GetSplitShadeOngoingPrivacyChipFactory create(
      Provider<View> headerProvider) {
    return new StatusBarViewModule_GetSplitShadeOngoingPrivacyChipFactory(headerProvider);
  }

  public static OngoingPrivacyChip getSplitShadeOngoingPrivacyChip(View header) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.getSplitShadeOngoingPrivacyChip(header));
  }
}
