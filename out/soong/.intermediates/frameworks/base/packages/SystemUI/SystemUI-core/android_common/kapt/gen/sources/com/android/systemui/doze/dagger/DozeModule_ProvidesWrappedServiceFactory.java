package com.android.systemui.doze.dagger;

import com.android.systemui.doze.DozeHost;
import com.android.systemui.doze.DozeMachine;
import com.android.systemui.statusbar.phone.DozeParameters;
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
public final class DozeModule_ProvidesWrappedServiceFactory implements Factory<DozeMachine.Service> {
  private final Provider<DozeMachine.Service> dozeMachineServiceProvider;

  private final Provider<DozeHost> dozeHostProvider;

  private final Provider<DozeParameters> dozeParametersProvider;

  public DozeModule_ProvidesWrappedServiceFactory(
      Provider<DozeMachine.Service> dozeMachineServiceProvider, Provider<DozeHost> dozeHostProvider,
      Provider<DozeParameters> dozeParametersProvider) {
    this.dozeMachineServiceProvider = dozeMachineServiceProvider;
    this.dozeHostProvider = dozeHostProvider;
    this.dozeParametersProvider = dozeParametersProvider;
  }

  @Override
  public DozeMachine.Service get() {
    return providesWrappedService(dozeMachineServiceProvider.get(), dozeHostProvider.get(), dozeParametersProvider.get());
  }

  public static DozeModule_ProvidesWrappedServiceFactory create(
      Provider<DozeMachine.Service> dozeMachineServiceProvider, Provider<DozeHost> dozeHostProvider,
      Provider<DozeParameters> dozeParametersProvider) {
    return new DozeModule_ProvidesWrappedServiceFactory(dozeMachineServiceProvider, dozeHostProvider, dozeParametersProvider);
  }

  public static DozeMachine.Service providesWrappedService(DozeMachine.Service dozeMachineService,
      DozeHost dozeHost, DozeParameters dozeParameters) {
    return Preconditions.checkNotNullFromProvides(DozeModule.providesWrappedService(dozeMachineService, dozeHost, dozeParameters));
  }
}
