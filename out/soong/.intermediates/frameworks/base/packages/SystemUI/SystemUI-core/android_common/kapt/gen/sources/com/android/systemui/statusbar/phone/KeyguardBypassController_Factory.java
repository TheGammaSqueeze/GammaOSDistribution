package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.policy.KeyguardStateController;
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
public final class KeyguardBypassController_Factory implements Factory<KeyguardBypassController> {
  private final Provider<Context> contextProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider;

  private final Provider<KeyguardStateController> keyguardStateControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public KeyguardBypassController_Factory(Provider<Context> contextProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.lockscreenUserManagerProvider = lockscreenUserManagerProvider;
    this.keyguardStateControllerProvider = keyguardStateControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public KeyguardBypassController get() {
    return newInstance(contextProvider.get(), tunerServiceProvider.get(), statusBarStateControllerProvider.get(), lockscreenUserManagerProvider.get(), keyguardStateControllerProvider.get(), dumpManagerProvider.get());
  }

  public static KeyguardBypassController_Factory create(Provider<Context> contextProvider,
      Provider<TunerService> tunerServiceProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationLockscreenUserManager> lockscreenUserManagerProvider,
      Provider<KeyguardStateController> keyguardStateControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new KeyguardBypassController_Factory(contextProvider, tunerServiceProvider, statusBarStateControllerProvider, lockscreenUserManagerProvider, keyguardStateControllerProvider, dumpManagerProvider);
  }

  public static KeyguardBypassController newInstance(Context context, TunerService tunerService,
      StatusBarStateController statusBarStateController,
      NotificationLockscreenUserManager lockscreenUserManager,
      KeyguardStateController keyguardStateController, DumpManager dumpManager) {
    return new KeyguardBypassController(context, tunerService, statusBarStateController, lockscreenUserManager, keyguardStateController, dumpManager);
  }
}
