package com.android.systemui.dagger;

import android.animation.AnimationHandler;
import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityTaskManager;
import android.app.AlarmManager;
import android.app.IActivityManager;
import android.app.IActivityTaskManager;
import android.app.INotificationManager;
import android.app.KeyguardManager;
import android.app.NotificationManager;
import android.app.Service;
import android.app.WallpaperManager;
import android.app.admin.DevicePolicyManager;
import android.app.smartspace.SmartspaceManager;
import android.app.trust.TrustManager;
import android.content.BroadcastReceiver;
import android.content.ContentResolver;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.om.OverlayManager;
import android.content.pm.IPackageManager;
import android.content.pm.LauncherApps;
import android.content.pm.PackageManager;
import android.content.pm.ShortcutManager;
import android.content.res.Resources;
import android.hardware.Sensor;
import android.hardware.SensorManager;
import android.hardware.SensorPrivacyManager;
import android.hardware.devicestate.DeviceStateManager;
import android.hardware.display.AmbientDisplayConfiguration;
import android.hardware.display.ColorDisplayManager;
import android.hardware.display.DisplayManager;
import android.hardware.display.NightDisplayListener;
import android.hardware.face.FaceManager;
import android.hardware.fingerprint.FingerprintManager;
import android.media.AudioManager;
import android.media.IAudioService;
import android.media.MediaRouter2Manager;
import android.media.session.MediaSessionManager;
import android.net.ConnectivityManager;
import android.net.NetworkScoreManager;
import android.net.wifi.WifiManager;
import android.os.Handler;
import android.os.Looper;
import android.os.PowerManager;
import android.os.UserManager;
import android.os.Vibrator;
import android.permission.PermissionManager;
import android.service.dreams.IDreamManager;
import android.service.notification.StatusBarNotification;
import android.service.quickaccesswallet.QuickAccessWalletClient;
import android.telecom.TelecomManager;
import android.telephony.SubscriptionManager;
import android.telephony.TelephonyManager;
import android.util.DisplayMetrics;
import android.view.Choreographer;
import android.view.CrossWindowBlurListeners;
import android.view.IWindowManager;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewConfiguration;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.view.accessibility.AccessibilityManager;
import android.view.inputmethod.InputMethodManager;
import android.widget.FrameLayout;
import com.android.internal.app.AssistUtils;
import com.android.internal.app.IBatteryStats;
import com.android.internal.jank.InteractionJankMonitor;
import com.android.internal.logging.MetricsLogger;
import com.android.internal.logging.UiEventLogger;
import com.android.internal.statusbar.IStatusBarService;
import com.android.internal.util.LatencyTracker;
import com.android.internal.util.NotificationMessagingUtil;
import com.android.internal.widget.LockPatternUtils;
import com.android.keyguard.AdminSecondaryLockScreenController;
import com.android.keyguard.AdminSecondaryLockScreenController_Factory_Factory;
import com.android.keyguard.CarrierText;
import com.android.keyguard.CarrierTextController;
import com.android.keyguard.CarrierTextManager;
import com.android.keyguard.CarrierTextManager_Builder_Factory;
import com.android.keyguard.EmergencyButtonController;
import com.android.keyguard.EmergencyButtonController_Factory_Factory;
import com.android.keyguard.KeyguardClockSwitch;
import com.android.keyguard.KeyguardClockSwitchController;
import com.android.keyguard.KeyguardDisplayManager;
import com.android.keyguard.KeyguardDisplayManager_Factory;
import com.android.keyguard.KeyguardHostView;
import com.android.keyguard.KeyguardHostViewController;
import com.android.keyguard.KeyguardHostViewController_Factory;
import com.android.keyguard.KeyguardInputViewController;
import com.android.keyguard.KeyguardInputViewController_Factory_Factory;
import com.android.keyguard.KeyguardMessageAreaController;
import com.android.keyguard.KeyguardMessageAreaController_Factory_Factory;
import com.android.keyguard.KeyguardRootViewController;
import com.android.keyguard.KeyguardRootViewController_Factory;
import com.android.keyguard.KeyguardSecurityContainer;
import com.android.keyguard.KeyguardSecurityContainerController_Factory_Factory;
import com.android.keyguard.KeyguardSecurityModel;
import com.android.keyguard.KeyguardSecurityModel_Factory;
import com.android.keyguard.KeyguardSecurityViewFlipper;
import com.android.keyguard.KeyguardSecurityViewFlipperController;
import com.android.keyguard.KeyguardSecurityViewFlipperController_Factory;
import com.android.keyguard.KeyguardSliceView;
import com.android.keyguard.KeyguardSliceViewController;
import com.android.keyguard.KeyguardSliceViewController_Factory;
import com.android.keyguard.KeyguardStatusView;
import com.android.keyguard.KeyguardStatusViewController;
import com.android.keyguard.KeyguardUnfoldTransition;
import com.android.keyguard.KeyguardUnfoldTransition_Factory;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.keyguard.KeyguardUpdateMonitor_Factory;
import com.android.keyguard.LiftToActivateListener_Factory;
import com.android.keyguard.LockIconView;
import com.android.keyguard.LockIconViewController;
import com.android.keyguard.LockIconViewController_Factory;
import com.android.keyguard.ViewMediatorCallback;
import com.android.keyguard.clock.ClockManager;
import com.android.keyguard.clock.ClockManager_Factory;
import com.android.keyguard.clock.ClockModule_ProvideClockInfoListFactory;
import com.android.keyguard.clock.ClockOptionsProvider;
import com.android.keyguard.clock.ClockOptionsProvider_MembersInjector;
import com.android.keyguard.dagger.KeyguardBouncerComponent;
import com.android.keyguard.dagger.KeyguardBouncerModule_ProvidesKeyguardHostViewFactory;
import com.android.keyguard.dagger.KeyguardBouncerModule_ProvidesKeyguardSecurityContainerFactory;
import com.android.keyguard.dagger.KeyguardBouncerModule_ProvidesKeyguardSecurityViewFlipperFactory;
import com.android.keyguard.dagger.KeyguardBouncerModule_ProvidesRootViewFactory;
import com.android.keyguard.dagger.KeyguardQsUserSwitchComponent;
import com.android.keyguard.dagger.KeyguardStatusBarViewComponent;
import com.android.keyguard.dagger.KeyguardStatusBarViewModule_GetBatteryMeterViewFactory;
import com.android.keyguard.dagger.KeyguardStatusBarViewModule_GetCarrierTextFactory;
import com.android.keyguard.dagger.KeyguardStatusViewComponent;
import com.android.keyguard.dagger.KeyguardStatusViewModule_GetKeyguardClockSwitchFactory;
import com.android.keyguard.dagger.KeyguardStatusViewModule_GetKeyguardSliceViewFactory;
import com.android.keyguard.dagger.KeyguardUserSwitcherComponent;
import com.android.launcher3.icons.IconProvider;
import com.android.settingslib.bluetooth.LocalBluetoothManager;
import com.android.settingslib.users.EditUserInfoController;
import com.android.systemui.ActivityIntentHelper;
import com.android.systemui.ActivityIntentHelper_Factory;
import com.android.systemui.ActivityStarterDelegate;
import com.android.systemui.ActivityStarterDelegate_Factory;
import com.android.systemui.BootCompleteCacheImpl;
import com.android.systemui.BootCompleteCacheImpl_Factory;
import com.android.systemui.Dependency;
import com.android.systemui.Dependency_Factory;
import com.android.systemui.ForegroundServiceController;
import com.android.systemui.ForegroundServiceController_Factory;
import com.android.systemui.ForegroundServiceNotificationListener;
import com.android.systemui.ForegroundServiceNotificationListener_Factory;
import com.android.systemui.ForegroundServicesDialog;
import com.android.systemui.ForegroundServicesDialog_Factory;
import com.android.systemui.ImageWallpaper;
import com.android.systemui.ImageWallpaper_Factory;
import com.android.systemui.InitController;
import com.android.systemui.InitController_Factory;
import com.android.systemui.LatencyTester;
import com.android.systemui.LatencyTester_Factory;
import com.android.systemui.ScreenDecorations;
import com.android.systemui.ScreenDecorations_Factory;
import com.android.systemui.SliceBroadcastRelayHandler;
import com.android.systemui.SliceBroadcastRelayHandler_Factory;
import com.android.systemui.SystemUI;
import com.android.systemui.SystemUIAppComponentFactory;
import com.android.systemui.SystemUIAppComponentFactory_MembersInjector;
import com.android.systemui.SystemUIService;
import com.android.systemui.SystemUIService_Factory;
import com.android.systemui.UiOffloadThread;
import com.android.systemui.UiOffloadThread_Factory;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver;
import com.android.systemui.accessibility.AccessibilityButtonModeObserver_Factory;
import com.android.systemui.accessibility.AccessibilityButtonTargetsObserver;
import com.android.systemui.accessibility.AccessibilityButtonTargetsObserver_Factory;
import com.android.systemui.accessibility.ModeSwitchesController;
import com.android.systemui.accessibility.SystemActions;
import com.android.systemui.accessibility.SystemActions_Factory;
import com.android.systemui.accessibility.WindowMagnification;
import com.android.systemui.accessibility.WindowMagnification_Factory;
import com.android.systemui.accessibility.floatingmenu.AccessibilityFloatingMenuController;
import com.android.systemui.animation.ActivityLaunchAnimator;
import com.android.systemui.animation.DialogLaunchAnimator;
import com.android.systemui.appops.AppOpsControllerImpl;
import com.android.systemui.appops.AppOpsControllerImpl_Factory;
import com.android.systemui.assist.AssistLogger;
import com.android.systemui.assist.AssistLogger_Factory;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.assist.AssistManager_Factory;
import com.android.systemui.assist.AssistModule_ProvideAssistUtilsFactory;
import com.android.systemui.assist.PhoneStateMonitor;
import com.android.systemui.assist.PhoneStateMonitor_Factory;
import com.android.systemui.assist.ui.DefaultUiController;
import com.android.systemui.assist.ui.DefaultUiController_Factory;
import com.android.systemui.battery.BatteryMeterView;
import com.android.systemui.battery.BatteryMeterViewController;
import com.android.systemui.battery.BatteryMeterViewController_Factory;
import com.android.systemui.biometrics.AuthController;
import com.android.systemui.biometrics.AuthController_Factory;
import com.android.systemui.biometrics.AuthRippleController;
import com.android.systemui.biometrics.AuthRippleController_Factory;
import com.android.systemui.biometrics.AuthRippleView;
import com.android.systemui.biometrics.SidefpsController;
import com.android.systemui.biometrics.SidefpsController_Factory;
import com.android.systemui.biometrics.UdfpsController;
import com.android.systemui.biometrics.UdfpsController_Factory;
import com.android.systemui.biometrics.UdfpsHapticsSimulator;
import com.android.systemui.biometrics.UdfpsHapticsSimulator_Factory;
import com.android.systemui.biometrics.UdfpsHbmProvider;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.broadcast.logging.BroadcastDispatcherLogger;
import com.android.systemui.broadcast.logging.BroadcastDispatcherLogger_Factory;
import com.android.systemui.classifier.BrightLineFalsingManager;
import com.android.systemui.classifier.BrightLineFalsingManager_Factory;
import com.android.systemui.classifier.DiagonalClassifier_Factory;
import com.android.systemui.classifier.DistanceClassifier_Factory;
import com.android.systemui.classifier.DoubleTapClassifier;
import com.android.systemui.classifier.DoubleTapClassifier_Factory;
import com.android.systemui.classifier.FalsingClassifier;
import com.android.systemui.classifier.FalsingCollector;
import com.android.systemui.classifier.FalsingCollectorImpl_Factory;
import com.android.systemui.classifier.FalsingDataProvider;
import com.android.systemui.classifier.FalsingDataProvider_Factory;
import com.android.systemui.classifier.FalsingManagerProxy;
import com.android.systemui.classifier.FalsingManagerProxy_Factory;
import com.android.systemui.classifier.FalsingModule_ProvidesBrightLineGestureClassifiersFactory;
import com.android.systemui.classifier.FalsingModule_ProvidesDoubleTapTimeoutMsFactory;
import com.android.systemui.classifier.FalsingModule_ProvidesDoubleTapTouchSlopFactory;
import com.android.systemui.classifier.FalsingModule_ProvidesSingleTapTouchSlopFactory;
import com.android.systemui.classifier.HistoryTracker;
import com.android.systemui.classifier.HistoryTracker_Factory;
import com.android.systemui.classifier.PointerCountClassifier_Factory;
import com.android.systemui.classifier.ProximityClassifier_Factory;
import com.android.systemui.classifier.SingleTapClassifier;
import com.android.systemui.classifier.SingleTapClassifier_Factory;
import com.android.systemui.classifier.TypeClassifier;
import com.android.systemui.classifier.TypeClassifier_Factory;
import com.android.systemui.classifier.ZigZagClassifier_Factory;
import com.android.systemui.colorextraction.SysuiColorExtractor;
import com.android.systemui.colorextraction.SysuiColorExtractor_Factory;
import com.android.systemui.controls.ControlsMetricsLoggerImpl;
import com.android.systemui.controls.ControlsMetricsLoggerImpl_Factory;
import com.android.systemui.controls.CustomIconCache;
import com.android.systemui.controls.CustomIconCache_Factory;
import com.android.systemui.controls.controller.ControlsBindingControllerImpl;
import com.android.systemui.controls.controller.ControlsBindingControllerImpl_Factory;
import com.android.systemui.controls.controller.ControlsControllerImpl;
import com.android.systemui.controls.controller.ControlsControllerImpl_Factory;
import com.android.systemui.controls.controller.ControlsFavoritePersistenceWrapper;
import com.android.systemui.controls.dagger.ControlsComponent;
import com.android.systemui.controls.dagger.ControlsComponent_Factory;
import com.android.systemui.controls.dagger.ControlsModule_ProvidesControlsFeatureEnabledFactory;
import com.android.systemui.controls.management.ControlsEditingActivity;
import com.android.systemui.controls.management.ControlsEditingActivity_Factory;
import com.android.systemui.controls.management.ControlsFavoritingActivity;
import com.android.systemui.controls.management.ControlsFavoritingActivity_Factory;
import com.android.systemui.controls.management.ControlsListingControllerImpl;
import com.android.systemui.controls.management.ControlsListingControllerImpl_Factory;
import com.android.systemui.controls.management.ControlsProviderSelectorActivity;
import com.android.systemui.controls.management.ControlsProviderSelectorActivity_Factory;
import com.android.systemui.controls.management.ControlsRequestDialog;
import com.android.systemui.controls.management.ControlsRequestDialog_Factory;
import com.android.systemui.controls.ui.ControlActionCoordinatorImpl;
import com.android.systemui.controls.ui.ControlActionCoordinatorImpl_Factory;
import com.android.systemui.controls.ui.ControlsActivity;
import com.android.systemui.controls.ui.ControlsActivity_Factory;
import com.android.systemui.controls.ui.ControlsUiControllerImpl;
import com.android.systemui.controls.ui.ControlsUiControllerImpl_Factory;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.demomode.dagger.DemoModeModule_ProvideDemoModeControllerFactory;
import com.android.systemui.dock.DockManagerImpl;
import com.android.systemui.dock.DockManagerImpl_Factory;
import com.android.systemui.doze.AlwaysOnDisplayPolicy;
import com.android.systemui.doze.DozeAuthRemover;
import com.android.systemui.doze.DozeAuthRemover_Factory;
import com.android.systemui.doze.DozeDockHandler;
import com.android.systemui.doze.DozeDockHandler_Factory;
import com.android.systemui.doze.DozeFalsingManagerAdapter;
import com.android.systemui.doze.DozeFalsingManagerAdapter_Factory;
import com.android.systemui.doze.DozeLog;
import com.android.systemui.doze.DozeLog_Factory;
import com.android.systemui.doze.DozeLogger;
import com.android.systemui.doze.DozeLogger_Factory;
import com.android.systemui.doze.DozeMachine;
import com.android.systemui.doze.DozeMachine_Factory;
import com.android.systemui.doze.DozePauser;
import com.android.systemui.doze.DozePauser_Factory;
import com.android.systemui.doze.DozeScreenBrightness;
import com.android.systemui.doze.DozeScreenBrightness_Factory;
import com.android.systemui.doze.DozeScreenState;
import com.android.systemui.doze.DozeScreenState_Factory;
import com.android.systemui.doze.DozeService;
import com.android.systemui.doze.DozeService_Factory;
import com.android.systemui.doze.DozeTriggers;
import com.android.systemui.doze.DozeTriggers_Factory;
import com.android.systemui.doze.DozeUi;
import com.android.systemui.doze.DozeUi_Factory;
import com.android.systemui.doze.DozeWallpaperState;
import com.android.systemui.doze.DozeWallpaperState_Factory;
import com.android.systemui.doze.dagger.DozeComponent;
import com.android.systemui.doze.dagger.DozeModule_ProvidesBrightnessSensorsFactory;
import com.android.systemui.doze.dagger.DozeModule_ProvidesDozeMachinePartesFactory;
import com.android.systemui.doze.dagger.DozeModule_ProvidesDozeWakeLockFactory;
import com.android.systemui.doze.dagger.DozeModule_ProvidesWrappedServiceFactory;
import com.android.systemui.dump.DumpHandler;
import com.android.systemui.dump.DumpHandler_Factory;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.dump.DumpManager_Factory;
import com.android.systemui.dump.LogBufferEulogizer;
import com.android.systemui.dump.LogBufferEulogizer_Factory;
import com.android.systemui.dump.LogBufferFreezer;
import com.android.systemui.dump.LogBufferFreezer_Factory;
import com.android.systemui.dump.SystemUIAuxiliaryDumpService;
import com.android.systemui.dump.SystemUIAuxiliaryDumpService_Factory;
import com.android.systemui.flags.FeatureFlagManager;
import com.android.systemui.flags.FeatureFlagManager_Factory;
import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.flags.FeatureFlags_Factory;
import com.android.systemui.flags.FlagManager;
import com.android.systemui.flags.FlagsModule_ProvideFlagManagerFactory;
import com.android.systemui.fragments.FragmentService;
import com.android.systemui.fragments.FragmentService_Factory;
import com.android.systemui.globalactions.GlobalActionsComponent;
import com.android.systemui.globalactions.GlobalActionsComponent_Factory;
import com.android.systemui.globalactions.GlobalActionsDialogLite;
import com.android.systemui.globalactions.GlobalActionsDialogLite_Factory;
import com.android.systemui.globalactions.GlobalActionsImpl;
import com.android.systemui.globalactions.GlobalActionsImpl_Factory;
import com.android.systemui.keyguard.DismissCallbackRegistry;
import com.android.systemui.keyguard.DismissCallbackRegistry_Factory;
import com.android.systemui.keyguard.KeyguardLifecyclesDispatcher;
import com.android.systemui.keyguard.KeyguardLifecyclesDispatcher_Factory;
import com.android.systemui.keyguard.KeyguardService;
import com.android.systemui.keyguard.KeyguardService_Factory;
import com.android.systemui.keyguard.KeyguardSliceProvider;
import com.android.systemui.keyguard.KeyguardSliceProvider_MembersInjector;
import com.android.systemui.keyguard.KeyguardUnlockAnimationController;
import com.android.systemui.keyguard.KeyguardUnlockAnimationController_Factory;
import com.android.systemui.keyguard.KeyguardViewMediator;
import com.android.systemui.keyguard.LifecycleScreenStatusProvider;
import com.android.systemui.keyguard.LifecycleScreenStatusProvider_Factory;
import com.android.systemui.keyguard.ScreenLifecycle;
import com.android.systemui.keyguard.ScreenLifecycle_Factory;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.keyguard.WakefulnessLifecycle_Factory;
import com.android.systemui.keyguard.WorkLockActivity;
import com.android.systemui.keyguard.WorkLockActivity_Factory;
import com.android.systemui.keyguard.dagger.KeyguardModule_NewKeyguardViewMediatorFactory;
import com.android.systemui.log.LogBuffer;
import com.android.systemui.log.LogBufferFactory;
import com.android.systemui.log.LogBufferFactory_Factory;
import com.android.systemui.log.LogcatEchoTracker;
import com.android.systemui.log.dagger.LogModule_ProvideBroadcastDispatcherLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideCollapsedSbFragmentLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideDozeLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideLSShadeTransitionControllerBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideLogcatEchoTrackerFactory;
import com.android.systemui.log.dagger.LogModule_ProvideNotifInteractionLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideNotificationSectionLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideNotificationsLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvidePrivacyLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideQSFragmentDisableLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideQuickSettingsLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideSwipeAwayGestureLogBufferFactory;
import com.android.systemui.log.dagger.LogModule_ProvideToastLogBufferFactory;
import com.android.systemui.media.KeyguardMediaController;
import com.android.systemui.media.KeyguardMediaController_Factory;
import com.android.systemui.media.LocalMediaManagerFactory;
import com.android.systemui.media.LocalMediaManagerFactory_Factory;
import com.android.systemui.media.MediaBrowserFactory;
import com.android.systemui.media.MediaBrowserFactory_Factory;
import com.android.systemui.media.MediaCarouselController;
import com.android.systemui.media.MediaCarouselController_Factory;
import com.android.systemui.media.MediaControlPanel;
import com.android.systemui.media.MediaControlPanel_Factory;
import com.android.systemui.media.MediaControllerFactory;
import com.android.systemui.media.MediaControllerFactory_Factory;
import com.android.systemui.media.MediaDataCombineLatest_Factory;
import com.android.systemui.media.MediaDataFilter;
import com.android.systemui.media.MediaDataFilter_Factory;
import com.android.systemui.media.MediaDataManager;
import com.android.systemui.media.MediaDataManager_Factory;
import com.android.systemui.media.MediaDeviceManager;
import com.android.systemui.media.MediaDeviceManager_Factory;
import com.android.systemui.media.MediaFeatureFlag;
import com.android.systemui.media.MediaFeatureFlag_Factory;
import com.android.systemui.media.MediaHierarchyManager;
import com.android.systemui.media.MediaHierarchyManager_Factory;
import com.android.systemui.media.MediaHost;
import com.android.systemui.media.MediaHostStatesManager;
import com.android.systemui.media.MediaHostStatesManager_Factory;
import com.android.systemui.media.MediaHost_MediaHostStateHolder_Factory;
import com.android.systemui.media.MediaResumeListener;
import com.android.systemui.media.MediaResumeListener_Factory;
import com.android.systemui.media.MediaSessionBasedFilter;
import com.android.systemui.media.MediaSessionBasedFilter_Factory;
import com.android.systemui.media.MediaTimeoutListener;
import com.android.systemui.media.MediaTimeoutListener_Factory;
import com.android.systemui.media.MediaViewController;
import com.android.systemui.media.MediaViewController_Factory;
import com.android.systemui.media.ResumeMediaBrowserFactory;
import com.android.systemui.media.ResumeMediaBrowserFactory_Factory;
import com.android.systemui.media.SeekBarViewModel;
import com.android.systemui.media.SeekBarViewModel_Factory;
import com.android.systemui.media.SmartspaceMediaDataProvider_Factory;
import com.android.systemui.media.dagger.MediaModule_ProvidesKeyguardMediaHostFactory;
import com.android.systemui.media.dagger.MediaModule_ProvidesQSMediaHostFactory;
import com.android.systemui.media.dagger.MediaModule_ProvidesQuickQSMediaHostFactory;
import com.android.systemui.media.dialog.MediaOutputDialogFactory;
import com.android.systemui.media.dialog.MediaOutputDialogFactory_Factory;
import com.android.systemui.media.dialog.MediaOutputDialogReceiver;
import com.android.systemui.media.dialog.MediaOutputDialogReceiver_Factory;
import com.android.systemui.media.systemsounds.HomeSoundEffectController;
import com.android.systemui.media.systemsounds.HomeSoundEffectController_Factory;
import com.android.systemui.model.SysUiState;
import com.android.systemui.navigationbar.NavBarHelper;
import com.android.systemui.navigationbar.NavBarHelper_Factory;
import com.android.systemui.navigationbar.NavigationBar;
import com.android.systemui.navigationbar.NavigationBarController;
import com.android.systemui.navigationbar.NavigationBarController_Factory;
import com.android.systemui.navigationbar.NavigationBarOverlayController;
import com.android.systemui.navigationbar.NavigationBarOverlayController_Factory;
import com.android.systemui.navigationbar.NavigationBar_Factory_Factory;
import com.android.systemui.navigationbar.NavigationModeController;
import com.android.systemui.navigationbar.NavigationModeController_Factory;
import com.android.systemui.navigationbar.TaskbarDelegate;
import com.android.systemui.navigationbar.TaskbarDelegate_Factory;
import com.android.systemui.navigationbar.gestural.EdgeBackGestureHandler;
import com.android.systemui.navigationbar.gestural.EdgeBackGestureHandler_Factory_Factory;
import com.android.systemui.people.PeopleProvider;
import com.android.systemui.people.PeopleProvider_MembersInjector;
import com.android.systemui.people.PeopleSpaceActivity;
import com.android.systemui.people.PeopleSpaceActivity_Factory;
import com.android.systemui.people.widget.LaunchConversationActivity;
import com.android.systemui.people.widget.LaunchConversationActivity_Factory;
import com.android.systemui.people.widget.PeopleSpaceWidgetManager;
import com.android.systemui.people.widget.PeopleSpaceWidgetManager_Factory;
import com.android.systemui.people.widget.PeopleSpaceWidgetPinnedReceiver;
import com.android.systemui.people.widget.PeopleSpaceWidgetPinnedReceiver_Factory;
import com.android.systemui.people.widget.PeopleSpaceWidgetProvider;
import com.android.systemui.people.widget.PeopleSpaceWidgetProvider_Factory;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.BcSmartspaceDataPlugin;
import com.android.systemui.plugins.PluginDependencyProvider;
import com.android.systemui.plugins.PluginDependencyProvider_Factory;
import com.android.systemui.plugins.PluginEnablerImpl;
import com.android.systemui.plugins.PluginEnablerImpl_Factory;
import com.android.systemui.plugins.PluginsModule_ProvidePluginInstanceManagerFactoryFactory;
import com.android.systemui.plugins.PluginsModule_ProvidesPluginDebugFactory;
import com.android.systemui.plugins.PluginsModule_ProvidesPluginExecutorFactory;
import com.android.systemui.plugins.PluginsModule_ProvidesPluginInstanceFactoryFactory;
import com.android.systemui.plugins.PluginsModule_ProvidesPluginManagerFactory;
import com.android.systemui.plugins.PluginsModule_ProvidesPluginPrefsFactory;
import com.android.systemui.plugins.PluginsModule_ProvidesPrivilegedPluginsFactory;
import com.android.systemui.plugins.VolumeDialog;
import com.android.systemui.power.EnhancedEstimatesImpl;
import com.android.systemui.power.EnhancedEstimatesImpl_Factory;
import com.android.systemui.power.PowerNotificationWarnings;
import com.android.systemui.power.PowerNotificationWarnings_Factory;
import com.android.systemui.power.PowerUI;
import com.android.systemui.power.PowerUI_Factory;
import com.android.systemui.privacy.OngoingPrivacyChip;
import com.android.systemui.privacy.PrivacyDialogController;
import com.android.systemui.privacy.PrivacyDialogController_Factory;
import com.android.systemui.privacy.PrivacyItemController;
import com.android.systemui.privacy.PrivacyItemController_Factory;
import com.android.systemui.privacy.logging.PrivacyLogger;
import com.android.systemui.privacy.logging.PrivacyLogger_Factory;
import com.android.systemui.privacy.television.TvOngoingPrivacyChip;
import com.android.systemui.privacy.television.TvOngoingPrivacyChip_Factory;
import com.android.systemui.qs.AutoAddTracker;
import com.android.systemui.qs.AutoAddTracker_Builder_Factory;
import com.android.systemui.qs.FooterActionsController;
import com.android.systemui.qs.FooterActionsControllerBuilder;
import com.android.systemui.qs.FooterActionsControllerBuilder_Factory;
import com.android.systemui.qs.FooterActionsView;
import com.android.systemui.qs.HeaderPrivacyIconsController;
import com.android.systemui.qs.HeaderPrivacyIconsController_Factory;
import com.android.systemui.qs.QSAnimator;
import com.android.systemui.qs.QSAnimator_Factory;
import com.android.systemui.qs.QSContainerImpl;
import com.android.systemui.qs.QSContainerImplController;
import com.android.systemui.qs.QSContainerImplController_Factory;
import com.android.systemui.qs.QSDetailDisplayer;
import com.android.systemui.qs.QSDetailDisplayer_Factory;
import com.android.systemui.qs.QSExpansionPathInterpolator;
import com.android.systemui.qs.QSExpansionPathInterpolator_Factory;
import com.android.systemui.qs.QSFooter;
import com.android.systemui.qs.QSFooterView;
import com.android.systemui.qs.QSFooterViewController;
import com.android.systemui.qs.QSFooterViewController_Factory;
import com.android.systemui.qs.QSFragment;
import com.android.systemui.qs.QSFragmentDisableFlagsLogger;
import com.android.systemui.qs.QSPanel;
import com.android.systemui.qs.QSPanelController;
import com.android.systemui.qs.QSPanelController_Factory;
import com.android.systemui.qs.QSSecurityFooter_Factory;
import com.android.systemui.qs.QSSquishinessController;
import com.android.systemui.qs.QSSquishinessController_Factory;
import com.android.systemui.qs.QSTileHost;
import com.android.systemui.qs.QSTileHost_Factory;
import com.android.systemui.qs.QSTileRevealController_Factory_Factory;
import com.android.systemui.qs.QuickQSPanel;
import com.android.systemui.qs.QuickQSPanelController;
import com.android.systemui.qs.QuickQSPanelController_Factory;
import com.android.systemui.qs.QuickStatusBarHeader;
import com.android.systemui.qs.QuickStatusBarHeaderController_Factory;
import com.android.systemui.qs.ReduceBrightColorsController;
import com.android.systemui.qs.carrier.QSCarrierGroupController;
import com.android.systemui.qs.carrier.QSCarrierGroupController_Builder_Factory;
import com.android.systemui.qs.carrier.QSCarrierGroupController_SubscriptionManagerSlotIndexResolver_Factory;
import com.android.systemui.qs.customize.QSCustomizer;
import com.android.systemui.qs.customize.QSCustomizerController;
import com.android.systemui.qs.customize.QSCustomizerController_Factory;
import com.android.systemui.qs.customize.TileAdapter;
import com.android.systemui.qs.customize.TileAdapter_Factory;
import com.android.systemui.qs.customize.TileQueryHelper;
import com.android.systemui.qs.customize.TileQueryHelper_Factory;
import com.android.systemui.qs.dagger.QSFlagsModule_IsPMLiteEnabledFactory;
import com.android.systemui.qs.dagger.QSFlagsModule_IsReduceBrightColorsAvailableFactory;
import com.android.systemui.qs.dagger.QSFragmentComponent;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvideQSPanelFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvideRootViewFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvideThemedContextFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvideThemedLayoutInflaterFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesBatteryMeterViewFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesPrivacyChipFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQQSFooterActionsControllerFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQQSFooterActionsViewFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSContainerImplFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSCutomizerFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSFooterActionsControllerFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSFooterActionsViewFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSFooterFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSFooterViewFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSSecurityFooterViewFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQSUsingMediaPlayerFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQuickQSPanelFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesQuickStatusBarHeaderFactory;
import com.android.systemui.qs.dagger.QSFragmentModule_ProvidesStatusIconContainerFactory;
import com.android.systemui.qs.dagger.QSModule_ProvideAutoTileManagerFactory;
import com.android.systemui.qs.external.CustomTile;
import com.android.systemui.qs.external.CustomTileStatePersister;
import com.android.systemui.qs.external.CustomTileStatePersister_Factory;
import com.android.systemui.qs.external.CustomTile_Builder_Factory;
import com.android.systemui.qs.logging.QSLogger;
import com.android.systemui.qs.logging.QSLogger_Factory;
import com.android.systemui.qs.tileimpl.QSFactoryImpl;
import com.android.systemui.qs.tileimpl.QSFactoryImpl_Factory;
import com.android.systemui.qs.tiles.AODTile;
import com.android.systemui.qs.tiles.AODTile_Factory;
import com.android.systemui.qs.tiles.AirplaneModeTile;
import com.android.systemui.qs.tiles.AirplaneModeTile_Factory;
import com.android.systemui.qs.tiles.AlarmTile;
import com.android.systemui.qs.tiles.AlarmTile_Factory;
import com.android.systemui.qs.tiles.AmbientDisplayTile;
import com.android.systemui.qs.tiles.AmbientDisplayTile_Factory;
import com.android.systemui.qs.tiles.BatterySaverTile;
import com.android.systemui.qs.tiles.BatterySaverTile_Factory;
import com.android.systemui.qs.tiles.BluetoothTile;
import com.android.systemui.qs.tiles.BluetoothTile_Factory;
import com.android.systemui.qs.tiles.CaffeineTile;
import com.android.systemui.qs.tiles.CaffeineTile_Factory;
import com.android.systemui.qs.tiles.CameraToggleTile;
import com.android.systemui.qs.tiles.CameraToggleTile_Factory;
import com.android.systemui.qs.tiles.CastTile;
import com.android.systemui.qs.tiles.CastTile_Factory;
import com.android.systemui.qs.tiles.CellularTile;
import com.android.systemui.qs.tiles.CellularTile_Factory;
import com.android.systemui.qs.tiles.ColorInversionTile;
import com.android.systemui.qs.tiles.ColorInversionTile_Factory;
import com.android.systemui.qs.tiles.DataSaverTile;
import com.android.systemui.qs.tiles.DataSaverTile_Factory;
import com.android.systemui.qs.tiles.DeviceControlsTile;
import com.android.systemui.qs.tiles.DeviceControlsTile_Factory;
import com.android.systemui.qs.tiles.DndTile;
import com.android.systemui.qs.tiles.DndTile_Factory;
import com.android.systemui.qs.tiles.FlashlightTile;
import com.android.systemui.qs.tiles.FlashlightTile_Factory;
import com.android.systemui.qs.tiles.HeadsUpTile;
import com.android.systemui.qs.tiles.HeadsUpTile_Factory;
import com.android.systemui.qs.tiles.HotspotTile;
import com.android.systemui.qs.tiles.HotspotTile_Factory;
import com.android.systemui.qs.tiles.InternetTile;
import com.android.systemui.qs.tiles.InternetTile_Factory;
import com.android.systemui.qs.tiles.LocationTile;
import com.android.systemui.qs.tiles.LocationTile_Factory;
import com.android.systemui.qs.tiles.MicrophoneToggleTile;
import com.android.systemui.qs.tiles.MicrophoneToggleTile_Factory;
import com.android.systemui.qs.tiles.NfcTile;
import com.android.systemui.qs.tiles.NfcTile_Factory;
import com.android.systemui.qs.tiles.NightDisplayTile;
import com.android.systemui.qs.tiles.NightDisplayTile_Factory;
import com.android.systemui.qs.tiles.PowerShareTile;
import com.android.systemui.qs.tiles.PowerShareTile_Factory;
import com.android.systemui.qs.tiles.ProfilesTile;
import com.android.systemui.qs.tiles.ProfilesTile_Factory;
import com.android.systemui.qs.tiles.QuickAccessWalletTile;
import com.android.systemui.qs.tiles.QuickAccessWalletTile_Factory;
import com.android.systemui.qs.tiles.ReadingModeTile;
import com.android.systemui.qs.tiles.ReadingModeTile_Factory;
import com.android.systemui.qs.tiles.ReduceBrightColorsTile;
import com.android.systemui.qs.tiles.ReduceBrightColorsTile_Factory;
import com.android.systemui.qs.tiles.RotationLockTile;
import com.android.systemui.qs.tiles.RotationLockTile_Factory;
import com.android.systemui.qs.tiles.ScreenRecordTile;
import com.android.systemui.qs.tiles.ScreenRecordTile_Factory;
import com.android.systemui.qs.tiles.SyncTile;
import com.android.systemui.qs.tiles.SyncTile_Factory;
import com.android.systemui.qs.tiles.UiModeNightTile;
import com.android.systemui.qs.tiles.UiModeNightTile_Factory;
import com.android.systemui.qs.tiles.UsbTetherTile;
import com.android.systemui.qs.tiles.UsbTetherTile_Factory;
import com.android.systemui.qs.tiles.UserDetailView;
import com.android.systemui.qs.tiles.UserDetailView_Adapter_Factory;
import com.android.systemui.qs.tiles.UserTile;
import com.android.systemui.qs.tiles.UserTile_Factory;
import com.android.systemui.qs.tiles.VpnTile;
import com.android.systemui.qs.tiles.VpnTile_Factory;
import com.android.systemui.qs.tiles.WifiTile;
import com.android.systemui.qs.tiles.WifiTile_Factory;
import com.android.systemui.qs.tiles.WorkModeTile;
import com.android.systemui.qs.tiles.WorkModeTile_Factory;
import com.android.systemui.qs.tiles.dialog.InternetDialogController;
import com.android.systemui.qs.tiles.dialog.InternetDialogController_Factory;
import com.android.systemui.qs.tiles.dialog.InternetDialogFactory;
import com.android.systemui.qs.tiles.dialog.InternetDialogFactory_Factory;
import com.android.systemui.qs.user.UserSwitchDialogController;
import com.android.systemui.qs.user.UserSwitchDialogController_Factory;
import com.android.systemui.recents.OverviewProxyRecentsImpl;
import com.android.systemui.recents.OverviewProxyRecentsImpl_Factory;
import com.android.systemui.recents.OverviewProxyService;
import com.android.systemui.recents.OverviewProxyService_Factory;
import com.android.systemui.recents.Recents;
import com.android.systemui.recents.RecentsImplementation;
import com.android.systemui.recents.RecentsModule_ProvideRecentsImplFactory;
import com.android.systemui.recents.ScreenPinningRequest;
import com.android.systemui.recents.ScreenPinningRequest_Factory;
import com.android.systemui.screenrecord.RecordingController;
import com.android.systemui.screenrecord.RecordingController_Factory;
import com.android.systemui.screenrecord.RecordingService;
import com.android.systemui.screenrecord.RecordingService_Factory;
import com.android.systemui.screenshot.ActionProxyReceiver;
import com.android.systemui.screenshot.ActionProxyReceiver_Factory;
import com.android.systemui.screenshot.DeleteScreenshotReceiver;
import com.android.systemui.screenshot.DeleteScreenshotReceiver_Factory;
import com.android.systemui.screenshot.ImageExporter_Factory;
import com.android.systemui.screenshot.ImageTileSet_Factory;
import com.android.systemui.screenshot.LongScreenshotActivity;
import com.android.systemui.screenshot.LongScreenshotActivity_Factory;
import com.android.systemui.screenshot.LongScreenshotData;
import com.android.systemui.screenshot.LongScreenshotData_Factory;
import com.android.systemui.screenshot.ScreenshotController;
import com.android.systemui.screenshot.ScreenshotController_Factory;
import com.android.systemui.screenshot.ScreenshotNotificationsController;
import com.android.systemui.screenshot.ScreenshotNotificationsController_Factory;
import com.android.systemui.screenshot.ScreenshotSmartActions;
import com.android.systemui.screenshot.ScreenshotSmartActions_Factory;
import com.android.systemui.screenshot.ScrollCaptureClient;
import com.android.systemui.screenshot.ScrollCaptureClient_Factory;
import com.android.systemui.screenshot.ScrollCaptureController;
import com.android.systemui.screenshot.ScrollCaptureController_Factory;
import com.android.systemui.screenshot.SmartActionsReceiver;
import com.android.systemui.screenshot.SmartActionsReceiver_Factory;
import com.android.systemui.screenshot.TakeScreenshotService;
import com.android.systemui.screenshot.TakeScreenshotService_Factory;
import com.android.systemui.sensorprivacy.SensorUseStartedActivity;
import com.android.systemui.sensorprivacy.SensorUseStartedActivity_Factory;
import com.android.systemui.sensorprivacy.television.TvUnblockSensorActivity;
import com.android.systemui.sensorprivacy.television.TvUnblockSensorActivity_Factory;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.settings.brightness.BrightnessController;
import com.android.systemui.settings.brightness.BrightnessController_Factory_Factory;
import com.android.systemui.settings.brightness.BrightnessDialog;
import com.android.systemui.settings.brightness.BrightnessDialog_Factory;
import com.android.systemui.settings.brightness.BrightnessSliderController;
import com.android.systemui.settings.brightness.BrightnessSliderController_Factory_Factory;
import com.android.systemui.settings.dagger.SettingsModule_ProvideUserTrackerFactory;
import com.android.systemui.shared.plugins.PluginActionManager;
import com.android.systemui.shared.plugins.PluginInstance;
import com.android.systemui.shared.plugins.PluginManager;
import com.android.systemui.shared.plugins.PluginPrefs;
import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.shared.system.DevicePolicyManagerWrapper;
import com.android.systemui.shared.system.PackageManagerWrapper;
import com.android.systemui.shared.system.TaskStackChangeListeners;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import com.android.systemui.shortcut.ShortcutKeyDispatcher;
import com.android.systemui.shortcut.ShortcutKeyDispatcher_Factory;
import com.android.systemui.statusbar.ActionClickLogger;
import com.android.systemui.statusbar.ActionClickLogger_Factory;
import com.android.systemui.statusbar.BlurUtils;
import com.android.systemui.statusbar.BlurUtils_Factory;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.DisableFlagsLogger;
import com.android.systemui.statusbar.DisableFlagsLogger_Factory;
import com.android.systemui.statusbar.KeyguardIndicationController;
import com.android.systemui.statusbar.KeyguardIndicationController_Factory;
import com.android.systemui.statusbar.LockscreenShadeTransitionController;
import com.android.systemui.statusbar.LockscreenShadeTransitionController_Factory;
import com.android.systemui.statusbar.MediaArtworkProcessor;
import com.android.systemui.statusbar.MediaArtworkProcessor_Factory;
import com.android.systemui.statusbar.NotificationClickNotifier;
import com.android.systemui.statusbar.NotificationClickNotifier_Factory;
import com.android.systemui.statusbar.NotificationInteractionTracker;
import com.android.systemui.statusbar.NotificationInteractionTracker_Factory;
import com.android.systemui.statusbar.NotificationListener;
import com.android.systemui.statusbar.NotificationLockscreenUserManagerImpl;
import com.android.systemui.statusbar.NotificationLockscreenUserManagerImpl_Factory;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.NotificationRemoteInputManager;
import com.android.systemui.statusbar.NotificationShadeDepthController;
import com.android.systemui.statusbar.NotificationShadeDepthController_Factory;
import com.android.systemui.statusbar.NotificationShelf;
import com.android.systemui.statusbar.NotificationShelfController;
import com.android.systemui.statusbar.NotificationShelfController_Factory;
import com.android.systemui.statusbar.NotificationViewHierarchyManager;
import com.android.systemui.statusbar.OperatorNameViewController;
import com.android.systemui.statusbar.OperatorNameViewController_Factory_Factory;
import com.android.systemui.statusbar.PulseExpansionHandler;
import com.android.systemui.statusbar.PulseExpansionHandler_Factory;
import com.android.systemui.statusbar.RemoteInputNotificationRebuilder;
import com.android.systemui.statusbar.RemoteInputNotificationRebuilder_Factory;
import com.android.systemui.statusbar.SmartReplyController;
import com.android.systemui.statusbar.StatusBarStateControllerImpl;
import com.android.systemui.statusbar.StatusBarStateControllerImpl_Factory;
import com.android.systemui.statusbar.VibratorHelper;
import com.android.systemui.statusbar.VibratorHelper_Factory;
import com.android.systemui.statusbar.VisualizerView;
import com.android.systemui.statusbar.charging.WiredChargingRippleController;
import com.android.systemui.statusbar.charging.WiredChargingRippleController_Factory;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import com.android.systemui.statusbar.commandline.CommandRegistry_Factory;
import com.android.systemui.statusbar.connectivity.AccessPointControllerImpl;
import com.android.systemui.statusbar.connectivity.AccessPointControllerImpl_WifiPickerTrackerFactory_Factory;
import com.android.systemui.statusbar.connectivity.CallbackHandler;
import com.android.systemui.statusbar.connectivity.CallbackHandler_Factory;
import com.android.systemui.statusbar.connectivity.NetworkControllerImpl;
import com.android.systemui.statusbar.connectivity.NetworkControllerImpl_Factory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideActivityLaunchAnimatorFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideCommandQueueFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideDialogLaunchAnimatorFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideNotificationListenerFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideNotificationMediaManagerFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideNotificationRemoteInputManagerFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideNotificationViewHierarchyManagerFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideOngoingCallControllerFactory;
import com.android.systemui.statusbar.dagger.StatusBarDependenciesModule_ProvideSmartReplyControllerFactory;
import com.android.systemui.statusbar.events.PrivacyDotViewController;
import com.android.systemui.statusbar.events.PrivacyDotViewController_Factory;
import com.android.systemui.statusbar.events.SystemEventChipAnimationController;
import com.android.systemui.statusbar.events.SystemEventChipAnimationController_Factory;
import com.android.systemui.statusbar.events.SystemEventCoordinator;
import com.android.systemui.statusbar.events.SystemEventCoordinator_Factory;
import com.android.systemui.statusbar.events.SystemStatusAnimationScheduler;
import com.android.systemui.statusbar.events.SystemStatusAnimationScheduler_Factory;
import com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureHandler;
import com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureHandler_Factory;
import com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureLogger;
import com.android.systemui.statusbar.gesture.SwipeStatusBarAwayGestureLogger_Factory;
import com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController;
import com.android.systemui.statusbar.lockscreen.LockscreenSmartspaceController_Factory;
import com.android.systemui.statusbar.notification.AnimatedImageNotificationManager;
import com.android.systemui.statusbar.notification.AnimatedImageNotificationManager_Factory;
import com.android.systemui.statusbar.notification.AssistantFeedbackController;
import com.android.systemui.statusbar.notification.AssistantFeedbackController_Factory;
import com.android.systemui.statusbar.notification.ConversationNotificationManager;
import com.android.systemui.statusbar.notification.ConversationNotificationManager_Factory;
import com.android.systemui.statusbar.notification.ConversationNotificationProcessor;
import com.android.systemui.statusbar.notification.ConversationNotificationProcessor_Factory;
import com.android.systemui.statusbar.notification.DynamicChildBindController;
import com.android.systemui.statusbar.notification.DynamicChildBindController_Factory;
import com.android.systemui.statusbar.notification.DynamicPrivacyController;
import com.android.systemui.statusbar.notification.DynamicPrivacyController_Factory;
import com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController;
import com.android.systemui.statusbar.notification.ForegroundServiceDismissalFeatureController_Factory;
import com.android.systemui.statusbar.notification.InstantAppNotifier;
import com.android.systemui.statusbar.notification.InstantAppNotifier_Factory;
import com.android.systemui.statusbar.notification.NotificationClicker;
import com.android.systemui.statusbar.notification.NotificationClickerLogger;
import com.android.systemui.statusbar.notification.NotificationClickerLogger_Factory;
import com.android.systemui.statusbar.notification.NotificationClicker_Builder_Factory;
import com.android.systemui.statusbar.notification.NotificationEntryManager;
import com.android.systemui.statusbar.notification.NotificationEntryManagerLogger;
import com.android.systemui.statusbar.notification.NotificationEntryManagerLogger_Factory;
import com.android.systemui.statusbar.notification.NotificationFilter;
import com.android.systemui.statusbar.notification.NotificationFilter_Factory;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager;
import com.android.systemui.statusbar.notification.NotificationSectionsFeatureManager_Factory;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator;
import com.android.systemui.statusbar.notification.NotificationWakeUpCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.NotifCollection;
import com.android.systemui.statusbar.notification.collection.NotifCollection_Factory;
import com.android.systemui.statusbar.notification.collection.NotifInflaterImpl;
import com.android.systemui.statusbar.notification.collection.NotifInflaterImpl_Factory;
import com.android.systemui.statusbar.notification.collection.NotifPipeline;
import com.android.systemui.statusbar.notification.collection.NotifPipeline_Factory;
import com.android.systemui.statusbar.notification.collection.NotificationEntry;
import com.android.systemui.statusbar.notification.collection.NotificationRankingManager;
import com.android.systemui.statusbar.notification.collection.NotificationRankingManager_Factory;
import com.android.systemui.statusbar.notification.collection.ShadeListBuilder;
import com.android.systemui.statusbar.notification.collection.ShadeListBuilder_Factory;
import com.android.systemui.statusbar.notification.collection.TargetSdkResolver;
import com.android.systemui.statusbar.notification.collection.TargetSdkResolver_Factory;
import com.android.systemui.statusbar.notification.collection.coalescer.GroupCoalescer;
import com.android.systemui.statusbar.notification.collection.coalescer.GroupCoalescerLogger;
import com.android.systemui.statusbar.notification.collection.coalescer.GroupCoalescerLogger_Factory;
import com.android.systemui.statusbar.notification.collection.coalescer.GroupCoalescer_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.AppOpsCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.AppOpsCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.BubbleCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.BubbleCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.ConversationCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.ConversationCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.DeviceProvisionedCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.DeviceProvisionedCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinatorLogger;
import com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinatorLogger_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.GutsCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.HeadsUpCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.HeadsUpCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.HideLocallyDismissedNotifsCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.HideLocallyDismissedNotifsCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.HideNotifsForOtherUsersCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.HideNotifsForOtherUsersCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.KeyguardCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.KeyguardCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.MediaCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.MediaCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinators;
import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinatorsImpl;
import com.android.systemui.statusbar.notification.collection.coordinator.NotifCoordinatorsImpl_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.PreparationCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.PreparationCoordinatorLogger;
import com.android.systemui.statusbar.notification.collection.coordinator.PreparationCoordinatorLogger_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.PreparationCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.RankingCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.RankingCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.RemoteInputCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.SensitiveContentCoordinatorModule_ProvideCoordinatorFactory;
import com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinatorLogger;
import com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinatorLogger_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.ShadeEventCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.SharedCoordinatorLogger;
import com.android.systemui.statusbar.notification.collection.coordinator.SharedCoordinatorLogger_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.SmartspaceDedupingCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.SmartspaceDedupingCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.ViewConfigCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.ViewConfigCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.VisualStabilityCoordinator;
import com.android.systemui.statusbar.notification.collection.coordinator.VisualStabilityCoordinator_Factory;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorsModule_NotifCoordinatorsFactory;
import com.android.systemui.statusbar.notification.collection.coordinator.dagger.CoordinatorsSubcomponent;
import com.android.systemui.statusbar.notification.collection.inflation.LowPriorityInflationHelper;
import com.android.systemui.statusbar.notification.collection.inflation.LowPriorityInflationHelper_Factory;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl;
import com.android.systemui.statusbar.notification.collection.inflation.NotificationRowBinderImpl_Factory;
import com.android.systemui.statusbar.notification.collection.init.NotifPipelineInitializer;
import com.android.systemui.statusbar.notification.collection.init.NotifPipelineInitializer_Factory;
import com.android.systemui.statusbar.notification.collection.legacy.LegacyNotificationPresenterExtensions;
import com.android.systemui.statusbar.notification.collection.legacy.LegacyNotificationPresenterExtensions_Factory;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy;
import com.android.systemui.statusbar.notification.collection.legacy.NotificationGroupManagerLegacy_Factory;
import com.android.systemui.statusbar.notification.collection.legacy.VisualStabilityManager;
import com.android.systemui.statusbar.notification.collection.listbuilder.ShadeListBuilderLogger;
import com.android.systemui.statusbar.notification.collection.listbuilder.ShadeListBuilderLogger_Factory;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionLogger;
import com.android.systemui.statusbar.notification.collection.notifcollection.NotifCollectionLogger_Factory;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider;
import com.android.systemui.statusbar.notification.collection.provider.HighPriorityProvider_Factory;
import com.android.systemui.statusbar.notification.collection.render.GroupExpansionManager;
import com.android.systemui.statusbar.notification.collection.render.GroupMembershipManager;
import com.android.systemui.statusbar.notification.collection.render.NodeController;
import com.android.systemui.statusbar.notification.collection.render.NotifGutsViewManager;
import com.android.systemui.statusbar.notification.collection.render.NotifShadeEventSource;
import com.android.systemui.statusbar.notification.collection.render.NotifViewBarn;
import com.android.systemui.statusbar.notification.collection.render.NotifViewBarn_Factory;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderController;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderNodeControllerImpl;
import com.android.systemui.statusbar.notification.collection.render.SectionHeaderNodeControllerImpl_Factory;
import com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger;
import com.android.systemui.statusbar.notification.collection.render.ShadeViewDifferLogger_Factory;
import com.android.systemui.statusbar.notification.collection.render.ShadeViewManagerFactory;
import com.android.systemui.statusbar.notification.collection.render.ShadeViewManagerFactory_Factory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesAlertingHeaderControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesAlertingHeaderNodeControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesAlertingHeaderSubcomponentFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesIncomingHeaderControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesIncomingHeaderNodeControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesIncomingHeaderSubcomponentFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesPeopleHeaderControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesPeopleHeaderNodeControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesPeopleHeaderSubcomponentFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesSilentHeaderControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesSilentHeaderNodeControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationSectionHeadersModule_ProvidesSilentHeaderSubcomponentFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideCommonNotifCollectionFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideGroupExpansionManagerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideGroupMembershipManagerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotifGutsViewManagerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotifShadeEventSourceFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotificationEntryManagerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotificationGutsManagerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotificationLoggerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotificationPanelLoggerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideNotificationsControllerFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideOnUserInteractionCallbackFactory;
import com.android.systemui.statusbar.notification.dagger.NotificationsModule_ProvideVisualStabilityManagerFactory;
import com.android.systemui.statusbar.notification.dagger.SectionHeaderControllerSubcomponent;
import com.android.systemui.statusbar.notification.icon.IconBuilder;
import com.android.systemui.statusbar.notification.icon.IconBuilder_Factory;
import com.android.systemui.statusbar.notification.icon.IconManager;
import com.android.systemui.statusbar.notification.icon.IconManager_Factory;
import com.android.systemui.statusbar.notification.init.NotificationsController;
import com.android.systemui.statusbar.notification.init.NotificationsControllerImpl;
import com.android.systemui.statusbar.notification.init.NotificationsControllerImpl_Factory;
import com.android.systemui.statusbar.notification.init.NotificationsControllerStub;
import com.android.systemui.statusbar.notification.init.NotificationsControllerStub_Factory;
import com.android.systemui.statusbar.notification.interruption.BypassHeadsUpNotifier;
import com.android.systemui.statusbar.notification.interruption.BypassHeadsUpNotifier_Factory;
import com.android.systemui.statusbar.notification.interruption.HeadsUpController;
import com.android.systemui.statusbar.notification.interruption.HeadsUpController_Factory;
import com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder;
import com.android.systemui.statusbar.notification.interruption.HeadsUpViewBinder_Factory;
import com.android.systemui.statusbar.notification.interruption.NotificationInterruptStateProviderImpl;
import com.android.systemui.statusbar.notification.interruption.NotificationInterruptStateProviderImpl_Factory;
import com.android.systemui.statusbar.notification.logging.NotificationLogger;
import com.android.systemui.statusbar.notification.logging.NotificationLogger_ExpansionStateLogger_Factory;
import com.android.systemui.statusbar.notification.logging.NotificationPanelLogger;
import com.android.systemui.statusbar.notification.people.NotificationPersonExtractorPluginBoundary;
import com.android.systemui.statusbar.notification.people.NotificationPersonExtractorPluginBoundary_Factory;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifierImpl;
import com.android.systemui.statusbar.notification.people.PeopleNotificationIdentifierImpl_Factory;
import com.android.systemui.statusbar.notification.row.ActivatableNotificationViewController;
import com.android.systemui.statusbar.notification.row.ActivatableNotificationViewController_Factory;
import com.android.systemui.statusbar.notification.row.ChannelEditorDialogController;
import com.android.systemui.statusbar.notification.row.ChannelEditorDialogController_Factory;
import com.android.systemui.statusbar.notification.row.ChannelEditorDialog_Builder_Factory;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRow;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRowController;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRowController_Factory;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRowDragController;
import com.android.systemui.statusbar.notification.row.ExpandableNotificationRowDragController_Factory;
import com.android.systemui.statusbar.notification.row.ExpandableOutlineViewController;
import com.android.systemui.statusbar.notification.row.ExpandableOutlineViewController_Factory;
import com.android.systemui.statusbar.notification.row.ExpandableViewController;
import com.android.systemui.statusbar.notification.row.ExpandableViewController_Factory;
import com.android.systemui.statusbar.notification.row.NotifBindPipeline;
import com.android.systemui.statusbar.notification.row.NotifBindPipelineInitializer;
import com.android.systemui.statusbar.notification.row.NotifBindPipelineInitializer_Factory;
import com.android.systemui.statusbar.notification.row.NotifBindPipelineLogger;
import com.android.systemui.statusbar.notification.row.NotifBindPipelineLogger_Factory;
import com.android.systemui.statusbar.notification.row.NotifBindPipeline_Factory;
import com.android.systemui.statusbar.notification.row.NotifInflationErrorManager;
import com.android.systemui.statusbar.notification.row.NotifInflationErrorManager_Factory;
import com.android.systemui.statusbar.notification.row.NotifRemoteViewCache;
import com.android.systemui.statusbar.notification.row.NotifRemoteViewCacheImpl;
import com.android.systemui.statusbar.notification.row.NotifRemoteViewCacheImpl_Factory;
import com.android.systemui.statusbar.notification.row.NotificationContentInflater;
import com.android.systemui.statusbar.notification.row.NotificationContentInflater_Factory;
import com.android.systemui.statusbar.notification.row.NotificationGutsManager;
import com.android.systemui.statusbar.notification.row.OnUserInteractionCallback;
import com.android.systemui.statusbar.notification.row.RowContentBindStage;
import com.android.systemui.statusbar.notification.row.RowContentBindStageLogger;
import com.android.systemui.statusbar.notification.row.RowContentBindStageLogger_Factory;
import com.android.systemui.statusbar.notification.row.RowContentBindStage_Factory;
import com.android.systemui.statusbar.notification.row.RowInflaterTask_Factory;
import com.android.systemui.statusbar.notification.row.dagger.ExpandableNotificationRowComponent;
import com.android.systemui.statusbar.notification.row.dagger.ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideAppNameFactory;
import com.android.systemui.statusbar.notification.row.dagger.ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideNotificationKeyFactory;
import com.android.systemui.statusbar.notification.row.dagger.ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideStatusBarNotificationFactory;
import com.android.systemui.statusbar.notification.row.dagger.NotificationShelfComponent;
import com.android.systemui.statusbar.notification.stack.AmbientState;
import com.android.systemui.statusbar.notification.stack.AmbientState_Factory;
import com.android.systemui.statusbar.notification.stack.ForegroundServiceSectionController;
import com.android.systemui.statusbar.notification.stack.ForegroundServiceSectionController_Factory;
import com.android.systemui.statusbar.notification.stack.NotificationListContainer;
import com.android.systemui.statusbar.notification.stack.NotificationRoundnessManager;
import com.android.systemui.statusbar.notification.stack.NotificationRoundnessManager_Factory;
import com.android.systemui.statusbar.notification.stack.NotificationSectionsLogger;
import com.android.systemui.statusbar.notification.stack.NotificationSectionsLogger_Factory;
import com.android.systemui.statusbar.notification.stack.NotificationSectionsManager;
import com.android.systemui.statusbar.notification.stack.NotificationSectionsManager_Factory;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayout;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController;
import com.android.systemui.statusbar.notification.stack.NotificationStackScrollLayoutController_Factory;
import com.android.systemui.statusbar.notification.stack.NotificationSwipeHelper_Builder_Factory;
import com.android.systemui.statusbar.phone.AutoHideController;
import com.android.systemui.statusbar.phone.AutoHideController_Factory_Factory;
import com.android.systemui.statusbar.phone.AutoTileManager;
import com.android.systemui.statusbar.phone.BiometricUnlockController;
import com.android.systemui.statusbar.phone.BiometricUnlockController_Factory;
import com.android.systemui.statusbar.phone.DarkIconDispatcherImpl;
import com.android.systemui.statusbar.phone.DarkIconDispatcherImpl_Factory;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.DozeParameters_Factory;
import com.android.systemui.statusbar.phone.DozeScrimController;
import com.android.systemui.statusbar.phone.DozeScrimController_Factory;
import com.android.systemui.statusbar.phone.DozeServiceHost;
import com.android.systemui.statusbar.phone.DozeServiceHost_Factory;
import com.android.systemui.statusbar.phone.HeadsUpAppearanceController;
import com.android.systemui.statusbar.phone.HeadsUpAppearanceController_Factory;
import com.android.systemui.statusbar.phone.HeadsUpManagerPhone;
import com.android.systemui.statusbar.phone.KeyguardBouncer;
import com.android.systemui.statusbar.phone.KeyguardBouncer_Factory_Factory;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.phone.KeyguardBypassController_Factory;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil_Factory;
import com.android.systemui.statusbar.phone.KeyguardEnvironmentImpl;
import com.android.systemui.statusbar.phone.KeyguardEnvironmentImpl_Factory;
import com.android.systemui.statusbar.phone.KeyguardStatusBarView;
import com.android.systemui.statusbar.phone.KeyguardStatusBarViewController;
import com.android.systemui.statusbar.phone.LSShadeTransitionLogger;
import com.android.systemui.statusbar.phone.LSShadeTransitionLogger_Factory;
import com.android.systemui.statusbar.phone.LightBarController;
import com.android.systemui.statusbar.phone.LightBarController_Factory;
import com.android.systemui.statusbar.phone.LightBarController_Factory_Factory;
import com.android.systemui.statusbar.phone.LightsOutNotifController;
import com.android.systemui.statusbar.phone.LightsOutNotifController_Factory;
import com.android.systemui.statusbar.phone.LockscreenGestureLogger;
import com.android.systemui.statusbar.phone.LockscreenGestureLogger_Factory;
import com.android.systemui.statusbar.phone.LockscreenWallpaper;
import com.android.systemui.statusbar.phone.LockscreenWallpaper_Factory;
import com.android.systemui.statusbar.phone.ManagedProfileControllerImpl;
import com.android.systemui.statusbar.phone.ManagedProfileControllerImpl_Factory;
import com.android.systemui.statusbar.phone.MultiUserSwitchController;
import com.android.systemui.statusbar.phone.MultiUserSwitchController_Factory_Factory;
import com.android.systemui.statusbar.phone.NotificationGroupAlertTransferHelper;
import com.android.systemui.statusbar.phone.NotificationIconAreaController;
import com.android.systemui.statusbar.phone.NotificationIconAreaController_Factory;
import com.android.systemui.statusbar.phone.NotificationPanelView;
import com.android.systemui.statusbar.phone.NotificationPanelViewController;
import com.android.systemui.statusbar.phone.NotificationPanelViewController_Factory;
import com.android.systemui.statusbar.phone.NotificationShadeWindowControllerImpl;
import com.android.systemui.statusbar.phone.NotificationShadeWindowControllerImpl_Factory;
import com.android.systemui.statusbar.phone.NotificationShadeWindowView;
import com.android.systemui.statusbar.phone.NotificationShadeWindowViewController;
import com.android.systemui.statusbar.phone.NotificationShadeWindowViewController_Factory;
import com.android.systemui.statusbar.phone.NotificationTapHelper;
import com.android.systemui.statusbar.phone.NotificationTapHelper_Factory_Factory;
import com.android.systemui.statusbar.phone.NotificationsQSContainerController;
import com.android.systemui.statusbar.phone.NotificationsQSContainerController_Factory;
import com.android.systemui.statusbar.phone.NotificationsQuickSettingsContainer;
import com.android.systemui.statusbar.phone.PhoneStatusBarPolicy;
import com.android.systemui.statusbar.phone.PhoneStatusBarPolicy_Factory;
import com.android.systemui.statusbar.phone.PhoneStatusBarView;
import com.android.systemui.statusbar.phone.PhoneStatusBarViewController;
import com.android.systemui.statusbar.phone.PhoneStatusBarViewController_Factory_Factory;
import com.android.systemui.statusbar.phone.ScrimController;
import com.android.systemui.statusbar.phone.ScrimController_Factory;
import com.android.systemui.statusbar.phone.ShadeControllerImpl;
import com.android.systemui.statusbar.phone.ShadeControllerImpl_Factory;
import com.android.systemui.statusbar.phone.SplitShadeHeaderController;
import com.android.systemui.statusbar.phone.SplitShadeHeaderController_Factory;
import com.android.systemui.statusbar.phone.StatusBar;
import com.android.systemui.statusbar.phone.StatusBarCommandQueueCallbacks;
import com.android.systemui.statusbar.phone.StatusBarCommandQueueCallbacks_Factory;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider;
import com.android.systemui.statusbar.phone.StatusBarContentInsetsProvider_Factory;
import com.android.systemui.statusbar.phone.StatusBarDemoMode;
import com.android.systemui.statusbar.phone.StatusBarDemoMode_Factory;
import com.android.systemui.statusbar.phone.StatusBarHeadsUpChangeListener;
import com.android.systemui.statusbar.phone.StatusBarHeadsUpChangeListener_Factory;
import com.android.systemui.statusbar.phone.StatusBarHideIconsForBouncerManager;
import com.android.systemui.statusbar.phone.StatusBarHideIconsForBouncerManager_Factory;
import com.android.systemui.statusbar.phone.StatusBarIconController;
import com.android.systemui.statusbar.phone.StatusBarIconControllerImpl;
import com.android.systemui.statusbar.phone.StatusBarIconControllerImpl_Factory;
import com.android.systemui.statusbar.phone.StatusBarIconController_TintedIconManager_Factory_Factory;
import com.android.systemui.statusbar.phone.StatusBarKeyguardViewManager;
import com.android.systemui.statusbar.phone.StatusBarKeyguardViewManager_Factory;
import com.android.systemui.statusbar.phone.StatusBarLocationPublisher;
import com.android.systemui.statusbar.phone.StatusBarLocationPublisher_Factory;
import com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController;
import com.android.systemui.statusbar.phone.StatusBarMoveFromCenterAnimationController_Factory;
import com.android.systemui.statusbar.phone.StatusBarNotificationActivityStarter;
import com.android.systemui.statusbar.phone.StatusBarNotificationActivityStarterLogger;
import com.android.systemui.statusbar.phone.StatusBarNotificationActivityStarterLogger_Factory;
import com.android.systemui.statusbar.phone.StatusBarNotificationActivityStarter_Builder_Factory;
import com.android.systemui.statusbar.phone.StatusBarRemoteInputCallback;
import com.android.systemui.statusbar.phone.StatusBarRemoteInputCallback_Factory;
import com.android.systemui.statusbar.phone.StatusBarSignalPolicy;
import com.android.systemui.statusbar.phone.StatusBarSignalPolicy_Factory;
import com.android.systemui.statusbar.phone.StatusBarTouchableRegionManager;
import com.android.systemui.statusbar.phone.StatusBarTouchableRegionManager_Factory;
import com.android.systemui.statusbar.phone.StatusIconContainer;
import com.android.systemui.statusbar.phone.SystemUIDialogManager;
import com.android.systemui.statusbar.phone.SystemUIDialogManager_Factory;
import com.android.systemui.statusbar.phone.TapAgainView;
import com.android.systemui.statusbar.phone.TapAgainViewController;
import com.android.systemui.statusbar.phone.TapAgainViewController_Factory;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController;
import com.android.systemui.statusbar.phone.UnlockedScreenOffAnimationController_Factory;
import com.android.systemui.statusbar.phone.dagger.StatusBarComponent;
import com.android.systemui.statusbar.phone.dagger.StatusBarPhoneDependenciesModule_ProvideNotificationGroupAlertTransferHelperFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarPhoneModule_ProvideStatusBarFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetAuthRippleViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetBatteryMeterViewControllerFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetBatteryMeterViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetLockIconViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetNotificationPanelViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetNotificationsQuickSettingsContainerFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetSplitShadeOngoingPrivacyChipFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetSplitShadeStatusBarViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_GetTapAgainViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_ProvidesNotificationShadeWindowViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_ProvidesNotificationShelfFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_ProvidesNotificationStackScrollLayoutFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_ProvidesStatusBarWindowViewFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_ProvidesStatusIconContainerFactory;
import com.android.systemui.statusbar.phone.dagger.StatusBarViewModule_ProvidesVisualizerViewFactory;
import com.android.systemui.statusbar.phone.fragment.CollapsedStatusBarFragment;
import com.android.systemui.statusbar.phone.fragment.CollapsedStatusBarFragmentLogger;
import com.android.systemui.statusbar.phone.fragment.CollapsedStatusBarFragmentLogger_Factory;
import com.android.systemui.statusbar.phone.fragment.dagger.StatusBarFragmentComponent;
import com.android.systemui.statusbar.phone.fragment.dagger.StatusBarFragmentModule_ProvideBatteryMeterViewFactory;
import com.android.systemui.statusbar.phone.fragment.dagger.StatusBarFragmentModule_ProvidePhoneStatusBarViewControllerFactory;
import com.android.systemui.statusbar.phone.fragment.dagger.StatusBarFragmentModule_ProvidePhoneStatusBarViewFactory;
import com.android.systemui.statusbar.phone.ongoingcall.OngoingCallController;
import com.android.systemui.statusbar.phone.ongoingcall.OngoingCallLogger;
import com.android.systemui.statusbar.phone.ongoingcall.OngoingCallLogger_Factory;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager;
import com.android.systemui.statusbar.phone.panelstate.PanelExpansionStateManager_Factory;
import com.android.systemui.statusbar.policy.AccessibilityController;
import com.android.systemui.statusbar.policy.AccessibilityController_Factory;
import com.android.systemui.statusbar.policy.AccessibilityManagerWrapper;
import com.android.systemui.statusbar.policy.AccessibilityManagerWrapper_Factory;
import com.android.systemui.statusbar.policy.BatteryController;
import com.android.systemui.statusbar.policy.BatteryStateNotifier;
import com.android.systemui.statusbar.policy.BatteryStateNotifier_Factory;
import com.android.systemui.statusbar.policy.BluetoothControllerImpl;
import com.android.systemui.statusbar.policy.BluetoothControllerImpl_Factory;
import com.android.systemui.statusbar.policy.CastControllerImpl;
import com.android.systemui.statusbar.policy.CastControllerImpl_Factory;
import com.android.systemui.statusbar.policy.ConfigurationController;
import com.android.systemui.statusbar.policy.DataSaverController;
import com.android.systemui.statusbar.policy.DeviceControlsControllerImpl;
import com.android.systemui.statusbar.policy.DeviceControlsControllerImpl_Factory;
import com.android.systemui.statusbar.policy.DevicePostureControllerImpl;
import com.android.systemui.statusbar.policy.DevicePostureControllerImpl_Factory;
import com.android.systemui.statusbar.policy.DeviceProvisionedController;
import com.android.systemui.statusbar.policy.DeviceProvisionedControllerImpl;
import com.android.systemui.statusbar.policy.DeviceProvisionedControllerImpl_Factory;
import com.android.systemui.statusbar.policy.DeviceStateRotationLockSettingController;
import com.android.systemui.statusbar.policy.DeviceStateRotationLockSettingController_Factory;
import com.android.systemui.statusbar.policy.ExtensionControllerImpl;
import com.android.systemui.statusbar.policy.ExtensionControllerImpl_Factory;
import com.android.systemui.statusbar.policy.FlashlightControllerImpl;
import com.android.systemui.statusbar.policy.FlashlightControllerImpl_Factory;
import com.android.systemui.statusbar.policy.HotspotControllerImpl;
import com.android.systemui.statusbar.policy.HotspotControllerImpl_Factory;
import com.android.systemui.statusbar.policy.IndividualSensorPrivacyController;
import com.android.systemui.statusbar.policy.KeyguardQsUserSwitchController;
import com.android.systemui.statusbar.policy.KeyguardQsUserSwitchController_Factory;
import com.android.systemui.statusbar.policy.KeyguardStateControllerImpl;
import com.android.systemui.statusbar.policy.KeyguardStateControllerImpl_Factory;
import com.android.systemui.statusbar.policy.KeyguardUserSwitcherController;
import com.android.systemui.statusbar.policy.KeyguardUserSwitcherController_Factory;
import com.android.systemui.statusbar.policy.KeyguardUserSwitcherView;
import com.android.systemui.statusbar.policy.LocationControllerImpl;
import com.android.systemui.statusbar.policy.LocationControllerImpl_Factory;
import com.android.systemui.statusbar.policy.NextAlarmControllerImpl;
import com.android.systemui.statusbar.policy.NextAlarmControllerImpl_Factory;
import com.android.systemui.statusbar.policy.RemoteInputQuickSettingsDisabler;
import com.android.systemui.statusbar.policy.RemoteInputQuickSettingsDisabler_Factory;
import com.android.systemui.statusbar.policy.RemoteInputUriController;
import com.android.systemui.statusbar.policy.RemoteInputUriController_Factory;
import com.android.systemui.statusbar.policy.RotationLockControllerImpl;
import com.android.systemui.statusbar.policy.RotationLockControllerImpl_Factory;
import com.android.systemui.statusbar.policy.SecurityControllerImpl;
import com.android.systemui.statusbar.policy.SecurityControllerImpl_Factory;
import com.android.systemui.statusbar.policy.SensorPrivacyController;
import com.android.systemui.statusbar.policy.SmartActionInflaterImpl;
import com.android.systemui.statusbar.policy.SmartActionInflaterImpl_Factory;
import com.android.systemui.statusbar.policy.SmartReplyConstants;
import com.android.systemui.statusbar.policy.SmartReplyConstants_Factory;
import com.android.systemui.statusbar.policy.SmartReplyInflaterImpl;
import com.android.systemui.statusbar.policy.SmartReplyInflaterImpl_Factory;
import com.android.systemui.statusbar.policy.SmartReplyStateInflaterImpl;
import com.android.systemui.statusbar.policy.SmartReplyStateInflaterImpl_Factory;
import com.android.systemui.statusbar.policy.UserInfoControllerImpl;
import com.android.systemui.statusbar.policy.UserInfoControllerImpl_Factory;
import com.android.systemui.statusbar.policy.UserSwitcherController;
import com.android.systemui.statusbar.policy.UserSwitcherController_Factory;
import com.android.systemui.statusbar.policy.UserSwitcherController_UserDetailAdapter_Factory;
import com.android.systemui.statusbar.policy.VariableDateViewController;
import com.android.systemui.statusbar.policy.VariableDateViewController_Factory_Factory;
import com.android.systemui.statusbar.policy.WalletControllerImpl;
import com.android.systemui.statusbar.policy.WalletControllerImpl_Factory;
import com.android.systemui.statusbar.policy.ZenModeControllerImpl;
import com.android.systemui.statusbar.policy.ZenModeControllerImpl_Factory;
import com.android.systemui.statusbar.policy.dagger.StatusBarPolicyModule_ProvideAccessPointControllerImplFactory;
import com.android.systemui.statusbar.policy.dagger.StatusBarPolicyModule_ProvidesDeviceStateRotationLockDefaultsFactory;
import com.android.systemui.statusbar.tv.TvStatusBar;
import com.android.systemui.statusbar.tv.TvStatusBar_Factory;
import com.android.systemui.statusbar.tv.notifications.TvNotificationHandler;
import com.android.systemui.statusbar.tv.notifications.TvNotificationHandler_Factory;
import com.android.systemui.statusbar.tv.notifications.TvNotificationPanel;
import com.android.systemui.statusbar.tv.notifications.TvNotificationPanelActivity;
import com.android.systemui.statusbar.tv.notifications.TvNotificationPanelActivity_Factory;
import com.android.systemui.statusbar.tv.notifications.TvNotificationPanel_Factory;
import com.android.systemui.statusbar.window.StatusBarWindowController;
import com.android.systemui.statusbar.window.StatusBarWindowController_Factory;
import com.android.systemui.statusbar.window.StatusBarWindowModule_ProvidesStatusBarWindowViewFactory;
import com.android.systemui.statusbar.window.StatusBarWindowView;
import com.android.systemui.telephony.TelephonyCallback_Factory;
import com.android.systemui.telephony.TelephonyListenerManager;
import com.android.systemui.telephony.TelephonyListenerManager_Factory;
import com.android.systemui.theme.ThemeOverlayApplier;
import com.android.systemui.theme.ThemeOverlayController;
import com.android.systemui.theme.ThemeOverlayController_Factory;
import com.android.systemui.toast.ToastFactory;
import com.android.systemui.toast.ToastFactory_Factory;
import com.android.systemui.toast.ToastLogger;
import com.android.systemui.toast.ToastLogger_Factory;
import com.android.systemui.toast.ToastUI;
import com.android.systemui.toast.ToastUI_Factory;
import com.android.systemui.tracing.ProtoTracer;
import com.android.systemui.tracing.ProtoTracer_Factory;
import com.android.systemui.tuner.TunablePadding;
import com.android.systemui.tuner.TunablePadding_TunablePaddingService_Factory;
import com.android.systemui.tuner.TunerActivity;
import com.android.systemui.tuner.TunerActivity_Factory;
import com.android.systemui.tuner.TunerServiceImpl;
import com.android.systemui.tuner.TunerServiceImpl_Factory;
import com.android.systemui.unfold.SysUIUnfoldComponent;
import com.android.systemui.unfold.SysUIUnfoldModule;
import com.android.systemui.unfold.SysUIUnfoldModule_ProvideSysUIUnfoldComponentFactory;
import com.android.systemui.unfold.UnfoldLightRevealOverlayAnimation;
import com.android.systemui.unfold.UnfoldLightRevealOverlayAnimation_Factory;
import com.android.systemui.unfold.UnfoldTransitionModule;
import com.android.systemui.unfold.UnfoldTransitionModule_ProvideNaturalRotationProgressProviderFactory;
import com.android.systemui.unfold.UnfoldTransitionModule_ProvideShellProgressProviderFactory;
import com.android.systemui.unfold.UnfoldTransitionModule_ProvideStatusBarScopedTransitionProviderFactory;
import com.android.systemui.unfold.UnfoldTransitionModule_ProvideUnfoldTransitionConfigFactory;
import com.android.systemui.unfold.UnfoldTransitionModule_ProvideUnfoldTransitionProgressProviderFactory;
import com.android.systemui.unfold.UnfoldTransitionProgressProvider;
import com.android.systemui.unfold.UnfoldTransitionWallpaperController;
import com.android.systemui.unfold.UnfoldTransitionWallpaperController_Factory;
import com.android.systemui.unfold.config.UnfoldTransitionConfig;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
import com.android.systemui.unfold.util.ScopedUnfoldTransitionProgressProvider;
import com.android.systemui.usb.UsbDebuggingActivity;
import com.android.systemui.usb.UsbDebuggingActivity_Factory;
import com.android.systemui.usb.UsbDebuggingSecondaryUserActivity;
import com.android.systemui.usb.UsbDebuggingSecondaryUserActivity_Factory;
import com.android.systemui.user.CreateUserActivity;
import com.android.systemui.user.CreateUserActivity_Factory;
import com.android.systemui.user.UserCreator;
import com.android.systemui.user.UserCreator_Factory;
import com.android.systemui.user.UserModule;
import com.android.systemui.user.UserModule_ProvideEditUserInfoControllerFactory;
import com.android.systemui.util.CarrierConfigTracker;
import com.android.systemui.util.CarrierConfigTracker_Factory;
import com.android.systemui.util.DeviceConfigProxy;
import com.android.systemui.util.DeviceConfigProxy_Factory;
import com.android.systemui.util.RingerModeTrackerImpl;
import com.android.systemui.util.RingerModeTrackerImpl_Factory;
import com.android.systemui.util.WallpaperController;
import com.android.systemui.util.WallpaperController_Factory;
import com.android.systemui.util.concurrency.DelayableExecutor;
import com.android.systemui.util.concurrency.Execution;
import com.android.systemui.util.concurrency.ExecutionImpl_Factory;
import com.android.systemui.util.concurrency.GlobalConcurrencyModule_ProvideMainDelayableExecutorFactory;
import com.android.systemui.util.concurrency.GlobalConcurrencyModule_ProvideMainExecutorFactory;
import com.android.systemui.util.concurrency.GlobalConcurrencyModule_ProvideMainHandlerFactory;
import com.android.systemui.util.concurrency.GlobalConcurrencyModule_ProvideMainLooperFactory;
import com.android.systemui.util.concurrency.GlobalConcurrencyModule_ProvidesUncaughtExceptionHandlerFactory;
import com.android.systemui.util.concurrency.MessageRouter;
import com.android.systemui.util.concurrency.RepeatableExecutor;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideBackgroundDelayableExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideBackgroundExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideBackgroundRepeatableExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideBgHandlerFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideBgLooperFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideDelayableExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideLongRunningExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideLongRunningLooperFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvideUiBackgroundExecutorFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvidesBackgroundMessageRouterFactory;
import com.android.systemui.util.concurrency.SysUIConcurrencyModule_ProvidesMainMessageRouterFactory;
import com.android.systemui.util.concurrency.ThreadFactoryImpl_Factory;
import com.android.systemui.util.io.Files;
import com.android.systemui.util.io.Files_Factory;
import com.android.systemui.util.leak.GarbageMonitor;
import com.android.systemui.util.leak.GarbageMonitor_Factory;
import com.android.systemui.util.leak.GarbageMonitor_MemoryTile_Factory;
import com.android.systemui.util.leak.GarbageMonitor_Service_Factory;
import com.android.systemui.util.leak.LeakDetector;
import com.android.systemui.util.leak.LeakReporter;
import com.android.systemui.util.leak.LeakReporter_Factory;
import com.android.systemui.util.sensors.AsyncSensorManager;
import com.android.systemui.util.sensors.AsyncSensorManager_Factory;
import com.android.systemui.util.sensors.PostureDependentProximitySensor_Factory;
import com.android.systemui.util.sensors.ProximityCheck;
import com.android.systemui.util.sensors.ProximitySensor;
import com.android.systemui.util.sensors.ProximitySensorImpl_Factory;
import com.android.systemui.util.sensors.SensorModule_ProvidePostureToProximitySensorMappingFactory;
import com.android.systemui.util.sensors.SensorModule_ProvidePostureToSecondaryProximitySensorMappingFactory;
import com.android.systemui.util.sensors.SensorModule_ProvidePrimaryProximitySensorFactory;
import com.android.systemui.util.sensors.SensorModule_ProvideProximityCheckFactory;
import com.android.systemui.util.sensors.SensorModule_ProvideProximitySensorFactory;
import com.android.systemui.util.sensors.SensorModule_ProvideSecondaryProximitySensorFactory;
import com.android.systemui.util.sensors.ThresholdSensor;
import com.android.systemui.util.sensors.ThresholdSensorImpl;
import com.android.systemui.util.sensors.ThresholdSensorImpl_BuilderFactory_Factory;
import com.android.systemui.util.sensors.ThresholdSensorImpl_Builder_Factory;
import com.android.systemui.util.settings.GlobalSettingsImpl_Factory;
import com.android.systemui.util.settings.SecureSettings;
import com.android.systemui.util.settings.SecureSettingsImpl_Factory;
import com.android.systemui.util.settings.SystemSettingsImpl_Factory;
import com.android.systemui.util.time.DateFormatUtil;
import com.android.systemui.util.time.DateFormatUtil_Factory;
import com.android.systemui.util.time.SystemClock;
import com.android.systemui.util.time.SystemClockImpl_Factory;
import com.android.systemui.util.wakelock.DelayedWakeLock;
import com.android.systemui.util.wakelock.DelayedWakeLock_Builder_Factory;
import com.android.systemui.util.wakelock.WakeLock;
import com.android.systemui.util.wakelock.WakeLock_Builder_Factory;
import com.android.systemui.util.wrapper.RotationPolicyWrapper;
import com.android.systemui.util.wrapper.RotationPolicyWrapperImpl;
import com.android.systemui.util.wrapper.RotationPolicyWrapperImpl_Factory;
import com.android.systemui.volume.VolumeDialogComponent;
import com.android.systemui.volume.VolumeDialogComponent_Factory;
import com.android.systemui.volume.VolumeDialogControllerImpl;
import com.android.systemui.volume.VolumeDialogControllerImpl_Factory;
import com.android.systemui.volume.VolumeUI;
import com.android.systemui.volume.VolumeUI_Factory;
import com.android.systemui.volume.dagger.VolumeModule_ProvideVolumeDialogFactory;
import com.android.systemui.wallet.controller.QuickAccessWalletController;
import com.android.systemui.wallet.controller.QuickAccessWalletController_Factory;
import com.android.systemui.wallet.dagger.WalletModule_ProvideQuickAccessWalletClientFactory;
import com.android.systemui.wallet.ui.WalletActivity;
import com.android.systemui.wallet.ui.WalletActivity_Factory;
import com.android.systemui.wmshell.BubblesManager;
import com.android.systemui.wmshell.WMShell;
import com.android.systemui.wmshell.WMShell_Factory;
import com.android.wm.shell.RootDisplayAreaOrganizer;
import com.android.wm.shell.RootTaskDisplayAreaOrganizer;
import com.android.wm.shell.ShellCommandHandler;
import com.android.wm.shell.ShellCommandHandlerImpl;
import com.android.wm.shell.ShellInit;
import com.android.wm.shell.ShellInitImpl;
import com.android.wm.shell.ShellTaskOrganizer;
import com.android.wm.shell.TaskViewFactory;
import com.android.wm.shell.TaskViewFactoryController;
import com.android.wm.shell.WindowManagerShellWrapper;
import com.android.wm.shell.animation.FlingAnimationUtils;
import com.android.wm.shell.animation.FlingAnimationUtils_Builder_Factory;
import com.android.wm.shell.apppairs.AppPairs;
import com.android.wm.shell.apppairs.AppPairsController;
import com.android.wm.shell.bubbles.BubbleController;
import com.android.wm.shell.bubbles.Bubbles;
import com.android.wm.shell.common.DisplayController;
import com.android.wm.shell.common.DisplayImeController;
import com.android.wm.shell.common.DisplayInsetsController;
import com.android.wm.shell.common.DisplayLayout;
import com.android.wm.shell.common.FloatingContentCoordinator;
import com.android.wm.shell.common.ShellExecutor;
import com.android.wm.shell.common.SyncTransactionQueue;
import com.android.wm.shell.common.SystemWindows;
import com.android.wm.shell.common.TaskStackListenerImpl;
import com.android.wm.shell.common.TransactionPool;
import com.android.wm.shell.compatui.CompatUI;
import com.android.wm.shell.compatui.CompatUIController;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideAppPairsFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideBubblesFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideCompatUIControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideCompatUIFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDisplayAreaHelperFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDisplayControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDisplayImeControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDisplayInsetsControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDisplayLayoutFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDragAndDropControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideDragAndDropFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideFloatingContentCoordinatorFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideFreeformTaskListenerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideFullscreenTaskListenerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideFullscreenUnfoldControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideHideDisplayCutoutControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideHideDisplayCutoutFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideIconProviderFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideLegacySplitScreenFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideOneHandedFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvidePipAppOpsListenerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvidePipMediaControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvidePipSurfaceTransactionHelperFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvidePipUiEventLoggerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideRecentTasksControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideRecentTasksFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideRemoteTransitionsFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideRootDisplayAreaOrganizerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideRootTaskDisplayAreaOrganizerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideShellCommandHandlerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideShellCommandHandlerImplFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideShellInitFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideShellInitImplFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideShellTaskOrganizerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideSplitScreenFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideStartingSurfaceFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideStartingWindowControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideStartingWindowTypeAlgorithmFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideSyncTransactionQueueFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideSystemWindowsFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideTaskSurfaceHelperControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideTaskSurfaceHelperFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideTaskViewFactoryControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideTaskViewFactoryFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideTransactionPoolFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideTransitionsFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvideWindowManagerShellWrapperFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProviderTaskStackListenerImplFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvidesOneHandedControllerFactory;
import com.android.wm.shell.dagger.WMShellBaseModule_ProvidesSplitScreenControllerFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideMainHandlerFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideShellAnimationExecutorFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideShellMainExecutorFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideShellMainExecutorSfVsyncAnimationHandlerFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideShellMainHandlerFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideSplashScreenExecutorFactory;
import com.android.wm.shell.dagger.WMShellConcurrencyModule_ProvideSysUIMainExecutorFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideAppPairsFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideBubbleControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideFreeformTaskListenerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideFullscreenUnfoldControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideLegacySplitScreenFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideOneHandedControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipAnimationControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipBoundsStateFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipMotionHelperFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipSnapAlgorithmFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipTaskOrganizerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipTouchHandlerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipTransitionControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidePipTransitionStateFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideSplitScreenControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideStageTaskUnfoldControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvideUnfoldBackgroundControllerFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidesPipBoundsAlgorithmFactory;
import com.android.wm.shell.dagger.WMShellModule_ProvidesPipPhoneMenuControllerFactory;
import com.android.wm.shell.displayareahelper.DisplayAreaHelper;
import com.android.wm.shell.draganddrop.DragAndDrop;
import com.android.wm.shell.draganddrop.DragAndDropController;
import com.android.wm.shell.freeform.FreeformTaskListener;
import com.android.wm.shell.fullscreen.FullscreenTaskListener;
import com.android.wm.shell.fullscreen.FullscreenUnfoldController;
import com.android.wm.shell.hidedisplaycutout.HideDisplayCutout;
import com.android.wm.shell.hidedisplaycutout.HideDisplayCutoutController;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreenController;
import com.android.wm.shell.onehanded.OneHanded;
import com.android.wm.shell.onehanded.OneHandedController;
import com.android.wm.shell.pip.Pip;
import com.android.wm.shell.pip.PipAnimationController;
import com.android.wm.shell.pip.PipBoundsAlgorithm;
import com.android.wm.shell.pip.PipBoundsState;
import com.android.wm.shell.pip.PipMediaController;
import com.android.wm.shell.pip.PipSnapAlgorithm;
import com.android.wm.shell.pip.PipSurfaceTransactionHelper;
import com.android.wm.shell.pip.PipTaskOrganizer;
import com.android.wm.shell.pip.PipTransitionController;
import com.android.wm.shell.pip.PipTransitionState;
import com.android.wm.shell.pip.PipUiEventLogger;
import com.android.wm.shell.pip.phone.PhonePipMenuController;
import com.android.wm.shell.pip.phone.PipAppOpsListener;
import com.android.wm.shell.pip.phone.PipMotionHelper;
import com.android.wm.shell.pip.phone.PipTouchHandler;
import com.android.wm.shell.recents.RecentTasks;
import com.android.wm.shell.recents.RecentTasksController;
import com.android.wm.shell.splitscreen.SplitScreen;
import com.android.wm.shell.splitscreen.SplitScreenController;
import com.android.wm.shell.splitscreen.StageTaskUnfoldController;
import com.android.wm.shell.startingsurface.StartingSurface;
import com.android.wm.shell.startingsurface.StartingWindowController;
import com.android.wm.shell.startingsurface.StartingWindowTypeAlgorithm;
import com.android.wm.shell.tasksurfacehelper.TaskSurfaceHelper;
import com.android.wm.shell.tasksurfacehelper.TaskSurfaceHelperController;
import com.android.wm.shell.transition.ShellTransitions;
import com.android.wm.shell.transition.Transitions;
import com.android.wm.shell.unfold.ShellUnfoldProgressProvider;
import com.android.wm.shell.unfold.UnfoldBackgroundController;
import dagger.internal.DelegateFactory;
import dagger.internal.DoubleCheck;
import dagger.internal.InstanceFactory;
import dagger.internal.MapProviderFactory;
import dagger.internal.Preconditions;
import dagger.internal.SetFactory;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.Set;
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
public final class DaggerGlobalRootComponent implements GlobalRootComponent {
  /**
   * A {@link Provider} that returns {@code Optional.empty()}.
   */
  @SuppressWarnings("rawtypes")
  private static final Provider ABSENT_JDK_OPTIONAL_PROVIDER = InstanceFactory.create(Optional.empty());

  private final Context context;

  private Provider<Context> contextProvider;

  private Provider<IWindowManager> provideIWindowManagerProvider;

  private Provider<UiEventLogger> provideUiEventLoggerProvider;

  private Provider<IStatusBarService> provideIStatusBarServiceProvider;

  private Provider<WindowManager> provideWindowManagerProvider;

  private Provider<LauncherApps> provideLauncherAppsProvider;

  private Provider<UnfoldTransitionConfig> provideUnfoldTransitionConfigProvider;

  private Provider<DumpManager> dumpManagerProvider;

  private Provider<ScreenLifecycle> screenLifecycleProvider;

  private Provider<LifecycleScreenStatusProvider> lifecycleScreenStatusProvider;

  private Provider<DeviceStateManager> provideDeviceStateManagerProvider;

  private Provider<SensorManager> providesSensorManagerProvider;

  private Provider<Executor> provideMainExecutorProvider;

  private Provider<Handler> provideMainHandlerProvider;

  private Provider<Optional<UnfoldTransitionProgressProvider>> provideUnfoldTransitionProgressProvider;

  private Provider<ShellUnfoldProgressProvider> provideShellProgressProvider;

  private Provider<PackageManager> providePackageManagerProvider;

  private Provider<ContentResolver> provideContentResolverProvider;

  private Provider<UserManager> provideUserManagerProvider;

  private Provider<Executor> providesPluginExecutorProvider;

  private Provider<NotificationManager> provideNotificationManagerProvider;

  private Provider<PluginEnablerImpl> pluginEnablerImplProvider;

  private Provider<List<String>> providesPrivilegedPluginsProvider;

  private Provider<PluginInstance.Factory> providesPluginInstanceFactoryProvider;

  private Provider<PluginActionManager.Factory> providePluginInstanceManagerFactoryProvider;

  private Provider<PluginPrefs> providesPluginPrefsProvider;

  private Provider<PluginManager> providesPluginManagerProvider;

  private Provider<DisplayMetrics> provideDisplayMetricsProvider;

  private Provider<PowerManager> providePowerManagerProvider;

  private Provider<ViewConfiguration> provideViewConfigurationProvider;

  private Provider<Resources> provideResourcesProvider;

  private Provider<AudioManager> provideAudioManagerProvider;

  private Provider<Execution> provideExecutionProvider;

  private Provider<ActivityTaskManager> provideActivityTaskManagerProvider;

  private Provider<FingerprintManager> providesFingerprintManagerProvider;

  private Provider<FaceManager> provideFaceManagerProvider;

  private Provider<DelayableExecutor> provideMainDelayableExecutorProvider;

  private Provider<TrustManager> provideTrustManagerProvider;

  private Provider<IActivityManager> provideIActivityManagerProvider;

  private Provider<DevicePolicyManager> provideDevicePolicyManagerProvider;

  private Provider<KeyguardManager> provideKeyguardManagerProvider;

  private Provider<PackageManagerWrapper> providePackageManagerWrapperProvider;

  private Provider<MediaSessionManager> provideMediaSessionManagerProvider;

  private Provider<MediaRouter2Manager> provideMediaRouter2ManagerProvider;

  private Provider<WallpaperManager> provideWallpaperManagerProvider;

  private Provider<SensorPrivacyManager> provideSensorPrivacyManagerProvider;

  private Provider<IDreamManager> provideIDreamManagerProvider;

  private Provider<SubscriptionManager> provideSubcriptionManagerProvider;

  private Provider<ConnectivityManager> provideConnectivityManagagerProvider;

  private Provider<TelephonyManager> provideTelephonyManagerProvider;

  private Provider<WifiManager> provideWifiManagerProvider;

  private Provider<NetworkScoreManager> provideNetworkScoreManagerProvider;

  private Provider<AccessibilityManager> provideAccessibilityManagerProvider;

  private Provider<TaskbarDelegate> taskbarDelegateProvider;

  private Provider<CrossWindowBlurListeners> provideCrossWindowBlurListenersProvider;

  private Provider<AlarmManager> provideAlarmManagerProvider;

  private Provider<Optional<TelecomManager>> provideOptionalTelecomManagerProvider;

  private Provider<InputMethodManager> provideInputMethodManagerProvider;

  private Provider<ShortcutManager> provideShortcutManagerProvider;

  private Provider<Optional<Vibrator>> provideOptionalVibratorProvider;

  private Provider<IAudioService> provideIAudioServiceProvider;

  private Provider<PluginDependencyProvider> pluginDependencyProvider;

  private Provider<TelecomManager> provideTelecomManagerProvider;

  private Provider<Integer> provideDisplayIdProvider;

  private Provider<IBatteryStats> provideIBatteryStatsProvider;

  private Provider<IActivityTaskManager> provideIActivityTaskManagerProvider;

  private Provider<InteractionJankMonitor> provideInteractionJankMonitorProvider;

  private Provider<LatencyTracker> provideLatencyTrackerProvider;

  private Provider<Optional<NaturalRotationUnfoldProgressProvider>> provideNaturalRotationProgressProvider;

  private Provider<Optional<ScopedUnfoldTransitionProgressProvider>> provideStatusBarScopedTransitionProvider;

  private Provider<Vibrator> provideVibratorProvider;

  private Provider<DisplayManager> provideDisplayManagerProvider;

  private Provider<ActivityManager> provideActivityManagerProvider;

  private Provider<OverlayManager> provideOverlayManagerProvider;

  private Provider<ColorDisplayManager> provideColorDisplayManagerProvider;

  private Provider<IPackageManager> provideIPackageManagerProvider;

  private Provider<SmartspaceManager> provideSmartspaceManagerProvider;

  private Provider<PermissionManager> providePermissionManagerProvider;

  private Provider<QSExpansionPathInterpolator> qSExpansionPathInterpolatorProvider;

  private DaggerGlobalRootComponent(GlobalModule globalModuleParam,
      UnfoldTransitionModule unfoldTransitionModuleParam, Context contextParam) {
    this.context = contextParam;
    initialize(globalModuleParam, unfoldTransitionModuleParam, contextParam);
  }

  public static GlobalRootComponent.Builder builder() {
    return new Builder();
  }

  private Handler mainHandler() {
    return GlobalConcurrencyModule_ProvideMainHandlerFactory.provideMainHandler(GlobalConcurrencyModule_ProvideMainLooperFactory.provideMainLooper());
  }

  private Resources mainResources() {
    return FrameworkServicesModule_ProvideResourcesFactory.provideResources(context);
  }

  @SuppressWarnings("unchecked")
  private void initialize(final GlobalModule globalModuleParam,
      final UnfoldTransitionModule unfoldTransitionModuleParam, final Context contextParam) {
    this.contextProvider = InstanceFactory.create(contextParam);
    this.provideIWindowManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIWindowManagerFactory.create());
    this.provideUiEventLoggerProvider = DoubleCheck.provider(GlobalModule_ProvideUiEventLoggerFactory.create());
    this.provideIStatusBarServiceProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIStatusBarServiceFactory.create());
    this.provideWindowManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideWindowManagerFactory.create(contextProvider));
    this.provideLauncherAppsProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideLauncherAppsFactory.create(contextProvider));
    this.provideUnfoldTransitionConfigProvider = DoubleCheck.provider(UnfoldTransitionModule_ProvideUnfoldTransitionConfigFactory.create(unfoldTransitionModuleParam, contextProvider));
    this.dumpManagerProvider = DoubleCheck.provider(DumpManager_Factory.create());
    this.screenLifecycleProvider = DoubleCheck.provider(ScreenLifecycle_Factory.create(dumpManagerProvider));
    this.lifecycleScreenStatusProvider = DoubleCheck.provider(LifecycleScreenStatusProvider_Factory.create(screenLifecycleProvider));
    this.provideDeviceStateManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideDeviceStateManagerFactory.create(contextProvider));
    this.providesSensorManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvidesSensorManagerFactory.create(contextProvider));
    this.provideMainExecutorProvider = DoubleCheck.provider(GlobalConcurrencyModule_ProvideMainExecutorFactory.create(contextProvider));
    this.provideMainHandlerProvider = GlobalConcurrencyModule_ProvideMainHandlerFactory.create(GlobalConcurrencyModule_ProvideMainLooperFactory.create());
    this.provideUnfoldTransitionProgressProvider = DoubleCheck.provider(UnfoldTransitionModule_ProvideUnfoldTransitionProgressProviderFactory.create(unfoldTransitionModuleParam, contextProvider, provideUnfoldTransitionConfigProvider, lifecycleScreenStatusProvider, provideDeviceStateManagerProvider, providesSensorManagerProvider, provideMainExecutorProvider, provideMainHandlerProvider));
    this.provideShellProgressProvider = DoubleCheck.provider(UnfoldTransitionModule_ProvideShellProgressProviderFactory.create(unfoldTransitionModuleParam, provideUnfoldTransitionConfigProvider, provideUnfoldTransitionProgressProvider));
    this.providePackageManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvidePackageManagerFactory.create(contextProvider));
    this.provideContentResolverProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideContentResolverFactory.create(contextProvider));
    this.provideUserManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideUserManagerFactory.create(contextProvider));
    this.providesPluginExecutorProvider = DoubleCheck.provider(PluginsModule_ProvidesPluginExecutorFactory.create((Provider) ThreadFactoryImpl_Factory.create()));
    this.provideNotificationManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideNotificationManagerFactory.create(contextProvider));
    this.pluginEnablerImplProvider = DoubleCheck.provider(PluginEnablerImpl_Factory.create(contextProvider, providePackageManagerProvider));
    this.providesPrivilegedPluginsProvider = PluginsModule_ProvidesPrivilegedPluginsFactory.create(contextProvider);
    this.providesPluginInstanceFactoryProvider = DoubleCheck.provider(PluginsModule_ProvidesPluginInstanceFactoryFactory.create(providesPrivilegedPluginsProvider, PluginsModule_ProvidesPluginDebugFactory.create()));
    this.providePluginInstanceManagerFactoryProvider = DoubleCheck.provider(PluginsModule_ProvidePluginInstanceManagerFactoryFactory.create(contextProvider, providePackageManagerProvider, provideMainExecutorProvider, providesPluginExecutorProvider, provideNotificationManagerProvider, (Provider) pluginEnablerImplProvider, providesPrivilegedPluginsProvider, providesPluginInstanceFactoryProvider));
    this.providesPluginPrefsProvider = PluginsModule_ProvidesPluginPrefsFactory.create(contextProvider);
    this.providesPluginManagerProvider = DoubleCheck.provider(PluginsModule_ProvidesPluginManagerFactory.create(contextProvider, providePluginInstanceManagerFactoryProvider, PluginsModule_ProvidesPluginDebugFactory.create(), GlobalConcurrencyModule_ProvidesUncaughtExceptionHandlerFactory.create(), (Provider) pluginEnablerImplProvider, providesPluginPrefsProvider, providesPrivilegedPluginsProvider));
    this.provideDisplayMetricsProvider = GlobalModule_ProvideDisplayMetricsFactory.create(globalModuleParam, contextProvider);
    this.providePowerManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvidePowerManagerFactory.create(contextProvider));
    this.provideViewConfigurationProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideViewConfigurationFactory.create(contextProvider));
    this.provideResourcesProvider = FrameworkServicesModule_ProvideResourcesFactory.create(contextProvider);
    this.provideAudioManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideAudioManagerFactory.create(contextProvider));
    this.provideExecutionProvider = DoubleCheck.provider((Provider) ExecutionImpl_Factory.create());
    this.provideActivityTaskManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideActivityTaskManagerFactory.create());
    this.providesFingerprintManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvidesFingerprintManagerFactory.create(contextProvider));
    this.provideFaceManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideFaceManagerFactory.create(contextProvider));
    this.provideMainDelayableExecutorProvider = DoubleCheck.provider(GlobalConcurrencyModule_ProvideMainDelayableExecutorFactory.create(GlobalConcurrencyModule_ProvideMainLooperFactory.create()));
    this.provideTrustManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideTrustManagerFactory.create(contextProvider));
    this.provideIActivityManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIActivityManagerFactory.create());
    this.provideDevicePolicyManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideDevicePolicyManagerFactory.create(contextProvider));
    this.provideKeyguardManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideKeyguardManagerFactory.create(contextProvider));
    this.providePackageManagerWrapperProvider = DoubleCheck.provider(FrameworkServicesModule_ProvidePackageManagerWrapperFactory.create());
    this.provideMediaSessionManagerProvider = FrameworkServicesModule_ProvideMediaSessionManagerFactory.create(contextProvider);
    this.provideMediaRouter2ManagerProvider = FrameworkServicesModule_ProvideMediaRouter2ManagerFactory.create(contextProvider);
    this.provideWallpaperManagerProvider = FrameworkServicesModule_ProvideWallpaperManagerFactory.create(contextProvider);
    this.provideSensorPrivacyManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideSensorPrivacyManagerFactory.create(contextProvider));
    this.provideIDreamManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIDreamManagerFactory.create());
    this.provideSubcriptionManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideSubcriptionManagerFactory.create(contextProvider));
    this.provideConnectivityManagagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideConnectivityManagagerFactory.create(contextProvider));
    this.provideTelephonyManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideTelephonyManagerFactory.create(contextProvider));
    this.provideWifiManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideWifiManagerFactory.create(contextProvider));
    this.provideNetworkScoreManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideNetworkScoreManagerFactory.create(contextProvider));
    this.provideAccessibilityManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideAccessibilityManagerFactory.create(contextProvider));
    this.taskbarDelegateProvider = DoubleCheck.provider(TaskbarDelegate_Factory.create(contextProvider));
    this.provideCrossWindowBlurListenersProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideCrossWindowBlurListenersFactory.create());
    this.provideAlarmManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideAlarmManagerFactory.create(contextProvider));
    this.provideOptionalTelecomManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideOptionalTelecomManagerFactory.create(contextProvider));
    this.provideInputMethodManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideInputMethodManagerFactory.create(contextProvider));
    this.provideShortcutManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideShortcutManagerFactory.create(contextProvider));
    this.provideOptionalVibratorProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideOptionalVibratorFactory.create(contextProvider));
    this.provideIAudioServiceProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIAudioServiceFactory.create());
    this.pluginDependencyProvider = DoubleCheck.provider(PluginDependencyProvider_Factory.create(providesPluginManagerProvider));
    this.provideTelecomManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideTelecomManagerFactory.create(contextProvider));
    this.provideDisplayIdProvider = FrameworkServicesModule_ProvideDisplayIdFactory.create(contextProvider);
    this.provideIBatteryStatsProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIBatteryStatsFactory.create());
    this.provideIActivityTaskManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIActivityTaskManagerFactory.create());
    this.provideInteractionJankMonitorProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideInteractionJankMonitorFactory.create());
    this.provideLatencyTrackerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideLatencyTrackerFactory.create(contextProvider));
    this.provideNaturalRotationProgressProvider = DoubleCheck.provider(UnfoldTransitionModule_ProvideNaturalRotationProgressProviderFactory.create(unfoldTransitionModuleParam, contextProvider, provideIWindowManagerProvider, provideUnfoldTransitionProgressProvider));
    this.provideStatusBarScopedTransitionProvider = DoubleCheck.provider(UnfoldTransitionModule_ProvideStatusBarScopedTransitionProviderFactory.create(unfoldTransitionModuleParam, provideNaturalRotationProgressProvider));
    this.provideVibratorProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideVibratorFactory.create(contextProvider));
    this.provideDisplayManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideDisplayManagerFactory.create(contextProvider));
    this.provideActivityManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideActivityManagerFactory.create(contextProvider));
    this.provideOverlayManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideOverlayManagerFactory.create(contextProvider));
    this.provideColorDisplayManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideColorDisplayManagerFactory.create(contextProvider));
    this.provideIPackageManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideIPackageManagerFactory.create());
    this.provideSmartspaceManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvideSmartspaceManagerFactory.create(contextProvider));
    this.providePermissionManagerProvider = DoubleCheck.provider(FrameworkServicesModule_ProvidePermissionManagerFactory.create(contextProvider));
    this.qSExpansionPathInterpolatorProvider = DoubleCheck.provider(QSExpansionPathInterpolator_Factory.create());
  }

  @Override
  public WMComponent.Builder getWMComponentBuilder() {
    return new WMComponentBuilder();
  }

  @Override
  public SysUIComponent.Builder getSysUIComponent() {
    return new SysUIComponentBuilder();
  }

  /**
   * Returns a {@link Provider} that returns {@code Optional.empty()}.
   */
  private static <T> Provider<Optional<T>> absentJdkOptionalProvider() {
    @SuppressWarnings("unchecked") // safe covariant cast
    Provider<Optional<T>> provider = (Provider<Optional<T>>) ABSENT_JDK_OPTIONAL_PROVIDER;return provider;
  }

  /**
   * A {@code Provider<Optional<T>>} that uses a delegate {@code Provider<T>}.
   */
  private static final class PresentJdkOptionalInstanceProvider<T> implements Provider<Optional<T>> {
    private final Provider<T> delegate;

    private PresentJdkOptionalInstanceProvider(Provider<T> delegate) {
      this.delegate = Preconditions.checkNotNull(delegate);
    }

    @Override
    public Optional<T> get() {
      return Optional.of(delegate.get());
    }

    private static <T> Provider<Optional<T>> of(Provider<T> delegate) {
      return new PresentJdkOptionalInstanceProvider<T>(delegate);
    }
  }

  private static final class Builder implements GlobalRootComponent.Builder {
    private Context context;

    @Override
    public Builder context(Context context) {
      this.context = Preconditions.checkNotNull(context);
      return this;
    }

    @Override
    public GlobalRootComponent build() {
      Preconditions.checkBuilderRequirement(context, Context.class);
      return new DaggerGlobalRootComponent(new GlobalModule(), new UnfoldTransitionModule(), context);
    }
  }

  private final class WMComponentBuilder implements WMComponent.Builder {
    @Override
    public WMComponent build() {
      return new WMComponentImpl();
    }
  }

  private final class WMComponentImpl implements WMComponent {
    private Provider<Handler> provideShellMainHandlerProvider;

    private Provider<ShellExecutor> provideSysUIMainExecutorProvider;

    private Provider<ShellExecutor> provideShellMainExecutorProvider;

    private Provider<DisplayController> provideDisplayControllerProvider;

    private Provider<Optional<DisplayImeController>> dynamicOverrideOptionalOfDisplayImeControllerProvider;

    private Provider<DisplayInsetsController> provideDisplayInsetsControllerProvider;

    private Provider<TransactionPool> provideTransactionPoolProvider;

    private Provider<DisplayImeController> provideDisplayImeControllerProvider;

    private Provider<IconProvider> provideIconProvider;

    private Provider<DragAndDropController> provideDragAndDropControllerProvider;

    private Provider<SyncTransactionQueue> provideSyncTransactionQueueProvider;

    private Provider<CompatUIController> provideCompatUIControllerProvider;

    private Provider<TaskStackListenerImpl> providerTaskStackListenerImplProvider;

    private Provider<Optional<RecentTasksController>> provideRecentTasksControllerProvider;

    private Provider<ShellTaskOrganizer> provideShellTaskOrganizerProvider;

    private Provider<FloatingContentCoordinator> provideFloatingContentCoordinatorProvider;

    private Provider<WindowManagerShellWrapper> provideWindowManagerShellWrapperProvider;

    private Provider<BubbleController> provideBubbleControllerProvider;

    private Provider<Optional<BubbleController>> optionalOfBubbleControllerProvider;

    private Provider<RootTaskDisplayAreaOrganizer> provideRootTaskDisplayAreaOrganizerProvider;

    private Provider<ShellExecutor> provideShellAnimationExecutorProvider;

    private Provider<Transitions> provideTransitionsProvider;

    private Provider<Optional<ShellUnfoldProgressProvider>> optionalOfShellUnfoldProgressProvider;

    private Provider<UnfoldBackgroundController> provideUnfoldBackgroundControllerProvider;

    private Provider<Optional<StageTaskUnfoldController>> provideStageTaskUnfoldControllerProvider;

    private Provider<SplitScreenController> provideSplitScreenControllerProvider;

    private Provider<Optional<SplitScreenController>> dynamicOverrideOptionalOfSplitScreenControllerProvider;

    private Provider<Optional<SplitScreenController>> providesSplitScreenControllerProvider;

    private Provider<AppPairsController> provideAppPairsProvider;

    private Provider<Optional<AppPairsController>> optionalOfAppPairsControllerProvider;

    private Provider<PipBoundsState> providePipBoundsStateProvider;

    private Provider<PipMediaController> providePipMediaControllerProvider;

    private Provider<SystemWindows> provideSystemWindowsProvider;

    private Provider<PhonePipMenuController> providesPipPhoneMenuControllerProvider;

    private Provider<PipSnapAlgorithm> providePipSnapAlgorithmProvider;

    private Provider<PipBoundsAlgorithm> providesPipBoundsAlgorithmProvider;

    private Provider<PipTransitionState> providePipTransitionStateProvider;

    private Provider<PipSurfaceTransactionHelper> providePipSurfaceTransactionHelperProvider;

    private Provider<PipAnimationController> providePipAnimationControllerProvider;

    private Provider<PipTransitionController> providePipTransitionControllerProvider;

    private Provider<AnimationHandler> provideShellMainExecutorSfVsyncAnimationHandlerProvider;

    private Provider<LegacySplitScreenController> provideLegacySplitScreenProvider;

    private Provider<Optional<LegacySplitScreenController>> optionalOfLegacySplitScreenControllerProvider;

    private Provider<PipUiEventLogger> providePipUiEventLoggerProvider;

    private Provider<PipTaskOrganizer> providePipTaskOrganizerProvider;

    private Provider<PipMotionHelper> providePipMotionHelperProvider;

    private Provider<PipTouchHandler> providePipTouchHandlerProvider;

    private Provider<Optional<PipTouchHandler>> optionalOfPipTouchHandlerProvider;

    private Provider<FullscreenUnfoldController> provideFullscreenUnfoldControllerProvider;

    private Provider<Optional<FullscreenUnfoldController>> dynamicOverrideOptionalOfFullscreenUnfoldControllerProvider;

    private Provider<Optional<FullscreenUnfoldController>> provideFullscreenUnfoldControllerProvider2;

    private Provider<FullscreenTaskListener> provideFullscreenTaskListenerProvider;

    private Provider<FreeformTaskListener> provideFreeformTaskListenerProvider;

    private Provider<Optional<FreeformTaskListener>> dynamicOverrideOptionalOfFreeformTaskListenerProvider;

    private Provider<Optional<FreeformTaskListener>> provideFreeformTaskListenerProvider2;

    private Provider<ShellExecutor> provideSplashScreenExecutorProvider;

    private Provider<Optional<StartingWindowTypeAlgorithm>> dynamicOverrideOptionalOfStartingWindowTypeAlgorithmProvider;

    private Provider<StartingWindowTypeAlgorithm> provideStartingWindowTypeAlgorithmProvider;

    private Provider<StartingWindowController> provideStartingWindowControllerProvider;

    private Provider<ShellInitImpl> provideShellInitImplProvider;

    private Provider<ShellInit> provideShellInitProvider;

    private Provider<PipAppOpsListener> providePipAppOpsListenerProvider;

    private Provider<DisplayLayout> provideDisplayLayoutProvider;

    private Provider<OneHandedController> provideOneHandedControllerProvider;

    private Provider<Optional<OneHandedController>> dynamicOverrideOptionalOfOneHandedControllerProvider;

    private Provider<Optional<OneHandedController>> providesOneHandedControllerProvider;

    private Provider<Optional<Pip>> providePipProvider;

    private Provider<Optional<HideDisplayCutoutController>> provideHideDisplayCutoutControllerProvider;

    private Provider<ShellCommandHandlerImpl> provideShellCommandHandlerImplProvider;

    private Provider<Optional<ShellCommandHandler>> provideShellCommandHandlerProvider;

    private Provider<Optional<OneHanded>> provideOneHandedProvider;

    private Provider<Optional<LegacySplitScreen>> provideLegacySplitScreenProvider2;

    private Provider<Optional<SplitScreen>> provideSplitScreenProvider;

    private Provider<Optional<AppPairs>> provideAppPairsProvider2;

    private Provider<Optional<Bubbles>> provideBubblesProvider;

    private Provider<Optional<HideDisplayCutout>> provideHideDisplayCutoutProvider;

    private Provider<TaskViewFactoryController> provideTaskViewFactoryControllerProvider;

    private Provider<Optional<TaskViewFactory>> provideTaskViewFactoryProvider;

    private Provider<ShellTransitions> provideRemoteTransitionsProvider;

    private Provider<Optional<StartingSurface>> provideStartingSurfaceProvider;

    private Provider<RootDisplayAreaOrganizer> provideRootDisplayAreaOrganizerProvider;

    private Provider<Optional<DisplayAreaHelper>> provideDisplayAreaHelperProvider;

    private Provider<Optional<TaskSurfaceHelperController>> provideTaskSurfaceHelperControllerProvider;

    private Provider<Optional<TaskSurfaceHelper>> provideTaskSurfaceHelperProvider;

    private Provider<Optional<RecentTasks>> provideRecentTasksProvider;

    private Provider<CompatUI> provideCompatUIProvider;

    private Provider<DragAndDrop> provideDragAndDropProvider;

    private WMComponentImpl() {

      initialize();
    }

    @SuppressWarnings("unchecked")
    private void initialize() {
      this.provideShellMainHandlerProvider = DoubleCheck.provider(WMShellConcurrencyModule_ProvideShellMainHandlerFactory.create(DaggerGlobalRootComponent.this.contextProvider, WMShellConcurrencyModule_ProvideMainHandlerFactory.create()));
      this.provideSysUIMainExecutorProvider = DoubleCheck.provider(WMShellConcurrencyModule_ProvideSysUIMainExecutorFactory.create(WMShellConcurrencyModule_ProvideMainHandlerFactory.create()));
      this.provideShellMainExecutorProvider = DoubleCheck.provider(WMShellConcurrencyModule_ProvideShellMainExecutorFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideShellMainHandlerProvider, provideSysUIMainExecutorProvider));
      this.provideDisplayControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDisplayControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider, provideShellMainExecutorProvider));
      this.dynamicOverrideOptionalOfDisplayImeControllerProvider = absentJdkOptionalProvider();
      this.provideDisplayInsetsControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDisplayInsetsControllerFactory.create(DaggerGlobalRootComponent.this.provideIWindowManagerProvider, provideDisplayControllerProvider, provideShellMainExecutorProvider));
      this.provideTransactionPoolProvider = DoubleCheck.provider(WMShellBaseModule_ProvideTransactionPoolFactory.create());
      this.provideDisplayImeControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDisplayImeControllerFactory.create(dynamicOverrideOptionalOfDisplayImeControllerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider, provideDisplayControllerProvider, provideDisplayInsetsControllerProvider, provideShellMainExecutorProvider, provideTransactionPoolProvider));
      this.provideIconProvider = DoubleCheck.provider(WMShellBaseModule_ProvideIconProviderFactory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.provideDragAndDropControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDragAndDropControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideDisplayControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideIconProvider, provideShellMainExecutorProvider));
      this.provideSyncTransactionQueueProvider = DoubleCheck.provider(WMShellBaseModule_ProvideSyncTransactionQueueFactory.create(provideTransactionPoolProvider, provideShellMainExecutorProvider));
      this.provideCompatUIControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideCompatUIControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideDisplayControllerProvider, provideDisplayInsetsControllerProvider, provideDisplayImeControllerProvider, provideSyncTransactionQueueProvider, provideShellMainExecutorProvider));
      this.providerTaskStackListenerImplProvider = DoubleCheck.provider(WMShellBaseModule_ProviderTaskStackListenerImplFactory.create(provideShellMainHandlerProvider));
      this.provideRecentTasksControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideRecentTasksControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, providerTaskStackListenerImplProvider, provideShellMainExecutorProvider));
      this.provideShellTaskOrganizerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideShellTaskOrganizerFactory.create(provideShellMainExecutorProvider, DaggerGlobalRootComponent.this.contextProvider, provideCompatUIControllerProvider, provideRecentTasksControllerProvider));
      this.provideFloatingContentCoordinatorProvider = DoubleCheck.provider(WMShellBaseModule_ProvideFloatingContentCoordinatorFactory.create());
      this.provideWindowManagerShellWrapperProvider = DoubleCheck.provider(WMShellBaseModule_ProvideWindowManagerShellWrapperFactory.create(provideShellMainExecutorProvider));
      this.provideBubbleControllerProvider = DoubleCheck.provider(WMShellModule_ProvideBubbleControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideFloatingContentCoordinatorProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, provideWindowManagerShellWrapperProvider, DaggerGlobalRootComponent.this.provideLauncherAppsProvider, providerTaskStackListenerImplProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideShellTaskOrganizerProvider, provideDisplayControllerProvider, provideShellMainExecutorProvider, provideShellMainHandlerProvider, provideSyncTransactionQueueProvider));
      this.optionalOfBubbleControllerProvider = PresentJdkOptionalInstanceProvider.of(provideBubbleControllerProvider);
      this.provideRootTaskDisplayAreaOrganizerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideRootTaskDisplayAreaOrganizerFactory.create(provideShellMainExecutorProvider, DaggerGlobalRootComponent.this.contextProvider));
      this.provideShellAnimationExecutorProvider = DoubleCheck.provider(WMShellConcurrencyModule_ProvideShellAnimationExecutorFactory.create());
      this.provideTransitionsProvider = DoubleCheck.provider(WMShellBaseModule_ProvideTransitionsFactory.create(provideShellTaskOrganizerProvider, provideTransactionPoolProvider, provideDisplayControllerProvider, DaggerGlobalRootComponent.this.contextProvider, provideShellMainExecutorProvider, provideShellAnimationExecutorProvider));
      this.optionalOfShellUnfoldProgressProvider = PresentJdkOptionalInstanceProvider.of(DaggerGlobalRootComponent.this.provideShellProgressProvider);
      this.provideUnfoldBackgroundControllerProvider = DoubleCheck.provider(WMShellModule_ProvideUnfoldBackgroundControllerFactory.create(provideRootTaskDisplayAreaOrganizerProvider, DaggerGlobalRootComponent.this.contextProvider));
      this.provideStageTaskUnfoldControllerProvider = WMShellModule_ProvideStageTaskUnfoldControllerFactory.create(optionalOfShellUnfoldProgressProvider, DaggerGlobalRootComponent.this.contextProvider, provideTransactionPoolProvider, provideUnfoldBackgroundControllerProvider, provideDisplayInsetsControllerProvider, provideShellMainExecutorProvider);
      this.provideSplitScreenControllerProvider = DoubleCheck.provider(WMShellModule_ProvideSplitScreenControllerFactory.create(provideShellTaskOrganizerProvider, provideSyncTransactionQueueProvider, DaggerGlobalRootComponent.this.contextProvider, provideRootTaskDisplayAreaOrganizerProvider, provideShellMainExecutorProvider, provideDisplayImeControllerProvider, provideDisplayInsetsControllerProvider, provideTransitionsProvider, provideTransactionPoolProvider, provideIconProvider, provideRecentTasksControllerProvider, provideStageTaskUnfoldControllerProvider));
      this.dynamicOverrideOptionalOfSplitScreenControllerProvider = PresentJdkOptionalInstanceProvider.of(provideSplitScreenControllerProvider);
      this.providesSplitScreenControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvidesSplitScreenControllerFactory.create(dynamicOverrideOptionalOfSplitScreenControllerProvider, DaggerGlobalRootComponent.this.contextProvider));
      this.provideAppPairsProvider = DoubleCheck.provider(WMShellModule_ProvideAppPairsFactory.create(provideShellTaskOrganizerProvider, provideSyncTransactionQueueProvider, provideDisplayControllerProvider, provideShellMainExecutorProvider, provideDisplayImeControllerProvider, provideDisplayInsetsControllerProvider));
      this.optionalOfAppPairsControllerProvider = PresentJdkOptionalInstanceProvider.of(provideAppPairsProvider);
      this.providePipBoundsStateProvider = DoubleCheck.provider(WMShellModule_ProvidePipBoundsStateFactory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.providePipMediaControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvidePipMediaControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideShellMainHandlerProvider));
      this.provideSystemWindowsProvider = DoubleCheck.provider(WMShellBaseModule_ProvideSystemWindowsFactory.create(provideDisplayControllerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider));
      this.providesPipPhoneMenuControllerProvider = DoubleCheck.provider(WMShellModule_ProvidesPipPhoneMenuControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, providePipBoundsStateProvider, providePipMediaControllerProvider, provideSystemWindowsProvider, providesSplitScreenControllerProvider, provideShellMainExecutorProvider, provideShellMainHandlerProvider));
      this.providePipSnapAlgorithmProvider = DoubleCheck.provider(WMShellModule_ProvidePipSnapAlgorithmFactory.create());
      this.providesPipBoundsAlgorithmProvider = DoubleCheck.provider(WMShellModule_ProvidesPipBoundsAlgorithmFactory.create(DaggerGlobalRootComponent.this.contextProvider, providePipBoundsStateProvider, providePipSnapAlgorithmProvider));
      this.providePipTransitionStateProvider = DoubleCheck.provider(WMShellModule_ProvidePipTransitionStateFactory.create());
      this.providePipSurfaceTransactionHelperProvider = DoubleCheck.provider(WMShellBaseModule_ProvidePipSurfaceTransactionHelperFactory.create());
      this.providePipAnimationControllerProvider = DoubleCheck.provider(WMShellModule_ProvidePipAnimationControllerFactory.create(providePipSurfaceTransactionHelperProvider));
      this.providePipTransitionControllerProvider = DoubleCheck.provider(WMShellModule_ProvidePipTransitionControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideTransitionsProvider, provideShellTaskOrganizerProvider, providePipAnimationControllerProvider, providesPipBoundsAlgorithmProvider, providePipBoundsStateProvider, providePipTransitionStateProvider, providesPipPhoneMenuControllerProvider));
      this.provideShellMainExecutorSfVsyncAnimationHandlerProvider = DoubleCheck.provider(WMShellConcurrencyModule_ProvideShellMainExecutorSfVsyncAnimationHandlerFactory.create(provideShellMainExecutorProvider));
      this.provideLegacySplitScreenProvider = DoubleCheck.provider(WMShellModule_ProvideLegacySplitScreenFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideDisplayControllerProvider, provideSystemWindowsProvider, provideDisplayImeControllerProvider, provideTransactionPoolProvider, provideShellTaskOrganizerProvider, provideSyncTransactionQueueProvider, providerTaskStackListenerImplProvider, provideTransitionsProvider, provideShellMainExecutorProvider, provideShellMainExecutorSfVsyncAnimationHandlerProvider));
      this.optionalOfLegacySplitScreenControllerProvider = PresentJdkOptionalInstanceProvider.of(provideLegacySplitScreenProvider);
      this.providePipUiEventLoggerProvider = DoubleCheck.provider(WMShellBaseModule_ProvidePipUiEventLoggerFactory.create(DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider));
      this.providePipTaskOrganizerProvider = DoubleCheck.provider(WMShellModule_ProvidePipTaskOrganizerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideSyncTransactionQueueProvider, providePipTransitionStateProvider, providePipBoundsStateProvider, providesPipBoundsAlgorithmProvider, providesPipPhoneMenuControllerProvider, providePipAnimationControllerProvider, providePipSurfaceTransactionHelperProvider, providePipTransitionControllerProvider, optionalOfLegacySplitScreenControllerProvider, providesSplitScreenControllerProvider, provideDisplayControllerProvider, providePipUiEventLoggerProvider, provideShellTaskOrganizerProvider, provideShellMainExecutorProvider));
      this.providePipMotionHelperProvider = DoubleCheck.provider(WMShellModule_ProvidePipMotionHelperFactory.create(DaggerGlobalRootComponent.this.contextProvider, providePipBoundsStateProvider, providePipTaskOrganizerProvider, providesPipPhoneMenuControllerProvider, providePipSnapAlgorithmProvider, providePipTransitionControllerProvider, provideFloatingContentCoordinatorProvider));
      this.providePipTouchHandlerProvider = DoubleCheck.provider(WMShellModule_ProvidePipTouchHandlerFactory.create(DaggerGlobalRootComponent.this.contextProvider, providesPipPhoneMenuControllerProvider, providesPipBoundsAlgorithmProvider, providePipBoundsStateProvider, providePipTaskOrganizerProvider, providePipMotionHelperProvider, provideFloatingContentCoordinatorProvider, providePipUiEventLoggerProvider, provideShellMainExecutorProvider));
      this.optionalOfPipTouchHandlerProvider = PresentJdkOptionalInstanceProvider.of(providePipTouchHandlerProvider);
      this.provideFullscreenUnfoldControllerProvider = DoubleCheck.provider(WMShellModule_ProvideFullscreenUnfoldControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, optionalOfShellUnfoldProgressProvider, provideUnfoldBackgroundControllerProvider, provideDisplayInsetsControllerProvider, provideShellMainExecutorProvider));
      this.dynamicOverrideOptionalOfFullscreenUnfoldControllerProvider = PresentJdkOptionalInstanceProvider.of(provideFullscreenUnfoldControllerProvider);
      this.provideFullscreenUnfoldControllerProvider2 = DoubleCheck.provider(WMShellBaseModule_ProvideFullscreenUnfoldControllerFactory.create(dynamicOverrideOptionalOfFullscreenUnfoldControllerProvider, optionalOfShellUnfoldProgressProvider));
      this.provideFullscreenTaskListenerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideFullscreenTaskListenerFactory.create(provideSyncTransactionQueueProvider, provideFullscreenUnfoldControllerProvider2, provideRecentTasksControllerProvider));
      this.provideFreeformTaskListenerProvider = DoubleCheck.provider(WMShellModule_ProvideFreeformTaskListenerFactory.create(provideSyncTransactionQueueProvider));
      this.dynamicOverrideOptionalOfFreeformTaskListenerProvider = PresentJdkOptionalInstanceProvider.of(provideFreeformTaskListenerProvider);
      this.provideFreeformTaskListenerProvider2 = DoubleCheck.provider(WMShellBaseModule_ProvideFreeformTaskListenerFactory.create(dynamicOverrideOptionalOfFreeformTaskListenerProvider, DaggerGlobalRootComponent.this.contextProvider));
      this.provideSplashScreenExecutorProvider = DoubleCheck.provider(WMShellConcurrencyModule_ProvideSplashScreenExecutorFactory.create());
      this.dynamicOverrideOptionalOfStartingWindowTypeAlgorithmProvider = absentJdkOptionalProvider();
      this.provideStartingWindowTypeAlgorithmProvider = DoubleCheck.provider(WMShellBaseModule_ProvideStartingWindowTypeAlgorithmFactory.create(dynamicOverrideOptionalOfStartingWindowTypeAlgorithmProvider));
      this.provideStartingWindowControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideStartingWindowControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideSplashScreenExecutorProvider, provideStartingWindowTypeAlgorithmProvider, provideIconProvider, provideTransactionPoolProvider));
      this.provideShellInitImplProvider = DoubleCheck.provider(WMShellBaseModule_ProvideShellInitImplFactory.create(provideDisplayControllerProvider, provideDisplayImeControllerProvider, provideDisplayInsetsControllerProvider, provideDragAndDropControllerProvider, provideShellTaskOrganizerProvider, optionalOfBubbleControllerProvider, providesSplitScreenControllerProvider, optionalOfAppPairsControllerProvider, optionalOfPipTouchHandlerProvider, provideFullscreenTaskListenerProvider, provideFullscreenUnfoldControllerProvider2, provideFreeformTaskListenerProvider2, provideRecentTasksControllerProvider, provideTransitionsProvider, provideStartingWindowControllerProvider, provideShellMainExecutorProvider));
      this.provideShellInitProvider = DoubleCheck.provider(WMShellBaseModule_ProvideShellInitFactory.create(provideShellInitImplProvider));
      this.providePipAppOpsListenerProvider = DoubleCheck.provider(WMShellBaseModule_ProvidePipAppOpsListenerFactory.create(DaggerGlobalRootComponent.this.contextProvider, providePipTouchHandlerProvider, provideShellMainExecutorProvider));
      this.provideDisplayLayoutProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDisplayLayoutFactory.create());
      this.provideOneHandedControllerProvider = DoubleCheck.provider(WMShellModule_ProvideOneHandedControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, provideDisplayControllerProvider, provideDisplayLayoutProvider, providerTaskStackListenerImplProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideShellMainExecutorProvider, provideShellMainHandlerProvider));
      this.dynamicOverrideOptionalOfOneHandedControllerProvider = PresentJdkOptionalInstanceProvider.of(provideOneHandedControllerProvider);
      this.providesOneHandedControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvidesOneHandedControllerFactory.create(dynamicOverrideOptionalOfOneHandedControllerProvider));
      this.providePipProvider = DoubleCheck.provider(WMShellModule_ProvidePipFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideDisplayControllerProvider, providePipAppOpsListenerProvider, providesPipBoundsAlgorithmProvider, providePipBoundsStateProvider, providePipMediaControllerProvider, providesPipPhoneMenuControllerProvider, providePipTaskOrganizerProvider, providePipTouchHandlerProvider, providePipTransitionControllerProvider, provideWindowManagerShellWrapperProvider, providerTaskStackListenerImplProvider, providesOneHandedControllerProvider, provideShellMainExecutorProvider));
      this.provideHideDisplayCutoutControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideHideDisplayCutoutControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideDisplayControllerProvider, provideShellMainExecutorProvider));
      this.provideShellCommandHandlerImplProvider = DoubleCheck.provider(WMShellBaseModule_ProvideShellCommandHandlerImplFactory.create(provideShellTaskOrganizerProvider, optionalOfLegacySplitScreenControllerProvider, providesSplitScreenControllerProvider, providePipProvider, providesOneHandedControllerProvider, provideHideDisplayCutoutControllerProvider, optionalOfAppPairsControllerProvider, provideRecentTasksControllerProvider, provideShellMainExecutorProvider));
      this.provideShellCommandHandlerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideShellCommandHandlerFactory.create(provideShellCommandHandlerImplProvider));
      this.provideOneHandedProvider = DoubleCheck.provider(WMShellBaseModule_ProvideOneHandedFactory.create(providesOneHandedControllerProvider));
      this.provideLegacySplitScreenProvider2 = DoubleCheck.provider(WMShellBaseModule_ProvideLegacySplitScreenFactory.create(optionalOfLegacySplitScreenControllerProvider));
      this.provideSplitScreenProvider = DoubleCheck.provider(WMShellBaseModule_ProvideSplitScreenFactory.create(providesSplitScreenControllerProvider));
      this.provideAppPairsProvider2 = DoubleCheck.provider(WMShellBaseModule_ProvideAppPairsFactory.create(optionalOfAppPairsControllerProvider));
      this.provideBubblesProvider = DoubleCheck.provider(WMShellBaseModule_ProvideBubblesFactory.create(optionalOfBubbleControllerProvider));
      this.provideHideDisplayCutoutProvider = DoubleCheck.provider(WMShellBaseModule_ProvideHideDisplayCutoutFactory.create(provideHideDisplayCutoutControllerProvider));
      this.provideTaskViewFactoryControllerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideTaskViewFactoryControllerFactory.create(provideShellTaskOrganizerProvider, provideShellMainExecutorProvider, provideSyncTransactionQueueProvider));
      this.provideTaskViewFactoryProvider = DoubleCheck.provider(WMShellBaseModule_ProvideTaskViewFactoryFactory.create(provideTaskViewFactoryControllerProvider));
      this.provideRemoteTransitionsProvider = DoubleCheck.provider(WMShellBaseModule_ProvideRemoteTransitionsFactory.create(provideTransitionsProvider));
      this.provideStartingSurfaceProvider = DoubleCheck.provider(WMShellBaseModule_ProvideStartingSurfaceFactory.create(provideStartingWindowControllerProvider));
      this.provideRootDisplayAreaOrganizerProvider = DoubleCheck.provider(WMShellBaseModule_ProvideRootDisplayAreaOrganizerFactory.create(provideShellMainExecutorProvider));
      this.provideDisplayAreaHelperProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDisplayAreaHelperFactory.create(provideShellMainExecutorProvider, provideRootDisplayAreaOrganizerProvider));
      this.provideTaskSurfaceHelperControllerProvider = WMShellBaseModule_ProvideTaskSurfaceHelperControllerFactory.create(provideShellTaskOrganizerProvider, provideShellMainExecutorProvider);
      this.provideTaskSurfaceHelperProvider = DoubleCheck.provider(WMShellBaseModule_ProvideTaskSurfaceHelperFactory.create(provideTaskSurfaceHelperControllerProvider));
      this.provideRecentTasksProvider = DoubleCheck.provider(WMShellBaseModule_ProvideRecentTasksFactory.create(provideRecentTasksControllerProvider));
      this.provideCompatUIProvider = DoubleCheck.provider(WMShellBaseModule_ProvideCompatUIFactory.create(provideCompatUIControllerProvider));
      this.provideDragAndDropProvider = DoubleCheck.provider(WMShellBaseModule_ProvideDragAndDropFactory.create(provideDragAndDropControllerProvider));
    }

    @Override
    public ShellInit getShellInit() {
      return provideShellInitProvider.get();
    }

    @Override
    public Optional<ShellCommandHandler> getShellCommandHandler() {
      return provideShellCommandHandlerProvider.get();
    }

    @Override
    public Optional<OneHanded> getOneHanded() {
      return provideOneHandedProvider.get();
    }

    @Override
    public Optional<Pip> getPip() {
      return providePipProvider.get();
    }

    @Override
    public Optional<LegacySplitScreen> getLegacySplitScreen() {
      return provideLegacySplitScreenProvider2.get();
    }

    @Override
    public Optional<SplitScreen> getSplitScreen() {
      return provideSplitScreenProvider.get();
    }

    @Override
    public Optional<AppPairs> getAppPairs() {
      return provideAppPairsProvider2.get();
    }

    @Override
    public Optional<Bubbles> getBubbles() {
      return provideBubblesProvider.get();
    }

    @Override
    public Optional<HideDisplayCutout> getHideDisplayCutout() {
      return provideHideDisplayCutoutProvider.get();
    }

    @Override
    public Optional<TaskViewFactory> getTaskViewFactory() {
      return provideTaskViewFactoryProvider.get();
    }

    @Override
    public ShellTransitions getTransitions() {
      return provideRemoteTransitionsProvider.get();
    }

    @Override
    public Optional<StartingSurface> getStartingSurface() {
      return provideStartingSurfaceProvider.get();
    }

    @Override
    public Optional<DisplayAreaHelper> getDisplayAreaHelper() {
      return provideDisplayAreaHelperProvider.get();
    }

    @Override
    public Optional<TaskSurfaceHelper> getTaskSurfaceHelper() {
      return provideTaskSurfaceHelperProvider.get();
    }

    @Override
    public Optional<RecentTasks> getRecentTasks() {
      return provideRecentTasksProvider.get();
    }

    @Override
    public CompatUI getCompatUI() {
      return provideCompatUIProvider.get();
    }

    @Override
    public DragAndDrop getDragAndDrop() {
      return provideDragAndDropProvider.get();
    }
  }

  private final class SysUIComponentBuilder implements SysUIComponent.Builder {
    private Optional<Pip> setPip;

    private Optional<LegacySplitScreen> setLegacySplitScreen;

    private Optional<SplitScreen> setSplitScreen;

    private Optional<AppPairs> setAppPairs;

    private Optional<OneHanded> setOneHanded;

    private Optional<Bubbles> setBubbles;

    private Optional<TaskViewFactory> setTaskViewFactory;

    private Optional<HideDisplayCutout> setHideDisplayCutout;

    private Optional<ShellCommandHandler> setShellCommandHandler;

    private ShellTransitions setTransitions;

    private Optional<StartingSurface> setStartingSurface;

    private Optional<DisplayAreaHelper> setDisplayAreaHelper;

    private Optional<TaskSurfaceHelper> setTaskSurfaceHelper;

    private Optional<RecentTasks> setRecentTasks;

    private Optional<CompatUI> setCompatUI;

    private Optional<DragAndDrop> setDragAndDrop;

    @Override
    public SysUIComponentBuilder setPip(Optional<Pip> p) {
      this.setPip = Preconditions.checkNotNull(p);
      return this;
    }

    @Override
    public SysUIComponentBuilder setLegacySplitScreen(Optional<LegacySplitScreen> s) {
      this.setLegacySplitScreen = Preconditions.checkNotNull(s);
      return this;
    }

    @Override
    public SysUIComponentBuilder setSplitScreen(Optional<SplitScreen> s) {
      this.setSplitScreen = Preconditions.checkNotNull(s);
      return this;
    }

    @Override
    public SysUIComponentBuilder setAppPairs(Optional<AppPairs> s) {
      this.setAppPairs = Preconditions.checkNotNull(s);
      return this;
    }

    @Override
    public SysUIComponentBuilder setOneHanded(Optional<OneHanded> o) {
      this.setOneHanded = Preconditions.checkNotNull(o);
      return this;
    }

    @Override
    public SysUIComponentBuilder setBubbles(Optional<Bubbles> b) {
      this.setBubbles = Preconditions.checkNotNull(b);
      return this;
    }

    @Override
    public SysUIComponentBuilder setTaskViewFactory(Optional<TaskViewFactory> t) {
      this.setTaskViewFactory = Preconditions.checkNotNull(t);
      return this;
    }

    @Override
    public SysUIComponentBuilder setHideDisplayCutout(Optional<HideDisplayCutout> h) {
      this.setHideDisplayCutout = Preconditions.checkNotNull(h);
      return this;
    }

    @Override
    public SysUIComponentBuilder setShellCommandHandler(Optional<ShellCommandHandler> shellDump) {
      this.setShellCommandHandler = Preconditions.checkNotNull(shellDump);
      return this;
    }

    @Override
    public SysUIComponentBuilder setTransitions(ShellTransitions t) {
      this.setTransitions = Preconditions.checkNotNull(t);
      return this;
    }

    @Override
    public SysUIComponentBuilder setStartingSurface(Optional<StartingSurface> s) {
      this.setStartingSurface = Preconditions.checkNotNull(s);
      return this;
    }

    @Override
    public SysUIComponentBuilder setDisplayAreaHelper(Optional<DisplayAreaHelper> h) {
      this.setDisplayAreaHelper = Preconditions.checkNotNull(h);
      return this;
    }

    @Override
    public SysUIComponentBuilder setTaskSurfaceHelper(Optional<TaskSurfaceHelper> t) {
      this.setTaskSurfaceHelper = Preconditions.checkNotNull(t);
      return this;
    }

    @Override
    public SysUIComponentBuilder setRecentTasks(Optional<RecentTasks> r) {
      this.setRecentTasks = Preconditions.checkNotNull(r);
      return this;
    }

    @Override
    public SysUIComponentBuilder setCompatUI(Optional<CompatUI> s) {
      this.setCompatUI = Preconditions.checkNotNull(s);
      return this;
    }

    @Override
    public SysUIComponentBuilder setDragAndDrop(Optional<DragAndDrop> d) {
      this.setDragAndDrop = Preconditions.checkNotNull(d);
      return this;
    }

    @Override
    public SysUIComponent build() {
      Preconditions.checkBuilderRequirement(setPip, Optional.class);
      Preconditions.checkBuilderRequirement(setLegacySplitScreen, Optional.class);
      Preconditions.checkBuilderRequirement(setSplitScreen, Optional.class);
      Preconditions.checkBuilderRequirement(setAppPairs, Optional.class);
      Preconditions.checkBuilderRequirement(setOneHanded, Optional.class);
      Preconditions.checkBuilderRequirement(setBubbles, Optional.class);
      Preconditions.checkBuilderRequirement(setTaskViewFactory, Optional.class);
      Preconditions.checkBuilderRequirement(setHideDisplayCutout, Optional.class);
      Preconditions.checkBuilderRequirement(setShellCommandHandler, Optional.class);
      Preconditions.checkBuilderRequirement(setTransitions, ShellTransitions.class);
      Preconditions.checkBuilderRequirement(setStartingSurface, Optional.class);
      Preconditions.checkBuilderRequirement(setDisplayAreaHelper, Optional.class);
      Preconditions.checkBuilderRequirement(setTaskSurfaceHelper, Optional.class);
      Preconditions.checkBuilderRequirement(setRecentTasks, Optional.class);
      Preconditions.checkBuilderRequirement(setCompatUI, Optional.class);
      Preconditions.checkBuilderRequirement(setDragAndDrop, Optional.class);
      return new SysUIComponentImpl(new DependencyProvider(), new NightDisplayListenerModule(), new SysUIUnfoldModule(), new UserModule(), setPip, setLegacySplitScreen, setSplitScreen, setAppPairs, setOneHanded, setBubbles, setTaskViewFactory, setHideDisplayCutout, setShellCommandHandler, setTransitions, setStartingSurface, setDisplayAreaHelper, setTaskSurfaceHelper, setRecentTasks, setCompatUI, setDragAndDrop);
    }
  }

  private final class SysUIComponentImpl implements SysUIComponent {
    private Provider<BootCompleteCacheImpl> bootCompleteCacheImplProvider;

    private Provider<ConfigurationController> provideConfigurationControllerProvider;

    @SuppressWarnings("rawtypes")
    private Provider globalSettingsImplProvider;

    private Provider<DemoModeController> provideDemoModeControllerProvider;

    private Provider<LeakDetector> provideLeakDetectorProvider;

    private Provider<Looper> provideBgLooperProvider;

    private Provider<Handler> provideBgHandlerProvider;

    private Provider<UserTracker> provideUserTrackerProvider;

    private Provider<TunerServiceImpl> tunerServiceImplProvider;

    private Provider<TunerActivity> tunerActivityProvider;

    private Provider<Executor> provideBackgroundExecutorProvider;

    private Provider<LogcatEchoTracker> provideLogcatEchoTrackerProvider;

    private Provider<LogBufferFactory> logBufferFactoryProvider;

    private Provider<LogBuffer> provideBroadcastDispatcherLogBufferProvider;

    private Provider<BroadcastDispatcherLogger> broadcastDispatcherLoggerProvider;

    private Provider<BroadcastDispatcher> providesBroadcastDispatcherProvider;

    private Provider<WorkLockActivity> workLockActivityProvider;

    private Provider<DeviceConfigProxy> deviceConfigProxyProvider;

    private Provider<EnhancedEstimatesImpl> enhancedEstimatesImplProvider;

    private Provider<BatteryController> provideBatteryControllerProvider;

    private Provider<DockManagerImpl> dockManagerImplProvider;

    private Provider<FalsingDataProvider> falsingDataProvider;

    private Provider<MetricsLogger> provideMetricsLoggerProvider;

    @SuppressWarnings("rawtypes")
    private Provider distanceClassifierProvider;

    @SuppressWarnings("rawtypes")
    private Provider proximityClassifierProvider;

    @SuppressWarnings("rawtypes")
    private Provider pointerCountClassifierProvider;

    private Provider<TypeClassifier> typeClassifierProvider;

    @SuppressWarnings("rawtypes")
    private Provider diagonalClassifierProvider;

    @SuppressWarnings("rawtypes")
    private Provider zigZagClassifierProvider;

    private Provider<Set<FalsingClassifier>> providesBrightLineGestureClassifiersProvider;

    private Provider<Set<FalsingClassifier>> namedSetOfFalsingClassifierProvider;

    private Provider<Float> providesSingleTapTouchSlopProvider;

    private Provider<SingleTapClassifier> singleTapClassifierProvider;

    private Provider<Float> providesDoubleTapTouchSlopProvider;

    private Provider<DoubleTapClassifier> doubleTapClassifierProvider;

    private Provider<SystemClock> bindSystemClockProvider;

    private Provider<HistoryTracker> historyTrackerProvider;

    private Provider<RingerModeTrackerImpl> ringerModeTrackerImplProvider;

    private Provider<StatusBarStateControllerImpl> statusBarStateControllerImplProvider;

    private Provider<LockPatternUtils> provideLockPatternUtilsProvider;

    private Provider<ProtoTracer> protoTracerProvider;

    private Provider<CommandRegistry> commandRegistryProvider;

    private Provider<CommandQueue> provideCommandQueueProvider;

    private Provider<LayoutInflater> providerLayoutInflaterProvider;

    private Provider<PanelExpansionStateManager> panelExpansionStateManagerProvider;

    private Provider<FalsingManagerProxy> falsingManagerProxyProvider;

    private Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

    private Provider<AsyncSensorManager> asyncSensorManagerProvider;

    private Provider<ThresholdSensorImpl.BuilderFactory> builderFactoryProvider;

    private Provider<ThresholdSensor[]> providePostureToProximitySensorMappingProvider;

    private Provider<ThresholdSensor[]> providePostureToSecondaryProximitySensorMappingProvider;

    private Provider<DevicePostureControllerImpl> devicePostureControllerImplProvider;

    @SuppressWarnings("rawtypes")
    private Provider postureDependentProximitySensorProvider;

    private Provider<ThresholdSensorImpl.Builder> builderProvider;

    private Provider<ThresholdSensor> providePrimaryProximitySensorProvider;

    private Provider<ThresholdSensor> provideSecondaryProximitySensorProvider;

    @SuppressWarnings("rawtypes")
    private Provider proximitySensorImplProvider;

    private Provider<ProximitySensor> provideProximitySensorProvider;

    private Provider<KeyguardStateControllerImpl> keyguardStateControllerImplProvider;

    @SuppressWarnings("rawtypes")
    private Provider falsingCollectorImplProvider;

    private Provider<StatusBarKeyguardViewManager> statusBarKeyguardViewManagerProvider;

    private Provider<Executor> provideUiBackgroundExecutorProvider;

    private Provider<DismissCallbackRegistry> dismissCallbackRegistryProvider;

    @SuppressWarnings("rawtypes")
    private Provider secureSettingsImplProvider;

    private Provider<DeviceProvisionedControllerImpl> deviceProvisionedControllerImplProvider;

    private Provider<DeviceProvisionedController> bindDeviceProvisionedControllerProvider;

    private Provider<FlagManager> provideFlagManagerProvider;

    private Provider<FeatureFlagManager> featureFlagManagerProvider;

    private Provider<FeatureFlags> featureFlagsProvider;

    private Provider<NotificationListener> provideNotificationListenerProvider;

    private Provider<LogBuffer> provideNotificationsLogBufferProvider;

    private Provider<NotificationEntryManagerLogger> notificationEntryManagerLoggerProvider;

    private Provider<ExtensionControllerImpl> extensionControllerImplProvider;

    private Provider<NotificationPersonExtractorPluginBoundary> notificationPersonExtractorPluginBoundaryProvider;

    private Provider<NotificationGroupManagerLegacy> notificationGroupManagerLegacyProvider;

    private Provider<GroupMembershipManager> provideGroupMembershipManagerProvider;

    private Provider<PeopleNotificationIdentifierImpl> peopleNotificationIdentifierImplProvider;

    private Provider<Optional<Bubbles>> setBubblesProvider;

    private Provider<NotificationMessagingUtil> provideNotificationMessagingUtilProvider;

    private Provider<NotificationClickNotifier> notificationClickNotifierProvider;

    private Provider<NotificationLockscreenUserManagerImpl> notificationLockscreenUserManagerImplProvider;

    private Provider<NotificationEntryManager> provideNotificationEntryManagerProvider;

    private Provider<SmartReplyController> provideSmartReplyControllerProvider;

    private Provider<RemoteInputNotificationRebuilder> remoteInputNotificationRebuilderProvider;

    private Provider<Optional<StatusBar>> optionalOfStatusBarProvider;

    private Provider<Handler> provideHandlerProvider;

    private Provider<RemoteInputUriController> remoteInputUriControllerProvider;

    private Provider<LogBuffer> provideNotifInteractionLogBufferProvider;

    private Provider<ActionClickLogger> actionClickLoggerProvider;

    private Provider<NotificationRemoteInputManager> provideNotificationRemoteInputManagerProvider;

    private Provider<NotifCollectionLogger> notifCollectionLoggerProvider;

    private Provider<Files> filesProvider;

    private Provider<LogBufferEulogizer> logBufferEulogizerProvider;

    private Provider<NotifCollection> notifCollectionProvider;

    private Provider<ShadeListBuilderLogger> shadeListBuilderLoggerProvider;

    private Provider<NotificationInteractionTracker> notificationInteractionTrackerProvider;

    private Provider<ShadeListBuilder> shadeListBuilderProvider;

    private Provider<NotifPipeline> notifPipelineProvider;

    private Provider<CommonNotifCollection> provideCommonNotifCollectionProvider;

    private Provider<NotifBindPipelineLogger> notifBindPipelineLoggerProvider;

    private Provider<NotifBindPipeline> notifBindPipelineProvider;

    private Provider<NotifRemoteViewCacheImpl> notifRemoteViewCacheImplProvider;

    private Provider<NotifRemoteViewCache> provideNotifRemoteViewCacheProvider;

    private Provider<ConversationNotificationManager> conversationNotificationManagerProvider;

    private Provider<ConversationNotificationProcessor> conversationNotificationProcessorProvider;

    private Provider<MediaFeatureFlag> mediaFeatureFlagProvider;

    private Provider<SmartReplyConstants> smartReplyConstantsProvider;

    private Provider<ActivityManagerWrapper> provideActivityManagerWrapperProvider;

    private Provider<DevicePolicyManagerWrapper> provideDevicePolicyManagerWrapperProvider;

    private Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

    private Provider<SmartReplyInflaterImpl> smartReplyInflaterImplProvider;

    private Provider<ActivityStarter> provideActivityStarterProvider;

    private Provider<KeyguardBypassController> keyguardBypassControllerProvider;

    private Provider<HeadsUpManagerPhone> provideHeadsUpManagerPhoneProvider;

    private Provider<SmartActionInflaterImpl> smartActionInflaterImplProvider;

    private Provider<SmartReplyStateInflaterImpl> smartReplyStateInflaterImplProvider;

    private Provider<NotificationContentInflater> notificationContentInflaterProvider;

    private Provider<NotifInflationErrorManager> notifInflationErrorManagerProvider;

    private Provider<RowContentBindStageLogger> rowContentBindStageLoggerProvider;

    private Provider<RowContentBindStage> rowContentBindStageProvider;

    private Provider<ExpandableNotificationRowComponent.Builder> expandableNotificationRowComponentBuilderProvider;

    private Provider<IconBuilder> iconBuilderProvider;

    private Provider<IconManager> iconManagerProvider;

    private Provider<LowPriorityInflationHelper> lowPriorityInflationHelperProvider;

    private Provider<NotificationRowBinderImpl> notificationRowBinderImplProvider;

    private Provider<ForegroundServiceDismissalFeatureController> foregroundServiceDismissalFeatureControllerProvider;

    private Provider<AmbientDisplayConfiguration> provideAmbientDisplayConfigurationProvider;

    private Provider<AlwaysOnDisplayPolicy> provideAlwaysOnDisplayPolicyProvider;

    private Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

    private Provider<KeyguardViewMediator> newKeyguardViewMediatorProvider;

    private Provider<DozeParameters> dozeParametersProvider;

    private Provider<UnlockedScreenOffAnimationController> unlockedScreenOffAnimationControllerProvider;

    private Provider<SysuiColorExtractor> sysuiColorExtractorProvider;

    private Provider<AuthController> authControllerProvider;

    private Provider<NotificationShadeWindowControllerImpl> notificationShadeWindowControllerImplProvider;

    private Provider<MediaArtworkProcessor> mediaArtworkProcessorProvider;

    private Provider<MediaControllerFactory> mediaControllerFactoryProvider;

    private Provider<MediaTimeoutListener> mediaTimeoutListenerProvider;

    private Provider<MediaBrowserFactory> mediaBrowserFactoryProvider;

    private Provider<ResumeMediaBrowserFactory> resumeMediaBrowserFactoryProvider;

    private Provider<MediaResumeListener> mediaResumeListenerProvider;

    private Provider<MediaSessionBasedFilter> mediaSessionBasedFilterProvider;

    private Provider<LocalBluetoothManager> provideLocalBluetoothControllerProvider;

    private Provider<LocalMediaManagerFactory> localMediaManagerFactoryProvider;

    private Provider<MediaDeviceManager> mediaDeviceManagerProvider;

    private Provider<MediaDataFilter> mediaDataFilterProvider;

    private Provider<MediaDataManager> mediaDataManagerProvider;

    private Provider<NotificationMediaManager> provideNotificationMediaManagerProvider;

    private Provider<KeyguardEnvironmentImpl> keyguardEnvironmentImplProvider;

    private Provider<IndividualSensorPrivacyController> provideIndividualSensorPrivacyControllerProvider;

    private Provider<AppOpsControllerImpl> appOpsControllerImplProvider;

    private Provider<ForegroundServiceController> foregroundServiceControllerProvider;

    private Provider<NotificationFilter> notificationFilterProvider;

    private Provider<NotificationSectionsFeatureManager> notificationSectionsFeatureManagerProvider;

    private Provider<HighPriorityProvider> highPriorityProvider;

    private Provider<NotificationRankingManager> notificationRankingManagerProvider;

    private Provider<TargetSdkResolver> targetSdkResolverProvider;

    private Provider<GroupCoalescerLogger> groupCoalescerLoggerProvider;

    private Provider<GroupCoalescer> groupCoalescerProvider;

    private Provider<CoordinatorsSubcomponent.Factory> coordinatorsSubcomponentFactoryProvider;

    private Provider<NotifCoordinators> notifCoordinatorsProvider;

    private Provider<NotifInflaterImpl> notifInflaterImplProvider;

    private Provider<ShadeViewDifferLogger> shadeViewDifferLoggerProvider;

    private Provider<NotifViewBarn> notifViewBarnProvider;

    private Provider<NotificationWakeUpCoordinator> notificationWakeUpCoordinatorProvider;

    private Provider<DarkIconDispatcherImpl> darkIconDispatcherImplProvider;

    private Provider<StatusBarWindowView> providesStatusBarWindowViewProvider;

    private Provider<StatusBarContentInsetsProvider> statusBarContentInsetsProvider;

    private Provider<StatusBarWindowController> statusBarWindowControllerProvider;

    private Provider<NotificationIconAreaController> notificationIconAreaControllerProvider;

    private Provider<ShadeViewManagerFactory> shadeViewManagerFactoryProvider;

    private Provider<NotifPipelineInitializer> notifPipelineInitializerProvider;

    private Provider<NotifBindPipelineInitializer> notifBindPipelineInitializerProvider;

    private Provider<NotificationGroupAlertTransferHelper> provideNotificationGroupAlertTransferHelperProvider;

    private Provider<HeadsUpViewBinder> headsUpViewBinderProvider;

    private Provider<NotificationInterruptStateProviderImpl> notificationInterruptStateProviderImplProvider;

    private Provider<VisualStabilityManager> provideVisualStabilityManagerProvider;

    private Provider<HeadsUpController> headsUpControllerProvider;

    private Provider<NotificationClickerLogger> notificationClickerLoggerProvider;

    private Provider<NotificationClicker.Builder> builderProvider2;

    private Provider<AnimatedImageNotificationManager> animatedImageNotificationManagerProvider;

    private Provider<PeopleSpaceWidgetManager> peopleSpaceWidgetManagerProvider;

    private Provider<NotificationsControllerImpl> notificationsControllerImplProvider;

    private Provider<NotificationsControllerStub> notificationsControllerStubProvider;

    private Provider<NotificationsController> provideNotificationsControllerProvider;

    private Provider<FragmentService.FragmentCreator.Factory> fragmentCreatorFactoryProvider;

    private Provider<FragmentService> fragmentServiceProvider;

    private Provider<NavigationModeController> navigationModeControllerProvider;

    private Provider<LightBarController> lightBarControllerProvider;

    private Provider<AutoHideController> provideAutoHideControllerProvider;

    private Provider<StatusBarIconControllerImpl> statusBarIconControllerImplProvider;

    private Provider<CarrierConfigTracker> carrierConfigTrackerProvider;

    private Provider<CallbackHandler> callbackHandlerProvider;

    private Provider<TelephonyListenerManager> telephonyListenerManagerProvider;

    private Provider<AccessPointControllerImpl.WifiPickerTrackerFactory> wifiPickerTrackerFactoryProvider;

    private Provider<AccessPointControllerImpl> provideAccessPointControllerImplProvider;

    private Provider<ToastFactory> toastFactoryProvider;

    private Provider<LocationControllerImpl> locationControllerImplProvider;

    private Provider<DialogLaunchAnimator> provideDialogLaunchAnimatorProvider;

    private Provider<InternetDialogController> internetDialogControllerProvider;

    private Provider<InternetDialogFactory> internetDialogFactoryProvider;

    private Provider<NetworkControllerImpl> networkControllerImplProvider;

    private Provider<SecurityControllerImpl> securityControllerImplProvider;

    private Provider<StatusBarSignalPolicy> statusBarSignalPolicyProvider;

    private Provider<NotificationRoundnessManager> notificationRoundnessManagerProvider;

    private Provider<LogBuffer> provideLSShadeTransitionControllerBufferProvider;

    private Provider<LockscreenGestureLogger> lockscreenGestureLoggerProvider;

    private Provider<LSShadeTransitionLogger> lSShadeTransitionLoggerProvider;

    private Provider<MediaHostStatesManager> mediaHostStatesManagerProvider;

    private Provider<MediaViewController> mediaViewControllerProvider;

    private Provider<DelayableExecutor> provideBackgroundDelayableExecutorProvider;

    private Provider<RepeatableExecutor> provideBackgroundRepeatableExecutorProvider;

    private Provider<SeekBarViewModel> seekBarViewModelProvider;

    private Provider<AssistUtils> provideAssistUtilsProvider;

    private Provider<PhoneStateMonitor> phoneStateMonitorProvider;

    private Provider<OverviewProxyService> overviewProxyServiceProvider;

    private Provider<SysUiState> provideSysUiStateProvider;

    private Provider<AccessibilityManagerWrapper> accessibilityManagerWrapperProvider;

    private Provider<AccessibilityButtonModeObserver> accessibilityButtonModeObserverProvider;

    private Provider<AssistManager> assistManagerProvider;

    private Provider<NavBarHelper> navBarHelperProvider;

    private Provider<Optional<Pip>> setPipProvider;

    private Provider<Optional<LegacySplitScreen>> setLegacySplitScreenProvider;

    private Provider<ContextComponentResolver> contextComponentResolverProvider;

    private Provider<RecentsImplementation> provideRecentsImplProvider;

    private Provider<Recents> provideRecentsProvider;

    private Provider<Optional<Recents>> optionalOfRecentsProvider;

    private Provider<ShadeControllerImpl> shadeControllerImplProvider;

    private Provider<BlurUtils> blurUtilsProvider;

    private Provider<LogBuffer> provideDozeLogBufferProvider;

    private Provider<DozeLogger> dozeLoggerProvider;

    private Provider<DozeLog> dozeLogProvider;

    private Provider<DozeScrimController> dozeScrimControllerProvider;

    private Provider<DelayedWakeLock.Builder> builderProvider3;

    private Provider<ScrimController> scrimControllerProvider;

    private Provider<BiometricUnlockController> biometricUnlockControllerProvider;

    private Provider<Choreographer> providesChoreographerProvider;

    private Provider<WallpaperController> wallpaperControllerProvider;

    private Provider<NotificationShadeDepthController> notificationShadeDepthControllerProvider;

    private Provider<SystemActions> systemActionsProvider;

    private Provider<NavigationBarOverlayController> navigationBarOverlayControllerProvider;

    private Provider<LightBarController.Factory> factoryProvider;

    private Provider<AutoHideController.Factory> factoryProvider2;

    private Provider<NavigationBar.Factory> factoryProvider3;

    private Provider<NavigationBarController> navigationBarControllerProvider;

    private Provider<Optional<SplitScreen>> setSplitScreenProvider;

    private Provider<Optional<OneHanded>> setOneHandedProvider;

    private Provider<Optional<RecentTasks>> setRecentTasksProvider;

    private Provider<Optional<StartingSurface>> setStartingSurfaceProvider;

    private Provider<ShellTransitions> setTransitionsProvider;

    private Provider<SmartspaceTransitionController> provideSmartspaceTransitionControllerProvider;

    private Provider<AssistLogger> assistLoggerProvider;

    private Provider<DefaultUiController> defaultUiControllerProvider;

    private Provider<SystemUIDialogManager> systemUIDialogManagerProvider;

    private Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider;

    private Provider<MediaCarouselController> mediaCarouselControllerProvider;

    private Provider<MediaControlPanel> mediaControlPanelProvider;

    private Provider<MediaHierarchyManager> mediaHierarchyManagerProvider;

    private Provider<MediaHost> providesKeyguardMediaHostProvider;

    private Provider<KeyguardMediaController> keyguardMediaControllerProvider;

    private Provider<LogBuffer> provideNotificationSectionLogBufferProvider;

    private Provider<NotificationSectionsLogger> notificationSectionsLoggerProvider;

    private Provider<SectionHeaderControllerSubcomponent.Builder> sectionHeaderControllerSubcomponentBuilderProvider;

    private Provider<SectionHeaderControllerSubcomponent> providesIncomingHeaderSubcomponentProvider;

    private Provider<SectionHeaderController> providesIncomingHeaderControllerProvider;

    private Provider<SectionHeaderControllerSubcomponent> providesPeopleHeaderSubcomponentProvider;

    private Provider<SectionHeaderController> providesPeopleHeaderControllerProvider;

    private Provider<SectionHeaderControllerSubcomponent> providesAlertingHeaderSubcomponentProvider;

    private Provider<SectionHeaderController> providesAlertingHeaderControllerProvider;

    private Provider<SectionHeaderControllerSubcomponent> providesSilentHeaderSubcomponentProvider;

    private Provider<SectionHeaderController> providesSilentHeaderControllerProvider;

    private Provider<NotificationSectionsManager> notificationSectionsManagerProvider;

    private Provider<AmbientState> ambientStateProvider;

    private Provider<LockscreenShadeTransitionController> lockscreenShadeTransitionControllerProvider;

    private Provider<PulseExpansionHandler> pulseExpansionHandlerProvider;

    private Provider<DynamicPrivacyController> dynamicPrivacyControllerProvider;

    private Provider<BypassHeadsUpNotifier> bypassHeadsUpNotifierProvider;

    private Provider<ShadeEventCoordinatorLogger> shadeEventCoordinatorLoggerProvider;

    private Provider<ShadeEventCoordinator> shadeEventCoordinatorProvider;

    private Provider<LegacyNotificationPresenterExtensions> legacyNotificationPresenterExtensionsProvider;

    private Provider<NotifShadeEventSource> provideNotifShadeEventSourceProvider;

    private Provider<INotificationManager> provideINotificationManagerProvider;

    private Provider<ChannelEditorDialogController> channelEditorDialogControllerProvider;

    private Provider<AssistantFeedbackController> assistantFeedbackControllerProvider;

    private Provider<ZenModeControllerImpl> zenModeControllerImplProvider;

    private Provider<Optional<BubblesManager>> provideBubblesManagerProvider;

    private Provider<DelayableExecutor> provideDelayableExecutorProvider;

    private Provider<VisualStabilityCoordinator> visualStabilityCoordinatorProvider;

    private Provider<OnUserInteractionCallback> provideOnUserInteractionCallbackProvider;

    private Provider<NotificationGutsManager> provideNotificationGutsManagerProvider;

    private Provider<NotificationLogger.ExpansionStateLogger> expansionStateLoggerProvider;

    private Provider<NotificationPanelLogger> provideNotificationPanelLoggerProvider;

    private Provider<NotificationLogger> provideNotificationLoggerProvider;

    private Provider<ForegroundServiceSectionController> foregroundServiceSectionControllerProvider;

    private Provider<DynamicChildBindController> dynamicChildBindControllerProvider;

    private Provider<NotificationViewHierarchyManager> provideNotificationViewHierarchyManagerProvider;

    private Provider<UserSwitcherController> userSwitcherControllerProvider;

    private Provider<AccessibilityButtonTargetsObserver> accessibilityButtonTargetsObserverProvider;

    private Provider<AccessibilityFloatingMenuController> provideAccessibilityFloatingMenuControllerProvider;

    private Provider<LockscreenWallpaper> lockscreenWallpaperProvider;

    private Provider<DozeServiceHost> dozeServiceHostProvider;

    private Provider<ScreenPinningRequest> screenPinningRequestProvider;

    private Provider<VolumeDialogControllerImpl> volumeDialogControllerImplProvider;

    private Provider<VolumeDialog> provideVolumeDialogProvider;

    private Provider<VolumeDialogComponent> volumeDialogComponentProvider;

    private Provider<LogBuffer> provideCollapsedSbFragmentLogBufferProvider;

    private Provider<DisableFlagsLogger> disableFlagsLoggerProvider;

    private Provider<CollapsedStatusBarFragmentLogger> collapsedStatusBarFragmentLoggerProvider;

    private Provider<StatusBarComponent.Factory> statusBarComponentFactoryProvider;

    private Provider<LightsOutNotifController> lightsOutNotifControllerProvider;

    private Provider<GroupExpansionManager> provideGroupExpansionManagerProvider;

    private Provider<StatusBarRemoteInputCallback> statusBarRemoteInputCallbackProvider;

    private Provider<ActivityIntentHelper> activityIntentHelperProvider;

    private Provider<StatusBarNotificationActivityStarterLogger> statusBarNotificationActivityStarterLoggerProvider;

    private Provider<StatusBarNotificationActivityStarter.Builder> builderProvider4;

    private Provider<ViewMediatorCallback> providesViewMediatorCallbackProvider;

    private Provider<InitController> initControllerProvider;

    private Provider<Handler> provideTimeTickHandlerProvider;

    private Provider<UserInfoControllerImpl> userInfoControllerImplProvider;

    private Provider<OperatorNameViewController.Factory> factoryProvider4;

    private Provider<CastControllerImpl> castControllerImplProvider;

    private Provider<HotspotControllerImpl> hotspotControllerImplProvider;

    private Provider<BluetoothControllerImpl> bluetoothControllerImplProvider;

    private Provider<NextAlarmControllerImpl> nextAlarmControllerImplProvider;

    private Provider<RotationPolicyWrapperImpl> rotationPolicyWrapperImplProvider;

    private Provider<RotationPolicyWrapper> bindRotationPolicyWrapperProvider;

    private Provider<String[]> providesDeviceStateRotationLockDefaultsProvider;

    private Provider<DeviceStateRotationLockSettingController> deviceStateRotationLockSettingControllerProvider;

    private Provider<RotationLockControllerImpl> rotationLockControllerImplProvider;

    private Provider<DataSaverController> provideDataSaverControllerProvider;

    private Provider<SensorPrivacyController> provideSensorPrivacyControllerProvider;

    private Provider<RecordingController> recordingControllerProvider;

    private Provider<SharedPreferences> provideSharePreferencesProvider;

    private Provider<DateFormatUtil> dateFormatUtilProvider;

    private Provider<LogBuffer> providePrivacyLogBufferProvider;

    private Provider<PrivacyLogger> privacyLoggerProvider;

    private Provider<PrivacyItemController> privacyItemControllerProvider;

    private Provider<PhoneStatusBarPolicy> phoneStatusBarPolicyProvider;

    private Provider<WakeLock.Builder> builderProvider5;

    private Provider<KeyguardIndicationController> keyguardIndicationControllerProvider;

    private Provider<StatusBarTouchableRegionManager> statusBarTouchableRegionManagerProvider;

    private Provider<BrightnessSliderController.Factory> factoryProvider5;

    private Provider<WiredChargingRippleController> wiredChargingRippleControllerProvider;

    private Provider<OngoingCallLogger> ongoingCallLoggerProvider;

    private Provider<LogBuffer> provideSwipeAwayGestureLogBufferProvider;

    private Provider<SwipeStatusBarAwayGestureLogger> swipeStatusBarAwayGestureLoggerProvider;

    private Provider<SwipeStatusBarAwayGestureHandler> swipeStatusBarAwayGestureHandlerProvider;

    private Provider<OngoingCallController> provideOngoingCallControllerProvider;

    private Provider<SystemEventCoordinator> systemEventCoordinatorProvider;

    private Provider<StatusBarLocationPublisher> statusBarLocationPublisherProvider;

    private Provider<SystemEventChipAnimationController> systemEventChipAnimationControllerProvider;

    private Provider<SystemStatusAnimationScheduler> systemStatusAnimationSchedulerProvider;

    private Provider<StatusBarHideIconsForBouncerManager> statusBarHideIconsForBouncerManagerProvider;

    private Provider<KeyguardUnlockAnimationController> keyguardUnlockAnimationControllerProvider;

    private Provider<MessageRouter> providesMainMessageRouterProvider;

    private Provider<ActivityLaunchAnimator> provideActivityLaunchAnimatorProvider;

    private Provider<StatusBar> provideStatusBarProvider;

    private Provider<ActivityStarterDelegate> activityStarterDelegateProvider;

    private Provider<UserDetailView.Adapter> adapterProvider;

    private Provider<UserSwitcherController.UserDetailAdapter> userDetailAdapterProvider;

    private Provider<KeyguardStatusViewComponent.Factory> keyguardStatusViewComponentFactoryProvider;

    private Provider<KeyguardDisplayManager> keyguardDisplayManagerProvider;

    private Provider<SysUIUnfoldComponent.Factory> sysUIUnfoldComponentFactoryProvider;

    private Provider<Optional<SysUIUnfoldComponent>> provideSysUIUnfoldComponentProvider;

    private Provider<KeyguardSecurityModel> keyguardSecurityModelProvider;

    private Provider<KeyguardBouncerComponent.Factory> keyguardBouncerComponentFactoryProvider;

    private Provider<KeyguardBouncer.Factory> factoryProvider6;

    private Provider<KeyguardMessageAreaController.Factory> factoryProvider7;

    private Provider<UdfpsHapticsSimulator> udfpsHapticsSimulatorProvider;

    private Provider<Optional<UdfpsHbmProvider>> optionalOfUdfpsHbmProvider;

    private Provider<UdfpsController> udfpsControllerProvider;

    private Provider<SidefpsController> sidefpsControllerProvider;

    private Provider<BrightLineFalsingManager> brightLineFalsingManagerProvider;

    private Provider<BrightnessDialog> brightnessDialogProvider;

    private Provider<UsbDebuggingActivity> usbDebuggingActivityProvider;

    private Provider<UsbDebuggingSecondaryUserActivity> usbDebuggingSecondaryUserActivityProvider;

    private Provider<UserCreator> userCreatorProvider;

    private Provider<EditUserInfoController> provideEditUserInfoControllerProvider;

    private Provider<CreateUserActivity> createUserActivityProvider;

    private Provider<TvNotificationHandler> tvNotificationHandlerProvider;

    private Provider<TvNotificationPanelActivity> tvNotificationPanelActivityProvider;

    private Provider<PeopleSpaceActivity> peopleSpaceActivityProvider;

    @SuppressWarnings("rawtypes")
    private Provider imageExporterProvider;

    private Provider<LongScreenshotData> longScreenshotDataProvider;

    private Provider<LongScreenshotActivity> longScreenshotActivityProvider;

    private Provider<LaunchConversationActivity> launchConversationActivityProvider;

    private Provider<SensorUseStartedActivity> sensorUseStartedActivityProvider;

    private Provider<TvUnblockSensorActivity> tvUnblockSensorActivityProvider;

    private Provider<Executor> provideExecutorProvider;

    private Provider<ControlsListingControllerImpl> controlsListingControllerImplProvider;

    private Provider<ControlsControllerImpl> controlsControllerImplProvider;

    private Provider<GlobalActionsComponent> globalActionsComponentProvider;

    private Provider<Boolean> providesControlsFeatureEnabledProvider;

    private Provider<ControlsUiControllerImpl> controlsUiControllerImplProvider;

    private Provider<ControlsComponent> controlsComponentProvider;

    private Provider<GlobalActionsDialogLite> globalActionsDialogLiteProvider;

    private Provider<GlobalActionsImpl> globalActionsImplProvider;

    private Provider<Optional<TaskViewFactory>> setTaskViewFactoryProvider;

    private Provider<ControlsMetricsLoggerImpl> controlsMetricsLoggerImplProvider;

    private Provider<ControlActionCoordinatorImpl> controlActionCoordinatorImplProvider;

    private Provider<CustomIconCache> customIconCacheProvider;

    private Provider<ControlsBindingControllerImpl> controlsBindingControllerImplProvider;

    private Provider<Optional<ControlsFavoritePersistenceWrapper>> optionalOfControlsFavoritePersistenceWrapperProvider;

    private Provider<ControlsProviderSelectorActivity> controlsProviderSelectorActivityProvider;

    private Provider<ControlsFavoritingActivity> controlsFavoritingActivityProvider;

    private Provider<ControlsEditingActivity> controlsEditingActivityProvider;

    private Provider<ControlsRequestDialog> controlsRequestDialogProvider;

    private Provider<ControlsActivity> controlsActivityProvider;

    private Provider<WalletActivity> walletActivityProvider;

    private Provider<Map<Class<?>, Provider<Activity>>> mapOfClassOfAndProviderOfActivityProvider;

    private Provider<DozeComponent.Builder> dozeComponentBuilderProvider;

    private Provider<DozeService> dozeServiceProvider;

    private Provider<KeyguardLifecyclesDispatcher> keyguardLifecyclesDispatcherProvider;

    private Provider<KeyguardService> keyguardServiceProvider;

    private Provider<DumpHandler> dumpHandlerProvider;

    private Provider<LogBufferFreezer> logBufferFreezerProvider;

    private Provider<BatteryStateNotifier> batteryStateNotifierProvider;

    private Provider<SystemUIService> systemUIServiceProvider;

    private Provider<SystemUIAuxiliaryDumpService> systemUIAuxiliaryDumpServiceProvider;

    private Provider<Looper> provideLongRunningLooperProvider;

    private Provider<Executor> provideLongRunningExecutorProvider;

    private Provider<RecordingService> recordingServiceProvider;

    private Provider<ScreenshotSmartActions> screenshotSmartActionsProvider;

    private Provider<ScreenshotNotificationsController> screenshotNotificationsControllerProvider;

    private Provider<ScrollCaptureClient> scrollCaptureClientProvider;

    @SuppressWarnings("rawtypes")
    private Provider imageTileSetProvider;

    private Provider<ScrollCaptureController> scrollCaptureControllerProvider;

    private Provider<ScreenshotController> screenshotControllerProvider;

    private Provider<TakeScreenshotService> takeScreenshotServiceProvider;

    private Provider<Map<Class<?>, Provider<Service>>> mapOfClassOfAndProviderOfServiceProvider;

    private Provider<MessageRouter> providesBackgroundMessageRouterProvider;

    private Provider<String> provideLeakReportEmailProvider;

    private Provider<LeakReporter> leakReporterProvider;

    private Provider<GarbageMonitor> garbageMonitorProvider;

    private Provider<GarbageMonitor.Service> serviceProvider;

    private Provider<InstantAppNotifier> instantAppNotifierProvider;

    private Provider<LatencyTester> latencyTesterProvider;

    private Provider<PowerUI> powerUIProvider;

    private Provider<PrivacyDotViewController> privacyDotViewControllerProvider;

    private Provider<ScreenDecorations> screenDecorationsProvider;

    private Provider<ShortcutKeyDispatcher> shortcutKeyDispatcherProvider;

    private Provider<SliceBroadcastRelayHandler> sliceBroadcastRelayHandlerProvider;

    private Provider<ThemeOverlayApplier> provideThemeOverlayManagerProvider;

    @SuppressWarnings("rawtypes")
    private Provider systemSettingsImplProvider;

    private Provider<ThemeOverlayController> themeOverlayControllerProvider;

    private Provider<LogBuffer> provideToastLogBufferProvider;

    private Provider<ToastLogger> toastLoggerProvider;

    private Provider<ToastUI> toastUIProvider;

    private Provider<TvStatusBar> tvStatusBarProvider;

    private Provider<TvNotificationPanel> tvNotificationPanelProvider;

    private Provider<TvOngoingPrivacyChip> tvOngoingPrivacyChipProvider;

    private Provider<VolumeUI> volumeUIProvider;

    private Provider<ModeSwitchesController> providesModeSwitchesControllerProvider;

    private Provider<WindowMagnification> windowMagnificationProvider;

    private Provider<Optional<HideDisplayCutout>> setHideDisplayCutoutProvider;

    private Provider<Optional<ShellCommandHandler>> setShellCommandHandlerProvider;

    private Provider<Optional<CompatUI>> setCompatUIProvider;

    private Provider<Optional<DragAndDrop>> setDragAndDropProvider;

    private Provider<WMShell> wMShellProvider;

    private Provider<TaskStackChangeListeners> provideTaskStackChangeListenersProvider;

    private Provider<HomeSoundEffectController> homeSoundEffectControllerProvider;

    private Provider<Map<Class<?>, Provider<SystemUI>>> mapOfClassOfAndProviderOfSystemUIProvider;

    private Provider<OverviewProxyRecentsImpl> overviewProxyRecentsImplProvider;

    private Provider<Map<Class<?>, Provider<RecentsImplementation>>> mapOfClassOfAndProviderOfRecentsImplementationProvider;

    private Provider<ActionProxyReceiver> actionProxyReceiverProvider;

    private Provider<DeleteScreenshotReceiver> deleteScreenshotReceiverProvider;

    private Provider<SmartActionsReceiver> smartActionsReceiverProvider;

    private Provider<MediaOutputDialogReceiver> mediaOutputDialogReceiverProvider;

    private Provider<PeopleSpaceWidgetPinnedReceiver> peopleSpaceWidgetPinnedReceiverProvider;

    private Provider<PeopleSpaceWidgetProvider> peopleSpaceWidgetProvider;

    private Provider<Map<Class<?>, Provider<BroadcastReceiver>>> mapOfClassOfAndProviderOfBroadcastReceiverProvider;

    private Provider<FlashlightControllerImpl> flashlightControllerImplProvider;

    private Provider<NightDisplayListener> provideNightDisplayListenerProvider;

    private Provider<ReduceBrightColorsController> provideReduceBrightColorsListenerProvider;

    private Provider<ManagedProfileControllerImpl> managedProfileControllerImplProvider;

    private Provider<AccessibilityController> accessibilityControllerProvider;

    private Provider<TunablePadding.TunablePaddingService> tunablePaddingServiceProvider;

    private Provider<UiOffloadThread> uiOffloadThreadProvider;

    private Provider<PowerNotificationWarnings> powerNotificationWarningsProvider;

    private Provider<VibratorHelper> vibratorHelperProvider;

    private Provider<RemoteInputQuickSettingsDisabler> remoteInputQuickSettingsDisablerProvider;

    private Provider<ForegroundServiceNotificationListener> foregroundServiceNotificationListenerProvider;

    private Provider<ClockManager> clockManagerProvider;

    private Provider<EdgeBackGestureHandler.Factory> factoryProvider8;

    private Provider<Dependency> dependencyProvider2;

    @SuppressWarnings("rawtypes")
    private Provider provideClockInfoListProvider;

    private Provider<Boolean> provideAllowNotificationLongPressProvider;

    private Provider<NodeController> providesAlertingHeaderNodeControllerProvider;

    private Provider<NodeController> providesSilentHeaderNodeControllerProvider;

    private Provider<NodeController> providesIncomingHeaderNodeControllerProvider;

    private Provider<NotifGutsViewManager> provideNotifGutsViewManagerProvider;

    private Provider<NodeController> providesPeopleHeaderNodeControllerProvider;

    private Provider<PreparationCoordinatorLogger> preparationCoordinatorLoggerProvider;

    private Provider<PreparationCoordinator> preparationCoordinatorProvider;

    private Provider<RemoteInputCoordinator> remoteInputCoordinatorProvider;

    private Provider<Optional<BcSmartspaceDataPlugin>> optionalOfBcSmartspaceDataPluginProvider;

    private Provider<LockscreenSmartspaceController> lockscreenSmartspaceControllerProvider;

    private Provider<QSTileHost> qSTileHostProvider;

    private Provider<LogBuffer> provideQuickSettingsLogBufferProvider;

    private Provider<QSLogger> qSLoggerProvider;

    private Provider<CustomTileStatePersister> customTileStatePersisterProvider;

    private Provider<CustomTile.Builder> builderProvider6;

    private Provider<WifiTile> wifiTileProvider;

    private Provider<InternetTile> internetTileProvider;

    private Provider<BluetoothTile> bluetoothTileProvider;

    private Provider<CellularTile> cellularTileProvider;

    private Provider<DndTile> dndTileProvider;

    private Provider<ColorInversionTile> colorInversionTileProvider;

    private Provider<AirplaneModeTile> airplaneModeTileProvider;

    private Provider<WorkModeTile> workModeTileProvider;

    private Provider<RotationLockTile> rotationLockTileProvider;

    private Provider<FlashlightTile> flashlightTileProvider;

    private Provider<LocationTile> locationTileProvider;

    private Provider<CastTile> castTileProvider;

    private Provider<HotspotTile> hotspotTileProvider;

    private Provider<UserTile> userTileProvider;

    private Provider<BatterySaverTile> batterySaverTileProvider;

    private Provider<DataSaverTile> dataSaverTileProvider;

    private Provider<NightDisplayListenerModule.Builder> builderProvider7;

    private Provider<NightDisplayTile> nightDisplayTileProvider;

    private Provider<NfcTile> nfcTileProvider;

    private Provider<GarbageMonitor.MemoryTile> memoryTileProvider;

    private Provider<UiModeNightTile> uiModeNightTileProvider;

    private Provider<ScreenRecordTile> screenRecordTileProvider;

    private Provider<Boolean> isReduceBrightColorsAvailableProvider;

    private Provider<ReduceBrightColorsTile> reduceBrightColorsTileProvider;

    private Provider<CameraToggleTile> cameraToggleTileProvider;

    private Provider<MicrophoneToggleTile> microphoneToggleTileProvider;

    private Provider<DeviceControlsTile> deviceControlsTileProvider;

    private Provider<AlarmTile> alarmTileProvider;

    private Provider<QuickAccessWalletClient> provideQuickAccessWalletClientProvider;

    private Provider<QuickAccessWalletController> quickAccessWalletControllerProvider;

    private Provider<QuickAccessWalletTile> quickAccessWalletTileProvider;

    private Provider<AmbientDisplayTile> ambientDisplayTileProvider;

    private Provider<AODTile> aODTileProvider;

    private Provider<CaffeineTile> caffeineTileProvider;

    private Provider<HeadsUpTile> headsUpTileProvider;

    private Provider<PowerShareTile> powerShareTileProvider;

    private Provider<ProfilesTile> profilesTileProvider;

    private Provider<ReadingModeTile> readingModeTileProvider;

    private Provider<SyncTile> syncTileProvider;

    private Provider<UsbTetherTile> usbTetherTileProvider;

    private Provider<VpnTile> vpnTileProvider;

    private Provider<QSFactoryImpl> qSFactoryImplProvider;

    private Provider<AutoAddTracker.Builder> builderProvider8;

    private Provider<DeviceControlsControllerImpl> deviceControlsControllerImplProvider;

    private Provider<WalletControllerImpl> walletControllerImplProvider;

    private Provider<AutoTileManager> provideAutoTileManagerProvider;

    private Provider<QSDetailDisplayer> qSDetailDisplayerProvider;

    private Provider<MediaHost> providesQSMediaHostProvider;

    private Provider<MediaHost> providesQuickQSMediaHostProvider;

    private Provider<LogBuffer> provideQSFragmentDisableLogBufferProvider;

    private Provider<NotificationShelfComponent.Builder> notificationShelfComponentBuilderProvider;

    private Provider<KeyguardQsUserSwitchComponent.Factory> keyguardQsUserSwitchComponentFactoryProvider;

    private Provider<KeyguardUserSwitcherComponent.Factory> keyguardUserSwitcherComponentFactoryProvider;

    private Provider<KeyguardStatusBarViewComponent.Factory> keyguardStatusBarViewComponentFactoryProvider;

    private Provider<PrivacyDialogController> privacyDialogControllerProvider;

    private Provider<QSCarrierGroupController.SubscriptionManagerSlotIndexResolver> subscriptionManagerSlotIndexResolverProvider;

    private Provider<Optional<DisplayAreaHelper>> setDisplayAreaHelperProvider;

    private Provider<ProximityCheck> provideProximityCheckProvider;

    private Provider<UserSwitchDialogController> userSwitchDialogControllerProvider;

    private Provider<Boolean> isPMLiteEnabledProvider;

    private Provider<StatusBarIconController.TintedIconManager.Factory> factoryProvider9;

    private SysUIComponentImpl(DependencyProvider dependencyProviderParam,
        NightDisplayListenerModule nightDisplayListenerModuleParam,
        SysUIUnfoldModule sysUIUnfoldModuleParam, UserModule userModuleParam,
        Optional<Pip> setPipParam, Optional<LegacySplitScreen> setLegacySplitScreenParam,
        Optional<SplitScreen> setSplitScreenParam, Optional<AppPairs> setAppPairs,
        Optional<OneHanded> setOneHandedParam, Optional<Bubbles> setBubblesParam,
        Optional<TaskViewFactory> setTaskViewFactoryParam,
        Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        Optional<ShellCommandHandler> setShellCommandHandlerParam,
        ShellTransitions setTransitionsParam, Optional<StartingSurface> setStartingSurfaceParam,
        Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        Optional<TaskSurfaceHelper> setTaskSurfaceHelper, Optional<RecentTasks> setRecentTasksParam,
        Optional<CompatUI> setCompatUIParam, Optional<DragAndDrop> setDragAndDropParam) {

      initialize(dependencyProviderParam, nightDisplayListenerModuleParam, sysUIUnfoldModuleParam, userModuleParam, setPipParam, setLegacySplitScreenParam, setSplitScreenParam, setAppPairs, setOneHandedParam, setBubblesParam, setTaskViewFactoryParam, setHideDisplayCutoutParam, setShellCommandHandlerParam, setTransitionsParam, setStartingSurfaceParam, setDisplayAreaHelperParam, setTaskSurfaceHelper, setRecentTasksParam, setCompatUIParam, setDragAndDropParam);
      initialize2(dependencyProviderParam, nightDisplayListenerModuleParam, sysUIUnfoldModuleParam, userModuleParam, setPipParam, setLegacySplitScreenParam, setSplitScreenParam, setAppPairs, setOneHandedParam, setBubblesParam, setTaskViewFactoryParam, setHideDisplayCutoutParam, setShellCommandHandlerParam, setTransitionsParam, setStartingSurfaceParam, setDisplayAreaHelperParam, setTaskSurfaceHelper, setRecentTasksParam, setCompatUIParam, setDragAndDropParam);
      initialize3(dependencyProviderParam, nightDisplayListenerModuleParam, sysUIUnfoldModuleParam, userModuleParam, setPipParam, setLegacySplitScreenParam, setSplitScreenParam, setAppPairs, setOneHandedParam, setBubblesParam, setTaskViewFactoryParam, setHideDisplayCutoutParam, setShellCommandHandlerParam, setTransitionsParam, setStartingSurfaceParam, setDisplayAreaHelperParam, setTaskSurfaceHelper, setRecentTasksParam, setCompatUIParam, setDragAndDropParam);
      initialize4(dependencyProviderParam, nightDisplayListenerModuleParam, sysUIUnfoldModuleParam, userModuleParam, setPipParam, setLegacySplitScreenParam, setSplitScreenParam, setAppPairs, setOneHandedParam, setBubblesParam, setTaskViewFactoryParam, setHideDisplayCutoutParam, setShellCommandHandlerParam, setTransitionsParam, setStartingSurfaceParam, setDisplayAreaHelperParam, setTaskSurfaceHelper, setRecentTasksParam, setCompatUIParam, setDragAndDropParam);
      initialize5(dependencyProviderParam, nightDisplayListenerModuleParam, sysUIUnfoldModuleParam, userModuleParam, setPipParam, setLegacySplitScreenParam, setSplitScreenParam, setAppPairs, setOneHandedParam, setBubblesParam, setTaskViewFactoryParam, setHideDisplayCutoutParam, setShellCommandHandlerParam, setTransitionsParam, setStartingSurfaceParam, setDisplayAreaHelperParam, setTaskSurfaceHelper, setRecentTasksParam, setCompatUIParam, setDragAndDropParam);
      initialize6(dependencyProviderParam, nightDisplayListenerModuleParam, sysUIUnfoldModuleParam, userModuleParam, setPipParam, setLegacySplitScreenParam, setSplitScreenParam, setAppPairs, setOneHandedParam, setBubblesParam, setTaskViewFactoryParam, setHideDisplayCutoutParam, setShellCommandHandlerParam, setTransitionsParam, setStartingSurfaceParam, setDisplayAreaHelperParam, setTaskSurfaceHelper, setRecentTasksParam, setCompatUIParam, setDragAndDropParam);
    }

    private CollapsedStatusBarFragmentLogger collapsedStatusBarFragmentLogger() {
      return new CollapsedStatusBarFragmentLogger(provideCollapsedSbFragmentLogBufferProvider.get(), disableFlagsLoggerProvider.get());
    }

    private OperatorNameViewController.Factory operatorNameViewControllerFactory() {
      return new OperatorNameViewController.Factory(darkIconDispatcherImplProvider.get(), networkControllerImplProvider.get(), tunerServiceImplProvider.get(), DaggerGlobalRootComponent.this.provideTelephonyManagerProvider.get(), keyguardUpdateMonitorProvider.get());
    }

    private Object secureSettingsImpl() {
      return SecureSettingsImpl_Factory.newInstance(DaggerGlobalRootComponent.this.provideContentResolverProvider.get());
    }

    @SuppressWarnings("unchecked")
    private void initialize(final DependencyProvider dependencyProviderParam,
        final NightDisplayListenerModule nightDisplayListenerModuleParam,
        final SysUIUnfoldModule sysUIUnfoldModuleParam, final UserModule userModuleParam,
        final Optional<Pip> setPipParam,
        final Optional<LegacySplitScreen> setLegacySplitScreenParam,
        final Optional<SplitScreen> setSplitScreenParam, final Optional<AppPairs> setAppPairs,
        final Optional<OneHanded> setOneHandedParam, final Optional<Bubbles> setBubblesParam,
        final Optional<TaskViewFactory> setTaskViewFactoryParam,
        final Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        final Optional<ShellCommandHandler> setShellCommandHandlerParam,
        final ShellTransitions setTransitionsParam,
        final Optional<StartingSurface> setStartingSurfaceParam,
        final Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        final Optional<TaskSurfaceHelper> setTaskSurfaceHelper,
        final Optional<RecentTasks> setRecentTasksParam, final Optional<CompatUI> setCompatUIParam,
        final Optional<DragAndDrop> setDragAndDropParam) {
      this.bootCompleteCacheImplProvider = DoubleCheck.provider(BootCompleteCacheImpl_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideConfigurationControllerProvider = DoubleCheck.provider(DependencyProvider_ProvideConfigurationControllerFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider));
      this.globalSettingsImplProvider = GlobalSettingsImpl_Factory.create(DaggerGlobalRootComponent.this.provideContentResolverProvider);
      this.provideDemoModeControllerProvider = DoubleCheck.provider(DemoModeModule_ProvideDemoModeControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, globalSettingsImplProvider));
      this.provideLeakDetectorProvider = DoubleCheck.provider(DependencyProvider_ProvideLeakDetectorFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideBgLooperProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideBgLooperFactory.create());
      this.provideBgHandlerProvider = SysUIConcurrencyModule_ProvideBgHandlerFactory.create(provideBgLooperProvider);
      this.provideUserTrackerProvider = DoubleCheck.provider(SettingsModule_ProvideUserTrackerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideBgHandlerProvider));
      this.tunerServiceImplProvider = DoubleCheck.provider(TunerServiceImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideLeakDetectorProvider, provideDemoModeControllerProvider, provideUserTrackerProvider));
      this.tunerActivityProvider = TunerActivity_Factory.create(provideDemoModeControllerProvider, (Provider) tunerServiceImplProvider);
      this.provideBackgroundExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideBackgroundExecutorFactory.create(provideBgLooperProvider));
      this.provideLogcatEchoTrackerProvider = DoubleCheck.provider(LogModule_ProvideLogcatEchoTrackerFactory.create(DaggerGlobalRootComponent.this.provideContentResolverProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create()));
      this.logBufferFactoryProvider = DoubleCheck.provider(LogBufferFactory_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, provideLogcatEchoTrackerProvider));
      this.provideBroadcastDispatcherLogBufferProvider = DoubleCheck.provider(LogModule_ProvideBroadcastDispatcherLogBufferFactory.create(logBufferFactoryProvider));
      this.broadcastDispatcherLoggerProvider = BroadcastDispatcherLogger_Factory.create(provideBroadcastDispatcherLogBufferProvider);
      this.providesBroadcastDispatcherProvider = DoubleCheck.provider(DependencyProvider_ProvidesBroadcastDispatcherFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider, provideBgLooperProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, broadcastDispatcherLoggerProvider, provideUserTrackerProvider));
      this.workLockActivityProvider = WorkLockActivity_Factory.create(providesBroadcastDispatcherProvider);
      this.deviceConfigProxyProvider = DoubleCheck.provider(DeviceConfigProxy_Factory.create());
      this.enhancedEstimatesImplProvider = DoubleCheck.provider(EnhancedEstimatesImpl_Factory.create());
      this.provideBatteryControllerProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideBatteryControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) enhancedEstimatesImplProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, providesBroadcastDispatcherProvider, provideDemoModeControllerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBgHandlerProvider));
      this.dockManagerImplProvider = DoubleCheck.provider(DockManagerImpl_Factory.create());
      this.falsingDataProvider = DoubleCheck.provider(FalsingDataProvider_Factory.create(DaggerGlobalRootComponent.this.provideDisplayMetricsProvider, provideBatteryControllerProvider, (Provider) dockManagerImplProvider));
      this.provideMetricsLoggerProvider = DoubleCheck.provider(DependencyProvider_ProvideMetricsLoggerFactory.create(dependencyProviderParam));
      this.distanceClassifierProvider = DistanceClassifier_Factory.create(falsingDataProvider, deviceConfigProxyProvider);
      this.proximityClassifierProvider = ProximityClassifier_Factory.create(distanceClassifierProvider, falsingDataProvider, deviceConfigProxyProvider);
      this.pointerCountClassifierProvider = PointerCountClassifier_Factory.create(falsingDataProvider);
      this.typeClassifierProvider = TypeClassifier_Factory.create(falsingDataProvider);
      this.diagonalClassifierProvider = DiagonalClassifier_Factory.create(falsingDataProvider, deviceConfigProxyProvider);
      this.zigZagClassifierProvider = ZigZagClassifier_Factory.create(falsingDataProvider, deviceConfigProxyProvider);
      this.providesBrightLineGestureClassifiersProvider = FalsingModule_ProvidesBrightLineGestureClassifiersFactory.create(distanceClassifierProvider, proximityClassifierProvider, pointerCountClassifierProvider, typeClassifierProvider, diagonalClassifierProvider, zigZagClassifierProvider);
      this.namedSetOfFalsingClassifierProvider = SetFactory.<FalsingClassifier>builder(0, 1).addCollectionProvider(providesBrightLineGestureClassifiersProvider).build();
      this.providesSingleTapTouchSlopProvider = FalsingModule_ProvidesSingleTapTouchSlopFactory.create(DaggerGlobalRootComponent.this.provideViewConfigurationProvider);
      this.singleTapClassifierProvider = SingleTapClassifier_Factory.create(falsingDataProvider, providesSingleTapTouchSlopProvider);
      this.providesDoubleTapTouchSlopProvider = FalsingModule_ProvidesDoubleTapTouchSlopFactory.create(DaggerGlobalRootComponent.this.provideResourcesProvider);
      this.doubleTapClassifierProvider = DoubleTapClassifier_Factory.create(falsingDataProvider, singleTapClassifierProvider, providesDoubleTapTouchSlopProvider, FalsingModule_ProvidesDoubleTapTimeoutMsFactory.create());
      this.bindSystemClockProvider = DoubleCheck.provider((Provider) SystemClockImpl_Factory.create());
      this.historyTrackerProvider = DoubleCheck.provider(HistoryTracker_Factory.create(bindSystemClockProvider));
      this.ringerModeTrackerImplProvider = DoubleCheck.provider(RingerModeTrackerImpl_Factory.create(DaggerGlobalRootComponent.this.provideAudioManagerProvider, providesBroadcastDispatcherProvider, provideBackgroundExecutorProvider));
      this.statusBarStateControllerImplProvider = DoubleCheck.provider(StatusBarStateControllerImpl_Factory.create(DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideLockPatternUtilsProvider = DoubleCheck.provider(DependencyProvider_ProvideLockPatternUtilsFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider));
      this.protoTracerProvider = DoubleCheck.provider(ProtoTracer_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.commandRegistryProvider = DoubleCheck.provider(CommandRegistry_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.provideCommandQueueProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideCommandQueueFactory.create(DaggerGlobalRootComponent.this.contextProvider, protoTracerProvider, commandRegistryProvider));
      this.providerLayoutInflaterProvider = DoubleCheck.provider(DependencyProvider_ProviderLayoutInflaterFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider));
      this.panelExpansionStateManagerProvider = DoubleCheck.provider(PanelExpansionStateManager_Factory.create());
      this.falsingManagerProxyProvider = new DelegateFactory<>();
      this.keyguardUpdateMonitorProvider = new DelegateFactory<>();
      this.asyncSensorManagerProvider = DoubleCheck.provider(AsyncSensorManager_Factory.create(DaggerGlobalRootComponent.this.providesSensorManagerProvider, (Provider) ThreadFactoryImpl_Factory.create(), DaggerGlobalRootComponent.this.providesPluginManagerProvider));
      this.builderFactoryProvider = ThresholdSensorImpl_BuilderFactory_Factory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, asyncSensorManagerProvider, DaggerGlobalRootComponent.this.provideExecutionProvider);
      this.providePostureToProximitySensorMappingProvider = SensorModule_ProvidePostureToProximitySensorMappingFactory.create(builderFactoryProvider, DaggerGlobalRootComponent.this.provideResourcesProvider);
      this.providePostureToSecondaryProximitySensorMappingProvider = SensorModule_ProvidePostureToSecondaryProximitySensorMappingFactory.create(builderFactoryProvider, DaggerGlobalRootComponent.this.provideResourcesProvider);
      this.devicePostureControllerImplProvider = DoubleCheck.provider(DevicePostureControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideDeviceStateManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.postureDependentProximitySensorProvider = PostureDependentProximitySensor_Factory.create(providePostureToProximitySensorMappingProvider, providePostureToSecondaryProximitySensorMappingProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideExecutionProvider, (Provider) devicePostureControllerImplProvider);
      this.builderProvider = ThresholdSensorImpl_Builder_Factory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, asyncSensorManagerProvider, DaggerGlobalRootComponent.this.provideExecutionProvider);
      this.providePrimaryProximitySensorProvider = SensorModule_ProvidePrimaryProximitySensorFactory.create(DaggerGlobalRootComponent.this.providesSensorManagerProvider, builderProvider);
      this.provideSecondaryProximitySensorProvider = SensorModule_ProvideSecondaryProximitySensorFactory.create(builderProvider);
      this.proximitySensorImplProvider = ProximitySensorImpl_Factory.create(providePrimaryProximitySensorProvider, provideSecondaryProximitySensorProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideExecutionProvider);
      this.provideProximitySensorProvider = SensorModule_ProvideProximitySensorFactory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, postureDependentProximitySensorProvider, proximitySensorImplProvider);
      this.keyguardStateControllerImplProvider = new DelegateFactory<>();
      this.falsingCollectorImplProvider = DoubleCheck.provider(FalsingCollectorImpl_Factory.create(falsingDataProvider, (Provider) falsingManagerProxyProvider, keyguardUpdateMonitorProvider, historyTrackerProvider, provideProximitySensorProvider, (Provider) statusBarStateControllerImplProvider, (Provider) keyguardStateControllerImplProvider, provideBatteryControllerProvider, (Provider) dockManagerImplProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, bindSystemClockProvider));
      this.statusBarKeyguardViewManagerProvider = new DelegateFactory<>();
      this.provideUiBackgroundExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideUiBackgroundExecutorFactory.create());
      this.dismissCallbackRegistryProvider = DoubleCheck.provider(DismissCallbackRegistry_Factory.create(provideUiBackgroundExecutorProvider));
      this.secureSettingsImplProvider = SecureSettingsImpl_Factory.create(DaggerGlobalRootComponent.this.provideContentResolverProvider);
      this.deviceProvisionedControllerImplProvider = DoubleCheck.provider(DeviceProvisionedControllerImpl_Factory.create(secureSettingsImplProvider, globalSettingsImplProvider, provideUserTrackerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideBgHandlerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.bindDeviceProvisionedControllerProvider = DoubleCheck.provider(SystemUIDefaultModule_BindDeviceProvisionedControllerFactory.create(deviceProvisionedControllerImplProvider));
      this.provideFlagManagerProvider = FlagsModule_ProvideFlagManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider);
      this.featureFlagManagerProvider = DoubleCheck.provider(FeatureFlagManager_Factory.create(provideFlagManagerProvider, DaggerGlobalRootComponent.this.contextProvider, secureSettingsImplProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.featureFlagsProvider = DoubleCheck.provider(FeatureFlags_Factory.create((Provider) featureFlagManagerProvider, DaggerGlobalRootComponent.this.contextProvider));
      this.provideNotificationListenerProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideNotificationListenerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideNotificationManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
      this.provideNotificationsLogBufferProvider = DoubleCheck.provider(LogModule_ProvideNotificationsLogBufferFactory.create(logBufferFactoryProvider));
      this.notificationEntryManagerLoggerProvider = NotificationEntryManagerLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.extensionControllerImplProvider = DoubleCheck.provider(ExtensionControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideLeakDetectorProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, (Provider) tunerServiceImplProvider, provideConfigurationControllerProvider));
      this.notificationPersonExtractorPluginBoundaryProvider = DoubleCheck.provider(NotificationPersonExtractorPluginBoundary_Factory.create((Provider) extensionControllerImplProvider));
      this.notificationGroupManagerLegacyProvider = new DelegateFactory<>();
      this.provideGroupMembershipManagerProvider = DoubleCheck.provider(NotificationsModule_ProvideGroupMembershipManagerFactory.create(featureFlagsProvider, notificationGroupManagerLegacyProvider));
      this.peopleNotificationIdentifierImplProvider = DoubleCheck.provider(PeopleNotificationIdentifierImpl_Factory.create((Provider) notificationPersonExtractorPluginBoundaryProvider, provideGroupMembershipManagerProvider));
      this.setBubblesProvider = InstanceFactory.create(setBubblesParam);
      DelegateFactory.setDelegate(notificationGroupManagerLegacyProvider, DoubleCheck.provider(NotificationGroupManagerLegacy_Factory.create((Provider) statusBarStateControllerImplProvider, (Provider) peopleNotificationIdentifierImplProvider, setBubblesProvider, DaggerGlobalRootComponent.this.dumpManagerProvider)));
      this.provideNotificationMessagingUtilProvider = DependencyProvider_ProvideNotificationMessagingUtilFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider);
      this.notificationClickNotifierProvider = DoubleCheck.provider(NotificationClickNotifier_Factory.create(DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.notificationLockscreenUserManagerImplProvider = DoubleCheck.provider(NotificationLockscreenUserManagerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideDevicePolicyManagerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, notificationClickNotifierProvider, DaggerGlobalRootComponent.this.provideKeyguardManagerProvider, (Provider) statusBarStateControllerImplProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, bindDeviceProvisionedControllerProvider, (Provider) keyguardStateControllerImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideNotificationEntryManagerProvider = new DelegateFactory<>();
      this.provideSmartReplyControllerProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideSmartReplyControllerFactory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, provideNotificationEntryManagerProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, notificationClickNotifierProvider));
      this.remoteInputNotificationRebuilderProvider = DoubleCheck.provider(RemoteInputNotificationRebuilder_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.optionalOfStatusBarProvider = new DelegateFactory<>();
      this.provideHandlerProvider = DependencyProvider_ProvideHandlerFactory.create(dependencyProviderParam);
      this.remoteInputUriControllerProvider = DoubleCheck.provider(RemoteInputUriController_Factory.create(DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider));
      this.provideNotifInteractionLogBufferProvider = DoubleCheck.provider(LogModule_ProvideNotifInteractionLogBufferFactory.create(logBufferFactoryProvider));
      this.actionClickLoggerProvider = ActionClickLogger_Factory.create(provideNotifInteractionLogBufferProvider);
      this.provideNotificationRemoteInputManagerProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideNotificationRemoteInputManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, featureFlagsProvider, (Provider) notificationLockscreenUserManagerImplProvider, provideSmartReplyControllerProvider, provideNotificationEntryManagerProvider, remoteInputNotificationRebuilderProvider, optionalOfStatusBarProvider, (Provider) statusBarStateControllerImplProvider, provideHandlerProvider, remoteInputUriControllerProvider, notificationClickNotifierProvider, actionClickLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.notifCollectionLoggerProvider = NotifCollectionLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.filesProvider = DoubleCheck.provider(Files_Factory.create());
      this.logBufferEulogizerProvider = DoubleCheck.provider(LogBufferEulogizer_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, bindSystemClockProvider, filesProvider));
      this.notifCollectionProvider = DoubleCheck.provider(NotifCollection_Factory.create(DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, bindSystemClockProvider, featureFlagsProvider, notifCollectionLoggerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, logBufferEulogizerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.shadeListBuilderLoggerProvider = ShadeListBuilderLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.notificationInteractionTrackerProvider = DoubleCheck.provider(NotificationInteractionTracker_Factory.create(notificationClickNotifierProvider, provideNotificationEntryManagerProvider));
      this.shadeListBuilderProvider = DoubleCheck.provider(ShadeListBuilder_Factory.create(bindSystemClockProvider, shadeListBuilderLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, notificationInteractionTrackerProvider));
      this.notifPipelineProvider = DoubleCheck.provider(NotifPipeline_Factory.create(notifCollectionProvider, shadeListBuilderProvider));
      this.provideCommonNotifCollectionProvider = DoubleCheck.provider(NotificationsModule_ProvideCommonNotifCollectionFactory.create(featureFlagsProvider, notifPipelineProvider, provideNotificationEntryManagerProvider));
    }

    @SuppressWarnings("unchecked")
    private void initialize2(final DependencyProvider dependencyProviderParam,
        final NightDisplayListenerModule nightDisplayListenerModuleParam,
        final SysUIUnfoldModule sysUIUnfoldModuleParam, final UserModule userModuleParam,
        final Optional<Pip> setPipParam,
        final Optional<LegacySplitScreen> setLegacySplitScreenParam,
        final Optional<SplitScreen> setSplitScreenParam, final Optional<AppPairs> setAppPairs,
        final Optional<OneHanded> setOneHandedParam, final Optional<Bubbles> setBubblesParam,
        final Optional<TaskViewFactory> setTaskViewFactoryParam,
        final Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        final Optional<ShellCommandHandler> setShellCommandHandlerParam,
        final ShellTransitions setTransitionsParam,
        final Optional<StartingSurface> setStartingSurfaceParam,
        final Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        final Optional<TaskSurfaceHelper> setTaskSurfaceHelper,
        final Optional<RecentTasks> setRecentTasksParam, final Optional<CompatUI> setCompatUIParam,
        final Optional<DragAndDrop> setDragAndDropParam) {
      this.notifBindPipelineLoggerProvider = NotifBindPipelineLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.notifBindPipelineProvider = DoubleCheck.provider(NotifBindPipeline_Factory.create(provideCommonNotifCollectionProvider, notifBindPipelineLoggerProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create()));
      this.notifRemoteViewCacheImplProvider = NotifRemoteViewCacheImpl_Factory.create(provideCommonNotifCollectionProvider);
      this.provideNotifRemoteViewCacheProvider = DoubleCheck.provider((Provider) notifRemoteViewCacheImplProvider);
      this.conversationNotificationManagerProvider = DoubleCheck.provider(ConversationNotificationManager_Factory.create(provideNotificationEntryManagerProvider, notificationGroupManagerLegacyProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
      this.conversationNotificationProcessorProvider = ConversationNotificationProcessor_Factory.create(DaggerGlobalRootComponent.this.provideLauncherAppsProvider, conversationNotificationManagerProvider);
      this.mediaFeatureFlagProvider = MediaFeatureFlag_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.smartReplyConstantsProvider = DoubleCheck.provider(SmartReplyConstants_Factory.create(DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.contextProvider, deviceConfigProxyProvider));
      this.provideActivityManagerWrapperProvider = DoubleCheck.provider(DependencyProvider_ProvideActivityManagerWrapperFactory.create(dependencyProviderParam));
      this.provideDevicePolicyManagerWrapperProvider = DoubleCheck.provider(DependencyProvider_ProvideDevicePolicyManagerWrapperFactory.create(dependencyProviderParam));
      this.keyguardDismissUtilProvider = DoubleCheck.provider(KeyguardDismissUtil_Factory.create());
      this.smartReplyInflaterImplProvider = SmartReplyInflaterImpl_Factory.create(smartReplyConstantsProvider, keyguardDismissUtilProvider, provideNotificationRemoteInputManagerProvider, provideSmartReplyControllerProvider, DaggerGlobalRootComponent.this.contextProvider);
      this.provideActivityStarterProvider = new DelegateFactory<>();
      this.keyguardBypassControllerProvider = DoubleCheck.provider(KeyguardBypassController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) tunerServiceImplProvider, (Provider) statusBarStateControllerImplProvider, (Provider) notificationLockscreenUserManagerImplProvider, (Provider) keyguardStateControllerImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideHeadsUpManagerPhoneProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideHeadsUpManagerPhoneFactory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) statusBarStateControllerImplProvider, keyguardBypassControllerProvider, provideGroupMembershipManagerProvider, provideConfigurationControllerProvider));
      this.smartActionInflaterImplProvider = SmartActionInflaterImpl_Factory.create(smartReplyConstantsProvider, provideActivityStarterProvider, provideSmartReplyControllerProvider, (Provider) provideHeadsUpManagerPhoneProvider);
      this.smartReplyStateInflaterImplProvider = SmartReplyStateInflaterImpl_Factory.create(smartReplyConstantsProvider, provideActivityManagerWrapperProvider, DaggerGlobalRootComponent.this.providePackageManagerWrapperProvider, provideDevicePolicyManagerWrapperProvider, (Provider) smartReplyInflaterImplProvider, (Provider) smartActionInflaterImplProvider);
      this.notificationContentInflaterProvider = DoubleCheck.provider(NotificationContentInflater_Factory.create(provideNotifRemoteViewCacheProvider, provideNotificationRemoteInputManagerProvider, conversationNotificationProcessorProvider, mediaFeatureFlagProvider, provideBackgroundExecutorProvider, (Provider) smartReplyStateInflaterImplProvider));
      this.notifInflationErrorManagerProvider = DoubleCheck.provider(NotifInflationErrorManager_Factory.create());
      this.rowContentBindStageLoggerProvider = RowContentBindStageLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.rowContentBindStageProvider = DoubleCheck.provider(RowContentBindStage_Factory.create((Provider) notificationContentInflaterProvider, notifInflationErrorManagerProvider, rowContentBindStageLoggerProvider));
      this.expandableNotificationRowComponentBuilderProvider = new Provider<ExpandableNotificationRowComponent.Builder>() {
        @Override
        public ExpandableNotificationRowComponent.Builder get() {
          return new ExpandableNotificationRowComponentBuilder();
        }
      };
      this.iconBuilderProvider = IconBuilder_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.iconManagerProvider = IconManager_Factory.create(provideCommonNotifCollectionProvider, DaggerGlobalRootComponent.this.provideLauncherAppsProvider, iconBuilderProvider);
      this.lowPriorityInflationHelperProvider = DoubleCheck.provider(LowPriorityInflationHelper_Factory.create(featureFlagsProvider, notificationGroupManagerLegacyProvider, rowContentBindStageProvider));
      this.notificationRowBinderImplProvider = DoubleCheck.provider(NotificationRowBinderImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideNotificationMessagingUtilProvider, provideNotificationRemoteInputManagerProvider, (Provider) notificationLockscreenUserManagerImplProvider, notifBindPipelineProvider, rowContentBindStageProvider, RowInflaterTask_Factory.create(), expandableNotificationRowComponentBuilderProvider, iconManagerProvider, lowPriorityInflationHelperProvider));
      this.foregroundServiceDismissalFeatureControllerProvider = DoubleCheck.provider(ForegroundServiceDismissalFeatureController_Factory.create(deviceConfigProxyProvider, DaggerGlobalRootComponent.this.contextProvider));
      DelegateFactory.setDelegate(provideNotificationEntryManagerProvider, DoubleCheck.provider(NotificationsModule_ProvideNotificationEntryManagerFactory.create(notificationEntryManagerLoggerProvider, notificationGroupManagerLegacyProvider, featureFlagsProvider, (Provider) notificationRowBinderImplProvider, provideNotificationRemoteInputManagerProvider, provideLeakDetectorProvider, foregroundServiceDismissalFeatureControllerProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, DaggerGlobalRootComponent.this.dumpManagerProvider)));
      this.provideAmbientDisplayConfigurationProvider = DependencyProvider_ProvideAmbientDisplayConfigurationFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider);
      this.provideAlwaysOnDisplayPolicyProvider = DoubleCheck.provider(DependencyProvider_ProvideAlwaysOnDisplayPolicyFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider));
      this.wakefulnessLifecycleProvider = DoubleCheck.provider(WakefulnessLifecycle_Factory.create(DaggerGlobalRootComponent.this.contextProvider, FrameworkServicesModule_ProvideIWallPaperManagerFactory.create(), DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.newKeyguardViewMediatorProvider = new DelegateFactory<>();
      this.dozeParametersProvider = new DelegateFactory<>();
      this.unlockedScreenOffAnimationControllerProvider = DoubleCheck.provider(UnlockedScreenOffAnimationController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, wakefulnessLifecycleProvider, statusBarStateControllerImplProvider, newKeyguardViewMediatorProvider, (Provider) keyguardStateControllerImplProvider, dozeParametersProvider, globalSettingsImplProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, provideHandlerProvider));
      DelegateFactory.setDelegate(dozeParametersProvider, DoubleCheck.provider(DozeParameters_Factory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, provideAmbientDisplayConfigurationProvider, provideAlwaysOnDisplayPolicyProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, provideBatteryControllerProvider, (Provider) tunerServiceImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, featureFlagsProvider, unlockedScreenOffAnimationControllerProvider, keyguardUpdateMonitorProvider, provideConfigurationControllerProvider, (Provider) statusBarStateControllerImplProvider)));
      this.sysuiColorExtractorProvider = DoubleCheck.provider(SysuiColorExtractor_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.authControllerProvider = new DelegateFactory<>();
      this.notificationShadeWindowControllerImplProvider = DoubleCheck.provider(NotificationShadeWindowControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider, dozeParametersProvider, (Provider) statusBarStateControllerImplProvider, provideConfigurationControllerProvider, newKeyguardViewMediatorProvider, keyguardBypassControllerProvider, sysuiColorExtractorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, (Provider) keyguardStateControllerImplProvider, unlockedScreenOffAnimationControllerProvider, authControllerProvider));
      this.mediaArtworkProcessorProvider = DoubleCheck.provider(MediaArtworkProcessor_Factory.create());
      this.mediaControllerFactoryProvider = MediaControllerFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.mediaTimeoutListenerProvider = DoubleCheck.provider(MediaTimeoutListener_Factory.create(mediaControllerFactoryProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider));
      this.mediaBrowserFactoryProvider = MediaBrowserFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.resumeMediaBrowserFactoryProvider = ResumeMediaBrowserFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, mediaBrowserFactoryProvider);
      this.mediaResumeListenerProvider = DoubleCheck.provider(MediaResumeListener_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, provideBackgroundExecutorProvider, (Provider) tunerServiceImplProvider, resumeMediaBrowserFactoryProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, bindSystemClockProvider));
      this.mediaSessionBasedFilterProvider = MediaSessionBasedFilter_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMediaSessionManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, provideBackgroundExecutorProvider);
      this.provideLocalBluetoothControllerProvider = DoubleCheck.provider(DependencyProvider_ProvideLocalBluetoothControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideBgHandlerProvider));
      this.localMediaManagerFactoryProvider = LocalMediaManagerFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideLocalBluetoothControllerProvider);
      this.mediaDeviceManagerProvider = MediaDeviceManager_Factory.create(mediaControllerFactoryProvider, localMediaManagerFactoryProvider, DaggerGlobalRootComponent.this.provideMediaRouter2ManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider);
      this.mediaDataFilterProvider = MediaDataFilter_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, (Provider) notificationLockscreenUserManagerImplProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, bindSystemClockProvider);
      this.mediaDataManagerProvider = DoubleCheck.provider(MediaDataManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, mediaControllerFactoryProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, providesBroadcastDispatcherProvider, mediaTimeoutListenerProvider, mediaResumeListenerProvider, mediaSessionBasedFilterProvider, mediaDeviceManagerProvider, MediaDataCombineLatest_Factory.create(), mediaDataFilterProvider, provideActivityStarterProvider, SmartspaceMediaDataProvider_Factory.create(), bindSystemClockProvider, (Provider) tunerServiceImplProvider));
      this.provideNotificationMediaManagerProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideNotificationMediaManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, optionalOfStatusBarProvider, (Provider) notificationShadeWindowControllerImplProvider, provideNotificationEntryManagerProvider, mediaArtworkProcessorProvider, keyguardBypassControllerProvider, notifPipelineProvider, notifCollectionProvider, featureFlagsProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, mediaDataManagerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.provideWallpaperManagerProvider));
      this.keyguardEnvironmentImplProvider = DoubleCheck.provider(KeyguardEnvironmentImpl_Factory.create());
      this.provideIndividualSensorPrivacyControllerProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideIndividualSensorPrivacyControllerFactory.create(DaggerGlobalRootComponent.this.provideSensorPrivacyManagerProvider));
      this.appOpsControllerImplProvider = DoubleCheck.provider(AppOpsControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.provideAudioManagerProvider, provideIndividualSensorPrivacyControllerProvider, providesBroadcastDispatcherProvider, bindSystemClockProvider));
      this.foregroundServiceControllerProvider = DoubleCheck.provider(ForegroundServiceController_Factory.create((Provider) appOpsControllerImplProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
      this.notificationFilterProvider = DoubleCheck.provider(NotificationFilter_Factory.create((Provider) statusBarStateControllerImplProvider, (Provider) keyguardEnvironmentImplProvider, foregroundServiceControllerProvider, (Provider) notificationLockscreenUserManagerImplProvider, mediaFeatureFlagProvider));
      this.notificationSectionsFeatureManagerProvider = NotificationSectionsFeatureManager_Factory.create(deviceConfigProxyProvider, DaggerGlobalRootComponent.this.contextProvider);
      this.highPriorityProvider = DoubleCheck.provider(HighPriorityProvider_Factory.create((Provider) peopleNotificationIdentifierImplProvider, provideGroupMembershipManagerProvider));
      this.notificationRankingManagerProvider = NotificationRankingManager_Factory.create(provideNotificationMediaManagerProvider, notificationGroupManagerLegacyProvider, (Provider) provideHeadsUpManagerPhoneProvider, notificationFilterProvider, notificationEntryManagerLoggerProvider, notificationSectionsFeatureManagerProvider, (Provider) peopleNotificationIdentifierImplProvider, highPriorityProvider, (Provider) keyguardEnvironmentImplProvider);
      this.targetSdkResolverProvider = DoubleCheck.provider(TargetSdkResolver_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.groupCoalescerLoggerProvider = GroupCoalescerLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.groupCoalescerProvider = GroupCoalescer_Factory.create(DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, bindSystemClockProvider, groupCoalescerLoggerProvider);
      this.coordinatorsSubcomponentFactoryProvider = new Provider<CoordinatorsSubcomponent.Factory>() {
        @Override
        public CoordinatorsSubcomponent.Factory get() {
          return new CoordinatorsSubcomponentFactory();
        }
      };
      this.notifCoordinatorsProvider = DoubleCheck.provider(CoordinatorsModule_NotifCoordinatorsFactory.create(coordinatorsSubcomponentFactoryProvider));
      this.notifInflaterImplProvider = DoubleCheck.provider(NotifInflaterImpl_Factory.create(DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, notifCollectionProvider, notifInflationErrorManagerProvider, notifPipelineProvider));
      this.shadeViewDifferLoggerProvider = ShadeViewDifferLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.notifViewBarnProvider = DoubleCheck.provider(NotifViewBarn_Factory.create());
      this.notificationWakeUpCoordinatorProvider = DoubleCheck.provider(NotificationWakeUpCoordinator_Factory.create((Provider) provideHeadsUpManagerPhoneProvider, (Provider) statusBarStateControllerImplProvider, keyguardBypassControllerProvider, dozeParametersProvider, unlockedScreenOffAnimationControllerProvider));
      this.darkIconDispatcherImplProvider = DoubleCheck.provider(DarkIconDispatcherImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.providesStatusBarWindowViewProvider = DoubleCheck.provider(StatusBarWindowModule_ProvidesStatusBarWindowViewFactory.create(providerLayoutInflaterProvider));
      this.statusBarContentInsetsProvider = DoubleCheck.provider(StatusBarContentInsetsProvider_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.statusBarWindowControllerProvider = DoubleCheck.provider(StatusBarWindowController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesStatusBarWindowViewProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider, statusBarContentInsetsProvider, DaggerGlobalRootComponent.this.provideResourcesProvider));
      this.notificationIconAreaControllerProvider = DoubleCheck.provider(NotificationIconAreaController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) statusBarStateControllerImplProvider, notificationWakeUpCoordinatorProvider, keyguardBypassControllerProvider, provideNotificationMediaManagerProvider, provideNotificationListenerProvider, dozeParametersProvider, setBubblesProvider, provideDemoModeControllerProvider, (Provider) darkIconDispatcherImplProvider, statusBarWindowControllerProvider, unlockedScreenOffAnimationControllerProvider));
      this.shadeViewManagerFactoryProvider = ShadeViewManagerFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, shadeViewDifferLoggerProvider, notifViewBarnProvider, notificationIconAreaControllerProvider);
      this.notifPipelineInitializerProvider = DoubleCheck.provider(NotifPipelineInitializer_Factory.create(notifPipelineProvider, groupCoalescerProvider, notifCollectionProvider, shadeListBuilderProvider, notifCoordinatorsProvider, notifInflaterImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, shadeViewManagerFactoryProvider, featureFlagsProvider));
      this.notifBindPipelineInitializerProvider = NotifBindPipelineInitializer_Factory.create(notifBindPipelineProvider, rowContentBindStageProvider);
      this.provideNotificationGroupAlertTransferHelperProvider = DoubleCheck.provider(StatusBarPhoneDependenciesModule_ProvideNotificationGroupAlertTransferHelperFactory.create(rowContentBindStageProvider));
      this.headsUpViewBinderProvider = DoubleCheck.provider(HeadsUpViewBinder_Factory.create(provideNotificationMessagingUtilProvider, rowContentBindStageProvider));
      this.notificationInterruptStateProviderImplProvider = DoubleCheck.provider(NotificationInterruptStateProviderImpl_Factory.create(DaggerGlobalRootComponent.this.provideContentResolverProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, DaggerGlobalRootComponent.this.provideIDreamManagerProvider, provideAmbientDisplayConfigurationProvider, notificationFilterProvider, provideBatteryControllerProvider, (Provider) statusBarStateControllerImplProvider, (Provider) provideHeadsUpManagerPhoneProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
      this.provideVisualStabilityManagerProvider = DoubleCheck.provider(NotificationsModule_ProvideVisualStabilityManagerFactory.create(provideNotificationEntryManagerProvider, provideHandlerProvider, (Provider) statusBarStateControllerImplProvider, wakefulnessLifecycleProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.headsUpControllerProvider = DoubleCheck.provider(HeadsUpController_Factory.create(headsUpViewBinderProvider, (Provider) notificationInterruptStateProviderImplProvider, (Provider) provideHeadsUpManagerPhoneProvider, provideNotificationRemoteInputManagerProvider, (Provider) statusBarStateControllerImplProvider, provideVisualStabilityManagerProvider, provideNotificationListenerProvider));
      this.notificationClickerLoggerProvider = NotificationClickerLogger_Factory.create(provideNotifInteractionLogBufferProvider);
      this.builderProvider2 = NotificationClicker_Builder_Factory.create(notificationClickerLoggerProvider);
      this.animatedImageNotificationManagerProvider = DoubleCheck.provider(AnimatedImageNotificationManager_Factory.create(provideNotificationEntryManagerProvider, (Provider) provideHeadsUpManagerPhoneProvider, (Provider) statusBarStateControllerImplProvider));
      this.peopleSpaceWidgetManagerProvider = DoubleCheck.provider(PeopleSpaceWidgetManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideLauncherAppsProvider, provideNotificationEntryManagerProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider, setBubblesProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, DaggerGlobalRootComponent.this.provideNotificationManagerProvider, providesBroadcastDispatcherProvider, provideBackgroundExecutorProvider));
      this.notificationsControllerImplProvider = DoubleCheck.provider(NotificationsControllerImpl_Factory.create(featureFlagsProvider, provideNotificationListenerProvider, provideNotificationEntryManagerProvider, notificationRankingManagerProvider, notifPipelineProvider, targetSdkResolverProvider, notifPipelineInitializerProvider, notifBindPipelineInitializerProvider, bindDeviceProvisionedControllerProvider, notificationRowBinderImplProvider, remoteInputUriControllerProvider, notificationGroupManagerLegacyProvider, provideNotificationGroupAlertTransferHelperProvider, (Provider) provideHeadsUpManagerPhoneProvider, headsUpControllerProvider, headsUpViewBinderProvider, builderProvider2, animatedImageNotificationManagerProvider, peopleSpaceWidgetManagerProvider));
      this.notificationsControllerStubProvider = NotificationsControllerStub_Factory.create(provideNotificationListenerProvider);
      this.provideNotificationsControllerProvider = DoubleCheck.provider(NotificationsModule_ProvideNotificationsControllerFactory.create(DaggerGlobalRootComponent.this.contextProvider, notificationsControllerImplProvider, notificationsControllerStubProvider));
      this.fragmentCreatorFactoryProvider = new Provider<FragmentService.FragmentCreator.Factory>() {
        @Override
        public FragmentService.FragmentCreator.Factory get() {
          return new FragmentCreatorFactory();
        }
      };
      this.fragmentServiceProvider = DoubleCheck.provider(FragmentService_Factory.create(fragmentCreatorFactoryProvider, provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.navigationModeControllerProvider = DoubleCheck.provider(NavigationModeController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, bindDeviceProvisionedControllerProvider, provideConfigurationControllerProvider, provideUiBackgroundExecutorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.lightBarControllerProvider = DoubleCheck.provider(LightBarController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) darkIconDispatcherImplProvider, provideBatteryControllerProvider, navigationModeControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideAutoHideControllerProvider = DoubleCheck.provider(DependencyProvider_ProvideAutoHideControllerFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider));
      this.statusBarIconControllerImplProvider = DoubleCheck.provider(StatusBarIconControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, provideDemoModeControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.carrierConfigTrackerProvider = DoubleCheck.provider(CarrierConfigTracker_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider));
      this.callbackHandlerProvider = CallbackHandler_Factory.create(GlobalConcurrencyModule_ProvideMainLooperFactory.create());
      this.telephonyListenerManagerProvider = DoubleCheck.provider(TelephonyListenerManager_Factory.create(DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, TelephonyCallback_Factory.create()));
      this.wifiPickerTrackerFactoryProvider = DoubleCheck.provider(AccessPointControllerImpl_WifiPickerTrackerFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideWifiManagerProvider, DaggerGlobalRootComponent.this.provideConnectivityManagagerProvider, DaggerGlobalRootComponent.this.provideNetworkScoreManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBgHandlerProvider));
      this.provideAccessPointControllerImplProvider = DoubleCheck.provider(StatusBarPolicyModule_ProvideAccessPointControllerImplFactory.create(DaggerGlobalRootComponent.this.provideUserManagerProvider, provideUserTrackerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, wifiPickerTrackerFactoryProvider));
      this.toastFactoryProvider = DoubleCheck.provider(ToastFactory_Factory.create(providerLayoutInflaterProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
    }

    @SuppressWarnings("unchecked")
    private void initialize3(final DependencyProvider dependencyProviderParam,
        final NightDisplayListenerModule nightDisplayListenerModuleParam,
        final SysUIUnfoldModule sysUIUnfoldModuleParam, final UserModule userModuleParam,
        final Optional<Pip> setPipParam,
        final Optional<LegacySplitScreen> setLegacySplitScreenParam,
        final Optional<SplitScreen> setSplitScreenParam, final Optional<AppPairs> setAppPairs,
        final Optional<OneHanded> setOneHandedParam, final Optional<Bubbles> setBubblesParam,
        final Optional<TaskViewFactory> setTaskViewFactoryParam,
        final Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        final Optional<ShellCommandHandler> setShellCommandHandlerParam,
        final ShellTransitions setTransitionsParam,
        final Optional<StartingSurface> setStartingSurfaceParam,
        final Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        final Optional<TaskSurfaceHelper> setTaskSurfaceHelper,
        final Optional<RecentTasks> setRecentTasksParam, final Optional<CompatUI> setCompatUIParam,
        final Optional<DragAndDrop> setDragAndDropParam) {
      this.locationControllerImplProvider = DoubleCheck.provider(LocationControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) appOpsControllerImplProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create(), provideBgHandlerProvider, providesBroadcastDispatcherProvider, (Provider) bootCompleteCacheImplProvider, provideUserTrackerProvider));
      this.provideDialogLaunchAnimatorProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideDialogLaunchAnimatorFactory.create(DaggerGlobalRootComponent.this.provideIDreamManagerProvider));
      this.internetDialogControllerProvider = InternetDialogController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideActivityStarterProvider, (Provider) provideAccessPointControllerImplProvider, DaggerGlobalRootComponent.this.provideSubcriptionManagerProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, DaggerGlobalRootComponent.this.provideWifiManagerProvider, DaggerGlobalRootComponent.this.provideConnectivityManagagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, providesBroadcastDispatcherProvider, keyguardUpdateMonitorProvider, globalSettingsImplProvider, (Provider) keyguardStateControllerImplProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, toastFactoryProvider, provideBgHandlerProvider, carrierConfigTrackerProvider, (Provider) locationControllerImplProvider, provideDialogLaunchAnimatorProvider);
      this.internetDialogFactoryProvider = DoubleCheck.provider(InternetDialogFactory_Factory.create(DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBackgroundExecutorProvider, internetDialogControllerProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideDialogLaunchAnimatorProvider));
      this.networkControllerImplProvider = DoubleCheck.provider(NetworkControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBgLooperProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideSubcriptionManagerProvider, callbackHandlerProvider, bindDeviceProvisionedControllerProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideConnectivityManagagerProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, telephonyListenerManagerProvider, DaggerGlobalRootComponent.this.provideWifiManagerProvider, DaggerGlobalRootComponent.this.provideNetworkScoreManagerProvider, provideAccessPointControllerImplProvider, provideDemoModeControllerProvider, carrierConfigTrackerProvider, featureFlagsProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, internetDialogFactoryProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.securityControllerImplProvider = DoubleCheck.provider(SecurityControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBgHandlerProvider, providesBroadcastDispatcherProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.statusBarSignalPolicyProvider = DoubleCheck.provider(StatusBarSignalPolicy_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) statusBarIconControllerImplProvider, carrierConfigTrackerProvider, (Provider) networkControllerImplProvider, (Provider) securityControllerImplProvider, (Provider) tunerServiceImplProvider, featureFlagsProvider));
      this.notificationRoundnessManagerProvider = DoubleCheck.provider(NotificationRoundnessManager_Factory.create(keyguardBypassControllerProvider, notificationSectionsFeatureManagerProvider, featureFlagsProvider));
      this.provideLSShadeTransitionControllerBufferProvider = DoubleCheck.provider(LogModule_ProvideLSShadeTransitionControllerBufferFactory.create(logBufferFactoryProvider));
      this.lockscreenGestureLoggerProvider = DoubleCheck.provider(LockscreenGestureLogger_Factory.create(provideMetricsLoggerProvider));
      this.lSShadeTransitionLoggerProvider = LSShadeTransitionLogger_Factory.create(provideLSShadeTransitionControllerBufferProvider, lockscreenGestureLoggerProvider, DaggerGlobalRootComponent.this.provideDisplayMetricsProvider);
      this.mediaHostStatesManagerProvider = DoubleCheck.provider(MediaHostStatesManager_Factory.create());
      this.mediaViewControllerProvider = MediaViewController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideConfigurationControllerProvider, mediaHostStatesManagerProvider);
      this.provideBackgroundDelayableExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideBackgroundDelayableExecutorFactory.create(provideBgLooperProvider));
      this.provideBackgroundRepeatableExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideBackgroundRepeatableExecutorFactory.create(provideBackgroundDelayableExecutorProvider));
      this.seekBarViewModelProvider = SeekBarViewModel_Factory.create(provideBackgroundRepeatableExecutorProvider);
      this.provideAssistUtilsProvider = DoubleCheck.provider(AssistModule_ProvideAssistUtilsFactory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.phoneStateMonitorProvider = DoubleCheck.provider(PhoneStateMonitor_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, optionalOfStatusBarProvider, (Provider) bootCompleteCacheImplProvider));
      this.overviewProxyServiceProvider = new DelegateFactory<>();
      this.provideSysUiStateProvider = DoubleCheck.provider(SystemUIModule_ProvideSysUiStateFactory.create(DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.accessibilityManagerWrapperProvider = DoubleCheck.provider(AccessibilityManagerWrapper_Factory.create(DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider));
      this.accessibilityButtonModeObserverProvider = DoubleCheck.provider(AccessibilityButtonModeObserver_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.assistManagerProvider = new DelegateFactory<>();
      this.navBarHelperProvider = DoubleCheck.provider(NavBarHelper_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, accessibilityManagerWrapperProvider, accessibilityButtonModeObserverProvider, overviewProxyServiceProvider, assistManagerProvider, optionalOfStatusBarProvider, navigationModeControllerProvider, provideUserTrackerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.setPipProvider = InstanceFactory.create(setPipParam);
      this.setLegacySplitScreenProvider = InstanceFactory.create(setLegacySplitScreenParam);
      this.contextComponentResolverProvider = new DelegateFactory<>();
      this.provideRecentsImplProvider = RecentsModule_ProvideRecentsImplFactory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) contextComponentResolverProvider);
      this.provideRecentsProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideRecentsFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideRecentsImplProvider, provideCommandQueueProvider));
      this.optionalOfRecentsProvider = PresentJdkOptionalInstanceProvider.of(provideRecentsProvider);
      this.shadeControllerImplProvider = new DelegateFactory<>();
      this.blurUtilsProvider = DoubleCheck.provider(BlurUtils_Factory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.provideCrossWindowBlurListenersProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideDozeLogBufferProvider = DoubleCheck.provider(LogModule_ProvideDozeLogBufferFactory.create(logBufferFactoryProvider));
      this.dozeLoggerProvider = DozeLogger_Factory.create(provideDozeLogBufferProvider);
      this.dozeLogProvider = DoubleCheck.provider(DozeLog_Factory.create(keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, dozeLoggerProvider));
      this.dozeScrimControllerProvider = DoubleCheck.provider(DozeScrimController_Factory.create(dozeParametersProvider, dozeLogProvider, (Provider) statusBarStateControllerImplProvider));
      this.builderProvider3 = DelayedWakeLock_Builder_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.scrimControllerProvider = DoubleCheck.provider(ScrimController_Factory.create(lightBarControllerProvider, dozeParametersProvider, DaggerGlobalRootComponent.this.provideAlarmManagerProvider, (Provider) keyguardStateControllerImplProvider, builderProvider3, provideHandlerProvider, keyguardUpdateMonitorProvider, (Provider) dockManagerImplProvider, provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, unlockedScreenOffAnimationControllerProvider, panelExpansionStateManagerProvider));
      this.biometricUnlockControllerProvider = DoubleCheck.provider(BiometricUnlockController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, dozeScrimControllerProvider, newKeyguardViewMediatorProvider, scrimControllerProvider, (Provider) shadeControllerImplProvider, (Provider) notificationShadeWindowControllerImplProvider, (Provider) keyguardStateControllerImplProvider, provideHandlerProvider, keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, keyguardBypassControllerProvider, dozeParametersProvider, provideMetricsLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, provideNotificationMediaManagerProvider, wakefulnessLifecycleProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, authControllerProvider, (Provider) statusBarStateControllerImplProvider));
      this.providesChoreographerProvider = DoubleCheck.provider(DependencyProvider_ProvidesChoreographerFactory.create(dependencyProviderParam));
      this.wallpaperControllerProvider = DoubleCheck.provider(WallpaperController_Factory.create(DaggerGlobalRootComponent.this.provideWallpaperManagerProvider));
      this.notificationShadeDepthControllerProvider = DoubleCheck.provider(NotificationShadeDepthController_Factory.create((Provider) statusBarStateControllerImplProvider, blurUtilsProvider, biometricUnlockControllerProvider, (Provider) keyguardStateControllerImplProvider, providesChoreographerProvider, wallpaperControllerProvider, (Provider) notificationShadeWindowControllerImplProvider, dozeParametersProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.systemActionsProvider = DoubleCheck.provider(SystemActions_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) notificationShadeWindowControllerImplProvider, optionalOfStatusBarProvider, optionalOfRecentsProvider));
      this.navigationBarOverlayControllerProvider = DoubleCheck.provider(NavigationBarOverlayController_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.factoryProvider = LightBarController_Factory_Factory.create((Provider) darkIconDispatcherImplProvider, provideBatteryControllerProvider, navigationModeControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider);
      this.factoryProvider2 = AutoHideController_Factory_Factory.create(DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider);
      this.factoryProvider3 = NavigationBar_Factory_Factory.create(assistManagerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, bindDeviceProvisionedControllerProvider, provideMetricsLoggerProvider, overviewProxyServiceProvider, navigationModeControllerProvider, accessibilityButtonModeObserverProvider, (Provider) statusBarStateControllerImplProvider, provideSysUiStateProvider, providesBroadcastDispatcherProvider, provideCommandQueueProvider, setPipProvider, setLegacySplitScreenProvider, optionalOfRecentsProvider, optionalOfStatusBarProvider, (Provider) shadeControllerImplProvider, provideNotificationRemoteInputManagerProvider, notificationShadeDepthControllerProvider, systemActionsProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, navigationBarOverlayControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, navBarHelperProvider, provideUserTrackerProvider, lightBarControllerProvider, factoryProvider, provideAutoHideControllerProvider, factoryProvider2, DaggerGlobalRootComponent.this.provideOptionalTelecomManagerProvider, DaggerGlobalRootComponent.this.provideInputMethodManagerProvider);
      this.navigationBarControllerProvider = DoubleCheck.provider(NavigationBarController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, overviewProxyServiceProvider, navigationModeControllerProvider, provideSysUiStateProvider, provideCommandQueueProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideConfigurationControllerProvider, navBarHelperProvider, DaggerGlobalRootComponent.this.taskbarDelegateProvider, factoryProvider3, DaggerGlobalRootComponent.this.dumpManagerProvider, provideAutoHideControllerProvider, lightBarControllerProvider, setPipProvider));
      this.setSplitScreenProvider = InstanceFactory.create(setSplitScreenParam);
      this.setOneHandedProvider = InstanceFactory.create(setOneHandedParam);
      this.setRecentTasksProvider = InstanceFactory.create(setRecentTasksParam);
      this.setStartingSurfaceProvider = InstanceFactory.create(setStartingSurfaceParam);
      this.setTransitionsProvider = InstanceFactory.create(setTransitionsParam);
      this.provideSmartspaceTransitionControllerProvider = DoubleCheck.provider(SystemUIModule_ProvideSmartspaceTransitionControllerFactory.create());
      DelegateFactory.setDelegate(overviewProxyServiceProvider, DoubleCheck.provider(OverviewProxyService_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, navigationBarControllerProvider, optionalOfStatusBarProvider, navigationModeControllerProvider, (Provider) notificationShadeWindowControllerImplProvider, provideSysUiStateProvider, setPipProvider, setLegacySplitScreenProvider, setSplitScreenProvider, setOneHandedProvider, setRecentTasksProvider, setStartingSurfaceProvider, providesBroadcastDispatcherProvider, setTransitionsProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, provideSmartspaceTransitionControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider)));
      this.assistLoggerProvider = DoubleCheck.provider(AssistLogger_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideAssistUtilsProvider, phoneStateMonitorProvider));
      this.defaultUiControllerProvider = DoubleCheck.provider(DefaultUiController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, assistLoggerProvider));
      DelegateFactory.setDelegate(assistManagerProvider, DoubleCheck.provider(AssistManager_Factory.create(bindDeviceProvisionedControllerProvider, DaggerGlobalRootComponent.this.contextProvider, provideAssistUtilsProvider, provideCommandQueueProvider, phoneStateMonitorProvider, overviewProxyServiceProvider, provideSysUiStateProvider, defaultUiControllerProvider, assistLoggerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider)));
      DelegateFactory.setDelegate(shadeControllerImplProvider, DoubleCheck.provider(ShadeControllerImpl_Factory.create(provideCommandQueueProvider, (Provider) statusBarStateControllerImplProvider, (Provider) notificationShadeWindowControllerImplProvider, statusBarKeyguardViewManagerProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, optionalOfStatusBarProvider, assistManagerProvider, setBubblesProvider)));
      this.systemUIDialogManagerProvider = DoubleCheck.provider(SystemUIDialogManager_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, statusBarKeyguardViewManagerProvider));
      this.mediaOutputDialogFactoryProvider = MediaOutputDialogFactory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMediaSessionManagerProvider, provideLocalBluetoothControllerProvider, (Provider) shadeControllerImplProvider, provideActivityStarterProvider, provideNotificationEntryManagerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideDialogLaunchAnimatorProvider, systemUIDialogManagerProvider);
      this.mediaCarouselControllerProvider = new DelegateFactory<>();
      this.mediaControlPanelProvider = MediaControlPanel_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundExecutorProvider, provideActivityStarterProvider, mediaViewControllerProvider, seekBarViewModelProvider, mediaDataManagerProvider, keyguardDismissUtilProvider, mediaOutputDialogFactoryProvider, mediaCarouselControllerProvider, (Provider) falsingManagerProxyProvider, bindSystemClockProvider);
      DelegateFactory.setDelegate(mediaCarouselControllerProvider, DoubleCheck.provider(MediaCarouselController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, mediaControlPanelProvider, provideVisualStabilityManagerProvider, mediaHostStatesManagerProvider, provideActivityStarterProvider, bindSystemClockProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, mediaDataManagerProvider, provideConfigurationControllerProvider, falsingCollectorImplProvider, (Provider) falsingManagerProxyProvider, DaggerGlobalRootComponent.this.dumpManagerProvider)));
      this.mediaHierarchyManagerProvider = DoubleCheck.provider(MediaHierarchyManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) statusBarStateControllerImplProvider, (Provider) keyguardStateControllerImplProvider, keyguardBypassControllerProvider, mediaCarouselControllerProvider, (Provider) notificationLockscreenUserManagerImplProvider, provideConfigurationControllerProvider, wakefulnessLifecycleProvider, (Provider) statusBarKeyguardViewManagerProvider));
      this.providesKeyguardMediaHostProvider = DoubleCheck.provider(MediaModule_ProvidesKeyguardMediaHostFactory.create(MediaHost_MediaHostStateHolder_Factory.create(), mediaHierarchyManagerProvider, mediaDataManagerProvider, mediaHostStatesManagerProvider));
      this.keyguardMediaControllerProvider = DoubleCheck.provider(KeyguardMediaController_Factory.create(providesKeyguardMediaHostProvider, keyguardBypassControllerProvider, (Provider) statusBarStateControllerImplProvider, (Provider) notificationLockscreenUserManagerImplProvider, DaggerGlobalRootComponent.this.contextProvider, provideConfigurationControllerProvider));
      this.provideNotificationSectionLogBufferProvider = DoubleCheck.provider(LogModule_ProvideNotificationSectionLogBufferFactory.create(logBufferFactoryProvider));
      this.notificationSectionsLoggerProvider = DoubleCheck.provider(NotificationSectionsLogger_Factory.create(provideNotificationSectionLogBufferProvider));
      this.sectionHeaderControllerSubcomponentBuilderProvider = new Provider<SectionHeaderControllerSubcomponent.Builder>() {
        @Override
        public SectionHeaderControllerSubcomponent.Builder get() {
          return new SectionHeaderControllerSubcomponentBuilder();
        }
      };
      this.providesIncomingHeaderSubcomponentProvider = DoubleCheck.provider(NotificationSectionHeadersModule_ProvidesIncomingHeaderSubcomponentFactory.create(sectionHeaderControllerSubcomponentBuilderProvider));
      this.providesIncomingHeaderControllerProvider = NotificationSectionHeadersModule_ProvidesIncomingHeaderControllerFactory.create(providesIncomingHeaderSubcomponentProvider);
      this.providesPeopleHeaderSubcomponentProvider = DoubleCheck.provider(NotificationSectionHeadersModule_ProvidesPeopleHeaderSubcomponentFactory.create(sectionHeaderControllerSubcomponentBuilderProvider));
      this.providesPeopleHeaderControllerProvider = NotificationSectionHeadersModule_ProvidesPeopleHeaderControllerFactory.create(providesPeopleHeaderSubcomponentProvider);
      this.providesAlertingHeaderSubcomponentProvider = DoubleCheck.provider(NotificationSectionHeadersModule_ProvidesAlertingHeaderSubcomponentFactory.create(sectionHeaderControllerSubcomponentBuilderProvider));
      this.providesAlertingHeaderControllerProvider = NotificationSectionHeadersModule_ProvidesAlertingHeaderControllerFactory.create(providesAlertingHeaderSubcomponentProvider);
      this.providesSilentHeaderSubcomponentProvider = DoubleCheck.provider(NotificationSectionHeadersModule_ProvidesSilentHeaderSubcomponentFactory.create(sectionHeaderControllerSubcomponentBuilderProvider));
      this.providesSilentHeaderControllerProvider = NotificationSectionHeadersModule_ProvidesSilentHeaderControllerFactory.create(providesSilentHeaderSubcomponentProvider);
      this.notificationSectionsManagerProvider = NotificationSectionsManager_Factory.create((Provider) statusBarStateControllerImplProvider, provideConfigurationControllerProvider, keyguardMediaControllerProvider, notificationSectionsFeatureManagerProvider, notificationSectionsLoggerProvider, providesIncomingHeaderControllerProvider, providesPeopleHeaderControllerProvider, providesAlertingHeaderControllerProvider, providesSilentHeaderControllerProvider);
      this.ambientStateProvider = DoubleCheck.provider(AmbientState_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) notificationSectionsManagerProvider, (Provider) keyguardBypassControllerProvider));
      this.lockscreenShadeTransitionControllerProvider = DoubleCheck.provider(LockscreenShadeTransitionController_Factory.create((Provider) statusBarStateControllerImplProvider, lSShadeTransitionLoggerProvider, keyguardBypassControllerProvider, (Provider) notificationLockscreenUserManagerImplProvider, falsingCollectorImplProvider, ambientStateProvider, mediaHierarchyManagerProvider, scrimControllerProvider, notificationShadeDepthControllerProvider, DaggerGlobalRootComponent.this.contextProvider, wakefulnessLifecycleProvider, provideConfigurationControllerProvider, (Provider) falsingManagerProxyProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.pulseExpansionHandlerProvider = DoubleCheck.provider(PulseExpansionHandler_Factory.create(DaggerGlobalRootComponent.this.contextProvider, notificationWakeUpCoordinatorProvider, keyguardBypassControllerProvider, provideHeadsUpManagerPhoneProvider, notificationRoundnessManagerProvider, provideConfigurationControllerProvider, (Provider) statusBarStateControllerImplProvider, (Provider) falsingManagerProxyProvider, lockscreenShadeTransitionControllerProvider, falsingCollectorImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.dynamicPrivacyControllerProvider = DoubleCheck.provider(DynamicPrivacyController_Factory.create((Provider) notificationLockscreenUserManagerImplProvider, (Provider) keyguardStateControllerImplProvider, (Provider) statusBarStateControllerImplProvider));
      this.bypassHeadsUpNotifierProvider = DoubleCheck.provider(BypassHeadsUpNotifier_Factory.create(DaggerGlobalRootComponent.this.contextProvider, keyguardBypassControllerProvider, (Provider) statusBarStateControllerImplProvider, provideHeadsUpManagerPhoneProvider, (Provider) notificationLockscreenUserManagerImplProvider, provideNotificationMediaManagerProvider, provideNotificationEntryManagerProvider, (Provider) tunerServiceImplProvider));
      this.shadeEventCoordinatorLoggerProvider = ShadeEventCoordinatorLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.shadeEventCoordinatorProvider = DoubleCheck.provider(ShadeEventCoordinator_Factory.create(shadeEventCoordinatorLoggerProvider));
      this.legacyNotificationPresenterExtensionsProvider = LegacyNotificationPresenterExtensions_Factory.create(provideNotificationEntryManagerProvider);
      this.provideNotifShadeEventSourceProvider = DoubleCheck.provider(NotificationsModule_ProvideNotifShadeEventSourceFactory.create(featureFlagsProvider, shadeEventCoordinatorProvider, legacyNotificationPresenterExtensionsProvider));
      this.provideINotificationManagerProvider = DoubleCheck.provider(DependencyProvider_ProvideINotificationManagerFactory.create(dependencyProviderParam));
      this.channelEditorDialogControllerProvider = DoubleCheck.provider(ChannelEditorDialogController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideINotificationManagerProvider, ChannelEditorDialog_Builder_Factory.create()));
      this.assistantFeedbackControllerProvider = DoubleCheck.provider(AssistantFeedbackController_Factory.create(DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.contextProvider, deviceConfigProxyProvider));
      this.zenModeControllerImplProvider = DoubleCheck.provider(ZenModeControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideBubblesManagerProvider = DoubleCheck.provider(SystemUIModule_ProvideBubblesManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, setBubblesProvider, (Provider) notificationShadeWindowControllerImplProvider, (Provider) statusBarStateControllerImplProvider, (Provider) shadeControllerImplProvider, provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, provideINotificationManagerProvider, (Provider) notificationInterruptStateProviderImplProvider, (Provider) zenModeControllerImplProvider, (Provider) notificationLockscreenUserManagerImplProvider, notificationGroupManagerLegacyProvider, provideNotificationEntryManagerProvider, notifPipelineProvider, provideSysUiStateProvider, featureFlagsProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.provideDelayableExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideDelayableExecutorFactory.create(provideBgLooperProvider));
      this.visualStabilityCoordinatorProvider = DoubleCheck.provider(VisualStabilityCoordinator_Factory.create((Provider) provideHeadsUpManagerPhoneProvider, wakefulnessLifecycleProvider, (Provider) statusBarStateControllerImplProvider, provideDelayableExecutorProvider));
      this.provideOnUserInteractionCallbackProvider = DoubleCheck.provider(NotificationsModule_ProvideOnUserInteractionCallbackFactory.create(featureFlagsProvider, (Provider) provideHeadsUpManagerPhoneProvider, (Provider) statusBarStateControllerImplProvider, notifPipelineProvider, notifCollectionProvider, visualStabilityCoordinatorProvider, provideNotificationEntryManagerProvider, provideVisualStabilityManagerProvider, provideGroupMembershipManagerProvider));
      this.provideNotificationGutsManagerProvider = DoubleCheck.provider(NotificationsModule_ProvideNotificationGutsManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, optionalOfStatusBarProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBgHandlerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, highPriorityProvider, provideINotificationManagerProvider, provideNotificationEntryManagerProvider, peopleSpaceWidgetManagerProvider, DaggerGlobalRootComponent.this.provideLauncherAppsProvider, DaggerGlobalRootComponent.this.provideShortcutManagerProvider, channelEditorDialogControllerProvider, (Provider) provideUserTrackerProvider, assistantFeedbackControllerProvider, provideBubblesManagerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideOnUserInteractionCallbackProvider, (Provider) shadeControllerImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.expansionStateLoggerProvider = NotificationLogger_ExpansionStateLogger_Factory.create(provideUiBackgroundExecutorProvider);
      this.provideNotificationPanelLoggerProvider = DoubleCheck.provider(NotificationsModule_ProvideNotificationPanelLoggerFactory.create());
      this.provideNotificationLoggerProvider = DoubleCheck.provider(NotificationsModule_ProvideNotificationLoggerFactory.create(provideNotificationListenerProvider, provideUiBackgroundExecutorProvider, provideNotificationEntryManagerProvider, (Provider) statusBarStateControllerImplProvider, expansionStateLoggerProvider, provideNotificationPanelLoggerProvider));
    }

    @SuppressWarnings("unchecked")
    private void initialize4(final DependencyProvider dependencyProviderParam,
        final NightDisplayListenerModule nightDisplayListenerModuleParam,
        final SysUIUnfoldModule sysUIUnfoldModuleParam, final UserModule userModuleParam,
        final Optional<Pip> setPipParam,
        final Optional<LegacySplitScreen> setLegacySplitScreenParam,
        final Optional<SplitScreen> setSplitScreenParam, final Optional<AppPairs> setAppPairs,
        final Optional<OneHanded> setOneHandedParam, final Optional<Bubbles> setBubblesParam,
        final Optional<TaskViewFactory> setTaskViewFactoryParam,
        final Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        final Optional<ShellCommandHandler> setShellCommandHandlerParam,
        final ShellTransitions setTransitionsParam,
        final Optional<StartingSurface> setStartingSurfaceParam,
        final Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        final Optional<TaskSurfaceHelper> setTaskSurfaceHelper,
        final Optional<RecentTasks> setRecentTasksParam, final Optional<CompatUI> setCompatUIParam,
        final Optional<DragAndDrop> setDragAndDropParam) {
      this.foregroundServiceSectionControllerProvider = DoubleCheck.provider(ForegroundServiceSectionController_Factory.create(provideNotificationEntryManagerProvider, foregroundServiceDismissalFeatureControllerProvider));
      this.dynamicChildBindControllerProvider = DynamicChildBindController_Factory.create(rowContentBindStageProvider);
      this.provideNotificationViewHierarchyManagerProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideNotificationViewHierarchyManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, featureFlagsProvider, (Provider) notificationLockscreenUserManagerImplProvider, notificationGroupManagerLegacyProvider, provideVisualStabilityManagerProvider, (Provider) statusBarStateControllerImplProvider, provideNotificationEntryManagerProvider, keyguardBypassControllerProvider, setBubblesProvider, dynamicPrivacyControllerProvider, foregroundServiceSectionControllerProvider, dynamicChildBindControllerProvider, lowPriorityInflationHelperProvider, assistantFeedbackControllerProvider, keyguardUpdateMonitorProvider, (Provider) keyguardStateControllerImplProvider));
      this.userSwitcherControllerProvider = new DelegateFactory<>();
      this.accessibilityButtonTargetsObserverProvider = DoubleCheck.provider(AccessibilityButtonTargetsObserver_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.provideAccessibilityFloatingMenuControllerProvider = DoubleCheck.provider(DependencyProvider_ProvideAccessibilityFloatingMenuControllerFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider, accessibilityButtonTargetsObserverProvider, accessibilityButtonModeObserverProvider, keyguardUpdateMonitorProvider));
      this.lockscreenWallpaperProvider = DoubleCheck.provider(LockscreenWallpaper_Factory.create(DaggerGlobalRootComponent.this.provideWallpaperManagerProvider, FrameworkServicesModule_ProvideIWallPaperManagerFactory.create(), keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideNotificationMediaManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
      this.dozeServiceHostProvider = DoubleCheck.provider(DozeServiceHost_Factory.create(dozeLogProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, wakefulnessLifecycleProvider, (Provider) statusBarStateControllerImplProvider, bindDeviceProvisionedControllerProvider, provideHeadsUpManagerPhoneProvider, provideBatteryControllerProvider, scrimControllerProvider, biometricUnlockControllerProvider, newKeyguardViewMediatorProvider, assistManagerProvider, dozeScrimControllerProvider, keyguardUpdateMonitorProvider, pulseExpansionHandlerProvider, (Provider) notificationShadeWindowControllerImplProvider, notificationWakeUpCoordinatorProvider, authControllerProvider, notificationIconAreaControllerProvider));
      this.screenPinningRequestProvider = ScreenPinningRequest_Factory.create(DaggerGlobalRootComponent.this.contextProvider, optionalOfStatusBarProvider);
      this.volumeDialogControllerImplProvider = DoubleCheck.provider(VolumeDialogControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, (Provider) ringerModeTrackerImplProvider, (Provider) ThreadFactoryImpl_Factory.create(), DaggerGlobalRootComponent.this.provideAudioManagerProvider, DaggerGlobalRootComponent.this.provideNotificationManagerProvider, DaggerGlobalRootComponent.this.provideOptionalVibratorProvider, DaggerGlobalRootComponent.this.provideIAudioServiceProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider, wakefulnessLifecycleProvider));
      this.provideVolumeDialogProvider = VolumeModule_ProvideVolumeDialogFactory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) volumeDialogControllerImplProvider, accessibilityManagerWrapperProvider, bindDeviceProvisionedControllerProvider, provideConfigurationControllerProvider, mediaOutputDialogFactoryProvider, provideActivityStarterProvider, (Provider) tunerServiceImplProvider);
      this.volumeDialogComponentProvider = DoubleCheck.provider(VolumeDialogComponent_Factory.create(DaggerGlobalRootComponent.this.contextProvider, newKeyguardViewMediatorProvider, provideActivityStarterProvider, volumeDialogControllerImplProvider, provideDemoModeControllerProvider, DaggerGlobalRootComponent.this.pluginDependencyProvider, (Provider) extensionControllerImplProvider, (Provider) tunerServiceImplProvider, provideVolumeDialogProvider));
      this.provideCollapsedSbFragmentLogBufferProvider = DoubleCheck.provider(LogModule_ProvideCollapsedSbFragmentLogBufferFactory.create(logBufferFactoryProvider));
      this.disableFlagsLoggerProvider = DoubleCheck.provider(DisableFlagsLogger_Factory.create());
      this.collapsedStatusBarFragmentLoggerProvider = CollapsedStatusBarFragmentLogger_Factory.create(provideCollapsedSbFragmentLogBufferProvider, disableFlagsLoggerProvider);
      this.statusBarComponentFactoryProvider = new Provider<StatusBarComponent.Factory>() {
        @Override
        public StatusBarComponent.Factory get() {
          return new StatusBarComponentFactory();
        }
      };
      this.lightsOutNotifControllerProvider = DoubleCheck.provider(LightsOutNotifController_Factory.create(DaggerGlobalRootComponent.this.provideWindowManagerProvider, provideNotificationEntryManagerProvider, provideCommandQueueProvider));
      this.provideGroupExpansionManagerProvider = DoubleCheck.provider(NotificationsModule_ProvideGroupExpansionManagerFactory.create(featureFlagsProvider, provideGroupMembershipManagerProvider, notificationGroupManagerLegacyProvider));
      this.statusBarRemoteInputCallbackProvider = DoubleCheck.provider(StatusBarRemoteInputCallback_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideGroupExpansionManagerProvider, (Provider) notificationLockscreenUserManagerImplProvider, (Provider) keyguardStateControllerImplProvider, (Provider) statusBarStateControllerImplProvider, statusBarKeyguardViewManagerProvider, provideActivityStarterProvider, (Provider) shadeControllerImplProvider, provideCommandQueueProvider, actionClickLoggerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.activityIntentHelperProvider = DoubleCheck.provider(ActivityIntentHelper_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.statusBarNotificationActivityStarterLoggerProvider = StatusBarNotificationActivityStarterLogger_Factory.create(provideNotifInteractionLogBufferProvider);
      this.builderProvider4 = DoubleCheck.provider(StatusBarNotificationActivityStarter_Builder_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideUiBackgroundExecutorProvider, provideNotificationEntryManagerProvider, notifPipelineProvider, provideHeadsUpManagerPhoneProvider, provideActivityStarterProvider, notificationClickNotifierProvider, (Provider) statusBarStateControllerImplProvider, statusBarKeyguardViewManagerProvider, DaggerGlobalRootComponent.this.provideKeyguardManagerProvider, DaggerGlobalRootComponent.this.provideIDreamManagerProvider, provideBubblesManagerProvider, assistManagerProvider, provideNotificationRemoteInputManagerProvider, provideGroupMembershipManagerProvider, (Provider) notificationLockscreenUserManagerImplProvider, (Provider) shadeControllerImplProvider, (Provider) keyguardStateControllerImplProvider, (Provider) notificationInterruptStateProviderImplProvider, provideLockPatternUtilsProvider, statusBarRemoteInputCallbackProvider, activityIntentHelperProvider, featureFlagsProvider, provideMetricsLoggerProvider, statusBarNotificationActivityStarterLoggerProvider, provideOnUserInteractionCallbackProvider));
      this.providesViewMediatorCallbackProvider = new DelegateFactory<>();
      this.initControllerProvider = DoubleCheck.provider(InitController_Factory.create());
      this.provideTimeTickHandlerProvider = DoubleCheck.provider(DependencyProvider_ProvideTimeTickHandlerFactory.create(dependencyProviderParam));
      this.userInfoControllerImplProvider = DoubleCheck.provider(UserInfoControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.factoryProvider4 = OperatorNameViewController_Factory_Factory.create((Provider) darkIconDispatcherImplProvider, (Provider) networkControllerImplProvider, (Provider) tunerServiceImplProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, keyguardUpdateMonitorProvider);
      this.castControllerImplProvider = DoubleCheck.provider(CastControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.hotspotControllerImplProvider = DoubleCheck.provider(HotspotControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBgHandlerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.bluetoothControllerImplProvider = DoubleCheck.provider(BluetoothControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideBgLooperProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create(), provideLocalBluetoothControllerProvider));
      this.nextAlarmControllerImplProvider = DoubleCheck.provider(NextAlarmControllerImpl_Factory.create(DaggerGlobalRootComponent.this.provideAlarmManagerProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.rotationPolicyWrapperImplProvider = RotationPolicyWrapperImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.bindRotationPolicyWrapperProvider = DoubleCheck.provider((Provider) rotationPolicyWrapperImplProvider);
      this.providesDeviceStateRotationLockDefaultsProvider = StatusBarPolicyModule_ProvidesDeviceStateRotationLockDefaultsFactory.create(DaggerGlobalRootComponent.this.provideResourcesProvider);
      this.deviceStateRotationLockSettingControllerProvider = DoubleCheck.provider(DeviceStateRotationLockSettingController_Factory.create(secureSettingsImplProvider, bindRotationPolicyWrapperProvider, DaggerGlobalRootComponent.this.provideDeviceStateManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, providesDeviceStateRotationLockDefaultsProvider));
      this.rotationLockControllerImplProvider = DoubleCheck.provider(RotationLockControllerImpl_Factory.create(bindRotationPolicyWrapperProvider, deviceStateRotationLockSettingControllerProvider, providesDeviceStateRotationLockDefaultsProvider));
      this.provideDataSaverControllerProvider = DoubleCheck.provider(DependencyProvider_ProvideDataSaverControllerFactory.create(dependencyProviderParam, (Provider) networkControllerImplProvider));
      this.provideSensorPrivacyControllerProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideSensorPrivacyControllerFactory.create(DaggerGlobalRootComponent.this.provideSensorPrivacyManagerProvider));
      this.recordingControllerProvider = DoubleCheck.provider(RecordingController_Factory.create(providesBroadcastDispatcherProvider, (Provider) provideUserTrackerProvider));
      this.provideSharePreferencesProvider = DependencyProvider_ProvideSharePreferencesFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider);
      this.dateFormatUtilProvider = DateFormatUtil_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.providePrivacyLogBufferProvider = DoubleCheck.provider(LogModule_ProvidePrivacyLogBufferFactory.create(logBufferFactoryProvider));
      this.privacyLoggerProvider = PrivacyLogger_Factory.create(providePrivacyLogBufferProvider);
      this.privacyItemControllerProvider = DoubleCheck.provider(PrivacyItemController_Factory.create((Provider) appOpsControllerImplProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, provideBackgroundDelayableExecutorProvider, deviceConfigProxyProvider, provideUserTrackerProvider, privacyLoggerProvider, bindSystemClockProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.phoneStatusBarPolicyProvider = PhoneStatusBarPolicy_Factory.create((Provider) statusBarIconControllerImplProvider, provideCommandQueueProvider, providesBroadcastDispatcherProvider, provideUiBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, (Provider) castControllerImplProvider, (Provider) hotspotControllerImplProvider, (Provider) bluetoothControllerImplProvider, (Provider) nextAlarmControllerImplProvider, (Provider) userInfoControllerImplProvider, (Provider) rotationLockControllerImplProvider, provideDataSaverControllerProvider, (Provider) zenModeControllerImplProvider, bindDeviceProvisionedControllerProvider, (Provider) keyguardStateControllerImplProvider, (Provider) locationControllerImplProvider, provideSensorPrivacyControllerProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider, DaggerGlobalRootComponent.this.provideAlarmManagerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, recordingControllerProvider, DaggerGlobalRootComponent.this.provideTelecomManagerProvider, DaggerGlobalRootComponent.this.provideDisplayIdProvider, provideSharePreferencesProvider, dateFormatUtilProvider, (Provider) ringerModeTrackerImplProvider, privacyItemControllerProvider, privacyLoggerProvider);
      this.builderProvider5 = WakeLock_Builder_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.keyguardIndicationControllerProvider = DoubleCheck.provider(KeyguardIndicationController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, builderProvider5, (Provider) keyguardStateControllerImplProvider, (Provider) statusBarStateControllerImplProvider, keyguardUpdateMonitorProvider, (Provider) dockManagerImplProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideDevicePolicyManagerProvider, DaggerGlobalRootComponent.this.provideIBatteryStatsProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, (Provider) falsingManagerProxyProvider, provideLockPatternUtilsProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider, keyguardBypassControllerProvider));
      this.statusBarTouchableRegionManagerProvider = DoubleCheck.provider(StatusBarTouchableRegionManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) notificationShadeWindowControllerImplProvider, provideConfigurationControllerProvider, provideHeadsUpManagerPhoneProvider));
      this.factoryProvider5 = new DelegateFactory<>();
      this.wiredChargingRippleControllerProvider = DoubleCheck.provider(WiredChargingRippleController_Factory.create(commandRegistryProvider, provideBatteryControllerProvider, provideConfigurationControllerProvider, featureFlagsProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, bindSystemClockProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider));
      this.ongoingCallLoggerProvider = DoubleCheck.provider(OngoingCallLogger_Factory.create(DaggerGlobalRootComponent.this.provideUiEventLoggerProvider));
      this.provideSwipeAwayGestureLogBufferProvider = DoubleCheck.provider(LogModule_ProvideSwipeAwayGestureLogBufferFactory.create(logBufferFactoryProvider));
      this.swipeStatusBarAwayGestureLoggerProvider = SwipeStatusBarAwayGestureLogger_Factory.create(provideSwipeAwayGestureLogBufferProvider);
      this.swipeStatusBarAwayGestureHandlerProvider = DoubleCheck.provider(SwipeStatusBarAwayGestureHandler_Factory.create(DaggerGlobalRootComponent.this.contextProvider, statusBarWindowControllerProvider, swipeStatusBarAwayGestureLoggerProvider));
      this.provideOngoingCallControllerProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideOngoingCallControllerFactory.create(provideCommonNotifCollectionProvider, featureFlagsProvider, bindSystemClockProvider, provideActivityStarterProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider, ongoingCallLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, statusBarWindowControllerProvider, swipeStatusBarAwayGestureHandlerProvider, (Provider) statusBarStateControllerImplProvider));
      this.systemEventCoordinatorProvider = DoubleCheck.provider(SystemEventCoordinator_Factory.create(bindSystemClockProvider, provideBatteryControllerProvider, privacyItemControllerProvider, DaggerGlobalRootComponent.this.contextProvider));
      this.statusBarLocationPublisherProvider = DoubleCheck.provider(StatusBarLocationPublisher_Factory.create());
      this.systemEventChipAnimationControllerProvider = SystemEventChipAnimationController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, statusBarWindowControllerProvider, statusBarLocationPublisherProvider);
      this.systemStatusAnimationSchedulerProvider = DoubleCheck.provider(SystemStatusAnimationScheduler_Factory.create(systemEventCoordinatorProvider, systemEventChipAnimationControllerProvider, statusBarWindowControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, bindSystemClockProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider));
      this.statusBarHideIconsForBouncerManagerProvider = DoubleCheck.provider(StatusBarHideIconsForBouncerManager_Factory.create(provideCommandQueueProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.keyguardUnlockAnimationControllerProvider = DoubleCheck.provider(KeyguardUnlockAnimationController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) keyguardStateControllerImplProvider, newKeyguardViewMediatorProvider, (Provider) statusBarKeyguardViewManagerProvider, provideSmartspaceTransitionControllerProvider, featureFlagsProvider, biometricUnlockControllerProvider));
      this.providesMainMessageRouterProvider = SysUIConcurrencyModule_ProvidesMainMessageRouterFactory.create(DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider);
      this.provideActivityLaunchAnimatorProvider = DoubleCheck.provider(StatusBarDependenciesModule_ProvideActivityLaunchAnimatorFactory.create());
      this.provideStatusBarProvider = DoubleCheck.provider(StatusBarPhoneModule_ProvideStatusBarFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideNotificationsControllerProvider, fragmentServiceProvider, lightBarControllerProvider, provideAutoHideControllerProvider, statusBarWindowControllerProvider, keyguardUpdateMonitorProvider, statusBarSignalPolicyProvider, pulseExpansionHandlerProvider, notificationWakeUpCoordinatorProvider, keyguardBypassControllerProvider, (Provider) keyguardStateControllerImplProvider, provideHeadsUpManagerPhoneProvider, dynamicPrivacyControllerProvider, bypassHeadsUpNotifierProvider, (Provider) falsingManagerProxyProvider, falsingCollectorImplProvider, providesBroadcastDispatcherProvider, provideNotifShadeEventSourceProvider, provideNotificationEntryManagerProvider, provideNotificationGutsManagerProvider, provideNotificationLoggerProvider, (Provider) notificationInterruptStateProviderImplProvider, provideNotificationViewHierarchyManagerProvider, panelExpansionStateManagerProvider, newKeyguardViewMediatorProvider, DaggerGlobalRootComponent.this.provideDisplayMetricsProvider, provideMetricsLoggerProvider, provideUiBackgroundExecutorProvider, provideNotificationMediaManagerProvider, (Provider) notificationLockscreenUserManagerImplProvider, provideNotificationRemoteInputManagerProvider, userSwitcherControllerProvider, (Provider) networkControllerImplProvider, provideBatteryControllerProvider, sysuiColorExtractorProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, wakefulnessLifecycleProvider, (Provider) statusBarStateControllerImplProvider, provideBubblesManagerProvider, setBubblesProvider, provideVisualStabilityManagerProvider, bindDeviceProvisionedControllerProvider, navigationBarControllerProvider, provideAccessibilityFloatingMenuControllerProvider, assistManagerProvider, provideConfigurationControllerProvider, (Provider) notificationShadeWindowControllerImplProvider, dozeParametersProvider, scrimControllerProvider, lockscreenWallpaperProvider, lockscreenGestureLoggerProvider, biometricUnlockControllerProvider, dozeServiceHostProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, screenPinningRequestProvider, dozeScrimControllerProvider, (Provider) volumeDialogComponentProvider, provideCommandQueueProvider, collapsedStatusBarFragmentLoggerProvider, statusBarComponentFactoryProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, setLegacySplitScreenProvider, lightsOutNotifControllerProvider, builderProvider4, (Provider) shadeControllerImplProvider, statusBarKeyguardViewManagerProvider, providesViewMediatorCallbackProvider, initControllerProvider, provideTimeTickHandlerProvider, DaggerGlobalRootComponent.this.pluginDependencyProvider, keyguardDismissUtilProvider, (Provider) extensionControllerImplProvider, userInfoControllerImplProvider, factoryProvider4, phoneStatusBarPolicyProvider, keyguardIndicationControllerProvider, provideDemoModeControllerProvider, notificationShadeDepthControllerProvider, statusBarTouchableRegionManagerProvider, notificationIconAreaControllerProvider, factoryProvider5, wiredChargingRippleControllerProvider, wallpaperControllerProvider, provideOngoingCallControllerProvider, systemStatusAnimationSchedulerProvider, statusBarLocationPublisherProvider, (Provider) statusBarIconControllerImplProvider, statusBarHideIconsForBouncerManagerProvider, lockscreenShadeTransitionControllerProvider, featureFlagsProvider, keyguardUnlockAnimationControllerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, providesMainMessageRouterProvider, DaggerGlobalRootComponent.this.provideWallpaperManagerProvider, unlockedScreenOffAnimationControllerProvider, setStartingSurfaceProvider, (Provider) tunerServiceImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideActivityLaunchAnimatorProvider));
      DelegateFactory.setDelegate(optionalOfStatusBarProvider, PresentJdkOptionalInstanceProvider.of(provideStatusBarProvider));
      this.activityStarterDelegateProvider = DoubleCheck.provider(ActivityStarterDelegate_Factory.create(optionalOfStatusBarProvider));
      DelegateFactory.setDelegate(provideActivityStarterProvider, PluginModule_ProvideActivityStarterFactory.create(activityStarterDelegateProvider, DaggerGlobalRootComponent.this.pluginDependencyProvider));
      this.adapterProvider = UserDetailView_Adapter_Factory.create(DaggerGlobalRootComponent.this.contextProvider, userSwitcherControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, (Provider) falsingManagerProxyProvider);
      this.userDetailAdapterProvider = UserSwitcherController_UserDetailAdapter_Factory.create(DaggerGlobalRootComponent.this.contextProvider, adapterProvider);
      DelegateFactory.setDelegate(userSwitcherControllerProvider, DoubleCheck.provider(UserSwitcherController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, provideUserTrackerProvider, (Provider) keyguardStateControllerImplProvider, bindDeviceProvisionedControllerProvider, DaggerGlobalRootComponent.this.provideDevicePolicyManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideActivityStarterProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, (Provider) falsingManagerProxyProvider, telephonyListenerManagerProvider, DaggerGlobalRootComponent.this.provideIActivityTaskManagerProvider, userDetailAdapterProvider, secureSettingsImplProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideInteractionJankMonitorProvider, DaggerGlobalRootComponent.this.provideLatencyTrackerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideDialogLaunchAnimatorProvider)));
      this.keyguardStatusViewComponentFactoryProvider = new Provider<KeyguardStatusViewComponent.Factory>() {
        @Override
        public KeyguardStatusViewComponent.Factory get() {
          return new KeyguardStatusViewComponentFactory();
        }
      };
      this.keyguardDisplayManagerProvider = KeyguardDisplayManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, navigationBarControllerProvider, keyguardStatusViewComponentFactoryProvider, provideUiBackgroundExecutorProvider);
      this.sysUIUnfoldComponentFactoryProvider = new Provider<SysUIUnfoldComponent.Factory>() {
        @Override
        public SysUIUnfoldComponent.Factory get() {
          return new SysUIUnfoldComponentFactory();
        }
      };
      this.provideSysUIUnfoldComponentProvider = DoubleCheck.provider(SysUIUnfoldModule_ProvideSysUIUnfoldComponentFactory.create(sysUIUnfoldModuleParam, DaggerGlobalRootComponent.this.provideUnfoldTransitionProgressProvider, DaggerGlobalRootComponent.this.provideNaturalRotationProgressProvider, DaggerGlobalRootComponent.this.provideStatusBarScopedTransitionProvider, sysUIUnfoldComponentFactoryProvider));
      DelegateFactory.setDelegate(newKeyguardViewMediatorProvider, DoubleCheck.provider(KeyguardModule_NewKeyguardViewMediatorFactory.create(DaggerGlobalRootComponent.this.contextProvider, falsingCollectorImplProvider, provideLockPatternUtilsProvider, providesBroadcastDispatcherProvider, (Provider) statusBarKeyguardViewManagerProvider, dismissCallbackRegistryProvider, keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, DaggerGlobalRootComponent.this.provideTrustManagerProvider, userSwitcherControllerProvider, provideUiBackgroundExecutorProvider, deviceConfigProxyProvider, navigationModeControllerProvider, keyguardDisplayManagerProvider, dozeParametersProvider, provideSysUIUnfoldComponentProvider, (Provider) statusBarStateControllerImplProvider, (Provider) keyguardStateControllerImplProvider, keyguardUnlockAnimationControllerProvider, unlockedScreenOffAnimationControllerProvider, notificationShadeDepthControllerProvider, (Provider) notificationShadeWindowControllerImplProvider)));
      DelegateFactory.setDelegate(providesViewMediatorCallbackProvider, DependencyProvider_ProvidesViewMediatorCallbackFactory.create(dependencyProviderParam, newKeyguardViewMediatorProvider));
      this.keyguardSecurityModelProvider = DoubleCheck.provider(KeyguardSecurityModel_Factory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, provideLockPatternUtilsProvider, keyguardUpdateMonitorProvider));
      this.keyguardBouncerComponentFactoryProvider = new Provider<KeyguardBouncerComponent.Factory>() {
        @Override
        public KeyguardBouncerComponent.Factory get() {
          return new KeyguardBouncerComponentFactory();
        }
      };
      this.factoryProvider6 = KeyguardBouncer_Factory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesViewMediatorCallbackProvider, dismissCallbackRegistryProvider, falsingCollectorImplProvider, (Provider) keyguardStateControllerImplProvider, keyguardUpdateMonitorProvider, keyguardBypassControllerProvider, provideHandlerProvider, keyguardSecurityModelProvider, keyguardBouncerComponentFactoryProvider);
      this.factoryProvider7 = KeyguardMessageAreaController_Factory_Factory.create(keyguardUpdateMonitorProvider, provideConfigurationControllerProvider);
      DelegateFactory.setDelegate(statusBarKeyguardViewManagerProvider, DoubleCheck.provider(StatusBarKeyguardViewManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesViewMediatorCallbackProvider, provideLockPatternUtilsProvider, (Provider) statusBarStateControllerImplProvider, provideConfigurationControllerProvider, keyguardUpdateMonitorProvider, navigationModeControllerProvider, (Provider) dockManagerImplProvider, (Provider) notificationShadeWindowControllerImplProvider, (Provider) keyguardStateControllerImplProvider, provideNotificationMediaManagerProvider, factoryProvider6, wakefulnessLifecycleProvider, unlockedScreenOffAnimationControllerProvider, factoryProvider7, (Provider) shadeControllerImplProvider, optionalOfStatusBarProvider)));
      this.udfpsHapticsSimulatorProvider = DoubleCheck.provider(UdfpsHapticsSimulator_Factory.create(commandRegistryProvider, DaggerGlobalRootComponent.this.provideVibratorProvider, keyguardUpdateMonitorProvider));
      this.optionalOfUdfpsHbmProvider = absentJdkOptionalProvider();
      this.udfpsControllerProvider = DoubleCheck.provider(UdfpsController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideExecutionProvider, providerLayoutInflaterProvider, DaggerGlobalRootComponent.this.providesFingerprintManagerProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, (Provider) statusBarStateControllerImplProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, panelExpansionStateManagerProvider, statusBarKeyguardViewManagerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, keyguardUpdateMonitorProvider, (Provider) falsingManagerProxyProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, lockscreenShadeTransitionControllerProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, DaggerGlobalRootComponent.this.provideVibratorProvider, udfpsHapticsSimulatorProvider, optionalOfUdfpsHbmProvider, (Provider) keyguardStateControllerImplProvider, keyguardBypassControllerProvider, DaggerGlobalRootComponent.this.provideDisplayManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideConfigurationControllerProvider, bindSystemClockProvider, unlockedScreenOffAnimationControllerProvider, systemUIDialogManagerProvider));
      this.sidefpsControllerProvider = DoubleCheck.provider(SidefpsController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providerLayoutInflaterProvider, DaggerGlobalRootComponent.this.providesFingerprintManagerProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, DaggerGlobalRootComponent.this.provideActivityTaskManagerProvider, overviewProxyServiceProvider, DaggerGlobalRootComponent.this.provideDisplayManagerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
      DelegateFactory.setDelegate(authControllerProvider, DoubleCheck.provider(AuthController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideExecutionProvider, provideCommandQueueProvider, DaggerGlobalRootComponent.this.provideActivityTaskManagerProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, DaggerGlobalRootComponent.this.providesFingerprintManagerProvider, DaggerGlobalRootComponent.this.provideFaceManagerProvider, udfpsControllerProvider, sidefpsControllerProvider, DaggerGlobalRootComponent.this.provideDisplayManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider)));
      DelegateFactory.setDelegate(keyguardUpdateMonitorProvider, DoubleCheck.provider(KeyguardUpdateMonitor_Factory.create(DaggerGlobalRootComponent.this.contextProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create(), providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, (Provider) ringerModeTrackerImplProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, (Provider) statusBarStateControllerImplProvider, provideLockPatternUtilsProvider, authControllerProvider, telephonyListenerManagerProvider, DaggerGlobalRootComponent.this.provideInteractionJankMonitorProvider, DaggerGlobalRootComponent.this.provideLatencyTrackerProvider)));
      DelegateFactory.setDelegate(keyguardStateControllerImplProvider, DoubleCheck.provider(KeyguardStateControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, keyguardUpdateMonitorProvider, provideLockPatternUtilsProvider, provideSmartspaceTransitionControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider)));
      this.brightLineFalsingManagerProvider = BrightLineFalsingManager_Factory.create(falsingDataProvider, provideMetricsLoggerProvider, namedSetOfFalsingClassifierProvider, singleTapClassifierProvider, doubleTapClassifierProvider, historyTrackerProvider, (Provider) keyguardStateControllerImplProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, GlobalModule_ProvideIsTestHarnessFactory.create());
      DelegateFactory.setDelegate(falsingManagerProxyProvider, DoubleCheck.provider(FalsingManagerProxy_Factory.create(DaggerGlobalRootComponent.this.providesPluginManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, deviceConfigProxyProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, brightLineFalsingManagerProvider)));
      DelegateFactory.setDelegate(factoryProvider5, BrightnessSliderController_Factory_Factory.create((Provider) falsingManagerProxyProvider));
      this.brightnessDialogProvider = BrightnessDialog_Factory.create(providesBroadcastDispatcherProvider, factoryProvider5, provideBgHandlerProvider);
      this.usbDebuggingActivityProvider = UsbDebuggingActivity_Factory.create(providesBroadcastDispatcherProvider);
      this.usbDebuggingSecondaryUserActivityProvider = UsbDebuggingSecondaryUserActivity_Factory.create(providesBroadcastDispatcherProvider);
      this.userCreatorProvider = UserCreator_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider);
      this.provideEditUserInfoControllerProvider = UserModule_ProvideEditUserInfoControllerFactory.create(userModuleParam);
      this.createUserActivityProvider = CreateUserActivity_Factory.create(userCreatorProvider, provideEditUserInfoControllerProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider);
      this.tvNotificationHandlerProvider = TvNotificationHandler_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideNotificationListenerProvider);
      this.tvNotificationPanelActivityProvider = TvNotificationPanelActivity_Factory.create(tvNotificationHandlerProvider);
      this.peopleSpaceActivityProvider = PeopleSpaceActivity_Factory.create(peopleSpaceWidgetManagerProvider);
    }

    @SuppressWarnings("unchecked")
    private void initialize5(final DependencyProvider dependencyProviderParam,
        final NightDisplayListenerModule nightDisplayListenerModuleParam,
        final SysUIUnfoldModule sysUIUnfoldModuleParam, final UserModule userModuleParam,
        final Optional<Pip> setPipParam,
        final Optional<LegacySplitScreen> setLegacySplitScreenParam,
        final Optional<SplitScreen> setSplitScreenParam, final Optional<AppPairs> setAppPairs,
        final Optional<OneHanded> setOneHandedParam, final Optional<Bubbles> setBubblesParam,
        final Optional<TaskViewFactory> setTaskViewFactoryParam,
        final Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        final Optional<ShellCommandHandler> setShellCommandHandlerParam,
        final ShellTransitions setTransitionsParam,
        final Optional<StartingSurface> setStartingSurfaceParam,
        final Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        final Optional<TaskSurfaceHelper> setTaskSurfaceHelper,
        final Optional<RecentTasks> setRecentTasksParam, final Optional<CompatUI> setCompatUIParam,
        final Optional<DragAndDrop> setDragAndDropParam) {
      this.imageExporterProvider = ImageExporter_Factory.create(DaggerGlobalRootComponent.this.provideContentResolverProvider);
      this.longScreenshotDataProvider = DoubleCheck.provider(LongScreenshotData_Factory.create());
      this.longScreenshotActivityProvider = LongScreenshotActivity_Factory.create(DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, imageExporterProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, provideBackgroundExecutorProvider, longScreenshotDataProvider);
      this.launchConversationActivityProvider = LaunchConversationActivity_Factory.create(provideNotificationEntryManagerProvider, provideBubblesManagerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, provideCommandQueueProvider);
      this.sensorUseStartedActivityProvider = SensorUseStartedActivity_Factory.create(provideIndividualSensorPrivacyControllerProvider, (Provider) keyguardStateControllerImplProvider, keyguardDismissUtilProvider, provideBgHandlerProvider);
      this.tvUnblockSensorActivityProvider = TvUnblockSensorActivity_Factory.create(provideIndividualSensorPrivacyControllerProvider);
      this.provideExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideExecutorFactory.create(provideBgLooperProvider));
      this.controlsListingControllerImplProvider = DoubleCheck.provider(ControlsListingControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideExecutorProvider, provideUserTrackerProvider));
      this.controlsControllerImplProvider = new DelegateFactory<>();
      this.globalActionsComponentProvider = new DelegateFactory<>();
      this.providesControlsFeatureEnabledProvider = DoubleCheck.provider(ControlsModule_ProvidesControlsFeatureEnabledFactory.create(DaggerGlobalRootComponent.this.providePackageManagerProvider));
      this.controlsUiControllerImplProvider = new DelegateFactory<>();
      this.controlsComponentProvider = DoubleCheck.provider(ControlsComponent_Factory.create(providesControlsFeatureEnabledProvider, DaggerGlobalRootComponent.this.contextProvider, (Provider) controlsControllerImplProvider, (Provider) controlsUiControllerImplProvider, (Provider) controlsListingControllerImplProvider, provideLockPatternUtilsProvider, (Provider) keyguardStateControllerImplProvider, provideUserTrackerProvider, secureSettingsImplProvider));
      this.globalActionsDialogLiteProvider = GlobalActionsDialogLite_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) globalActionsComponentProvider, DaggerGlobalRootComponent.this.provideAudioManagerProvider, DaggerGlobalRootComponent.this.provideIDreamManagerProvider, DaggerGlobalRootComponent.this.provideDevicePolicyManagerProvider, provideLockPatternUtilsProvider, providesBroadcastDispatcherProvider, globalSettingsImplProvider, secureSettingsImplProvider, DaggerGlobalRootComponent.this.provideVibratorProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, provideConfigurationControllerProvider, (Provider) keyguardStateControllerImplProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, DaggerGlobalRootComponent.this.provideTrustManagerProvider, DaggerGlobalRootComponent.this.provideIActivityManagerProvider, DaggerGlobalRootComponent.this.provideTelecomManagerProvider, provideMetricsLoggerProvider, sysuiColorExtractorProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, (Provider) notificationShadeWindowControllerImplProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, (Provider) ringerModeTrackerImplProvider, provideSysUiStateProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider, optionalOfStatusBarProvider, keyguardUpdateMonitorProvider, provideDialogLaunchAnimatorProvider, systemUIDialogManagerProvider, controlsComponentProvider);
      this.globalActionsImplProvider = GlobalActionsImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, globalActionsDialogLiteProvider, blurUtilsProvider, (Provider) keyguardStateControllerImplProvider, bindDeviceProvisionedControllerProvider);
      DelegateFactory.setDelegate(globalActionsComponentProvider, DoubleCheck.provider(GlobalActionsComponent_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, (Provider) extensionControllerImplProvider, (Provider) globalActionsImplProvider, statusBarKeyguardViewManagerProvider)));
      this.setTaskViewFactoryProvider = InstanceFactory.create(setTaskViewFactoryParam);
      this.controlsMetricsLoggerImplProvider = DoubleCheck.provider(ControlsMetricsLoggerImpl_Factory.create());
      this.controlActionCoordinatorImplProvider = DoubleCheck.provider(ControlActionCoordinatorImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, provideActivityStarterProvider, (Provider) keyguardStateControllerImplProvider, globalActionsComponentProvider, setTaskViewFactoryProvider, providesBroadcastDispatcherProvider, (Provider) controlsUiControllerImplProvider, (Provider) controlsMetricsLoggerImplProvider));
      this.customIconCacheProvider = DoubleCheck.provider(CustomIconCache_Factory.create());
      DelegateFactory.setDelegate(controlsUiControllerImplProvider, DoubleCheck.provider(ControlsUiControllerImpl_Factory.create((Provider) controlsControllerImplProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, provideBackgroundDelayableExecutorProvider, (Provider) controlsListingControllerImplProvider, provideSharePreferencesProvider, (Provider) controlActionCoordinatorImplProvider, provideActivityStarterProvider, (Provider) shadeControllerImplProvider, customIconCacheProvider, (Provider) controlsMetricsLoggerImplProvider, (Provider) keyguardStateControllerImplProvider)));
      this.controlsBindingControllerImplProvider = DoubleCheck.provider(ControlsBindingControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundDelayableExecutorProvider, (Provider) controlsControllerImplProvider, provideUserTrackerProvider));
      this.optionalOfControlsFavoritePersistenceWrapperProvider = absentJdkOptionalProvider();
      DelegateFactory.setDelegate(controlsControllerImplProvider, DoubleCheck.provider(ControlsControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundDelayableExecutorProvider, (Provider) controlsUiControllerImplProvider, (Provider) controlsBindingControllerImplProvider, (Provider) controlsListingControllerImplProvider, providesBroadcastDispatcherProvider, optionalOfControlsFavoritePersistenceWrapperProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, provideUserTrackerProvider)));
      this.controlsProviderSelectorActivityProvider = ControlsProviderSelectorActivity_Factory.create(DaggerGlobalRootComponent.this.provideMainExecutorProvider, provideBackgroundExecutorProvider, (Provider) controlsListingControllerImplProvider, (Provider) controlsControllerImplProvider, providesBroadcastDispatcherProvider, (Provider) controlsUiControllerImplProvider);
      this.controlsFavoritingActivityProvider = ControlsFavoritingActivity_Factory.create(DaggerGlobalRootComponent.this.provideMainExecutorProvider, controlsControllerImplProvider, (Provider) controlsListingControllerImplProvider, providesBroadcastDispatcherProvider, (Provider) controlsUiControllerImplProvider);
      this.controlsEditingActivityProvider = ControlsEditingActivity_Factory.create(controlsControllerImplProvider, providesBroadcastDispatcherProvider, customIconCacheProvider, (Provider) controlsUiControllerImplProvider);
      this.controlsRequestDialogProvider = ControlsRequestDialog_Factory.create((Provider) controlsControllerImplProvider, providesBroadcastDispatcherProvider, (Provider) controlsListingControllerImplProvider);
      this.controlsActivityProvider = ControlsActivity_Factory.create((Provider) controlsUiControllerImplProvider, providesBroadcastDispatcherProvider);
      this.walletActivityProvider = WalletActivity_Factory.create((Provider) keyguardStateControllerImplProvider, keyguardDismissUtilProvider, provideActivityStarterProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, falsingCollectorImplProvider, provideUserTrackerProvider, keyguardUpdateMonitorProvider, statusBarKeyguardViewManagerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider);
      this.mapOfClassOfAndProviderOfActivityProvider = MapProviderFactory.<Class<?>, Activity>builder(19).put(TunerActivity.class, (Provider) tunerActivityProvider).put(ForegroundServicesDialog.class, (Provider) ForegroundServicesDialog_Factory.create()).put(WorkLockActivity.class, (Provider) workLockActivityProvider).put(BrightnessDialog.class, (Provider) brightnessDialogProvider).put(UsbDebuggingActivity.class, (Provider) usbDebuggingActivityProvider).put(UsbDebuggingSecondaryUserActivity.class, (Provider) usbDebuggingSecondaryUserActivityProvider).put(CreateUserActivity.class, (Provider) createUserActivityProvider).put(TvNotificationPanelActivity.class, (Provider) tvNotificationPanelActivityProvider).put(PeopleSpaceActivity.class, (Provider) peopleSpaceActivityProvider).put(LongScreenshotActivity.class, (Provider) longScreenshotActivityProvider).put(LaunchConversationActivity.class, (Provider) launchConversationActivityProvider).put(SensorUseStartedActivity.class, (Provider) sensorUseStartedActivityProvider).put(TvUnblockSensorActivity.class, (Provider) tvUnblockSensorActivityProvider).put(ControlsProviderSelectorActivity.class, (Provider) controlsProviderSelectorActivityProvider).put(ControlsFavoritingActivity.class, (Provider) controlsFavoritingActivityProvider).put(ControlsEditingActivity.class, (Provider) controlsEditingActivityProvider).put(ControlsRequestDialog.class, (Provider) controlsRequestDialogProvider).put(ControlsActivity.class, (Provider) controlsActivityProvider).put(WalletActivity.class, (Provider) walletActivityProvider).build();
      this.dozeComponentBuilderProvider = new Provider<DozeComponent.Builder>() {
        @Override
        public DozeComponent.Builder get() {
          return new DozeComponentFactory();
        }
      };
      this.dozeServiceProvider = DozeService_Factory.create(dozeComponentBuilderProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider);
      this.keyguardLifecyclesDispatcherProvider = DoubleCheck.provider(KeyguardLifecyclesDispatcher_Factory.create(DaggerGlobalRootComponent.this.screenLifecycleProvider, wakefulnessLifecycleProvider));
      this.keyguardServiceProvider = KeyguardService_Factory.create(newKeyguardViewMediatorProvider, keyguardLifecyclesDispatcherProvider, setTransitionsProvider);
      this.dumpHandlerProvider = DumpHandler_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, logBufferEulogizerProvider);
      this.logBufferFreezerProvider = LogBufferFreezer_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider);
      this.batteryStateNotifierProvider = BatteryStateNotifier_Factory.create(provideBatteryControllerProvider, DaggerGlobalRootComponent.this.provideNotificationManagerProvider, provideDelayableExecutorProvider, DaggerGlobalRootComponent.this.contextProvider);
      this.systemUIServiceProvider = SystemUIService_Factory.create(DaggerGlobalRootComponent.this.provideMainHandlerProvider, dumpHandlerProvider, providesBroadcastDispatcherProvider, logBufferFreezerProvider, batteryStateNotifierProvider);
      this.systemUIAuxiliaryDumpServiceProvider = SystemUIAuxiliaryDumpService_Factory.create(dumpHandlerProvider);
      this.provideLongRunningLooperProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideLongRunningLooperFactory.create());
      this.provideLongRunningExecutorProvider = DoubleCheck.provider(SysUIConcurrencyModule_ProvideLongRunningExecutorFactory.create(provideLongRunningLooperProvider));
      this.recordingServiceProvider = RecordingService_Factory.create(recordingControllerProvider, provideLongRunningExecutorProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, DaggerGlobalRootComponent.this.provideNotificationManagerProvider, (Provider) provideUserTrackerProvider, keyguardDismissUtilProvider);
      this.screenshotSmartActionsProvider = DoubleCheck.provider(ScreenshotSmartActions_Factory.create());
      this.screenshotNotificationsControllerProvider = ScreenshotNotificationsController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider);
      this.scrollCaptureClientProvider = ScrollCaptureClient_Factory.create(DaggerGlobalRootComponent.this.provideIWindowManagerProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.contextProvider);
      this.imageTileSetProvider = ImageTileSet_Factory.create(provideHandlerProvider);
      this.scrollCaptureControllerProvider = ScrollCaptureController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundExecutorProvider, scrollCaptureClientProvider, imageTileSetProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider);
      this.screenshotControllerProvider = ScreenshotController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, screenshotSmartActionsProvider, screenshotNotificationsControllerProvider, scrollCaptureClientProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, imageExporterProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, scrollCaptureControllerProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, longScreenshotDataProvider, DaggerGlobalRootComponent.this.provideActivityManagerProvider);
      this.takeScreenshotServiceProvider = TakeScreenshotService_Factory.create(screenshotControllerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, screenshotNotificationsControllerProvider);
      this.mapOfClassOfAndProviderOfServiceProvider = MapProviderFactory.<Class<?>, Service>builder(7).put(DozeService.class, (Provider) dozeServiceProvider).put(ImageWallpaper.class, (Provider) ImageWallpaper_Factory.create()).put(KeyguardService.class, (Provider) keyguardServiceProvider).put(SystemUIService.class, (Provider) systemUIServiceProvider).put(SystemUIAuxiliaryDumpService.class, (Provider) systemUIAuxiliaryDumpServiceProvider).put(RecordingService.class, (Provider) recordingServiceProvider).put(TakeScreenshotService.class, (Provider) takeScreenshotServiceProvider).build();
      this.providesBackgroundMessageRouterProvider = SysUIConcurrencyModule_ProvidesBackgroundMessageRouterFactory.create(provideBackgroundDelayableExecutorProvider);
      this.provideLeakReportEmailProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideLeakReportEmailFactory.create());
      this.leakReporterProvider = DoubleCheck.provider(LeakReporter_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideLeakDetectorProvider, provideLeakReportEmailProvider));
      this.garbageMonitorProvider = DoubleCheck.provider(GarbageMonitor_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundDelayableExecutorProvider, providesBackgroundMessageRouterProvider, provideLeakDetectorProvider, leakReporterProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.serviceProvider = DoubleCheck.provider(GarbageMonitor_Service_Factory.create(DaggerGlobalRootComponent.this.contextProvider, garbageMonitorProvider));
      this.instantAppNotifierProvider = DoubleCheck.provider(InstantAppNotifier_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, provideUiBackgroundExecutorProvider, setLegacySplitScreenProvider));
      this.latencyTesterProvider = DoubleCheck.provider(LatencyTester_Factory.create(DaggerGlobalRootComponent.this.contextProvider, biometricUnlockControllerProvider, providesBroadcastDispatcherProvider));
      this.powerUIProvider = DoubleCheck.provider(PowerUI_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, provideCommandQueueProvider, optionalOfStatusBarProvider));
      this.privacyDotViewControllerProvider = DoubleCheck.provider(PrivacyDotViewController_Factory.create(DaggerGlobalRootComponent.this.provideMainExecutorProvider, (Provider) statusBarStateControllerImplProvider, provideConfigurationControllerProvider, statusBarContentInsetsProvider, systemStatusAnimationSchedulerProvider));
      this.screenDecorationsProvider = DoubleCheck.provider(ScreenDecorations_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, secureSettingsImplProvider, providesBroadcastDispatcherProvider, (Provider) tunerServiceImplProvider, provideUserTrackerProvider, privacyDotViewControllerProvider, (Provider) ThreadFactoryImpl_Factory.create()));
      this.shortcutKeyDispatcherProvider = DoubleCheck.provider(ShortcutKeyDispatcher_Factory.create(DaggerGlobalRootComponent.this.contextProvider, setLegacySplitScreenProvider));
      this.sliceBroadcastRelayHandlerProvider = DoubleCheck.provider(SliceBroadcastRelayHandler_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider));
      this.provideThemeOverlayManagerProvider = DoubleCheck.provider(DependencyProvider_ProvideThemeOverlayManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, DaggerGlobalRootComponent.this.provideOverlayManagerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.systemSettingsImplProvider = SystemSettingsImpl_Factory.create(DaggerGlobalRootComponent.this.provideContentResolverProvider);
      this.themeOverlayControllerProvider = DoubleCheck.provider(ThemeOverlayController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider, provideBgHandlerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, provideBackgroundExecutorProvider, provideThemeOverlayManagerProvider, secureSettingsImplProvider, DaggerGlobalRootComponent.this.provideWallpaperManagerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, bindDeviceProvisionedControllerProvider, provideUserTrackerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, featureFlagsProvider, wakefulnessLifecycleProvider, provideConfigurationControllerProvider, systemSettingsImplProvider));
      this.provideToastLogBufferProvider = DoubleCheck.provider(LogModule_ProvideToastLogBufferFactory.create(logBufferFactoryProvider));
      this.toastLoggerProvider = ToastLogger_Factory.create(provideToastLogBufferProvider);
      this.toastUIProvider = DoubleCheck.provider(ToastUI_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, toastFactoryProvider, toastLoggerProvider));
      this.tvStatusBarProvider = DoubleCheck.provider(TvStatusBar_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, assistManagerProvider));
      this.tvNotificationPanelProvider = DoubleCheck.provider(TvNotificationPanel_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider));
      this.tvOngoingPrivacyChipProvider = DoubleCheck.provider(TvOngoingPrivacyChip_Factory.create(DaggerGlobalRootComponent.this.contextProvider, privacyItemControllerProvider));
      this.volumeUIProvider = DoubleCheck.provider(VolumeUI_Factory.create(DaggerGlobalRootComponent.this.contextProvider, volumeDialogComponentProvider));
      this.providesModeSwitchesControllerProvider = DoubleCheck.provider(DependencyProvider_ProvidesModeSwitchesControllerFactory.create(dependencyProviderParam, DaggerGlobalRootComponent.this.contextProvider));
      this.windowMagnificationProvider = DoubleCheck.provider(WindowMagnification_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideCommandQueueProvider, providesModeSwitchesControllerProvider, provideSysUiStateProvider, overviewProxyServiceProvider));
      this.setHideDisplayCutoutProvider = InstanceFactory.create(setHideDisplayCutoutParam);
      this.setShellCommandHandlerProvider = InstanceFactory.create(setShellCommandHandlerParam);
      this.setCompatUIProvider = InstanceFactory.create(setCompatUIParam);
      this.setDragAndDropProvider = InstanceFactory.create(setDragAndDropParam);
      this.wMShellProvider = DoubleCheck.provider(WMShell_Factory.create(DaggerGlobalRootComponent.this.contextProvider, setPipProvider, setLegacySplitScreenProvider, setSplitScreenProvider, setOneHandedProvider, setHideDisplayCutoutProvider, setShellCommandHandlerProvider, setCompatUIProvider, setDragAndDropProvider, provideCommandQueueProvider, provideConfigurationControllerProvider, keyguardUpdateMonitorProvider, navigationModeControllerProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, provideSysUiStateProvider, protoTracerProvider, wakefulnessLifecycleProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider));
      this.provideTaskStackChangeListenersProvider = DoubleCheck.provider(DependencyProvider_ProvideTaskStackChangeListenersFactory.create(dependencyProviderParam));
      this.homeSoundEffectControllerProvider = DoubleCheck.provider(HomeSoundEffectController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideAudioManagerProvider, provideTaskStackChangeListenersProvider, provideActivityManagerWrapperProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider));
      this.mapOfClassOfAndProviderOfSystemUIProvider = MapProviderFactory.<Class<?>, SystemUI>builder(22).put(AuthController.class, (Provider) authControllerProvider).put(GarbageMonitor.Service.class, (Provider) serviceProvider).put(GlobalActionsComponent.class, (Provider) globalActionsComponentProvider).put(InstantAppNotifier.class, (Provider) instantAppNotifierProvider).put(KeyguardViewMediator.class, (Provider) newKeyguardViewMediatorProvider).put(LatencyTester.class, (Provider) latencyTesterProvider).put(PowerUI.class, (Provider) powerUIProvider).put(Recents.class, (Provider) provideRecentsProvider).put(ScreenDecorations.class, (Provider) screenDecorationsProvider).put(ShortcutKeyDispatcher.class, (Provider) shortcutKeyDispatcherProvider).put(SliceBroadcastRelayHandler.class, (Provider) sliceBroadcastRelayHandlerProvider).put(StatusBar.class, (Provider) provideStatusBarProvider).put(SystemActions.class, (Provider) systemActionsProvider).put(ThemeOverlayController.class, (Provider) themeOverlayControllerProvider).put(ToastUI.class, (Provider) toastUIProvider).put(TvStatusBar.class, (Provider) tvStatusBarProvider).put(TvNotificationPanel.class, (Provider) tvNotificationPanelProvider).put(TvOngoingPrivacyChip.class, (Provider) tvOngoingPrivacyChipProvider).put(VolumeUI.class, (Provider) volumeUIProvider).put(WindowMagnification.class, (Provider) windowMagnificationProvider).put(WMShell.class, (Provider) wMShellProvider).put(HomeSoundEffectController.class, (Provider) homeSoundEffectControllerProvider).build();
      this.overviewProxyRecentsImplProvider = DoubleCheck.provider(OverviewProxyRecentsImpl_Factory.create(optionalOfStatusBarProvider));
      this.mapOfClassOfAndProviderOfRecentsImplementationProvider = MapProviderFactory.<Class<?>, RecentsImplementation>builder(1).put(OverviewProxyRecentsImpl.class, (Provider) overviewProxyRecentsImplProvider).build();
      this.actionProxyReceiverProvider = ActionProxyReceiver_Factory.create(optionalOfStatusBarProvider, provideActivityManagerWrapperProvider, screenshotSmartActionsProvider);
      this.deleteScreenshotReceiverProvider = DeleteScreenshotReceiver_Factory.create(screenshotSmartActionsProvider, provideBackgroundExecutorProvider);
      this.smartActionsReceiverProvider = SmartActionsReceiver_Factory.create(screenshotSmartActionsProvider);
      this.mediaOutputDialogReceiverProvider = MediaOutputDialogReceiver_Factory.create(mediaOutputDialogFactoryProvider);
      this.peopleSpaceWidgetPinnedReceiverProvider = PeopleSpaceWidgetPinnedReceiver_Factory.create(peopleSpaceWidgetManagerProvider);
      this.peopleSpaceWidgetProvider = PeopleSpaceWidgetProvider_Factory.create(peopleSpaceWidgetManagerProvider);
      this.mapOfClassOfAndProviderOfBroadcastReceiverProvider = MapProviderFactory.<Class<?>, BroadcastReceiver>builder(6).put(ActionProxyReceiver.class, (Provider) actionProxyReceiverProvider).put(DeleteScreenshotReceiver.class, (Provider) deleteScreenshotReceiverProvider).put(SmartActionsReceiver.class, (Provider) smartActionsReceiverProvider).put(MediaOutputDialogReceiver.class, (Provider) mediaOutputDialogReceiverProvider).put(PeopleSpaceWidgetPinnedReceiver.class, (Provider) peopleSpaceWidgetPinnedReceiverProvider).put(PeopleSpaceWidgetProvider.class, (Provider) peopleSpaceWidgetProvider).build();
      DelegateFactory.setDelegate(contextComponentResolverProvider, DoubleCheck.provider(ContextComponentResolver_Factory.create(mapOfClassOfAndProviderOfActivityProvider, mapOfClassOfAndProviderOfServiceProvider, mapOfClassOfAndProviderOfSystemUIProvider, mapOfClassOfAndProviderOfRecentsImplementationProvider, mapOfClassOfAndProviderOfBroadcastReceiverProvider)));
      this.flashlightControllerImplProvider = DoubleCheck.provider(FlashlightControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      this.provideNightDisplayListenerProvider = NightDisplayListenerModule_ProvideNightDisplayListenerFactory.create(nightDisplayListenerModuleParam, DaggerGlobalRootComponent.this.contextProvider, provideBgHandlerProvider);
      this.provideReduceBrightColorsListenerProvider = DoubleCheck.provider(DependencyProvider_ProvideReduceBrightColorsListenerFactory.create(dependencyProviderParam, provideBgHandlerProvider, provideUserTrackerProvider, DaggerGlobalRootComponent.this.provideColorDisplayManagerProvider, secureSettingsImplProvider));
      this.managedProfileControllerImplProvider = DoubleCheck.provider(ManagedProfileControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesBroadcastDispatcherProvider));
      this.accessibilityControllerProvider = DoubleCheck.provider(AccessibilityController_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.tunablePaddingServiceProvider = DoubleCheck.provider(TunablePadding_TunablePaddingService_Factory.create((Provider) tunerServiceImplProvider));
      this.uiOffloadThreadProvider = DoubleCheck.provider(UiOffloadThread_Factory.create());
    }

    @SuppressWarnings("unchecked")
    private void initialize6(final DependencyProvider dependencyProviderParam,
        final NightDisplayListenerModule nightDisplayListenerModuleParam,
        final SysUIUnfoldModule sysUIUnfoldModuleParam, final UserModule userModuleParam,
        final Optional<Pip> setPipParam,
        final Optional<LegacySplitScreen> setLegacySplitScreenParam,
        final Optional<SplitScreen> setSplitScreenParam, final Optional<AppPairs> setAppPairs,
        final Optional<OneHanded> setOneHandedParam, final Optional<Bubbles> setBubblesParam,
        final Optional<TaskViewFactory> setTaskViewFactoryParam,
        final Optional<HideDisplayCutout> setHideDisplayCutoutParam,
        final Optional<ShellCommandHandler> setShellCommandHandlerParam,
        final ShellTransitions setTransitionsParam,
        final Optional<StartingSurface> setStartingSurfaceParam,
        final Optional<DisplayAreaHelper> setDisplayAreaHelperParam,
        final Optional<TaskSurfaceHelper> setTaskSurfaceHelper,
        final Optional<RecentTasks> setRecentTasksParam, final Optional<CompatUI> setCompatUIParam,
        final Optional<DragAndDrop> setDragAndDropParam) {
      this.powerNotificationWarningsProvider = DoubleCheck.provider(PowerNotificationWarnings_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideActivityStarterProvider));
      this.vibratorHelperProvider = DoubleCheck.provider(VibratorHelper_Factory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.remoteInputQuickSettingsDisablerProvider = DoubleCheck.provider(RemoteInputQuickSettingsDisabler_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideCommandQueueProvider, provideConfigurationControllerProvider));
      this.foregroundServiceNotificationListenerProvider = DoubleCheck.provider(ForegroundServiceNotificationListener_Factory.create(DaggerGlobalRootComponent.this.contextProvider, foregroundServiceControllerProvider, provideNotificationEntryManagerProvider, notifPipelineProvider, bindSystemClockProvider));
      this.clockManagerProvider = DoubleCheck.provider(ClockManager_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providerLayoutInflaterProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, sysuiColorExtractorProvider, (Provider) dockManagerImplProvider, providesBroadcastDispatcherProvider));
      this.factoryProvider8 = EdgeBackGestureHandler_Factory_Factory.create(overviewProxyServiceProvider, provideSysUiStateProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, providesBroadcastDispatcherProvider, protoTracerProvider, navigationModeControllerProvider, DaggerGlobalRootComponent.this.provideViewConfigurationProvider, DaggerGlobalRootComponent.this.provideWindowManagerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider, (Provider) falsingManagerProxyProvider);
      this.dependencyProvider2 = DoubleCheck.provider(Dependency_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, provideActivityStarterProvider, providesBroadcastDispatcherProvider, asyncSensorManagerProvider, (Provider) bluetoothControllerImplProvider, (Provider) locationControllerImplProvider, (Provider) rotationLockControllerImplProvider, (Provider) zenModeControllerImplProvider, (Provider) hotspotControllerImplProvider, (Provider) castControllerImplProvider, (Provider) flashlightControllerImplProvider, userSwitcherControllerProvider, (Provider) userInfoControllerImplProvider, (Provider) keyguardStateControllerImplProvider, keyguardUpdateMonitorProvider, provideBatteryControllerProvider, provideNightDisplayListenerProvider, provideReduceBrightColorsListenerProvider, (Provider) managedProfileControllerImplProvider, (Provider) nextAlarmControllerImplProvider, provideDataSaverControllerProvider, accessibilityControllerProvider, bindDeviceProvisionedControllerProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, assistManagerProvider, (Provider) securityControllerImplProvider, provideLeakDetectorProvider, leakReporterProvider, garbageMonitorProvider, (Provider) tunerServiceImplProvider, (Provider) notificationShadeWindowControllerImplProvider, statusBarWindowControllerProvider, (Provider) darkIconDispatcherImplProvider, provideConfigurationControllerProvider, (Provider) statusBarIconControllerImplProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, wakefulnessLifecycleProvider, fragmentServiceProvider, (Provider) extensionControllerImplProvider, DaggerGlobalRootComponent.this.pluginDependencyProvider, provideLocalBluetoothControllerProvider, (Provider) volumeDialogControllerImplProvider, provideMetricsLoggerProvider, accessibilityManagerWrapperProvider, sysuiColorExtractorProvider, tunablePaddingServiceProvider, foregroundServiceControllerProvider, uiOffloadThreadProvider, (Provider) powerNotificationWarningsProvider, lightBarControllerProvider, DaggerGlobalRootComponent.this.provideIWindowManagerProvider, overviewProxyServiceProvider, navigationModeControllerProvider, accessibilityButtonModeObserverProvider, accessibilityButtonTargetsObserverProvider, (Provider) enhancedEstimatesImplProvider, vibratorHelperProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, DaggerGlobalRootComponent.this.provideDisplayMetricsProvider, lockscreenGestureLoggerProvider, (Provider) keyguardEnvironmentImplProvider, (Provider) shadeControllerImplProvider, (Provider) statusBarRemoteInputCallbackProvider, (Provider) appOpsControllerImplProvider, navigationBarControllerProvider, provideAccessibilityFloatingMenuControllerProvider, (Provider) statusBarStateControllerImplProvider, (Provider) notificationLockscreenUserManagerImplProvider, provideNotificationGroupAlertTransferHelperProvider, notificationGroupManagerLegacyProvider, provideVisualStabilityManagerProvider, provideNotificationGutsManagerProvider, provideNotificationMediaManagerProvider, provideNotificationRemoteInputManagerProvider, smartReplyConstantsProvider, provideNotificationListenerProvider, provideNotificationLoggerProvider, provideNotificationViewHierarchyManagerProvider, notificationFilterProvider, keyguardDismissUtilProvider, provideSmartReplyControllerProvider, remoteInputQuickSettingsDisablerProvider, provideNotificationEntryManagerProvider, DaggerGlobalRootComponent.this.provideSensorPrivacyManagerProvider, provideAutoHideControllerProvider, foregroundServiceNotificationListenerProvider, privacyItemControllerProvider, provideBgLooperProvider, provideBgHandlerProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create(), DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideTimeTickHandlerProvider, provideLeakReportEmailProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, provideBackgroundExecutorProvider, clockManagerProvider, provideActivityManagerWrapperProvider, provideDevicePolicyManagerWrapperProvider, DaggerGlobalRootComponent.this.providePackageManagerWrapperProvider, provideSensorPrivacyControllerProvider, (Provider) dockManagerImplProvider, provideINotificationManagerProvider, provideSysUiStateProvider, DaggerGlobalRootComponent.this.provideAlarmManagerProvider, keyguardSecurityModelProvider, dozeParametersProvider, FrameworkServicesModule_ProvideIWallPaperManagerFactory.create(), provideCommandQueueProvider, recordingControllerProvider, protoTracerProvider, mediaOutputDialogFactoryProvider, deviceConfigProxyProvider, navigationBarOverlayControllerProvider, telephonyListenerManagerProvider, systemStatusAnimationSchedulerProvider, privacyDotViewControllerProvider, factoryProvider8, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, featureFlagsProvider, statusBarContentInsetsProvider, internetDialogFactoryProvider, notificationSectionsManagerProvider, unlockedScreenOffAnimationControllerProvider, ambientStateProvider, provideGroupMembershipManagerProvider, provideGroupExpansionManagerProvider, authControllerProvider));
      this.provideClockInfoListProvider = ClockModule_ProvideClockInfoListFactory.create(clockManagerProvider);
      this.provideAllowNotificationLongPressProvider = DoubleCheck.provider(SystemUIDefaultModule_ProvideAllowNotificationLongPressFactory.create());
      this.providesAlertingHeaderNodeControllerProvider = NotificationSectionHeadersModule_ProvidesAlertingHeaderNodeControllerFactory.create(providesAlertingHeaderSubcomponentProvider);
      this.providesSilentHeaderNodeControllerProvider = NotificationSectionHeadersModule_ProvidesSilentHeaderNodeControllerFactory.create(providesSilentHeaderSubcomponentProvider);
      this.providesIncomingHeaderNodeControllerProvider = NotificationSectionHeadersModule_ProvidesIncomingHeaderNodeControllerFactory.create(providesIncomingHeaderSubcomponentProvider);
      this.provideNotifGutsViewManagerProvider = DoubleCheck.provider(NotificationsModule_ProvideNotifGutsViewManagerFactory.create(provideNotificationGutsManagerProvider));
      this.providesPeopleHeaderNodeControllerProvider = NotificationSectionHeadersModule_ProvidesPeopleHeaderNodeControllerFactory.create(providesPeopleHeaderSubcomponentProvider);
      this.preparationCoordinatorLoggerProvider = PreparationCoordinatorLogger_Factory.create(provideNotificationsLogBufferProvider);
      this.preparationCoordinatorProvider = DoubleCheck.provider(PreparationCoordinator_Factory.create(preparationCoordinatorLoggerProvider, (Provider) notifInflaterImplProvider, notifInflationErrorManagerProvider, notifViewBarnProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider));
      this.remoteInputCoordinatorProvider = DoubleCheck.provider(RemoteInputCoordinator_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, remoteInputNotificationRebuilderProvider, provideNotificationRemoteInputManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideSmartReplyControllerProvider));
      this.optionalOfBcSmartspaceDataPluginProvider = absentJdkOptionalProvider();
      this.lockscreenSmartspaceControllerProvider = DoubleCheck.provider(LockscreenSmartspaceController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, featureFlagsProvider, DaggerGlobalRootComponent.this.provideSmartspaceManagerProvider, provideActivityStarterProvider, (Provider) falsingManagerProxyProvider, secureSettingsImplProvider, provideUserTrackerProvider, DaggerGlobalRootComponent.this.provideContentResolverProvider, provideConfigurationControllerProvider, (Provider) statusBarStateControllerImplProvider, bindDeviceProvisionedControllerProvider, DaggerGlobalRootComponent.this.provideExecutionProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, optionalOfBcSmartspaceDataPluginProvider));
      this.qSTileHostProvider = new DelegateFactory<>();
      this.provideQuickSettingsLogBufferProvider = DoubleCheck.provider(LogModule_ProvideQuickSettingsLogBufferFactory.create(logBufferFactoryProvider));
      this.qSLoggerProvider = QSLogger_Factory.create(provideQuickSettingsLogBufferProvider);
      this.customTileStatePersisterProvider = CustomTileStatePersister_Factory.create(DaggerGlobalRootComponent.this.contextProvider);
      this.builderProvider6 = CustomTile_Builder_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, customTileStatePersisterProvider);
      this.wifiTileProvider = WifiTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) networkControllerImplProvider, (Provider) provideAccessPointControllerImplProvider);
      this.internetTileProvider = InternetTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) networkControllerImplProvider, (Provider) provideAccessPointControllerImplProvider, internetDialogFactoryProvider);
      this.bluetoothTileProvider = BluetoothTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) bluetoothControllerImplProvider);
      this.cellularTileProvider = CellularTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) networkControllerImplProvider);
      this.dndTileProvider = DndTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) zenModeControllerImplProvider, provideSharePreferencesProvider, secureSettingsImplProvider, provideDialogLaunchAnimatorProvider);
      this.colorInversionTileProvider = ColorInversionTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideUserTrackerProvider, secureSettingsImplProvider);
      this.airplaneModeTileProvider = AirplaneModeTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideConnectivityManagagerProvider);
      this.workModeTileProvider = WorkModeTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) managedProfileControllerImplProvider);
      this.rotationLockTileProvider = RotationLockTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) rotationLockControllerImplProvider);
      this.flashlightTileProvider = FlashlightTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) flashlightControllerImplProvider);
      this.locationTileProvider = LocationTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) locationControllerImplProvider, (Provider) keyguardStateControllerImplProvider);
      this.castTileProvider = CastTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) castControllerImplProvider, (Provider) keyguardStateControllerImplProvider, (Provider) networkControllerImplProvider, (Provider) hotspotControllerImplProvider, provideDialogLaunchAnimatorProvider);
      this.hotspotTileProvider = HotspotTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) hotspotControllerImplProvider, provideDataSaverControllerProvider);
      this.userTileProvider = UserTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, userSwitcherControllerProvider, (Provider) userInfoControllerImplProvider);
      this.batterySaverTileProvider = BatterySaverTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideBatteryControllerProvider, secureSettingsImplProvider);
      this.dataSaverTileProvider = DataSaverTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideDataSaverControllerProvider, provideDialogLaunchAnimatorProvider);
      this.builderProvider7 = NightDisplayListenerModule_Builder_Factory.create(DaggerGlobalRootComponent.this.contextProvider, provideBgHandlerProvider);
      this.nightDisplayTileProvider = NightDisplayTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) locationControllerImplProvider, DaggerGlobalRootComponent.this.provideColorDisplayManagerProvider, builderProvider7);
      this.nfcTileProvider = NfcTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, providesBroadcastDispatcherProvider);
      this.memoryTileProvider = GarbageMonitor_MemoryTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, garbageMonitorProvider);
      this.uiModeNightTileProvider = UiModeNightTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideConfigurationControllerProvider, provideBatteryControllerProvider, (Provider) locationControllerImplProvider);
      this.screenRecordTileProvider = ScreenRecordTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, recordingControllerProvider, keyguardDismissUtilProvider, (Provider) keyguardStateControllerImplProvider, provideDialogLaunchAnimatorProvider);
      this.isReduceBrightColorsAvailableProvider = DoubleCheck.provider(QSFlagsModule_IsReduceBrightColorsAvailableFactory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.reduceBrightColorsTileProvider = ReduceBrightColorsTile_Factory.create(isReduceBrightColorsAvailableProvider, provideReduceBrightColorsListenerProvider, (Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider);
      this.cameraToggleTileProvider = CameraToggleTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideMetricsLoggerProvider, (Provider) falsingManagerProxyProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideIndividualSensorPrivacyControllerProvider, (Provider) keyguardStateControllerImplProvider);
      this.microphoneToggleTileProvider = MicrophoneToggleTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideMetricsLoggerProvider, (Provider) falsingManagerProxyProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideIndividualSensorPrivacyControllerProvider, (Provider) keyguardStateControllerImplProvider);
      this.deviceControlsTileProvider = DeviceControlsTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, controlsComponentProvider, (Provider) keyguardStateControllerImplProvider);
      this.alarmTileProvider = AlarmTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideUserTrackerProvider, (Provider) nextAlarmControllerImplProvider);
      this.provideQuickAccessWalletClientProvider = DoubleCheck.provider(WalletModule_ProvideQuickAccessWalletClientFactory.create(DaggerGlobalRootComponent.this.contextProvider));
      this.quickAccessWalletControllerProvider = DoubleCheck.provider(QuickAccessWalletController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, secureSettingsImplProvider, provideQuickAccessWalletClientProvider, bindSystemClockProvider));
      this.quickAccessWalletTileProvider = QuickAccessWalletTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) keyguardStateControllerImplProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider, secureSettingsImplProvider, quickAccessWalletControllerProvider);
      this.ambientDisplayTileProvider = AmbientDisplayTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideUserTrackerProvider, secureSettingsImplProvider);
      this.aODTileProvider = AODTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, secureSettingsImplProvider, provideBatteryControllerProvider);
      this.caffeineTileProvider = CaffeineTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider);
      this.headsUpTileProvider = HeadsUpTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider);
      this.powerShareTileProvider = PowerShareTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideBatteryControllerProvider);
      this.profilesTileProvider = ProfilesTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, provideDialogLaunchAnimatorProvider, keyguardDismissUtilProvider, (Provider) keyguardStateControllerImplProvider);
      this.readingModeTileProvider = ReadingModeTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider);
      this.syncTileProvider = SyncTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider);
      this.usbTetherTileProvider = UsbTetherTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider);
      this.vpnTileProvider = VpnTile_Factory.create((Provider) qSTileHostProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) falsingManagerProxyProvider, provideMetricsLoggerProvider, (Provider) statusBarStateControllerImplProvider, provideActivityStarterProvider, qSLoggerProvider, (Provider) securityControllerImplProvider, (Provider) keyguardStateControllerImplProvider);
      this.qSFactoryImplProvider = DoubleCheck.provider(QSFactoryImpl_Factory.create((Provider) qSTileHostProvider, builderProvider6, wifiTileProvider, internetTileProvider, bluetoothTileProvider, cellularTileProvider, dndTileProvider, colorInversionTileProvider, airplaneModeTileProvider, workModeTileProvider, rotationLockTileProvider, flashlightTileProvider, locationTileProvider, castTileProvider, hotspotTileProvider, userTileProvider, batterySaverTileProvider, dataSaverTileProvider, nightDisplayTileProvider, nfcTileProvider, memoryTileProvider, uiModeNightTileProvider, screenRecordTileProvider, reduceBrightColorsTileProvider, cameraToggleTileProvider, microphoneToggleTileProvider, deviceControlsTileProvider, alarmTileProvider, quickAccessWalletTileProvider, ambientDisplayTileProvider, aODTileProvider, caffeineTileProvider, headsUpTileProvider, powerShareTileProvider, profilesTileProvider, readingModeTileProvider, syncTileProvider, usbTetherTileProvider, vpnTileProvider));
      this.builderProvider8 = DoubleCheck.provider(AutoAddTracker_Builder_Factory.create(secureSettingsImplProvider, providesBroadcastDispatcherProvider, (Provider) qSTileHostProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBackgroundExecutorProvider));
      this.deviceControlsControllerImplProvider = DoubleCheck.provider(DeviceControlsControllerImpl_Factory.create(DaggerGlobalRootComponent.this.contextProvider, controlsComponentProvider, (Provider) provideUserTrackerProvider, secureSettingsImplProvider));
      this.walletControllerImplProvider = DoubleCheck.provider(WalletControllerImpl_Factory.create(provideQuickAccessWalletClientProvider));
      this.provideAutoTileManagerProvider = QSModule_ProvideAutoTileManagerFactory.create(DaggerGlobalRootComponent.this.contextProvider, builderProvider8, qSTileHostProvider, provideBgHandlerProvider, secureSettingsImplProvider, (Provider) hotspotControllerImplProvider, provideDataSaverControllerProvider, (Provider) managedProfileControllerImplProvider, provideNightDisplayListenerProvider, (Provider) castControllerImplProvider, provideReduceBrightColorsListenerProvider, (Provider) deviceControlsControllerImplProvider, (Provider) walletControllerImplProvider, isReduceBrightColorsAvailableProvider);
      DelegateFactory.setDelegate(qSTileHostProvider, DoubleCheck.provider(QSTileHost_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) statusBarIconControllerImplProvider, (Provider) qSFactoryImplProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, provideBgLooperProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, (Provider) tunerServiceImplProvider, provideAutoTileManagerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, providesBroadcastDispatcherProvider, optionalOfStatusBarProvider, qSLoggerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, provideUserTrackerProvider, secureSettingsImplProvider, customTileStatePersisterProvider)));
      this.qSDetailDisplayerProvider = DoubleCheck.provider(QSDetailDisplayer_Factory.create());
      this.providesQSMediaHostProvider = DoubleCheck.provider(MediaModule_ProvidesQSMediaHostFactory.create(MediaHost_MediaHostStateHolder_Factory.create(), mediaHierarchyManagerProvider, mediaDataManagerProvider, mediaHostStatesManagerProvider));
      this.providesQuickQSMediaHostProvider = DoubleCheck.provider(MediaModule_ProvidesQuickQSMediaHostFactory.create(MediaHost_MediaHostStateHolder_Factory.create(), mediaHierarchyManagerProvider, mediaDataManagerProvider, mediaHostStatesManagerProvider));
      this.provideQSFragmentDisableLogBufferProvider = DoubleCheck.provider(LogModule_ProvideQSFragmentDisableLogBufferFactory.create(logBufferFactoryProvider));
      this.notificationShelfComponentBuilderProvider = new Provider<NotificationShelfComponent.Builder>() {
        @Override
        public NotificationShelfComponent.Builder get() {
          return new NotificationShelfComponentBuilder();
        }
      };
      this.keyguardQsUserSwitchComponentFactoryProvider = new Provider<KeyguardQsUserSwitchComponent.Factory>() {
        @Override
        public KeyguardQsUserSwitchComponent.Factory get() {
          return new KeyguardQsUserSwitchComponentFactory();
        }
      };
      this.keyguardUserSwitcherComponentFactoryProvider = new Provider<KeyguardUserSwitcherComponent.Factory>() {
        @Override
        public KeyguardUserSwitcherComponent.Factory get() {
          return new KeyguardUserSwitcherComponentFactory();
        }
      };
      this.keyguardStatusBarViewComponentFactoryProvider = new Provider<KeyguardStatusBarViewComponent.Factory>() {
        @Override
        public KeyguardStatusBarViewComponent.Factory get() {
          return new KeyguardStatusBarViewComponentFactory();
        }
      };
      this.privacyDialogControllerProvider = DoubleCheck.provider(PrivacyDialogController_Factory.create(DaggerGlobalRootComponent.this.providePermissionManagerProvider, DaggerGlobalRootComponent.this.providePackageManagerProvider, privacyItemControllerProvider, provideUserTrackerProvider, provideActivityStarterProvider, provideBackgroundExecutorProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, privacyLoggerProvider, (Provider) keyguardStateControllerImplProvider, (Provider) appOpsControllerImplProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider));
      this.subscriptionManagerSlotIndexResolverProvider = DoubleCheck.provider(QSCarrierGroupController_SubscriptionManagerSlotIndexResolver_Factory.create());
      this.setDisplayAreaHelperProvider = InstanceFactory.create(setDisplayAreaHelperParam);
      this.provideProximityCheckProvider = SensorModule_ProvideProximityCheckFactory.create(provideProximitySensorProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider);
      this.userSwitchDialogControllerProvider = DoubleCheck.provider(UserSwitchDialogController_Factory.create(adapterProvider, provideActivityStarterProvider, (Provider) falsingManagerProxyProvider, provideDialogLaunchAnimatorProvider));
      this.isPMLiteEnabledProvider = DoubleCheck.provider(QSFlagsModule_IsPMLiteEnabledFactory.create(featureFlagsProvider, globalSettingsImplProvider));
      this.factoryProvider9 = DoubleCheck.provider(StatusBarIconController_TintedIconManager_Factory_Factory.create(featureFlagsProvider));
    }

    @Override
    public BootCompleteCacheImpl provideBootCacheImpl() {
      return bootCompleteCacheImplProvider.get();
    }

    @Override
    public ConfigurationController getConfigurationController() {
      return provideConfigurationControllerProvider.get();
    }

    @Override
    public ContextComponentHelper getContextComponentHelper() {
      return contextComponentResolverProvider.get();
    }

    @Override
    public Dependency createDependency() {
      return dependencyProvider2.get();
    }

    @Override
    public DumpManager createDumpManager() {
      return DaggerGlobalRootComponent.this.dumpManagerProvider.get();
    }

    @Override
    public InitController getInitController() {
      return initControllerProvider.get();
    }

    @Override
    public Optional<SysUIUnfoldComponent> getSysUIUnfoldComponent() {
      return provideSysUIUnfoldComponentProvider.get();
    }

    @Override
    public Optional<NaturalRotationUnfoldProgressProvider> getNaturalRotationUnfoldProgressProvider(
        ) {
      return DaggerGlobalRootComponent.this.provideNaturalRotationProgressProvider.get();
    }

    @Override
    public void inject(SystemUIAppComponentFactory factory) {
      injectSystemUIAppComponentFactory(factory);
    }

    @Override
    public void inject(KeyguardSliceProvider keyguardSliceProvider) {
      injectKeyguardSliceProvider(keyguardSliceProvider);
    }

    @Override
    public void inject(ClockOptionsProvider clockOptionsProvider) {
      injectClockOptionsProvider(clockOptionsProvider);
    }

    @Override
    public void inject(PeopleProvider peopleProvider) {
      injectPeopleProvider(peopleProvider);
    }

    private SystemUIAppComponentFactory injectSystemUIAppComponentFactory(
        SystemUIAppComponentFactory instance) {
      SystemUIAppComponentFactory_MembersInjector.injectMComponentHelper(instance, contextComponentResolverProvider.get());
      return instance;
    }

    private KeyguardSliceProvider injectKeyguardSliceProvider(KeyguardSliceProvider instance) {
      KeyguardSliceProvider_MembersInjector.injectMDozeParameters(instance, dozeParametersProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMZenModeController(instance, zenModeControllerImplProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMNextAlarmController(instance, nextAlarmControllerImplProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMAlarmManager(instance, DaggerGlobalRootComponent.this.provideAlarmManagerProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMContentResolver(instance, DaggerGlobalRootComponent.this.provideContentResolverProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMMediaManager(instance, provideNotificationMediaManagerProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMStatusBarStateController(instance, statusBarStateControllerImplProvider.get());
      KeyguardSliceProvider_MembersInjector.injectMKeyguardBypassController(instance, keyguardBypassControllerProvider.get());
      return instance;
    }

    private ClockOptionsProvider injectClockOptionsProvider(ClockOptionsProvider instance) {
      ClockOptionsProvider_MembersInjector.injectMClockInfosProvider(instance, provideClockInfoListProvider);
      return instance;
    }

    private PeopleProvider injectPeopleProvider(PeopleProvider instance) {
      PeopleProvider_MembersInjector.injectMPeopleSpaceWidgetManager(instance, peopleSpaceWidgetManagerProvider.get());
      return instance;
    }

    private final class ExpandableNotificationRowComponentBuilder implements ExpandableNotificationRowComponent.Builder {
      private ExpandableNotificationRow expandableNotificationRow;

      private NotificationEntry notificationEntry;

      private ExpandableNotificationRow.OnExpandClickListener onExpandClickListener;

      private NotificationListContainer listContainer;

      @Override
      public ExpandableNotificationRowComponentBuilder expandableNotificationRow(
          ExpandableNotificationRow view) {
        this.expandableNotificationRow = Preconditions.checkNotNull(view);
        return this;
      }

      @Override
      public ExpandableNotificationRowComponentBuilder notificationEntry(NotificationEntry entry) {
        this.notificationEntry = Preconditions.checkNotNull(entry);
        return this;
      }

      @Override
      public ExpandableNotificationRowComponentBuilder onExpandClickListener(
          ExpandableNotificationRow.OnExpandClickListener presenter) {
        this.onExpandClickListener = Preconditions.checkNotNull(presenter);
        return this;
      }

      @Override
      public ExpandableNotificationRowComponentBuilder listContainer(
          NotificationListContainer listContainer) {
        this.listContainer = Preconditions.checkNotNull(listContainer);
        return this;
      }

      @Override
      public ExpandableNotificationRowComponent build() {
        Preconditions.checkBuilderRequirement(expandableNotificationRow, ExpandableNotificationRow.class);
        Preconditions.checkBuilderRequirement(notificationEntry, NotificationEntry.class);
        Preconditions.checkBuilderRequirement(onExpandClickListener, ExpandableNotificationRow.OnExpandClickListener.class);
        Preconditions.checkBuilderRequirement(listContainer, NotificationListContainer.class);
        return new ExpandableNotificationRowComponentImpl(expandableNotificationRow, notificationEntry, onExpandClickListener, listContainer);
      }
    }

    private final class ExpandableNotificationRowComponentImpl implements ExpandableNotificationRowComponent {
      private Provider<ExpandableNotificationRow> expandableNotificationRowProvider;

      private Provider<NotificationListContainer> listContainerProvider;

      private Provider<NotificationTapHelper.Factory> factoryProvider;

      private Provider<ExpandableViewController> expandableViewControllerProvider;

      private Provider<ExpandableOutlineViewController> expandableOutlineViewControllerProvider;

      private Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider;

      private Provider<NotificationEntry> notificationEntryProvider;

      private Provider<StatusBarNotification> provideStatusBarNotificationProvider;

      private Provider<String> provideAppNameProvider;

      private Provider<String> provideNotificationKeyProvider;

      private Provider<ExpandableNotificationRow.OnExpandClickListener> onExpandClickListenerProvider;

      private Provider<ExpandableNotificationRowDragController> expandableNotificationRowDragControllerProvider;

      private Provider<ExpandableNotificationRowController> expandableNotificationRowControllerProvider;

      private ExpandableNotificationRowComponentImpl(
          ExpandableNotificationRow expandableNotificationRowParam,
          NotificationEntry notificationEntryParam,
          ExpandableNotificationRow.OnExpandClickListener onExpandClickListenerParam,
          NotificationListContainer listContainerParam) {

        initialize(expandableNotificationRowParam, notificationEntryParam, onExpandClickListenerParam, listContainerParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final ExpandableNotificationRow expandableNotificationRowParam,
          final NotificationEntry notificationEntryParam,
          final ExpandableNotificationRow.OnExpandClickListener onExpandClickListenerParam,
          final NotificationListContainer listContainerParam) {
        this.expandableNotificationRowProvider = InstanceFactory.create(expandableNotificationRowParam);
        this.listContainerProvider = InstanceFactory.create(listContainerParam);
        this.factoryProvider = NotificationTapHelper_Factory_Factory.create((Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider);
        this.expandableViewControllerProvider = ExpandableViewController_Factory.create((Provider) expandableNotificationRowProvider);
        this.expandableOutlineViewControllerProvider = ExpandableOutlineViewController_Factory.create((Provider) expandableNotificationRowProvider, expandableViewControllerProvider);
        this.activatableNotificationViewControllerProvider = ActivatableNotificationViewController_Factory.create((Provider) expandableNotificationRowProvider, factoryProvider, expandableOutlineViewControllerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.falsingCollectorImplProvider);
        this.notificationEntryProvider = InstanceFactory.create(notificationEntryParam);
        this.provideStatusBarNotificationProvider = ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideStatusBarNotificationFactory.create(notificationEntryProvider);
        this.provideAppNameProvider = ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideAppNameFactory.create(DaggerGlobalRootComponent.this.contextProvider, provideStatusBarNotificationProvider);
        this.provideNotificationKeyProvider = ExpandableNotificationRowComponent_ExpandableNotificationRowModule_ProvideNotificationKeyFactory.create(provideStatusBarNotificationProvider);
        this.onExpandClickListenerProvider = InstanceFactory.create(onExpandClickListenerParam);
        this.expandableNotificationRowDragControllerProvider = ExpandableNotificationRowDragController_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider);
        this.expandableNotificationRowControllerProvider = DoubleCheck.provider(ExpandableNotificationRowController_Factory.create(expandableNotificationRowProvider, listContainerProvider, activatableNotificationViewControllerProvider, SysUIComponentImpl.this.provideNotificationMediaManagerProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, SysUIComponentImpl.this.bindSystemClockProvider, provideAppNameProvider, provideNotificationKeyProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, SysUIComponentImpl.this.provideGroupMembershipManagerProvider, SysUIComponentImpl.this.provideGroupExpansionManagerProvider, SysUIComponentImpl.this.rowContentBindStageProvider, SysUIComponentImpl.this.provideNotificationLoggerProvider, (Provider) SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider, onExpandClickListenerProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.provideNotificationGutsManagerProvider, SysUIComponentImpl.this.provideAllowNotificationLongPressProvider, SysUIComponentImpl.this.provideOnUserInteractionCallbackProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.falsingCollectorImplProvider, (Provider) SysUIComponentImpl.this.peopleNotificationIdentifierImplProvider, SysUIComponentImpl.this.provideBubblesManagerProvider, expandableNotificationRowDragControllerProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider));
      }

      @Override
      public ExpandableNotificationRowController getExpandableNotificationRowController() {
        return expandableNotificationRowControllerProvider.get();
      }
    }

    private final class CoordinatorsSubcomponentFactory implements CoordinatorsSubcomponent.Factory {
      @Override
      public CoordinatorsSubcomponent create() {
        return new CoordinatorsSubcomponentImpl();
      }
    }

    private final class CoordinatorsSubcomponentImpl implements CoordinatorsSubcomponent {
      private Provider<HideLocallyDismissedNotifsCoordinator> hideLocallyDismissedNotifsCoordinatorProvider;

      private Provider<SharedCoordinatorLogger> sharedCoordinatorLoggerProvider;

      private Provider<HideNotifsForOtherUsersCoordinator> hideNotifsForOtherUsersCoordinatorProvider;

      private Provider<KeyguardCoordinator> keyguardCoordinatorProvider;

      private Provider<RankingCoordinator> rankingCoordinatorProvider;

      private Provider<AppOpsCoordinator> appOpsCoordinatorProvider;

      private Provider<DeviceProvisionedCoordinator> deviceProvisionedCoordinatorProvider;

      private Provider<BubbleCoordinator> bubbleCoordinatorProvider;

      private Provider<HeadsUpCoordinator> headsUpCoordinatorProvider;

      private Provider<GutsCoordinatorLogger> gutsCoordinatorLoggerProvider;

      private Provider<GutsCoordinator> gutsCoordinatorProvider;

      private Provider<ConversationCoordinator> conversationCoordinatorProvider;

      private Provider<MediaCoordinator> mediaCoordinatorProvider;

      private Provider<SmartspaceDedupingCoordinator> smartspaceDedupingCoordinatorProvider;

      private Provider<ViewConfigCoordinator> viewConfigCoordinatorProvider;

      private Provider<SensitiveContentCoordinator> provideCoordinatorProvider;

      private Provider<NotifCoordinatorsImpl> notifCoordinatorsImplProvider;

      private CoordinatorsSubcomponentImpl() {

        initialize();
      }

      @SuppressWarnings("unchecked")
      private void initialize() {
        this.hideLocallyDismissedNotifsCoordinatorProvider = DoubleCheck.provider(HideLocallyDismissedNotifsCoordinator_Factory.create());
        this.sharedCoordinatorLoggerProvider = SharedCoordinatorLogger_Factory.create(SysUIComponentImpl.this.provideNotificationsLogBufferProvider);
        this.hideNotifsForOtherUsersCoordinatorProvider = DoubleCheck.provider(HideNotifsForOtherUsersCoordinator_Factory.create((Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, sharedCoordinatorLoggerProvider));
        this.keyguardCoordinatorProvider = DoubleCheck.provider(KeyguardCoordinator_Factory.create(DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.provideHandlerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.providesBroadcastDispatcherProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, SysUIComponentImpl.this.highPriorityProvider));
        this.rankingCoordinatorProvider = DoubleCheck.provider(RankingCoordinator_Factory.create((Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.highPriorityProvider, SysUIComponentImpl.this.providesAlertingHeaderNodeControllerProvider, SysUIComponentImpl.this.providesSilentHeaderControllerProvider, SysUIComponentImpl.this.providesSilentHeaderNodeControllerProvider));
        this.appOpsCoordinatorProvider = DoubleCheck.provider(AppOpsCoordinator_Factory.create(SysUIComponentImpl.this.foregroundServiceControllerProvider, (Provider) SysUIComponentImpl.this.appOpsControllerImplProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider));
        this.deviceProvisionedCoordinatorProvider = DoubleCheck.provider(DeviceProvisionedCoordinator_Factory.create(SysUIComponentImpl.this.bindDeviceProvisionedControllerProvider, DaggerGlobalRootComponent.this.provideIPackageManagerProvider));
        this.bubbleCoordinatorProvider = DoubleCheck.provider(BubbleCoordinator_Factory.create(SysUIComponentImpl.this.provideBubblesManagerProvider, SysUIComponentImpl.this.setBubblesProvider, SysUIComponentImpl.this.notifCollectionProvider));
        this.headsUpCoordinatorProvider = DoubleCheck.provider(HeadsUpCoordinator_Factory.create((Provider) SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider, SysUIComponentImpl.this.headsUpViewBinderProvider, (Provider) SysUIComponentImpl.this.notificationInterruptStateProviderImplProvider, SysUIComponentImpl.this.provideNotificationRemoteInputManagerProvider, SysUIComponentImpl.this.providesIncomingHeaderNodeControllerProvider));
        this.gutsCoordinatorLoggerProvider = GutsCoordinatorLogger_Factory.create(SysUIComponentImpl.this.provideNotificationsLogBufferProvider);
        this.gutsCoordinatorProvider = DoubleCheck.provider(GutsCoordinator_Factory.create(SysUIComponentImpl.this.provideNotifGutsViewManagerProvider, gutsCoordinatorLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
        this.conversationCoordinatorProvider = DoubleCheck.provider(ConversationCoordinator_Factory.create((Provider) SysUIComponentImpl.this.peopleNotificationIdentifierImplProvider, SysUIComponentImpl.this.providesPeopleHeaderNodeControllerProvider));
        this.mediaCoordinatorProvider = DoubleCheck.provider(MediaCoordinator_Factory.create(SysUIComponentImpl.this.mediaFeatureFlagProvider));
        this.smartspaceDedupingCoordinatorProvider = DoubleCheck.provider(SmartspaceDedupingCoordinator_Factory.create((Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.lockscreenSmartspaceControllerProvider, SysUIComponentImpl.this.provideNotificationEntryManagerProvider, (Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.notifPipelineProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, SysUIComponentImpl.this.bindSystemClockProvider));
        this.viewConfigCoordinatorProvider = DoubleCheck.provider(ViewConfigCoordinator_Factory.create(SysUIComponentImpl.this.provideConfigurationControllerProvider, SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.featureFlagsProvider, SysUIComponentImpl.this.provideNotificationGutsManagerProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider));
        this.provideCoordinatorProvider = DoubleCheck.provider(SensitiveContentCoordinatorModule_ProvideCoordinatorFactory.create(SysUIComponentImpl.this.dynamicPrivacyControllerProvider, (Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider));
        this.notifCoordinatorsImplProvider = DoubleCheck.provider(NotifCoordinatorsImpl_Factory.create(DaggerGlobalRootComponent.this.dumpManagerProvider, SysUIComponentImpl.this.featureFlagsProvider, hideLocallyDismissedNotifsCoordinatorProvider, hideNotifsForOtherUsersCoordinatorProvider, keyguardCoordinatorProvider, rankingCoordinatorProvider, appOpsCoordinatorProvider, deviceProvisionedCoordinatorProvider, bubbleCoordinatorProvider, headsUpCoordinatorProvider, gutsCoordinatorProvider, conversationCoordinatorProvider, SysUIComponentImpl.this.preparationCoordinatorProvider, mediaCoordinatorProvider, SysUIComponentImpl.this.remoteInputCoordinatorProvider, SysUIComponentImpl.this.shadeEventCoordinatorProvider, smartspaceDedupingCoordinatorProvider, viewConfigCoordinatorProvider, SysUIComponentImpl.this.visualStabilityCoordinatorProvider, provideCoordinatorProvider));
      }

      @Override
      public NotifCoordinators getNotifCoordinators() {
        return notifCoordinatorsImplProvider.get();
      }
    }

    private final class FragmentCreatorFactory implements FragmentService.FragmentCreator.Factory {
      @Override
      public FragmentService.FragmentCreator build() {
        return new FragmentCreatorImpl();
      }
    }

    private final class FragmentCreatorImpl implements FragmentService.FragmentCreator {
      private FragmentCreatorImpl() {

      }

      private QSFragmentDisableFlagsLogger qSFragmentDisableFlagsLogger() {
        return new QSFragmentDisableFlagsLogger(SysUIComponentImpl.this.provideQSFragmentDisableLogBufferProvider.get(), SysUIComponentImpl.this.disableFlagsLoggerProvider.get());
      }

      @Override
      public QSFragment createQSFragment() {
        return new QSFragment(SysUIComponentImpl.this.remoteInputQuickSettingsDisablerProvider.get(), SysUIComponentImpl.this.qSTileHostProvider.get(), SysUIComponentImpl.this.statusBarStateControllerImplProvider.get(), SysUIComponentImpl.this.provideCommandQueueProvider.get(), SysUIComponentImpl.this.qSDetailDisplayerProvider.get(), SysUIComponentImpl.this.providesQSMediaHostProvider.get(), SysUIComponentImpl.this.providesQuickQSMediaHostProvider.get(), SysUIComponentImpl.this.keyguardBypassControllerProvider.get(), new QSFragmentComponentFactory(), qSFragmentDisableFlagsLogger(), SysUIComponentImpl.this.falsingManagerProxyProvider.get(), DaggerGlobalRootComponent.this.dumpManagerProvider.get());
      }
    }

    private final class SectionHeaderControllerSubcomponentBuilder implements SectionHeaderControllerSubcomponent.Builder {
      private String nodeLabel;

      private Integer headerText;

      private String clickIntentAction;

      @Override
      public SectionHeaderControllerSubcomponentBuilder nodeLabel(String nodeLabel) {
        this.nodeLabel = Preconditions.checkNotNull(nodeLabel);
        return this;
      }

      @Override
      public SectionHeaderControllerSubcomponentBuilder headerText(int headerText) {
        this.headerText = Preconditions.checkNotNull(headerText);
        return this;
      }

      @Override
      public SectionHeaderControllerSubcomponentBuilder clickIntentAction(
          String clickIntentAction) {
        this.clickIntentAction = Preconditions.checkNotNull(clickIntentAction);
        return this;
      }

      @Override
      public SectionHeaderControllerSubcomponent build() {
        Preconditions.checkBuilderRequirement(nodeLabel, String.class);
        Preconditions.checkBuilderRequirement(headerText, Integer.class);
        Preconditions.checkBuilderRequirement(clickIntentAction, String.class);
        return new SectionHeaderControllerSubcomponentImpl(nodeLabel, headerText, clickIntentAction);
      }
    }

    private final class SectionHeaderControllerSubcomponentImpl implements SectionHeaderControllerSubcomponent {
      private Provider<String> nodeLabelProvider;

      private Provider<Integer> headerTextProvider;

      private Provider<String> clickIntentActionProvider;

      private Provider<SectionHeaderNodeControllerImpl> sectionHeaderNodeControllerImplProvider;

      private SectionHeaderControllerSubcomponentImpl(String nodeLabelParam,
          Integer headerTextParam, String clickIntentActionParam) {

        initialize(nodeLabelParam, headerTextParam, clickIntentActionParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final String nodeLabelParam, final Integer headerTextParam,
          final String clickIntentActionParam) {
        this.nodeLabelProvider = InstanceFactory.create(nodeLabelParam);
        this.headerTextProvider = InstanceFactory.create(headerTextParam);
        this.clickIntentActionProvider = InstanceFactory.create(clickIntentActionParam);
        this.sectionHeaderNodeControllerImplProvider = DoubleCheck.provider(SectionHeaderNodeControllerImpl_Factory.create(nodeLabelProvider, SysUIComponentImpl.this.providerLayoutInflaterProvider, headerTextProvider, SysUIComponentImpl.this.provideActivityStarterProvider, clickIntentActionProvider));
      }

      @Override
      public NodeController getNodeController() {
        return sectionHeaderNodeControllerImplProvider.get();
      }

      @Override
      public SectionHeaderController getHeaderController() {
        return sectionHeaderNodeControllerImplProvider.get();
      }
    }

    private final class StatusBarComponentFactory implements StatusBarComponent.Factory {
      @Override
      public StatusBarComponent create() {
        return new StatusBarComponentImpl();
      }
    }

    private final class StatusBarComponentImpl implements StatusBarComponent {
      private Provider<NotificationShadeWindowView> providesNotificationShadeWindowViewProvider;

      private Provider<VisualizerView> providesVisualizerViewProvider;

      private Provider<NotificationStackScrollLayout> providesNotificationStackScrollLayoutProvider;

      private Provider<NotificationShelf> providesNotificationShelfProvider;

      private Provider<NotificationShelfController> providesStatusBarWindowViewProvider;

      @SuppressWarnings("rawtypes")
      private Provider builderProvider;

      private Provider<NotificationStackScrollLayoutController> notificationStackScrollLayoutControllerProvider;

      private Provider<NotificationPanelView> getNotificationPanelViewProvider;

      private Provider<FlingAnimationUtils.Builder> builderProvider2;

      private Provider<NotificationsQuickSettingsContainer> getNotificationsQuickSettingsContainerProvider;

      private Provider<NotificationsQSContainerController> notificationsQSContainerControllerProvider;

      private Provider<LockIconView> getLockIconViewProvider;

      private Provider<AuthRippleView> getAuthRippleViewProvider;

      private Provider<AuthRippleController> authRippleControllerProvider;

      private Provider<LockIconViewController> lockIconViewControllerProvider;

      private Provider<TapAgainView> getTapAgainViewProvider;

      private Provider<TapAgainViewController> tapAgainViewControllerProvider;

      private Provider<View> getSplitShadeStatusBarViewProvider;

      private Provider<OngoingPrivacyChip> getSplitShadeOngoingPrivacyChipProvider;

      private Provider<StatusIconContainer> providesStatusIconContainerProvider;

      private Provider<HeaderPrivacyIconsController> headerPrivacyIconsControllerProvider;

      private Provider<CarrierTextManager.Builder> builderProvider3;

      private Provider<QSCarrierGroupController.Builder> builderProvider4;

      private Provider<BatteryMeterView> getBatteryMeterViewProvider;

      private Provider<BatteryMeterViewController> getBatteryMeterViewControllerProvider;

      private Provider<SplitShadeHeaderController> splitShadeHeaderControllerProvider;

      private Provider<NotificationPanelViewController> notificationPanelViewControllerProvider;

      private Provider<NotificationShadeWindowViewController> notificationShadeWindowViewControllerProvider;

      private Provider<StatusBarDemoMode> statusBarDemoModeProvider;

      private Provider<StatusBarHeadsUpChangeListener> statusBarHeadsUpChangeListenerProvider;

      private Provider<StatusBarCommandQueueCallbacks> statusBarCommandQueueCallbacksProvider;

      private StatusBarComponentImpl() {

        initialize();
      }

      @SuppressWarnings("unchecked")
      private void initialize() {
        this.providesNotificationShadeWindowViewProvider = DoubleCheck.provider(StatusBarViewModule_ProvidesNotificationShadeWindowViewFactory.create(SysUIComponentImpl.this.providerLayoutInflaterProvider));
        this.providesVisualizerViewProvider = DoubleCheck.provider(StatusBarViewModule_ProvidesVisualizerViewFactory.create(providesNotificationShadeWindowViewProvider));
        this.providesNotificationStackScrollLayoutProvider = DoubleCheck.provider(StatusBarViewModule_ProvidesNotificationStackScrollLayoutFactory.create(providesNotificationShadeWindowViewProvider));
        this.providesNotificationShelfProvider = DoubleCheck.provider(StatusBarViewModule_ProvidesNotificationShelfFactory.create(SysUIComponentImpl.this.providerLayoutInflaterProvider, providesNotificationStackScrollLayoutProvider));
        this.providesStatusBarWindowViewProvider = DoubleCheck.provider(StatusBarViewModule_ProvidesStatusBarWindowViewFactory.create(SysUIComponentImpl.this.notificationShelfComponentBuilderProvider, providesNotificationShelfProvider));
        this.builderProvider = NotificationSwipeHelper_Builder_Factory.create(DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.provideViewConfigurationProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider);
        this.notificationStackScrollLayoutControllerProvider = DoubleCheck.provider(NotificationStackScrollLayoutController_Factory.create(SysUIComponentImpl.this.provideAllowNotificationLongPressProvider, SysUIComponentImpl.this.provideNotificationGutsManagerProvider, SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider, SysUIComponentImpl.this.notificationRoundnessManagerProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, SysUIComponentImpl.this.bindDeviceProvisionedControllerProvider, SysUIComponentImpl.this.dynamicPrivacyControllerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.keyguardMediaControllerProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, (Provider) SysUIComponentImpl.this.zenModeControllerImplProvider, SysUIComponentImpl.this.sysuiColorExtractorProvider, (Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, SysUIComponentImpl.this.falsingCollectorImplProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, builderProvider, SysUIComponentImpl.this.provideStatusBarProvider, SysUIComponentImpl.this.scrimControllerProvider, SysUIComponentImpl.this.notificationGroupManagerLegacyProvider, SysUIComponentImpl.this.provideGroupExpansionManagerProvider, SysUIComponentImpl.this.providesSilentHeaderControllerProvider, SysUIComponentImpl.this.featureFlagsProvider, SysUIComponentImpl.this.notifPipelineProvider, SysUIComponentImpl.this.notifCollectionProvider, SysUIComponentImpl.this.provideNotificationEntryManagerProvider, SysUIComponentImpl.this.lockscreenShadeTransitionControllerProvider, DaggerGlobalRootComponent.this.provideIStatusBarServiceProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, SysUIComponentImpl.this.foregroundServiceDismissalFeatureControllerProvider, SysUIComponentImpl.this.foregroundServiceSectionControllerProvider, SysUIComponentImpl.this.providerLayoutInflaterProvider, SysUIComponentImpl.this.provideNotificationRemoteInputManagerProvider, SysUIComponentImpl.this.provideVisualStabilityManagerProvider, (Provider) SysUIComponentImpl.this.shadeControllerImplProvider));
        this.getNotificationPanelViewProvider = DoubleCheck.provider(StatusBarViewModule_GetNotificationPanelViewFactory.create(providesNotificationShadeWindowViewProvider));
        this.builderProvider2 = FlingAnimationUtils_Builder_Factory.create(DaggerGlobalRootComponent.this.provideDisplayMetricsProvider);
        this.getNotificationsQuickSettingsContainerProvider = DoubleCheck.provider(StatusBarViewModule_GetNotificationsQuickSettingsContainerFactory.create(providesNotificationShadeWindowViewProvider));
        this.notificationsQSContainerControllerProvider = NotificationsQSContainerController_Factory.create(getNotificationsQuickSettingsContainerProvider, SysUIComponentImpl.this.navigationModeControllerProvider, SysUIComponentImpl.this.overviewProxyServiceProvider);
        this.getLockIconViewProvider = DoubleCheck.provider(StatusBarViewModule_GetLockIconViewFactory.create(providesNotificationShadeWindowViewProvider));
        this.getAuthRippleViewProvider = DoubleCheck.provider(StatusBarViewModule_GetAuthRippleViewFactory.create(providesNotificationShadeWindowViewProvider));
        this.authRippleControllerProvider = DoubleCheck.provider(AuthRippleController_Factory.create(SysUIComponentImpl.this.provideStatusBarProvider, DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.authControllerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, SysUIComponentImpl.this.wakefulnessLifecycleProvider, SysUIComponentImpl.this.commandRegistryProvider, (Provider) SysUIComponentImpl.this.notificationShadeWindowControllerImplProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, SysUIComponentImpl.this.biometricUnlockControllerProvider, SysUIComponentImpl.this.udfpsControllerProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, getAuthRippleViewProvider));
        this.lockIconViewControllerProvider = DoubleCheck.provider(LockIconViewController_Factory.create(getLockIconViewProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, (Provider) SysUIComponentImpl.this.statusBarKeyguardViewManagerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.authControllerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideVibratorProvider, authRippleControllerProvider, DaggerGlobalRootComponent.this.provideResourcesProvider));
        this.getTapAgainViewProvider = DoubleCheck.provider(StatusBarViewModule_GetTapAgainViewFactory.create(getNotificationPanelViewProvider));
        this.tapAgainViewControllerProvider = DoubleCheck.provider(TapAgainViewController_Factory.create(getTapAgainViewProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, FalsingModule_ProvidesDoubleTapTimeoutMsFactory.create()));
        this.getSplitShadeStatusBarViewProvider = DoubleCheck.provider(StatusBarViewModule_GetSplitShadeStatusBarViewFactory.create(providesNotificationShadeWindowViewProvider, SysUIComponentImpl.this.featureFlagsProvider));
        this.getSplitShadeOngoingPrivacyChipProvider = DoubleCheck.provider(StatusBarViewModule_GetSplitShadeOngoingPrivacyChipFactory.create(getSplitShadeStatusBarViewProvider));
        this.providesStatusIconContainerProvider = DoubleCheck.provider(StatusBarViewModule_ProvidesStatusIconContainerFactory.create(getSplitShadeStatusBarViewProvider));
        this.headerPrivacyIconsControllerProvider = HeaderPrivacyIconsController_Factory.create(SysUIComponentImpl.this.privacyItemControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, getSplitShadeOngoingPrivacyChipProvider, SysUIComponentImpl.this.privacyDialogControllerProvider, SysUIComponentImpl.this.privacyLoggerProvider, providesStatusIconContainerProvider, SysUIComponentImpl.this.bindDeviceProvisionedControllerProvider);
        this.builderProvider3 = CarrierTextManager_Builder_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.provideWifiManagerProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, SysUIComponentImpl.this.telephonyListenerManagerProvider, SysUIComponentImpl.this.wakefulnessLifecycleProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, SysUIComponentImpl.this.provideBackgroundExecutorProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider);
        this.builderProvider4 = QSCarrierGroupController_Builder_Factory.create(SysUIComponentImpl.this.provideActivityStarterProvider, SysUIComponentImpl.this.provideBgHandlerProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create(), (Provider) SysUIComponentImpl.this.networkControllerImplProvider, builderProvider3, DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.carrierConfigTrackerProvider, SysUIComponentImpl.this.featureFlagsProvider, (Provider) SysUIComponentImpl.this.subscriptionManagerSlotIndexResolverProvider);
        this.getBatteryMeterViewProvider = DoubleCheck.provider(StatusBarViewModule_GetBatteryMeterViewFactory.create(getSplitShadeStatusBarViewProvider));
        this.getBatteryMeterViewControllerProvider = DoubleCheck.provider(StatusBarViewModule_GetBatteryMeterViewControllerFactory.create(getBatteryMeterViewProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, SysUIComponentImpl.this.providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideContentResolverProvider, SysUIComponentImpl.this.provideBatteryControllerProvider));
        this.splitShadeHeaderControllerProvider = DoubleCheck.provider(SplitShadeHeaderController_Factory.create(getSplitShadeStatusBarViewProvider, (Provider) SysUIComponentImpl.this.statusBarIconControllerImplProvider, headerPrivacyIconsControllerProvider, builderProvider4, SysUIComponentImpl.this.featureFlagsProvider, getBatteryMeterViewControllerProvider));
        this.notificationPanelViewControllerProvider = DoubleCheck.provider(NotificationPanelViewController_Factory.create(getNotificationPanelViewProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, SysUIComponentImpl.this.providerLayoutInflaterProvider, SysUIComponentImpl.this.notificationWakeUpCoordinatorProvider, SysUIComponentImpl.this.pulseExpansionHandlerProvider, SysUIComponentImpl.this.dynamicPrivacyControllerProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.falsingCollectorImplProvider, (Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.provideNotificationEntryManagerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, (Provider) SysUIComponentImpl.this.notificationShadeWindowControllerImplProvider, SysUIComponentImpl.this.dozeLogProvider, SysUIComponentImpl.this.dozeParametersProvider, SysUIComponentImpl.this.provideCommandQueueProvider, SysUIComponentImpl.this.vibratorHelperProvider, DaggerGlobalRootComponent.this.provideLatencyTrackerProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, DaggerGlobalRootComponent.this.provideDisplayIdProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, DaggerGlobalRootComponent.this.provideActivityManagerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, builderProvider2, SysUIComponentImpl.this.statusBarTouchableRegionManagerProvider, SysUIComponentImpl.this.conversationNotificationManagerProvider, SysUIComponentImpl.this.mediaHierarchyManagerProvider, SysUIComponentImpl.this.statusBarKeyguardViewManagerProvider, notificationsQSContainerControllerProvider, notificationStackScrollLayoutControllerProvider, SysUIComponentImpl.this.keyguardStatusViewComponentFactoryProvider, SysUIComponentImpl.this.keyguardQsUserSwitchComponentFactoryProvider, SysUIComponentImpl.this.keyguardUserSwitcherComponentFactoryProvider, SysUIComponentImpl.this.keyguardStatusBarViewComponentFactoryProvider, SysUIComponentImpl.this.lockscreenShadeTransitionControllerProvider, SysUIComponentImpl.this.qSDetailDisplayerProvider, SysUIComponentImpl.this.notificationGroupManagerLegacyProvider, SysUIComponentImpl.this.notificationIconAreaControllerProvider, SysUIComponentImpl.this.authControllerProvider, SysUIComponentImpl.this.scrimControllerProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, SysUIComponentImpl.this.mediaDataManagerProvider, SysUIComponentImpl.this.notificationShadeDepthControllerProvider, SysUIComponentImpl.this.ambientStateProvider, lockIconViewControllerProvider, SysUIComponentImpl.this.keyguardMediaControllerProvider, SysUIComponentImpl.this.privacyDotViewControllerProvider, tapAgainViewControllerProvider, SysUIComponentImpl.this.navigationModeControllerProvider, SysUIComponentImpl.this.fragmentServiceProvider, DaggerGlobalRootComponent.this.provideContentResolverProvider, SysUIComponentImpl.this.quickAccessWalletControllerProvider, SysUIComponentImpl.this.recordingControllerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, SysUIComponentImpl.this.secureSettingsImplProvider, splitShadeHeaderControllerProvider, SysUIComponentImpl.this.unlockedScreenOffAnimationControllerProvider, SysUIComponentImpl.this.lockscreenGestureLoggerProvider, SysUIComponentImpl.this.panelExpansionStateManagerProvider, SysUIComponentImpl.this.provideNotificationRemoteInputManagerProvider, SysUIComponentImpl.this.provideSysUIUnfoldComponentProvider, SysUIComponentImpl.this.controlsComponentProvider, SysUIComponentImpl.this.featureFlagsProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, DaggerGlobalRootComponent.this.contextProvider));
        this.notificationShadeWindowViewControllerProvider = NotificationShadeWindowViewController_Factory.create(SysUIComponentImpl.this.notificationWakeUpCoordinatorProvider, SysUIComponentImpl.this.pulseExpansionHandlerProvider, SysUIComponentImpl.this.dynamicPrivacyControllerProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, SysUIComponentImpl.this.lockscreenShadeTransitionControllerProvider, SysUIComponentImpl.this.falsingCollectorImplProvider, DaggerGlobalRootComponent.this.providesPluginManagerProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, (Provider) SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider, SysUIComponentImpl.this.provideNotificationEntryManagerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.dozeLogProvider, SysUIComponentImpl.this.dozeParametersProvider, SysUIComponentImpl.this.provideCommandQueueProvider, (Provider) SysUIComponentImpl.this.shadeControllerImplProvider, (Provider) SysUIComponentImpl.this.dockManagerImplProvider, SysUIComponentImpl.this.notificationShadeDepthControllerProvider, providesNotificationShadeWindowViewProvider, notificationPanelViewControllerProvider, SysUIComponentImpl.this.panelExpansionStateManagerProvider, SysUIComponentImpl.this.statusBarWindowControllerProvider, notificationStackScrollLayoutControllerProvider, SysUIComponentImpl.this.statusBarKeyguardViewManagerProvider, lockIconViewControllerProvider, DaggerGlobalRootComponent.this.contextProvider);
        this.statusBarDemoModeProvider = DoubleCheck.provider(StatusBarDemoMode_Factory.create(SysUIComponentImpl.this.provideStatusBarProvider, (Provider) SysUIComponentImpl.this.notificationShadeWindowControllerImplProvider, notificationShadeWindowViewControllerProvider, SysUIComponentImpl.this.navigationBarControllerProvider, DaggerGlobalRootComponent.this.provideDisplayIdProvider));
        this.statusBarHeadsUpChangeListenerProvider = DoubleCheck.provider(StatusBarHeadsUpChangeListener_Factory.create((Provider) SysUIComponentImpl.this.notificationShadeWindowControllerImplProvider, SysUIComponentImpl.this.statusBarWindowControllerProvider, notificationPanelViewControllerProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.provideNotificationRemoteInputManagerProvider, SysUIComponentImpl.this.provideNotificationsControllerProvider, SysUIComponentImpl.this.dozeServiceHostProvider, SysUIComponentImpl.this.dozeScrimControllerProvider));
        this.statusBarCommandQueueCallbacksProvider = DoubleCheck.provider(StatusBarCommandQueueCallbacks_Factory.create(SysUIComponentImpl.this.provideStatusBarProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, (Provider) SysUIComponentImpl.this.shadeControllerImplProvider, SysUIComponentImpl.this.provideCommandQueueProvider, notificationPanelViewControllerProvider, SysUIComponentImpl.this.setLegacySplitScreenProvider, SysUIComponentImpl.this.remoteInputQuickSettingsDisablerProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider, SysUIComponentImpl.this.wakefulnessLifecycleProvider, SysUIComponentImpl.this.bindDeviceProvisionedControllerProvider, SysUIComponentImpl.this.statusBarKeyguardViewManagerProvider, SysUIComponentImpl.this.assistManagerProvider, SysUIComponentImpl.this.dozeServiceHostProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, providesNotificationShadeWindowViewProvider, notificationStackScrollLayoutControllerProvider, SysUIComponentImpl.this.statusBarHideIconsForBouncerManagerProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, SysUIComponentImpl.this.vibratorHelperProvider, DaggerGlobalRootComponent.this.provideOptionalVibratorProvider, SysUIComponentImpl.this.lightBarControllerProvider, SysUIComponentImpl.this.disableFlagsLoggerProvider, DaggerGlobalRootComponent.this.provideDisplayIdProvider));
      }

      @Override
      public NotificationShadeWindowView getNotificationShadeWindowView() {
        return providesNotificationShadeWindowViewProvider.get();
      }

      @Override
      public VisualizerView getVisualizerView() {
        return providesVisualizerViewProvider.get();
      }

      @Override
      public NotificationShelfController getNotificationShelfController() {
        return providesStatusBarWindowViewProvider.get();
      }

      @Override
      public NotificationStackScrollLayoutController getNotificationStackScrollLayoutController() {
        return notificationStackScrollLayoutControllerProvider.get();
      }

      @Override
      public NotificationShadeWindowViewController getNotificationShadeWindowViewController() {
        return new NotificationShadeWindowViewController(SysUIComponentImpl.this.notificationWakeUpCoordinatorProvider.get(), SysUIComponentImpl.this.pulseExpansionHandlerProvider.get(), SysUIComponentImpl.this.dynamicPrivacyControllerProvider.get(), SysUIComponentImpl.this.keyguardBypassControllerProvider.get(), SysUIComponentImpl.this.lockscreenShadeTransitionControllerProvider.get(), (FalsingCollector) SysUIComponentImpl.this.falsingCollectorImplProvider.get(), DaggerGlobalRootComponent.this.providesPluginManagerProvider.get(), SysUIComponentImpl.this.tunerServiceImplProvider.get(), SysUIComponentImpl.this.notificationLockscreenUserManagerImplProvider.get(), SysUIComponentImpl.this.provideNotificationEntryManagerProvider.get(), SysUIComponentImpl.this.keyguardStateControllerImplProvider.get(), SysUIComponentImpl.this.statusBarStateControllerImplProvider.get(), SysUIComponentImpl.this.dozeLogProvider.get(), SysUIComponentImpl.this.dozeParametersProvider.get(), SysUIComponentImpl.this.provideCommandQueueProvider.get(), SysUIComponentImpl.this.shadeControllerImplProvider.get(), SysUIComponentImpl.this.dockManagerImplProvider.get(), SysUIComponentImpl.this.notificationShadeDepthControllerProvider.get(), providesNotificationShadeWindowViewProvider.get(), notificationPanelViewControllerProvider.get(), SysUIComponentImpl.this.panelExpansionStateManagerProvider.get(), SysUIComponentImpl.this.statusBarWindowControllerProvider.get(), notificationStackScrollLayoutControllerProvider.get(), SysUIComponentImpl.this.statusBarKeyguardViewManagerProvider.get(), lockIconViewControllerProvider.get(), DaggerGlobalRootComponent.this.context);
      }

      @Override
      public NotificationPanelViewController getNotificationPanelViewController() {
        return notificationPanelViewControllerProvider.get();
      }

      @Override
      public LockIconViewController getLockIconViewController() {
        return lockIconViewControllerProvider.get();
      }

      @Override
      public AuthRippleController getAuthRippleController() {
        return authRippleControllerProvider.get();
      }

      @Override
      public StatusBarDemoMode getStatusBarDemoMode() {
        return statusBarDemoModeProvider.get();
      }

      @Override
      public StatusBarHeadsUpChangeListener getStatusBarHeadsUpChangeListener() {
        return statusBarHeadsUpChangeListenerProvider.get();
      }

      @Override
      public StatusBarCommandQueueCallbacks getStatusBarCommandQueueCallbacks() {
        return statusBarCommandQueueCallbacksProvider.get();
      }

      @Override
      public SplitShadeHeaderController getSplitShadeHeaderController() {
        return splitShadeHeaderControllerProvider.get();
      }

      @Override
      public CollapsedStatusBarFragment createCollapsedStatusBarFragment() {
        return new CollapsedStatusBarFragment(new StatusBarFragmentComponentFactory(), SysUIComponentImpl.this.provideOngoingCallControllerProvider.get(), SysUIComponentImpl.this.systemStatusAnimationSchedulerProvider.get(), SysUIComponentImpl.this.statusBarLocationPublisherProvider.get(), SysUIComponentImpl.this.notificationIconAreaControllerProvider.get(), SysUIComponentImpl.this.panelExpansionStateManagerProvider.get(), SysUIComponentImpl.this.featureFlagsProvider.get(), SysUIComponentImpl.this.statusBarIconControllerImplProvider.get(), SysUIComponentImpl.this.statusBarHideIconsForBouncerManagerProvider.get(), SysUIComponentImpl.this.keyguardStateControllerImplProvider.get(), notificationPanelViewControllerProvider.get(), SysUIComponentImpl.this.networkControllerImplProvider.get(), SysUIComponentImpl.this.statusBarStateControllerImplProvider.get(), SysUIComponentImpl.this.provideCommandQueueProvider.get(), SysUIComponentImpl.this.collapsedStatusBarFragmentLogger(), SysUIComponentImpl.this.operatorNameViewControllerFactory(), (SecureSettings) SysUIComponentImpl.this.secureSettingsImpl(), DaggerGlobalRootComponent.this.provideMainExecutorProvider.get());
      }

      private final class StatusBarFragmentComponentFactory implements StatusBarFragmentComponent.Factory {
        @Override
        public StatusBarFragmentComponent create(
            CollapsedStatusBarFragment collapsedStatusBarFragment) {
          Preconditions.checkNotNull(collapsedStatusBarFragment);
          return new StatusBarFragmentComponentImpl(collapsedStatusBarFragment);
        }
      }

      private final class StatusBarFragmentComponentImpl implements StatusBarFragmentComponent {
        private Provider<CollapsedStatusBarFragment> collapsedStatusBarFragmentProvider;

        private Provider<PhoneStatusBarView> providePhoneStatusBarViewProvider;

        private Provider<BatteryMeterView> provideBatteryMeterViewProvider;

        private Provider<PhoneStatusBarViewController.Factory> factoryProvider;

        private Provider<PhoneStatusBarViewController> providePhoneStatusBarViewControllerProvider;

        private Provider<HeadsUpAppearanceController> headsUpAppearanceControllerProvider;

        private StatusBarFragmentComponentImpl(
            CollapsedStatusBarFragment collapsedStatusBarFragmentParam) {

          initialize(collapsedStatusBarFragmentParam);
        }

        @SuppressWarnings("unchecked")
        private void initialize(final CollapsedStatusBarFragment collapsedStatusBarFragmentParam) {
          this.collapsedStatusBarFragmentProvider = InstanceFactory.create(collapsedStatusBarFragmentParam);
          this.providePhoneStatusBarViewProvider = DoubleCheck.provider(StatusBarFragmentModule_ProvidePhoneStatusBarViewFactory.create(collapsedStatusBarFragmentProvider));
          this.provideBatteryMeterViewProvider = DoubleCheck.provider(StatusBarFragmentModule_ProvideBatteryMeterViewFactory.create(providePhoneStatusBarViewProvider));
          this.factoryProvider = PhoneStatusBarViewController_Factory_Factory.create(SysUIComponentImpl.this.provideSysUIUnfoldComponentProvider, DaggerGlobalRootComponent.this.provideStatusBarScopedTransitionProvider);
          this.providePhoneStatusBarViewControllerProvider = DoubleCheck.provider(StatusBarFragmentModule_ProvidePhoneStatusBarViewControllerFactory.create(factoryProvider, providePhoneStatusBarViewProvider, StatusBarComponentImpl.this.notificationPanelViewControllerProvider));
          this.headsUpAppearanceControllerProvider = DoubleCheck.provider(HeadsUpAppearanceController_Factory.create(SysUIComponentImpl.this.notificationIconAreaControllerProvider, SysUIComponentImpl.this.provideHeadsUpManagerPhoneProvider, StatusBarComponentImpl.this.notificationStackScrollLayoutControllerProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, SysUIComponentImpl.this.notificationWakeUpCoordinatorProvider, SysUIComponentImpl.this.provideCommandQueueProvider, StatusBarComponentImpl.this.notificationPanelViewControllerProvider, providePhoneStatusBarViewProvider));
        }

        @Override
        public BatteryMeterViewController getBatteryMeterViewController() {
          return new BatteryMeterViewController(provideBatteryMeterViewProvider.get(), SysUIComponentImpl.this.provideConfigurationControllerProvider.get(), SysUIComponentImpl.this.tunerServiceImplProvider.get(), SysUIComponentImpl.this.providesBroadcastDispatcherProvider.get(), DaggerGlobalRootComponent.this.mainHandler(), DaggerGlobalRootComponent.this.provideContentResolverProvider.get(), SysUIComponentImpl.this.provideBatteryControllerProvider.get());
        }

        @Override
        public PhoneStatusBarView getPhoneStatusBarView() {
          return providePhoneStatusBarViewProvider.get();
        }

        @Override
        public PhoneStatusBarViewController getPhoneStatusBarViewController() {
          return providePhoneStatusBarViewControllerProvider.get();
        }

        @Override
        public HeadsUpAppearanceController getHeadsUpAppearanceController() {
          return headsUpAppearanceControllerProvider.get();
        }
      }
    }

    private final class KeyguardStatusViewComponentFactory implements KeyguardStatusViewComponent.Factory {
      @Override
      public KeyguardStatusViewComponent build(KeyguardStatusView presentation) {
        Preconditions.checkNotNull(presentation);
        return new KeyguardStatusViewComponentImpl(presentation);
      }
    }

    private final class KeyguardStatusViewComponentImpl implements KeyguardStatusViewComponent {
      private final KeyguardStatusView presentation;

      private Provider<KeyguardStatusView> presentationProvider;

      private Provider<KeyguardClockSwitch> getKeyguardClockSwitchProvider;

      private Provider<KeyguardSliceView> getKeyguardSliceViewProvider;

      private Provider<KeyguardSliceViewController> keyguardSliceViewControllerProvider;

      private KeyguardStatusViewComponentImpl(KeyguardStatusView presentationParam) {
        this.presentation = presentationParam;
        initialize(presentationParam);
      }

      private KeyguardClockSwitch keyguardClockSwitch() {
        return KeyguardStatusViewModule_GetKeyguardClockSwitchFactory.getKeyguardClockSwitch(presentation);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final KeyguardStatusView presentationParam) {
        this.presentationProvider = InstanceFactory.create(presentationParam);
        this.getKeyguardClockSwitchProvider = KeyguardStatusViewModule_GetKeyguardClockSwitchFactory.create(presentationProvider);
        this.getKeyguardSliceViewProvider = KeyguardStatusViewModule_GetKeyguardSliceViewFactory.create(getKeyguardClockSwitchProvider);
        this.keyguardSliceViewControllerProvider = DoubleCheck.provider(KeyguardSliceViewController_Factory.create(getKeyguardSliceViewProvider, SysUIComponentImpl.this.provideActivityStarterProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, DaggerGlobalRootComponent.this.dumpManagerProvider));
      }

      @Override
      public KeyguardClockSwitchController getKeyguardClockSwitchController() {
        return new KeyguardClockSwitchController(keyguardClockSwitch(), SysUIComponentImpl.this.statusBarStateControllerImplProvider.get(), SysUIComponentImpl.this.sysuiColorExtractorProvider.get(), SysUIComponentImpl.this.clockManagerProvider.get(), keyguardSliceViewControllerProvider.get(), SysUIComponentImpl.this.notificationIconAreaControllerProvider.get(), SysUIComponentImpl.this.providesBroadcastDispatcherProvider.get(), SysUIComponentImpl.this.provideBatteryControllerProvider.get(), SysUIComponentImpl.this.keyguardUpdateMonitorProvider.get(), SysUIComponentImpl.this.keyguardBypassControllerProvider.get(), SysUIComponentImpl.this.lockscreenSmartspaceControllerProvider.get(), SysUIComponentImpl.this.keyguardUnlockAnimationControllerProvider.get(), SysUIComponentImpl.this.provideSmartspaceTransitionControllerProvider.get(), (SecureSettings) SysUIComponentImpl.this.secureSettingsImpl(), DaggerGlobalRootComponent.this.provideMainExecutorProvider.get(), DaggerGlobalRootComponent.this.mainResources());
      }

      @Override
      public KeyguardStatusViewController getKeyguardStatusViewController() {
        return new KeyguardStatusViewController(presentation, keyguardSliceViewControllerProvider.get(), getKeyguardClockSwitchController(), SysUIComponentImpl.this.keyguardStateControllerImplProvider.get(), SysUIComponentImpl.this.keyguardUpdateMonitorProvider.get(), SysUIComponentImpl.this.provideConfigurationControllerProvider.get(), SysUIComponentImpl.this.dozeParametersProvider.get(), SysUIComponentImpl.this.keyguardUnlockAnimationControllerProvider.get(), SysUIComponentImpl.this.provideSmartspaceTransitionControllerProvider.get(), SysUIComponentImpl.this.unlockedScreenOffAnimationControllerProvider.get());
      }
    }

    private final class SysUIUnfoldComponentFactory implements SysUIUnfoldComponent.Factory {
      @Override
      public SysUIUnfoldComponent create(UnfoldTransitionProgressProvider p1,
          NaturalRotationUnfoldProgressProvider p2, ScopedUnfoldTransitionProgressProvider p3) {
        Preconditions.checkNotNull(p1);
        Preconditions.checkNotNull(p2);
        Preconditions.checkNotNull(p3);
        return new SysUIUnfoldComponentImpl(p1, p2, p3);
      }
    }

    private final class SysUIUnfoldComponentImpl implements SysUIUnfoldComponent {
      private Provider<NaturalRotationUnfoldProgressProvider> p2Provider;

      private Provider<KeyguardUnfoldTransition> keyguardUnfoldTransitionProvider;

      private Provider<ScopedUnfoldTransitionProgressProvider> p3Provider;

      private Provider<StatusBarMoveFromCenterAnimationController> statusBarMoveFromCenterAnimationControllerProvider;

      private Provider<UnfoldTransitionProgressProvider> p1Provider;

      private Provider<UnfoldTransitionWallpaperController> unfoldTransitionWallpaperControllerProvider;

      private Provider<UnfoldLightRevealOverlayAnimation> unfoldLightRevealOverlayAnimationProvider;

      private SysUIUnfoldComponentImpl(UnfoldTransitionProgressProvider p1Param,
          NaturalRotationUnfoldProgressProvider p2Param,
          ScopedUnfoldTransitionProgressProvider p3Param) {

        initialize(p1Param, p2Param, p3Param);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final UnfoldTransitionProgressProvider p1Param,
          final NaturalRotationUnfoldProgressProvider p2Param,
          final ScopedUnfoldTransitionProgressProvider p3Param) {
        this.p2Provider = InstanceFactory.create(p2Param);
        this.keyguardUnfoldTransitionProvider = DoubleCheck.provider(KeyguardUnfoldTransition_Factory.create(DaggerGlobalRootComponent.this.contextProvider, p2Provider));
        this.p3Provider = InstanceFactory.create(p3Param);
        this.statusBarMoveFromCenterAnimationControllerProvider = DoubleCheck.provider(StatusBarMoveFromCenterAnimationController_Factory.create(p3Provider, DaggerGlobalRootComponent.this.provideWindowManagerProvider));
        this.p1Provider = InstanceFactory.create(p1Param);
        this.unfoldTransitionWallpaperControllerProvider = DoubleCheck.provider(UnfoldTransitionWallpaperController_Factory.create(p1Provider, SysUIComponentImpl.this.wallpaperControllerProvider));
        this.unfoldLightRevealOverlayAnimationProvider = DoubleCheck.provider(UnfoldLightRevealOverlayAnimation_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideDeviceStateManagerProvider, DaggerGlobalRootComponent.this.provideDisplayManagerProvider, p1Provider, SysUIComponentImpl.this.setDisplayAreaHelperProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, SysUIComponentImpl.this.provideUiBackgroundExecutorProvider));
      }

      @Override
      public KeyguardUnfoldTransition getKeyguardUnfoldTransition() {
        return keyguardUnfoldTransitionProvider.get();
      }

      @Override
      public StatusBarMoveFromCenterAnimationController getStatusBarMoveFromCenterAnimationController(
          ) {
        return statusBarMoveFromCenterAnimationControllerProvider.get();
      }

      @Override
      public UnfoldTransitionWallpaperController getUnfoldTransitionWallpaperController() {
        return unfoldTransitionWallpaperControllerProvider.get();
      }

      @Override
      public UnfoldLightRevealOverlayAnimation getUnfoldLightRevealOverlayAnimation() {
        return unfoldLightRevealOverlayAnimationProvider.get();
      }
    }

    private final class KeyguardBouncerComponentFactory implements KeyguardBouncerComponent.Factory {
      @Override
      public KeyguardBouncerComponent create() {
        return new KeyguardBouncerComponentImpl();
      }
    }

    private final class KeyguardBouncerComponentImpl implements KeyguardBouncerComponent {
      private Provider<ViewGroup> providesRootViewProvider;

      private Provider<KeyguardRootViewController> keyguardRootViewControllerProvider;

      private Provider<KeyguardHostView> providesKeyguardHostViewProvider;

      private Provider<KeyguardSecurityContainer> providesKeyguardSecurityContainerProvider;

      private Provider<AdminSecondaryLockScreenController.Factory> factoryProvider;

      private Provider<KeyguardSecurityViewFlipper> providesKeyguardSecurityViewFlipperProvider;

      @SuppressWarnings("rawtypes")
      private Provider liftToActivateListenerProvider;

      private Provider<EmergencyButtonController.Factory> factoryProvider2;

      private Provider<KeyguardInputViewController.Factory> factoryProvider3;

      private Provider<KeyguardSecurityViewFlipperController> keyguardSecurityViewFlipperControllerProvider;

      @SuppressWarnings("rawtypes")
      private Provider factoryProvider4;

      private Provider<KeyguardHostViewController> keyguardHostViewControllerProvider;

      private KeyguardBouncerComponentImpl() {

        initialize();
      }

      @SuppressWarnings("unchecked")
      private void initialize() {
        this.providesRootViewProvider = DoubleCheck.provider(KeyguardBouncerModule_ProvidesRootViewFactory.create(SysUIComponentImpl.this.providerLayoutInflaterProvider));
        this.keyguardRootViewControllerProvider = DoubleCheck.provider(KeyguardRootViewController_Factory.create(providesRootViewProvider));
        this.providesKeyguardHostViewProvider = DoubleCheck.provider(KeyguardBouncerModule_ProvidesKeyguardHostViewFactory.create(providesRootViewProvider));
        this.providesKeyguardSecurityContainerProvider = DoubleCheck.provider(KeyguardBouncerModule_ProvidesKeyguardSecurityContainerFactory.create(providesKeyguardHostViewProvider));
        this.factoryProvider = DoubleCheck.provider(AdminSecondaryLockScreenController_Factory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesKeyguardSecurityContainerProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
        this.providesKeyguardSecurityViewFlipperProvider = DoubleCheck.provider(KeyguardBouncerModule_ProvidesKeyguardSecurityViewFlipperFactory.create(providesKeyguardSecurityContainerProvider));
        this.liftToActivateListenerProvider = LiftToActivateListener_Factory.create(DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider);
        this.factoryProvider2 = EmergencyButtonController_Factory_Factory.create(SysUIComponentImpl.this.provideConfigurationControllerProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, DaggerGlobalRootComponent.this.providePowerManagerProvider, DaggerGlobalRootComponent.this.provideActivityTaskManagerProvider, (Provider) SysUIComponentImpl.this.shadeControllerImplProvider, DaggerGlobalRootComponent.this.provideTelecomManagerProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider);
        this.factoryProvider3 = KeyguardInputViewController_Factory_Factory.create(SysUIComponentImpl.this.keyguardUpdateMonitorProvider, SysUIComponentImpl.this.provideLockPatternUtilsProvider, DaggerGlobalRootComponent.this.provideLatencyTrackerProvider, SysUIComponentImpl.this.factoryProvider7, DaggerGlobalRootComponent.this.provideInputMethodManagerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, liftToActivateListenerProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, SysUIComponentImpl.this.falsingCollectorImplProvider, factoryProvider2, (Provider) SysUIComponentImpl.this.devicePostureControllerImplProvider);
        this.keyguardSecurityViewFlipperControllerProvider = DoubleCheck.provider(KeyguardSecurityViewFlipperController_Factory.create(providesKeyguardSecurityViewFlipperProvider, SysUIComponentImpl.this.providerLayoutInflaterProvider, factoryProvider3, factoryProvider2));
        this.factoryProvider4 = KeyguardSecurityContainerController_Factory_Factory.create(providesKeyguardSecurityContainerProvider, factoryProvider, SysUIComponentImpl.this.provideLockPatternUtilsProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, SysUIComponentImpl.this.keyguardSecurityModelProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, keyguardSecurityViewFlipperControllerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, SysUIComponentImpl.this.falsingCollectorImplProvider);
        this.keyguardHostViewControllerProvider = DoubleCheck.provider(KeyguardHostViewController_Factory.create(providesKeyguardHostViewProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, DaggerGlobalRootComponent.this.provideAudioManagerProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, SysUIComponentImpl.this.providesViewMediatorCallbackProvider, factoryProvider4));
      }

      @Override
      public KeyguardRootViewController getKeyguardRootViewController() {
        return keyguardRootViewControllerProvider.get();
      }

      @Override
      public KeyguardHostViewController getKeyguardHostViewController() {
        return keyguardHostViewControllerProvider.get();
      }
    }

    private final class DozeComponentFactory implements DozeComponent.Builder {
      @Override
      public DozeComponent build(DozeMachine.Service dozeMachineService) {
        Preconditions.checkNotNull(dozeMachineService);
        return new DozeComponentImpl(dozeMachineService);
      }
    }

    private final class DozeComponentImpl implements DozeComponent {
      private Provider<DozeMachine.Service> dozeMachineServiceProvider;

      private Provider<DozeMachine.Service> providesWrappedServiceProvider;

      private Provider<WakeLock> providesDozeWakeLockProvider;

      private Provider<DozePauser> dozePauserProvider;

      private Provider<DozeFalsingManagerAdapter> dozeFalsingManagerAdapterProvider;

      private Provider<DozeTriggers> dozeTriggersProvider;

      private Provider<DozeUi> dozeUiProvider;

      private Provider<Optional<Sensor>[]> providesBrightnessSensorsProvider;

      private Provider<DozeScreenBrightness> dozeScreenBrightnessProvider;

      private Provider<DozeScreenState> dozeScreenStateProvider;

      private Provider<DozeWallpaperState> dozeWallpaperStateProvider;

      private Provider<DozeDockHandler> dozeDockHandlerProvider;

      private Provider<DozeAuthRemover> dozeAuthRemoverProvider;

      private Provider<DozeMachine.Part[]> providesDozeMachinePartesProvider;

      private Provider<DozeMachine> dozeMachineProvider;

      private DozeComponentImpl(DozeMachine.Service dozeMachineServiceParam) {

        initialize(dozeMachineServiceParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final DozeMachine.Service dozeMachineServiceParam) {
        this.dozeMachineServiceProvider = InstanceFactory.create(dozeMachineServiceParam);
        this.providesWrappedServiceProvider = DoubleCheck.provider(DozeModule_ProvidesWrappedServiceFactory.create(dozeMachineServiceProvider, (Provider) SysUIComponentImpl.this.dozeServiceHostProvider, SysUIComponentImpl.this.dozeParametersProvider));
        this.providesDozeWakeLockProvider = DoubleCheck.provider(DozeModule_ProvidesDozeWakeLockFactory.create(SysUIComponentImpl.this.builderProvider3, DaggerGlobalRootComponent.this.provideMainHandlerProvider));
        this.dozePauserProvider = DoubleCheck.provider(DozePauser_Factory.create(DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideAlarmManagerProvider, SysUIComponentImpl.this.provideAlwaysOnDisplayPolicyProvider));
        this.dozeFalsingManagerAdapterProvider = DoubleCheck.provider(DozeFalsingManagerAdapter_Factory.create(SysUIComponentImpl.this.falsingCollectorImplProvider));
        this.dozeTriggersProvider = DoubleCheck.provider(DozeTriggers_Factory.create(DaggerGlobalRootComponent.this.contextProvider, (Provider) SysUIComponentImpl.this.dozeServiceHostProvider, SysUIComponentImpl.this.provideAmbientDisplayConfigurationProvider, SysUIComponentImpl.this.dozeParametersProvider, SysUIComponentImpl.this.asyncSensorManagerProvider, providesDozeWakeLockProvider, (Provider) SysUIComponentImpl.this.dockManagerImplProvider, SysUIComponentImpl.this.provideProximitySensorProvider, SysUIComponentImpl.this.provideProximityCheckProvider, SysUIComponentImpl.this.dozeLogProvider, SysUIComponentImpl.this.providesBroadcastDispatcherProvider, SysUIComponentImpl.this.secureSettingsImplProvider, SysUIComponentImpl.this.authControllerProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.devicePostureControllerImplProvider));
        this.dozeUiProvider = DoubleCheck.provider(DozeUi_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideAlarmManagerProvider, providesDozeWakeLockProvider, (Provider) SysUIComponentImpl.this.dozeServiceHostProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, SysUIComponentImpl.this.dozeParametersProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, SysUIComponentImpl.this.dozeLogProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider));
        this.providesBrightnessSensorsProvider = DozeModule_ProvidesBrightnessSensorsFactory.create(SysUIComponentImpl.this.asyncSensorManagerProvider, DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.dozeParametersProvider);
        this.dozeScreenBrightnessProvider = DoubleCheck.provider(DozeScreenBrightness_Factory.create(DaggerGlobalRootComponent.this.contextProvider, providesWrappedServiceProvider, SysUIComponentImpl.this.asyncSensorManagerProvider, providesBrightnessSensorsProvider, (Provider) SysUIComponentImpl.this.dozeServiceHostProvider, SysUIComponentImpl.this.provideHandlerProvider, SysUIComponentImpl.this.provideAlwaysOnDisplayPolicyProvider, SysUIComponentImpl.this.wakefulnessLifecycleProvider, SysUIComponentImpl.this.dozeParametersProvider, (Provider) SysUIComponentImpl.this.devicePostureControllerImplProvider, SysUIComponentImpl.this.dozeLogProvider, SysUIComponentImpl.this.unlockedScreenOffAnimationControllerProvider));
        this.dozeScreenStateProvider = DoubleCheck.provider(DozeScreenState_Factory.create(providesWrappedServiceProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, (Provider) SysUIComponentImpl.this.dozeServiceHostProvider, SysUIComponentImpl.this.dozeParametersProvider, providesDozeWakeLockProvider, SysUIComponentImpl.this.authControllerProvider, SysUIComponentImpl.this.udfpsControllerProvider, SysUIComponentImpl.this.dozeLogProvider, dozeScreenBrightnessProvider));
        this.dozeWallpaperStateProvider = DoubleCheck.provider(DozeWallpaperState_Factory.create(FrameworkServicesModule_ProvideIWallPaperManagerFactory.create(), SysUIComponentImpl.this.biometricUnlockControllerProvider, SysUIComponentImpl.this.dozeParametersProvider));
        this.dozeDockHandlerProvider = DoubleCheck.provider(DozeDockHandler_Factory.create(SysUIComponentImpl.this.provideAmbientDisplayConfigurationProvider, (Provider) SysUIComponentImpl.this.dockManagerImplProvider));
        this.dozeAuthRemoverProvider = DoubleCheck.provider(DozeAuthRemover_Factory.create(SysUIComponentImpl.this.keyguardUpdateMonitorProvider));
        this.providesDozeMachinePartesProvider = DozeModule_ProvidesDozeMachinePartesFactory.create(dozePauserProvider, dozeFalsingManagerAdapterProvider, dozeTriggersProvider, dozeUiProvider, dozeScreenStateProvider, dozeScreenBrightnessProvider, dozeWallpaperStateProvider, dozeDockHandlerProvider, dozeAuthRemoverProvider);
        this.dozeMachineProvider = DoubleCheck.provider(DozeMachine_Factory.create(providesWrappedServiceProvider, SysUIComponentImpl.this.provideAmbientDisplayConfigurationProvider, providesDozeWakeLockProvider, SysUIComponentImpl.this.wakefulnessLifecycleProvider, SysUIComponentImpl.this.provideBatteryControllerProvider, SysUIComponentImpl.this.dozeLogProvider, (Provider) SysUIComponentImpl.this.dockManagerImplProvider, (Provider) SysUIComponentImpl.this.dozeServiceHostProvider, providesDozeMachinePartesProvider));
      }

      @Override
      public DozeMachine getDozeMachine() {
        return dozeMachineProvider.get();
      }
    }

    private final class QSFragmentComponentFactory implements QSFragmentComponent.Factory {
      @Override
      public QSFragmentComponent create(QSFragment qsFragment) {
        Preconditions.checkNotNull(qsFragment);
        return new QSFragmentComponentImpl(qsFragment);
      }
    }

    private final class QSFragmentComponentImpl implements QSFragmentComponent {
      private Provider<QSFragment> qsFragmentProvider;

      private Provider<View> provideRootViewProvider;

      private Provider<QSPanel> provideQSPanelProvider;

      private Provider<Context> provideThemedContextProvider;

      private Provider<LayoutInflater> provideThemedLayoutInflaterProvider;

      private Provider<View> providesQSSecurityFooterViewProvider;

      @SuppressWarnings("rawtypes")
      private Provider qSSecurityFooterProvider;

      private Provider<QSCustomizer> providesQSCutomizerProvider;

      private Provider<TileQueryHelper> tileQueryHelperProvider;

      private Provider<TileAdapter> tileAdapterProvider;

      private Provider<QSCustomizerController> qSCustomizerControllerProvider;

      private Provider<Boolean> providesQSUsingMediaPlayerProvider;

      @SuppressWarnings("rawtypes")
      private Provider factoryProvider;

      private Provider<BrightnessController.Factory> factoryProvider2;

      private Provider<QSPanelController> qSPanelControllerProvider;

      private Provider<QuickStatusBarHeader> providesQuickStatusBarHeaderProvider;

      private Provider<QuickQSPanel> providesQuickQSPanelProvider;

      private Provider<MultiUserSwitchController.Factory> factoryProvider3;

      private Provider<FooterActionsControllerBuilder> footerActionsControllerBuilderProvider;

      private Provider<FooterActionsView> providesQQSFooterActionsViewProvider;

      private Provider<FooterActionsController> providesQQSFooterActionsControllerProvider;

      private Provider<QuickQSPanelController> quickQSPanelControllerProvider;

      private Provider<FooterActionsView> providesQSFooterActionsViewProvider;

      private Provider<QSAnimator> qSAnimatorProvider;

      private Provider<QSContainerImpl> providesQSContainerImplProvider;

      private Provider<OngoingPrivacyChip> providesPrivacyChipProvider;

      private Provider<StatusIconContainer> providesStatusIconContainerProvider;

      private Provider<HeaderPrivacyIconsController> headerPrivacyIconsControllerProvider;

      private Provider<CarrierTextManager.Builder> builderProvider;

      private Provider<QSCarrierGroupController.Builder> builderProvider2;

      private Provider<BatteryMeterView> providesBatteryMeterViewProvider;

      private Provider<BatteryMeterViewController> batteryMeterViewControllerProvider;

      private Provider<VariableDateViewController.Factory> factoryProvider4;

      @SuppressWarnings("rawtypes")
      private Provider quickStatusBarHeaderControllerProvider;

      private Provider<QSContainerImplController> qSContainerImplControllerProvider;

      private Provider<QSFooterView> providesQSFooterViewProvider;

      private Provider<FooterActionsController> providesQSFooterActionsControllerProvider;

      private Provider<QSFooterViewController> qSFooterViewControllerProvider;

      private Provider<QSFooter> providesQSFooterProvider;

      private Provider<QSSquishinessController> qSSquishinessControllerProvider;

      private QSFragmentComponentImpl(QSFragment qsFragmentParam) {

        initialize(qsFragmentParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final QSFragment qsFragmentParam) {
        this.qsFragmentProvider = InstanceFactory.create(qsFragmentParam);
        this.provideRootViewProvider = QSFragmentModule_ProvideRootViewFactory.create(qsFragmentProvider);
        this.provideQSPanelProvider = QSFragmentModule_ProvideQSPanelFactory.create(provideRootViewProvider);
        this.provideThemedContextProvider = QSFragmentModule_ProvideThemedContextFactory.create(provideRootViewProvider);
        this.provideThemedLayoutInflaterProvider = QSFragmentModule_ProvideThemedLayoutInflaterFactory.create(provideThemedContextProvider);
        this.providesQSSecurityFooterViewProvider = DoubleCheck.provider(QSFragmentModule_ProvidesQSSecurityFooterViewFactory.create(provideThemedLayoutInflaterProvider, provideQSPanelProvider));
        this.qSSecurityFooterProvider = DoubleCheck.provider(QSSecurityFooter_Factory.create(providesQSSecurityFooterViewProvider, SysUIComponentImpl.this.provideUserTrackerProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, SysUIComponentImpl.this.provideActivityStarterProvider, (Provider) SysUIComponentImpl.this.securityControllerImplProvider, SysUIComponentImpl.this.provideBgLooperProvider));
        this.providesQSCutomizerProvider = DoubleCheck.provider(QSFragmentModule_ProvidesQSCutomizerFactory.create(provideRootViewProvider));
        this.tileQueryHelperProvider = DoubleCheck.provider(TileQueryHelper_Factory.create(DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.provideUserTrackerProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, SysUIComponentImpl.this.provideBackgroundExecutorProvider));
        this.tileAdapterProvider = DoubleCheck.provider(TileAdapter_Factory.create(provideThemedContextProvider, SysUIComponentImpl.this.qSTileHostProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider));
        this.qSCustomizerControllerProvider = DoubleCheck.provider(QSCustomizerController_Factory.create(providesQSCutomizerProvider, tileQueryHelperProvider, SysUIComponentImpl.this.qSTileHostProvider, tileAdapterProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, SysUIComponentImpl.this.lightBarControllerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider));
        this.providesQSUsingMediaPlayerProvider = QSFragmentModule_ProvidesQSUsingMediaPlayerFactory.create(DaggerGlobalRootComponent.this.contextProvider);
        this.factoryProvider = DoubleCheck.provider(QSTileRevealController_Factory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, qSCustomizerControllerProvider));
        this.factoryProvider2 = BrightnessController_Factory_Factory.create(DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.providesBroadcastDispatcherProvider, SysUIComponentImpl.this.provideBgHandlerProvider);
        this.qSPanelControllerProvider = DoubleCheck.provider(QSPanelController_Factory.create(provideQSPanelProvider, qSSecurityFooterProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, SysUIComponentImpl.this.qSTileHostProvider, qSCustomizerControllerProvider, providesQSUsingMediaPlayerProvider, SysUIComponentImpl.this.providesQSMediaHostProvider, factoryProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, SysUIComponentImpl.this.qSLoggerProvider, factoryProvider2, SysUIComponentImpl.this.factoryProvider5, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.provideCommandQueueProvider));
        this.providesQuickStatusBarHeaderProvider = QSFragmentModule_ProvidesQuickStatusBarHeaderFactory.create(provideRootViewProvider);
        this.providesQuickQSPanelProvider = QSFragmentModule_ProvidesQuickQSPanelFactory.create(providesQuickStatusBarHeaderProvider);
        this.factoryProvider3 = DoubleCheck.provider(MultiUserSwitchController_Factory_Factory.create(DaggerGlobalRootComponent.this.provideUserManagerProvider, SysUIComponentImpl.this.userSwitcherControllerProvider, SysUIComponentImpl.this.qSDetailDisplayerProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.userSwitchDialogControllerProvider, SysUIComponentImpl.this.featureFlagsProvider));
        this.footerActionsControllerBuilderProvider = FooterActionsControllerBuilder_Factory.create(qSPanelControllerProvider, SysUIComponentImpl.this.provideActivityStarterProvider, DaggerGlobalRootComponent.this.provideUserManagerProvider, (Provider) SysUIComponentImpl.this.userInfoControllerImplProvider, factoryProvider3, SysUIComponentImpl.this.bindDeviceProvisionedControllerProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, SysUIComponentImpl.this.globalActionsDialogLiteProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, SysUIComponentImpl.this.isPMLiteEnabledProvider);
        this.providesQQSFooterActionsViewProvider = QSFragmentModule_ProvidesQQSFooterActionsViewFactory.create(provideRootViewProvider);
        this.providesQQSFooterActionsControllerProvider = QSFragmentModule_ProvidesQQSFooterActionsControllerFactory.create(footerActionsControllerBuilderProvider, providesQQSFooterActionsViewProvider);
        this.quickQSPanelControllerProvider = DoubleCheck.provider(QuickQSPanelController_Factory.create(providesQuickQSPanelProvider, SysUIComponentImpl.this.qSTileHostProvider, qSCustomizerControllerProvider, providesQSUsingMediaPlayerProvider, SysUIComponentImpl.this.providesQuickQSMediaHostProvider, SysUIComponentImpl.this.provideMetricsLoggerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, SysUIComponentImpl.this.qSLoggerProvider, DaggerGlobalRootComponent.this.dumpManagerProvider, providesQQSFooterActionsControllerProvider));
        this.providesQSFooterActionsViewProvider = QSFragmentModule_ProvidesQSFooterActionsViewFactory.create(provideRootViewProvider);
        this.qSAnimatorProvider = DoubleCheck.provider(QSAnimator_Factory.create((Provider) qsFragmentProvider, providesQuickQSPanelProvider, providesQuickStatusBarHeaderProvider, qSPanelControllerProvider, quickQSPanelControllerProvider, SysUIComponentImpl.this.qSTileHostProvider, qSSecurityFooterProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, DaggerGlobalRootComponent.this.qSExpansionPathInterpolatorProvider, providesQSFooterActionsViewProvider, providesQQSFooterActionsViewProvider));
        this.providesQSContainerImplProvider = QSFragmentModule_ProvidesQSContainerImplFactory.create(provideRootViewProvider);
        this.providesPrivacyChipProvider = DoubleCheck.provider(QSFragmentModule_ProvidesPrivacyChipFactory.create(providesQuickStatusBarHeaderProvider));
        this.providesStatusIconContainerProvider = DoubleCheck.provider(QSFragmentModule_ProvidesStatusIconContainerFactory.create(providesQuickStatusBarHeaderProvider));
        this.headerPrivacyIconsControllerProvider = HeaderPrivacyIconsController_Factory.create(SysUIComponentImpl.this.privacyItemControllerProvider, DaggerGlobalRootComponent.this.provideUiEventLoggerProvider, providesPrivacyChipProvider, SysUIComponentImpl.this.privacyDialogControllerProvider, SysUIComponentImpl.this.privacyLoggerProvider, providesStatusIconContainerProvider, SysUIComponentImpl.this.bindDeviceProvisionedControllerProvider);
        this.builderProvider = CarrierTextManager_Builder_Factory.create(DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.provideWifiManagerProvider, DaggerGlobalRootComponent.this.provideTelephonyManagerProvider, SysUIComponentImpl.this.telephonyListenerManagerProvider, SysUIComponentImpl.this.wakefulnessLifecycleProvider, DaggerGlobalRootComponent.this.provideMainExecutorProvider, SysUIComponentImpl.this.provideBackgroundExecutorProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider);
        this.builderProvider2 = QSCarrierGroupController_Builder_Factory.create(SysUIComponentImpl.this.provideActivityStarterProvider, SysUIComponentImpl.this.provideBgHandlerProvider, GlobalConcurrencyModule_ProvideMainLooperFactory.create(), (Provider) SysUIComponentImpl.this.networkControllerImplProvider, builderProvider, DaggerGlobalRootComponent.this.contextProvider, SysUIComponentImpl.this.carrierConfigTrackerProvider, SysUIComponentImpl.this.featureFlagsProvider, (Provider) SysUIComponentImpl.this.subscriptionManagerSlotIndexResolverProvider);
        this.providesBatteryMeterViewProvider = QSFragmentModule_ProvidesBatteryMeterViewFactory.create(providesQuickStatusBarHeaderProvider);
        this.batteryMeterViewControllerProvider = BatteryMeterViewController_Factory.create(providesBatteryMeterViewProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, (Provider) SysUIComponentImpl.this.tunerServiceImplProvider, SysUIComponentImpl.this.providesBroadcastDispatcherProvider, DaggerGlobalRootComponent.this.provideMainHandlerProvider, DaggerGlobalRootComponent.this.provideContentResolverProvider, SysUIComponentImpl.this.provideBatteryControllerProvider);
        this.factoryProvider4 = VariableDateViewController_Factory_Factory.create(SysUIComponentImpl.this.bindSystemClockProvider, SysUIComponentImpl.this.providesBroadcastDispatcherProvider, SysUIComponentImpl.this.provideTimeTickHandlerProvider);
        this.quickStatusBarHeaderControllerProvider = DoubleCheck.provider(QuickStatusBarHeaderController_Factory.create(providesQuickStatusBarHeaderProvider, headerPrivacyIconsControllerProvider, (Provider) SysUIComponentImpl.this.statusBarIconControllerImplProvider, SysUIComponentImpl.this.provideDemoModeControllerProvider, quickQSPanelControllerProvider, builderProvider2, DaggerGlobalRootComponent.this.qSExpansionPathInterpolatorProvider, batteryMeterViewControllerProvider, SysUIComponentImpl.this.featureFlagsProvider, factoryProvider4, SysUIComponentImpl.this.statusBarContentInsetsProvider));
        this.qSContainerImplControllerProvider = DoubleCheck.provider(QSContainerImplController_Factory.create(providesQSContainerImplProvider, qSPanelControllerProvider, quickStatusBarHeaderControllerProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider));
        this.providesQSFooterViewProvider = QSFragmentModule_ProvidesQSFooterViewFactory.create(provideRootViewProvider);
        this.providesQSFooterActionsControllerProvider = QSFragmentModule_ProvidesQSFooterActionsControllerFactory.create(footerActionsControllerBuilderProvider, providesQSFooterActionsViewProvider);
        this.qSFooterViewControllerProvider = DoubleCheck.provider(QSFooterViewController_Factory.create(providesQSFooterViewProvider, SysUIComponentImpl.this.provideUserTrackerProvider, qSPanelControllerProvider, quickQSPanelControllerProvider, providesQSFooterActionsControllerProvider));
        this.providesQSFooterProvider = DoubleCheck.provider(QSFragmentModule_ProvidesQSFooterFactory.create(qSFooterViewControllerProvider));
        this.qSSquishinessControllerProvider = DoubleCheck.provider(QSSquishinessController_Factory.create(qSAnimatorProvider, qSPanelControllerProvider, quickQSPanelControllerProvider));
      }

      @Override
      public QSPanelController getQSPanelController() {
        return qSPanelControllerProvider.get();
      }

      @Override
      public QuickQSPanelController getQuickQSPanelController() {
        return quickQSPanelControllerProvider.get();
      }

      @Override
      public QSAnimator getQSAnimator() {
        return qSAnimatorProvider.get();
      }

      @Override
      public QSContainerImplController getQSContainerImplController() {
        return qSContainerImplControllerProvider.get();
      }

      @Override
      public QSFooter getQSFooter() {
        return providesQSFooterProvider.get();
      }

      @Override
      public QSCustomizerController getQSCustomizerController() {
        return qSCustomizerControllerProvider.get();
      }

      @Override
      public QSSquishinessController getQSSquishinessController() {
        return qSSquishinessControllerProvider.get();
      }
    }

    private final class NotificationShelfComponentBuilder implements NotificationShelfComponent.Builder {
      private NotificationShelf notificationShelf;

      @Override
      public NotificationShelfComponentBuilder notificationShelf(NotificationShelf view) {
        this.notificationShelf = Preconditions.checkNotNull(view);
        return this;
      }

      @Override
      public NotificationShelfComponent build() {
        Preconditions.checkBuilderRequirement(notificationShelf, NotificationShelf.class);
        return new NotificationShelfComponentImpl(notificationShelf);
      }
    }

    private final class NotificationShelfComponentImpl implements NotificationShelfComponent {
      private Provider<NotificationShelf> notificationShelfProvider;

      private Provider<NotificationTapHelper.Factory> factoryProvider;

      private Provider<ExpandableViewController> expandableViewControllerProvider;

      private Provider<ExpandableOutlineViewController> expandableOutlineViewControllerProvider;

      private Provider<ActivatableNotificationViewController> activatableNotificationViewControllerProvider;

      private Provider<NotificationShelfController> notificationShelfControllerProvider;

      private NotificationShelfComponentImpl(NotificationShelf notificationShelfParam) {

        initialize(notificationShelfParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final NotificationShelf notificationShelfParam) {
        this.notificationShelfProvider = InstanceFactory.create(notificationShelfParam);
        this.factoryProvider = NotificationTapHelper_Factory_Factory.create((Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, DaggerGlobalRootComponent.this.provideMainDelayableExecutorProvider);
        this.expandableViewControllerProvider = ExpandableViewController_Factory.create((Provider) notificationShelfProvider);
        this.expandableOutlineViewControllerProvider = ExpandableOutlineViewController_Factory.create((Provider) notificationShelfProvider, expandableViewControllerProvider);
        this.activatableNotificationViewControllerProvider = ActivatableNotificationViewController_Factory.create((Provider) notificationShelfProvider, factoryProvider, expandableOutlineViewControllerProvider, DaggerGlobalRootComponent.this.provideAccessibilityManagerProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.falsingCollectorImplProvider);
        this.notificationShelfControllerProvider = DoubleCheck.provider(NotificationShelfController_Factory.create(notificationShelfProvider, activatableNotificationViewControllerProvider, SysUIComponentImpl.this.keyguardBypassControllerProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider));
      }

      @Override
      public NotificationShelfController getNotificationShelfController() {
        return notificationShelfControllerProvider.get();
      }
    }

    private final class KeyguardQsUserSwitchComponentFactory implements KeyguardQsUserSwitchComponent.Factory {
      @Override
      public KeyguardQsUserSwitchComponent build(FrameLayout userAvatarContainer) {
        Preconditions.checkNotNull(userAvatarContainer);
        return new KeyguardQsUserSwitchComponentImpl(userAvatarContainer);
      }
    }

    private final class KeyguardQsUserSwitchComponentImpl implements KeyguardQsUserSwitchComponent {
      private Provider<FrameLayout> userAvatarContainerProvider;

      private Provider<KeyguardQsUserSwitchController> keyguardQsUserSwitchControllerProvider;

      private KeyguardQsUserSwitchComponentImpl(FrameLayout userAvatarContainerParam) {

        initialize(userAvatarContainerParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final FrameLayout userAvatarContainerParam) {
        this.userAvatarContainerProvider = InstanceFactory.create(userAvatarContainerParam);
        this.keyguardQsUserSwitchControllerProvider = DoubleCheck.provider(KeyguardQsUserSwitchController_Factory.create(userAvatarContainerProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, SysUIComponentImpl.this.userSwitcherControllerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.falsingManagerProxyProvider, SysUIComponentImpl.this.provideConfigurationControllerProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.dozeParametersProvider, SysUIComponentImpl.this.adapterProvider, SysUIComponentImpl.this.unlockedScreenOffAnimationControllerProvider, SysUIComponentImpl.this.featureFlagsProvider, SysUIComponentImpl.this.userSwitchDialogControllerProvider));
      }

      @Override
      public KeyguardQsUserSwitchController getKeyguardQsUserSwitchController() {
        return keyguardQsUserSwitchControllerProvider.get();
      }
    }

    private final class KeyguardUserSwitcherComponentFactory implements KeyguardUserSwitcherComponent.Factory {
      @Override
      public KeyguardUserSwitcherComponent build(
          KeyguardUserSwitcherView keyguardUserSwitcherView) {
        Preconditions.checkNotNull(keyguardUserSwitcherView);
        return new KeyguardUserSwitcherComponentImpl(keyguardUserSwitcherView);
      }
    }

    private final class KeyguardUserSwitcherComponentImpl implements KeyguardUserSwitcherComponent {
      private Provider<KeyguardUserSwitcherView> keyguardUserSwitcherViewProvider;

      private Provider<KeyguardUserSwitcherController> keyguardUserSwitcherControllerProvider;

      private KeyguardUserSwitcherComponentImpl(
          KeyguardUserSwitcherView keyguardUserSwitcherViewParam) {

        initialize(keyguardUserSwitcherViewParam);
      }

      @SuppressWarnings("unchecked")
      private void initialize(final KeyguardUserSwitcherView keyguardUserSwitcherViewParam) {
        this.keyguardUserSwitcherViewProvider = InstanceFactory.create(keyguardUserSwitcherViewParam);
        this.keyguardUserSwitcherControllerProvider = DoubleCheck.provider(KeyguardUserSwitcherController_Factory.create(keyguardUserSwitcherViewProvider, DaggerGlobalRootComponent.this.contextProvider, DaggerGlobalRootComponent.this.provideResourcesProvider, SysUIComponentImpl.this.providerLayoutInflaterProvider, DaggerGlobalRootComponent.this.screenLifecycleProvider, SysUIComponentImpl.this.userSwitcherControllerProvider, (Provider) SysUIComponentImpl.this.keyguardStateControllerImplProvider, (Provider) SysUIComponentImpl.this.statusBarStateControllerImplProvider, SysUIComponentImpl.this.keyguardUpdateMonitorProvider, SysUIComponentImpl.this.dozeParametersProvider, SysUIComponentImpl.this.unlockedScreenOffAnimationControllerProvider));
      }

      @Override
      public KeyguardUserSwitcherController getKeyguardUserSwitcherController() {
        return keyguardUserSwitcherControllerProvider.get();
      }
    }

    private final class KeyguardStatusBarViewComponentFactory implements KeyguardStatusBarViewComponent.Factory {
      @Override
      public KeyguardStatusBarViewComponent build(KeyguardStatusBarView view,
          NotificationPanelViewController.NotificationPanelViewStateProvider notificationPanelViewStateProvider) {
        Preconditions.checkNotNull(view);
        Preconditions.checkNotNull(notificationPanelViewStateProvider);
        return new KeyguardStatusBarViewComponentImpl(view, notificationPanelViewStateProvider);
      }
    }

    private final class KeyguardStatusBarViewComponentImpl implements KeyguardStatusBarViewComponent {
      private final KeyguardStatusBarView view;

      private final NotificationPanelViewController.NotificationPanelViewStateProvider notificationPanelViewStateProvider;

      private Provider<KeyguardStatusBarView> viewProvider;

      private Provider<CarrierText> getCarrierTextProvider;

      private Provider<BatteryMeterView> getBatteryMeterViewProvider;

      private KeyguardStatusBarViewComponentImpl(KeyguardStatusBarView viewParam,
          NotificationPanelViewController.NotificationPanelViewStateProvider notificationPanelViewStateProviderParam) {
        this.view = viewParam;
        this.notificationPanelViewStateProvider = notificationPanelViewStateProviderParam;
        initialize(viewParam, notificationPanelViewStateProviderParam);
      }

      private CarrierTextManager.Builder carrierTextManagerBuilder() {
        return new CarrierTextManager.Builder(DaggerGlobalRootComponent.this.context, DaggerGlobalRootComponent.this.mainResources(), DaggerGlobalRootComponent.this.provideWifiManagerProvider.get(), DaggerGlobalRootComponent.this.provideTelephonyManagerProvider.get(), SysUIComponentImpl.this.telephonyListenerManagerProvider.get(), SysUIComponentImpl.this.wakefulnessLifecycleProvider.get(), DaggerGlobalRootComponent.this.provideMainExecutorProvider.get(), SysUIComponentImpl.this.provideBackgroundExecutorProvider.get(), SysUIComponentImpl.this.keyguardUpdateMonitorProvider.get());
      }

      private CarrierTextController carrierTextController() {
        return new CarrierTextController(getCarrierTextProvider.get(), carrierTextManagerBuilder(), SysUIComponentImpl.this.keyguardUpdateMonitorProvider.get());
      }

      private BatteryMeterViewController batteryMeterViewController() {
        return new BatteryMeterViewController(getBatteryMeterViewProvider.get(), SysUIComponentImpl.this.provideConfigurationControllerProvider.get(), SysUIComponentImpl.this.tunerServiceImplProvider.get(), SysUIComponentImpl.this.providesBroadcastDispatcherProvider.get(), DaggerGlobalRootComponent.this.mainHandler(), DaggerGlobalRootComponent.this.provideContentResolverProvider.get(), SysUIComponentImpl.this.provideBatteryControllerProvider.get());
      }

      @SuppressWarnings("unchecked")
      private void initialize(final KeyguardStatusBarView viewParam,
          final NotificationPanelViewController.NotificationPanelViewStateProvider notificationPanelViewStateProviderParam) {
        this.viewProvider = InstanceFactory.create(viewParam);
        this.getCarrierTextProvider = DoubleCheck.provider(KeyguardStatusBarViewModule_GetCarrierTextFactory.create(viewProvider));
        this.getBatteryMeterViewProvider = DoubleCheck.provider(KeyguardStatusBarViewModule_GetBatteryMeterViewFactory.create(viewProvider));
      }

      @Override
      public KeyguardStatusBarViewController getKeyguardStatusBarViewController() {
        return new KeyguardStatusBarViewController(view, carrierTextController(), SysUIComponentImpl.this.provideConfigurationControllerProvider.get(), SysUIComponentImpl.this.systemStatusAnimationSchedulerProvider.get(), SysUIComponentImpl.this.provideBatteryControllerProvider.get(), SysUIComponentImpl.this.userInfoControllerImplProvider.get(), SysUIComponentImpl.this.statusBarIconControllerImplProvider.get(), SysUIComponentImpl.this.factoryProvider9.get(), batteryMeterViewController(), notificationPanelViewStateProvider, SysUIComponentImpl.this.keyguardStateControllerImplProvider.get(), SysUIComponentImpl.this.keyguardBypassControllerProvider.get(), SysUIComponentImpl.this.keyguardUpdateMonitorProvider.get(), SysUIComponentImpl.this.biometricUnlockControllerProvider.get(), SysUIComponentImpl.this.statusBarStateControllerImplProvider.get(), SysUIComponentImpl.this.statusBarContentInsetsProvider.get());
      }
    }
  }
}
