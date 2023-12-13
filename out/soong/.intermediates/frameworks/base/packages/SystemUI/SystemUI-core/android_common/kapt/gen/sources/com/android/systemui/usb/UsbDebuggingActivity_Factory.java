package com.android.systemui.usb;

import com.android.systemui.broadcast.BroadcastDispatcher;
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
public final class UsbDebuggingActivity_Factory implements Factory<UsbDebuggingActivity> {
  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public UsbDebuggingActivity_Factory(Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public UsbDebuggingActivity get() {
    return newInstance(broadcastDispatcherProvider.get());
  }

  public static UsbDebuggingActivity_Factory create(
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new UsbDebuggingActivity_Factory(broadcastDispatcherProvider);
  }

  public static UsbDebuggingActivity newInstance(BroadcastDispatcher broadcastDispatcher) {
    return new UsbDebuggingActivity(broadcastDispatcher);
  }
}
