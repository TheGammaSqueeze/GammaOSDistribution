package com.android.systemui.statusbar.phone;

import android.view.WindowManager;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
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
public final class LightsOutNotifController_Factory implements Factory<LightsOutNotifController> {
  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  public LightsOutNotifController_Factory(Provider<WindowManager> windowManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<CommandQueue> commandQueueProvider) {
    this.windowManagerProvider = windowManagerProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.commandQueueProvider = commandQueueProvider;
  }

  @Override
  public LightsOutNotifController get() {
    return newInstance(windowManagerProvider.get(), entryManagerProvider.get(), commandQueueProvider.get());
  }

  public static LightsOutNotifController_Factory create(
      Provider<WindowManager> windowManagerProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<CommandQueue> commandQueueProvider) {
    return new LightsOutNotifController_Factory(windowManagerProvider, entryManagerProvider, commandQueueProvider);
  }

  public static LightsOutNotifController newInstance(WindowManager windowManager,
      NotificationEntryManager entryManager, CommandQueue commandQueue) {
    return new LightsOutNotifController(windowManager, entryManager, commandQueue);
  }
}
