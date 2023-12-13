package com.android.systemui.media.dialog;

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
public final class MediaOutputDialogReceiver_Factory implements Factory<MediaOutputDialogReceiver> {
  private final Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider;

  public MediaOutputDialogReceiver_Factory(
      Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider) {
    this.mediaOutputDialogFactoryProvider = mediaOutputDialogFactoryProvider;
  }

  @Override
  public MediaOutputDialogReceiver get() {
    return newInstance(mediaOutputDialogFactoryProvider.get());
  }

  public static MediaOutputDialogReceiver_Factory create(
      Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider) {
    return new MediaOutputDialogReceiver_Factory(mediaOutputDialogFactoryProvider);
  }

  public static MediaOutputDialogReceiver newInstance(
      MediaOutputDialogFactory mediaOutputDialogFactory) {
    return new MediaOutputDialogReceiver(mediaOutputDialogFactory);
  }
}
