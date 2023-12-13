package com.android.systemui.statusbar.notification.collection.inflation;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.row.RowContentBindStage;
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
public final class LowPriorityInflationHelper_Factory implements Factory<LowPriorityInflationHelper> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<RowContentBindStage> rowContentBindStageProvider;

  public LowPriorityInflationHelper_Factory(Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<RowContentBindStage> rowContentBindStageProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.rowContentBindStageProvider = rowContentBindStageProvider;
  }

  @Override
  public LowPriorityInflationHelper get() {
    return newInstance(featureFlagsProvider.get(), groupManagerProvider.get(), rowContentBindStageProvider.get());
  }

  public static LowPriorityInflationHelper_Factory create(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<RowContentBindStage> rowContentBindStageProvider) {
    return new LowPriorityInflationHelper_Factory(featureFlagsProvider, groupManagerProvider, rowContentBindStageProvider);
  }

  public static LowPriorityInflationHelper newInstance(FeatureFlags featureFlags,
      NotificationGroupManagerLegacy groupManager, RowContentBindStage rowContentBindStage) {
    return new LowPriorityInflationHelper(featureFlags, groupManager, rowContentBindStage);
  }
}
