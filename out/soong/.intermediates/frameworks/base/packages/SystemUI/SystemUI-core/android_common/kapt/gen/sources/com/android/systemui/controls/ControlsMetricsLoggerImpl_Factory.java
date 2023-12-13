package com.android.systemui.controls;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ControlsMetricsLoggerImpl_Factory implements Factory<ControlsMetricsLoggerImpl> {
  @Override
  public ControlsMetricsLoggerImpl get() {
    return newInstance();
  }

  public static ControlsMetricsLoggerImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ControlsMetricsLoggerImpl newInstance() {
    return new ControlsMetricsLoggerImpl();
  }

  private static final class InstanceHolder {
    private static final ControlsMetricsLoggerImpl_Factory INSTANCE = new ControlsMetricsLoggerImpl_Factory();
  }
}
