package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.statusbar.notification.collection.render.NodeController;
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
public final class NotificationSectionHeadersModule_ProvidesIncomingHeaderNodeControllerFactory implements Factory<NodeController> {
  private final Provider<SectionHeaderControllerSubcomponent> subcomponentProvider;

  public NotificationSectionHeadersModule_ProvidesIncomingHeaderNodeControllerFactory(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    this.subcomponentProvider = subcomponentProvider;
  }

  @Override
  public NodeController get() {
    return providesIncomingHeaderNodeController(subcomponentProvider.get());
  }

  public static NotificationSectionHeadersModule_ProvidesIncomingHeaderNodeControllerFactory create(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    return new NotificationSectionHeadersModule_ProvidesIncomingHeaderNodeControllerFactory(subcomponentProvider);
  }

  public static NodeController providesIncomingHeaderNodeController(
      SectionHeaderControllerSubcomponent subcomponent) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesIncomingHeaderNodeController(subcomponent));
  }
}
