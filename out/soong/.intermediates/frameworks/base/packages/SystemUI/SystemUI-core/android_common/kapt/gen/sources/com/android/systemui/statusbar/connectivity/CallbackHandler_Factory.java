package com.android.systemui.statusbar.connectivity;

import android.os.Looper;
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
public final class CallbackHandler_Factory implements Factory<CallbackHandler> {
  private final Provider<Looper> looperProvider;

  public CallbackHandler_Factory(Provider<Looper> looperProvider) {
    this.looperProvider = looperProvider;
  }

  @Override
  public CallbackHandler get() {
    return newInstance(looperProvider.get());
  }

  public static CallbackHandler_Factory create(Provider<Looper> looperProvider) {
    return new CallbackHandler_Factory(looperProvider);
  }

  public static CallbackHandler newInstance(Looper looper) {
    return new CallbackHandler(looper);
  }
}
