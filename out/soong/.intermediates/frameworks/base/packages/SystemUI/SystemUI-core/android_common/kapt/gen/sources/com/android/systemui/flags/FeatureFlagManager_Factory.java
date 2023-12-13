package com.android.systemui.flags;

import android.content.Context;
import android.content.res.Resources;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.util.settings.SecureSettings;
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
public final class FeatureFlagManager_Factory implements Factory<FeatureFlagManager> {
  private final Provider<FlagManager> flagManagerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<SecureSettings> secureSettingsProvider;

  private final Provider<Resources> resourcesProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public FeatureFlagManager_Factory(Provider<FlagManager> flagManagerProvider,
      Provider<Context> contextProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<Resources> resourcesProvider, Provider<DumpManager> dumpManagerProvider) {
    this.flagManagerProvider = flagManagerProvider;
    this.contextProvider = contextProvider;
    this.secureSettingsProvider = secureSettingsProvider;
    this.resourcesProvider = resourcesProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public FeatureFlagManager get() {
    return newInstance(flagManagerProvider.get(), contextProvider.get(), secureSettingsProvider.get(), resourcesProvider.get(), dumpManagerProvider.get());
  }

  public static FeatureFlagManager_Factory create(Provider<FlagManager> flagManagerProvider,
      Provider<Context> contextProvider, Provider<SecureSettings> secureSettingsProvider,
      Provider<Resources> resourcesProvider, Provider<DumpManager> dumpManagerProvider) {
    return new FeatureFlagManager_Factory(flagManagerProvider, contextProvider, secureSettingsProvider, resourcesProvider, dumpManagerProvider);
  }

  public static FeatureFlagManager newInstance(FlagManager flagManager, Context context,
      SecureSettings secureSettings, Resources resources, DumpManager dumpManager) {
    return new FeatureFlagManager(flagManager, context, secureSettings, resources, dumpManager);
  }
}
