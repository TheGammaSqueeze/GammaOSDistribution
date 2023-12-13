package com.android.systemui.navigationbar;

import android.content.Context;
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
public final class NavigationBarOverlayController_Factory implements Factory<NavigationBarOverlayController> {
  private final Provider<Context> contextProvider;

  public NavigationBarOverlayController_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public NavigationBarOverlayController get() {
    return newInstance(contextProvider.get());
  }

  public static NavigationBarOverlayController_Factory create(Provider<Context> contextProvider) {
    return new NavigationBarOverlayController_Factory(contextProvider);
  }

  public static NavigationBarOverlayController newInstance(Context context) {
    return new NavigationBarOverlayController(context);
  }
}
