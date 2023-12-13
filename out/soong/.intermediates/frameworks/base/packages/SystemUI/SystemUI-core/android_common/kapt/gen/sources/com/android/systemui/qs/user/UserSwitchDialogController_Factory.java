package com.android.systemui.qs.user;

import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
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
public final class UserSwitchDialogController_Factory implements Factory<UserSwitchDialogController> {
  private final Provider<UserDetailView.Adapter> userDetailViewAdapterProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  public UserSwitchDialogController_Factory(
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    this.userDetailViewAdapterProvider = userDetailViewAdapterProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
  }

  @Override
  public UserSwitchDialogController get() {
    return newInstance(userDetailViewAdapterProvider, activityStarterProvider.get(), falsingManagerProvider.get(), dialogLaunchAnimatorProvider.get());
  }

  public static UserSwitchDialogController_Factory create(
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    return new UserSwitchDialogController_Factory(userDetailViewAdapterProvider, activityStarterProvider, falsingManagerProvider, dialogLaunchAnimatorProvider);
  }

  public static UserSwitchDialogController newInstance(
      Provider<UserDetailView.Adapter> userDetailViewAdapterProvider,
      ActivityStarter activityStarter, FalsingManager falsingManager,
      DialogLaunchAnimator dialogLaunchAnimator) {
    return new UserSwitchDialogController(userDetailViewAdapterProvider, activityStarter, falsingManager, dialogLaunchAnimator);
  }
}
