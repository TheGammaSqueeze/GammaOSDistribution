package com.android.systemui.statusbar.notification.dagger;

import android.app.INotificationManager;
import android.content.Context;
import android.content.pm.LauncherApps;
import android.content.pm.ShortcutManager;
import android.os.Handler;
import android.view.accessibility.AccessibilityManager;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.people.widget.PeopleSpaceWidgetManager;
import com.android.systemui.settings.UserContextProvider;
import com.android.systemui.statusbar.notification.AssistantFeedbackController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider;
import com.android.systemui.statusbar.notification.row.ChannelEditorDialogController;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.notification.row.OnUserInteractionCallback;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.wmshell.BubblesManager;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class NotificationsModule_ProvideNotificationGutsManagerFactory implements Factory<NotificationGutsManager> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<Handler> bgHandlerProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<HighPriorityProvider> highPriorityProvider;

  private final Provider<INotificationManager> notificationManagerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider;

  private final Provider<LauncherApps> launcherAppsProvider;

  private final Provider<ShortcutManager> shortcutManagerProvider;

  private final Provider<ChannelEditorDialogController> channelEditorDialogControllerProvider;

  private final Provider<UserContextProvider> contextTrackerProvider;

  private final Provider<AssistantFeedbackController> assistantFeedbackControllerProvider;

  private final Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider;

  private final Provider<ShadeController> shadeControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public NotificationsModule_ProvideNotificationGutsManagerFactory(
      Provider<Context> contextProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> bgHandlerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<HighPriorityProvider> highPriorityProvider,
      Provider<INotificationManager> notificationManagerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider,
      Provider<LauncherApps> launcherAppsProvider,
      Provider<ShortcutManager> shortcutManagerProvider,
      Provider<ChannelEditorDialogController> channelEditorDialogControllerProvider,
      Provider<UserContextProvider> contextTrackerProvider,
      Provider<AssistantFeedbackController> assistantFeedbackControllerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.bgHandlerProvider = bgHandlerProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.highPriorityProvider = highPriorityProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.peopleSpaceWidgetManagerProvider = peopleSpaceWidgetManagerProvider;
    this.launcherAppsProvider = launcherAppsProvider;
    this.shortcutManagerProvider = shortcutManagerProvider;
    this.channelEditorDialogControllerProvider = channelEditorDialogControllerProvider;
    this.contextTrackerProvider = contextTrackerProvider;
    this.assistantFeedbackControllerProvider = assistantFeedbackControllerProvider;
    this.bubblesManagerOptionalProvider = bubblesManagerOptionalProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.onUserInteractionCallbackProvider = onUserInteractionCallbackProvider;
    this.shadeControllerProvider = shadeControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public NotificationGutsManager get() {
    return provideNotificationGutsManager(contextProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), mainHandlerProvider.get(), bgHandlerProvider.get(), accessibilityManagerProvider.get(), highPriorityProvider.get(), notificationManagerProvider.get(), notificationEntryManagerProvider.get(), peopleSpaceWidgetManagerProvider.get(), launcherAppsProvider.get(), shortcutManagerProvider.get(), channelEditorDialogControllerProvider.get(), contextTrackerProvider.get(), assistantFeedbackControllerProvider.get(), bubblesManagerOptionalProvider.get(), uiEventLoggerProvider.get(), onUserInteractionCallbackProvider.get(), shadeControllerProvider.get(), dumpManagerProvider.get());
  }

  public static NotificationsModule_ProvideNotificationGutsManagerFactory create(
      Provider<Context> contextProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<Handler> mainHandlerProvider, Provider<Handler> bgHandlerProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<HighPriorityProvider> highPriorityProvider,
      Provider<INotificationManager> notificationManagerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider,
      Provider<LauncherApps> launcherAppsProvider,
      Provider<ShortcutManager> shortcutManagerProvider,
      Provider<ChannelEditorDialogController> channelEditorDialogControllerProvider,
      Provider<UserContextProvider> contextTrackerProvider,
      Provider<AssistantFeedbackController> assistantFeedbackControllerProvider,
      Provider<Optional<BubblesManager>> bubblesManagerOptionalProvider,
      Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<OnUserInteractionCallback> onUserInteractionCallbackProvider,
      Provider<ShadeController> shadeControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new NotificationsModule_ProvideNotificationGutsManagerFactory(contextProvider, statusBarOptionalLazyProvider, mainHandlerProvider, bgHandlerProvider, accessibilityManagerProvider, highPriorityProvider, notificationManagerProvider, notificationEntryManagerProvider, peopleSpaceWidgetManagerProvider, launcherAppsProvider, shortcutManagerProvider, channelEditorDialogControllerProvider, contextTrackerProvider, assistantFeedbackControllerProvider, bubblesManagerOptionalProvider, uiEventLoggerProvider, onUserInteractionCallbackProvider, shadeControllerProvider, dumpManagerProvider);
  }

  public static NotificationGutsManager provideNotificationGutsManager(Context context,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy, Handler mainHandler, Handler bgHandler,
      AccessibilityManager accessibilityManager, HighPriorityProvider highPriorityProvider,
      INotificationManager notificationManager, NotificationEntryManager notificationEntryManager,
      PeopleSpaceWidgetManager peopleSpaceWidgetManager, LauncherApps launcherApps,
      ShortcutManager shortcutManager, ChannelEditorDialogController channelEditorDialogController,
      UserContextProvider contextTracker, AssistantFeedbackController assistantFeedbackController,
      Optional<BubblesManager> bubblesManagerOptional, UiEventLogger uiEventLogger,
      OnUserInteractionCallback onUserInteractionCallback, ShadeController shadeController,
      DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideNotificationGutsManager(context, statusBarOptionalLazy, mainHandler, bgHandler, accessibilityManager, highPriorityProvider, notificationManager, notificationEntryManager, peopleSpaceWidgetManager, launcherApps, shortcutManager, channelEditorDialogController, contextTracker, assistantFeedbackController, bubblesManagerOptional, uiEventLogger, onUserInteractionCallback, shadeController, dumpManager));
  }
}
