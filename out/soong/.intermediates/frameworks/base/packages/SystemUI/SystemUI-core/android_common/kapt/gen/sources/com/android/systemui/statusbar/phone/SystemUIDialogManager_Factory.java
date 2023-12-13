package com.android.systemui.statusbar.phone;

import com.android.systemui.dump.DumpManager;
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
public final class SystemUIDialogManager_Factory implements Factory<SystemUIDialogManager> {
  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  public SystemUIDialogManager_Factory(Provider<DumpManager> dumpManagerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
  }

  @Override
  public SystemUIDialogManager get() {
    return newInstance(dumpManagerProvider.get(), statusBarKeyguardViewManagerProvider.get());
  }

  public static SystemUIDialogManager_Factory create(Provider<DumpManager> dumpManagerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider) {
    return new SystemUIDialogManager_Factory(dumpManagerProvider, statusBarKeyguardViewManagerProvider);
  }

  public static SystemUIDialogManager newInstance(DumpManager dumpManager,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager) {
    return new SystemUIDialogManager(dumpManager, statusBarKeyguardViewManager);
  }
}
