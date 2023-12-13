package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.os.Looper;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
import com.android.systemui.dump.DumpManager;
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
public final class BluetoothControllerImpl_Factory implements Factory<BluetoothControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<Looper> bgLooperProvider;

  private final Provider<Looper> mainLooperProvider;

  private final Provider<LocalBluetoothManager> localBluetoothManagerProvider;

  public BluetoothControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<Looper> bgLooperProvider,
      Provider<Looper> mainLooperProvider,
      Provider<LocalBluetoothManager> localBluetoothManagerProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.bgLooperProvider = bgLooperProvider;
    this.mainLooperProvider = mainLooperProvider;
    this.localBluetoothManagerProvider = localBluetoothManagerProvider;
  }

  @Override
  public BluetoothControllerImpl get() {
    return newInstance(contextProvider.get(), dumpManagerProvider.get(), bgLooperProvider.get(), mainLooperProvider.get(), localBluetoothManagerProvider.get());
  }

  public static BluetoothControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<Looper> bgLooperProvider,
      Provider<Looper> mainLooperProvider,
      Provider<LocalBluetoothManager> localBluetoothManagerProvider) {
    return new BluetoothControllerImpl_Factory(contextProvider, dumpManagerProvider, bgLooperProvider, mainLooperProvider, localBluetoothManagerProvider);
  }

  public static BluetoothControllerImpl newInstance(Context context, DumpManager dumpManager,
      Looper bgLooper, Looper mainLooper, LocalBluetoothManager localBluetoothManager) {
    return new BluetoothControllerImpl(context, dumpManager, bgLooper, mainLooper, localBluetoothManager);
  }
}
