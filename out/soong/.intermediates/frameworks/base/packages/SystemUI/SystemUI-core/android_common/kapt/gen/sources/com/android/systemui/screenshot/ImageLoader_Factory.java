package com.android.systemui.screenshot;

import android.content.ContentResolver;
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
public final class ImageLoader_Factory implements Factory<ImageLoader> {
  private final Provider<ContentResolver> resolverProvider;

  public ImageLoader_Factory(Provider<ContentResolver> resolverProvider) {
    this.resolverProvider = resolverProvider;
  }

  @Override
  public ImageLoader get() {
    return newInstance(resolverProvider.get());
  }

  public static ImageLoader_Factory create(Provider<ContentResolver> resolverProvider) {
    return new ImageLoader_Factory(resolverProvider);
  }

  public static ImageLoader newInstance(ContentResolver resolver) {
    return new ImageLoader(resolver);
  }
}
