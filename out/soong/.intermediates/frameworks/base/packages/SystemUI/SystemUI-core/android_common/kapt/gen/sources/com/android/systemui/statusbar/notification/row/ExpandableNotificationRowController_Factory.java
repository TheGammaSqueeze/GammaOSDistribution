package com.android.systemui.statusbar.notification.row;

import com.android.internal.statusbar.IStatusBarService;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.notification.collection.render.GroupExpansionManager;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.logging.NotificationLogger;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifier;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import com.android.systemui.util.time.SystemClock;
import com.android.systemui.wmshell.BubblesManager;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class ExpandableNotificationRowController_Factory implements Factory<ExpandableNotificationRowController> {
  private final Provider<ExpandableNotificationRow> viewProvider;

  private final Provider<NotificationListContainer> listContainerProvider;

  private final Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider;

  private final Provider<NotificationMediaManager> mediaManagerProvider;

  private final Provider<PluginManager> pluginManagerProvider;

  private final Provider<SystemClock> clockProvider;

  private final Provider<String> appNameProvider;

  private final Provider<String> notificationKeyProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<GroupMembershipManager> groupMembershipManagerProvider;

  private final Provider<GroupExpansionManager> groupExpansionManagerProvider;

  private final Provider<RowContentBindStage> rowContentBindStageProvider;

  private final Provider<NotificationLogger> notificationLoggerProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<ExpandableNotificationRow.OnExpandClickListener> onExpandClickListenerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotificationGutsManager> notificationGutsManagerProvider;

  private final Provider<Boolean> allowLongPressProvider;

  private final Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<FalsingCollector> falsingCollectorProvider;

  private final Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider;

  private final Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider;

  private final Provider<ExpandableNotificationRowDragController> dragControllerProvider;

  private final Provider<IStatusBarService> statusBarServiceProvider;

  public ExpandableNotificationRowController_Factory(
      Provider<ExpandableNotificationRow> viewProvider,
      Provider<NotificationListContainer> listContainerProvider,
      Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider,
      Provider<NotificationMediaManager> mediaManagerProvider,
      Provider<PluginManager> pluginManagerProvider, Provider<SystemClock> clockProvider,
      Provider<String> appNameProvider, Provider<String> notificationKeyProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<GroupMembershipManager> groupMembershipManagerProvider,
      Provider<GroupExpansionManager> groupExpansionManagerProvider,
      Provider<RowContentBindStage> rowContentBindStageProvider,
      Provider<NotificationLogger> notificationLoggerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<ExpandableNotificationRow.OnExpandClickListener> onExpandClickListenerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationGutsManager> notificationGutsManagerProvider,
      Provider<Boolean> allowLongPressProvider,
      Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<ExpandableNotificationRowDragController> dragControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider) {
    this.viewProvider = viewProvider;
    this.listContainerProvider = listContainerProvider;
    this.activatableNotificationViewControllerProvider = activatableNotificationViewControllerProvider;
    this.mediaManagerProvider = mediaManagerProvider;
    this.pluginManagerProvider = pluginManagerProvider;
    this.clockProvider = clockProvider;
    this.appNameProvider = appNameProvider;
    this.notificationKeyProvider = notificationKeyProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.groupMembershipManagerProvider = groupMembershipManagerProvider;
    this.groupExpansionManagerProvider = groupExpansionManagerProvider;
    this.rowContentBindStageProvider = rowContentBindStageProvider;
    this.notificationLoggerProvider = notificationLoggerProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.onExpandClickListenerProvider = onExpandClickListenerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.notificationGutsManagerProvider = notificationGutsManagerProvider;
    this.allowLongPressProvider = allowLongPressProvider;
    this.onUserInteractionCallbackProvider = onUserInteractionCallbackProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.falsingCollectorProvider = falsingCollectorProvider;
    this.peopleNotificationIdentifierProvider = peopleNotificationIdentifierProvider;
    this.bubblesManagerOptionalProvider = bubblesManagerOptionalProvider;
    this.dragControllerProvider = dragControllerProvider;
    this.statusBarServiceProvider = statusBarServiceProvider;
  }

  @Override
  public ExpandableNotificationRowController get() {
    return newInstance(viewProvider.get(), listContainerProvider.get(), activatableNotificationViewControllerProvider.get(), mediaManagerProvider.get(), pluginManagerProvider.get(), clockProvider.get(), appNameProvider.get(), notificationKeyProvider.get(), keyguardBypassControllerProvider.get(), groupMembershipManagerProvider.get(), groupExpansionManagerProvider.get(), rowContentBindStageProvider.get(), notificationLoggerProvider.get(), headsUpManagerProvider.get(), onExpandClickListenerProvider.get(), statusBarStateControllerProvider.get(), notificationGutsManagerProvider.get(), allowLongPressProvider.get(), onUserInteractionCallbackProvider.get(), falsingManagerProvider.get(), falsingCollectorProvider.get(), peopleNotificationIdentifierProvider.get(), bubblesManagerOptionalProvider.get(), dragControllerProvider.get(), statusBarServiceProvider.get());
  }

  public static ExpandableNotificationRowController_Factory create(
      Provider<ExpandableNotificationRow> viewProvider,
      Provider<NotificationListContainer> listContainerProvider,
      Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider,
      Provider<NotificationMediaManager> mediaManagerProvider,
      Provider<PluginManager> pluginManagerProvider, Provider<SystemClock> clockProvider,
      Provider<String> appNameProvider, Provider<String> notificationKeyProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<GroupMembershipManager> groupMembershipManagerProvider,
      Provider<GroupExpansionManager> groupExpansionManagerProvider,
      Provider<RowContentBindStage> rowContentBindStageProvider,
      Provider<NotificationLogger> notificationLoggerProvider,
      Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<ExpandableNotificationRow.OnExpandClickListener> onExpandClickListenerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotificationGutsManager> notificationGutsManagerProvider,
      Provider<Boolean> allowLongPressProvider,
      Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<FalsingCollector> falsingCollectorProvider,
      Provider<PeopleNotificationIdentifier> peopleNotificationIdentifierProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<ExpandableNotificationRowDragController> dragControllerProvider,
      Provider<IStatusBarService> statusBarServiceProvider) {
    return new ExpandableNotificationRowController_Factory(viewProvider, listContainerProvider, activatableNotificationViewControllerProvider, mediaManagerProvider, pluginManagerProvider, clockProvider, appNameProvider, notificationKeyProvider, keyguardBypassControllerProvider, groupMembershipManagerProvider, groupExpansionManagerProvider, rowContentBindStageProvider, notificationLoggerProvider, headsUpManagerProvider, onExpandClickListenerProvider, statusBarStateControllerProvider, notificationGutsManagerProvider, allowLongPressProvider, onUserInteractionCallbackProvider, falsingManagerProvider, falsingCollectorProvider, peopleNotificationIdentifierProvider, bubblesManagerOptionalProvider, dragControllerProvider, statusBarServiceProvider);
  }

  public static ExpandableNotificationRowController newInstance(ExpandableNotificationRow view,
      NotificationListContainer listContainer,
      ActivatableNotificationViewController activatableNotificationViewController,
      NotificationMediaManager mediaManager, PluginManager pluginManager, SystemClock clock,
      String appName, String notificationKey, KeyguardBypassController keyguardBypassController,
      GroupMembershipManager groupMembershipManager, GroupExpansionManager groupExpansionManager,
      RowContentBindStage rowContentBindStage, NotificationLogger notificationLogger,
      HeadsUpManager headsUpManager,
      ExpandableNotificationRow.OnExpandClickListener onExpandClickListener,
      StatusBarStateController statusBarStateController,
      NotificationGutsManager notificationGutsManager, boolean allowLongPress,
      OnUserInteractionCallback onUserInteractionCallback, FalsingManager falsingManager,
      FalsingCollector falsingCollector, PeopleNotificationIdentifier peopleNotificationIdentifier,
      Optional<BubblesManager> bubblesManagerOptional,
      ExpandableNotificationRowDragController dragController, IStatusBarService statusBarService) {
    return new ExpandableNotificationRowController(view, listContainer, activatableNotificationViewController, mediaManager, pluginManager, clock, appName, notificationKey, keyguardBypassController, groupMembershipManager, groupExpansionManager, rowContentBindStage, notificationLogger, headsUpManager, onExpandClickListener, statusBarStateController, notificationGutsManager, allowLongPress, onUserInteractionCallback, falsingManager, falsingCollector, peopleNotificationIdentifier, bubblesManagerOptional, dragController, statusBarService);
  }
}
