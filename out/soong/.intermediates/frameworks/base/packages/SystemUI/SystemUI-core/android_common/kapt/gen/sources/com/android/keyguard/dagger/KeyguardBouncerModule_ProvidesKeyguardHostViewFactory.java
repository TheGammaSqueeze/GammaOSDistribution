package com.android.keyguard.dagger;

import android.view.ViewGroup;
import com.android.keyguard.KeyguardHostView;
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
public final class KeyguardBouncerModule_ProvidesKeyguardHostViewFactory implements Factory<KeyguardHostView> {
  private final Provider<ViewGroup> rootViewProvider;

  public KeyguardBouncerModule_ProvidesKeyguardHostViewFactory(
      Provider<ViewGroup> rootViewProvider) {
    this.rootViewProvider = rootViewProvider;
  }

  @Override
  public KeyguardHostView get() {
    return providesKeyguardHostView(rootViewProvider.get());
  }

  public static KeyguardBouncerModule_ProvidesKeyguardHostViewFactory create(
      Provider<ViewGroup> rootViewProvider) {
    return new KeyguardBouncerModule_ProvidesKeyguardHostViewFactory(rootViewProvider);
  }

  public static KeyguardHostView providesKeyguardHostView(ViewGroup rootView) {
    return Preconditions.checkNotNullFromProvides(KeyguardBouncerModule.providesKeyguardHostView(rootView));
  }
}
