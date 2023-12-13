package com.android.systemui.statusbar.policy;

import android.view.accessibility.AccessibilityManager;
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
public final class AccessibilityManagerWrapper_Factory implements Factory<AccessibilityManagerWrapper> {
  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  public AccessibilityManagerWrapper_Factory(
      Provider<AccessibilityManager> accessibilityManagerProvider) {
    this.accessibilityManagerProvider = accessibilityManagerProvider;
  }

  @Override
  public AccessibilityManagerWrapper get() {
    return newInstance(accessibilityManagerProvider.get());
  }

  public static AccessibilityManagerWrapper_Factory create(
      Provider<AccessibilityManager> accessibilityManagerProvider) {
    return new AccessibilityManagerWrapper_Factory(accessibilityManagerProvider);
  }

  public static AccessibilityManagerWrapper newInstance(AccessibilityManager accessibilityManager) {
    return new AccessibilityManagerWrapper(accessibilityManager);
  }
}
