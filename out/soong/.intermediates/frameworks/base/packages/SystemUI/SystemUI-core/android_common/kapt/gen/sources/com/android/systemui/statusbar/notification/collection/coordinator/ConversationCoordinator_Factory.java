package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.statusbar.notification.collection.render.NodeController;
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
public final class ConversationCoordinator_Factory implements Factory<ConversationCoordinator> {
  private final Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider;

  private final Provider<NodeController> peopleHeaderControllerProvider;

  public ConversationCoordinator_Factory(
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<NodeController> peopleHeaderControllerProvider) {
    this.peopleNotificationIdentifierProvider = peopleNotificationIdentifierProvider;
    this.peopleHeaderControllerProvider = peopleHeaderControllerProvider;
  }

  @Override
  public ConversationCoordinator get() {
    return newInstance(peopleNotificationIdentifierProvider.get(), peopleHeaderControllerProvider.get());
  }

  public static ConversationCoordinator_Factory create(
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<NodeController> peopleHeaderControllerProvider) {
    return new ConversationCoordinator_Factory(peopleNotificationIdentifierProvider, peopleHeaderControllerProvider);
  }

  public static ConversationCoordinator newInstance(
      PeopleNotificationIdentifier peopleNotificationIdentifier,
      NodeController peopleHeaderController) {
    return new ConversationCoordinator(peopleNotificationIdentifier, peopleHeaderController);
  }
}
