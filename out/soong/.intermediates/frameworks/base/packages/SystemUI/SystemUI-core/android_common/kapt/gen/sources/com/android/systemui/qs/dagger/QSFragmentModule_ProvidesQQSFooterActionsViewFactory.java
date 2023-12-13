package com.android.systemui.qs.dagger;

import android.view.View;
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
public final class QSFragmentModule_ProvidesQQSFooterActionsViewFactory implements Factory<FooterActionsView> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvidesQQSFooterActionsViewFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public FooterActionsView get() {
    return providesQQSFooterActionsView(viewProvider.get());
  }

  public static QSFragmentModule_ProvidesQQSFooterActionsViewFactory create(
      Provider<View> viewProvider) {
    return new QSFragmentModule_ProvidesQQSFooterActionsViewFactory(viewProvider);
  }

  public static FooterActionsView providesQQSFooterActionsView(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQQSFooterActionsView(view));
  }
}
