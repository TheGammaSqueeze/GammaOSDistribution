package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.render.GroupExpansionManager;
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
public final class NotificationsModule_ProvideGroupExpansionManagerFactory implements Factory<GroupExpansionManager> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<GroupMembershipManager> groupMembershipManagerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider;

  public NotificationsModule_ProvideGroupExpansionManagerFactory(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<GroupMembershipManager> groupMembershipManagerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.groupMembershipManagerProvider = groupMembershipManagerProvider;
    this.groupManagerLegacyProvider = groupManagerLegacyProvider;
  }

  @Override
  public GroupExpansionManager get() {
    return provideGroupExpansionManager(featureFlagsProvider.get(), DoubleCheck.lazy(groupMembershipManagerProvider), DoubleCheck.lazy(groupManagerLegacyProvider));
  }

  public static NotificationsModule_ProvideGroupExpansionManagerFactory create(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<GroupMembershipManager> groupMembershipManagerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerLegacyProvider) {
    return new NotificationsModule_ProvideGroupExpansionManagerFactory(featureFlagsProvider, groupMembershipManagerProvider, groupManagerLegacyProvider);
  }

  public static GroupExpansionManager provideGroupExpansionManager(FeatureFlags featureFlags,
      Lazy<GroupMembershipManager> groupMembershipManager,
      Lazy<NotificationGroupManagerLegacy> groupManagerLegacy) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideGroupExpansionManager(featureFlags, groupMembershipManager, groupManagerLegacy));
  }
}
