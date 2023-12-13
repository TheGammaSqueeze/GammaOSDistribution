package com.android.systemui.statusbar.notification;

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
public final class AssistantFeedbackController_Factory implements Factory<AssistantFeedbackController> {
  private final Provider<Handler> handlerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<DeviceConfigProxy> proxyProvider;

  public AssistantFeedbackController_Factory(Provider<Handler> handlerProvider,
      Provider<Context> contextProvider, Provider<DeviceConfigProxy> proxyProvider) {
    this.handlerProvider = handlerProvider;
    this.contextProvider = contextProvider;
    this.proxyProvider = proxyProvider;
  }

  @Override
  public AssistantFeedbackController get() {
    return newInstance(handlerProvider.get(), contextProvider.get(), proxyProvider.get());
  }

  public static AssistantFeedbackController_Factory create(Provider<Handler> handlerProvider,
      Provider<Context> contextProvider, Provider<DeviceConfigProxy> proxyProvider) {
    return new AssistantFeedbackController_Factory(handlerProvider, contextProvider, proxyProvider);
  }

  public static AssistantFeedbackController newInstance(Handler handler, Context context,
      DeviceConfigProxy proxy) {
    return new AssistantFeedbackController(handler, context, proxy);
  }
}
