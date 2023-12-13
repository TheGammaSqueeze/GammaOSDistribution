package com.android.keyguard.dagger;

import android.view.LayoutInflater;
import android.view.ViewGroup;
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
public final class KeyguardBouncerModule_ProvidesRootViewFactory implements Factory<ViewGroup> {
  private final Provider<LayoutInflater> layoutInflaterProvider;

  public KeyguardBouncerModule_ProvidesRootViewFactory(
      Provider<LayoutInflater> layoutInflaterProvider) {
    this.layoutInflaterProvider = layoutInflaterProvider;
  }

  @Override
  public ViewGroup get() {
    return providesRootView(layoutInflaterProvider.get());
  }

  public static KeyguardBouncerModule_ProvidesRootViewFactory create(
      Provider<LayoutInflater> layoutInflaterProvider) {
    return new KeyguardBouncerModule_ProvidesRootViewFactory(layoutInflaterProvider);
  }

  public static ViewGroup providesRootView(LayoutInflater layoutInflater) {
    return Preconditions.checkNotNullFromProvides(KeyguardBouncerModule.providesRootView(layoutInflater));
  }
}
