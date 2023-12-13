package com.android.systemui.accessibility.floatingmenu;

import android.content.Context;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver;
import com.android.systemui.accessibility.AccessibilityButtonTargetsObserver;
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
public final class AccessibilityFloatingMenuController_Factory implements Factory<AccessibilityFloatingMenuController> {
  private final Provider<Context> contextProvider;

  private final Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider;

  private final Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public AccessibilityFloatingMenuController_Factory(Provider<Context> contextProvider,
      Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.contextProvider = contextProvider;
    this.accessibilityButtonTargetsObserverProvider = accessibilityButtonTargetsObserverProvider;
    this.accessibilityButtonModeObserverProvider = accessibilityButtonModeObserverProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public AccessibilityFloatingMenuController get() {
    return newInstance(contextProvider.get(), accessibilityButtonTargetsObserverProvider.get(), accessibilityButtonModeObserverProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static AccessibilityFloatingMenuController_Factory create(
      Provider<Context> contextProvider,
      Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new AccessibilityFloatingMenuController_Factory(contextProvider, accessibilityButtonTargetsObserverProvider, accessibilityButtonModeObserverProvider, keyguardUpdateMonitorProvider);
  }

  public static AccessibilityFloatingMenuController newInstance(Context context,
      AccessibilityButtonTargetsObserver accessibilityButtonTargetsObserver,
      AccessibilityButtonModeObserver accessibilityButtonModeObserver,
      KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return new AccessibilityFloatingMenuController(context, accessibilityButtonTargetsObserver, accessibilityButtonModeObserver, keyguardUpdateMonitor);
  }
}
