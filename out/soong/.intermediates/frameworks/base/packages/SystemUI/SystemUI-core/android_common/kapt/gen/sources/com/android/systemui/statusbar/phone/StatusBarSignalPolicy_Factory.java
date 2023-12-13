package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.connectivity.NetworkController;
import com.android.systemui.statusbar.policy.SecurityController;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.CarrierConfigTracker;
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
public final class StatusBarSignalPolicy_Factory implements Factory<StatusBarSignalPolicy> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarIconController> iconControllerProvider;

  private final Provider<CarrierConfigTracker> carrierConfigTrackerProvider;

  private final Provider<NetworkController> networkControllerProvider;

  private final Provider<SecurityController> securityControllerProvider;

  private final Provider<TunerService> tunerServiceProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  public StatusBarSignalPolicy_Factory(Provider<Context> contextProvider,
      Provider<StatusBarIconController> iconControllerProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<SecurityController> securityControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<FeatureFlags> featureFlagsProvider) {
    this.contextProvider = contextProvider;
    this.iconControllerProvider = iconControllerProvider;
    this.carrierConfigTrackerProvider = carrierConfigTrackerProvider;
    this.networkControllerProvider = networkControllerProvider;
    this.securityControllerProvider = securityControllerProvider;
    this.tunerServiceProvider = tunerServiceProvider;
    this.featureFlagsProvider = featureFlagsProvider;
  }

  @Override
  public StatusBarSignalPolicy get() {
    return newInstance(contextProvider.get(), iconControllerProvider.get(), carrierConfigTrackerProvider.get(), networkControllerProvider.get(), securityControllerProvider.get(), tunerServiceProvider.get(), featureFlagsProvider.get());
  }

  public static StatusBarSignalPolicy_Factory create(Provider<Context> contextProvider,
      Provider<StatusBarIconController> iconControllerProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<SecurityController> securityControllerProvider,
      Provider<TunerService> tunerServiceProvider, Provider<FeatureFlags> featureFlagsProvider) {
    return new StatusBarSignalPolicy_Factory(contextProvider, iconControllerProvider, carrierConfigTrackerProvider, networkControllerProvider, securityControllerProvider, tunerServiceProvider, featureFlagsProvider);
  }

  public static StatusBarSignalPolicy newInstance(Context context,
      StatusBarIconController iconController, CarrierConfigTracker carrierConfigTracker,
      NetworkController networkController, SecurityController securityController,
      TunerService tunerService, FeatureFlags featureFlags) {
    return new StatusBarSignalPolicy(context, iconController, carrierConfigTracker, networkController, securityController, tunerService, featureFlags);
  }
}
