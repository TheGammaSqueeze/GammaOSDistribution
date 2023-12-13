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
public final class MediaHostStatesManager_Factory implements Factory<MediaHostStatesManager> {
  @Override
  public MediaHostStatesManager get() {
    return newInstance();
  }

  public static MediaHostStatesManager_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static MediaHostStatesManager newInstance() {
    return new MediaHostStatesManager();
  }

  private static final class InstanceHolder {
    private static final MediaHostStatesManager_Factory INSTANCE = new MediaHostStatesManager_Factory();
  }
}
