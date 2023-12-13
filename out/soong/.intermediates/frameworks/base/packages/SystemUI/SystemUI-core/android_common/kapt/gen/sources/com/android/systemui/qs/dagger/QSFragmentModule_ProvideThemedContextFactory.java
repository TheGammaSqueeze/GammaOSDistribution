package com.android.systemui.qs.dagger;

import android.content.Context;
import android.view.View;
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
public final class QSFragmentModule_ProvideThemedContextFactory implements Factory<Context> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvideThemedContextFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public Context get() {
    return provideThemedContext(viewProvider.get());
  }

  public static QSFragmentModule_ProvideThemedContextFactory create(Provider<View> viewProvider) {
    return new QSFragmentModule_ProvideThemedContextFactory(viewProvider);
  }

  public static Context provideThemedContext(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.provideThemedContext(view));
  }
}
