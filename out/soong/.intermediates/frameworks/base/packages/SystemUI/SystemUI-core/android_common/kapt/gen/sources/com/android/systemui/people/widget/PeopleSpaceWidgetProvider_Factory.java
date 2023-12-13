package com.android.systemui.people.widget;

import dagger.internal.Factory;
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
public final class PeopleSpaceWidgetProvider_Factory implements Factory<PeopleSpaceWidgetProvider> {
  private final Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider;

  public PeopleSpaceWidgetProvider_Factory(
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    this.peopleSpaceWidgetManagerProvider = peopleSpaceWidgetManagerProvider;
  }

  @Override
  public PeopleSpaceWidgetProvider get() {
    return newInstance(peopleSpaceWidgetManagerProvider.get());
  }

  public static PeopleSpaceWidgetProvider_Factory create(
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    return new PeopleSpaceWidgetProvider_Factory(peopleSpaceWidgetManagerProvider);
  }

  public static PeopleSpaceWidgetProvider newInstance(
      PeopleSpaceWidgetManager peopleSpaceWidgetManager) {
    return new PeopleSpaceWidgetProvider(peopleSpaceWidgetManager);
  }
}
