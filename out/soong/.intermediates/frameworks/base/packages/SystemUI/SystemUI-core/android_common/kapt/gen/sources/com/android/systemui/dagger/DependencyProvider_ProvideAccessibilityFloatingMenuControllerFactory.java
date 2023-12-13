package com.android.systemui.dagger;

import android.content.Context;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver;
import com.android.systemui.accessibility.AccessibilityButtonTargetsObserver;
import com.android.systemui.accessibility.floatingmenu.AccessibilityFloatingMenuController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class DependencyProvider_ProvideAccessibilityFloatingMenuControllerFactory implements Factory<AccessibilityFloatingMenuController> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  private final Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider;

  private final Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  public DependencyProvider_ProvideAccessibilityFloatingMenuControllerFactory(
      DependencyProvider module, Provider<Context> contextProvider,
      Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
    this.accessibilityButtonTargetsObserverProvider = accessibilityButtonTargetsObserverProvider;
    this.accessibilityButtonModeObserverProvider = accessibilityButtonModeObserverProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
  }

  @Override
  public AccessibilityFloatingMenuController get() {
    return provideAccessibilityFloatingMenuController(module, contextProvider.get(), accessibilityButtonTargetsObserverProvider.get(), accessibilityButtonModeObserverProvider.get(), keyguardUpdateMonitorProvider.get());
  }

  public static DependencyProvider_ProvideAccessibilityFloatingMenuControllerFactory create(
      DependencyProvider module, Provider<Context> contextProvider,
      Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider) {
    return new DependencyProvider_ProvideAccessibilityFloatingMenuControllerFactory(module, contextProvider, accessibilityButtonTargetsObserverProvider, accessibilityButtonModeObserverProvider, keyguardUpdateMonitorProvider);
  }

  public static AccessibilityFloatingMenuController provideAccessibilityFloatingMenuController(
      DependencyProvider instance, Context context,
      AccessibilityButtonTargetsObserver accessibilityButtonTargetsObserver,
      AccessibilityButtonModeObserver accessibilityButtonModeObserver,
      KeyguardUpdateMonitor keyguardUpdateMonitor) {
    return Preconditions.checkNotNullFromProvides(instance.provideAccessibilityFloatingMenuController(context, accessibilityButtonTargetsObserver, accessibilityButtonModeObserver, keyguardUpdateMonitor));
  }
}
