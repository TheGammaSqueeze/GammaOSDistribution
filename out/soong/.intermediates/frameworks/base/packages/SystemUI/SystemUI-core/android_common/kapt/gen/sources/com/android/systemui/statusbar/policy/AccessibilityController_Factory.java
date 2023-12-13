package com.android.systemui.statusbar.policy;

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
public final class AccessibilityController_Factory implements Factory<AccessibilityController> {
  private final Provider<Context> contextProvider;

  public AccessibilityController_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AccessibilityController get() {
    return newInstance(contextProvider.get());
  }

  public static AccessibilityController_Factory create(Provider<Context> contextProvider) {
    return new AccessibilityController_Factory(contextProvider);
  }

  public static AccessibilityController newInstance(Context context) {
    return new AccessibilityController(context);
  }
}
