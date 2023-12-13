package com.android.systemui.keyguard;

import android.app.AlarmManager;
import android.content.ContentResolver;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.statusbar.NotificationMediaManager;
import com.android.systemui.statusbar.phone.DozeParameters;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.NextAlarmController;
import com.android.systemui.statusbar.policy.ZenModeController;
import dagger.MembersInjector;
import dagger.internal.InjectedFieldSignature;
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
public final class KeyguardSliceProvider_MembersInjector implements MembersInjector<KeyguardSliceProvider> {
  private final Provider<DozeParameters> mDozeParametersProvider;

  private final Provider<ZenModeController> mZenModeControllerProvider;

  private final Provider<NextAlarmController> mNextAlarmControllerProvider;

  private final Provider<AlarmManager> mAlarmManagerProvider;

  private final Provider<ContentResolver> mContentResolverProvider;

  private final Provider<NotificationMediaManager> mMediaManagerProvider;

  private final Provider<StatusBarStateController> mStatusBarStateControllerProvider;

  private final Provider<KeyguardBypassController> mKeyguardBypassControllerProvider;

  public KeyguardSliceProvider_MembersInjector(Provider<DozeParameters> mDozeParametersProvider,
      Provider<ZenModeController> mZenModeControllerProvider,
      Provider<NextAlarmController> mNextAlarmControllerProvider,
      Provider<AlarmManager> mAlarmManagerProvider,
      Provider<ContentResolver> mContentResolverProvider,
      Provider<NotificationMediaManager> mMediaManagerProvider,
      Provider<StatusBarStateController> mStatusBarStateControllerProvider,
      Provider<KeyguardBypassController> mKeyguardBypassControllerProvider) {
    this.mDozeParametersProvider = mDozeParametersProvider;
    this.mZenModeControllerProvider = mZenModeControllerProvider;
    this.mNextAlarmControllerProvider = mNextAlarmControllerProvider;
    this.mAlarmManagerProvider = mAlarmManagerProvider;
    this.mContentResolverProvider = mContentResolverProvider;
    this.mMediaManagerProvider = mMediaManagerProvider;
    this.mStatusBarStateControllerProvider = mStatusBarStateControllerProvider;
    this.mKeyguardBypassControllerProvider = mKeyguardBypassControllerProvider;
  }

  public static MembersInjector<KeyguardSliceProvider> create(
      Provider<DozeParameters> mDozeParametersProvider,
      Provider<ZenModeController> mZenModeControllerProvider,
      Provider<NextAlarmController> mNextAlarmControllerProvider,
      Provider<AlarmManager> mAlarmManagerProvider,
      Provider<ContentResolver> mContentResolverProvider,
      Provider<NotificationMediaManager> mMediaManagerProvider,
      Provider<StatusBarStateController> mStatusBarStateControllerProvider,
      Provider<KeyguardBypassController> mKeyguardBypassControllerProvider) {
    return new KeyguardSliceProvider_MembersInjector(mDozeParametersProvider, mZenModeControllerProvider, mNextAlarmControllerProvider, mAlarmManagerProvider, mContentResolverProvider, mMediaManagerProvider, mStatusBarStateControllerProvider, mKeyguardBypassControllerProvider);
  }

  @Override
  public void injectMembers(KeyguardSliceProvider instance) {
    injectMDozeParameters(instance, mDozeParametersProvider.get());
    injectMZenModeController(instance, mZenModeControllerProvider.get());
    injectMNextAlarmController(instance, mNextAlarmControllerProvider.get());
    injectMAlarmManager(instance, mAlarmManagerProvider.get());
    injectMContentResolver(instance, mContentResolverProvider.get());
    injectMMediaManager(instance, mMediaManagerProvider.get());
    injectMStatusBarStateController(instance, mStatusBarStateControllerProvider.get());
    injectMKeyguardBypassController(instance, mKeyguardBypassControllerProvider.get());
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mDozeParameters")
  public static void injectMDozeParameters(KeyguardSliceProvider instance,
      DozeParameters mDozeParameters) {
    instance.mDozeParameters = mDozeParameters;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mZenModeController")
  public static void injectMZenModeController(KeyguardSliceProvider instance,
      ZenModeController mZenModeController) {
    instance.mZenModeController = mZenModeController;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mNextAlarmController")
  public static void injectMNextAlarmController(KeyguardSliceProvider instance,
      NextAlarmController mNextAlarmController) {
    instance.mNextAlarmController = mNextAlarmController;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mAlarmManager")
  public static void injectMAlarmManager(KeyguardSliceProvider instance,
      AlarmManager mAlarmManager) {
    instance.mAlarmManager = mAlarmManager;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mContentResolver")
  public static void injectMContentResolver(KeyguardSliceProvider instance,
      ContentResolver mContentResolver) {
    instance.mContentResolver = mContentResolver;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mMediaManager")
  public static void injectMMediaManager(KeyguardSliceProvider instance,
      NotificationMediaManager mMediaManager) {
    instance.mMediaManager = mMediaManager;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mStatusBarStateController")
  public static void injectMStatusBarStateController(KeyguardSliceProvider instance,
      StatusBarStateController mStatusBarStateController) {
    instance.mStatusBarStateController = mStatusBarStateController;
  }

  @InjectedFieldSignature("com.android.systemui.keyguard.KeyguardSliceProvider.mKeyguardBypassController")
  public static void injectMKeyguardBypassController(KeyguardSliceProvider instance,
      KeyguardBypassController mKeyguardBypassController) {
    instance.mKeyguardBypassController = mKeyguardBypassController;
  }
}
