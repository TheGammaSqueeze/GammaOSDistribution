package com.android.systemui.media;

import android.content.Context;
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
public final class MediaFeatureFlag_Factory implements Factory<MediaFeatureFlag> {
  private final Provider<Context> contextProvider;

  public MediaFeatureFlag_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public MediaFeatureFlag get() {
    return newInstance(contextProvider.get());
  }

  public static MediaFeatureFlag_Factory create(Provider<Context> contextProvider) {
    return new MediaFeatureFlag_Factory(contextProvider);
  }

  public static MediaFeatureFlag newInstance(Context context) {
    return new MediaFeatureFlag(context);
  }
}
