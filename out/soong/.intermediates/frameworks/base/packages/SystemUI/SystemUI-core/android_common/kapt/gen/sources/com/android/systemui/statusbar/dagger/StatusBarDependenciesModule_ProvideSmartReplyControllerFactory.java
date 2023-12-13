package com.android.systemui.statusbar.dagger;

import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.NotificationClickNotifier;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
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
public final class StatusBarDependenciesModule_ProvideSmartReplyControllerFactory implements Factory<SmartReplyController> {
  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  private final Provider<NotificationClickNotifier> clickNotifierProvider;

  public StatusBarDependenciesModule_ProvideSmartReplyControllerFactory(
      Provider<DumpManager> dumpManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
    this.clickNotifierProvider = clickNotifierProvider;
  }

  @Override
  public SmartReplyController get() {
    return provideSmartReplyController(dumpManagerProvider.get(), entryManagerProvider.get(), statusBarServiceProvider.get(), clickNotifierProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideSmartReplyControllerFactory create(
      Provider<DumpManager> dumpManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<IStatusBarService> statusBarServiceProvider,
      Provider<NotificationClickNotifier> clickNotifierProvider) {
    return new StatusBarDependenciesModule_ProvideSmartReplyControllerFactory(dumpManagerProvider, entryManagerProvider, statusBarServiceProvider, clickNotifierProvider);
  }

  public static SmartReplyController provideSmartReplyController(DumpManager dumpManager,
      NotificationEntryManager entryManager, IStatusBarService statusBarService,
      NotificationClickNotifier clickNotifier) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideSmartReplyController(dumpManager, entryManager, statusBarService, clickNotifier));
  }
}
