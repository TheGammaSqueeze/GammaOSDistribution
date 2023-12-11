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
import com.android.systemui.dagger.qualifiers.Background;
import com.android.systemui.dagger.qualifiers.Main;
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
import dagger.Lazy;
import dagger.MembersInjector;
import dagger.internal.DoubleCheck;
import dagger.internal.InjectedFieldSignature;
import java.util.concurrent.Executor;
import javax.annotation.processing.Generated;
import javax.inject.Named;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class Dependency_MembersInjector implements MembersInjector<Dependency> {
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

  public Dependency_MembersInjector(Provider<DumpManager> mDumpManagerProvider,
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

  public static MembersInjector<Dependency> create(Provider<DumpManager> mDumpManagerProvider,
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
    return new Dependency_MembersInjector(mDumpManagerProvider, mActivityStarterProvider, mBroadcastDispatcherProvider, mAsyncSensorManagerProvider, mBluetoothControllerProvider, mLocationControllerProvider, mRotationLockControllerProvider, mZenModeControllerProvider, mHotspotControllerProvider, mCastControllerProvider, mFlashlightControllerProvider, mUserSwitcherControllerProvider, mUserInfoControllerProvider, mKeyguardMonitorProvider, mKeyguardUpdateMonitorProvider, mBatteryControllerProvider, mNightDisplayListenerProvider, mReduceBrightColorsControllerProvider, mManagedProfileControllerProvider, mNextAlarmControllerProvider, mDataSaverControllerProvider, mAccessibilityControllerProvider, mDeviceProvisionedControllerProvider, mPluginManagerProvider, mAssistManagerProvider, mSecurityControllerProvider, mLeakDetectorProvider, mLeakReporterProvider, mGarbageMonitorProvider, mTunerServiceProvider, mNotificationShadeWindowControllerProvider, mTempStatusBarWindowControllerProvider, mDarkIconDispatcherProvider, mConfigurationControllerProvider, mStatusBarIconControllerProvider, mScreenLifecycleProvider, mWakefulnessLifecycleProvider, mFragmentServiceProvider, mExtensionControllerProvider, mPluginDependencyProvider, mLocalBluetoothManagerProvider, mVolumeDialogControllerProvider, mMetricsLoggerProvider, mAccessibilityManagerWrapperProvider, mSysuiColorExtractorProvider, mTunablePaddingServiceProvider, mForegroundServiceControllerProvider, mUiOffloadThreadProvider, mWarningsUIProvider, mLightBarControllerProvider, mIWindowManagerProvider, mOverviewProxyServiceProvider, mNavBarModeControllerProvider, mAccessibilityButtonModeObserverProvider, mAccessibilityButtonListControllerProvider, mEnhancedEstimatesProvider, mVibratorHelperProvider, mIStatusBarServiceProvider, mDisplayMetricsProvider, mLockscreenGestureLoggerProvider, mKeyguardEnvironmentProvider, mShadeControllerProvider, mNotificationRemoteInputManagerCallbackProvider, mAppOpsControllerProvider, mNavigationBarControllerProvider, mAccessibilityFloatingMenuControllerProvider, mStatusBarStateControllerProvider, mNotificationLockscreenUserManagerProvider, mNotificationGroupAlertTransferHelperProvider, mNotificationGroupManagerProvider, mVisualStabilityManagerProvider, mNotificationGutsManagerProvider, mNotificationMediaManagerProvider, mNotificationRemoteInputManagerProvider, mSmartReplyConstantsProvider, mNotificationListenerProvider, mNotificationLoggerProvider, mNotificationViewHierarchyManagerProvider, mNotificationFilterProvider, mKeyguardDismissUtilProvider, mSmartReplyControllerProvider, mRemoteInputQuickSettingsDisablerProvider, mNotificationEntryManagerProvider, mSensorPrivacyManagerProvider, mAutoHideControllerProvider, mForegroundServiceNotificationListenerProvider, mPrivacyItemControllerProvider, mBgLooperProvider, mBgHandlerProvider, mMainLooperProvider, mMainHandlerProvider, mTimeTickHandlerProvider, mLeakReportEmailProvider, mMainExecutorProvider, mBackgroundExecutorProvider, mClockManagerProvider, mActivityManagerWrapperProvider, mDevicePolicyManagerWrapperProvider, mPackageManagerWrapperProvider, mSensorPrivacyControllerProvider, mDockManagerProvider, mINotificationManagerProvider, mSysUiStateFlagsContainerProvider, mAlarmManagerProvider, mKeyguardSecurityModelProvider, mDozeParametersProvider, mWallpaperManagerProvider, mCommandQueueProvider, mRecordingControllerProvider, mProtoTracerProvider, mMediaOutputDialogFactoryProvider, mDeviceConfigProxyProvider, mNavbarButtonsControllerLazyProvider, mTelephonyListenerManagerProvider, mSystemStatusAnimationSchedulerLazyProvider, mPrivacyDotViewControllerLazyProvider, mEdgeBackGestureHandlerFactoryLazyProvider, mUiEventLoggerProvider, mFeatureFlagsLazyProvider, mContentInsetsProviderLazyProvider, mInternetDialogFactoryProvider, mNotificationSectionsManagerLazyProvider, mUnlockedScreenOffAnimationControllerLazyProvider, mAmbientStateLazyProvider, mGroupMembershipManagerLazyProvider, mGroupExpansionManagerLazyProvider, mAuthControllerProvider);
  }

  @Override
  public void injectMembers(Dependency instance) {
    injectMDumpManager(instance, mDumpManagerProvider.get());
    injectMActivityStarter(instance, DoubleCheck.lazy(mActivityStarterProvider));
    injectMBroadcastDispatcher(instance, DoubleCheck.lazy(mBroadcastDispatcherProvider));
    injectMAsyncSensorManager(instance, DoubleCheck.lazy(mAsyncSensorManagerProvider));
    injectMBluetoothController(instance, DoubleCheck.lazy(mBluetoothControllerProvider));
    injectMLocationController(instance, DoubleCheck.lazy(mLocationControllerProvider));
    injectMRotationLockController(instance, DoubleCheck.lazy(mRotationLockControllerProvider));
    injectMZenModeController(instance, DoubleCheck.lazy(mZenModeControllerProvider));
    injectMHotspotController(instance, DoubleCheck.lazy(mHotspotControllerProvider));
    injectMCastController(instance, DoubleCheck.lazy(mCastControllerProvider));
    injectMFlashlightController(instance, DoubleCheck.lazy(mFlashlightControllerProvider));
    injectMUserSwitcherController(instance, DoubleCheck.lazy(mUserSwitcherControllerProvider));
    injectMUserInfoController(instance, DoubleCheck.lazy(mUserInfoControllerProvider));
    injectMKeyguardMonitor(instance, DoubleCheck.lazy(mKeyguardMonitorProvider));
    injectMKeyguardUpdateMonitor(instance, DoubleCheck.lazy(mKeyguardUpdateMonitorProvider));
    injectMBatteryController(instance, DoubleCheck.lazy(mBatteryControllerProvider));
    injectMNightDisplayListener(instance, DoubleCheck.lazy(mNightDisplayListenerProvider));
    injectMReduceBrightColorsController(instance, DoubleCheck.lazy(mReduceBrightColorsControllerProvider));
    injectMManagedProfileController(instance, DoubleCheck.lazy(mManagedProfileControllerProvider));
    injectMNextAlarmController(instance, DoubleCheck.lazy(mNextAlarmControllerProvider));
    injectMDataSaverController(instance, DoubleCheck.lazy(mDataSaverControllerProvider));
    injectMAccessibilityController(instance, DoubleCheck.lazy(mAccessibilityControllerProvider));
    injectMDeviceProvisionedController(instance, DoubleCheck.lazy(mDeviceProvisionedControllerProvider));
    injectMPluginManager(instance, DoubleCheck.lazy(mPluginManagerProvider));
    injectMAssistManager(instance, DoubleCheck.lazy(mAssistManagerProvider));
    injectMSecurityController(instance, DoubleCheck.lazy(mSecurityControllerProvider));
    injectMLeakDetector(instance, DoubleCheck.lazy(mLeakDetectorProvider));
    injectMLeakReporter(instance, DoubleCheck.lazy(mLeakReporterProvider));
    injectMGarbageMonitor(instance, DoubleCheck.lazy(mGarbageMonitorProvider));
    injectMTunerService(instance, DoubleCheck.lazy(mTunerServiceProvider));
    injectMNotificationShadeWindowController(instance, DoubleCheck.lazy(mNotificationShadeWindowControllerProvider));
    injectMTempStatusBarWindowController(instance, DoubleCheck.lazy(mTempStatusBarWindowControllerProvider));
    injectMDarkIconDispatcher(instance, DoubleCheck.lazy(mDarkIconDispatcherProvider));
    injectMConfigurationController(instance, DoubleCheck.lazy(mConfigurationControllerProvider));
    injectMStatusBarIconController(instance, DoubleCheck.lazy(mStatusBarIconControllerProvider));
    injectMScreenLifecycle(instance, DoubleCheck.lazy(mScreenLifecycleProvider));
    injectMWakefulnessLifecycle(instance, DoubleCheck.lazy(mWakefulnessLifecycleProvider));
    injectMFragmentService(instance, DoubleCheck.lazy(mFragmentServiceProvider));
    injectMExtensionController(instance, DoubleCheck.lazy(mExtensionControllerProvider));
    injectMPluginDependencyProvider(instance, DoubleCheck.lazy(mPluginDependencyProvider));
    injectMLocalBluetoothManager(instance, DoubleCheck.lazy(mLocalBluetoothManagerProvider));
    injectMVolumeDialogController(instance, DoubleCheck.lazy(mVolumeDialogControllerProvider));
    injectMMetricsLogger(instance, DoubleCheck.lazy(mMetricsLoggerProvider));
    injectMAccessibilityManagerWrapper(instance, DoubleCheck.lazy(mAccessibilityManagerWrapperProvider));
    injectMSysuiColorExtractor(instance, DoubleCheck.lazy(mSysuiColorExtractorProvider));
    injectMTunablePaddingService(instance, DoubleCheck.lazy(mTunablePaddingServiceProvider));
    injectMForegroundServiceController(instance, DoubleCheck.lazy(mForegroundServiceControllerProvider));
    injectMUiOffloadThread(instance, DoubleCheck.lazy(mUiOffloadThreadProvider));
    injectMWarningsUI(instance, DoubleCheck.lazy(mWarningsUIProvider));
    injectMLightBarController(instance, DoubleCheck.lazy(mLightBarControllerProvider));
    injectMIWindowManager(instance, DoubleCheck.lazy(mIWindowManagerProvider));
    injectMOverviewProxyService(instance, DoubleCheck.lazy(mOverviewProxyServiceProvider));
    injectMNavBarModeController(instance, DoubleCheck.lazy(mNavBarModeControllerProvider));
    injectMAccessibilityButtonModeObserver(instance, DoubleCheck.lazy(mAccessibilityButtonModeObserverProvider));
    injectMAccessibilityButtonListController(instance, DoubleCheck.lazy(mAccessibilityButtonListControllerProvider));
    injectMEnhancedEstimates(instance, DoubleCheck.lazy(mEnhancedEstimatesProvider));
    injectMVibratorHelper(instance, DoubleCheck.lazy(mVibratorHelperProvider));
    injectMIStatusBarService(instance, DoubleCheck.lazy(mIStatusBarServiceProvider));
    injectMDisplayMetrics(instance, DoubleCheck.lazy(mDisplayMetricsProvider));
    injectMLockscreenGestureLogger(instance, DoubleCheck.lazy(mLockscreenGestureLoggerProvider));
    injectMKeyguardEnvironment(instance, DoubleCheck.lazy(mKeyguardEnvironmentProvider));
    injectMShadeController(instance, DoubleCheck.lazy(mShadeControllerProvider));
    injectMNotificationRemoteInputManagerCallback(instance, DoubleCheck.lazy(mNotificationRemoteInputManagerCallbackProvider));
    injectMAppOpsController(instance, DoubleCheck.lazy(mAppOpsControllerProvider));
    injectMNavigationBarController(instance, DoubleCheck.lazy(mNavigationBarControllerProvider));
    injectMAccessibilityFloatingMenuController(instance, DoubleCheck.lazy(mAccessibilityFloatingMenuControllerProvider));
    injectMStatusBarStateController(instance, DoubleCheck.lazy(mStatusBarStateControllerProvider));
    injectMNotificationLockscreenUserManager(instance, DoubleCheck.lazy(mNotificationLockscreenUserManagerProvider));
    injectMNotificationGroupAlertTransferHelper(instance, DoubleCheck.lazy(mNotificationGroupAlertTransferHelperProvider));
    injectMNotificationGroupManager(instance, DoubleCheck.lazy(mNotificationGroupManagerProvider));
    injectMVisualStabilityManager(instance, DoubleCheck.lazy(mVisualStabilityManagerProvider));
    injectMNotificationGutsManager(instance, DoubleCheck.lazy(mNotificationGutsManagerProvider));
    injectMNotificationMediaManager(instance, DoubleCheck.lazy(mNotificationMediaManagerProvider));
    injectMNotificationRemoteInputManager(instance, DoubleCheck.lazy(mNotificationRemoteInputManagerProvider));
    injectMSmartReplyConstants(instance, DoubleCheck.lazy(mSmartReplyConstantsProvider));
    injectMNotificationListener(instance, DoubleCheck.lazy(mNotificationListenerProvider));
    injectMNotificationLogger(instance, DoubleCheck.lazy(mNotificationLoggerProvider));
    injectMNotificationViewHierarchyManager(instance, DoubleCheck.lazy(mNotificationViewHierarchyManagerProvider));
    injectMNotificationFilter(instance, DoubleCheck.lazy(mNotificationFilterProvider));
    injectMKeyguardDismissUtil(instance, DoubleCheck.lazy(mKeyguardDismissUtilProvider));
    injectMSmartReplyController(instance, DoubleCheck.lazy(mSmartReplyControllerProvider));
    injectMRemoteInputQuickSettingsDisabler(instance, DoubleCheck.lazy(mRemoteInputQuickSettingsDisablerProvider));
    injectMNotificationEntryManager(instance, DoubleCheck.lazy(mNotificationEntryManagerProvider));
    injectMSensorPrivacyManager(instance, DoubleCheck.lazy(mSensorPrivacyManagerProvider));
    injectMAutoHideController(instance, DoubleCheck.lazy(mAutoHideControllerProvider));
    injectMForegroundServiceNotificationListener(instance, DoubleCheck.lazy(mForegroundServiceNotificationListenerProvider));
    injectMPrivacyItemController(instance, DoubleCheck.lazy(mPrivacyItemControllerProvider));
    injectMBgLooper(instance, DoubleCheck.lazy(mBgLooperProvider));
    injectMBgHandler(instance, DoubleCheck.lazy(mBgHandlerProvider));
    injectMMainLooper(instance, DoubleCheck.lazy(mMainLooperProvider));
    injectMMainHandler(instance, DoubleCheck.lazy(mMainHandlerProvider));
    injectMTimeTickHandler(instance, DoubleCheck.lazy(mTimeTickHandlerProvider));
    injectMLeakReportEmail(instance, DoubleCheck.lazy(mLeakReportEmailProvider));
    injectMMainExecutor(instance, DoubleCheck.lazy(mMainExecutorProvider));
    injectMBackgroundExecutor(instance, DoubleCheck.lazy(mBackgroundExecutorProvider));
    injectMClockManager(instance, DoubleCheck.lazy(mClockManagerProvider));
    injectMActivityManagerWrapper(instance, DoubleCheck.lazy(mActivityManagerWrapperProvider));
    injectMDevicePolicyManagerWrapper(instance, DoubleCheck.lazy(mDevicePolicyManagerWrapperProvider));
    injectMPackageManagerWrapper(instance, DoubleCheck.lazy(mPackageManagerWrapperProvider));
    injectMSensorPrivacyController(instance, DoubleCheck.lazy(mSensorPrivacyControllerProvider));
    injectMDockManager(instance, DoubleCheck.lazy(mDockManagerProvider));
    injectMINotificationManager(instance, DoubleCheck.lazy(mINotificationManagerProvider));
    injectMSysUiStateFlagsContainer(instance, DoubleCheck.lazy(mSysUiStateFlagsContainerProvider));
    injectMAlarmManager(instance, DoubleCheck.lazy(mAlarmManagerProvider));
    injectMKeyguardSecurityModel(instance, DoubleCheck.lazy(mKeyguardSecurityModelProvider));
    injectMDozeParameters(instance, DoubleCheck.lazy(mDozeParametersProvider));
    injectMWallpaperManager(instance, DoubleCheck.lazy(mWallpaperManagerProvider));
    injectMCommandQueue(instance, DoubleCheck.lazy(mCommandQueueProvider));
    injectMRecordingController(instance, DoubleCheck.lazy(mRecordingControllerProvider));
    injectMProtoTracer(instance, DoubleCheck.lazy(mProtoTracerProvider));
    injectMMediaOutputDialogFactory(instance, DoubleCheck.lazy(mMediaOutputDialogFactoryProvider));
    injectMDeviceConfigProxy(instance, DoubleCheck.lazy(mDeviceConfigProxyProvider));
    injectMNavbarButtonsControllerLazy(instance, DoubleCheck.lazy(mNavbarButtonsControllerLazyProvider));
    injectMTelephonyListenerManager(instance, DoubleCheck.lazy(mTelephonyListenerManagerProvider));
    injectMSystemStatusAnimationSchedulerLazy(instance, DoubleCheck.lazy(mSystemStatusAnimationSchedulerLazyProvider));
    injectMPrivacyDotViewControllerLazy(instance, DoubleCheck.lazy(mPrivacyDotViewControllerLazyProvider));
    injectMEdgeBackGestureHandlerFactoryLazy(instance, DoubleCheck.lazy(mEdgeBackGestureHandlerFactoryLazyProvider));
    injectMUiEventLogger(instance, DoubleCheck.lazy(mUiEventLoggerProvider));
    injectMFeatureFlagsLazy(instance, DoubleCheck.lazy(mFeatureFlagsLazyProvider));
    injectMContentInsetsProviderLazy(instance, DoubleCheck.lazy(mContentInsetsProviderLazyProvider));
    injectMInternetDialogFactory(instance, DoubleCheck.lazy(mInternetDialogFactoryProvider));
    injectMNotificationSectionsManagerLazy(instance, DoubleCheck.lazy(mNotificationSectionsManagerLazyProvider));
    injectMUnlockedScreenOffAnimationControllerLazy(instance, DoubleCheck.lazy(mUnlockedScreenOffAnimationControllerLazyProvider));
    injectMAmbientStateLazy(instance, DoubleCheck.lazy(mAmbientStateLazyProvider));
    injectMGroupMembershipManagerLazy(instance, DoubleCheck.lazy(mGroupMembershipManagerLazyProvider));
    injectMGroupExpansionManagerLazy(instance, DoubleCheck.lazy(mGroupExpansionManagerLazyProvider));
    injectMAuthController(instance, DoubleCheck.lazy(mAuthControllerProvider));
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDumpManager")
  public static void injectMDumpManager(Dependency instance, DumpManager mDumpManager) {
    instance.mDumpManager = mDumpManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mActivityStarter")
  public static void injectMActivityStarter(Dependency instance,
      Lazy<ActivityStarter> mActivityStarter) {
    instance.mActivityStarter = mActivityStarter;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mBroadcastDispatcher")
  public static void injectMBroadcastDispatcher(Dependency instance,
      Lazy<BroadcastDispatcher> mBroadcastDispatcher) {
    instance.mBroadcastDispatcher = mBroadcastDispatcher;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAsyncSensorManager")
  public static void injectMAsyncSensorManager(Dependency instance,
      Lazy<AsyncSensorManager> mAsyncSensorManager) {
    instance.mAsyncSensorManager = mAsyncSensorManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mBluetoothController")
  public static void injectMBluetoothController(Dependency instance,
      Lazy<BluetoothController> mBluetoothController) {
    instance.mBluetoothController = mBluetoothController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLocationController")
  public static void injectMLocationController(Dependency instance,
      Lazy<LocationController> mLocationController) {
    instance.mLocationController = mLocationController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mRotationLockController")
  public static void injectMRotationLockController(Dependency instance,
      Lazy<RotationLockController> mRotationLockController) {
    instance.mRotationLockController = mRotationLockController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mZenModeController")
  public static void injectMZenModeController(Dependency instance,
      Lazy<ZenModeController> mZenModeController) {
    instance.mZenModeController = mZenModeController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mHotspotController")
  public static void injectMHotspotController(Dependency instance,
      Lazy<HotspotController> mHotspotController) {
    instance.mHotspotController = mHotspotController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mCastController")
  public static void injectMCastController(Dependency instance,
      Lazy<CastController> mCastController) {
    instance.mCastController = mCastController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mFlashlightController")
  public static void injectMFlashlightController(Dependency instance,
      Lazy<FlashlightController> mFlashlightController) {
    instance.mFlashlightController = mFlashlightController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mUserSwitcherController")
  public static void injectMUserSwitcherController(Dependency instance,
      Lazy<UserSwitcherController> mUserSwitcherController) {
    instance.mUserSwitcherController = mUserSwitcherController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mUserInfoController")
  public static void injectMUserInfoController(Dependency instance,
      Lazy<UserInfoController> mUserInfoController) {
    instance.mUserInfoController = mUserInfoController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mKeyguardMonitor")
  public static void injectMKeyguardMonitor(Dependency instance,
      Lazy<KeyguardStateController> mKeyguardMonitor) {
    instance.mKeyguardMonitor = mKeyguardMonitor;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mKeyguardUpdateMonitor")
  public static void injectMKeyguardUpdateMonitor(Dependency instance,
      Lazy<KeyguardUpdateMonitor> mKeyguardUpdateMonitor) {
    instance.mKeyguardUpdateMonitor = mKeyguardUpdateMonitor;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mBatteryController")
  public static void injectMBatteryController(Dependency instance,
      Lazy<BatteryController> mBatteryController) {
    instance.mBatteryController = mBatteryController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNightDisplayListener")
  public static void injectMNightDisplayListener(Dependency instance,
      Lazy<NightDisplayListener> mNightDisplayListener) {
    instance.mNightDisplayListener = mNightDisplayListener;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mReduceBrightColorsController")
  public static void injectMReduceBrightColorsController(Dependency instance,
      Lazy<ReduceBrightColorsController> mReduceBrightColorsController) {
    instance.mReduceBrightColorsController = mReduceBrightColorsController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mManagedProfileController")
  public static void injectMManagedProfileController(Dependency instance,
      Lazy<ManagedProfileController> mManagedProfileController) {
    instance.mManagedProfileController = mManagedProfileController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNextAlarmController")
  public static void injectMNextAlarmController(Dependency instance,
      Lazy<NextAlarmController> mNextAlarmController) {
    instance.mNextAlarmController = mNextAlarmController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDataSaverController")
  public static void injectMDataSaverController(Dependency instance,
      Lazy<DataSaverController> mDataSaverController) {
    instance.mDataSaverController = mDataSaverController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAccessibilityController")
  public static void injectMAccessibilityController(Dependency instance,
      Lazy<AccessibilityController> mAccessibilityController) {
    instance.mAccessibilityController = mAccessibilityController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDeviceProvisionedController")
  public static void injectMDeviceProvisionedController(Dependency instance,
      Lazy<DeviceProvisionedController> mDeviceProvisionedController) {
    instance.mDeviceProvisionedController = mDeviceProvisionedController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mPluginManager")
  public static void injectMPluginManager(Dependency instance, Lazy<PluginManager> mPluginManager) {
    instance.mPluginManager = mPluginManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAssistManager")
  public static void injectMAssistManager(Dependency instance, Lazy<AssistManager> mAssistManager) {
    instance.mAssistManager = mAssistManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSecurityController")
  public static void injectMSecurityController(Dependency instance,
      Lazy<SecurityController> mSecurityController) {
    instance.mSecurityController = mSecurityController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLeakDetector")
  public static void injectMLeakDetector(Dependency instance, Lazy<LeakDetector> mLeakDetector) {
    instance.mLeakDetector = mLeakDetector;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLeakReporter")
  public static void injectMLeakReporter(Dependency instance, Lazy<LeakReporter> mLeakReporter) {
    instance.mLeakReporter = mLeakReporter;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mGarbageMonitor")
  public static void injectMGarbageMonitor(Dependency instance,
      Lazy<GarbageMonitor> mGarbageMonitor) {
    instance.mGarbageMonitor = mGarbageMonitor;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mTunerService")
  public static void injectMTunerService(Dependency instance, Lazy<TunerService> mTunerService) {
    instance.mTunerService = mTunerService;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationShadeWindowController")
  public static void injectMNotificationShadeWindowController(Dependency instance,
      Lazy<NotificationShadeWindowController> mNotificationShadeWindowController) {
    instance.mNotificationShadeWindowController = mNotificationShadeWindowController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mTempStatusBarWindowController")
  public static void injectMTempStatusBarWindowController(Dependency instance,
      Lazy<StatusBarWindowController> mTempStatusBarWindowController) {
    instance.mTempStatusBarWindowController = mTempStatusBarWindowController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDarkIconDispatcher")
  public static void injectMDarkIconDispatcher(Dependency instance,
      Lazy<DarkIconDispatcher> mDarkIconDispatcher) {
    instance.mDarkIconDispatcher = mDarkIconDispatcher;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mConfigurationController")
  public static void injectMConfigurationController(Dependency instance,
      Lazy<ConfigurationController> mConfigurationController) {
    instance.mConfigurationController = mConfigurationController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mStatusBarIconController")
  public static void injectMStatusBarIconController(Dependency instance,
      Lazy<StatusBarIconController> mStatusBarIconController) {
    instance.mStatusBarIconController = mStatusBarIconController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mScreenLifecycle")
  public static void injectMScreenLifecycle(Dependency instance,
      Lazy<ScreenLifecycle> mScreenLifecycle) {
    instance.mScreenLifecycle = mScreenLifecycle;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mWakefulnessLifecycle")
  public static void injectMWakefulnessLifecycle(Dependency instance,
      Lazy<WakefulnessLifecycle> mWakefulnessLifecycle) {
    instance.mWakefulnessLifecycle = mWakefulnessLifecycle;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mFragmentService")
  public static void injectMFragmentService(Dependency instance,
      Lazy<FragmentService> mFragmentService) {
    instance.mFragmentService = mFragmentService;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mExtensionController")
  public static void injectMExtensionController(Dependency instance,
      Lazy<ExtensionController> mExtensionController) {
    instance.mExtensionController = mExtensionController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mPluginDependencyProvider")
  public static void injectMPluginDependencyProvider(Dependency instance,
      Lazy<PluginDependencyProvider> mPluginDependencyProvider) {
    instance.mPluginDependencyProvider = mPluginDependencyProvider;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLocalBluetoothManager")
  public static void injectMLocalBluetoothManager(Dependency instance,
      Lazy<LocalBluetoothManager> mLocalBluetoothManager) {
    instance.mLocalBluetoothManager = mLocalBluetoothManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mVolumeDialogController")
  public static void injectMVolumeDialogController(Dependency instance,
      Lazy<VolumeDialogController> mVolumeDialogController) {
    instance.mVolumeDialogController = mVolumeDialogController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mMetricsLogger")
  public static void injectMMetricsLogger(Dependency instance, Lazy<MetricsLogger> mMetricsLogger) {
    instance.mMetricsLogger = mMetricsLogger;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAccessibilityManagerWrapper")
  public static void injectMAccessibilityManagerWrapper(Dependency instance,
      Lazy<AccessibilityManagerWrapper> mAccessibilityManagerWrapper) {
    instance.mAccessibilityManagerWrapper = mAccessibilityManagerWrapper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSysuiColorExtractor")
  public static void injectMSysuiColorExtractor(Dependency instance,
      Lazy<SysuiColorExtractor> mSysuiColorExtractor) {
    instance.mSysuiColorExtractor = mSysuiColorExtractor;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mTunablePaddingService")
  public static void injectMTunablePaddingService(Dependency instance,
      Lazy<TunablePadding.TunablePaddingService> mTunablePaddingService) {
    instance.mTunablePaddingService = mTunablePaddingService;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mForegroundServiceController")
  public static void injectMForegroundServiceController(Dependency instance,
      Lazy<ForegroundServiceController> mForegroundServiceController) {
    instance.mForegroundServiceController = mForegroundServiceController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mUiOffloadThread")
  public static void injectMUiOffloadThread(Dependency instance,
      Lazy<UiOffloadThread> mUiOffloadThread) {
    instance.mUiOffloadThread = mUiOffloadThread;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mWarningsUI")
  public static void injectMWarningsUI(Dependency instance, Lazy<PowerUI.WarningsUI> mWarningsUI) {
    instance.mWarningsUI = mWarningsUI;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLightBarController")
  public static void injectMLightBarController(Dependency instance,
      Lazy<LightBarController> mLightBarController) {
    instance.mLightBarController = mLightBarController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mIWindowManager")
  public static void injectMIWindowManager(Dependency instance,
      Lazy<IWindowManager> mIWindowManager) {
    instance.mIWindowManager = mIWindowManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mOverviewProxyService")
  public static void injectMOverviewProxyService(Dependency instance,
      Lazy<OverviewProxyService> mOverviewProxyService) {
    instance.mOverviewProxyService = mOverviewProxyService;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNavBarModeController")
  public static void injectMNavBarModeController(Dependency instance,
      Lazy<NavigationModeController> mNavBarModeController) {
    instance.mNavBarModeController = mNavBarModeController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAccessibilityButtonModeObserver")
  public static void injectMAccessibilityButtonModeObserver(Dependency instance,
      Lazy<AccessibilityButtonModeObserver> mAccessibilityButtonModeObserver) {
    instance.mAccessibilityButtonModeObserver = mAccessibilityButtonModeObserver;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAccessibilityButtonListController")
  public static void injectMAccessibilityButtonListController(Dependency instance,
      Lazy<AccessibilityButtonTargetsObserver> mAccessibilityButtonListController) {
    instance.mAccessibilityButtonListController = mAccessibilityButtonListController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mEnhancedEstimates")
  public static void injectMEnhancedEstimates(Dependency instance,
      Lazy<EnhancedEstimates> mEnhancedEstimates) {
    instance.mEnhancedEstimates = mEnhancedEstimates;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mVibratorHelper")
  public static void injectMVibratorHelper(Dependency instance,
      Lazy<VibratorHelper> mVibratorHelper) {
    instance.mVibratorHelper = mVibratorHelper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mIStatusBarService")
  public static void injectMIStatusBarService(Dependency instance,
      Lazy<IStatusBarService> mIStatusBarService) {
    instance.mIStatusBarService = mIStatusBarService;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDisplayMetrics")
  public static void injectMDisplayMetrics(Dependency instance,
      Lazy<DisplayMetrics> mDisplayMetrics) {
    instance.mDisplayMetrics = mDisplayMetrics;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLockscreenGestureLogger")
  public static void injectMLockscreenGestureLogger(Dependency instance,
      Lazy<LockscreenGestureLogger> mLockscreenGestureLogger) {
    instance.mLockscreenGestureLogger = mLockscreenGestureLogger;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mKeyguardEnvironment")
  public static void injectMKeyguardEnvironment(Dependency instance,
      Lazy<NotificationEntryManager.KeyguardEnvironment> mKeyguardEnvironment) {
    instance.mKeyguardEnvironment = mKeyguardEnvironment;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mShadeController")
  public static void injectMShadeController(Dependency instance,
      Lazy<ShadeController> mShadeController) {
    instance.mShadeController = mShadeController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationRemoteInputManagerCallback")
  public static void injectMNotificationRemoteInputManagerCallback(Dependency instance,
      Lazy<NotificationRemoteInputManager.Callback> mNotificationRemoteInputManagerCallback) {
    instance.mNotificationRemoteInputManagerCallback = mNotificationRemoteInputManagerCallback;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAppOpsController")
  public static void injectMAppOpsController(Dependency instance,
      Lazy<AppOpsController> mAppOpsController) {
    instance.mAppOpsController = mAppOpsController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNavigationBarController")
  public static void injectMNavigationBarController(Dependency instance,
      Lazy<NavigationBarController> mNavigationBarController) {
    instance.mNavigationBarController = mNavigationBarController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAccessibilityFloatingMenuController")
  public static void injectMAccessibilityFloatingMenuController(Dependency instance,
      Lazy<AccessibilityFloatingMenuController> mAccessibilityFloatingMenuController) {
    instance.mAccessibilityFloatingMenuController = mAccessibilityFloatingMenuController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mStatusBarStateController")
  public static void injectMStatusBarStateController(Dependency instance,
      Lazy<StatusBarStateController> mStatusBarStateController) {
    instance.mStatusBarStateController = mStatusBarStateController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationLockscreenUserManager")
  public static void injectMNotificationLockscreenUserManager(Dependency instance,
      Lazy<NotificationLockscreenUserManager> mNotificationLockscreenUserManager) {
    instance.mNotificationLockscreenUserManager = mNotificationLockscreenUserManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationGroupAlertTransferHelper")
  public static void injectMNotificationGroupAlertTransferHelper(Dependency instance,
      Lazy<NotificationGroupAlertTransferHelper> mNotificationGroupAlertTransferHelper) {
    instance.mNotificationGroupAlertTransferHelper = mNotificationGroupAlertTransferHelper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationGroupManager")
  public static void injectMNotificationGroupManager(Dependency instance,
      Lazy<NotificationGroupManagerLegacy> mNotificationGroupManager) {
    instance.mNotificationGroupManager = mNotificationGroupManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mVisualStabilityManager")
  public static void injectMVisualStabilityManager(Dependency instance,
      Lazy<VisualStabilityManager> mVisualStabilityManager) {
    instance.mVisualStabilityManager = mVisualStabilityManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationGutsManager")
  public static void injectMNotificationGutsManager(Dependency instance,
      Lazy<NotificationGutsManager> mNotificationGutsManager) {
    instance.mNotificationGutsManager = mNotificationGutsManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationMediaManager")
  public static void injectMNotificationMediaManager(Dependency instance,
      Lazy<NotificationMediaManager> mNotificationMediaManager) {
    instance.mNotificationMediaManager = mNotificationMediaManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationRemoteInputManager")
  public static void injectMNotificationRemoteInputManager(Dependency instance,
      Lazy<NotificationRemoteInputManager> mNotificationRemoteInputManager) {
    instance.mNotificationRemoteInputManager = mNotificationRemoteInputManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSmartReplyConstants")
  public static void injectMSmartReplyConstants(Dependency instance,
      Lazy<SmartReplyConstants> mSmartReplyConstants) {
    instance.mSmartReplyConstants = mSmartReplyConstants;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationListener")
  public static void injectMNotificationListener(Dependency instance,
      Lazy<NotificationListener> mNotificationListener) {
    instance.mNotificationListener = mNotificationListener;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationLogger")
  public static void injectMNotificationLogger(Dependency instance,
      Lazy<NotificationLogger> mNotificationLogger) {
    instance.mNotificationLogger = mNotificationLogger;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationViewHierarchyManager")
  public static void injectMNotificationViewHierarchyManager(Dependency instance,
      Lazy<NotificationViewHierarchyManager> mNotificationViewHierarchyManager) {
    instance.mNotificationViewHierarchyManager = mNotificationViewHierarchyManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationFilter")
  public static void injectMNotificationFilter(Dependency instance,
      Lazy<NotificationFilter> mNotificationFilter) {
    instance.mNotificationFilter = mNotificationFilter;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mKeyguardDismissUtil")
  public static void injectMKeyguardDismissUtil(Dependency instance,
      Lazy<KeyguardDismissUtil> mKeyguardDismissUtil) {
    instance.mKeyguardDismissUtil = mKeyguardDismissUtil;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSmartReplyController")
  public static void injectMSmartReplyController(Dependency instance,
      Lazy<SmartReplyController> mSmartReplyController) {
    instance.mSmartReplyController = mSmartReplyController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mRemoteInputQuickSettingsDisabler")
  public static void injectMRemoteInputQuickSettingsDisabler(Dependency instance,
      Lazy<RemoteInputQuickSettingsDisabler> mRemoteInputQuickSettingsDisabler) {
    instance.mRemoteInputQuickSettingsDisabler = mRemoteInputQuickSettingsDisabler;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationEntryManager")
  public static void injectMNotificationEntryManager(Dependency instance,
      Lazy<NotificationEntryManager> mNotificationEntryManager) {
    instance.mNotificationEntryManager = mNotificationEntryManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSensorPrivacyManager")
  public static void injectMSensorPrivacyManager(Dependency instance,
      Lazy<SensorPrivacyManager> mSensorPrivacyManager) {
    instance.mSensorPrivacyManager = mSensorPrivacyManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAutoHideController")
  public static void injectMAutoHideController(Dependency instance,
      Lazy<AutoHideController> mAutoHideController) {
    instance.mAutoHideController = mAutoHideController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mForegroundServiceNotificationListener")
  public static void injectMForegroundServiceNotificationListener(Dependency instance,
      Lazy<ForegroundServiceNotificationListener> mForegroundServiceNotificationListener) {
    instance.mForegroundServiceNotificationListener = mForegroundServiceNotificationListener;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mPrivacyItemController")
  public static void injectMPrivacyItemController(Dependency instance,
      Lazy<PrivacyItemController> mPrivacyItemController) {
    instance.mPrivacyItemController = mPrivacyItemController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mBgLooper")
  @Background
  public static void injectMBgLooper(Dependency instance, Lazy<Looper> mBgLooper) {
    instance.mBgLooper = mBgLooper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mBgHandler")
  @Background
  public static void injectMBgHandler(Dependency instance, Lazy<Handler> mBgHandler) {
    instance.mBgHandler = mBgHandler;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mMainLooper")
  @Main
  public static void injectMMainLooper(Dependency instance, Lazy<Looper> mMainLooper) {
    instance.mMainLooper = mMainLooper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mMainHandler")
  @Main
  public static void injectMMainHandler(Dependency instance, Lazy<Handler> mMainHandler) {
    instance.mMainHandler = mMainHandler;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mTimeTickHandler")
  @Named("time_tick_handler")
  public static void injectMTimeTickHandler(Dependency instance, Lazy<Handler> mTimeTickHandler) {
    instance.mTimeTickHandler = mTimeTickHandler;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mLeakReportEmail")
  @Named("leak_report_email")
  public static void injectMLeakReportEmail(Dependency instance, Lazy<String> mLeakReportEmail) {
    instance.mLeakReportEmail = mLeakReportEmail;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mMainExecutor")
  @Main
  public static void injectMMainExecutor(Dependency instance, Lazy<Executor> mMainExecutor) {
    instance.mMainExecutor = mMainExecutor;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mBackgroundExecutor")
  @Background
  public static void injectMBackgroundExecutor(Dependency instance,
      Lazy<Executor> mBackgroundExecutor) {
    instance.mBackgroundExecutor = mBackgroundExecutor;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mClockManager")
  public static void injectMClockManager(Dependency instance, Lazy<ClockManager> mClockManager) {
    instance.mClockManager = mClockManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mActivityManagerWrapper")
  public static void injectMActivityManagerWrapper(Dependency instance,
      Lazy<ActivityManagerWrapper> mActivityManagerWrapper) {
    instance.mActivityManagerWrapper = mActivityManagerWrapper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDevicePolicyManagerWrapper")
  public static void injectMDevicePolicyManagerWrapper(Dependency instance,
      Lazy<DevicePolicyManagerWrapper> mDevicePolicyManagerWrapper) {
    instance.mDevicePolicyManagerWrapper = mDevicePolicyManagerWrapper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mPackageManagerWrapper")
  public static void injectMPackageManagerWrapper(Dependency instance,
      Lazy<PackageManagerWrapper> mPackageManagerWrapper) {
    instance.mPackageManagerWrapper = mPackageManagerWrapper;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSensorPrivacyController")
  public static void injectMSensorPrivacyController(Dependency instance,
      Lazy<SensorPrivacyController> mSensorPrivacyController) {
    instance.mSensorPrivacyController = mSensorPrivacyController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDockManager")
  public static void injectMDockManager(Dependency instance, Lazy<DockManager> mDockManager) {
    instance.mDockManager = mDockManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mINotificationManager")
  public static void injectMINotificationManager(Dependency instance,
      Lazy<INotificationManager> mINotificationManager) {
    instance.mINotificationManager = mINotificationManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSysUiStateFlagsContainer")
  public static void injectMSysUiStateFlagsContainer(Dependency instance,
      Lazy<SysUiState> mSysUiStateFlagsContainer) {
    instance.mSysUiStateFlagsContainer = mSysUiStateFlagsContainer;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAlarmManager")
  public static void injectMAlarmManager(Dependency instance, Lazy<AlarmManager> mAlarmManager) {
    instance.mAlarmManager = mAlarmManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mKeyguardSecurityModel")
  public static void injectMKeyguardSecurityModel(Dependency instance,
      Lazy<KeyguardSecurityModel> mKeyguardSecurityModel) {
    instance.mKeyguardSecurityModel = mKeyguardSecurityModel;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDozeParameters")
  public static void injectMDozeParameters(Dependency instance,
      Lazy<DozeParameters> mDozeParameters) {
    instance.mDozeParameters = mDozeParameters;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mWallpaperManager")
  public static void injectMWallpaperManager(Dependency instance,
      Lazy<IWallpaperManager> mWallpaperManager) {
    instance.mWallpaperManager = mWallpaperManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mCommandQueue")
  public static void injectMCommandQueue(Dependency instance, Lazy<CommandQueue> mCommandQueue) {
    instance.mCommandQueue = mCommandQueue;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mRecordingController")
  public static void injectMRecordingController(Dependency instance,
      Lazy<RecordingController> mRecordingController) {
    instance.mRecordingController = mRecordingController;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mProtoTracer")
  public static void injectMProtoTracer(Dependency instance, Lazy<ProtoTracer> mProtoTracer) {
    instance.mProtoTracer = mProtoTracer;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mMediaOutputDialogFactory")
  public static void injectMMediaOutputDialogFactory(Dependency instance,
      Lazy<MediaOutputDialogFactory> mMediaOutputDialogFactory) {
    instance.mMediaOutputDialogFactory = mMediaOutputDialogFactory;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mDeviceConfigProxy")
  public static void injectMDeviceConfigProxy(Dependency instance,
      Lazy<DeviceConfigProxy> mDeviceConfigProxy) {
    instance.mDeviceConfigProxy = mDeviceConfigProxy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNavbarButtonsControllerLazy")
  public static void injectMNavbarButtonsControllerLazy(Dependency instance,
      Lazy<NavigationBarOverlayController> mNavbarButtonsControllerLazy) {
    instance.mNavbarButtonsControllerLazy = mNavbarButtonsControllerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mTelephonyListenerManager")
  public static void injectMTelephonyListenerManager(Dependency instance,
      Lazy<TelephonyListenerManager> mTelephonyListenerManager) {
    instance.mTelephonyListenerManager = mTelephonyListenerManager;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mSystemStatusAnimationSchedulerLazy")
  public static void injectMSystemStatusAnimationSchedulerLazy(Dependency instance,
      Lazy<SystemStatusAnimationScheduler> mSystemStatusAnimationSchedulerLazy) {
    instance.mSystemStatusAnimationSchedulerLazy = mSystemStatusAnimationSchedulerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mPrivacyDotViewControllerLazy")
  public static void injectMPrivacyDotViewControllerLazy(Dependency instance,
      Lazy<PrivacyDotViewController> mPrivacyDotViewControllerLazy) {
    instance.mPrivacyDotViewControllerLazy = mPrivacyDotViewControllerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mEdgeBackGestureHandlerFactoryLazy")
  public static void injectMEdgeBackGestureHandlerFactoryLazy(Dependency instance,
      Lazy<EdgeBackGestureHandler.Factory> mEdgeBackGestureHandlerFactoryLazy) {
    instance.mEdgeBackGestureHandlerFactoryLazy = mEdgeBackGestureHandlerFactoryLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mUiEventLogger")
  public static void injectMUiEventLogger(Dependency instance, Lazy<UiEventLogger> mUiEventLogger) {
    instance.mUiEventLogger = mUiEventLogger;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mFeatureFlagsLazy")
  public static void injectMFeatureFlagsLazy(Dependency instance,
      Lazy<FeatureFlags> mFeatureFlagsLazy) {
    instance.mFeatureFlagsLazy = mFeatureFlagsLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mContentInsetsProviderLazy")
  public static void injectMContentInsetsProviderLazy(Dependency instance,
      Lazy<StatusBarContentInsetsProvider> mContentInsetsProviderLazy) {
    instance.mContentInsetsProviderLazy = mContentInsetsProviderLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mInternetDialogFactory")
  public static void injectMInternetDialogFactory(Dependency instance,
      Lazy<InternetDialogFactory> mInternetDialogFactory) {
    instance.mInternetDialogFactory = mInternetDialogFactory;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mNotificationSectionsManagerLazy")
  public static void injectMNotificationSectionsManagerLazy(Dependency instance,
      Lazy<NotificationSectionsManager> mNotificationSectionsManagerLazy) {
    instance.mNotificationSectionsManagerLazy = mNotificationSectionsManagerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mUnlockedScreenOffAnimationControllerLazy")
  public static void injectMUnlockedScreenOffAnimationControllerLazy(Dependency instance,
      Lazy<UnlockedScreenOffAnimationController> mUnlockedScreenOffAnimationControllerLazy) {
    instance.mUnlockedScreenOffAnimationControllerLazy = mUnlockedScreenOffAnimationControllerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAmbientStateLazy")
  public static void injectMAmbientStateLazy(Dependency instance,
      Lazy<AmbientState> mAmbientStateLazy) {
    instance.mAmbientStateLazy = mAmbientStateLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mGroupMembershipManagerLazy")
  public static void injectMGroupMembershipManagerLazy(Dependency instance,
      Lazy<GroupMembershipManager> mGroupMembershipManagerLazy) {
    instance.mGroupMembershipManagerLazy = mGroupMembershipManagerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mGroupExpansionManagerLazy")
  public static void injectMGroupExpansionManagerLazy(Dependency instance,
      Lazy<GroupExpansionManager> mGroupExpansionManagerLazy) {
    instance.mGroupExpansionManagerLazy = mGroupExpansionManagerLazy;
  }

  @InjectedFieldSignature("com.android.systemui.Dependency.mAuthController")
  public static void injectMAuthController(Dependency instance,
      Lazy<AuthController> mAuthController) {
    instance.mAuthController = mAuthController;
  }
}
