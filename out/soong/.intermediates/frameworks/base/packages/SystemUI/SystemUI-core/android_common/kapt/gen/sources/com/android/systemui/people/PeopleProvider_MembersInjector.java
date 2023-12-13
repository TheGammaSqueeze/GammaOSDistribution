package com.android.systemui.people;

import com.android.systemui.people.widget.PeopleSpaceWidgetManager;
import dagger.MembersInjector;
import dagger.internal.InjectedFieldSignature;
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
public final class PeopleProvider_MembersInjector implements MembersInjector<PeopleProvider> {
  private final Provider<PeopleSpaceWidgetManager> mPeopleSpaceWidgetManagerProvider;

  public PeopleProvider_MembersInjector(
      Provider<PeopleSpaceWidgetManager> mPeopleSpaceWidgetManagerProvider) {
    this.mPeopleSpaceWidgetManagerProvider = mPeopleSpaceWidgetManagerProvider;
  }

  public static MembersInjector<PeopleProvider> create(
      Provider<PeopleSpaceWidgetManager> mPeopleSpaceWidgetManagerProvider) {
    return new PeopleProvider_MembersInjector(mPeopleSpaceWidgetManagerProvider);
  }

  @Override
  public void injectMembers(PeopleProvider instance) {
    injectMPeopleSpaceWidgetManager(instance, mPeopleSpaceWidgetManagerProvider.get());
  }

  @InjectedFieldSignature("com.android.systemui.people.PeopleProvider.mPeopleSpaceWidgetManager")
  public static void injectMPeopleSpaceWidgetManager(PeopleProvider instance,
      PeopleSpaceWidgetManager mPeopleSpaceWidgetManager) {
    instance.mPeopleSpaceWidgetManager = mPeopleSpaceWidgetManager;
  }
}
