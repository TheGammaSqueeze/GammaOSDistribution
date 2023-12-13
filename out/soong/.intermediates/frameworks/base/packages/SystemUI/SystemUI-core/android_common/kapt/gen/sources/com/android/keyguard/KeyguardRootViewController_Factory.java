package com.android.keyguard;

import android.view.ViewGroup;
import dagger.internal.Factory;
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
public final class KeyguardRootViewController_Factory implements Factory<KeyguardRootViewController> {
  private final Provider<ViewGroup> viewProvider;

  public KeyguardRootViewController_Factory(Provider<ViewGroup> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public KeyguardRootViewController get() {
    return newInstance(viewProvider.get());
  }

  public static KeyguardRootViewController_Factory create(Provider<ViewGroup> viewProvider) {
    return new KeyguardRootViewController_Factory(viewProvider);
  }

  public static KeyguardRootViewController newInstance(ViewGroup view) {
    return new KeyguardRootViewController(view);
  }
}
