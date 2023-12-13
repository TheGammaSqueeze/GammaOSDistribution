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
public final class NotificationSectionHeadersModule_ProvidesSilentHeaderNodeControllerFactory implements Factory<NodeController> {
  private final Provider<SectionHeaderControllerSubcomponent> subcomponentProvider;

  public NotificationSectionHeadersModule_ProvidesSilentHeaderNodeControllerFactory(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    this.subcomponentProvider = subcomponentProvider;
  }

  @Override
  public NodeController get() {
    return providesSilentHeaderNodeController(subcomponentProvider.get());
  }

  public static NotificationSectionHeadersModule_ProvidesSilentHeaderNodeControllerFactory create(
      Provider<SectionHeaderControllerSubcomponent> subcomponentProvider) {
    return new NotificationSectionHeadersModule_ProvidesSilentHeaderNodeControllerFactory(subcomponentProvider);
  }

  public static NodeController providesSilentHeaderNodeController(
      SectionHeaderControllerSubcomponent subcomponent) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesSilentHeaderNodeController(subcomponent));
  }
}
