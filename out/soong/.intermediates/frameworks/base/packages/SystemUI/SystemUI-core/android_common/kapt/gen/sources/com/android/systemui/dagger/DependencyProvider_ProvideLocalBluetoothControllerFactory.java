package com.android.systemui.dagger;

import android.annotation.Nullable;
import android.content.Context;
import android.os.Handler;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
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
public final class DependencyProvider_ProvideLocalBluetoothControllerFactory implements Factory<LocalBluetoothManager> {
  private final Provider<Context> contextProvider;

  private final Provider<Handler> bgHandlerProvider;

  public DependencyProvider_ProvideLocalBluetoothControllerFactory(
      Provider<Context> contextProvider, Provider<Handler> bgHandlerProvider) {
    this.contextProvider = contextProvider;
    this.bgHandlerProvider = bgHandlerProvider;
  }

  @Override
  @Nullable
  public LocalBluetoothManager get() {
    return provideLocalBluetoothController(contextProvider.get(), bgHandlerProvider.get());
  }

  public static DependencyProvider_ProvideLocalBluetoothControllerFactory create(
      Provider<Context> contextProvider, Provider<Handler> bgHandlerProvider) {
    return new DependencyProvider_ProvideLocalBluetoothControllerFactory(contextProvider, bgHandlerProvider);
  }

  @Nullable
  public static LocalBluetoothManager provideLocalBluetoothController(Context context,
      Handler bgHandler) {
    return DependencyProvider.provideLocalBluetoothController(context, bgHandler);
  }
}
