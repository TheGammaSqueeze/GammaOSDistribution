package com.android.systemui.statusbar.notification.collection.coordinator;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class HideLocallyDismissedNotifsCoordinator_Factory implements Factory<HideLocallyDismissedNotifsCoordinator> {
  @Override
  public HideLocallyDismissedNotifsCoordinator get() {
    return newInstance();
  }

  public static HideLocallyDismissedNotifsCoordinator_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static HideLocallyDismissedNotifsCoordinator newInstance() {
    return new HideLocallyDismissedNotifsCoordinator();
  }

  private static final class InstanceHolder {
    private static final HideLocallyDismissedNotifsCoordinator_Factory INSTANCE = new HideLocallyDismissedNotifsCoordinator_Factory();
  }
}
