package com.android.systemui.dagger;

import android.content.Context;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
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
public final class SystemUIDefaultModule_ProvideHeadsUpManagerPhoneFactory implements Factory<HeadsUpManagerPhone> {
  private final Provider<Context> contextProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<KeyguardBypassController> bypassControllerProvider;

  private final Provider<GroupMembershipManager> groupManagerProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  public SystemUIDefaultModule_ProvideHeadsUpManagerPhoneFactory(Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<GroupMembershipManager> groupManagerProvider,
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

  public static SystemUIDefaultModule_ProvideHeadsUpManagerPhoneFactory create(
      Provider<Context> contextProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<KeyguardBypassController> bypassControllerProvider,
      Provider<GroupMembershipManager> groupManagerProvider,
      Provider<ConfigurationController> configurationControllerProvider) {
    return new SystemUIDefaultModule_ProvideHeadsUpManagerPhoneFactory(contextProvider, statusBarStateControllerProvider, bypassControllerProvider, groupManagerProvider, configurationControllerProvider);
  }

  public static HeadsUpManagerPhone provideHeadsUpManagerPhone(Context context,
      StatusBarStateController statusBarStateController, KeyguardBypassController bypassController,
      GroupMembershipManager groupManager, ConfigurationController configurationController) {
    return Preconditions.checkNotNullFromProvides(SystemUIDefaultModule.provideHeadsUpManagerPhone(context, statusBarStateController, bypassController, groupManager, configurationController));
  }
}
