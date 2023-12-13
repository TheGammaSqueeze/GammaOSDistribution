package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.wmshell.BubblesManager;
import com.android.wm.shell.bubbles.Bubbles;
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
public final class BubbleCoordinator_Factory implements Factory<BubbleCoordinator> {
  private final Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider;

  private final Provider<Optional<Bubbles>> bubblesOptionalProvider;

  private final Provider<NotifCollection> notifCollectionProvider;

  public BubbleCoordinator_Factory(
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<NotifCollection> notifCollectionProvider) {
    this.bubblesManagerOptionalProvider = bubblesManagerOptionalProvider;
    this.bubblesOptionalProvider = bubblesOptionalProvider;
    this.notifCollectionProvider = notifCollectionProvider;
  }

  @Override
  public BubbleCoordinator get() {
    return newInstance(bubblesManagerOptionalProvider.get(), bubblesOptionalProvider.get(), notifCollectionProvider.get());
  }

  public static BubbleCoordinator_Factory create(
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<Optional<Bubbles>> bubblesOptionalProvider,
      Provider<NotifCollection> notifCollectionProvider) {
    return new BubbleCoordinator_Factory(bubblesManagerOptionalProvider, bubblesOptionalProvider, notifCollectionProvider);
  }

  public static BubbleCoordinator newInstance(Optional<BubblesManager> bubblesManagerOptional,
      Optional<Bubbles> bubblesOptional, NotifCollection notifCollection) {
    return new BubbleCoordinator(bubblesManagerOptional, bubblesOptional, notifCollection);
  }
}
