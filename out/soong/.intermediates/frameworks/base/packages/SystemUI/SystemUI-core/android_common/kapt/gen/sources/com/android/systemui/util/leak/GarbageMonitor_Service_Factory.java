package com.android.systemui.util.leak;

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
public final class GarbageMonitor_Service_Factory implements Factory<GarbageMonitor.Service> {
  private final Provider<Context> contextProvider;

  private final Provider<GarbageMonitor> garbageMonitorProvider;

  public GarbageMonitor_Service_Factory(Provider<Context> contextProvider,
      Provider<GarbageMonitor> garbageMonitorProvider) {
    this.contextProvider = contextProvider;
    this.garbageMonitorProvider = garbageMonitorProvider;
  }

  @Override
  public GarbageMonitor.Service get() {
    return newInstance(contextProvider.get(), garbageMonitorProvider.get());
  }

  public static GarbageMonitor_Service_Factory create(Provider<Context> contextProvider,
      Provider<GarbageMonitor> garbageMonitorProvider) {
    return new GarbageMonitor_Service_Factory(contextProvider, garbageMonitorProvider);
  }

  public static GarbageMonitor.Service newInstance(Context context, GarbageMonitor garbageMonitor) {
    return new GarbageMonitor.Service(context, garbageMonitor);
  }
}
