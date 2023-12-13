package com.android.systemui.statusbar.notification.row;

import android.view.accessibility.AccessibilityManager;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.phone.NotificationTapHelper;
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
public final class ActivatableNotificationViewController_Factory implements Factory<ActivatableNotificationViewController> {
  private final Provider<ActivatableNotificationView> viewProvider;

  private final Provider<NotificationTapHelper.Factory> notificationTapHelpFactoryProvider;

  private final Provider<ExpandableOutlineViewController> expandableOutlineViewControllerProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  public ActivatableNotificationViewController_Factory(
      Provider<ActivatableNotificationView> viewProvider,
      Provider<NotificationTapHelper.Factory> notificationTapHelpFactoryProvider,
      Provider<ExpandableOutlineViewController> expandableOutlineViewControllerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider) {
    this.viewProvider = viewProvider;
    this.notificationTapHelpFactoryProvider = notificationTapHelpFactoryProvider;
    this.expandableOutlineViewControllerProvider = expandableOutlineViewControllerProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
  }

  @Override
  public ActivatableNotificationViewController get() {
    return newInstance(viewProvider.get(), notificationTapHelpFactoryProvider.get(), expandableOutlineViewControllerProvider.get(), accessibilityManagerProvider.get(), falsingManagerProvider.get(), falsingCollectorProvider.get());
  }

  public static ActivatableNotificationViewController_Factory create(
      Provider<ActivatableNotificationView> viewProvider,
      Provider<NotificationTapHelper.Factory> notificationTapHelpFactoryProvider,
      Provider<ExpandableOutlineViewController> expandableOutlineViewControllerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider) {
    return new ActivatableNotificationViewController_Factory(viewProvider, notificationTapHelpFactoryProvider, expandableOutlineViewControllerProvider, accessibilityManagerProvider, falsingManagerProvider, falsingCollectorProvider);
  }

  public static ActivatableNotificationViewController newInstance(ActivatableNotificationView view,
      NotificationTapHelper.Factory notificationTapHelpFactory,
      ExpandableOutlineViewController expandableOutlineViewController,
      AccessibilityManager accessibilityManager, FalsingManager falsingManager,
      FalsingCollector falsingCollector) {
    return new ActivatableNotificationViewController(view, notificationTapHelpFactory, expandableOutlineViewController, accessibilityManager, falsingManager, falsingCollector);
  }
}
