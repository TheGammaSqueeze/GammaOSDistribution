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
public final class SecureSettingsImpl_Factory implements Factory<SecureSettingsImpl> {
  private final Provider<ContentResolver> contentResolverProvider;

  public SecureSettingsImpl_Factory(Provider<ContentResolver> contentResolverProvider) {
    this.contentResolverProvider = contentResolverProvider;
  }

  @Override
  public SecureSettingsImpl get() {
    return newInstance(contentResolverProvider.get());
  }

  public static SecureSettingsImpl_Factory create(
      Provider<ContentResolver> contentResolverProvider) {
    return new SecureSettingsImpl_Factory(contentResolverProvider);
  }

  public static SecureSettingsImpl newInstance(ContentResolver contentResolver) {
    return new SecureSettingsImpl(contentResolver);
  }
}
