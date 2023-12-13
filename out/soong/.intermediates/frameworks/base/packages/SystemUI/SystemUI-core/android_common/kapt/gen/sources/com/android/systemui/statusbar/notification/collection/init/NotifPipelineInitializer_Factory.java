package com.android.systemui.statusbar.notification.collection.init;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotifInflaterImpl;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.ShadeListBuilder;
import com.android.systemui.statusbar.notification.collection.coalescer.GroupCoalescer;
import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators;
import com.android.systemui.statusbar.notification.collection.render.ShadeViewManagerFactory;
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
public final class NotifPipelineInitializer_Factory implements Factory<NotifPipelineInitializer> {
  private final Provider<NotifPipeline> pipelineWrapperProvider;

  private final Provider<GroupCoalescer> groupCoalescerProvider;

  private final Provider<NotifCollection> notifCollectionProvider;

  private final Provider<ShadeListBuilder> listBuilderProvider;

  private final Provider<NotifCoordinators> notifCoordinatorsProvider;

  private final Provider<NotifInflaterImpl> notifInflaterProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<ShadeViewManagerFactory> shadeViewManagerFactoryProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  public NotifPipelineInitializer_Factory(Provider<NotifPipeline> pipelineWrapperProvider,
      Provider<GroupCoalescer> groupCoalescerProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<ShadeListBuilder> listBuilderProvider,
      Provider<NotifCoordinators> notifCoordinatorsProvider,
      Provider<NotifInflaterImpl> notifInflaterProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<ShadeViewManagerFactory> shadeViewManagerFactoryProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    this.pipelineWrapperProvider = pipelineWrapperProvider;
    this.groupCoalescerProvider = groupCoalescerProvider;
    this.notifCollectionProvider = notifCollectionProvider;
    this.listBuilderProvider = listBuilderProvider;
    this.notifCoordinatorsProvider = notifCoordinatorsProvider;
    this.notifInflaterProvider = notifInflaterProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.shadeViewManagerFactoryProvider = shadeViewManagerFactoryProvider;
    this.featureFlagsProvider = featureFlagsProvider;
  }

  @Override
  public NotifPipelineInitializer get() {
    return newInstance(pipelineWrapperProvider.get(), groupCoalescerProvider.get(), notifCollectionProvider.get(), listBuilderProvider.get(), notifCoordinatorsProvider.get(), notifInflaterProvider.get(), dumpManagerProvider.get(), shadeViewManagerFactoryProvider.get(), featureFlagsProvider.get());
  }

  public static NotifPipelineInitializer_Factory create(
      Provider<NotifPipeline> pipelineWrapperProvider,
      Provider<GroupCoalescer> groupCoalescerProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<ShadeListBuilder> listBuilderProvider,
      Provider<NotifCoordinators> notifCoordinatorsProvider,
      Provider<NotifInflaterImpl> notifInflaterProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<ShadeViewManagerFactory> shadeViewManagerFactoryProvider,
      Provider<FeatureFlags> featureFlagsProvider) {
    return new NotifPipelineInitializer_Factory(pipelineWrapperProvider, groupCoalescerProvider, notifCollectionProvider, listBuilderProvider, notifCoordinatorsProvider, notifInflaterProvider, dumpManagerProvider, shadeViewManagerFactoryProvider, featureFlagsProvider);
  }

  public static NotifPipelineInitializer newInstance(NotifPipeline pipelineWrapper,
      GroupCoalescer groupCoalescer, NotifCollection notifCollection, ShadeListBuilder listBuilder,
      NotifCoordinators notifCoordinators, NotifInflaterImpl notifInflater, DumpManager dumpManager,
      ShadeViewManagerFactory shadeViewManagerFactory, FeatureFlags featureFlags) {
    return new NotifPipelineInitializer(pipelineWrapper, groupCoalescer, notifCollection, listBuilder, notifCoordinators, notifInflater, dumpManager, shadeViewManagerFactory, featureFlags);
  }
}
