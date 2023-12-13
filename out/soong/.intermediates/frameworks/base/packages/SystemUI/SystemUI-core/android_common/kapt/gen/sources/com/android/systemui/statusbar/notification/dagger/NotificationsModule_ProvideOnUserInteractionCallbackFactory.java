package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.coordinator.VisualStabilityCoordinator;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.row.OnUserInteractionCallback;
import com.android.systemui.statusbar.policy.HeadsUpManager;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class NotificationsModule_ProvideOnUserInteractionCallbackFactory implements Factory<OnUserInteractionCallback> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<HeadsUpManager> headsUpManagerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<NotifPipeline> pipelineProvider;

  private final Provider<NotifCollection> notifCollectionProvider;

  private final Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  private final Provider<VisualStabilityManager> visualStabilityManagerProvider;

  private final Provider<GroupMembershipManager> groupMembershipManagerLazyProvider;

  public NotificationsModule_ProvideOnUserInteractionCallbackFactory(
      Provider<FeatureFlags> featureFlagsProvider, Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotifPipeline> pipelineProvider, Provider<NotifCollection> notifCollectionProvider,
      Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<GroupMembershipManager> groupMembershipManagerLazyProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.headsUpManagerProvider = headsUpManagerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.pipelineProvider = pipelineProvider;
    this.notifCollectionProvider = notifCollectionProvider;
    this.visualStabilityCoordinatorProvider = visualStabilityCoordinatorProvider;
    this.entryManagerProvider = entryManagerProvider;
    this.visualStabilityManagerProvider = visualStabilityManagerProvider;
    this.groupMembershipManagerLazyProvider = groupMembershipManagerLazyProvider;
  }

  @Override
  public OnUserInteractionCallback get() {
    return provideOnUserInteractionCallback(featureFlagsProvider.get(), headsUpManagerProvider.get(), statusBarStateControllerProvider.get(), DoubleCheck.lazy(pipelineProvider), DoubleCheck.lazy(notifCollectionProvider), DoubleCheck.lazy(visualStabilityCoordinatorProvider), entryManagerProvider.get(), visualStabilityManagerProvider.get(), DoubleCheck.lazy(groupMembershipManagerLazyProvider));
  }

  public static NotificationsModule_ProvideOnUserInteractionCallbackFactory create(
      Provider<FeatureFlags> featureFlagsProvider, Provider<HeadsUpManager> headsUpManagerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<NotifPipeline> pipelineProvider, Provider<NotifCollection> notifCollectionProvider,
      Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider,
      Provider<NotificationEntryManager> entryManagerProvider,
      Provider<VisualStabilityManager> visualStabilityManagerProvider,
      Provider<GroupMembershipManager> groupMembershipManagerLazyProvider) {
    return new NotificationsModule_ProvideOnUserInteractionCallbackFactory(featureFlagsProvider, headsUpManagerProvider, statusBarStateControllerProvider, pipelineProvider, notifCollectionProvider, visualStabilityCoordinatorProvider, entryManagerProvider, visualStabilityManagerProvider, groupMembershipManagerLazyProvider);
  }

  public static OnUserInteractionCallback provideOnUserInteractionCallback(
      FeatureFlags featureFlags, HeadsUpManager headsUpManager,
      StatusBarStateController statusBarStateController, Lazy<NotifPipeline> pipeline,
      Lazy<NotifCollection> notifCollection,
      Lazy<VisualStabilityCoordinator> visualStabilityCoordinator,
      NotificationEntryManager entryManager, VisualStabilityManager visualStabilityManager,
      Lazy<GroupMembershipManager> groupMembershipManagerLazy) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideOnUserInteractionCallback(featureFlags, headsUpManager, statusBarStateController, pipeline, notifCollection, visualStabilityCoordinator, entryManager, visualStabilityManager, groupMembershipManagerLazy));
  }
}
