package com.android.systemui.qs.dagger;

import com.android.systemui.qs.QSFooter;
import com.android.systemui.qs.QSFooterViewController;
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
public final class QSFragmentModule_ProvidesQSFooterFactory implements Factory<QSFooter> {
  private final Provider<QSFooterViewController> qsFooterViewControllerProvider;

  public QSFragmentModule_ProvidesQSFooterFactory(
      Provider<QSFooterViewController> qsFooterViewControllerProvider) {
    this.qsFooterViewControllerProvider = qsFooterViewControllerProvider;
  }

  @Override
  public QSFooter get() {
    return providesQSFooter(qsFooterViewControllerProvider.get());
  }

  public static QSFragmentModule_ProvidesQSFooterFactory create(
      Provider<QSFooterViewController> qsFooterViewControllerProvider) {
    return new QSFragmentModule_ProvidesQSFooterFactory(qsFooterViewControllerProvider);
  }

  public static QSFooter providesQSFooter(QSFooterViewController qsFooterViewController) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQSFooter(qsFooterViewController));
  }
}
