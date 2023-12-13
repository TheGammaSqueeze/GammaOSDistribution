package com.android.systemui.statusbar.notification.collection.legacy;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier;
import com.android.wm.shell.bubbles.Bubbles;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class NotificationGroupManagerLegacy_Factory implements Factory<NotificationGroupManagerLegacy> {
  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotificationGroupManagerLegacy_Factory(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.peopleNotificationIdentifierProvider = peopleNotificationIdentifierProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotificationGroupManagerLegacy get() {
    return newInstance(statusBarStateControllerProvider.get(), DoubleCheck.lazy(peopleNotificationIdentifierProvider), bubblesOptionalProvider.get(), dumpManagerProvider.get());
  }

  public static NotificationGroupManagerLegacy_Factory create(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NotificationGroupManagerLegacy_Factory(statusBarStateControllerProvider, peopleNotificationIdentifierProvider, bubblesOptionalProvider, dumpManagerProvider);
  }

  public static NotificationGroupManagerLegacy newInstance(
      StatusBarStateController statusBarStateController,
      Lazy<PeopleNotificationIdentifier> peopleNotificationIdentifier,
      Optional<Bubbles> bubblesOptional, DumpManager dumpManager) {
    return new NotificationGroupManagerLegacy(statusBarStateController, peopleNotificationIdentifier, bubblesOptional, dumpManager);
  }
}
