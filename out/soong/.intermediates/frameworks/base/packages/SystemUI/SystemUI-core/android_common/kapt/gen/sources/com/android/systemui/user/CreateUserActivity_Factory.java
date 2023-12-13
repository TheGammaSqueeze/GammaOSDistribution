package com.android.systemui.user;

import android.app.IActivityManager;
import com.android.settingslib.users.EditUserInfoController;
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
public final class CreateUserActivity_Factory implements Factory<CreateUserActivity> {
  private final Provider<UserCreator> userCreatorProvider;

  private final Provider<EditUserInfoController> editUserInfoControllerProvider;

  private final Provider<IActivityManager> activityManagerProvider;

  public CreateUserActivity_Factory(Provider<UserCreator> userCreatorProvider,
      Provider<EditUserInfoController> editUserInfoControllerProvider,
      Provider<IActivityManager> activityManagerProvider) {
    this.userCreatorProvider = userCreatorProvider;
    this.editUserInfoControllerProvider = editUserInfoControllerProvider;
    this.activityManagerProvider = activityManagerProvider;
  }

  @Override
  public CreateUserActivity get() {
    return newInstance(userCreatorProvider.get(), editUserInfoControllerProvider.get(), activityManagerProvider.get());
  }

  public static CreateUserActivity_Factory create(Provider<UserCreator> userCreatorProvider,
      Provider<EditUserInfoController> editUserInfoControllerProvider,
      Provider<IActivityManager> activityManagerProvider) {
    return new CreateUserActivity_Factory(userCreatorProvider, editUserInfoControllerProvider, activityManagerProvider);
  }

  public static CreateUserActivity newInstance(UserCreator userCreator,
      EditUserInfoController editUserInfoController, IActivityManager activityManager) {
    return new CreateUserActivity(userCreator, editUserInfoController, activityManager);
  }
}
