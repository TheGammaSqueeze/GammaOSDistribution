package com.android.keyguard.dagger;

import com.android.keyguard.KeyguardHostView;
import com.android.keyguard.KeyguardSecurityContainer;
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
public final class KeyguardBouncerModule_ProvidesKeyguardSecurityContainerFactory implements Factory<KeyguardSecurityContainer> {
  private final Provider<KeyguardHostView> hostViewProvider;

  public KeyguardBouncerModule_ProvidesKeyguardSecurityContainerFactory(
      Provider<KeyguardHostView> hostViewProvider) {
    this.hostViewProvider = hostViewProvider;
  }

  @Override
  public KeyguardSecurityContainer get() {
    return providesKeyguardSecurityContainer(hostViewProvider.get());
  }

  public static KeyguardBouncerModule_ProvidesKeyguardSecurityContainerFactory create(
      Provider<KeyguardHostView> hostViewProvider) {
    return new KeyguardBouncerModule_ProvidesKeyguardSecurityContainerFactory(hostViewProvider);
  }

  public static KeyguardSecurityContainer providesKeyguardSecurityContainer(
      KeyguardHostView hostView) {
    return Preconditions.checkNotNullFromProvides(KeyguardBouncerModule.providesKeyguardSecurityContainer(hostView));
  }
}
