package com.android.systemui.statusbar.lockscreen;

import android.app.smartspace.SmartspaceManager;
import android.content.ContentResolver;
import android.content.Context;
import android.os.Handler;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.BcSmartspaceDataPlugin;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.util.concurrency.Execution;
import com.android.systemui.util.settings.SecureSettings;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class LockscreenSmartspaceController_Factory implements Factory<LockscreenSmartspaceController> {
  private final Provider<Context> contextProvider;

  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<SmartspaceManager> smartspaceManagerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<ContentResolver> contentResolverProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<DeviceProvisionedController> deviceProvisionedControllerProvider;

  private final Provider<Execution> executionProvider;

  private final Provider<Executor> uiExecutorProvider;

  private final Provider<Handler> handlerProvider;

  private final Provider<Optional<BcSmartspaceDataPlugin>> optionalPluginProvider;

  public LockscreenSmartspaceController_Factory(Provider<Context> contextProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<SmartspaceManager> smartspaceManagerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<UserTracker> userTrackerProvider,
      Provider<ContentResolver> contentResolverProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<Execution> executionProvider, Provider<Executor> uiExecutorProvider,
      Provider<Handler> handlerProvider,
      Provider<Optional<BcSmartspaceDataPlugin>> optionalPluginProvider) {
    this.contextProvider = contextProvider;
    this.featureFlagsProvider = featureFlagsProvider;
    this.smartspaceManagerProvider = smartspaceManagerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.contentResolverProvider = contentResolverProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.deviceProvisionedControllerProvider = deviceProvisionedControllerProvider;
    this.executionProvider = executionProvider;
    this.uiExecutorProvider = uiExecutorProvider;
    this.handlerProvider = handlerProvider;
    this.optionalPluginProvider = optionalPluginProvider;
  }

  @Override
  public LockscreenSmartspaceController get() {
    return newInstance(contextProvider.get(), featureFlagsProvider.get(), smartspaceManagerProvider.get(), activityStarterProvider.get(), falsingManagerProvider.get(), secureSettingsProvider.get(), userTrackerProvider.get(), contentResolverProvider.get(), configurationControllerProvider.get(), statusBarStateControllerProvider.get(), deviceProvisionedControllerProvider.get(), executionProvider.get(), uiExecutorProvider.get(), handlerProvider.get(), optionalPluginProvider.get());
  }

  public static LockscreenSmartspaceController_Factory create(Provider<Context> contextProvider,
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<SmartspaceManager> smartspaceManagerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<FalsingManager> falsingManagerProvider,
      Provider<SecureSettings> secureSettingsProvider, Provider<UserTracker> userTrackerProvider,
      Provider<ContentResolver> contentResolverProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<DeviceProvisionedController> deviceProvisionedControllerProvider,
      Provider<Execution> executionProvider, Provider<Executor> uiExecutorProvider,
      Provider<Handler> handlerProvider,
      Provider<Optional<BcSmartspaceDataPlugin>> optionalPluginProvider) {
    return new LockscreenSmartspaceController_Factory(contextProvider, featureFlagsProvider, smartspaceManagerProvider, activityStarterProvider, falsingManagerProvider, secureSettingsProvider, userTrackerProvider, contentResolverProvider, configurationControllerProvider, statusBarStateControllerProvider, deviceProvisionedControllerProvider, executionProvider, uiExecutorProvider, handlerProvider, optionalPluginProvider);
  }

  public static LockscreenSmartspaceController newInstance(Context context,
      FeatureFlags featureFlags, SmartspaceManager smartspaceManager,
      ActivityStarter activityStarter, FalsingManager falsingManager, SecureSettings secureSettings,
      UserTracker userTracker, ContentResolver contentResolver,
      ConfigurationController configurationController,
      StatusBarStateController statusBarStateController,
      DeviceProvisionedController deviceProvisionedController, Execution execution,
      Executor uiExecutor, Handler handler, Optional<BcSmartspaceDataPlugin> optionalPlugin) {
    return new LockscreenSmartspaceController(context, featureFlags, smartspaceManager, activityStarter, falsingManager, secureSettings, userTracker, contentResolver, configurationController, statusBarStateController, deviceProvisionedController, execution, uiExecutor, handler, optionalPlugin);
  }
}
