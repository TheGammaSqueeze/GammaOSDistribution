package com.android.systemui.user;

import android.content.Context;
import android.os.UserManager;
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
public final class UserCreator_Factory implements Factory<UserCreator> {
  private final Provider<Context> contextProvider;

  private final Provider<UserManager> userManagerProvider;

  public UserCreator_Factory(Provider<Context> contextProvider,
      Provider<UserManager> userManagerProvider) {
    this.contextProvider = contextProvider;
    this.userManagerProvider = userManagerProvider;
  }

  @Override
  public UserCreator get() {
    return newInstance(contextProvider.get(), userManagerProvider.get());
  }

  public static UserCreator_Factory create(Provider<Context> contextProvider,
      Provider<UserManager> userManagerProvider) {
    return new UserCreator_Factory(contextProvider, userManagerProvider);
  }

  public static UserCreator newInstance(Context context, UserManager userManager) {
    return new UserCreator(context, userManager);
  }
}
