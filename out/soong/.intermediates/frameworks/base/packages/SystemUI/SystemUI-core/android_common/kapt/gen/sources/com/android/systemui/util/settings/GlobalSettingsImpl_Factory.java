package com.android.systemui.util.settings;

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
public final class GlobalSettingsImpl_Factory implements Factory<GlobalSettingsImpl> {
  private final Provider<ContentResolver> contentResolverProvider;

  public GlobalSettingsImpl_Factory(Provider<ContentResolver> contentResolverProvider) {
    this.contentResolverProvider = contentResolverProvider;
  }

  @Override
  public GlobalSettingsImpl get() {
    return newInstance(contentResolverProvider.get());
  }

  public static GlobalSettingsImpl_Factory create(
      Provider<ContentResolver> contentResolverProvider) {
    return new GlobalSettingsImpl_Factory(contentResolverProvider);
  }

  public static GlobalSettingsImpl newInstance(ContentResolver contentResolver) {
    return new GlobalSettingsImpl(contentResolver);
  }
}
