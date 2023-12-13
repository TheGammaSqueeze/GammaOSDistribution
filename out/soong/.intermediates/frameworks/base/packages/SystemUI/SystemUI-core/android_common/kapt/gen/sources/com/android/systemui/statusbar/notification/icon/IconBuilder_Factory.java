package com.android.systemui.statusbar.notification.icon;

import android.content.Context;
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
public final class IconBuilder_Factory implements Factory<IconBuilder> {
  private final Provider<Context> contextProvider;

  public IconBuilder_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public IconBuilder get() {
    return newInstance(contextProvider.get());
  }

  public static IconBuilder_Factory create(Provider<Context> contextProvider) {
    return new IconBuilder_Factory(contextProvider);
  }

  public static IconBuilder newInstance(Context context) {
    return new IconBuilder(context);
  }
}
