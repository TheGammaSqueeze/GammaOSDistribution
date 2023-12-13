package com.android.systemui.qs.carrier;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import com.android.keyguard.CarrierTextManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.statusbar.connectivity.NetworkController;
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
public final class QSCarrierGroupController_Builder_Factory implements Factory<QSCarrierGroupController.Builder> {
  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<Looper> looperProvider;

  private final Provider<NetworkController> networkControllerProvider;

  private final Provider<CarrierTextManager.Builder> carrierTextControllerBuilderProvider;

  private final Provider<Context> contextProvider;

  private final Provider<CarrierConfigTracker> carrierConfigTrackerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<QSCarrierGroupController.SlotIndexResolver> slotIndexResolverProvider;

  public QSCarrierGroupController_Builder_Factory(Provider<ActivityStarter> activityStarterProvider,
      Provider<Handler> handlerProvider, Provider<Looper> looperProvider,
      Provider<NetworkController> networkControllerProvider,
      Provider<CarrierTextManager.Builder> carrierTextControllerBuilderProvider,
      Provider<Context> contextProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<QSCarrierGroupController.SlotIndexResolver> slotIndexResolverProvider) {
    this.activityStarterProvider = activityStarterProvider;
    this.handlerProvider = handlerProvider;
    this.looperProvider = looperProvider;
    this.networkControllerProvider = networkControllerProvider;
    this.carrierTextControllerBuilderProvider = carrierTextControllerBuilderProvider;
    this.contextProvider = contextProvider;
    this.carrierConfigTrackerProvider = carrierConfigTrackerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.slotIndexResolverProvider = slotIndexResolverProvider;
  }

  @Override
  public QSCarrierGroupController.Builder get() {
    return newInstance(activityStarterProvider.get(), handlerProvider.get(), looperProvider.get(), networkControllerProvider.get(), carrierTextControllerBuilderProvider.get(), contextProvider.get(), carrierConfigTrackerProvider.get(), featureFlagsProvider.get(), slotIndexResolverProvider.get());
  }

  public static QSCarrierGroupController_Builder_Factory create(
      Provider<ActivityStarter> activityStarterProvider, Provider<Handler> handlerProvider,
      Provider<Looper> looperProvider, Provider<NetworkController> networkControllerProvider,
      Provider<CarrierTextManager.Builder> carrierTextControllerBuilderProvider,
      Provider<Context> contextProvider,
      Provider<CarrierConfigTracker> carrierConfigTrackerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<QSCarrierGroupController.SlotIndexResolver> slotIndexResolverProvider) {
    return new QSCarrierGroupController_Builder_Factory(activityStarterProvider, handlerProvider, looperProvider, networkControllerProvider, carrierTextControllerBuilderProvider, contextProvider, carrierConfigTrackerProvider, featureFlagsProvider, slotIndexResolverProvider);
  }

  public static QSCarrierGroupController.Builder newInstance(ActivityStarter activityStarter,
      Handler handler, Looper looper, NetworkController networkController,
      CarrierTextManager.Builder carrierTextControllerBuilder, Context context,
      CarrierConfigTracker carrierConfigTracker, FeatureFlags featureFlags,
      QSCarrierGroupController.SlotIndexResolver slotIndexResolver) {
    return new QSCarrierGroupController.Builder(activityStarter, handler, looper, networkController, carrierTextControllerBuilder, context, carrierConfigTracker, featureFlags, slotIndexResolver);
  }
}
