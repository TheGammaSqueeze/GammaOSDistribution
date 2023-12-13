package com.android.systemui.qs.dagger;

import android.view.View;
import com.android.systemui.qs.QSFooterView;
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
public final class QSFragmentModule_ProvidesQSFooterViewFactory implements Factory<QSFooterView> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvidesQSFooterViewFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public QSFooterView get() {
    return providesQSFooterView(viewProvider.get());
  }

  public static QSFragmentModule_ProvidesQSFooterViewFactory create(Provider<View> viewProvider) {
    return new QSFragmentModule_ProvidesQSFooterViewFactory(viewProvider);
  }

  public static QSFooterView providesQSFooterView(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQSFooterView(view));
  }
}
