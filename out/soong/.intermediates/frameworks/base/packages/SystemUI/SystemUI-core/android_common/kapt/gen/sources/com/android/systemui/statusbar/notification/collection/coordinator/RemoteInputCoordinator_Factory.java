package com.android.systemui.statusbar.notification.collection.coordinator;

import android.os.Handler;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.RemoteInputNotificationRebuilder;
import com.android.systemui.statusbar.SmartReplyController;
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
public final class RemoteInputCoordinator_Factory implements Factory<RemoteInputCoordinator> {
  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<RemoteInputNotificationRebuilder> mRebuilderProvider;

  private final Provider<NotificationRemoteInputManager> mNotificationRemoteInputManagerProvider;

  private final Provider<Handler> mMainHandlerProvider;

  private final Provider<SmartReplyController> mSmartReplyControllerProvider;

  public RemoteInputCoordinator_Factory(Provider<DumpManager> dumpManagerProvider,
      Provider<RemoteInputNotificationRebuilder> mRebuilderProvider,
      Provider<NotificationRemoteInputManager> mNotificationRemoteInputManagerProvider,
      Provider<Handler> mMainHandlerProvider,
      Provider<SmartReplyController> mSmartReplyControllerProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
    this.mRebuilderProvider = mRebuilderProvider;
    this.mNotificationRemoteInputManagerProvider = mNotificationRemoteInputManagerProvider;
    this.mMainHandlerProvider = mMainHandlerProvider;
    this.mSmartReplyControllerProvider = mSmartReplyControllerProvider;
  }

  @Override
  public RemoteInputCoordinator get() {
    return newInstance(dumpManagerProvider.get(), mRebuilderProvider.get(), mNotificationRemoteInputManagerProvider.get(), mMainHandlerProvider.get(), mSmartReplyControllerProvider.get());
  }

  public static RemoteInputCoordinator_Factory create(Provider<DumpManager> dumpManagerProvider,
      Provider<RemoteInputNotificationRebuilder> mRebuilderProvider,
      Provider<NotificationRemoteInputManager> mNotificationRemoteInputManagerProvider,
      Provider<Handler> mMainHandlerProvider,
      Provider<SmartReplyController> mSmartReplyControllerProvider) {
    return new RemoteInputCoordinator_Factory(dumpManagerProvider, mRebuilderProvider, mNotificationRemoteInputManagerProvider, mMainHandlerProvider, mSmartReplyControllerProvider);
  }

  public static RemoteInputCoordinator newInstance(DumpManager dumpManager,
      RemoteInputNotificationRebuilder mRebuilder,
      NotificationRemoteInputManager mNotificationRemoteInputManager, Handler mMainHandler,
      SmartReplyController mSmartReplyController) {
    return new RemoteInputCoordinator(dumpManager, mRebuilder, mNotificationRemoteInputManager, mMainHandler, mSmartReplyController);
  }
}
