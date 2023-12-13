package com.android.systemui.statusbar.tv;

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
public final class VpnStatusObserver_Factory implements Factory<VpnStatusObserver> {
  private final Provider<Context> contextProvider;

  public VpnStatusObserver_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public VpnStatusObserver get() {
    return newInstance(contextProvider.get());
  }

  public static VpnStatusObserver_Factory create(Provider<Context> contextProvider) {
    return new VpnStatusObserver_Factory(contextProvider);
  }

  public static VpnStatusObserver newInstance(Context context) {
    return new VpnStatusObserver(context);
  }
}
