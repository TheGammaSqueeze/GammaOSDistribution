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
public final class AccessibilityButtonTargetsObserver_Factory implements Factory<AccessibilityButtonTargetsObserver> {
  private final Provider<Context> contextProvider;

  public AccessibilityButtonTargetsObserver_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AccessibilityButtonTargetsObserver get() {
    return newInstance(contextProvider.get());
  }

  public static AccessibilityButtonTargetsObserver_Factory create(
      Provider<Context> contextProvider) {
    return new AccessibilityButtonTargetsObserver_Factory(contextProvider);
  }

  public static AccessibilityButtonTargetsObserver newInstance(Context context) {
    return new AccessibilityButtonTargetsObserver(context);
  }
}
