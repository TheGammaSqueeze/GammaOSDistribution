package com.android.systemui.qs.dagger;

import android.view.View;
import com.android.systemui.qs.customize.QSCustomizer;
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
public final class QSFragmentModule_ProvidesQSCutomizerFactory implements Factory<QSCustomizer> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvidesQSCutomizerFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public QSCustomizer get() {
    return providesQSCutomizer(viewProvider.get());
  }

  public static QSFragmentModule_ProvidesQSCutomizerFactory create(Provider<View> viewProvider) {
    return new QSFragmentModule_ProvidesQSCutomizerFactory(viewProvider);
  }

  public static QSCustomizer providesQSCutomizer(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQSCutomizer(view));
  }
}
