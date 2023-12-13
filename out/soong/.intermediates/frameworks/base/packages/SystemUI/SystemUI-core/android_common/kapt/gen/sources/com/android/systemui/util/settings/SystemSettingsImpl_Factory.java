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
public final class SystemSettingsImpl_Factory implements Factory<SystemSettingsImpl> {
  private final Provider<ContentResolver> contentResolverProvider;

  public SystemSettingsImpl_Factory(Provider<ContentResolver> contentResolverProvider) {
    this.contentResolverProvider = contentResolverProvider;
  }

  @Override
  public SystemSettingsImpl get() {
    return newInstance(contentResolverProvider.get());
  }

  public static SystemSettingsImpl_Factory create(
      Provider<ContentResolver> contentResolverProvider) {
    return new SystemSettingsImpl_Factory(contentResolverProvider);
  }

  public static SystemSettingsImpl newInstance(ContentResolver contentResolver) {
    return new SystemSettingsImpl(contentResolver);
  }
}
