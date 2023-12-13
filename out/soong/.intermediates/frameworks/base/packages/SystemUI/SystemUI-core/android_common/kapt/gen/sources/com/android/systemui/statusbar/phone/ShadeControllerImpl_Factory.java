package com.android.systemui.statusbar.phone;

import android.view.WindowManager;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.wm.shell.bubbles.Bubbles;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class ShadeControllerImpl_Factory implements Factory<ShadeControllerImpl> {
  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<AssistManager> assistManagerLazyProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  public ShadeControllerImpl_Factory(Provider<CommandQueue> commandQueueProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider) {
    this.commandQueueProvider = commandQueueProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.statusBarKeyguardViewManagerProvider = statusBarKeyguardViewManagerProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.assistManagerLazyProvider = assistManagerLazyProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
  }

  @Override
  public ShadeControllerImpl get() {
    return newInstance(commandQueueProvider.get(), statusBarStateControllerProvider.get(), notificationShadeWindowControllerProvider.get(), statusBarKeyguardViewManagerProvider.get(), windowManagerProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), DoubleCheck.lazy(assistManagerLazyProvider), bubblesOptionalProvider.get());
  }

  public static ShadeControllerImpl_Factory create(Provider<CommandQueue> commandQueueProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider) {
    return new ShadeControllerImpl_Factory(commandQueueProvider, statusBarStateControllerProvider, notificationShadeWindowControllerProvider, statusBarKeyguardViewManagerProvider, windowManagerProvider, statusBarOptionalLazyProvider, assistManagerLazyProvider, bubblesOptionalProvider);
  }

  public static ShadeControllerImpl newInstance(CommandQueue commandQueue,
      StatusBarStateController statusBarStateController,
      NotificationShadeWindowController notificationShadeWindowController,
      StatusBarKeyguardViewManager statusBarKeyguardViewManager, WindowManager windowManager,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy, Lazy<AssistManager> assistManagerLazy,
      Optional<Bubbles> bubblesOptional) {
    return new ShadeControllerImpl(commandQueue, statusBarStateController, notificationShadeWindowController, statusBarKeyguardViewManager, windowManager, statusBarOptionalLazy, assistManagerLazy, bubblesOptional);
  }
}
