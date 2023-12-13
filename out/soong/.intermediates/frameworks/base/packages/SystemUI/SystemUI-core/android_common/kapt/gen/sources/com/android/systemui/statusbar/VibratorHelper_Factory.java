package com.android.systemui.statusbar;

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
public final class VibratorHelper_Factory implements Factory<VibratorHelper> {
  private final Provider<Context> contextProvider;

  public VibratorHelper_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public VibratorHelper get() {
    return newInstance(contextProvider.get());
  }

  public static VibratorHelper_Factory create(Provider<Context> contextProvider) {
    return new VibratorHelper_Factory(contextProvider);
  }

  public static VibratorHelper newInstance(Context context) {
    return new VibratorHelper(context);
  }
}
