package com.android.systemui.statusbar.policy;

import com.android.internal.statusbar.IStatusBarService;
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
public final class RemoteInputUriController_Factory implements Factory<RemoteInputUriController> {
  private final Provider<IStatusBarService> statusBarServiceProvider;

  public RemoteInputUriController_Factory(Provider<IStatusBarService> statusBarServiceProvider) {
    this.statusBarServiceProvider = statusBarServiceProvider;
  }

  @Override
  public RemoteInputUriController get() {
    return newInstance(statusBarServiceProvider.get());
  }

  public static RemoteInputUriController_Factory create(
      Provider<IStatusBarService> statusBarServiceProvider) {
    return new RemoteInputUriController_Factory(statusBarServiceProvider);
  }

  public static RemoteInputUriController newInstance(IStatusBarService statusBarService) {
    return new RemoteInputUriController(statusBarService);
  }
}
