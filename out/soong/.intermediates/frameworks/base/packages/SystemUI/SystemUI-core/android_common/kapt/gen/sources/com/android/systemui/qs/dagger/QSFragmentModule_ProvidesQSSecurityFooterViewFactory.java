package com.android.systemui.qs.dagger;

import android.view.LayoutInflater;
import android.view.View;
import com.android.systemui.qs.QSPanel;
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
public final class QSFragmentModule_ProvidesQSSecurityFooterViewFactory implements Factory<View> {
  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<QSPanel> qsPanelProvider;

  public QSFragmentModule_ProvidesQSSecurityFooterViewFactory(
      Provider<LayoutInflater> layoutInflaterProvider, Provider<QSPanel> qsPanelProvider) {
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.qsPanelProvider = qsPanelProvider;
  }

  @Override
  public View get() {
    return providesQSSecurityFooterView(layoutInflaterProvider.get(), qsPanelProvider.get());
  }

  public static QSFragmentModule_ProvidesQSSecurityFooterViewFactory create(
      Provider<LayoutInflater> layoutInflaterProvider, Provider<QSPanel> qsPanelProvider) {
    return new QSFragmentModule_ProvidesQSSecurityFooterViewFactory(layoutInflaterProvider, qsPanelProvider);
  }

  public static View providesQSSecurityFooterView(LayoutInflater layoutInflater, QSPanel qsPanel) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQSSecurityFooterView(layoutInflater, qsPanel));
  }
}
