package com.android.systemui.media;

import android.content.Context;
import com.android.keyguard.KeyguardViewController;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.SysuiStatusBarStateController;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class MediaHierarchyManager_Factory implements Factory<MediaHierarchyManager> {
  private final Provider<Context> contextProvider;

  private final Provider<SysuiStatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<MediaCarouselController> mediaCarouselControllerProvider;

  private final Provider<NotificationLockscreenUserManager> notifLockscreenUserManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  private final Provider<KeyguardViewController> keyguardViewControllerProvider;

  public MediaHierarchyManager_Factory(Provider<Context> contextProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<MediaCarouselController> mediaCarouselControllerProvider,
      Provider<NotificationLockscreenUserManager> notifLockscreenUserManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<KeyguardViewController> keyguardViewControllerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.mediaCarouselControllerProvider = mediaCarouselControllerProvider;
    this.notifLockscreenUserManagerProvider = notifLockscreenUserManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
    this.keyguardViewControllerProvider = keyguardViewControllerProvider;
  }

  @Override
  public MediaHierarchyManager get() {
    return newInstance(contextProvider.get(), statusBarStateControllerProvider.get(), keyguardStateControllerProvider.get(), bypassControllerProvider.get(), mediaCarouselControllerProvider.get(), notifLockscreenUserManagerProvider.get(), configurationControllerProvider.get(), wakefulnessLifecycleProvider.get(), keyguardViewControllerProvider.get());
  }

  public static MediaHierarchyManager_Factory create(Provider<Context> contextProvider,
      Provider<SysuiStatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<MediaCarouselController> mediaCarouselControllerProvider,
      Provider<NotificationLockscreenUserManager> notifLockscreenUserManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider,
      Provider<KeyguardViewController> keyguardViewControllerProvider) {
    return new MediaHierarchyManager_Factory(contextProvider, statusBarStateControllerProvider, keyguardStateControllerProvider, bypassControllerProvider, mediaCarouselControllerProvider, notifLockscreenUserManagerProvider, configurationControllerProvider, wakefulnessLifecycleProvider, keyguardViewControllerProvider);
  }

  public static MediaHierarchyManager newInstance(Context context,
      SysuiStatusBarStateController statusBarStateController,
      KeyguardStateController keyguardStateController, KeyguardBypassController bypassController,
      MediaCarouselController mediaCarouselController,
      NotificationLockscreenUserManager notifLockscreenUserManager,
      ConfigurationController configurationController, WakefulnessLifecycle wakefulnessLifecycle,
      KeyguardViewController keyguardViewController) {
    return new MediaHierarchyManager(context, statusBarStateController, keyguardStateController, bypassController, mediaCarouselController, notifLockscreenUserManager, configurationController, wakefulnessLifecycle, keyguardViewController);
  }
}
