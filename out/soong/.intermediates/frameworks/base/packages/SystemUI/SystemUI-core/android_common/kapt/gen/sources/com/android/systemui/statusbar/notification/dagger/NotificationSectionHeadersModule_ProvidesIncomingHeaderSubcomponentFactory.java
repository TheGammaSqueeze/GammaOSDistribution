package com.android.systemui.statusbar.notification.dagger;

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
public final class NotificationSectionHeadersModule_ProvidesIncomingHeaderSubcomponentFactory implements Factory<SectionHeaderControllerSubcomponent> {
  private final Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider;

  public NotificationSectionHeadersModule_ProvidesIncomingHeaderSubcomponentFactory(
      Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider) {
    this.builderProvider = builderProvider;
  }

  @Override
  public SectionHeaderControllerSubcomponent get() {
    return providesIncomingHeaderSubcomponent(builderProvider);
  }

  public static NotificationSectionHeadersModule_ProvidesIncomingHeaderSubcomponentFactory create(
      Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider) {
    return new NotificationSectionHeadersModule_ProvidesIncomingHeaderSubcomponentFactory(builderProvider);
  }

  public static SectionHeaderControllerSubcomponent providesIncomingHeaderSubcomponent(
      Provider<SectionHeaderControllerSubcomponent.Builder> builder) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesIncomingHeaderSubcomponent(builder));
  }
}
