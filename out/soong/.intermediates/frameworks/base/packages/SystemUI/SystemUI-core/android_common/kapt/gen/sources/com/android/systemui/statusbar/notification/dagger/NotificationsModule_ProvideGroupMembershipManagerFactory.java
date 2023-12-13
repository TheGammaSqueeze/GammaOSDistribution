package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class NotificationsModule_ProvideGroupMembershipManagerFactory implements Factory<GroupMembershipManager> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider;

  public NotificationsModule_ProvideGroupMembershipManagerFactory(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.groupManagerLegacyProvider = groupManagerLegacyProvider;
  }

  @Override
  public GroupMembershipManager get() {
    return provideGroupMembershipManager(featureFlagsProvider.get(), DoubleCheck.lazy(groupManagerLegacyProvider));
  }

  public static NotificationsModule_ProvideGroupMembershipManagerFactory create(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider) {
    return new NotificationsModule_ProvideGroupMembershipManagerFactory(featureFlagsProvider, groupManagerLegacyProvider);
  }

  public static GroupMembershipManager provideGroupMembershipManager(FeatureFlags featureFlags,
      Lazy<NotificationGroupManagerLegacy> groupManagerLegacy) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideGroupMembershipManager(featureFlags, groupManagerLegacy));
  }
}
