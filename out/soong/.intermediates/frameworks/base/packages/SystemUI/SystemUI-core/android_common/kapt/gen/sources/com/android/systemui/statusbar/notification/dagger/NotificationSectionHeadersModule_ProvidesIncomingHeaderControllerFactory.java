package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
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
public final class NotificationSectionHeadersModule_ProvidesIncomingHeaderControllerFactory implements Factory<SectionHeaderController> {
  private final Provider<SectionHeaderControllerSubcomponent> subcomponentProvider;

  public NotificationSectionHeadersModule_ProvidesIncomingHeaderControllerFactory(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    this.subcomponentProvider = subcomponentProvider;
  }

  @Override
  public SectionHeaderController get() {
    return providesIncomingHeaderController(subcomponentProvider.get());
  }

  public static NotificationSectionHeadersModule_ProvidesIncomingHeaderControllerFactory create(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    return new NotificationSectionHeadersModule_ProvidesIncomingHeaderControllerFactory(subcomponentProvider);
  }

  public static SectionHeaderController providesIncomingHeaderController(
      SectionHeaderControllerSubcomponent subcomponent) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesIncomingHeaderController(subcomponent));
  }
}
