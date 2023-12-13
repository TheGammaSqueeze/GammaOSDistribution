package com.android.systemui.dagger;

import android.view.CrossWindowBlurListeners;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class FrameworkServicesModule_ProvideCrossWindowBlurListenersFactory implements Factory<CrossWindowBlurListeners> {
  @Override
  public CrossWindowBlurListeners get() {
    return provideCrossWindowBlurListeners();
  }

  public static FrameworkServicesModule_ProvideCrossWindowBlurListenersFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static CrossWindowBlurListeners provideCrossWindowBlurListeners() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideCrossWindowBlurListeners());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideCrossWindowBlurListenersFactory INSTANCE = new FrameworkServicesModule_ProvideCrossWindowBlurListenersFactory();
  }
}
