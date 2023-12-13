package com.android.keyguard;

import android.view.LayoutInflater;
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
public final class KeyguardSecurityViewFlipperController_Factory implements Factory<KeyguardSecurityViewFlipperController> {
  private final Provider<KeyguardSecurityViewFlipper> viewProvider;

  private final Provider<LayoutInflater> layoutInflaterProvider;

  private final Provider<KeyguardInputViewController.Factory> keyguardSecurityViewControllerFactoryProvider;

  private final Provider<EmergencyButtonController.Factory> emergencyButtonControllerFactoryProvider;

  public KeyguardSecurityViewFlipperController_Factory(
      Provider<KeyguardSecurityViewFlipper> viewProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<KeyguardInputViewController.Factory> keyguardSecurityViewControllerFactoryProvider,
      Provider<EmergencyButtonController.Factory> emergencyButtonControllerFactoryProvider) {
    this.viewProvider = viewProvider;
    this.layoutInflaterProvider = layoutInflaterProvider;
    this.keyguardSecurityViewControllerFactoryProvider = keyguardSecurityViewControllerFactoryProvider;
    this.emergencyButtonControllerFactoryProvider = emergencyButtonControllerFactoryProvider;
  }

  @Override
  public KeyguardSecurityViewFlipperController get() {
    return newInstance(viewProvider.get(), layoutInflaterProvider.get(), keyguardSecurityViewControllerFactoryProvider.get(), emergencyButtonControllerFactoryProvider.get());
  }

  public static KeyguardSecurityViewFlipperController_Factory create(
      Provider<KeyguardSecurityViewFlipper> viewProvider,
      Provider<LayoutInflater> layoutInflaterProvider,
      Provider<KeyguardInputViewController.Factory> keyguardSecurityViewControllerFactoryProvider,
      Provider<EmergencyButtonController.Factory> emergencyButtonControllerFactoryProvider) {
    return new KeyguardSecurityViewFlipperController_Factory(viewProvider, layoutInflaterProvider, keyguardSecurityViewControllerFactoryProvider, emergencyButtonControllerFactoryProvider);
  }

  public static KeyguardSecurityViewFlipperController newInstance(KeyguardSecurityViewFlipper view,
      LayoutInflater layoutInflater,
      KeyguardInputViewController.Factory keyguardSecurityViewControllerFactory,
      EmergencyButtonController.Factory emergencyButtonControllerFactory) {
    return new KeyguardSecurityViewFlipperController(view, layoutInflater, keyguardSecurityViewControllerFactory, emergencyButtonControllerFactory);
  }
}
