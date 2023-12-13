package com.android.systemui.statusbar.notification.collection.provider;

import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier;
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
public final class HighPriorityProvider_Factory implements Factory<HighPriorityProvider> {
  private final Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider;

  private final Provider<GroupMembershipManager> groupManagerProvider;

  public HighPriorityProvider_Factory(
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<GroupMembershipManager> groupManagerProvider) {
    this.peopleNotificationIdentifierProvider = peopleNotificationIdentifierProvider;
    this.groupManagerProvider = groupManagerProvider;
  }

  @Override
  public HighPriorityProvider get() {
    return newInstance(peopleNotificationIdentifierProvider.get(), groupManagerProvider.get());
  }

  public static HighPriorityProvider_Factory create(
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<GroupMembershipManager> groupManagerProvider) {
    return new HighPriorityProvider_Factory(peopleNotificationIdentifierProvider, groupManagerProvider);
  }

  public static HighPriorityProvider newInstance(
      PeopleNotificationIdentifier peopleNotificationIdentifier,
      GroupMembershipManager groupManager) {
    return new HighPriorityProvider(peopleNotificationIdentifier, groupManager);
  }
}
