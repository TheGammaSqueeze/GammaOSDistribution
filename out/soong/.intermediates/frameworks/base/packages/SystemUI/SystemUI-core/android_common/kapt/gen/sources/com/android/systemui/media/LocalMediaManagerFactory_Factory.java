package com.android.systemui.media;

import android.content.Context;
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
public final class LocalMediaManagerFactory_Factory implements Factory<LocalMediaManagerFactory> {
  private final Provider<Context> contextProvider;

  private final Provider<LocalBluetoothManager> localBluetoothManagerProvider;

  public LocalMediaManagerFactory_Factory(Provider<Context> contextProvider,
      Provider<LocalBluetoothManager> localBluetoothManagerProvider) {
    this.contextProvider = contextProvider;
    this.localBluetoothManagerProvider = localBluetoothManagerProvider;
  }

  @Override
  public LocalMediaManagerFactory get() {
    return newInstance(contextProvider.get(), localBluetoothManagerProvider.get());
  }

  public static LocalMediaManagerFactory_Factory create(Provider<Context> contextProvider,
      Provider<LocalBluetoothManager> localBluetoothManagerProvider) {
    return new LocalMediaManagerFactory_Factory(contextProvider, localBluetoothManagerProvider);
  }

  public static LocalMediaManagerFactory newInstance(Context context,
      LocalBluetoothManager localBluetoothManager) {
    return new LocalMediaManagerFactory(context, localBluetoothManager);
  }
}
