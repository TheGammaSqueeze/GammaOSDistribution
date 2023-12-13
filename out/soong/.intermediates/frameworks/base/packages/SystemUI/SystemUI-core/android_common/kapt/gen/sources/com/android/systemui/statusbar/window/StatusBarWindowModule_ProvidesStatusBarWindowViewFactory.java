package com.android.systemui.statusbar.window;

import android.view.LayoutInflater;
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
public final class StatusBarWindowModule_ProvidesStatusBarWindowViewFactory implements Factory<StatusBarWindowView> {
  private final Provider<LayoutInflater> layoutInflaterProvider;

  public StatusBarWindowModule_ProvidesStatusBarWindowViewFactory(
      Provider<LayoutInflater> layoutInflaterProvider) {
    this.layoutInflaterProvider = layoutInflaterProvider;
  }

  @Override
  public StatusBarWindowView get() {
    return providesStatusBarWindowView(layoutInflaterProvider.get());
  }

  public static StatusBarWindowModule_ProvidesStatusBarWindowViewFactory create(
      Provider<LayoutInflater> layoutInflaterProvider) {
    return new StatusBarWindowModule_ProvidesStatusBarWindowViewFactory(layoutInflaterProvider);
  }

  public static StatusBarWindowView providesStatusBarWindowView(LayoutInflater layoutInflater) {
    return Preconditions.checkNotNullFromProvides(StatusBarWindowModule.providesStatusBarWindowView(layoutInflater));
  }
}
