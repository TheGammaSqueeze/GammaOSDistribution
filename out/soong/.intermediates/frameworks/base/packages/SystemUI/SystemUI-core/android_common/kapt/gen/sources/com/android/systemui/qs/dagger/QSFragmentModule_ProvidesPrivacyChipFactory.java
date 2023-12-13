package com.android.systemui.qs.dagger;

import com.android.systemui.privacy.OngoingPrivacyChip;
import com.android.systemui.qs.QuickStatusBarHeader;
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
public final class QSFragmentModule_ProvidesPrivacyChipFactory implements Factory<OngoingPrivacyChip> {
  private final Provider<QuickStatusBarHeader> qsHeaderProvider;

  public QSFragmentModule_ProvidesPrivacyChipFactory(
      Provider<QuickStatusBarHeader> qsHeaderProvider) {
    this.qsHeaderProvider = qsHeaderProvider;
  }

  @Override
  public OngoingPrivacyChip get() {
    return providesPrivacyChip(qsHeaderProvider.get());
  }

  public static QSFragmentModule_ProvidesPrivacyChipFactory create(
      Provider<QuickStatusBarHeader> qsHeaderProvider) {
    return new QSFragmentModule_ProvidesPrivacyChipFactory(qsHeaderProvider);
  }

  public static OngoingPrivacyChip providesPrivacyChip(QuickStatusBarHeader qsHeader) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesPrivacyChip(qsHeader));
  }
}
