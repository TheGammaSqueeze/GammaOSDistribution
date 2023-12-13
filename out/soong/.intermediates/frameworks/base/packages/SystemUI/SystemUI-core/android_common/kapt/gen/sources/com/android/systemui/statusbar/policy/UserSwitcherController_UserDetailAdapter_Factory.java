package com.android.systemui.statusbar.policy;

import android.content.Context;
import com.android.systemui.qs.tiles.UserDetailView;
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
public final class UserSwitcherController_UserDetailAdapter_Factory implements Factory<UserSwitcherController.UserDetailAdapter> {
  private final Provider<Context> contextProvider;

  private final Provider<UserDetailView.Adapter> userDetailViewAdapterProvider;

  public UserSwitcherController_UserDetailAdapter_Factory(Provider<Context> contextProvider,
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider) {
    this.contextProvider = contextProvider;
    this.userDetailViewAdapterProvider = userDetailViewAdapterProvider;
  }

  @Override
  public UserSwitcherController.UserDetailAdapter get() {
    return newInstance(contextProvider.get(), userDetailViewAdapterProvider);
  }

  public static UserSwitcherController_UserDetailAdapter_Factory create(
      Provider<Context> contextProvider,
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider) {
    return new UserSwitcherController_UserDetailAdapter_Factory(contextProvider, userDetailViewAdapterProvider);
  }

  public static UserSwitcherController.UserDetailAdapter newInstance(Context context,
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider) {
    return new UserSwitcherController.UserDetailAdapter(context, userDetailViewAdapterProvider);
  }
}
