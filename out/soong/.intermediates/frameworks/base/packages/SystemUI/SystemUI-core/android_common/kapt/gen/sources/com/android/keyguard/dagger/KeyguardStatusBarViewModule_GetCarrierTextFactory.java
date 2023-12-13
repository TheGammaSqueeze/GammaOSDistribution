package com.android.keyguard.dagger;

import com.android.keyguard.CarrierText;
import com.android.systemui.statusbar.phone.KeyguardStatusBarView;
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
public final class KeyguardStatusBarViewModule_GetCarrierTextFactory implements Factory<CarrierText> {
  private final Provider<KeyguardStatusBarView> viewProvider;

  public KeyguardStatusBarViewModule_GetCarrierTextFactory(
      Provider<KeyguardStatusBarView> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public CarrierText get() {
    return getCarrierText(viewProvider.get());
  }

  public static KeyguardStatusBarViewModule_GetCarrierTextFactory create(
      Provider<KeyguardStatusBarView> viewProvider) {
    return new KeyguardStatusBarViewModule_GetCarrierTextFactory(viewProvider);
  }

  public static CarrierText getCarrierText(KeyguardStatusBarView view) {
    return Preconditions.checkNotNullFromProvides(KeyguardStatusBarViewModule.getCarrierText(view));
  }
}
