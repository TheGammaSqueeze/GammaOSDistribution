package com.android.systemui.qs.external;

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
public final class CustomTileStatePersister_Factory implements Factory<CustomTileStatePersister> {
  private final Provider<Context> contextProvider;

  public CustomTileStatePersister_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public CustomTileStatePersister get() {
    return newInstance(contextProvider.get());
  }

  public static CustomTileStatePersister_Factory create(Provider<Context> contextProvider) {
    return new CustomTileStatePersister_Factory(contextProvider);
  }

  public static CustomTileStatePersister newInstance(Context context) {
    return new CustomTileStatePersister(context);
  }
}
