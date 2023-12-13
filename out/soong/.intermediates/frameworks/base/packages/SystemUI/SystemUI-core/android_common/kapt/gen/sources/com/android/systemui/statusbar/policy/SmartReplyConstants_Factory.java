package com.android.systemui.statusbar.policy;

import android.content.Context;
import android.os.Handler;
import com.android.systemui.util.DeviceConfigProxy;
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
public final class SmartReplyConstants_Factory implements Factory<SmartReplyConstants> {
  private final Provider<Handler> handlerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<DeviceConfigProxy> deviceConfigProvider;

  public SmartReplyConstants_Factory(Provider<Handler> handlerProvider,
      Provider<Context> contextProvider, Provider<DeviceConfigProxy> deviceConfigProvider) {
    this.handlerProvider = handlerProvider;
    this.contextProvider = contextProvider;
    this.deviceConfigProvider = deviceConfigProvider;
  }

  @Override
  public SmartReplyConstants get() {
    return newInstance(handlerProvider.get(), contextProvider.get(), deviceConfigProvider.get());
  }

  public static SmartReplyConstants_Factory create(Provider<Handler> handlerProvider,
      Provider<Context> contextProvider, Provider<DeviceConfigProxy> deviceConfigProvider) {
    return new SmartReplyConstants_Factory(handlerProvider, contextProvider, deviceConfigProvider);
  }

  public static SmartReplyConstants newInstance(Handler handler, Context context,
      DeviceConfigProxy deviceConfig) {
    return new SmartReplyConstants(handler, context, deviceConfig);
  }
}
