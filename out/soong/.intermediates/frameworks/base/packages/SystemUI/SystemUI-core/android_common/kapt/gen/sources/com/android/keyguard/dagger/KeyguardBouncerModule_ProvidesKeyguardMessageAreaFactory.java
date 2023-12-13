package com.android.keyguard.dagger;

import android.view.ViewGroup;
import com.android.keyguard.KeyguardMessageArea;
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
public final class KeyguardBouncerModule_ProvidesKeyguardMessageAreaFactory implements Factory<KeyguardMessageArea> {
  private final Provider<ViewGroup> viewGroupProvider;

  public KeyguardBouncerModule_ProvidesKeyguardMessageAreaFactory(
      Provider<ViewGroup> viewGroupProvider) {
    this.viewGroupProvider = viewGroupProvider;
  }

  @Override
  public KeyguardMessageArea get() {
    return providesKeyguardMessageArea(viewGroupProvider.get());
  }

  public static KeyguardBouncerModule_ProvidesKeyguardMessageAreaFactory create(
      Provider<ViewGroup> viewGroupProvider) {
    return new KeyguardBouncerModule_ProvidesKeyguardMessageAreaFactory(viewGroupProvider);
  }

  public static KeyguardMessageArea providesKeyguardMessageArea(ViewGroup viewGroup) {
    return Preconditions.checkNotNullFromProvides(KeyguardBouncerModule.providesKeyguardMessageArea(viewGroup));
  }
}
