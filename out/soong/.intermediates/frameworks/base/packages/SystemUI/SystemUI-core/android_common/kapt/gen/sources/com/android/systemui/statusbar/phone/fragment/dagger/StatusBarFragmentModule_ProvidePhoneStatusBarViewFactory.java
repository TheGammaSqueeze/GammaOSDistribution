package com.android.systemui.statusbar.phone.fragment.dagger;

import com.android.systemui.statusbar.phone.PhoneStatusBarView;
import com.android.systemui.statusbar.phone.fragment.CollapsedStatusBarFragment;
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
public final class StatusBarFragmentModule_ProvidePhoneStatusBarViewFactory implements Factory<PhoneStatusBarView> {
  private final Provider<CollapsedStatusBarFragment> collapsedStatusBarFragmentProvider;

  public StatusBarFragmentModule_ProvidePhoneStatusBarViewFactory(
      Provider<CollapsedStatusBarFragment> collapsedStatusBarFragmentProvider) {
    this.collapsedStatusBarFragmentProvider = collapsedStatusBarFragmentProvider;
  }

  @Override
  public PhoneStatusBarView get() {
    return providePhoneStatusBarView(collapsedStatusBarFragmentProvider.get());
  }

  public static StatusBarFragmentModule_ProvidePhoneStatusBarViewFactory create(
      Provider<CollapsedStatusBarFragment> collapsedStatusBarFragmentProvider) {
    return new StatusBarFragmentModule_ProvidePhoneStatusBarViewFactory(collapsedStatusBarFragmentProvider);
  }

  public static PhoneStatusBarView providePhoneStatusBarView(
      CollapsedStatusBarFragment collapsedStatusBarFragment) {
    return Preconditions.checkNotNullFromProvides(StatusBarFragmentModule.providePhoneStatusBarView(collapsedStatusBarFragment));
  }
}
