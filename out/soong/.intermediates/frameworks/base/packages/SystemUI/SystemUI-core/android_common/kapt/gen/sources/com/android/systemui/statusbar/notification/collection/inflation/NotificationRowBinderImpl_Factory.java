package com.android.systemui.statusbar.notification.collection.inflation;

import android.content.Context;
import com.android.internal.util.NotificationMessagingUtil;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.notification.icon.IconManager;
import com.android.systemui.statusbar.notification.row.NotifBindPipeline;
import com.android.systemui.statusbar.notification.row.RowContentBindStage;
import com.android.systemui.statusbar.notification.row.RowInflaterTask;
import com.android.systemui.statusbar.notification.row.dagger.ExpandableNotificationRowComponent;
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
public final class NotificationRowBinderImpl_Factory implements Factory<NotificationRowBinderImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<NotificationMessagingUtil> notificationMessagingUtilProvider;

  private final Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider;

  private final Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider;

  private final Provider<NotifBindPipeline> notifBindPipelineProvider;

  private final Provider<RowContentBindStage> rowContentBindStageProvider;

  private final Provider<RowInflaterTask> rowInflaterTaskProvider;

  private final Provider<ExpandableNotificationRowComponent.Builder> expandableNotificationRowComponentBuilderProvider;

  private final Provider<IconManager> iconManagerProvider;

  private final Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider;

  public NotificationRowBinderImpl_Factory(Provider<Context> contextProvider,
      Provider<NotificationMessagingUtil> notificationMessagingUtilProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotifBindPipeline> notifBindPipelineProvider,
      Provider<RowContentBindStage> rowContentBindStageProvider,
      Provider<RowInflaterTask> rowInflaterTaskProvider,
      Provider<ExpandableNotificationRowComponent.Builder> expandableNotificationRowComponentBuilderProvider,
      Provider<IconManager> iconManagerProvider,
      Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider) {
    this.contextProvider = contextProvider;
    this.notificationMessagingUtilProvider = notificationMessagingUtilProvider;
    this.notificationRemoteInputManagerProvider = notificationRemoteInputManagerProvider;
    this.notificationLockscreenUserManagerProvider = notificationLockscreenUserManagerProvider;
    this.notifBindPipelineProvider = notifBindPipelineProvider;
    this.rowContentBindStageProvider = rowContentBindStageProvider;
    this.rowInflaterTaskProvider = rowInflaterTaskProvider;
    this.expandableNotificationRowComponentBuilderProvider = expandableNotificationRowComponentBuilderProvider;
    this.iconManagerProvider = iconManagerProvider;
    this.lowPriorityInflationHelperProvider = lowPriorityInflationHelperProvider;
  }

  @Override
  public NotificationRowBinderImpl get() {
    return newInstance(contextProvider.get(), notificationMessagingUtilProvider.get(), notificationRemoteInputManagerProvider.get(), notificationLockscreenUserManagerProvider.get(), notifBindPipelineProvider.get(), rowContentBindStageProvider.get(), rowInflaterTaskProvider, expandableNotificationRowComponentBuilderProvider.get(), iconManagerProvider.get(), lowPriorityInflationHelperProvider.get());
  }

  public static NotificationRowBinderImpl_Factory create(Provider<Context> contextProvider,
      Provider<NotificationMessagingUtil> notificationMessagingUtilProvider,
      Provider<NotificationRemoteInputManager> notificationRemoteInputManagerProvider,
      Provider<NotificationLockscreenUserManager> notificationLockscreenUserManagerProvider,
      Provider<NotifBindPipeline> notifBindPipelineProvider,
      Provider<RowContentBindStage> rowContentBindStageProvider,
      Provider<RowInflaterTask> rowInflaterTaskProvider,
      Provider<ExpandableNotificationRowComponent.Builder> expandableNotificationRowComponentBuilderProvider,
      Provider<IconManager> iconManagerProvider,
      Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider) {
    return new NotificationRowBinderImpl_Factory(contextProvider, notificationMessagingUtilProvider, notificationRemoteInputManagerProvider, notificationLockscreenUserManagerProvider, notifBindPipelineProvider, rowContentBindStageProvider, rowInflaterTaskProvider, expandableNotificationRowComponentBuilderProvider, iconManagerProvider, lowPriorityInflationHelperProvider);
  }

  public static NotificationRowBinderImpl newInstance(Context context,
      NotificationMessagingUtil notificationMessagingUtil,
      NotificationRemoteInputManager notificationRemoteInputManager,
      NotificationLockscreenUserManager notificationLockscreenUserManager,
      NotifBindPipeline notifBindPipeline, RowContentBindStage rowContentBindStage,
      Provider<RowInflaterTask> rowInflaterTaskProvider,
      ExpandableNotificationRowComponent.Builder expandableNotificationRowComponentBuilder,
      IconManager iconManager, LowPriorityInflationHelper lowPriorityInflationHelper) {
    return new NotificationRowBinderImpl(context, notificationMessagingUtil, notificationRemoteInputManager, notificationLockscreenUserManager, notifBindPipeline, rowContentBindStage, rowInflaterTaskProvider, expandableNotificationRowComponentBuilder, iconManager, lowPriorityInflationHelper);
  }
}
