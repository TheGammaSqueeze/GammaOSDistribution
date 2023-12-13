package com.android.systemui.people;

import com.android.systemui.people.widget.PeopleSpaceWidgetManager;
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
public final class PeopleSpaceActivity_Factory implements Factory<PeopleSpaceActivity> {
  private final Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider;

  public PeopleSpaceActivity_Factory(
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    this.peopleSpaceWidgetManagerProvider = peopleSpaceWidgetManagerProvider;
  }

  @Override
  public PeopleSpaceActivity get() {
    return newInstance(peopleSpaceWidgetManagerProvider.get());
  }

  public static PeopleSpaceActivity_Factory create(
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider) {
    return new PeopleSpaceActivity_Factory(peopleSpaceWidgetManagerProvider);
  }

  public static PeopleSpaceActivity newInstance(PeopleSpaceWidgetManager peopleSpaceWidgetManager) {
    return new PeopleSpaceActivity(peopleSpaceWidgetManager);
  }
}
