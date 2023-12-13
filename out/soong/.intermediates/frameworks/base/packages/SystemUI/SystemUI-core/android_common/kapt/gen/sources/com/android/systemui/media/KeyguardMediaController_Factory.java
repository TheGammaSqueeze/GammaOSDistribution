package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class KeyguardMediaController_Factory implements Factory<KeyguardMediaController> {
  private final Provider<MediaHost> mediaHostProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationLockscreenUserManager> notifLockscreenUserManagerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  public KeyguardMediaController_Factory(Provider<MediaHost> mediaHostProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationLockscreenUserManager> notifLockscreenUserManagerProvider,
      Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    this.mediaHostProvider = mediaHostProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notifLockscreenUserManagerProvider = notifLockscreenUserManagerProvider;
    this.contextProvider = contextProvider;
    this.configurationControllerProvider = configurationControllerProvider;
  }

  @Override
  public KeyguardMediaController get() {
    return newInstance(mediaHostProvider.get(), bypassControllerProvider.get(), statusBarStateControllerProvider.get(), notifLockscreenUserManagerProvider.get(), contextProvider.get(), configurationControllerProvider.get());
  }

  public static KeyguardMediaController_Factory create(Provider<MediaHost> mediaHostProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationLockscreenUserManager> notifLockscreenUserManagerProvider,
      Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    return new KeyguardMediaController_Factory(mediaHostProvider, bypassControllerProvider, statusBarStateControllerProvider, notifLockscreenUserManagerProvider, contextProvider, configurationControllerProvider);
  }

  public static KeyguardMediaController newInstance(MediaHost mediaHost,
      KeyguardBypassController bypassController,
      SysuiStatusBarStateController statusBarStateController,
      NotificationLockscreenUserManager notifLockscreenUserManager, Context context,
      ConfigurationController configurationController) {
    return new KeyguardMediaController(mediaHost, bypassController, statusBarStateController, notifLockscreenUserManager, context, configurationController);
  }
}
