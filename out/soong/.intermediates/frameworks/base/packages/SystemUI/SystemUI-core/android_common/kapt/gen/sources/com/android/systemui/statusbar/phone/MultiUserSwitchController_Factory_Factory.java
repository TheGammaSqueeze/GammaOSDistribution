package com.android.systemui.statusbar.phone;

import android.os.UserManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.qs.QSDetailDisplayer;
import com.android.systemui.qs.user.UserSwitchDialogController;
import com.android.systemui.statusbar.policy.UserSwitcherController;
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
public final class MultiUserSwitchController_Factory_Factory implements Factory<MultiUserSwitchController.Factory> {
  private final Provider<UserManager> userManagerProvider;

  private final Provider<UserSwitcherController> userSwitcherControllerProvider;

  private final Provider<QSDetailDisplayer> qsDetailDisplayerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<UserSwitchDialogController> userSwitchDialogControllerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  public MultiUserSwitchController_Factory_Factory(Provider<UserManager> userManagerProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<QSDetailDisplayer> qsDetailDisplayerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<UserSwitchDialogController> userSwitchDialogControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    this.userManagerProvider = userManagerProvider;
    this.userSwitcherControllerProvider = userSwitcherControllerProvider;
    this.qsDetailDisplayerProvider = qsDetailDisplayerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.userSwitchDialogControllerProvider = userSwitchDialogControllerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
  }

  @Override
  public MultiUserSwitchController.Factory get() {
    return newInstance(userManagerProvider.get(), userSwitcherControllerProvider.get(), qsDetailDisplayerProvider.get(), falsingManagerProvider.get(), userSwitchDialogControllerProvider.get(), featureFlagsProvider.get());
  }

  public static MultiUserSwitchController_Factory_Factory create(
      Provider<UserManager> userManagerProvider,
      Provider<UserSwitcherController> userSwitcherControllerProvider,
      Provider<QSDetailDisplayer> qsDetailDisplayerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<UserSwitchDialogController> userSwitchDialogControllerProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    return new MultiUserSwitchController_Factory_Factory(userManagerProvider, userSwitcherControllerProvider, qsDetailDisplayerProvider, falsingManagerProvider, userSwitchDialogControllerProvider, featureFlagsProvider);
  }

  public static MultiUserSwitchController.Factory newInstance(UserManager userManager,
      UserSwitcherController userSwitcherController, QSDetailDisplayer qsDetailDisplayer,
      FalsingManager falsingManager, UserSwitchDialogController userSwitchDialogController,
      FeatureFlags featureFlags) {
    return new MultiUserSwitchController.Factory(userManager, userSwitcherController, qsDetailDisplayer, falsingManager, userSwitchDialogController, featureFlags);
  }
}
