package com.android.systemui.statusbar.notification.interruption;

import android.content.Context;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.tuner.TunerService;
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
public final class BypassHeadsUpNotifier_Factory implements Factory<BypassHeadsUpNotifier> {
  private final Provider<Context> contextProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<HeadsUpManagerPhone> headsUpManagerProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<NotificationMediaManager> mediaManagerProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  public BypassHeadsUpNotifier_Factory(Provider<Context> contextProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationMediaManager> mediaManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<TunerService> tunerServiceProvider) {
    this.contextProvider = contextProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.mediaManagerProvider = mediaManagerProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
  }

  @Override
  public BypassHeadsUpNotifier get() {
    return newInstance(contextProvider.get(), bypassControllerProvider.get(), statusBarStateControllerProvider.get(), headsUpManagerProvider.get(), notificationLockscreenUserManagerProvider.get(), mediaManagerProvider.get(), entryManagerProvider.get(), tunerServiceProvider.get());
  }

  public static BypassHeadsUpNotifier_Factory create(Provider<Context> contextProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<HeadsUpManagerPhone> headsUpManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotificationMediaManager> mediaManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<TunerService> tunerServiceProvider) {
    return new BypassHeadsUpNotifier_Factory(contextProvider, bypassControllerProvider, statusBarStateControllerProvider, headsUpManagerProvider, notificationLockscreenUserManagerProvider, mediaManagerProvider, entryManagerProvider, tunerServiceProvider);
  }

  public static BypassHeadsUpNotifier newInstance(Context context,
      KeyguardBypassController bypassController, StatusBarStateController statusBarStateController,
      HeadsUpManagerPhone headsUpManager,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      NotificationMediaManager mediaManager, NotificationEntryManager entryManager,
      TunerService tunerService) {
    return new BypassHeadsUpNotifier(context, bypassController, statusBarStateController, headsUpManager, notificationLockscreenUserManager, mediaManager, entryManager, tunerService);
  }
}
