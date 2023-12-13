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
public final class QSFragmentModule_ProvidesQQSFooterActionsControllerFactory implements Factory<FooterActionsController> {
  private final Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider;

  private final Provider<FooterActionsView> qqsFooterActionsViewProvider;

  public QSFragmentModule_ProvidesQQSFooterActionsControllerFactory(
      Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider,
      Provider<FooterActionsView> qqsFooterActionsViewProvider) {
    this.footerActionsControllerBuilderProvider = footerActionsControllerBuilderProvider;
    this.qqsFooterActionsViewProvider = qqsFooterActionsViewProvider;
  }

  @Override
  public FooterActionsController get() {
    return providesQQSFooterActionsController(footerActionsControllerBuilderProvider.get(), qqsFooterActionsViewProvider.get());
  }

  public static QSFragmentModule_ProvidesQQSFooterActionsControllerFactory create(
      Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider,
      Provider<FooterActionsView> qqsFooterActionsViewProvider) {
    return new QSFragmentModule_ProvidesQQSFooterActionsControllerFactory(footerActionsControllerBuilderProvider, qqsFooterActionsViewProvider);
  }

  public static FooterActionsController providesQQSFooterActionsController(
      FooterActionsControllerBuilder footerActionsControllerBuilder,
      FooterActionsView qqsFooterActionsView) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQQSFooterActionsController(footerActionsControllerBuilder, qqsFooterActionsView));
  }
}
