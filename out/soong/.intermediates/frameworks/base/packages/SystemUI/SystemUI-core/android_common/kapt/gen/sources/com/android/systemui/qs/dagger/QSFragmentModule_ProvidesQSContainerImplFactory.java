package com.android.systemui.qs.dagger;

import android.view.View;
import com.android.systemui.qs.QSContainerImpl;
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
public final class QSFragmentModule_ProvidesQSContainerImplFactory implements Factory<QSContainerImpl> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvidesQSContainerImplFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public QSContainerImpl get() {
    return providesQSContainerImpl(viewProvider.get());
  }

  public static QSFragmentModule_ProvidesQSContainerImplFactory create(
      Provider<View> viewProvider) {
    return new QSFragmentModule_ProvidesQSContainerImplFactory(viewProvider);
  }

  public static QSContainerImpl providesQSContainerImpl(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQSContainerImpl(view));
  }
}
