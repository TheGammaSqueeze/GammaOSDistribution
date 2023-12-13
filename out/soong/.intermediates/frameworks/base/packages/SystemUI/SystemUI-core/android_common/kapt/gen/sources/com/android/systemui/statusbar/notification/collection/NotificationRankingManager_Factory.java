package com.android.systemui.statusbar.notification.collection;

import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationEntryManagerLogger;
import com.android.systemui.statusbar.notification.NotificationFilter;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class NotificationRankingManager_Factory implements Factory<NotificationRankingManager> {
  private final Provider<NotificationMediaManager> mediaManagerLazyProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<NotificationFilter> notifFilterProvider;

  private final Provider<NotificationEntryManagerLogger> loggerProvider;

  private final Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider;

  private final Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider;

  private final Provider<HighPriorityProvider> highPriorityProvider;

  private final Provider<NotificationEntryManager.KeyguardEnvironment> keyguardEnvironmentProvider;

  public NotificationRankingManager_Factory(
      Provider<NotificationMediaManager> mediaManagerLazyProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<NotificationFilter> notifFilterProvider,
      Provider<NotificationEntryManagerLogger> loggerProvider,
      Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<HighPriorityProvider> highPriorityProvider,
      Provider<NotificationEntryManager.KeyguardEnvironment> keyguardEnvironmentProvider) {
    this.mediaManagerLazyProvider = mediaManagerLazyProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.notifFilterProvider = notifFilterProvider;
    this.loggerProvider = loggerProvider;
    this.sectionsFeatureManagerProvider = sectionsFeatureManagerProvider;
    this.peopleNotificationIdentifierProvider = peopleNotificationIdentifierProvider;
    this.highPriorityProvider = highPriorityProvider;
    this.keyguardEnvironmentProvider = keyguardEnvironmentProvider;
  }

  @Override
  public NotificationRankingManager get() {
    return newInstance(DoubleCheck.lazy(mediaManagerLazyProvider), groupManagerProvider.get(), headsUpManagerProvider.get(), notifFilterProvider.get(), loggerProvider.get(), sectionsFeatureManagerProvider.get(), peopleNotificationIdentifierProvider.get(), highPriorityProvider.get(), keyguardEnvironmentProvider.get());
  }

  public static NotificationRankingManager_Factory create(
      Provider<NotificationMediaManager> mediaManagerLazyProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<NotificationFilter> notifFilterProvider,
      Provider<NotificationEntryManagerLogger> loggerProvider,
      Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<HighPriorityProvider> highPriorityProvider,
      Provider<NotificationEntryManager.KeyguardEnvironment> keyguardEnvironmentProvider) {
    return new NotificationRankingManager_Factory(mediaManagerLazyProvider, groupManagerProvider, headsUpManagerProvider, notifFilterProvider, loggerProvider, sectionsFeatureManagerProvider, peopleNotificationIdentifierProvider, highPriorityProvider, keyguardEnvironmentProvider);
  }

  public static NotificationRankingManager newInstance(
      Lazy<NotificationMediaManager> mediaManagerLazy, NotificationGroupManagerLegacy groupManager,
      HeadsUpManager headsUpManager, NotificationFilter notifFilter,
      NotificationEntryManagerLogger logger,
      NotificationSectionsFeatureManager sectionsFeatureManager,
      PeopleNotificationIdentifier peopleNotificationIdentifier,
      HighPriorityProvider highPriorityProvider,
      NotificationEntryManager.KeyguardEnvironment keyguardEnvironment) {
    return new NotificationRankingManager(mediaManagerLazy, groupManager, headsUpManager, notifFilter, logger, sectionsFeatureManager, peopleNotificationIdentifier, highPriorityProvider, keyguardEnvironment);
  }
}
