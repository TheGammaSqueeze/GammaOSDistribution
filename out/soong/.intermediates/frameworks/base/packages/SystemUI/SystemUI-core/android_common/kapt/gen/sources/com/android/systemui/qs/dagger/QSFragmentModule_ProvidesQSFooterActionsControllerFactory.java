package com.android.systemui.qs.dagger;

import com.android.systemui.qs.FooterActionsController;
import com.android.systemui.qs.FooterActionsControllerBuilder;
import com.android.systemui.qs.FooterActionsView;
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
public final class QSFragmentModule_ProvidesQSFooterActionsControllerFactory implements Factory<FooterActionsController> {
  private final Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider;

  private final Provider<FooterActionsView> qsFooterActionsViewProvider;

  public QSFragmentModule_ProvidesQSFooterActionsControllerFactory(
      Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider,
      Provider<FooterActionsView> qsFooterActionsViewProvider) {
    this.footerActionsControllerBuilderProvider = footerActionsControllerBuilderProvider;
    this.qsFooterActionsViewProvider = qsFooterActionsViewProvider;
  }

  @Override
  public FooterActionsController get() {
    return providesQSFooterActionsController(footerActionsControllerBuilderProvider.get(), qsFooterActionsViewProvider.get());
  }

  public static QSFragmentModule_ProvidesQSFooterActionsControllerFactory create(
      Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider,
      Provider<FooterActionsView> qsFooterActionsViewProvider) {
    return new QSFragmentModule_ProvidesQSFooterActionsControllerFactory(footerActionsControllerBuilderProvider, qsFooterActionsViewProvider);
  }

  public static FooterActionsController providesQSFooterActionsController(
      FooterActionsControllerBuilder footerActionsControllerBuilder,
      FooterActionsView qsFooterActionsView) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQSFooterActionsController(footerActionsControllerBuilder, qsFooterActionsView));
  }
}
