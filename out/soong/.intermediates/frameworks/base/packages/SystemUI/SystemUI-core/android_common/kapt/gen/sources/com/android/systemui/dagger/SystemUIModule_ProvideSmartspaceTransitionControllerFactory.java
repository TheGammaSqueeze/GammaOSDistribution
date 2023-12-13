package com.android.systemui.dagger;

import com.android.systemui.shared.system.smartspace.SmartspaceTransitionController;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class SystemUIModule_ProvideSmartspaceTransitionControllerFactory implements Factory<SmartspaceTransitionController> {
  @Override
  public SmartspaceTransitionController get() {
    return provideSmartspaceTransitionController();
  }

  public static SystemUIModule_ProvideSmartspaceTransitionControllerFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static SmartspaceTransitionController provideSmartspaceTransitionController() {
    return Preconditions.checkNotNullFromProvides(SystemUIModule.provideSmartspaceTransitionController());
  }

  private static final class InstanceHolder {
    private static final SystemUIModule_ProvideSmartspaceTransitionControllerFactory INSTANCE = new SystemUIModule_ProvideSmartspaceTransitionControllerFactory();
  }
}
