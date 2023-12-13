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
public final class NotificationSectionHeadersModule_ProvidesSilentHeaderSubcomponentFactory implements Factory<SectionHeaderControllerSubcomponent> {
  private final Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider;

  public NotificationSectionHeadersModule_ProvidesSilentHeaderSubcomponentFactory(
      Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider) {
    this.builderProvider = builderProvider;
  }

  @Override
  public SectionHeaderControllerSubcomponent get() {
    return providesSilentHeaderSubcomponent(builderProvider);
  }

  public static NotificationSectionHeadersModule_ProvidesSilentHeaderSubcomponentFactory create(
      Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider) {
    return new NotificationSectionHeadersModule_ProvidesSilentHeaderSubcomponentFactory(builderProvider);
  }

  public static SectionHeaderControllerSubcomponent providesSilentHeaderSubcomponent(
      Provider<SectionHeaderControllerSubcomponent.Builder> builder) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesSilentHeaderSubcomponent(builder));
  }
}
