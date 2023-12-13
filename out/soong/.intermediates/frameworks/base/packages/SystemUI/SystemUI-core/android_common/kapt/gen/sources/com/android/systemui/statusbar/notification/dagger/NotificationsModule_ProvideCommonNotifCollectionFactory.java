package com.android.systemui.statusbar.notification.dagger;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
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
public final class NotificationsModule_ProvideCommonNotifCollectionFactory implements Factory<CommonNotifCollection> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotifPipeline> pipelineProvider;

  private final Provider<NotificationEntryManager> entryManagerProvider;

  public NotificationsModule_ProvideCommonNotifCollectionFactory(
      Provider<FeatureFlags> featureFlagsProvider, Provider<NotifPipeline> pipelineProvider,
      Provider<NotificationEntryManager> entryManagerProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.pipelineProvider = pipelineProvider;
    this.entryManagerProvider = entryManagerProvider;
  }

  @Override
  public CommonNotifCollection get() {
    return provideCommonNotifCollection(featureFlagsProvider.get(), DoubleCheck.lazy(pipelineProvider), entryManagerProvider.get());
  }

  public static NotificationsModule_ProvideCommonNotifCollectionFactory create(
      Provider<FeatureFlags> featureFlagsProvider, Provider<NotifPipeline> pipelineProvider,
      Provider<NotificationEntryManager> entryManagerProvider) {
    return new NotificationsModule_ProvideCommonNotifCollectionFactory(featureFlagsProvider, pipelineProvider, entryManagerProvider);
  }

  public static CommonNotifCollection provideCommonNotifCollection(FeatureFlags featureFlags,
      Lazy<NotifPipeline> pipeline, NotificationEntryManager entryManager) {
    return Preconditions.checkNotNullFromProvides(NotificationsModule.provideCommonNotifCollection(featureFlags, pipeline, entryManager));
  }
}
