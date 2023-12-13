package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
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
public final class RankingCoordinator_Factory implements Factory<RankingCoordinator> {
  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<HighPriorityProvider> highPriorityProvider;

  private final Provider<NodeController> alertingHeaderControllerProvider;

  private final Provider<SectionHeaderController> silentHeaderControllerProvider;

  private final Provider<NodeController> silentNodeControllerProvider;

  public RankingCoordinator_Factory(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<HighPriorityProvider> highPriorityProvider,
      Provider<NodeController> alertingHeaderControllerProvider,
      Provider<SectionHeaderController> silentHeaderControllerProvider,
      Provider<NodeController> silentNodeControllerProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.highPriorityProvider = highPriorityProvider;
    this.alertingHeaderControllerProvider = alertingHeaderControllerProvider;
    this.silentHeaderControllerProvider = silentHeaderControllerProvider;
    this.silentNodeControllerProvider = silentNodeControllerProvider;
  }

  @Override
  public RankingCoordinator get() {
    return newInstance(statusBarStateControllerProvider.get(), highPriorityProvider.get(), alertingHeaderControllerProvider.get(), silentHeaderControllerProvider.get(), silentNodeControllerProvider.get());
  }

  public static RankingCoordinator_Factory create(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<HighPriorityProvider> highPriorityProvider,
      Provider<NodeController> alertingHeaderControllerProvider,
      Provider<SectionHeaderController> silentHeaderControllerProvider,
      Provider<NodeController> silentNodeControllerProvider) {
    return new RankingCoordinator_Factory(statusBarStateControllerProvider, highPriorityProvider, alertingHeaderControllerProvider, silentHeaderControllerProvider, silentNodeControllerProvider);
  }

  public static RankingCoordinator newInstance(StatusBarStateController statusBarStateController,
      HighPriorityProvider highPriorityProvider, NodeController alertingHeaderController,
      SectionHeaderController silentHeaderController, NodeController silentNodeController) {
    return new RankingCoordinator(statusBarStateController, highPriorityProvider, alertingHeaderController, silentHeaderController, silentNodeController);
  }
}
