package com.android.systemui.qs;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.media.MediaHost;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.plugins.statusbar.StatusBarStateController;
import com.android.systemui.qs.dagger.QSFragmentComponent;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.phone.KeyguardBypassController;
import com.android.systemui.statusbar.policy.RemoteInputQuickSettingsDisabler;
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
public final class QSFragment_Factory implements Factory<QSFragment> {
  private final Provider<RemoteInputQuickSettingsDisabler> remoteInputQsDisablerProvider;

  private final Provider<QSTileHost> qsTileHostProvider;

  private final Provider<StatusBarStateController> statusBarStateControllerProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<QSDetailDisplayer> qsDetailDisplayerProvider;

  private final Provider<MediaHost> qsMediaHostProvider;

  private final Provider<MediaHost> qqsMediaHostProvider;

  private final Provider<KeyguardBypassController> keyguardBypassControllerProvider;

  private final Provider<QSFragmentComponent.Factory> qsComponentFactoryProvider;

  private final Provider<QSFragmentDisableFlagsLogger> qsFragmentDisableFlagsLoggerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public QSFragment_Factory(
      Provider<RemoteInputQuickSettingsDisabler> remoteInputQsDisablerProvider,
      Provider<QSTileHost> qsTileHostProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<QSDetailDisplayer> qsDetailDisplayerProvider,
      Provider<MediaHost> qsMediaHostProvider, Provider<MediaHost> qqsMediaHostProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<QSFragmentComponent.Factory> qsComponentFactoryProvider,
      Provider<QSFragmentDisableFlagsLogger> qsFragmentDisableFlagsLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    this.remoteInputQsDisablerProvider = remoteInputQsDisablerProvider;
    this.qsTileHostProvider = qsTileHostProvider;
    this.statusBarStateControllerProvider = statusBarStateControllerProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.qsDetailDisplayerProvider = qsDetailDisplayerProvider;
    this.qsMediaHostProvider = qsMediaHostProvider;
    this.qqsMediaHostProvider = qqsMediaHostProvider;
    this.keyguardBypassControllerProvider = keyguardBypassControllerProvider;
    this.qsComponentFactoryProvider = qsComponentFactoryProvider;
    this.qsFragmentDisableFlagsLoggerProvider = qsFragmentDisableFlagsLoggerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public QSFragment get() {
    return newInstance(remoteInputQsDisablerProvider.get(), qsTileHostProvider.get(), statusBarStateControllerProvider.get(), commandQueueProvider.get(), qsDetailDisplayerProvider.get(), qsMediaHostProvider.get(), qqsMediaHostProvider.get(), keyguardBypassControllerProvider.get(), qsComponentFactoryProvider.get(), qsFragmentDisableFlagsLoggerProvider.get(), falsingManagerProvider.get(), dumpManagerProvider.get());
  }

  public static QSFragment_Factory create(
      Provider<RemoteInputQuickSettingsDisabler> remoteInputQsDisablerProvider,
      Provider<QSTileHost> qsTileHostProvider,
      Provider<StatusBarStateController> statusBarStateControllerProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<QSDetailDisplayer> qsDetailDisplayerProvider,
      Provider<MediaHost> qsMediaHostProvider, Provider<MediaHost> qqsMediaHostProvider,
      Provider<KeyguardBypassController> keyguardBypassControllerProvider,
      Provider<QSFragmentComponent.Factory> qsComponentFactoryProvider,
      Provider<QSFragmentDisableFlagsLogger> qsFragmentDisableFlagsLoggerProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<DumpManager> dumpManagerProvider) {
    return new QSFragment_Factory(remoteInputQsDisablerProvider, qsTileHostProvider, statusBarStateControllerProvider, commandQueueProvider, qsDetailDisplayerProvider, qsMediaHostProvider, qqsMediaHostProvider, keyguardBypassControllerProvider, qsComponentFactoryProvider, qsFragmentDisableFlagsLoggerProvider, falsingManagerProvider, dumpManagerProvider);
  }

  public static QSFragment newInstance(RemoteInputQuickSettingsDisabler remoteInputQsDisabler,
      QSTileHost qsTileHost, StatusBarStateController statusBarStateController,
      CommandQueue commandQueue, QSDetailDisplayer qsDetailDisplayer, MediaHost qsMediaHost,
      MediaHost qqsMediaHost, KeyguardBypassController keyguardBypassController,
      QSFragmentComponent.Factory qsComponentFactory,
      QSFragmentDisableFlagsLogger qsFragmentDisableFlagsLogger, FalsingManager falsingManager,
      DumpManager dumpManager) {
    return new QSFragment(remoteInputQsDisabler, qsTileHost, statusBarStateController, commandQueue, qsDetailDisplayer, qsMediaHost, qqsMediaHost, keyguardBypassController, qsComponentFactory, qsFragmentDisableFlagsLogger, falsingManager, dumpManager);
  }
}
