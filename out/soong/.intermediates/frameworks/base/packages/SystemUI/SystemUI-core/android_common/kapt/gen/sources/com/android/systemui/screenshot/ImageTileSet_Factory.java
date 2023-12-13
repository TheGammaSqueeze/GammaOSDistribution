package com.android.systemui.screenshot;

import android.os.Handler;
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
public final class ImageTileSet_Factory implements Factory<ImageTileSet> {
  private final Provider<Handler> handlerProvider;

  public ImageTileSet_Factory(Provider<Handler> handlerProvider) {
    this.handlerProvider = handlerProvider;
  }

  @Override
  public ImageTileSet get() {
    return newInstance(handlerProvider.get());
  }

  public static ImageTileSet_Factory create(Provider<Handler> handlerProvider) {
    return new ImageTileSet_Factory(handlerProvider);
  }

  public static ImageTileSet newInstance(Handler handler) {
    return new ImageTileSet(handler);
  }
}
