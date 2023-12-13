package com.android.systemui.qs.dagger;

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
public final class QSFlagsModule_IsReduceBrightColorsAvailableFactory implements Factory<Boolean> {
  private final Provider<Context> contextProvider;

  public QSFlagsModule_IsReduceBrightColorsAvailableFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Boolean get() {
    return isReduceBrightColorsAvailable(contextProvider.get());
  }

  public static QSFlagsModule_IsReduceBrightColorsAvailableFactory create(
      Provider<Context> contextProvider) {
    return new QSFlagsModule_IsReduceBrightColorsAvailableFactory(contextProvider);
  }

  public static boolean isReduceBrightColorsAvailable(Context context) {
    return QSFlagsModule.isReduceBrightColorsAvailable(context);
  }
}
