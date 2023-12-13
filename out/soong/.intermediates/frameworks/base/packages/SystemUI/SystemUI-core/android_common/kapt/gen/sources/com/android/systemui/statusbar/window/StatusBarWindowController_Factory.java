package com.android.systemui.statusbar.window;

import android.content.Context;
import android.content.res.Resources;
import android.view.IWindowManager;
import android.view.WindowManager;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider;
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
public final class StatusBarWindowController_Factory implements Factory<StatusBarWindowController> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarWindowView> statusBarWindowViewProvider;

  private final Provider<WindowManager> windowManagerProvider;

  private final Provider<IWindowManager> iWindowManagerProvider;

  private final Provider<StatusBarContentInsetsProvider> contentInsetsProvider;

  private final Provider<Resources> resourcesProvider;

  public StatusBarWindowController_Factory(Provider<Context> contextProvider,
      Provider<StatusBarWindowView> statusBarWindowViewProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<IWindowManager> iWindowManagerProvider,
      Provider<StatusBarContentInsetsProvider> contentInsetsProvider,
      Provider<Resources> resourcesProvider) {
    this.contextProvider = contextProvider;
    this.statusBarWindowViewProvider = statusBarWindowViewProvider;
    this.windowManagerProvider = windowManagerProvider;
    this.iWindowManagerProvider = iWindowManagerProvider;
    this.contentInsetsProvider = contentInsetsProvider;
    this.resourcesProvider = resourcesProvider;
  }

  @Override
  public StatusBarWindowController get() {
    return newInstance(contextProvider.get(), statusBarWindowViewProvider.get(), windowManagerProvider.get(), iWindowManagerProvider.get(), contentInsetsProvider.get(), resourcesProvider.get());
  }

  public static StatusBarWindowController_Factory create(Provider<Context> contextProvider,
      Provider<StatusBarWindowView> statusBarWindowViewProvider,
      Provider<WindowManager> windowManagerProvider,
      Provider<IWindowManager> iWindowManagerProvider,
      Provider<StatusBarContentInsetsProvider> contentInsetsProvider,
      Provider<Resources> resourcesProvider) {
    return new StatusBarWindowController_Factory(contextProvider, statusBarWindowViewProvider, windowManagerProvider, iWindowManagerProvider, contentInsetsProvider, resourcesProvider);
  }

  public static StatusBarWindowController newInstance(Context context,
      StatusBarWindowView statusBarWindowView, WindowManager windowManager,
      IWindowManager iWindowManager, StatusBarContentInsetsProvider contentInsetsProvider,
      Resources resources) {
    return new StatusBarWindowController(context, statusBarWindowView, windowManager, iWindowManager, contentInsetsProvider, resources);
  }
}
