package com.android.systemui.statusbar.policy;

import android.content.Context;
import com.android.systemui.controls.dagger.ControlsComponent;
import com.android.systemui.settings.UserContextProvider;
import com.android.systemui.util.settings.SecureSettings;
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
public final class DeviceControlsControllerImpl_Factory implements Factory<DeviceControlsControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<ControlsComponent> controlsComponentProvider;

  private final Provider<UserContextProvider> userContextProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  public DeviceControlsControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<ControlsComponent> controlsComponentProvider,
      Provider<UserContextProvider> userContextProvider,
      Provider<SecureSettings> secureSettingsProvider) {
    this.contextProvider = contextProvider;
    this.controlsComponentProvider = controlsComponentProvider;
    this.userContextProvider = userContextProvider;
    this.secureSettingsProvider = secureSettingsProvider;
  }

  @Override
  public DeviceControlsControllerImpl get() {
    return newInstance(contextProvider.get(), controlsComponentProvider.get(), userContextProvider.get(), secureSettingsProvider.get());
  }

  public static DeviceControlsControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<ControlsComponent> controlsComponentProvider,
      Provider<UserContextProvider> userContextProvider,
      Provider<SecureSettings> secureSettingsProvider) {
    return new DeviceControlsControllerImpl_Factory(contextProvider, controlsComponentProvider, userContextProvider, secureSettingsProvider);
  }

  public static DeviceControlsControllerImpl newInstance(Context context,
      ControlsComponent controlsComponent, UserContextProvider userContextProvider,
      SecureSettings secureSettings) {
    return new DeviceControlsControllerImpl(context, controlsComponent, userContextProvider, secureSettings);
  }
}
