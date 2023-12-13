package com.android.systemui.statusbar.notification.stack;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
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
public final class NotificationRoundnessManager_Factory implements Factory<NotificationRoundnessManager> {
  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  public NotificationRoundnessManager_Factory(
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.sectionsFeatureManagerProvider = sectionsFeatureManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
  }

  @Override
  public NotificationRoundnessManager get() {
    return newInstance(keyguardBypassControllerProvider.get(), sectionsFeatureManagerProvider.get(), featureFlagsProvider.get());
  }

  public static NotificationRoundnessManager_Factory create(
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    return new NotificationRoundnessManager_Factory(keyguardBypassControllerProvider, sectionsFeatureManagerProvider, featureFlagsProvider);
  }

  public static NotificationRoundnessManager newInstance(
      KeyguardBypassController keyguardBypassController,
      NotificationSectionsFeatureManager sectionsFeatureManager, FeatureFlags featureFlags) {
    return new NotificationRoundnessManager(keyguardBypassController, sectionsFeatureManager, featureFlags);
  }
}
