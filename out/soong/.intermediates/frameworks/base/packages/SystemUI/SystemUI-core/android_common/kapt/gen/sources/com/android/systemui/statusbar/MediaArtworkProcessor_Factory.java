package com.android.systemui.statusbar;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class MediaArtworkProcessor_Factory implements Factory<MediaArtworkProcessor> {
  @Override
  public MediaArtworkProcessor get() {
    return newInstance();
  }

  public static MediaArtworkProcessor_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static MediaArtworkProcessor newInstance() {
    return new MediaArtworkProcessor();
  }

  private static final class InstanceHolder {
    private static final MediaArtworkProcessor_Factory INSTANCE = new MediaArtworkProcessor_Factory();
  }
}
