package com.android.systemui.demomode.dagger;

import android.content.Context;
import com.android.systemui.demomode.DemoModeController;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.settings.GlobalSettings;
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
public final class DemoModeModule_ProvideDemoModeControllerFactory implements Factory<DemoModeController> {
  private final Provider<Context> contextProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<GlobalSettings> globalSettingsProvider;

  public DemoModeModule_ProvideDemoModeControllerFactory(Provider<Context> contextProvider,
      Provider<DumpManager> dumpManagerProvider, Provider<GlobalSettings> globalSettingsProvider) {
    this.contextProvider = contextProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.globalSettingsProvider = globalSettingsProvider;
  }

  @Override
  public DemoModeController get() {
    return provideDemoModeController(contextProvider.get(), dumpManagerProvider.get(), globalSettingsProvider.get());
  }

  public static DemoModeModule_ProvideDemoModeControllerFactory create(
      Provider<Context> contextProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<GlobalSettings> globalSettingsProvider) {
    return new DemoModeModule_ProvideDemoModeControllerFactory(contextProvider, dumpManagerProvider, globalSettingsProvider);
  }

  public static DemoModeController provideDemoModeController(Context context,
      DumpManager dumpManager, GlobalSettings globalSettings) {
    return Preconditions.checkNotNullFromProvides(DemoModeModule.provideDemoModeController(context, dumpManager, globalSettings));
  }
}
