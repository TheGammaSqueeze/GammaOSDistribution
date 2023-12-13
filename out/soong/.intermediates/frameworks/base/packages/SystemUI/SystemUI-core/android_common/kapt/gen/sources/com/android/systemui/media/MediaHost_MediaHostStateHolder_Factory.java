package com.android.systemui.media;

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
public final class MediaHost_MediaHostStateHolder_Factory implements Factory<MediaHost.MediaHostStateHolder> {
  @Override
  public MediaHost.MediaHostStateHolder get() {
    return newInstance();
  }

  public static MediaHost_MediaHostStateHolder_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static MediaHost.MediaHostStateHolder newInstance() {
    return new MediaHost.MediaHostStateHolder();
  }

  private static final class InstanceHolder {
    private static final MediaHost_MediaHostStateHolder_Factory INSTANCE = new MediaHost_MediaHostStateHolder_Factory();
  }
}
