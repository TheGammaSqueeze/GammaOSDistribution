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
public final class NotificationSectionHeadersModule_ProvidesPeopleHeaderNodeControllerFactory implements Factory<NodeController> {
  private final Provider<SectionHeaderControllerSubcomponent> subcomponentProvider;

  public NotificationSectionHeadersModule_ProvidesPeopleHeaderNodeControllerFactory(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    this.subcomponentProvider = subcomponentProvider;
  }

  @Override
  public NodeController get() {
    return providesPeopleHeaderNodeController(subcomponentProvider.get());
  }

  public static NotificationSectionHeadersModule_ProvidesPeopleHeaderNodeControllerFactory create(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    return new NotificationSectionHeadersModule_ProvidesPeopleHeaderNodeControllerFactory(subcomponentProvider);
  }

  public static NodeController providesPeopleHeaderNodeController(
      SectionHeaderControllerSubcomponent subcomponent) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesPeopleHeaderNodeController(subcomponent));
  }
}
