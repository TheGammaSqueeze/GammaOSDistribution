package com.android.systemui.statusbar.notification.people;

import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
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
public final class PeopleNotificationIdentifierImpl_Factory implements Factory<PeopleNotificationIdentifierImpl> {
  private final Provider<NotificationPersonExtractor> personExtractorProvider;

  private final Provider<GroupMembershipManager> groupManagerProvider;

  public PeopleNotificationIdentifierImpl_Factory(
      Provider<NotificationPersonExtractor> personExtractorProvider,
      Provider<GroupMembershipManager> groupManagerProvider) {
    this.personExtractorProvider = personExtractorProvider;
    this.groupManagerProvider = groupManagerProvider;
  }

  @Override
  public PeopleNotificationIdentifierImpl get() {
    return newInstance(personExtractorProvider.get(), groupManagerProvider.get());
  }

  public static PeopleNotificationIdentifierImpl_Factory create(
      Provider<NotificationPersonExtractor> personExtractorProvider,
      Provider<GroupMembershipManager> groupManagerProvider) {
    return new PeopleNotificationIdentifierImpl_Factory(personExtractorProvider, groupManagerProvider);
  }

  public static PeopleNotificationIdentifierImpl newInstance(
      NotificationPersonExtractor personExtractor, GroupMembershipManager groupManager) {
    return new PeopleNotificationIdentifierImpl(personExtractor, groupManager);
  }
}
