package com.android.systemui;

import android.app.AlarmManager;
import android.app.INotificationManager;
import android.app.IWallpaperManager;
import android.hardware.SensorPrivacyManager;
import android.hardware.display.NightDisplayListener;
import android.os.Handler;
import android.os.Looper;
import android.util.DisplayMetrics;
import android.view.IWindowManager;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.statusbar.IStatusBarService;
import com.android.keyguard.KeyguardSecurityModel;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.clock.ClockManager;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver;
import com.android.systemui.accessibility.AccessibilityButtonTargetsObserver;
import com.android.systemui.accessibility.floatingmenu.AccessibilityFloatingMenuController;
import com.android.systemui.appops.AppOpsController;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.dock.DockManager;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.fragments.FragmentService;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.media.dialog.MediaOutputDialogFactory;
import com.android.systemui.model.SysUiState;
import com.android.systemui.navigationbar.NavigationBarController;
import com.android.systemui.navigationbar.NavigationBarOverlayController;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.navigationbar.gestural.EdgeBackGestureHandler;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.DarkIconDispatcher;
import com.android.systemui.plugins.PluginDependencyProvider;
import com.android.systemui.plugins.VolumeDialogController;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.power.EnhancedEstimates;
import com.android.systemui.power.PowerUI;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.qs.ReduceBrightColorsController;
import com.android.systemui.qs.tiles.dialog.InternetDialogFactory;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.screenrecord.RecordingController;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.shared.system.DevicePolicyManagerWrapper;
import com.android.systemui.shared.system.PackageManagerWrapper;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationLockscreenUserManager;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationShadeWindowController;
import com.android.systemui.statusbar.NotificationViewHierarchyManager;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.VibratorHelper;
import com.android.systemui.statusbar.events.PrivacyDotViewController;
import com.android.systemui.statusbar.events.SystemStatusAnimationScheduler;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationFilter;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.notification.collection.render.GroupExpansionManager;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.logging.NotificationLogger;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.notification.stack.AmbientState;
import com.android.systemui.statusbar.notification.stack.NotificationSectionsManager;
import com.android.systemui.statusbar.phone.AutoHideController;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.phone.LightBarController;
import com.android.systemui.statusbar.phone.LockscreenGestureLogger;
import com.android.systemui.statusbar.phone.ManagedProfileController;
import com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper;
import com.android.systemui.statusbar.phone.ShadeController;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider;
import com.android.systemui.statusbar.phone.StatusBarIconController;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.policy.AccessibilityController;
import com.android.systemui.statusbar.policy.AccessibilityManagerWrapper;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.BluetoothController;
import com.android.systemui.statusbar.policy.CastController;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DataSaverController;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.ExtensionController;
import com.android.systemui.statusbar.policy.FlashlightController;
import com.android.systemui.statusbar.policy.HotspotController;
import com.android.systemui.statusbar.policy.KeyguardStateController;
import com.android.systemui.statusbar.policy.LocationController;
import com.android.systemui.statusbar.policy.NextAlarmController;
import com.android.systemui.statusbar.policy.RemoteInputQuickSettingsDisabler;
import com.android.systemui.statusbar.policy.RotationLockController;
import com.android.systemui.statusbar.policy.SecurityController;
import com.android.systemui.statusbar.policy.SensorPrivacyController;
import com.android.systemui.statusbar.policy.SmartReplyConstants;
import com.android.systemui.statusbar.policy.UserInfoController;
import com.android.systemui.statusbar.policy.UserSwitcherController;
import com.android.systemui.statusbar.policy.ZenModeController;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.telephony.TelephonyListenerManager;
import com.android.systemui.tracing.ProtoTracer;
import com.android.systemui.tuner.TunablePadding;
import com.android.systemui.tuner.TunerService;
import com.android.systemui.util.DeviceConfigProxy;
import com.android.systemui.util.leak.GarbageMonitor;
import com.android.systemui.util.leak.LeakDetector;
import com.android.systemui.util.leak.LeakReporter;
import com.android.systemui.util.sensors.AsyncSensorManager;
import dagger.internal.DoubleCheck;
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
public final class Dependency_Factory implements Factory<Dependency> {
  private final Provider<DumpManager> mDumpManagerProvider;

  private final Provider<ActivityStarter> mActivityStarterProvider;

  private final Provider<BroadcastDispatcher> mBroadcastDispatcherProvider;

  private final Provider<AsyncSensorManager> mAsyncSensorManagerProvider;

  private final Provider<BluetoothController> mBluetoothControllerProvider;

  private final Provider<LocationController> mLocationControllerProvider;

  private final Provider<RotationLockController> mRotationLockControllerProvider;

  private final Provider<ZenModeController> mZenModeControllerProvider;

  private final Provider<HotspotController> mHotspotControllerProvider;

  private final Provider<CastController> mCastControllerProvider;

  private final Provider<FlashlightController> mFlashlightControllerProvider;

  private final Provider<UserSwitcherController> mUserSwitcherControllerProvider;

  private final Provider<UserInfoController> mUserInfoControllerProvider;

  private final Provider<KeyguardStateController> mKeyguardMonitorProvider;

  private final Provider<KeyguardUpdateMonitor> mKeyguardUpdateMonitorProvider;

  private final Provider<BatteryController> mBatteryControllerProvider;

  private final Provider<NightDisplayListener> mNightDisplayListenerProvider;

  private final Provider<ReduceBrightColorsController> mReduceBrightColorsControllerProvider;

  private final Provider<ManagedProfileController> mManagedProfileControllerProvider;

  private final Provider<NextAlarmController> mNextAlarmControllerProvider;

  private final Provider<DataSaverController> mDataSaverControllerProvider;

  private final Provider<AccessibilityController> mAccessibilityControllerProvider;

  private final Provider<DeviceProvisionedController> mDeviceProvisionedControllerProvider;

  private final Provider<PluginManager> mPluginManagerProvider;

  private final Provider<AssistManager> mAssistManagerProvider;

  private final Provider<SecurityController> mSecurityControllerProvider;

  private final Provider<LeakDetector> mLeakDetectorProvider;

  private final Provider<LeakReporter> mLeakReporterProvider;

  private final Provider<GarbageMonitor> mGarbageMonitorProvider;

  private final Provider<TunerService> mTunerServiceProvider;

  private final Provider<NotificationShadeWindowController> mNotificationShadeWindowControllerProvider;

  private final Provider<StatusBarWindowController> mTempStatusBarWindowControllerProvider;

  private final Provider<DarkIconDispatcher> mDarkIconDispatcherProvider;

  private final Provider<ConfigurationController> mConfigurationControllerProvider;

  private final Provider<StatusBarIconController> mStatusBarIconControllerProvider;

  private final Provider<ScreenLifecycle> mScreenLifecycleProvider;

  private final Provider<WakefulnessLifecycle> mWakefulnessLifecycleProvider;

  private final Provider<FragmentService> mFragmentServiceProvider;

  private final Provider<ExtensionController> mExtensionControllerProvider;

  private final Provider<PluginDependencyProvider> mPluginDependencyProvider;

  private final Provider<LocalBluetoothManager> mLocalBluetoothManagerProvider;

  private final Provider<VolumeDialogController> mVolumeDialogControllerProvider;

  private final Provider<MetricsLogger> mMetricsLoggerProvider;

  private final Provider<AccessibilityManagerWrapper> mAccessibilityManagerWrapperProvider;

  private final Provider<SysuiColorExtractor> mSysuiColorExtractorProvider;

  private final Provider<TunablePadding.TunablePaddingService> mTunablePaddingServiceProvider;

  private final Provider<ForegroundServiceController> mForegroundServiceControllerProvider;

  private final Provider<UiOffloadThread> mUiOffloadThreadProvider;

  private final Provider<PowerUI.WarningsUI> mWarningsUIProvider;

  private final Provider<LightBarController> mLightBarControllerProvider;

  private final Provider<IWindowManager> mIWindowManagerProvider;

  private final Provider<OverviewProxyService> mOverviewProxyServiceProvider;

  private final Provider<NavigationModeController> mNavBarModeControllerProvider;

  private final Provider<AccessibilityButtonModeObserver> mAccessibilityButtonModeObserverProvider;

  private final Provider<AccessibilityButtonTargetsObserver> mAccessibilityButtonListControllerProvider;

  private final Provider<EnhancedEstimates> mEnhancedEstimatesProvider;

  private final Provider<VibratorHelper> mVibratorHelperProvider;

  private final Provider<IStatusBarService> mIStatusBarServiceProvider;

  private final Provider<DisplayMetrics> mDisplayMetricsProvider;

  private final Provider<LockscreenGestureLogger> mLockscreenGestureLoggerProvider;

  private final Provider<NotificationEntryManager.KeyguardEnvironment> mKeyguardEnvironmentProvider;

  private final Provider<ShadeController> mShadeControllerProvider;

  private final Provider<NotificationRemoteInputManager.Callback> mNotificationRemoteInputManagerCallbackProvider;

  private final Provider<AppOpsController> mAppOpsControllerProvider;

  private final Provider<NavigationBarController> mNavigationBarControllerProvider;

  private final Provider<AccessibilityFloatingMenuController> mAccessibilityFloatingMenuControllerProvider;

  private final Provider<StatusBarStateController> mStatusBarStateControllerProvider;

  private final Provider<NotificationLockscreenUserManager> mNotificationLockscreenUserManagerProvider;

  private final Provider<NotificationGroupAlertTransferHelper> mNotificationGroupAlertTransferHelperProvider;

  private final Provider<NotificationGroupManagerLegacy> mNotificationGroupManagerProvider;

  private final Provider<VisualStabilityManager> mVisualStabilityManagerProvider;

  private final Provider<NotificationGutsManager> mNotificationGutsManagerProvider;

  private final Provider<NotificationMediaManager> mNotificationMediaManagerProvider;

  private final Provider<NotificationRemoteInputManager> mNotificationRemoteInputManagerProvider;

  private final Provider<SmartReplyConstants> mSmartReplyConstantsProvider;

  private final Provider<NotificationListener> mNotificationListenerProvider;

  private final Provider<NotificationLogger> mNotificationLoggerProvider;

  private final Provider<NotificationViewHierarchyManager> mNotificationViewHierarchyManagerProvider;

  private final Provider<NotificationFilter> mNotificationFilterProvider;

  private final Provider<KeyguardDismissUtil> mKeyguardDismissUtilProvider;

  private final Provider<SmartReplyController> mSmartReplyControllerProvider;

  private final Provider<RemoteInputQuickSettingsDisabler> mRemoteInputQuickSettingsDisablerProvider;

  private final Provider<NotificationEntryManager> mNotificationEntryManagerProvider;

  private final Provider<SensorPrivacyManager> mSensorPrivacyManagerProvider;

  private final Provider<AutoHideController> mAutoHideControllerProvider;

  private final Provider<ForegroundServiceNotificationListener> mForegroundServiceNotificationListenerProvider;

  private final Provider<PrivacyItemController> mPrivacyItemControllerProvider;

  private final Provider<Looper> mBgLooperProvider;

  private final Provider<Handler> mBgHandlerProvider;

  private final Provider<Looper> mMainLooperProvider;

  private final Provider<Handler> mMainHandlerProvider;

  private final Provider<Handler> mTimeTickHandlerProvider;

  private final Provider<String> mLeakReportEmailProvider;

  private final Provider<Executor> mMainExecutorProvider;

  private final Provider<Executor> mBackgroundExecutorProvider;

  private final Provider<ClockManager> mClockManagerProvider;

  private final Provider<ActivityManagerWrapper> mActivityManagerWrapperProvider;

  private final Provider<DevicePolicyManagerWrapper> mDevicePolicyManagerWrapperProvider;

  private final Provider<PackageManagerWrapper> mPackageManagerWrapperProvider;

  private final Provider<SensorPrivacyController> mSensorPrivacyControllerProvider;

  private final Provider<DockManager> mDockManagerProvider;

  private final Provider<INotificationManager> mINotificationManagerProvider;

  private final Provider<SysUiState> mSysUiStateFlagsContainerProvider;

  private final Provider<AlarmManager> mAlarmManagerProvider;

  private final Provider<KeyguardSecurityModel> mKeyguardSecurityModelProvider;

  private final Provider<DozeParameters> mDozeParametersProvider;

  private final Provider<IWallpaperManager> mWallpaperManagerProvider;

  private final Provider<CommandQueue> mCommandQueueProvider;

  private final Provider<RecordingController> mRecordingControllerProvider;

  private final Provider<ProtoTracer> mProtoTracerProvider;

  private final Provider<MediaOutputDialogFactory> mMediaOutputDialogFactoryProvider;

  private final Provider<DeviceConfigProxy> mDeviceConfigProxyProvider;

  private final Provider<NavigationBarOverlayController> mNavbarButtonsControllerLazyProvider;

  private final Provider<TelephonyListenerManager> mTelephonyListenerManagerProvider;

  private final Provider<SystemStatusAnimationScheduler> mSystemStatusAnimationSchedulerLazyProvider;

  private final Provider<PrivacyDotViewController> mPrivacyDotViewControllerLazyProvider;

  private final Provider<EdgeBackGestureHandler.Factory> mEdgeBackGestureHandlerFactoryLazyProvider;

  private final Provider<UiEventLogger> mUiEventLoggerProvider;

  private final Provider<FeatureFlags> mFeatureFlagsLazyProvider;

  private final Provider<StatusBarContentInsetsProvider> mContentInsetsProviderLazyProvider;

  private final Provider<InternetDialogFactory> mInternetDialogFactoryProvider;

  private final Provider<NotificationSectionsManager> mNotificationSectionsManagerLazyProvider;

  private final Provider<UnlockedScreenOffAnimationController> mUnlockedScreenOffAnimationControllerLazyProvider;

  private final Provider<AmbientState> mAmbientStateLazyProvider;

  private final Provider<GroupMembershipManager> mGroupMembershipManagerLazyProvider;

  private final Provider<GroupExpansionManager> mGroupExpansionManagerLazyProvider;

  private final Provider<AuthController> mAuthControllerProvider;

  public Dependency_Factory(Provider<DumpManager> mDumpManagerProvider,
      Provider<ActivityStarter> mActivityStarterProvider,
      Provider<BroadcastDispatcher> mBroadcastDispatcherProvider,
      Provider<AsyncSensorManager> mAsyncSensorManagerProvider,
      Provider<BluetoothController> mBluetoothControllerProvider,
      Provider<LocationController> mLocationControllerProvider,
      Provider<RotationLockController> mRotationLockControllerProvider,
      Provider<ZenModeController> mZenModeControllerProvider,
      Provider<HotspotController> mHotspotControllerProvider,
      Provider<CastController> mCastControllerProvider,
      Provider<FlashlightController> mFlashlightControllerProvider,
      Provider<UserSwitcherController> mUserSwitcherControllerProvider,
      Provider<UserInfoController> mUserInfoControllerProvider,
      Provider<KeyguardStateController> mKeyguardMonitorProvider,
      Provider<KeyguardUpdateMonitor> mKeyguardUpdateMonitorProvider,
      Provider<BatteryController> mBatteryControllerProvider,
      Provider<NightDisplayListener> mNightDisplayListenerProvider,
      Provider<ReduceBrightColorsController> mReduceBrightColorsControllerProvider,
      Provider<ManagedProfileController> mManagedProfileControllerProvider,
      Provider<NextAlarmController> mNextAlarmControllerProvider,
      Provider<DataSaverController> mDataSaverControllerProvider,
      Provider<AccessibilityController> mAccessibilityControllerProvider,
      Provider<DeviceProvisionedController> mDeviceProvisionedControllerProvider,
      Provider<PluginManager> mPluginManagerProvider,
      Provider<AssistManager> mAssistManagerProvider,
      Provider<SecurityController> mSecurityControllerProvider,
      Provider<LeakDetector> mLeakDetectorProvider, Provider<LeakReporter> mLeakReporterProvider,
      Provider<GarbageMonitor> mGarbageMonitorProvider,
      Provider<TunerService> mTunerServiceProvider,
      Provider<NotificationShadeWindowController> mNotificationShadeWindowControllerProvider,
      Provider<StatusBarWindowController> mTempStatusBarWindowControllerProvider,
      Provider<DarkIconDispatcher> mDarkIconDispatcherProvider,
      Provider<ConfigurationController> mConfigurationControllerProvider,
      Provider<StatusBarIconController> mStatusBarIconControllerProvider,
      Provider<ScreenLifecycle> mScreenLifecycleProvider,
      Provider<WakefulnessLifecycle> mWakefulnessLifecycleProvider,
      Provider<FragmentService> mFragmentServiceProvider,
      Provider<ExtensionController> mExtensionControllerProvider,
      Provider<PluginDependencyProvider> mPluginDependencyProvider,
      Provider<LocalBluetoothManager> mLocalBluetoothManagerProvider,
      Provider<VolumeDialogController> mVolumeDialogControllerProvider,
      Provider<MetricsLogger> mMetricsLoggerProvider,
      Provider<AccessibilityManagerWrapper> mAccessibilityManagerWrapperProvider,
      Provider<SysuiColorExtractor> mSysuiColorExtractorProvider,
      Provider<TunablePadding.TunablePaddingService> mTunablePaddingServiceProvider,
      Provider<ForegroundServiceController> mForegroundServiceControllerProvider,
      Provider<UiOffloadThread> mUiOffloadThreadProvider,
      Provider<PowerUI.WarningsUI> mWarningsUIProvider,
      Provider<LightBarController> mLightBarControllerProvider,
      Provider<IWindowManager> mIWindowManagerProvider,
      Provider<OverviewProxyService> mOverviewProxyServiceProvider,
      Provider<NavigationModeController> mNavBarModeControllerProvider,
      Provider<AccessibilityButtonModeObserver> mAccessibilityButtonModeObserverProvider,
      Provider<AccessibilityButtonTargetsObserver> mAccessibilityButtonListControllerProvider,
      Provider<EnhancedEstimates> mEnhancedEstimatesProvider,
      Provider<VibratorHelper> mVibratorHelperProvider,
      Provider<IStatusBarService> mIStatusBarServiceProvider,
      Provider<DisplayMetrics> mDisplayMetricsProvider,
      Provider<LockscreenGestureLogger> mLockscreenGestureLoggerProvider,
      Provider<NotificationEntryManager.KeyguardEnvironment> mKeyguardEnvironmentProvider,
      Provider<ShadeController> mShadeControllerProvider,
      Provider<NotificationRemoteInputManager.Callback> mNotificationRemoteInputManagerCallbackProvider,
      Provider<AppOpsController> mAppOpsControllerProvider,
      Provider<NavigationBarController> mNavigationBarControllerProvider,
      Provider<AccessibilityFloatingMenuController> mAccessibilityFloatingMenuControllerProvider,
      Provider<StatusBarStateController> mStatusBarStateControllerProvider,
      Provider<NotificationLockscreenUserManager> mNotificationLockscreenUserManagerProvider,
      Provider<NotificationGroupAlertTransferHelper> mNotificationGroupAlertTransferHelperProvider,
      Provider<NotificationGroupManagerLegacy> mNotificationGroupManagerProvider,
      Provider<VisualStabilityManager> mVisualStabilityManagerProvider,
      Provider<NotificationGutsManager> mNotificationGutsManagerProvider,
      Provider<NotificationMediaManager> mNotificationMediaManagerProvider,
      Provider<NotificationRemoteInputManager> mNotificationRemoteInputManagerProvider,
      Provider<SmartReplyConstants> mSmartReplyConstantsProvider,
      Provider<NotificationListener> mNotificationListenerProvider,
      Provider<NotificationLogger> mNotificationLoggerProvider,
      Provider<NotificationViewHierarchyManager> mNotificationViewHierarchyManagerProvider,
      Provider<NotificationFilter> mNotificationFilterProvider,
      Provider<KeyguardDismissUtil> mKeyguardDismissUtilProvider,
      Provider<SmartReplyController> mSmartReplyControllerProvider,
      Provider<RemoteInputQuickSettingsDisabler> mRemoteInputQuickSettingsDisablerProvider,
      Provider<NotificationEntryManager> mNotificationEntryManagerProvider,
      Provider<SensorPrivacyManager> mSensorPrivacyManagerProvider,
      Provider<AutoHideController> mAutoHideControllerProvider,
      Provider<ForegroundServiceNotificationListener> mForegroundServiceNotificationListenerProvider,
      Provider<PrivacyItemController> mPrivacyItemControllerProvider,
      Provider<Looper> mBgLooperProvider, Provider<Handler> mBgHandlerProvider,
      Provider<Looper> mMainLooperProvider, Provider<Handler> mMainHandlerProvider,
      Provider<Handler> mTimeTickHandlerProvider, Provider<String> mLeakReportEmailProvider,
      Provider<Executor> mMainExecutorProvider, Provider<Executor> mBackgroundExecutorProvider,
      Provider<ClockManager> mClockManagerProvider,
      Provider<ActivityManagerWrapper> mActivityManagerWrapperProvider,
      Provider<DevicePolicyManagerWrapper> mDevicePolicyManagerWrapperProvider,
      Provider<PackageManagerWrapper> mPackageManagerWrapperProvider,
      Provider<SensorPrivacyController> mSensorPrivacyControllerProvider,
      Provider<DockManager> mDockManagerProvider,
      Provider<INotificationManager> mINotificationManagerProvider,
      Provider<SysUiState> mSysUiStateFlagsContainerProvider,
      Provider<AlarmManager> mAlarmManagerProvider,
      Provider<KeyguardSecurityModel> mKeyguardSecurityModelProvider,
      Provider<DozeParameters> mDozeParametersProvider,
      Provider<IWallpaperManager> mWallpaperManagerProvider,
      Provider<CommandQueue> mCommandQueueProvider,
      Provider<RecordingController> mRecordingControllerProvider,
      Provider<ProtoTracer> mProtoTracerProvider,
      Provider<MediaOutputDialogFactory> mMediaOutputDialogFactoryProvider,
      Provider<DeviceConfigProxy> mDeviceConfigProxyProvider,
      Provider<NavigationBarOverlayController> mNavbarButtonsControllerLazyProvider,
      Provider<TelephonyListenerManager> mTelephonyListenerManagerProvider,
      Provider<SystemStatusAnimationScheduler> mSystemStatusAnimationSchedulerLazyProvider,
      Provider<PrivacyDotViewController> mPrivacyDotViewControllerLazyProvider,
      Provider<EdgeBackGestureHandler.Factory> mEdgeBackGestureHandlerFactoryLazyProvider,
      Provider<UiEventLogger> mUiEventLoggerProvider,
      Provider<FeatureFlags> mFeatureFlagsLazyProvider,
      Provider<StatusBarContentInsetsProvider> mContentInsetsProviderLazyProvider,
      Provider<InternetDialogFactory> mInternetDialogFactoryProvider,
      Provider<NotificationSectionsManager> mNotificationSectionsManagerLazyProvider,
      Provider<UnlockedScreenOffAnimationController> mUnlockedScreenOffAnimationControllerLazyProvider,
      Provider<AmbientState> mAmbientStateLazyProvider,
      Provider<GroupMembershipManager> mGroupMembershipManagerLazyProvider,
      Provider<GroupExpansionManager> mGroupExpansionManagerLazyProvider,
      Provider<AuthController> mAuthControllerProvider) {
    this.mDumpManagerProvider = mDumpManagerProvider;
    this.mActivityStarterProvider = mActivityStarterProvider;
    this.mBroadcastDispatcherProvider = mBroadcastDispatcherProvider;
    this.mAsyncSensorManagerProvider = mAsyncSensorManagerProvider;
    this.mBluetoothControllerProvider = mBluetoothControllerProvider;
    this.mLocationControllerProvider = mLocationControllerProvider;
    this.mRotationLockControllerProvider = mRotationLockControllerProvider;
    this.mZenModeControllerProvider = mZenModeControllerProvider;
    this.mHotspotControllerProvider = mHotspotControllerProvider;
    this.mCastControllerProvider = mCastControllerProvider;
    this.mFlashlightControllerProvider = mFlashlightControllerProvider;
    this.mUserSwitcherControllerProvider = mUserSwitcherControllerProvider;
    this.mUserInfoControllerProvider = mUserInfoControllerProvider;
    this.mKeyguardMonitorProvider = mKeyguardMonitorProvider;
    this.mKeyguardUpdateMonitorProvider = mKeyguardUpdateMonitorProvider;
    this.mBatteryControllerProvider = mBatteryControllerProvider;
    this.mNightDisplayListenerProvider = mNightDisplayListenerProvider;
    this.mReduceBrightColorsControllerProvider = mReduceBrightColorsControllerProvider;
    this.mManagedProfileControllerProvider = mManagedProfileControllerProvider;
    this.mNextAlarmControllerProvider = mNextAlarmControllerProvider;
    this.mDataSaverControllerProvider = mDataSaverControllerProvider;
    this.mAccessibilityControllerProvider = mAccessibilityControllerProvider;
    this.mDeviceProvisionedControllerProvider = mDeviceProvisionedControllerProvider;
    this.mPluginManagerProvider = mPluginManagerProvider;
    this.mAssistManagerProvider = mAssistManagerProvider;
    this.mSecurityControllerProvider = mSecurityControllerProvider;
    this.mLeakDetectorProvider = mLeakDetectorProvider;
    this.mLeakReporterProvider = mLeakReporterProvider;
    this.mGarbageMonitorProvider = mGarbageMonitorProvider;
    this.mTunerServiceProvider = mTunerServiceProvider;
    this.mNotificationShadeWindowControllerProvider = mNotificationShadeWindowControllerProvider;
    this.mTempStatusBarWindowControllerProvider = mTempStatusBarWindowControllerProvider;
    this.mDarkIconDispatcherProvider = mDarkIconDispatcherProvider;
    this.mConfigurationControllerProvider = mConfigurationControllerProvider;
    this.mStatusBarIconControllerProvider = mStatusBarIconControllerProvider;
    this.mScreenLifecycleProvider = mScreenLifecycleProvider;
    this.mWakefulnessLifecycleProvider = mWakefulnessLifecycleProvider;
    this.mFragmentServiceProvider = mFragmentServiceProvider;
    this.mExtensionControllerProvider = mExtensionControllerProvider;
    this.mPluginDependencyProvider = mPluginDependencyProvider;
    this.mLocalBluetoothManagerProvider = mLocalBluetoothManagerProvider;
    this.mVolumeDialogControllerProvider = mVolumeDialogControllerProvider;
    this.mMetricsLoggerProvider = mMetricsLoggerProvider;
    this.mAccessibilityManagerWrapperProvider = mAccessibilityManagerWrapperProvider;
    this.mSysuiColorExtractorProvider = mSysuiColorExtractorProvider;
    this.mTunablePaddingServiceProvider = mTunablePaddingServiceProvider;
    this.mForegroundServiceControllerProvider = mForegroundServiceControllerProvider;
    this.mUiOffloadThreadProvider = mUiOffloadThreadProvider;
    this.mWarningsUIProvider = mWarningsUIProvider;
    this.mLightBarControllerProvider = mLightBarControllerProvider;
    this.mIWindowManagerProvider = mIWindowManagerProvider;
    this.mOverviewProxyServiceProvider = mOverviewProxyServiceProvider;
    this.mNavBarModeControllerProvider = mNavBarModeControllerProvider;
    this.mAccessibilityButtonModeObserverProvider = mAccessibilityButtonModeObserverProvider;
    this.mAccessibilityButtonListControllerProvider = mAccessibilityButtonListControllerProvider;
    this.mEnhancedEstimatesProvider = mEnhancedEstimatesProvider;
    this.mVibratorHelperProvider = mVibratorHelperProvider;
    this.mIStatusBarServiceProvider = mIStatusBarServiceProvider;
    this.mDisplayMetricsProvider = mDisplayMetricsProvider;
    this.mLockscreenGestureLoggerProvider = mLockscreenGestureLoggerProvider;
    this.mKeyguardEnvironmentProvider = mKeyguardEnvironmentProvider;
    this.mShadeControllerProvider = mShadeControllerProvider;
    this.mNotificationRemoteInputManagerCallbackProvider = mNotificationRemoteInputManagerCallbackProvider;
    this.mAppOpsControllerProvider = mAppOpsControllerProvider;
    this.mNavigationBarControllerProvider = mNavigationBarControllerProvider;
    this.mAccessibilityFloatingMenuControllerProvider = mAccessibilityFloatingMenuControllerProvider;
    this.mStatusBarStateControllerProvider = mStatusBarStateControllerProvider;
    this.mNotificationLockscreenUserManagerProvider = mNotificationLockscreenUserManagerProvider;
    this.mNotificationGroupAlertTransferHelperProvider = mNotificationGroupAlertTransferHelperProvider;
    this.mNotificationGroupManagerProvider = mNotificationGroupManagerProvider;
    this.mVisualStabilityManagerProvider = mVisualStabilityManagerProvider;
    this.mNotificationGutsManagerProvider = mNotificationGutsManagerProvider;
    this.mNotificationMediaManagerProvider = mNotificationMediaManagerProvider;
    this.mNotificationRemoteInputManagerProvider = mNotificationRemoteInputManagerProvider;
    this.mSmartReplyConstantsProvider = mSmartReplyConstantsProvider;
    this.mNotificationListenerProvider = mNotificationListenerProvider;
    this.mNotificationLoggerProvider = mNotificationLoggerProvider;
    this.mNotificationViewHierarchyManagerProvider = mNotificationViewHierarchyManagerProvider;
    this.mNotificationFilterProvider = mNotificationFilterProvider;
    this.mKeyguardDismissUtilProvider = mKeyguardDismissUtilProvider;
    this.mSmartReplyControllerProvider = mSmartReplyControllerProvider;
    this.mRemoteInputQuickSettingsDisablerProvider = mRemoteInputQuickSettingsDisablerProvider;
    this.mNotificationEntryManagerProvider = mNotificationEntryManagerProvider;
    this.mSensorPrivacyManagerProvider = mSensorPrivacyManagerProvider;
    this.mAutoHideControllerProvider = mAutoHideControllerProvider;
    this.mForegroundServiceNotificationListenerProvider = mForegroundServiceNotificationListenerProvider;
    this.mPrivacyItemControllerProvider = mPrivacyItemControllerProvider;
    this.mBgLooperProvider = mBgLooperProvider;
    this.mBgHandlerProvider = mBgHandlerProvider;
    this.mMainLooperProvider = mMainLooperProvider;
    this.mMainHandlerProvider = mMainHandlerProvider;
    this.mTimeTickHandlerProvider = mTimeTickHandlerProvider;
    this.mLeakReportEmailProvider = mLeakReportEmailProvider;
    this.mMainExecutorProvider = mMainExecutorProvider;
    this.mBackgroundExecutorProvider = mBackgroundExecutorProvider;
    this.mClockManagerProvider = mClockManagerProvider;
    this.mActivityManagerWrapperProvider = mActivityManagerWrapperProvider;
    this.mDevicePolicyManagerWrapperProvider = mDevicePolicyManagerWrapperProvider;
    this.mPackageManagerWrapperProvider = mPackageManagerWrapperProvider;
    this.mSensorPrivacyControllerProvider = mSensorPrivacyControllerProvider;
    this.mDockManagerProvider = mDockManagerProvider;
    this.mINotificationManagerProvider = mINotificationManagerProvider;
    this.mSysUiStateFlagsContainerProvider = mSysUiStateFlagsContainerProvider;
    this.mAlarmManagerProvider = mAlarmManagerProvider;
    this.mKeyguardSecurityModelProvider = mKeyguardSecurityModelProvider;
    this.mDozeParametersProvider = mDozeParametersProvider;
    this.mWallpaperManagerProvider = mWallpaperManagerProvider;
    this.mCommandQueueProvider = mCommandQueueProvider;
    this.mRecordingControllerProvider = mRecordingControllerProvider;
    this.mProtoTracerProvider = mProtoTracerProvider;
    this.mMediaOutputDialogFactoryProvider = mMediaOutputDialogFactoryProvider;
    this.mDeviceConfigProxyProvider = mDeviceConfigProxyProvider;
    this.mNavbarButtonsControllerLazyProvider = mNavbarButtonsControllerLazyProvider;
    this.mTelephonyListenerManagerProvider = mTelephonyListenerManagerProvider;
    this.mSystemStatusAnimationSchedulerLazyProvider = mSystemStatusAnimationSchedulerLazyProvider;
    this.mPrivacyDotViewControllerLazyProvider = mPrivacyDotViewControllerLazyProvider;
    this.mEdgeBackGestureHandlerFactoryLazyProvider = mEdgeBackGestureHandlerFactoryLazyProvider;
    this.mUiEventLoggerProvider = mUiEventLoggerProvider;
    this.mFeatureFlagsLazyProvider = mFeatureFlagsLazyProvider;
    this.mContentInsetsProviderLazyProvider = mContentInsetsProviderLazyProvider;
    this.mInternetDialogFactoryProvider = mInternetDialogFactoryProvider;
    this.mNotificationSectionsManagerLazyProvider = mNotificationSectionsManagerLazyProvider;
    this.mUnlockedScreenOffAnimationControllerLazyProvider = mUnlockedScreenOffAnimationControllerLazyProvider;
    this.mAmbientStateLazyProvider = mAmbientStateLazyProvider;
    this.mGroupMembershipManagerLazyProvider = mGroupMembershipManagerLazyProvider;
    this.mGroupExpansionManagerLazyProvider = mGroupExpansionManagerLazyProvider;
    this.mAuthControllerProvider = mAuthControllerProvider;
  }

  @Override
  public Dependency get() {
    Dependency instance = newInstance();
    Dependency_MembersInjector.injectMDumpManager(instance, mDumpManagerProvider.get());
    Dependency_MembersInjector.injectMActivityStarter(instance, DoubleCheck.lazy(mActivityStarterProvider));
    Dependency_MembersInjector.injectMBroadcastDispatcher(instance, DoubleCheck.lazy(mBroadcastDispatcherProvider));
    Dependency_MembersInjector.injectMAsyncSensorManager(instance, DoubleCheck.lazy(mAsyncSensorManagerProvider));
    Dependency_MembersInjector.injectMBluetoothController(instance, DoubleCheck.lazy(mBluetoothControllerProvider));
    Dependency_MembersInjector.injectMLocationController(instance, DoubleCheck.lazy(mLocationControllerProvider));
    Dependency_MembersInjector.injectMRotationLockController(instance, DoubleCheck.lazy(mRotationLockControllerProvider));
    Dependency_MembersInjector.injectMZenModeController(instance, DoubleCheck.lazy(mZenModeControllerProvider));
    Dependency_MembersInjector.injectMHotspotController(instance, DoubleCheck.lazy(mHotspotControllerProvider));
    Dependency_MembersInjector.injectMCastController(instance, DoubleCheck.lazy(mCastControllerProvider));
    Dependency_MembersInjector.injectMFlashlightController(instance, DoubleCheck.lazy(mFlashlightControllerProvider));
    Dependency_MembersInjector.injectMUserSwitcherController(instance, DoubleCheck.lazy(mUserSwitcherControllerProvider));
    Dependency_MembersInjector.injectMUserInfoController(instance, DoubleCheck.lazy(mUserInfoControllerProvider));
    Dependency_MembersInjector.injectMKeyguardMonitor(instance, DoubleCheck.lazy(mKeyguardMonitorProvider));
    Dependency_MembersInjector.injectMKeyguardUpdateMonitor(instance, DoubleCheck.lazy(mKeyguardUpdateMonitorProvider));
    Dependency_MembersInjector.injectMBatteryController(instance, DoubleCheck.lazy(mBatteryControllerProvider));
    Dependency_MembersInjector.injectMNightDisplayListener(instance, DoubleCheck.lazy(mNightDisplayListenerProvider));
    Dependency_MembersInjector.injectMReduceBrightColorsController(instance, DoubleCheck.lazy(mReduceBrightColorsControllerProvider));
    Dependency_MembersInjector.injectMManagedProfileController(instance, DoubleCheck.lazy(mManagedProfileControllerProvider));
    Dependency_MembersInjector.injectMNextAlarmController(instance, DoubleCheck.lazy(mNextAlarmControllerProvider));
    Dependency_MembersInjector.injectMDataSaverController(instance, DoubleCheck.lazy(mDataSaverControllerProvider));
    Dependency_MembersInjector.injectMAccessibilityController(instance, DoubleCheck.lazy(mAccessibilityControllerProvider));
    Dependency_MembersInjector.injectMDeviceProvisionedController(instance, DoubleCheck.lazy(mDeviceProvisionedControllerProvider));
    Dependency_MembersInjector.injectMPluginManager(instance, DoubleCheck.lazy(mPluginManagerProvider));
    Dependency_MembersInjector.injectMAssistManager(instance, DoubleCheck.lazy(mAssistManagerProvider));
    Dependency_MembersInjector.injectMSecurityController(instance, DoubleCheck.lazy(mSecurityControllerProvider));
    Dependency_MembersInjector.injectMLeakDetector(instance, DoubleCheck.lazy(mLeakDetectorProvider));
    Dependency_MembersInjector.injectMLeakReporter(instance, DoubleCheck.lazy(mLeakReporterProvider));
    Dependency_MembersInjector.injectMGarbageMonitor(instance, DoubleCheck.lazy(mGarbageMonitorProvider));
    Dependency_MembersInjector.injectMTunerService(instance, DoubleCheck.lazy(mTunerServiceProvider));
    Dependency_MembersInjector.injectMNotificationShadeWindowController(instance, DoubleCheck.lazy(mNotificationShadeWindowControllerProvider));
    Dependency_MembersInjector.injectMTempStatusBarWindowController(instance, DoubleCheck.lazy(mTempStatusBarWindowControllerProvider));
    Dependency_MembersInjector.injectMDarkIconDispatcher(instance, DoubleCheck.lazy(mDarkIconDispatcherProvider));
    Dependency_MembersInjector.injectMConfigurationController(instance, DoubleCheck.lazy(mConfigurationControllerProvider));
    Dependency_MembersInjector.injectMStatusBarIconController(instance, DoubleCheck.lazy(mStatusBarIconControllerProvider));
    Dependency_MembersInjector.injectMScreenLifecycle(instance, DoubleCheck.lazy(mScreenLifecycleProvider));
    Dependency_MembersInjector.injectMWakefulnessLifecycle(instance, DoubleCheck.lazy(mWakefulnessLifecycleProvider));
    Dependency_MembersInjector.injectMFragmentService(instance, DoubleCheck.lazy(mFragmentServiceProvider));
    Dependency_MembersInjector.injectMExtensionController(instance, DoubleCheck.lazy(mExtensionControllerProvider));
    Dependency_MembersInjector.injectMPluginDependencyProvider(instance, DoubleCheck.lazy(mPluginDependencyProvider));
    Dependency_MembersInjector.injectMLocalBluetoothManager(instance, DoubleCheck.lazy(mLocalBluetoothManagerProvider));
    Dependency_MembersInjector.injectMVolumeDialogController(instance, DoubleCheck.lazy(mVolumeDialogControllerProvider));
    Dependency_MembersInjector.injectMMetricsLogger(instance, DoubleCheck.lazy(mMetricsLoggerProvider));
    Dependency_MembersInjector.injectMAccessibilityManagerWrapper(instance, DoubleCheck.lazy(mAccessibilityManagerWrapperProvider));
    Dependency_MembersInjector.injectMSysuiColorExtractor(instance, DoubleCheck.lazy(mSysuiColorExtractorProvider));
    Dependency_MembersInjector.injectMTunablePaddingService(instance, DoubleCheck.lazy(mTunablePaddingServiceProvider));
    Dependency_MembersInjector.injectMForegroundServiceController(instance, DoubleCheck.lazy(mForegroundServiceControllerProvider));
    Dependency_MembersInjector.injectMUiOffloadThread(instance, DoubleCheck.lazy(mUiOffloadThreadProvider));
    Dependency_MembersInjector.injectMWarningsUI(instance, DoubleCheck.lazy(mWarningsUIProvider));
    Dependency_MembersInjector.injectMLightBarController(instance, DoubleCheck.lazy(mLightBarControllerProvider));
    Dependency_MembersInjector.injectMIWindowManager(instance, DoubleCheck.lazy(mIWindowManagerProvider));
    Dependency_MembersInjector.injectMOverviewProxyService(instance, DoubleCheck.lazy(mOverviewProxyServiceProvider));
    Dependency_MembersInjector.injectMNavBarModeController(instance, DoubleCheck.lazy(mNavBarModeControllerProvider));
    Dependency_MembersInjector.injectMAccessibilityButtonModeObserver(instance, DoubleCheck.lazy(mAccessibilityButtonModeObserverProvider));
    Dependency_MembersInjector.injectMAccessibilityButtonListController(instance, DoubleCheck.lazy(mAccessibilityButtonListControllerProvider));
    Dependency_MembersInjector.injectMEnhancedEstimates(instance, DoubleCheck.lazy(mEnhancedEstimatesProvider));
    Dependency_MembersInjector.injectMVibratorHelper(instance, DoubleCheck.lazy(mVibratorHelperProvider));
    Dependency_MembersInjector.injectMIStatusBarService(instance, DoubleCheck.lazy(mIStatusBarServiceProvider));
    Dependency_MembersInjector.injectMDisplayMetrics(instance, DoubleCheck.lazy(mDisplayMetricsProvider));
    Dependency_MembersInjector.injectMLockscreenGestureLogger(instance, DoubleCheck.lazy(mLockscreenGestureLoggerProvider));
    Dependency_MembersInjector.injectMKeyguardEnvironment(instance, DoubleCheck.lazy(mKeyguardEnvironmentProvider));
    Dependency_MembersInjector.injectMShadeController(instance, DoubleCheck.lazy(mShadeControllerProvider));
    Dependency_MembersInjector.injectMNotificationRemoteInputManagerCallback(instance, DoubleCheck.lazy(mNotificationRemoteInputManagerCallbackProvider));
    Dependency_MembersInjector.injectMAppOpsController(instance, DoubleCheck.lazy(mAppOpsControllerProvider));
    Dependency_MembersInjector.injectMNavigationBarController(instance, DoubleCheck.lazy(mNavigationBarControllerProvider));
    Dependency_MembersInjector.injectMAccessibilityFloatingMenuController(instance, DoubleCheck.lazy(mAccessibilityFloatingMenuControllerProvider));
    Dependency_MembersInjector.injectMStatusBarStateController(instance, DoubleCheck.lazy(mStatusBarStateControllerProvider));
    Dependency_MembersInjector.injectMNotificationLockscreenUserManager(instance, DoubleCheck.lazy(mNotificationLockscreenUserManagerProvider));
    Dependency_MembersInjector.injectMNotificationGroupAlertTransferHelper(instance, DoubleCheck.lazy(mNotificationGroupAlertTransferHelperProvider));
    Dependency_MembersInjector.injectMNotificationGroupManager(instance, DoubleCheck.lazy(mNotificationGroupManagerProvider));
    Dependency_MembersInjector.injectMVisualStabilityManager(instance, DoubleCheck.lazy(mVisualStabilityManagerProvider));
    Dependency_MembersInjector.injectMNotificationGutsManager(instance, DoubleCheck.lazy(mNotificationGutsManagerProvider));
    Dependency_MembersInjector.injectMNotificationMediaManager(instance, DoubleCheck.lazy(mNotificationMediaManagerProvider));
    Dependency_MembersInjector.injectMNotificationRemoteInputManager(instance, DoubleCheck.lazy(mNotificationRemoteInputManagerProvider));
    Dependency_MembersInjector.injectMSmartReplyConstants(instance, DoubleCheck.lazy(mSmartReplyConstantsProvider));
    Dependency_MembersInjector.injectMNotificationListener(instance, DoubleCheck.lazy(mNotificationListenerProvider));
    Dependency_MembersInjector.injectMNotificationLogger(instance, DoubleCheck.lazy(mNotificationLoggerProvider));
    Dependency_MembersInjector.injectMNotificationViewHierarchyManager(instance, DoubleCheck.lazy(mNotificationViewHierarchyManagerProvider));
    Dependency_MembersInjector.injectMNotificationFilter(instance, DoubleCheck.lazy(mNotificationFilterProvider));
    Dependency_MembersInjector.injectMKeyguardDismissUtil(instance, DoubleCheck.lazy(mKeyguardDismissUtilProvider));
    Dependency_MembersInjector.injectMSmartReplyController(instance, DoubleCheck.lazy(mSmartReplyControllerProvider));
    Dependency_MembersInjector.injectMRemoteInputQuickSettingsDisabler(instance, DoubleCheck.lazy(mRemoteInputQuickSettingsDisablerProvider));
    Dependency_MembersInjector.injectMNotificationEntryManager(instance, DoubleCheck.lazy(mNotificationEntryManagerProvider));
    Dependency_MembersInjector.injectMSensorPrivacyManager(instance, DoubleCheck.lazy(mSensorPrivacyManagerProvider));
    Dependency_MembersInjector.injectMAutoHideController(instance, DoubleCheck.lazy(mAutoHideControllerProvider));
    Dependency_MembersInjector.injectMForegroundServiceNotificationListener(instance, DoubleCheck.lazy(mForegroundServiceNotificationListenerProvider));
    Dependency_MembersInjector.injectMPrivacyItemController(instance, DoubleCheck.lazy(mPrivacyItemControllerProvider));
    Dependency_MembersInjector.injectMBgLooper(instance, DoubleCheck.lazy(mBgLooperProvider));
    Dependency_MembersInjector.injectMBgHandler(instance, DoubleCheck.lazy(mBgHandlerProvider));
    Dependency_MembersInjector.injectMMainLooper(instance, DoubleCheck.lazy(mMainLooperProvider));
    Dependency_MembersInjector.injectMMainHandler(instance, DoubleCheck.lazy(mMainHandlerProvider));
    Dependency_MembersInjector.injectMTimeTickHandler(instance, DoubleCheck.lazy(mTimeTickHandlerProvider));
    Dependency_MembersInjector.injectMLeakReportEmail(instance, DoubleCheck.lazy(mLeakReportEmailProvider));
    Dependency_MembersInjector.injectMMainExecutor(instance, DoubleCheck.lazy(mMainExecutorProvider));
    Dependency_MembersInjector.injectMBackgroundExecutor(instance, DoubleCheck.lazy(mBackgroundExecutorProvider));
    Dependency_MembersInjector.injectMClockManager(instance, DoubleCheck.lazy(mClockManagerProvider));
    Dependency_MembersInjector.injectMActivityManagerWrapper(instance, DoubleCheck.lazy(mActivityManagerWrapperProvider));
    Dependency_MembersInjector.injectMDevicePolicyManagerWrapper(instance, DoubleCheck.lazy(mDevicePolicyManagerWrapperProvider));
    Dependency_MembersInjector.injectMPackageManagerWrapper(instance, DoubleCheck.lazy(mPackageManagerWrapperProvider));
    Dependency_MembersInjector.injectMSensorPrivacyController(instance, DoubleCheck.lazy(mSensorPrivacyControllerProvider));
    Dependency_MembersInjector.injectMDockManager(instance, DoubleCheck.lazy(mDockManagerProvider));
    Dependency_MembersInjector.injectMINotificationManager(instance, DoubleCheck.lazy(mINotificationManagerProvider));
    Dependency_MembersInjector.injectMSysUiStateFlagsContainer(instance, DoubleCheck.lazy(mSysUiStateFlagsContainerProvider));
    Dependency_MembersInjector.injectMAlarmManager(instance, DoubleCheck.lazy(mAlarmManagerProvider));
    Dependency_MembersInjector.injectMKeyguardSecurityModel(instance, DoubleCheck.lazy(mKeyguardSecurityModelProvider));
    Dependency_MembersInjector.injectMDozeParameters(instance, DoubleCheck.lazy(mDozeParametersProvider));
    Dependency_MembersInjector.injectMWallpaperManager(instance, DoubleCheck.lazy(mWallpaperManagerProvider));
    Dependency_MembersInjector.injectMCommandQueue(instance, DoubleCheck.lazy(mCommandQueueProvider));
    Dependency_MembersInjector.injectMRecordingController(instance, DoubleCheck.lazy(mRecordingControllerProvider));
    Dependency_MembersInjector.injectMProtoTracer(instance, DoubleCheck.lazy(mProtoTracerProvider));
    Dependency_MembersInjector.injectMMediaOutputDialogFactory(instance, DoubleCheck.lazy(mMediaOutputDialogFactoryProvider));
    Dependency_MembersInjector.injectMDeviceConfigProxy(instance, DoubleCheck.lazy(mDeviceConfigProxyProvider));
    Dependency_MembersInjector.injectMNavbarButtonsControllerLazy(instance, DoubleCheck.lazy(mNavbarButtonsControllerLazyProvider));
    Dependency_MembersInjector.injectMTelephonyListenerManager(instance, DoubleCheck.lazy(mTelephonyListenerManagerProvider));
    Dependency_MembersInjector.injectMSystemStatusAnimationSchedulerLazy(instance, DoubleCheck.lazy(mSystemStatusAnimationSchedulerLazyProvider));
    Dependency_MembersInjector.injectMPrivacyDotViewControllerLazy(instance, DoubleCheck.lazy(mPrivacyDotViewControllerLazyProvider));
    Dependency_MembersInjector.injectMEdgeBackGestureHandlerFactoryLazy(instance, DoubleCheck.lazy(mEdgeBackGestureHandlerFactoryLazyProvider));
    Dependency_MembersInjector.injectMUiEventLogger(instance, DoubleCheck.lazy(mUiEventLoggerProvider));
    Dependency_MembersInjector.injectMFeatureFlagsLazy(instance, DoubleCheck.lazy(mFeatureFlagsLazyProvider));
    Dependency_MembersInjector.injectMContentInsetsProviderLazy(instance, DoubleCheck.lazy(mContentInsetsProviderLazyProvider));
    Dependency_MembersInjector.injectMInternetDialogFactory(instance, DoubleCheck.lazy(mInternetDialogFactoryProvider));
    Dependency_MembersInjector.injectMNotificationSectionsManagerLazy(instance, DoubleCheck.lazy(mNotificationSectionsManagerLazyProvider));
    Dependency_MembersInjector.injectMUnlockedScreenOffAnimationControllerLazy(instance, DoubleCheck.lazy(mUnlockedScreenOffAnimationControllerLazyProvider));
    Dependency_MembersInjector.injectMAmbientStateLazy(instance, DoubleCheck.lazy(mAmbientStateLazyProvider));
    Dependency_MembersInjector.injectMGroupMembershipManagerLazy(instance, DoubleCheck.lazy(mGroupMembershipManagerLazyProvider));
    Dependency_MembersInjector.injectMGroupExpansionManagerLazy(instance, DoubleCheck.lazy(mGroupExpansionManagerLazyProvider));
    Dependency_MembersInjector.injectMAuthController(instance, DoubleCheck.lazy(mAuthControllerProvider));
    return instance;
  }

  public static Dependency_Factory create(Provider<DumpManager> mDumpManagerProvider,
      Provider<ActivityStarter> mActivityStarterProvider,
      Provider<BroadcastDispatcher> mBroadcastDispatcherProvider,
      Provider<AsyncSensorManager> mAsyncSensorManagerProvider,
      Provider<BluetoothController> mBluetoothControllerProvider,
      Provider<LocationController> mLocationControllerProvider,
      Provider<RotationLockController> mRotationLockControllerProvider,
      Provider<ZenModeController> mZenModeControllerProvider,
      Provider<HotspotController> mHotspotControllerProvider,
      Provider<CastController> mCastControllerProvider,
      Provider<FlashlightController> mFlashlightControllerProvider,
      Provider<UserSwitcherController> mUserSwitcherControllerProvider,
      Provider<UserInfoController> mUserInfoControllerProvider,
      Provider<KeyguardStateController> mKeyguardMonitorProvider,
      Provider<KeyguardUpdateMonitor> mKeyguardUpdateMonitorProvider,
      Provider<BatteryController> mBatteryControllerProvider,
      Provider<NightDisplayListener> mNightDisplayListenerProvider,
      Provider<ReduceBrightColorsController> mReduceBrightColorsControllerProvider,
      Provider<ManagedProfileController> mManagedProfileControllerProvider,
      Provider<NextAlarmController> mNextAlarmControllerProvider,
      Provider<DataSaverController> mDataSaverControllerProvider,
      Provider<AccessibilityController> mAccessibilityControllerProvider,
      Provider<DeviceProvisionedController> mDeviceProvisionedControllerProvider,
      Provider<PluginManager> mPluginManagerProvider,
      Provider<AssistManager> mAssistManagerProvider,
      Provider<SecurityController> mSecurityControllerProvider,
      Provider<LeakDetector> mLeakDetectorProvider, Provider<LeakReporter> mLeakReporterProvider,
      Provider<GarbageMonitor> mGarbageMonitorProvider,
      Provider<TunerService> mTunerServiceProvider,
      Provider<NotificationShadeWindowController> mNotificationShadeWindowControllerProvider,
      Provider<StatusBarWindowController> mTempStatusBarWindowControllerProvider,
      Provider<DarkIconDispatcher> mDarkIconDispatcherProvider,
      Provider<ConfigurationController> mConfigurationControllerProvider,
      Provider<StatusBarIconController> mStatusBarIconControllerProvider,
      Provider<ScreenLifecycle> mScreenLifecycleProvider,
      Provider<WakefulnessLifecycle> mWakefulnessLifecycleProvider,
      Provider<FragmentService> mFragmentServiceProvider,
      Provider<ExtensionController> mExtensionControllerProvider,
      Provider<PluginDependencyProvider> mPluginDependencyProvider,
      Provider<LocalBluetoothManager> mLocalBluetoothManagerProvider,
      Provider<VolumeDialogController> mVolumeDialogControllerProvider,
      Provider<MetricsLogger> mMetricsLoggerProvider,
      Provider<AccessibilityManagerWrapper> mAccessibilityManagerWrapperProvider,
      Provider<SysuiColorExtractor> mSysuiColorExtractorProvider,
      Provider<TunablePadding.TunablePaddingService> mTunablePaddingServiceProvider,
      Provider<ForegroundServiceController> mForegroundServiceControllerProvider,
      Provider<UiOffloadThread> mUiOffloadThreadProvider,
      Provider<PowerUI.WarningsUI> mWarningsUIProvider,
      Provider<LightBarController> mLightBarControllerProvider,
      Provider<IWindowManager> mIWindowManagerProvider,
      Provider<OverviewProxyService> mOverviewProxyServiceProvider,
      Provider<NavigationModeController> mNavBarModeControllerProvider,
      Provider<AccessibilityButtonModeObserver> mAccessibilityButtonModeObserverProvider,
      Provider<AccessibilityButtonTargetsObserver> mAccessibilityButtonListControllerProvider,
      Provider<EnhancedEstimates> mEnhancedEstimatesProvider,
      Provider<VibratorHelper> mVibratorHelperProvider,
      Provider<IStatusBarService> mIStatusBarServiceProvider,
      Provider<DisplayMetrics> mDisplayMetricsProvider,
      Provider<LockscreenGestureLogger> mLockscreenGestureLoggerProvider,
      Provider<NotificationEntryManager.KeyguardEnvironment> mKeyguardEnvironmentProvider,
      Provider<ShadeController> mShadeControllerProvider,
      Provider<NotificationRemoteInputManager.Callback> mNotificationRemoteInputManagerCallbackProvider,
      Provider<AppOpsController> mAppOpsControllerProvider,
      Provider<NavigationBarController> mNavigationBarControllerProvider,
      Provider<AccessibilityFloatingMenuController> mAccessibilityFloatingMenuControllerProvider,
      Provider<StatusBarStateController> mStatusBarStateControllerProvider,
      Provider<NotificationLockscreenUserManager> mNotificationLockscreenUserManagerProvider,
      Provider<NotificationGroupAlertTransferHelper> mNotificationGroupAlertTransferHelperProvider,
      Provider<NotificationGroupManagerLegacy> mNotificationGroupManagerProvider,
      Provider<VisualStabilityManager> mVisualStabilityManagerProvider,
      Provider<NotificationGutsManager> mNotificationGutsManagerProvider,
      Provider<NotificationMediaManager> mNotificationMediaManagerProvider,
      Provider<NotificationRemoteInputManager> mNotificationRemoteInputManagerProvider,
      Provider<SmartReplyConstants> mSmartReplyConstantsProvider,
      Provider<NotificationListener> mNotificationListenerProvider,
      Provider<NotificationLogger> mNotificationLoggerProvider,
      Provider<NotificationViewHierarchyManager> mNotificationViewHierarchyManagerProvider,
      Provider<NotificationFilter> mNotificationFilterProvider,
      Provider<KeyguardDismissUtil> mKeyguardDismissUtilProvider,
      Provider<SmartReplyController> mSmartReplyControllerProvider,
      Provider<RemoteInputQuickSettingsDisabler> mRemoteInputQuickSettingsDisablerProvider,
      Provider<NotificationEntryManager> mNotificationEntryManagerProvider,
      Provider<SensorPrivacyManager> mSensorPrivacyManagerProvider,
      Provider<AutoHideController> mAutoHideControllerProvider,
      Provider<ForegroundServiceNotificationListener> mForegroundServiceNotificationListenerProvider,
      Provider<PrivacyItemController> mPrivacyItemControllerProvider,
      Provider<Looper> mBgLooperProvider, Provider<Handler> mBgHandlerProvider,
      Provider<Looper> mMainLooperProvider, Provider<Handler> mMainHandlerProvider,
      Provider<Handler> mTimeTickHandlerProvider, Provider<String> mLeakReportEmailProvider,
      Provider<Executor> mMainExecutorProvider, Provider<Executor> mBackgroundExecutorProvider,
      Provider<ClockManager> mClockManagerProvider,
      Provider<ActivityManagerWrapper> mActivityManagerWrapperProvider,
      Provider<DevicePolicyManagerWrapper> mDevicePolicyManagerWrapperProvider,
      Provider<PackageManagerWrapper> mPackageManagerWrapperProvider,
      Provider<SensorPrivacyController> mSensorPrivacyControllerProvider,
      Provider<DockManager> mDockManagerProvider,
      Provider<INotificationManager> mINotificationManagerProvider,
      Provider<SysUiState> mSysUiStateFlagsContainerProvider,
      Provider<AlarmManager> mAlarmManagerProvider,
      Provider<KeyguardSecurityModel> mKeyguardSecurityModelProvider,
      Provider<DozeParameters> mDozeParametersProvider,
      Provider<IWallpaperManager> mWallpaperManagerProvider,
      Provider<CommandQueue> mCommandQueueProvider,
      Provider<RecordingController> mRecordingControllerProvider,
      Provider<ProtoTracer> mProtoTracerProvider,
      Provider<MediaOutputDialogFactory> mMediaOutputDialogFactoryProvider,
      Provider<DeviceConfigProxy> mDeviceConfigProxyProvider,
      Provider<NavigationBarOverlayController> mNavbarButtonsControllerLazyProvider,
      Provider<TelephonyListenerManager> mTelephonyListenerManagerProvider,
      Provider<SystemStatusAnimationScheduler> mSystemStatusAnimationSchedulerLazyProvider,
      Provider<PrivacyDotViewController> mPrivacyDotViewControllerLazyProvider,
      Provider<EdgeBackGestureHandler.Factory> mEdgeBackGestureHandlerFactoryLazyProvider,
      Provider<UiEventLogger> mUiEventLoggerProvider,
      Provider<FeatureFlags> mFeatureFlagsLazyProvider,
      Provider<StatusBarContentInsetsProvider> mContentInsetsProviderLazyProvider,
      Provider<InternetDialogFactory> mInternetDialogFactoryProvider,
      Provider<NotificationSectionsManager> mNotificationSectionsManagerLazyProvider,
      Provider<UnlockedScreenOffAnimationController> mUnlockedScreenOffAnimationControllerLazyProvider,
      Provider<AmbientState> mAmbientStateLazyProvider,
      Provider<GroupMembershipManager> mGroupMembershipManagerLazyProvider,
      Provider<GroupExpansionManager> mGroupExpansionManagerLazyProvider,
      Provider<AuthController> mAuthControllerProvider) {
    return new Dependency_Factory(mDumpManagerProvider, mActivityStarterProvider, mBroadcastDispatcherProvider, mAsyncSensorManagerProvider, mBluetoothControllerProvider, mLocationControllerProvider, mRotationLockControllerProvider, mZenModeControllerProvider, mHotspotControllerProvider, mCastControllerProvider, mFlashlightControllerProvider, mUserSwitcherControllerProvider, mUserInfoControllerProvider, mKeyguardMonitorProvider, mKeyguardUpdateMonitorProvider, mBatteryControllerProvider, mNightDisplayListenerProvider, mReduceBrightColorsControllerProvider, mManagedProfileControllerProvider, mNextAlarmControllerProvider, mDataSaverControllerProvider, mAccessibilityControllerProvider, mDeviceProvisionedControllerProvider, mPluginManagerProvider, mAssistManagerProvider, mSecurityControllerProvider, mLeakDetectorProvider, mLeakReporterProvider, mGarbageMonitorProvider, mTunerServiceProvider, mNotificationShadeWindowControllerProvider, mTempStatusBarWindowControllerProvider, mDarkIconDispatcherProvider, mConfigurationControllerProvider, mStatusBarIconControllerProvider, mScreenLifecycleProvider, mWakefulnessLifecycleProvider, mFragmentServiceProvider, mExtensionControllerProvider, mPluginDependencyProvider, mLocalBluetoothManagerProvider, mVolumeDialogControllerProvider, mMetricsLoggerProvider, mAccessibilityManagerWrapperProvider, mSysuiColorExtractorProvider, mTunablePaddingServiceProvider, mForegroundServiceControllerProvider, mUiOffloadThreadProvider, mWarningsUIProvider, mLightBarControllerProvider, mIWindowManagerProvider, mOverviewProxyServiceProvider, mNavBarModeControllerProvider, mAccessibilityButtonModeObserverProvider, mAccessibilityButtonListControllerProvider, mEnhancedEstimatesProvider, mVibratorHelperProvider, mIStatusBarServiceProvider, mDisplayMetricsProvider, mLockscreenGestureLoggerProvider, mKeyguardEnvironmentProvider, mShadeControllerProvider, mNotificationRemoteInputManagerCallbackProvider, mAppOpsControllerProvider, mNavigationBarControllerProvider, mAccessibilityFloatingMenuControllerProvider, mStatusBarStateControllerProvider, mNotificationLockscreenUserManagerProvider, mNotificationGroupAlertTransferHelperProvider, mNotificationGroupManagerProvider, mVisualStabilityManagerProvider, mNotificationGutsManagerProvider, mNotificationMediaManagerProvider, mNotificationRemoteInputManagerProvider, mSmartReplyConstantsProvider, mNotificationListenerProvider, mNotificationLoggerProvider, mNotificationViewHierarchyManagerProvider, mNotificationFilterProvider, mKeyguardDismissUtilProvider, mSmartReplyControllerProvider, mRemoteInputQuickSettingsDisablerProvider, mNotificationEntryManagerProvider, mSensorPrivacyManagerProvider, mAutoHideControllerProvider, mForegroundServiceNotificationListenerProvider, mPrivacyItemControllerProvider, mBgLooperProvider, mBgHandlerProvider, mMainLooperProvider, mMainHandlerProvider, mTimeTickHandlerProvider, mLeakReportEmailProvider, mMainExecutorProvider, mBackgroundExecutorProvider, mClockManagerProvider, mActivityManagerWrapperProvider, mDevicePolicyManagerWrapperProvider, mPackageManagerWrapperProvider, mSensorPrivacyControllerProvider, mDockManagerProvider, mINotificationManagerProvider, mSysUiStateFlagsContainerProvider, mAlarmManagerProvider, mKeyguardSecurityModelProvider, mDozeParametersProvider, mWallpaperManagerProvider, mCommandQueueProvider, mRecordingControllerProvider, mProtoTracerProvider, mMediaOutputDialogFactoryProvider, mDeviceConfigProxyProvider, mNavbarButtonsControllerLazyProvider, mTelephonyListenerManagerProvider, mSystemStatusAnimationSchedulerLazyProvider, mPrivacyDotViewControllerLazyProvider, mEdgeBackGestureHandlerFactoryLazyProvider, mUiEventLoggerProvider, mFeatureFlagsLazyProvider, mContentInsetsProviderLazyProvider, mInternetDialogFactoryProvider, mNotificationSectionsManagerLazyProvider, mUnlockedScreenOffAnimationControllerLazyProvider, mAmbientStateLazyProvider, mGroupMembershipManagerLazyProvider, mGroupExpansionManagerLazyProvider, mAuthControllerProvider);
  }

  public static Dependency newInstance() {
    return new Dependency();
  }
}
