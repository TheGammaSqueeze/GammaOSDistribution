package com.android.systemui.statusbar.policy.dagger;

import android.os.UserManager;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.connectivity.AccessPointControllerImpl;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import java.util.concurrent.Executor;
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
public final class StatusBarPolicyModule_ProvideAccessPointControllerImplFactory implements Factory<AccessPointControllerImpl> {
  private final Provider<UserManager> userManagerProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<Executor> mainExecutorProvider;

  private final Provider<AccessPointControllerImpl.WifiPickerTrackerFactory> wifiPickerTrackerFactoryProvider;

  public StatusBarPolicyModule_ProvideAccessPointControllerImplFactory(
      Provider<UserManager> userManagerProvider, Provider<UserTracker> userTrackerProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<AccessPointControllerImpl.WifiPickerTrackerFactory> wifiPickerTrackerFactoryProvider) {
    this.userManagerProvider = userManagerProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.wifiPickerTrackerFactoryProvider = wifiPickerTrackerFactoryProvider;
  }

  @Override
  public AccessPointControllerImpl get() {
    return provideAccessPointControllerImpl(userManagerProvider.get(), userTrackerProvider.get(), mainExecutorProvider.get(), wifiPickerTrackerFactoryProvider.get());
  }

  public static StatusBarPolicyModule_ProvideAccessPointControllerImplFactory create(
      Provider<UserManager> userManagerProvider, Provider<UserTracker> userTrackerProvider,
      Provider<Executor> mainExecutorProvider,
      Provider<AccessPointControllerImpl.WifiPickerTrackerFactory> wifiPickerTrackerFactoryProvider) {
    return new StatusBarPolicyModule_ProvideAccessPointControllerImplFactory(userManagerProvider, userTrackerProvider, mainExecutorProvider, wifiPickerTrackerFactoryProvider);
  }

  public static AccessPointControllerImpl provideAccessPointControllerImpl(UserManager userManager,
      UserTracker userTracker, Executor mainExecutor,
      AccessPointControllerImpl.WifiPickerTrackerFactory wifiPickerTrackerFactory) {
    return Preconditions.checkNotNullFromProvides(StatusBarPolicyModule.provideAccessPointControllerImpl(userManager, userTracker, mainExecutor, wifiPickerTrackerFactory));
  }
}
