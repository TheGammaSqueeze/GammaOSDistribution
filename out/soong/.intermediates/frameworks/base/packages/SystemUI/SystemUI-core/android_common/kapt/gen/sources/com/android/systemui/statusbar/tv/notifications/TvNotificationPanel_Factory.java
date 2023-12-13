package com.android.systemui.statusbar.tv.notifications;

import android.content.Context;
import com.android.systemui.statusbar.CommandQueue;
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
public final class TvNotificationPanel_Factory implements Factory<TvNotificationPanel> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  public TvNotificationPanel_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
  }

  @Override
  public TvNotificationPanel get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get());
  }

  public static TvNotificationPanel_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider) {
    return new TvNotificationPanel_Factory(contextProvider, commandQueueProvider);
  }

  public static TvNotificationPanel newInstance(Context context, CommandQueue commandQueue) {
    return new TvNotificationPanel(context, commandQueue);
  }
}
