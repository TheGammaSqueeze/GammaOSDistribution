package com.android.systemui.statusbar.phone;

import android.content.Context;
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
public final class AutoHideController_Factory implements Factory<AutoHideController> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<IWindowManager> iWindowManagerProvider;

  public AutoHideController_Factory(Provider<Context> contextProvider,
      Provider<Handler> handlerProvider, Provider<IWindowManager> iWindowManagerProvider) {
    this.contextProvider = contextProvider;
    this.handlerProvider = handlerProvider;
    this.iWindowManagerProvider = iWindowManagerProvider;
  }

  @Override
  public AutoHideController get() {
    return newInstance(contextProvider.get(), handlerProvider.get(), iWindowManagerProvider.get());
  }

  public static AutoHideController_Factory create(Provider<Context> contextProvider,
      Provider<Handler> handlerProvider, Provider<IWindowManager> iWindowManagerProvider) {
    return new AutoHideController_Factory(contextProvider, handlerProvider, iWindowManagerProvider);
  }

  public static AutoHideController newInstance(Context context, Handler handler,
      IWindowManager iWindowManager) {
    return new AutoHideController(context, handler, iWindowManager);
  }
}
