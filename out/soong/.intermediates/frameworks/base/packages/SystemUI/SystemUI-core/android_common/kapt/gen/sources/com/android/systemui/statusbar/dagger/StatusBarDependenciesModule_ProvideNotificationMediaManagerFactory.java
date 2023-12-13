package com.android.systemui.statusbar.dagger;

import android.app.WallpaperManager;
import android.content.Context;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.media.MediaDataManager;
import com.android.systemui.statusbar.MediaArtworkProcessor;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class StatusBarDependenciesModule_ProvideNotificationMediaManagerFactory implements Factory<NotificationMediaManager> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  private final Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider;

  private final Provider<NotificationEntryManager> notificationEntryManagerProvider;

  private final Provider<MediaArtworkProcessor> mediaArtworkProcessorProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<NotifPipeline> notifPipelineProvider;

  private final Provider<NotifCollection> notifCollectionProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<DelayableExecutor> mainExecutorProvider;

  private final Provider<MediaDataManager> mediaDataManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<WallpaperManager> wallpaperManagerProvider;

  public StatusBarDependenciesModule_ProvideNotificationMediaManagerFactory(
      Provider<Context> contextProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<MediaArtworkProcessor> mediaArtworkProcessorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotifPipeline> notifPipelineProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<DelayableExecutor> mainExecutorProvider,
      Provider<MediaDataManager> mediaDataManagerProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<WallpaperManager> wallpaperManagerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
    this.notificationShadeWindowControllerProvider = notificationShadeWindowControllerProvider;
    this.notificationEntryManagerProvider = notificationEntryManagerProvider;
    this.mediaArtworkProcessorProvider = mediaArtworkProcessorProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.notifPipelineProvider = notifPipelineProvider;
    this.notifCollectionProvider = notifCollectionProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.mainExecutorProvider = mainExecutorProvider;
    this.mediaDataManagerProvider = mediaDataManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.wallpaperManagerProvider = wallpaperManagerProvider;
  }

  @Override
  public NotificationMediaManager get() {
    return provideNotificationMediaManager(contextProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider), DoubleCheck.lazy(notificationShadeWindowControllerProvider), notificationEntryManagerProvider.get(), mediaArtworkProcessorProvider.get(), keyguardBypassControllerProvider.get(), notifPipelineProvider.get(), notifCollectionProvider.get(), featureFlagsProvider.get(), mainExecutorProvider.get(), mediaDataManagerProvider.get(), dumpManagerProvider.get(), wallpaperManagerProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideNotificationMediaManagerFactory create(
      Provider<Context> contextProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider,
      Provider<NotificationShadeWindowController> notificationShadeWindowControllerProvider,
      Provider<NotificationEntryManager> notificationEntryManagerProvider,
      Provider<MediaArtworkProcessor> mediaArtworkProcessorProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<NotifPipeline> notifPipelineProvider,
      Provider<NotifCollection> notifCollectionProvider,
      Provider<FeatureFlags> featureFlagsProvider, Provider<DelayableExecutor> mainExecutorProvider,
      Provider<MediaDataManager> mediaDataManagerProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<WallpaperManager> wallpaperManagerProvider) {
    return new StatusBarDependenciesModule_ProvideNotificationMediaManagerFactory(contextProvider, statusBarOptionalLazyProvider, notificationShadeWindowControllerProvider, notificationEntryManagerProvider, mediaArtworkProcessorProvider, keyguardBypassControllerProvider, notifPipelineProvider, notifCollectionProvider, featureFlagsProvider, mainExecutorProvider, mediaDataManagerProvider, dumpManagerProvider, wallpaperManagerProvider);
  }

  public static NotificationMediaManager provideNotificationMediaManager(Context context,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy,
      Lazy<NotificationShadeWindowController> notificationShadeWindowController,
      NotificationEntryManager notificationEntryManager,
      MediaArtworkProcessor mediaArtworkProcessor,
      KeyguardBypassController keyguardBypassController, NotifPipeline notifPipeline,
      NotifCollection notifCollection, FeatureFlags featureFlags, DelayableExecutor mainExecutor,
      MediaDataManager mediaDataManager, DumpManager dumpManager,
      WallpaperManager wallpaperManager) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideNotificationMediaManager(context, statusBarOptionalLazy, notificationShadeWindowController, notificationEntryManager, mediaArtworkProcessor, keyguardBypassController, notifPipeline, notifCollection, featureFlags, mainExecutor, mediaDataManager, dumpManager, wallpaperManager));
  }
}
