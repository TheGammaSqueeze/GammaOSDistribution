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
public final class ImageExporter_Factory implements Factory<ImageExporter> {
  private final Provider<ContentResolver> resolverProvider;

  public ImageExporter_Factory(Provider<ContentResolver> resolverProvider) {
    this.resolverProvider = resolverProvider;
  }

  @Override
  public ImageExporter get() {
    return newInstance(resolverProvider.get());
  }

  public static ImageExporter_Factory create(Provider<ContentResolver> resolverProvider) {
    return new ImageExporter_Factory(resolverProvider);
  }

  public static ImageExporter newInstance(ContentResolver resolver) {
    return new ImageExporter(resolver);
  }
}
