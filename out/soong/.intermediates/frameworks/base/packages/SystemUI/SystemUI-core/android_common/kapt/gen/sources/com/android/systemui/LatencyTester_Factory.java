package com.android.systemui;

import android.content.Context;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
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
public final class LatencyTester_Factory implements Factory<LatencyTester> {
  private final Provider<Context> contextProvider;

  private final Provider<BiometricUnlockController> biometricUnlockControllerProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public LatencyTester_Factory(Provider<Context> contextProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.contextProvider = contextProvider;
    this.biometricUnlockControllerProvider = biometricUnlockControllerProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public LatencyTester get() {
    return newInstance(contextProvider.get(), biometricUnlockControllerProvider.get(), broadcastDispatcherProvider.get());
  }

  public static LatencyTester_Factory create(Provider<Context> contextProvider,
      Provider<BiometricUnlockController> biometricUnlockControllerProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new LatencyTester_Factory(contextProvider, biometricUnlockControllerProvider, broadcastDispatcherProvider);
  }

  public static LatencyTester newInstance(Context context,
      BiometricUnlockController biometricUnlockController,
      BroadcastDispatcher broadcastDispatcher) {
    return new LatencyTester(context, biometricUnlockController, broadcastDispatcher);
  }
}
