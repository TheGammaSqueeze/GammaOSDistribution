package com.android.systemui.tv;

import android.content.Context;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class TvSystemUIModule_ProvideHeadsUpManagerPhoneFactory implements Factory<HeadsUpManagerPhone> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<NotificationGroupManagerLegacy> groupManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  public TvSystemUIModule_ProvideHeadsUpManagerPhoneFactory(Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    this.contextProvider = contextProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.bypassControllerProvider = bypassControllerProvider;
    this.groupManagerProvider = groupManagerProvider;
    this.configurationControllerProvider = configurationControllerProvider;
  }

  @Override
  public HeadsUpManagerPhone get() {
    return provideHeadsUpManagerPhone(contextProvider.get(), statusBarStateControllerProvider.get(), bypassControllerProvider.get(), groupManagerProvider.get(), configurationControllerProvider.get());
  }

  public static TvSystemUIModule_ProvideHeadsUpManagerPhoneFactory create(
      Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<NotificationGroupManagerLegacy> groupManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    return new TvSystemUIModule_ProvideHeadsUpManagerPhoneFactory(contextProvider, statusBarStateControllerProvider, bypassControllerProvider, groupManagerProvider, configurationControllerProvider);
  }

  public static HeadsUpManagerPhone provideHeadsUpManagerPhone(Context context,
      StatusBarStateController statusBarStateController, KeyguardBypassController bypassController,
      NotificationGroupManagerLegacy groupManager,
      ConfigurationController configurationController) {
    return Preconditions.checkNotNullFromProvides(TvSystemUIModule.provideHeadsUpManagerPhone(context, statusBarStateController, bypassController, groupManager, configurationController));
  }
}
