package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
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
public final class NotifCoordinatorsImpl_Factory implements Factory<NotifCoordinatorsImpl> {
  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<HideLocallyDismissedNotifsCoordinator> hideLocallyDismissedNotifsCoordinatorProvider;

  private final Provider<HideNotifsForOtherUsersCoordinator> hideNotifsForOtherUsersCoordinatorProvider;

  private final Provider<KeyguardCoordinator> keyguardCoordinatorProvider;

  private final Provider<RankingCoordinator> rankingCoordinatorProvider;

  private final Provider<AppOpsCoordinator> appOpsCoordinatorProvider;

  private final Provider<DeviceProvisionedCoordinator> deviceProvisionedCoordinatorProvider;

  private final Provider<BubbleCoordinator> bubbleCoordinatorProvider;

  private final Provider<HeadsUpCoordinator> headsUpCoordinatorProvider;

  private final Provider<GutsCoordinator> gutsCoordinatorProvider;

  private final Provider<ConversationCoordinator> conversationCoordinatorProvider;

  private final Provider<PreparationCoordinator> preparationCoordinatorProvider;

  private final Provider<MediaCoordinator> mediaCoordinatorProvider;

  private final Provider<RemoteInputCoordinator> remoteInputCoordinatorProvider;

  private final Provider<ShadeEventCoordinator> shadeEventCoordinatorProvider;

  private final Provider<SmartspaceDedupingCoordinator> smartspaceDedupingCoordinatorProvider;

  private final Provider<ViewConfigCoordinator> viewConfigCoordinatorProvider;

  private final Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider;

  private final Provider<SensitiveContentCoordinator> sensitiveContentCoordinatorProvider;

  public NotifCoordinatorsImpl_Factory(Provider<DumpManager> dumpManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<HideLocallyDismissedNotifsCoordinator> hideLocallyDismissedNotifsCoordinatorProvider,
      Provider<HideNotifsForOtherUsersCoordinator> hideNotifsForOtherUsersCoordinatorProvider,
      Provider<KeyguardCoordinator> keyguardCoordinatorProvider,
      Provider<RankingCoordinator> rankingCoordinatorProvider,
      Provider<AppOpsCoordinator> appOpsCoordinatorProvider,
      Provider<DeviceProvisionedCoordinator> deviceProvisionedCoordinatorProvider,
      Provider<BubbleCoordinator> bubbleCoordinatorProvider,
      Provider<HeadsUpCoordinator> headsUpCoordinatorProvider,
      Provider<GutsCoordinator> gutsCoordinatorProvider,
      Provider<ConversationCoordinator> conversationCoordinatorProvider,
      Provider<PreparationCoordinator> preparationCoordinatorProvider,
      Provider<MediaCoordinator> mediaCoordinatorProvider,
      Provider<RemoteInputCoordinator> remoteInputCoordinatorProvider,
      Provider<ShadeEventCoordinator> shadeEventCoordinatorProvider,
      Provider<SmartspaceDedupingCoordinator> smartspaceDedupingCoordinatorProvider,
      Provider<ViewConfigCoordinator> viewConfigCoordinatorProvider,
      Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider,
      Provider<SensitiveContentCoordinator> sensitiveContentCoordinatorProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.hideLocallyDismissedNotifsCoordinatorProvider = hideLocallyDismissedNotifsCoordinatorProvider;
    this.hideNotifsForOtherUsersCoordinatorProvider = hideNotifsForOtherUsersCoordinatorProvider;
    this.keyguardCoordinatorProvider = keyguardCoordinatorProvider;
    this.rankingCoordinatorProvider = rankingCoordinatorProvider;
    this.appOpsCoordinatorProvider = appOpsCoordinatorProvider;
    this.deviceProvisionedCoordinatorProvider = deviceProvisionedCoordinatorProvider;
    this.bubbleCoordinatorProvider = bubbleCoordinatorProvider;
    this.headsUpCoordinatorProvider = headsUpCoordinatorProvider;
    this.gutsCoordinatorProvider = gutsCoordinatorProvider;
    this.conversationCoordinatorProvider = conversationCoordinatorProvider;
    this.preparationCoordinatorProvider = preparationCoordinatorProvider;
    this.mediaCoordinatorProvider = mediaCoordinatorProvider;
    this.remoteInputCoordinatorProvider = remoteInputCoordinatorProvider;
    this.shadeEventCoordinatorProvider = shadeEventCoordinatorProvider;
    this.smartspaceDedupingCoordinatorProvider = smartspaceDedupingCoordinatorProvider;
    this.viewConfigCoordinatorProvider = viewConfigCoordinatorProvider;
    this.visualStabilityCoordinatorProvider = visualStabilityCoordinatorProvider;
    this.sensitiveContentCoordinatorProvider = sensitiveContentCoordinatorProvider;
  }

  @Override
  public NotifCoordinatorsImpl get() {
    return newInstance(dumpManagerProvider.get(), featureFlagsProvider.get(), hideLocallyDismissedNotifsCoordinatorProvider.get(), hideNotifsForOtherUsersCoordinatorProvider.get(), keyguardCoordinatorProvider.get(), rankingCoordinatorProvider.get(), appOpsCoordinatorProvider.get(), deviceProvisionedCoordinatorProvider.get(), bubbleCoordinatorProvider.get(), headsUpCoordinatorProvider.get(), gutsCoordinatorProvider.get(), conversationCoordinatorProvider.get(), preparationCoordinatorProvider.get(), mediaCoordinatorProvider.get(), remoteInputCoordinatorProvider.get(), shadeEventCoordinatorProvider.get(), smartspaceDedupingCoordinatorProvider.get(), viewConfigCoordinatorProvider.get(), visualStabilityCoordinatorProvider.get(), sensitiveContentCoordinatorProvider.get());
  }

  public static NotifCoordinatorsImpl_Factory create(Provider<DumpManager> dumpManagerProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<HideLocallyDismissedNotifsCoordinator> hideLocallyDismissedNotifsCoordinatorProvider,
      Provider<HideNotifsForOtherUsersCoordinator> hideNotifsForOtherUsersCoordinatorProvider,
      Provider<KeyguardCoordinator> keyguardCoordinatorProvider,
      Provider<RankingCoordinator> rankingCoordinatorProvider,
      Provider<AppOpsCoordinator> appOpsCoordinatorProvider,
      Provider<DeviceProvisionedCoordinator> deviceProvisionedCoordinatorProvider,
      Provider<BubbleCoordinator> bubbleCoordinatorProvider,
      Provider<HeadsUpCoordinator> headsUpCoordinatorProvider,
      Provider<GutsCoordinator> gutsCoordinatorProvider,
      Provider<ConversationCoordinator> conversationCoordinatorProvider,
      Provider<PreparationCoordinator> preparationCoordinatorProvider,
      Provider<MediaCoordinator> mediaCoordinatorProvider,
      Provider<RemoteInputCoordinator> remoteInputCoordinatorProvider,
      Provider<ShadeEventCoordinator> shadeEventCoordinatorProvider,
      Provider<SmartspaceDedupingCoordinator> smartspaceDedupingCoordinatorProvider,
      Provider<ViewConfigCoordinator> viewConfigCoordinatorProvider,
      Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider,
      Provider<SensitiveContentCoordinator> sensitiveContentCoordinatorProvider) {
    return new NotifCoordinatorsImpl_Factory(dumpManagerProvider, featureFlagsProvider, hideLocallyDismissedNotifsCoordinatorProvider, hideNotifsForOtherUsersCoordinatorProvider, keyguardCoordinatorProvider, rankingCoordinatorProvider, appOpsCoordinatorProvider, deviceProvisionedCoordinatorProvider, bubbleCoordinatorProvider, headsUpCoordinatorProvider, gutsCoordinatorProvider, conversationCoordinatorProvider, preparationCoordinatorProvider, mediaCoordinatorProvider, remoteInputCoordinatorProvider, shadeEventCoordinatorProvider, smartspaceDedupingCoordinatorProvider, viewConfigCoordinatorProvider, visualStabilityCoordinatorProvider, sensitiveContentCoordinatorProvider);
  }

  public static NotifCoordinatorsImpl newInstance(DumpManager dumpManager,
      FeatureFlags featureFlags,
      HideLocallyDismissedNotifsCoordinator hideLocallyDismissedNotifsCoordinator,
      HideNotifsForOtherUsersCoordinator hideNotifsForOtherUsersCoordinator,
      KeyguardCoordinator keyguardCoordinator, RankingCoordinator rankingCoordinator,
      AppOpsCoordinator appOpsCoordinator,
      DeviceProvisionedCoordinator deviceProvisionedCoordinator,
      BubbleCoordinator bubbleCoordinator, HeadsUpCoordinator headsUpCoordinator,
      GutsCoordinator gutsCoordinator, ConversationCoordinator conversationCoordinator,
      PreparationCoordinator preparationCoordinator, MediaCoordinator mediaCoordinator,
      RemoteInputCoordinator remoteInputCoordinator, ShadeEventCoordinator shadeEventCoordinator,
      SmartspaceDedupingCoordinator smartspaceDedupingCoordinator,
      ViewConfigCoordinator viewConfigCoordinator,
      VisualStabilityCoordinator visualStabilityCoordinator,
      SensitiveContentCoordinator sensitiveContentCoordinator) {
    return new NotifCoordinatorsImpl(dumpManager, featureFlags, hideLocallyDismissedNotifsCoordinator, hideNotifsForOtherUsersCoordinator, keyguardCoordinator, rankingCoordinator, appOpsCoordinator, deviceProvisionedCoordinator, bubbleCoordinator, headsUpCoordinator, gutsCoordinator, conversationCoordinator, preparationCoordinator, mediaCoordinator, remoteInputCoordinator, shadeEventCoordinator, smartspaceDedupingCoordinator, viewConfigCoordinator, visualStabilityCoordinator, sensitiveContentCoordinator);
  }
}
