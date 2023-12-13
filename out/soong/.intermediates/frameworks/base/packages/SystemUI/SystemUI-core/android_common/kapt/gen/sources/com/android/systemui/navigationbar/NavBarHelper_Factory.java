package com.android.systemui.navigationbar;

import android.content.Context;
import android.view.accessibility.AccessibilityManager;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.policy.AccessibilityManagerWrapper;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class NavBarHelper_Factory implements Factory<NavBarHelper> {
  private final Provider<Context> contextProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider;

  private final Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider;

  private final Provider<OverviewProxyService> overviewProxyServiceProvider;

  private final Provider<AssistManager> assistManagerLazyProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<NavigationModeController> navigationModeControllerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NavBarHelper_Factory(Provider<Context> contextProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.accessibilityManagerWrapperProvider = accessibilityManagerWrapperProvider;
    this.accessibilityButtonModeObserverProvider = accessibilityButtonModeObserverProvider;
    this.overviewProxyServiceProvider = overviewProxyServiceProvider;
    this.assistManagerLazyProvider = assistManagerLazyProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.navigationModeControllerProvider = navigationModeControllerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NavBarHelper get() {
    return newInstance(contextProvider.get(), accessibilityManagerProvider.get(), accessibilityManagerWrapperProvider.get(), accessibilityButtonModeObserverProvider.get(), overviewProxyServiceProvider.get(), DoubleCheck.lazy(assistManagerLazyProvider), DoubleCheck.lazy(statusBarOptionalLazyProvider), navigationModeControllerProvider.get(), userTrackerProvider.get(), dumpManagerProvider.get());
  }

  public static NavBarHelper_Factory create(Provider<Context> contextProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider,
      Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider,
      Provider<OverviewProxyService> overviewProxyServiceProvider,
      Provider<AssistManager> assistManagerLazyProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<NavigationModeController> navigationModeControllerProvider,
      Provider<UserTracker> userTrackerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new NavBarHelper_Factory(contextProvider, accessibilityManagerProvider, accessibilityManagerWrapperProvider, accessibilityButtonModeObserverProvider, overviewProxyServiceProvider, assistManagerLazyProvider, statusBarOptionalLazyProvider, navigationModeControllerProvider, userTrackerProvider, dumpManagerProvider);
  }

  public static NavBarHelper newInstance(Context context, AccessibilityManager accessibilityManager,
      AccessibilityManagerWrapper accessibilityManagerWrapper,
      AccessibilityButtonModeObserver accessibilityButtonModeObserver,
      OverviewProxyService overviewProxyService, Lazy<AssistManager> assistManagerLazy,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy,
      NavigationModeController navigationModeController, UserTracker userTracker,
      DumpManager dumpManager) {
    return new NavBarHelper(context, accessibilityManager, accessibilityManagerWrapper, accessibilityButtonModeObserver, overviewProxyService, assistManagerLazy, statusBarOptionalLazy, navigationModeController, userTracker, dumpManager);
  }
}
