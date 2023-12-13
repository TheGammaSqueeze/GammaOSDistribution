package com.android.systemui.qs.dagger;

import com.android.systemui.qs.QuickStatusBarHeader;
import com.android.systemui.statusbar.phone.StatusIconContainer;
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
public final class QSFragmentModule_ProvidesStatusIconContainerFactory implements Factory<StatusIconContainer> {
  private final Provider<QuickStatusBarHeader> qsHeaderProvider;

  public QSFragmentModule_ProvidesStatusIconContainerFactory(
      Provider<QuickStatusBarHeader> qsHeaderProvider) {
    this.qsHeaderProvider = qsHeaderProvider;
  }

  @Override
  public StatusIconContainer get() {
    return providesStatusIconContainer(qsHeaderProvider.get());
  }

  public static QSFragmentModule_ProvidesStatusIconContainerFactory create(
      Provider<QuickStatusBarHeader> qsHeaderProvider) {
    return new QSFragmentModule_ProvidesStatusIconContainerFactory(qsHeaderProvider);
  }

  public static StatusIconContainer providesStatusIconContainer(QuickStatusBarHeader qsHeader) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesStatusIconContainer(qsHeader));
  }
}
