package com.android.systemui.statusbar.notification.stack;

import com.android.systemui.media.KeyguardMediaController;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class NotificationSectionsManager_Factory implements Factory<NotificationSectionsManager> {
  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<KeyguardMediaController> keyguardMediaControllerProvider;

  private final Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider;

  private final Provider<NotificationSectionsLogger> loggerProvider;

  private final Provider<SectionHeaderController> incomingHeaderControllerProvider;

  private final Provider<SectionHeaderController> peopleHeaderControllerProvider;

  private final Provider<SectionHeaderController> alertingHeaderControllerProvider;

  private final Provider<SectionHeaderController> silentHeaderControllerProvider;

  public NotificationSectionsManager_Factory(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardMediaController> keyguardMediaControllerProvider,
      Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider,
      Provider<NotificationSectionsLogger> loggerProvider,
      Provider<SectionHeaderController> incomingHeaderControllerProvider,
      Provider<SectionHeaderController> peopleHeaderControllerProvider,
      Provider<SectionHeaderController> alertingHeaderControllerProvider,
      Provider<SectionHeaderController> silentHeaderControllerProvider) {
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.keyguardMediaControllerProvider = keyguardMediaControllerProvider;
    this.sectionsFeatureManagerProvider = sectionsFeatureManagerProvider;
    this.loggerProvider = loggerProvider;
    this.incomingHeaderControllerProvider = incomingHeaderControllerProvider;
    this.peopleHeaderControllerProvider = peopleHeaderControllerProvider;
    this.alertingHeaderControllerProvider = alertingHeaderControllerProvider;
    this.silentHeaderControllerProvider = silentHeaderControllerProvider;
  }

  @Override
  public NotificationSectionsManager get() {
    return newInstance(statusBarStateControllerProvider.get(), configurationControllerProvider.get(), keyguardMediaControllerProvider.get(), sectionsFeatureManagerProvider.get(), loggerProvider.get(), incomingHeaderControllerProvider.get(), peopleHeaderControllerProvider.get(), alertingHeaderControllerProvider.get(), silentHeaderControllerProvider.get());
  }

  public static NotificationSectionsManager_Factory create(
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<KeyguardMediaController> keyguardMediaControllerProvider,
      Provider<NotificationSectionsFeatureManager> sectionsFeatureManagerProvider,
      Provider<NotificationSectionsLogger> loggerProvider,
      Provider<SectionHeaderController> incomingHeaderControllerProvider,
      Provider<SectionHeaderController> peopleHeaderControllerProvider,
      Provider<SectionHeaderController> alertingHeaderControllerProvider,
      Provider<SectionHeaderController> silentHeaderControllerProvider) {
    return new NotificationSectionsManager_Factory(statusBarStateControllerProvider, configurationControllerProvider, keyguardMediaControllerProvider, sectionsFeatureManagerProvider, loggerProvider, incomingHeaderControllerProvider, peopleHeaderControllerProvider, alertingHeaderControllerProvider, silentHeaderControllerProvider);
  }

  public static NotificationSectionsManager newInstance(
      StatusBarStateController statusBarStateController,
      ConfigurationController configurationController,
      KeyguardMediaController keyguardMediaController,
      NotificationSectionsFeatureManager sectionsFeatureManager, NotificationSectionsLogger logger,
      SectionHeaderController incomingHeaderController,
      SectionHeaderController peopleHeaderController,
      SectionHeaderController alertingHeaderController,
      SectionHeaderController silentHeaderController) {
    return new NotificationSectionsManager(statusBarStateController, configurationController, keyguardMediaController, sectionsFeatureManager, logger, incomingHeaderController, peopleHeaderController, alertingHeaderController, silentHeaderController);
  }
}
