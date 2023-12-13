package com.android.systemui.accessibility;

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
public final class AccessibilityButtonModeObserver_Factory implements Factory<AccessibilityButtonModeObserver> {
  private final Provider<Context> contextProvider;

  public AccessibilityButtonModeObserver_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AccessibilityButtonModeObserver get() {
    return newInstance(contextProvider.get());
  }

  public static AccessibilityButtonModeObserver_Factory create(Provider<Context> contextProvider) {
    return new AccessibilityButtonModeObserver_Factory(contextProvider);
  }

  public static AccessibilityButtonModeObserver newInstance(Context context) {
    return new AccessibilityButtonModeObserver(context);
  }
}
