package com.android.systemui.statusbar.notification.collection.coordinator;

import com.android.systemui.media.MediaFeatureFlag;
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
public final class MediaCoordinator_Factory implements Factory<MediaCoordinator> {
  private final Provider<MediaFeatureFlag> featureFlagProvider;

  public MediaCoordinator_Factory(Provider<MediaFeatureFlag> featureFlagProvider) {
    this.featureFlagProvider = featureFlagProvider;
  }

  @Override
  public MediaCoordinator get() {
    return newInstance(featureFlagProvider.get());
  }

  public static MediaCoordinator_Factory create(Provider<MediaFeatureFlag> featureFlagProvider) {
    return new MediaCoordinator_Factory(featureFlagProvider);
  }

  public static MediaCoordinator newInstance(MediaFeatureFlag featureFlag) {
    return new MediaCoordinator(featureFlag);
  }
}
