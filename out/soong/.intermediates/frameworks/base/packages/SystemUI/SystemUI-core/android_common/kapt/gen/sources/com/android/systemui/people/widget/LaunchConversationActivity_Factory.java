package com.android.systemui.people.widget;

import android.os.UserManager;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.wmshell.BubblesManager;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class LaunchConversationActivity_Factory implements Factory<LaunchConversationActivity> {
  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  public LaunchConversationActivity_Factory(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<UserManager> userManagerProvider, Provider<CommandQueue> commandQueueProvider) {
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.bubblesManagerOptionalProvider = bubblesManagerOptionalProvider;
    this.userManagerProvider = userManagerProvider;
    this.commandQueueProvider = commandQueueProvider;
  }

  @Override
  public LaunchConversationActivity get() {
    return newInstance(notificationEntryManagerProvider.get(), bubblesManagerOptionalProvider.get(), userManagerProvider.get(), commandQueueProvider.get());
  }

  public static LaunchConversationActivity_Factory create(
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<UserManager> userManagerProvider, Provider<CommandQueue> commandQueueProvider) {
    return new LaunchConversationActivity_Factory(notificationEntryManagerProvider, bubblesManagerOptionalProvider, userManagerProvider, commandQueueProvider);
  }

  public static LaunchConversationActivity newInstance(
      NotificationEntryManager notificationEntryManager,
      Optional<BubblesManager> bubblesManagerOptional, UserManager userManager,
      CommandQueue commandQueue) {
    return new LaunchConversationActivity(notificationEntryManager, bubblesManagerOptional, userManager, commandQueue);
  }
}
