package com.android.systemui.qs.dagger;

import android.view.View;
import com.android.systemui.qs.QuickStatusBarHeader;
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
public final class QSFragmentModule_ProvidesQuickStatusBarHeaderFactory implements Factory<QuickStatusBarHeader> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvidesQuickStatusBarHeaderFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public QuickStatusBarHeader get() {
    return providesQuickStatusBarHeader(viewProvider.get());
  }

  public static QSFragmentModule_ProvidesQuickStatusBarHeaderFactory create(
      Provider<View> viewProvider) {
    return new QSFragmentModule_ProvidesQuickStatusBarHeaderFactory(viewProvider);
  }

  public static QuickStatusBarHeader providesQuickStatusBarHeader(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.providesQuickStatusBarHeader(view));
  }
}
