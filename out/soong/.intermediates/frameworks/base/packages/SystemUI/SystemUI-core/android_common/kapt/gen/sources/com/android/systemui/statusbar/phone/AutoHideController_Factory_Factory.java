package com.android.systemui.statusbar.phone;

import android.os.Handler;
import android.view.IWindowManager;
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
public final class AutoHideController_Factory_Factory implements Factory<AutoHideController.Factory> {
  private final Provider<Handler> handlerProvider;

  private final Provider<IWindowManager> iWindowManagerProvider;

  public AutoHideController_Factory_Factory(Provider<Handler> handlerProvider,
      Provider<IWindowManager> iWindowManagerProvider) {
    this.handlerProvider = handlerProvider;
    this.iWindowManagerProvider = iWindowManagerProvider;
  }

  @Override
  public AutoHideController.Factory get() {
    return newInstance(handlerProvider.get(), iWindowManagerProvider.get());
  }

  public static AutoHideController_Factory_Factory create(Provider<Handler> handlerProvider,
      Provider<IWindowManager> iWindowManagerProvider) {
    return new AutoHideController_Factory_Factory(handlerProvider, iWindowManagerProvider);
  }

  public static AutoHideController.Factory newInstance(Handler handler,
      IWindowManager iWindowManager) {
    return new AutoHideController.Factory(handler, iWindowManager);
  }
}
