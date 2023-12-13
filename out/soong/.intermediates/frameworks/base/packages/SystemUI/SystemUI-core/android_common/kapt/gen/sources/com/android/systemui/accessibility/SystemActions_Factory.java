package com.android.systemui.accessibility;

import android.content.Context;
import com.android.systemui.recents.Recents;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.phone.StatusBar;
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
public final class SystemActions_Factory implements Factory<SystemActions> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeControllerProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<Optional<Recents>> recentsOptionalProvider;

  public SystemActions_Factory(Provider<Context> contextProvider,
      Provider<NotificationShadeWindowController> notificationShadeControllerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<Optional<Recents>> recentsOptionalProvider) {
    this.contextProvider = contextProvider;
    this.notificationShadeControllerProvider = notificationShadeControllerProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.recentsOptionalProvider = recentsOptionalProvider;
  }

  @Override
  public SystemActions get() {
    return newInstance(contextProvider.get(), notificationShadeControllerProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), recentsOptionalProvider.get());
  }

  public static SystemActions_Factory create(Provider<Context> contextProvider,
      Provider<NotificationShadeWindowController> notificationShadeControllerProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<Optional<Recents>> recentsOptionalProvider) {
    return new SystemActions_Factory(contextProvider, notificationShadeControllerProvider, statusBarOptionalLazyProvider, recentsOptionalProvider);
  }

  public static SystemActions newInstance(Context context,
      NotificationShadeWindowController notificationShadeController,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy, Optional<Recents> recentsOptional) {
    return new SystemActions(context, notificationShadeController, statusBarOptionalLazy, recentsOptional);
  }
}
