package com.android.systemui.qs.dagger;

import com.android.systemui.flags.FeatureFlags;
import com.android.systemui.util.settings.GlobalSettings;
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
public final class QSFlagsModule_IsPMLiteEnabledFactory implements Factory<Boolean> {
  private final Provider<FeatureFlags> featureFlagsProvider;

  private final Provider<GlobalSettings> globalSettingsProvider;

  public QSFlagsModule_IsPMLiteEnabledFactory(Provider<FeatureFlags> featureFlagsProvider,
      Provider<GlobalSettings> globalSettingsProvider) {
    this.featureFlagsProvider = featureFlagsProvider;
    this.globalSettingsProvider = globalSettingsProvider;
  }

  @Override
  public Boolean get() {
    return isPMLiteEnabled(featureFlagsProvider.get(), globalSettingsProvider.get());
  }

  public static QSFlagsModule_IsPMLiteEnabledFactory create(
      Provider<FeatureFlags> featureFlagsProvider,
      Provider<GlobalSettings> globalSettingsProvider) {
    return new QSFlagsModule_IsPMLiteEnabledFactory(featureFlagsProvider, globalSettingsProvider);
  }

  public static boolean isPMLiteEnabled(FeatureFlags featureFlags, GlobalSettings globalSettings) {
    return QSFlagsModule.isPMLiteEnabled(featureFlags, globalSettings);
  }
}
