package com.android.systemui.statusbar.notification.collection;

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
public final class TargetSdkResolver_Factory implements Factory<TargetSdkResolver> {
  private final Provider<Context> contextProvider;

  public TargetSdkResolver_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public TargetSdkResolver get() {
    return newInstance(contextProvider.get());
  }

  public static TargetSdkResolver_Factory create(Provider<Context> contextProvider) {
    return new TargetSdkResolver_Factory(contextProvider);
  }

  public static TargetSdkResolver newInstance(Context context) {
    return new TargetSdkResolver(context);
  }
}
