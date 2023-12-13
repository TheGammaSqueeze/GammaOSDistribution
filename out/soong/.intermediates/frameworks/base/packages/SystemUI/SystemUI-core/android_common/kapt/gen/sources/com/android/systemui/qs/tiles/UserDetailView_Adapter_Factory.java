package com.android.systemui.qs.tiles;

import android.content.Context;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.policy.UserSwitcherController;
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
public final class UserDetailView_Adapter_Factory implements Factory<UserDetailView.Adapter> {
  private final Provider<Context> contextProvider;

  private final Provider<UserSwitcherController> controllerProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  public UserDetailView_Adapter_Factory(Provider<Context> contextProvider,
      Provider<UserSwitcherController> controllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider) {
    this.contextProvider = contextProvider;
    this.controllerProvider = controllerProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
  }

  @Override
  public UserDetailView.Adapter get() {
    return newInstance(contextProvider.get(), controllerProvider.get(), uiEventLoggerProvider.get(), falsingManagerProvider.get());
  }

  public static UserDetailView_Adapter_Factory create(Provider<Context> contextProvider,
      Provider<UserSwitcherController> controllerProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider) {
    return new UserDetailView_Adapter_Factory(contextProvider, controllerProvider, uiEventLoggerProvider, falsingManagerProvider);
  }

  public static UserDetailView.Adapter newInstance(Context context,
      UserSwitcherController controller, UiEventLogger uiEventLogger,
      FalsingManager falsingManager) {
    return new UserDetailView.Adapter(context, controller, uiEventLogger, falsingManager);
  }
}
