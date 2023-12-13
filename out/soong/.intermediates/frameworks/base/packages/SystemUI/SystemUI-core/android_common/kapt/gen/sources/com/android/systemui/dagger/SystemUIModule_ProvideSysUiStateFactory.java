package com.android.systemui.dagger;

import com.android.systemui.dump.DumpManager;
import com.android.systemui.model.SysUiState;
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
public final class SystemUIModule_ProvideSysUiStateFactory implements Factory<SysUiState> {
  private final Provider<DumpManager> dumpManagerProvider;

  public SystemUIModule_ProvideSysUiStateFactory(Provider<DumpManager> dumpManagerProvider) {
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public SysUiState get() {
    return provideSysUiState(dumpManagerProvider.get());
  }

  public static SystemUIModule_ProvideSysUiStateFactory create(
      Provider<DumpManager> dumpManagerProvider) {
    return new SystemUIModule_ProvideSysUiStateFactory(dumpManagerProvider);
  }

  public static SysUiState provideSysUiState(DumpManager dumpManager) {
    return Preconditions.checkNotNullFromProvides(SystemUIModule.provideSysUiState(dumpManager));
  }
}
