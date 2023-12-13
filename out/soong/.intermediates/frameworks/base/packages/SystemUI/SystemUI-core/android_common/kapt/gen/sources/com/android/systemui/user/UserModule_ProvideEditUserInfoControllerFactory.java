package com.android.systemui.user;

import com.android.settingslib.users.EditUserInfoController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class UserModule_ProvideEditUserInfoControllerFactory implements Factory<EditUserInfoController> {
  private final UserModule module;

  public UserModule_ProvideEditUserInfoControllerFactory(UserModule module) {
    this.module = module;
  }

  @Override
  public EditUserInfoController get() {
    return provideEditUserInfoController(module);
  }

  public static UserModule_ProvideEditUserInfoControllerFactory create(UserModule module) {
    return new UserModule_ProvideEditUserInfoControllerFactory(module);
  }

  public static EditUserInfoController provideEditUserInfoController(UserModule instance) {
    return Preconditions.checkNotNullFromProvides(instance.provideEditUserInfoController());
  }
}
