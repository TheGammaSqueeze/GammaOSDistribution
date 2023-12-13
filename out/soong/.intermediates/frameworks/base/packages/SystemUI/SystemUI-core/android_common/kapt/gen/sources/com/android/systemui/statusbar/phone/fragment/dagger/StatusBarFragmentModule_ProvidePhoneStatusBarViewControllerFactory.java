package com.android.systemui.statusbar.phone.fragment.dagger;

import com.android.systemui.statusbar.phone.NotificationPanelViewController;
import com.android.systemui.statusbar.phone.PhoneStatusBarView;
import com.android.systemui.statusbar.phone.PhoneStatusBarViewController;
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
public final class StatusBarFragmentModule_ProvidePhoneStatusBarViewControllerFactory implements Factory<PhoneStatusBarViewController> {
  private final Provider<PhoneStatusBarViewController.Factory> phoneStatusBarViewControllerFactoryProvider;

  private final Provider<PhoneStatusBarView> phoneStatusBarViewProvider;

  private final Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

  public StatusBarFragmentModule_ProvidePhoneStatusBarViewControllerFactory(
      Provider<PhoneStatusBarViewController.Factory> phoneStatusBarViewControllerFactoryProvider,
      Provider<PhoneStatusBarView> phoneStatusBarViewProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider) {
    this.phoneStatusBarViewControllerFactoryProvider = phoneStatusBarViewControllerFactoryProvider;
    this.phoneStatusBarViewProvider = phoneStatusBarViewProvider;
    this.notificationPanelViewControllerProvider = notificationPanelViewControllerProvider;
  }

  @Override
  public PhoneStatusBarViewController get() {
    return providePhoneStatusBarViewController(phoneStatusBarViewControllerFactoryProvider.get(), phoneStatusBarViewProvider.get(), notificationPanelViewControllerProvider.get());
  }

  public static StatusBarFragmentModule_ProvidePhoneStatusBarViewControllerFactory create(
      Provider<PhoneStatusBarViewController.Factory> phoneStatusBarViewControllerFactoryProvider,
      Provider<PhoneStatusBarView> phoneStatusBarViewProvider,
      Provider<NotificationPanelViewController> notificationPanelViewControllerProvider) {
    return new StatusBarFragmentModule_ProvidePhoneStatusBarViewControllerFactory(phoneStatusBarViewControllerFactoryProvider, phoneStatusBarViewProvider, notificationPanelViewControllerProvider);
  }

  public static PhoneStatusBarViewController providePhoneStatusBarViewController(
      PhoneStatusBarViewController.Factory phoneStatusBarViewControllerFactory,
      PhoneStatusBarView phoneStatusBarView,
      NotificationPanelViewController notificationPanelViewController) {
    return Preconditions.checkNotNullFromProvides(StatusBarFragmentModule.providePhoneStatusBarViewController(phoneStatusBarViewControllerFactory, phoneStatusBarView, notificationPanelViewController));
  }
}
