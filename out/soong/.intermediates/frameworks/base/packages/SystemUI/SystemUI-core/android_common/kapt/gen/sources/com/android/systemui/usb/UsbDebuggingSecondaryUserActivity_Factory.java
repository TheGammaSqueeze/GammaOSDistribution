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
public final class UsbDebuggingSecondaryUserActivity_Factory implements Factory<UsbDebuggingSecondaryUserActivity> {
  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  public UsbDebuggingSecondaryUserActivity_Factory(
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
  }

  @Override
  public UsbDebuggingSecondaryUserActivity get() {
    return newInstance(broadcastDispatcherProvider.get());
  }

  public static UsbDebuggingSecondaryUserActivity_Factory create(
      Provider<BroadcastDispatcher> broadcastDispatcherProvider) {
    return new UsbDebuggingSecondaryUserActivity_Factory(broadcastDispatcherProvider);
  }

  public static UsbDebuggingSecondaryUserActivity newInstance(
      BroadcastDispatcher broadcastDispatcher) {
    return new UsbDebuggingSecondaryUserActivity(broadcastDispatcher);
  }
}
