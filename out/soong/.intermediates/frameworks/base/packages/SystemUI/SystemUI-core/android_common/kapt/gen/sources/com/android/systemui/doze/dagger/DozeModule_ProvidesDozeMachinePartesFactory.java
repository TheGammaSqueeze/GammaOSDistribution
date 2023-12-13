package com.android.systemui.doze.dagger;

import com.android.systemui.doze.DozeAuthRemover;
import com.android.systemui.doze.DozeDockHandler;
import com.android.systemui.doze.DozeFalsingManagerAdapter;
import com.android.systemui.doze.DozeMachine;
import com.android.systemui.doze.DozePauser;
import com.android.systemui.doze.DozeScreenBrightness;
import com.android.systemui.doze.DozeScreenState;
import com.android.systemui.doze.DozeTriggers;
import com.android.systemui.doze.DozeUi;
import com.android.systemui.doze.DozeWallpaperState;
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
public final class DozeModule_ProvidesDozeMachinePartesFactory implements Factory<DozeMachine.Part[]> {
  private final Provider<DozePauser> dozePauserProvider;

  private final Provider<DozeFalsingManagerAdapter> dozeFalsingManagerAdapterProvider;

  private final Provider<DozeTriggers> dozeTriggersProvider;

  private final Provider<DozeUi> dozeUiProvider;

  private final Provider<DozeScreenState> dozeScreenStateProvider;

  private final Provider<DozeScreenBrightness> dozeScreenBrightnessProvider;

  private final Provider<DozeWallpaperState> dozeWallpaperStateProvider;

  private final Provider<DozeDockHandler> dozeDockHandlerProvider;

  private final Provider<DozeAuthRemover> dozeAuthRemoverProvider;

  public DozeModule_ProvidesDozeMachinePartesFactory(Provider<DozePauser> dozePauserProvider,
      Provider<DozeFalsingManagerAdapter> dozeFalsingManagerAdapterProvider,
      Provider<DozeTriggers> dozeTriggersProvider, Provider<DozeUi> dozeUiProvider,
      Provider<DozeScreenState> dozeScreenStateProvider,
      Provider<DozeScreenBrightness> dozeScreenBrightnessProvider,
      Provider<DozeWallpaperState> dozeWallpaperStateProvider,
      Provider<DozeDockHandler> dozeDockHandlerProvider,
      Provider<DozeAuthRemover> dozeAuthRemoverProvider) {
    this.dozePauserProvider = dozePauserProvider;
    this.dozeFalsingManagerAdapterProvider = dozeFalsingManagerAdapterProvider;
    this.dozeTriggersProvider = dozeTriggersProvider;
    this.dozeUiProvider = dozeUiProvider;
    this.dozeScreenStateProvider = dozeScreenStateProvider;
    this.dozeScreenBrightnessProvider = dozeScreenBrightnessProvider;
    this.dozeWallpaperStateProvider = dozeWallpaperStateProvider;
    this.dozeDockHandlerProvider = dozeDockHandlerProvider;
    this.dozeAuthRemoverProvider = dozeAuthRemoverProvider;
  }

  @Override
  public DozeMachine.Part[] get() {
    return providesDozeMachinePartes(dozePauserProvider.get(), dozeFalsingManagerAdapterProvider.get(), dozeTriggersProvider.get(), dozeUiProvider.get(), dozeScreenStateProvider.get(), dozeScreenBrightnessProvider.get(), dozeWallpaperStateProvider.get(), dozeDockHandlerProvider.get(), dozeAuthRemoverProvider.get());
  }

  public static DozeModule_ProvidesDozeMachinePartesFactory create(
      Provider<DozePauser> dozePauserProvider,
      Provider<DozeFalsingManagerAdapter> dozeFalsingManagerAdapterProvider,
      Provider<DozeTriggers> dozeTriggersProvider, Provider<DozeUi> dozeUiProvider,
      Provider<DozeScreenState> dozeScreenStateProvider,
      Provider<DozeScreenBrightness> dozeScreenBrightnessProvider,
      Provider<DozeWallpaperState> dozeWallpaperStateProvider,
      Provider<DozeDockHandler> dozeDockHandlerProvider,
      Provider<DozeAuthRemover> dozeAuthRemoverProvider) {
    return new DozeModule_ProvidesDozeMachinePartesFactory(dozePauserProvider, dozeFalsingManagerAdapterProvider, dozeTriggersProvider, dozeUiProvider, dozeScreenStateProvider, dozeScreenBrightnessProvider, dozeWallpaperStateProvider, dozeDockHandlerProvider, dozeAuthRemoverProvider);
  }

  public static DozeMachine.Part[] providesDozeMachinePartes(DozePauser dozePauser,
      DozeFalsingManagerAdapter dozeFalsingManagerAdapter, DozeTriggers dozeTriggers, DozeUi dozeUi,
      DozeScreenState dozeScreenState, DozeScreenBrightness dozeScreenBrightness,
      DozeWallpaperState dozeWallpaperState, DozeDockHandler dozeDockHandler,
      DozeAuthRemover dozeAuthRemover) {
    return Preconditions.checkNotNullFromProvides(DozeModule.providesDozeMachinePartes(dozePauser, dozeFalsingManagerAdapter, dozeTriggers, dozeUi, dozeScreenState, dozeScreenBrightness, dozeWallpaperState, dozeDockHandler, dozeAuthRemover));
  }
}
