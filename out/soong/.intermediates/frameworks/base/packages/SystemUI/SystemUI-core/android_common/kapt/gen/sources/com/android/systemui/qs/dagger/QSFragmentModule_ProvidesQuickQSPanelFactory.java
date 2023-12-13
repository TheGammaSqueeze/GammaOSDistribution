package com.android.systemui.qs.dagger;

import com.android.systemui.qs.QuickQSPanel;
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
public final class QSFragmentModule_ProvidesQuickQSPanelFactory implements Factory<QuickQSPanel> {
  private final Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider;

  public QSFragmentModule_ProvidesQuickQSPanelFactory(
      Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider) {
    this.quickStatusBarHeaderProvider = quickStatusBarHeaderProvider;
  }

  @Override
  public QuickQSPanel get() {
    return providesQuickQSPanel(quickStatusBarHeaderProvider.get());
  }

  public static QSFragmentModule_ProvidesQuickQSPanelFactory create(
      Provider<QuickStatusBarHeader> quickStatusBarHeaderProvider) {
    return new QSFragmentModule_ProvidesQuickQSPanelFactory(quickStatusBarHeaderProvider);
  }

  public static QuickQSPanel providesQuickQSPanel(QuickStatusBarHeader quickStatusBarHeader) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQuickQSPanel(quickStatusBarHeader));
  }
}
