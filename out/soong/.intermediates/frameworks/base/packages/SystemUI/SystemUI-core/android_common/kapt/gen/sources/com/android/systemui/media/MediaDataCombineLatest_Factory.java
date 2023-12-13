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
public final class MediaDataCombineLatest_Factory implements Factory<MediaDataCombineLatest> {
  @Override
  public MediaDataCombineLatest get() {
    return newInstance();
  }

  public static MediaDataCombineLatest_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static MediaDataCombineLatest newInstance() {
    return new MediaDataCombineLatest();
  }

  private static final class InstanceHolder {
    private static final MediaDataCombineLatest_Factory INSTANCE = new MediaDataCombineLatest_Factory();
  }
}
