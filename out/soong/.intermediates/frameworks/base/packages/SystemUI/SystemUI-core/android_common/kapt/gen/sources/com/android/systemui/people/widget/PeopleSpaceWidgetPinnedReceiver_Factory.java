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
public final class PeopleSpaceWidgetPinnedReceiver_Factory implements Factory<PeopleSpaceWidgetPinnedReceiver> {
  private final Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider;

  public PeopleSpaceWidgetPinnedReceiver_Factory(
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    this.peopleSpaceWidgetManagerProvider = peopleSpaceWidgetManagerProvider;
  }

  @Override
  public PeopleSpaceWidgetPinnedReceiver get() {
    return newInstance(peopleSpaceWidgetManagerProvider.get());
  }

  public static PeopleSpaceWidgetPinnedReceiver_Factory create(
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    return new PeopleSpaceWidgetPinnedReceiver_Factory(peopleSpaceWidgetManagerProvider);
  }

  public static PeopleSpaceWidgetPinnedReceiver newInstance(
      PeopleSpaceWidgetManager peopleSpaceWidgetManager) {
    return new PeopleSpaceWidgetPinnedReceiver(peopleSpaceWidgetManager);
  }
}
