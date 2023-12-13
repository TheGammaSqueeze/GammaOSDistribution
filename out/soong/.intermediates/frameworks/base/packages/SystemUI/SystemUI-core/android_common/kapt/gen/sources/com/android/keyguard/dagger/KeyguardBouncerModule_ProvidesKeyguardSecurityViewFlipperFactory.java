package com.android.keyguard.dagger;

import com.android.keyguard.KeyguardSecurityContainer;
import com.android.keyguard.KeyguardSecurityViewFlipper;
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
public final class KeyguardBouncerModule_ProvidesKeyguardSecurityViewFlipperFactory implements Factory<KeyguardSecurityViewFlipper> {
  private final Provider<KeyguardSecurityContainer> containerViewProvider;

  public KeyguardBouncerModule_ProvidesKeyguardSecurityViewFlipperFactory(
      Provider<KeyguardSecurityContainer> containerViewProvider) {
    this.containerViewProvider = containerViewProvider;
  }

  @Override
  public KeyguardSecurityViewFlipper get() {
    return providesKeyguardSecurityViewFlipper(containerViewProvider.get());
  }

  public static KeyguardBouncerModule_ProvidesKeyguardSecurityViewFlipperFactory create(
      Provider<KeyguardSecurityContainer> containerViewProvider) {
    return new KeyguardBouncerModule_ProvidesKeyguardSecurityViewFlipperFactory(containerViewProvider);
  }

  public static KeyguardSecurityViewFlipper providesKeyguardSecurityViewFlipper(
      KeyguardSecurityContainer containerView) {
    return Preconditions.checkNotNullFromProvides(KeyguardBouncerModule.providesKeyguardSecurityViewFlipper(containerView));
  }
}
