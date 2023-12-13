package com.android.systemui.dagger;

import com.android.internal.jank.InteractionJankMonitor;
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
public final class FrameworkServicesModule_ProvideInteractionJankMonitorFactory implements Factory<InteractionJankMonitor> {
  @Override
  public InteractionJankMonitor get() {
    return provideInteractionJankMonitor();
  }

  public static FrameworkServicesModule_ProvideInteractionJankMonitorFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static InteractionJankMonitor provideInteractionJankMonitor() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideInteractionJankMonitor());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideInteractionJankMonitorFactory INSTANCE = new FrameworkServicesModule_ProvideInteractionJankMonitorFactory();
  }
}
