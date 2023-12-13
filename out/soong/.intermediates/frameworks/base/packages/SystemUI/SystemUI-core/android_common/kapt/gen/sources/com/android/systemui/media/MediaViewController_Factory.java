package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.statusbar.policy.ConfigurationController;
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
public final class MediaViewController_Factory implements Factory<MediaViewController> {
  private final Provider<Context> contextProvider;

  private final Provider<ConfigurationController> configurationControllerProvider;

  private final Provider<MediaHostStatesManager> mediaHostStatesManagerProvider;

  public MediaViewController_Factory(Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<MediaHostStatesManager> mediaHostStatesManagerProvider) {
    this.contextProvider = contextProvider;
    this.configurationControllerProvider = configurationControllerProvider;
    this.mediaHostStatesManagerProvider = mediaHostStatesManagerProvider;
  }

  @Override
  public MediaViewController get() {
    return newInstance(contextProvider.get(), configurationControllerProvider.get(), mediaHostStatesManagerProvider.get());
  }

  public static MediaViewController_Factory create(Provider<Context> contextProvider,
      Provider<ConfigurationController> configurationControllerProvider,
      Provider<MediaHostStatesManager> mediaHostStatesManagerProvider) {
    return new MediaViewController_Factory(contextProvider, configurationControllerProvider, mediaHostStatesManagerProvider);
  }

  public static MediaViewController newInstance(Context context,
      ConfigurationController configurationController,
      MediaHostStatesManager mediaHostStatesManager) {
    return new MediaViewController(context, configurationController, mediaHostStatesManager);
  }
}
