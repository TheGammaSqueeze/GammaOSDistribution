package com.android.systemui.statusbar.events;

import android.content.Context;
import com.android.systemui.statusbar.phone.StatusBarLocationPublisher;
import com.android.systemui.statusbar.window.StatusBarWindowController;
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
public final class SystemEventChipAnimationController_Factory implements Factory<SystemEventChipAnimationController> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarWindowController> statusBarWindowControllerProvider;

  private final Provider<StatusBarLocationPublisher> locationPublisherProvider;

  public SystemEventChipAnimationController_Factory(Provider<Context> contextProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<StatusBarLocationPublisher> locationPublisherProvider) {
    this.contextProvider = contextProvider;
    this.statusBarWindowControllerProvider = statusBarWindowControllerProvider;
    this.locationPublisherProvider = locationPublisherProvider;
  }

  @Override
  public SystemEventChipAnimationController get() {
    return newInstance(contextProvider.get(), statusBarWindowControllerProvider.get(), locationPublisherProvider.get());
  }

  public static SystemEventChipAnimationController_Factory create(Provider<Context> contextProvider,
      Provider<StatusBarWindowController> statusBarWindowControllerProvider,
      Provider<StatusBarLocationPublisher> locationPublisherProvider) {
    return new SystemEventChipAnimationController_Factory(contextProvider, statusBarWindowControllerProvider, locationPublisherProvider);
  }

  public static SystemEventChipAnimationController newInstance(Context context,
      StatusBarWindowController statusBarWindowController,
      StatusBarLocationPublisher locationPublisher) {
    return new SystemEventChipAnimationController(context, statusBarWindowController, locationPublisher);
  }
}
