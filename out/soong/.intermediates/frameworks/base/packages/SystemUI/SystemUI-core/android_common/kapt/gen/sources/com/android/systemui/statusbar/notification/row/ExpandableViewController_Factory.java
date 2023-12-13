package com.android.systemui.statusbar.notification.row;

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
public final class ExpandableViewController_Factory implements Factory<ExpandableViewController> {
  private final Provider<ExpandableView> viewProvider;

  public ExpandableViewController_Factory(Provider<ExpandableView> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public ExpandableViewController get() {
    return newInstance(viewProvider.get());
  }

  public static ExpandableViewController_Factory create(Provider<ExpandableView> viewProvider) {
    return new ExpandableViewController_Factory(viewProvider);
  }

  public static ExpandableViewController newInstance(ExpandableView view) {
    return new ExpandableViewController(view);
  }
}
