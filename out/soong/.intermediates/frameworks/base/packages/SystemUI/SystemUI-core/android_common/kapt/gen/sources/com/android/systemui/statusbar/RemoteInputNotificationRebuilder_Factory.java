package com.android.systemui.statusbar;

import android.content.Context;
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
public final class RemoteInputNotificationRebuilder_Factory implements Factory<RemoteInputNotificationRebuilder> {
  private final Provider<Context> contextProvider;

  public RemoteInputNotificationRebuilder_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public RemoteInputNotificationRebuilder get() {
    return newInstance(contextProvider.get());
  }

  public static RemoteInputNotificationRebuilder_Factory create(Provider<Context> contextProvider) {
    return new RemoteInputNotificationRebuilder_Factory(contextProvider);
  }

  public static RemoteInputNotificationRebuilder newInstance(Context context) {
    return new RemoteInputNotificationRebuilder(context);
  }
}
