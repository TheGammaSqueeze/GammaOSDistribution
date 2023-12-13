package com.android.systemui.statusbar.notification.row;

import com.android.systemui.media.MediaFeatureFlag;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.notification.ConversationNotificationProcessor;
import com.android.systemui.statusbar.policy.SmartReplyStateInflater;
import dagger.internal.Factory;
import java.util.concurrent.Executor;
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
public final class NotificationContentInflater_Factory implements Factory<NotificationContentInflater> {
  private final Provider<NotifRemoteViewCache> remoteViewCacheProvider;

  private final Provider<NotificationRemoteInputManager> remoteInputManagerProvider;

  private final Provider<ConversationNotificationProcessor> conversationProcessorProvider;

  private final Provider<MediaFeatureFlag> mediaFeatureFlagProvider;

  private final Provider<Executor> bgExecutorProvider;

  private final Provider<SmartReplyStateInflater> smartRepliesInflaterProvider;

  public NotificationContentInflater_Factory(Provider<NotifRemoteViewCache> remoteViewCacheProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<ConversationNotificationProcessor> conversationProcessorProvider,
      Provider<MediaFeatureFlag> mediaFeatureFlagProvider, Provider<Executor> bgExecutorProvider,
      Provider<SmartReplyStateInflater> smartRepliesInflaterProvider) {
    this.remoteViewCacheProvider = remoteViewCacheProvider;
    this.remoteInputManagerProvider = remoteInputManagerProvider;
    this.conversationProcessorProvider = conversationProcessorProvider;
    this.mediaFeatureFlagProvider = mediaFeatureFlagProvider;
    this.bgExecutorProvider = bgExecutorProvider;
    this.smartRepliesInflaterProvider = smartRepliesInflaterProvider;
  }

  @Override
  public NotificationContentInflater get() {
    return newInstance(remoteViewCacheProvider.get(), remoteInputManagerProvider.get(), conversationProcessorProvider.get(), mediaFeatureFlagProvider.get(), bgExecutorProvider.get(), smartRepliesInflaterProvider.get());
  }

  public static NotificationContentInflater_Factory create(
      Provider<NotifRemoteViewCache> remoteViewCacheProvider,
      Provider<NotificationRemoteInputManager> remoteInputManagerProvider,
      Provider<ConversationNotificationProcessor> conversationProcessorProvider,
      Provider<MediaFeatureFlag> mediaFeatureFlagProvider, Provider<Executor> bgExecutorProvider,
      Provider<SmartReplyStateInflater> smartRepliesInflaterProvider) {
    return new NotificationContentInflater_Factory(remoteViewCacheProvider, remoteInputManagerProvider, conversationProcessorProvider, mediaFeatureFlagProvider, bgExecutorProvider, smartRepliesInflaterProvider);
  }

  public static NotificationContentInflater newInstance(NotifRemoteViewCache remoteViewCache,
      NotificationRemoteInputManager remoteInputManager,
      ConversationNotificationProcessor conversationProcessor, MediaFeatureFlag mediaFeatureFlag,
      Executor bgExecutor, SmartReplyStateInflater smartRepliesInflater) {
    return new NotificationContentInflater(remoteViewCache, remoteInputManager, conversationProcessor, mediaFeatureFlag, bgExecutor, smartRepliesInflater);
  }
}
