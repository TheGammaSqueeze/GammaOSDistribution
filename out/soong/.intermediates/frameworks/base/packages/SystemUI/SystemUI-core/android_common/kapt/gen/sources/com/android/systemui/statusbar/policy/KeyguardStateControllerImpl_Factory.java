package com.android.systemui.statusbar.policy;

import android.content.Context;
import com.android.internal.widget.LockPatternUtils;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
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
public final class KeyguardStateControllerImpl_Factory implements Factory<KeyguardStateControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<LockPatternUtils> lockPatternUtilsProvider;

  private final Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public KeyguardStateControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.lockPatternUtilsProvider = lockPatternUtilsProvider;
    this.smartspaceTransitionControllerProvider = smartspaceTransitionControllerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public KeyguardStateControllerImpl get() {
    return newInstance(contextProvider.get(), keyguardUpdateMonitorProvider.get(), lockPatternUtilsProvider.get(), smartspaceTransitionControllerProvider.get(), dumpManagerProvider.get());
  }

  public static KeyguardStateControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<LockPatternUtils> lockPatternUtilsProvider,
      Provider<SmartspaceTransitionController> smartspaceTransitionControllerProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new KeyguardStateControllerImpl_Factory(contextProvider, keyguardUpdateMonitorProvider, lockPatternUtilsProvider, smartspaceTransitionControllerProvider, dumpManagerProvider);
  }

  public static KeyguardStateControllerImpl newInstance(Context context,
      KeyguardUpdateMonitor keyguardUpdateMonitor, LockPatternUtils lockPatternUtils,
      SmartspaceTransitionController smartspaceTransitionController, DumpManager dumpManager) {
    return new KeyguardStateControllerImpl(context, keyguardUpdateMonitor, lockPatternUtils, smartspaceTransitionController, dumpManager);
  }
}
