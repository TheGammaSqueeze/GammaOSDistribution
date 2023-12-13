package com.android.systemui.qs.dagger;

import android.view.View;
import com.android.systemui.qs.QSFragment;
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
public final class QSFragmentModule_ProvideRootViewFactory implements Factory<View> {
  private final Provider<QSFragment> qsFragmentProvider;

  public QSFragmentModule_ProvideRootViewFactory(Provider<QSFragment> qsFragmentProvider) {
    this.qsFragmentProvider = qsFragmentProvider;
  }

  @Override
  public View get() {
    return provideRootView(qsFragmentProvider.get());
  }

  public static QSFragmentModule_ProvideRootViewFactory create(
      Provider<QSFragment> qsFragmentProvider) {
    return new QSFragmentModule_ProvideRootViewFactory(qsFragmentProvider);
  }

  public static View provideRootView(QSFragment qsFragment) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.provideRootView(qsFragment));
  }
}
