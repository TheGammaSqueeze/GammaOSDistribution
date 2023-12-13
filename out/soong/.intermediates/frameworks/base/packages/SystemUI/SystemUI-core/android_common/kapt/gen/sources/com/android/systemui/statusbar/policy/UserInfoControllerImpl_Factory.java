package com.android.systemui.statusbar.policy;

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
public final class UserInfoControllerImpl_Factory implements Factory<UserInfoControllerImpl> {
  private final Provider<Context> contextProvider;

  public UserInfoControllerImpl_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public UserInfoControllerImpl get() {
    return newInstance(contextProvider.get());
  }

  public static UserInfoControllerImpl_Factory create(Provider<Context> contextProvider) {
    return new UserInfoControllerImpl_Factory(contextProvider);
  }

  public static UserInfoControllerImpl newInstance(Context context) {
    return new UserInfoControllerImpl(context);
  }
}
