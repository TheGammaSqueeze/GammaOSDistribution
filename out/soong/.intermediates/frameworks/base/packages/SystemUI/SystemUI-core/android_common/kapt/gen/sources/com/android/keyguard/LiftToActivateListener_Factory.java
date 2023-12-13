package com.android.keyguard;

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
public final class LiftToActivateListener_Factory implements Factory<LiftToActivateListener> {
  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  public LiftToActivateListener_Factory(
      Provider<AccessibilityManager> accessibilityManagerProvider) {
    this.accessibilityManagerProvider = accessibilityManagerProvider;
  }

  @Override
  public LiftToActivateListener get() {
    return newInstance(accessibilityManagerProvider.get());
  }

  public static LiftToActivateListener_Factory create(
      Provider<AccessibilityManager> accessibilityManagerProvider) {
    return new LiftToActivateListener_Factory(accessibilityManagerProvider);
  }

  public static LiftToActivateListener newInstance(AccessibilityManager accessibilityManager) {
    return new LiftToActivateListener(accessibilityManager);
  }
}
