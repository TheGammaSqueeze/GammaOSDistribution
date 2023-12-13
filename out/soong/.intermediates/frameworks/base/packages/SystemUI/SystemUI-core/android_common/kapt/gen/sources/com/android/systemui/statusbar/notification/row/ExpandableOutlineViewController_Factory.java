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
public final class ExpandableOutlineViewController_Factory implements Factory<ExpandableOutlineViewController> {
  private final Provider<ExpandableOutlineView> viewProvider;

  private final Provider<ExpandableViewController> expandableViewControllerProvider;

  public ExpandableOutlineViewController_Factory(Provider<ExpandableOutlineView> viewProvider,
      Provider<ExpandableViewController> expandableViewControllerProvider) {
    this.viewProvider = viewProvider;
    this.expandableViewControllerProvider = expandableViewControllerProvider;
  }

  @Override
  public ExpandableOutlineViewController get() {
    return newInstance(viewProvider.get(), expandableViewControllerProvider.get());
  }

  public static ExpandableOutlineViewController_Factory create(
      Provider<ExpandableOutlineView> viewProvider,
      Provider<ExpandableViewController> expandableViewControllerProvider) {
    return new ExpandableOutlineViewController_Factory(viewProvider, expandableViewControllerProvider);
  }

  public static ExpandableOutlineViewController newInstance(ExpandableOutlineView view,
      ExpandableViewController expandableViewController) {
    return new ExpandableOutlineViewController(view, expandableViewController);
  }
}
