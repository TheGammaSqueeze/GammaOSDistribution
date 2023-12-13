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
public final class NotificationSectionHeadersModule_ProvidesPeopleHeaderSubcomponentFactory implements Factory<SectionHeaderControllerSubcomponent> {
  private final Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider;

  public NotificationSectionHeadersModule_ProvidesPeopleHeaderSubcomponentFactory(
      Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider) {
    this.builderProvider = builderProvider;
  }

  @Override
  public SectionHeaderControllerSubcomponent get() {
    return providesPeopleHeaderSubcomponent(builderProvider);
  }

  public static NotificationSectionHeadersModule_ProvidesPeopleHeaderSubcomponentFactory create(
      Provider<SectionHeaderControllerSubcomponent.Builder> builderProvider) {
    return new NotificationSectionHeadersModule_ProvidesPeopleHeaderSubcomponentFactory(builderProvider);
  }

  public static SectionHeaderControllerSubcomponent providesPeopleHeaderSubcomponent(
      Provider<SectionHeaderControllerSubcomponent.Builder> builder) {
    return Preconditions.checkNotNullFromProvides(NotificationSectionHeadersModule.providesPeopleHeaderSubcomponent(builder));
  }
}
