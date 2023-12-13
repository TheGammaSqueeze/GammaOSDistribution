package com.android.systemui.statusbar.phone;

import com.android.systemui.unfold.SysUIUnfoldComponent;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class PhoneStatusBarViewController_Factory_Factory implements Factory<PhoneStatusBarViewController.Factory> {
  private final Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider;

  private final Provider<Optional<ScopedUnfoldTransitionProgressProvider>> progressProvider;

  public PhoneStatusBarViewController_Factory_Factory(
      Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider,
      Provider<Optional<ScopedUnfoldTransitionProgressProvider>> progressProvider) {
    this.unfoldComponentProvider = unfoldComponentProvider;
    this.progressProvider = progressProvider;
  }

  @Override
  public PhoneStatusBarViewController.Factory get() {
    return newInstance(unfoldComponentProvider.get(), progressProvider.get());
  }

  public static PhoneStatusBarViewController_Factory_Factory create(
      Provider<Optional<SysUIUnfoldComponent>> unfoldComponentProvider,
      Provider<Optional<ScopedUnfoldTransitionProgressProvider>> progressProvider) {
    return new PhoneStatusBarViewController_Factory_Factory(unfoldComponentProvider, progressProvider);
  }

  public static PhoneStatusBarViewController.Factory newInstance(
      Optional<SysUIUnfoldComponent> unfoldComponent,
      Optional<ScopedUnfoldTransitionProgressProvider> progressProvider) {
    return new PhoneStatusBarViewController.Factory(unfoldComponent, progressProvider);
  }
}
