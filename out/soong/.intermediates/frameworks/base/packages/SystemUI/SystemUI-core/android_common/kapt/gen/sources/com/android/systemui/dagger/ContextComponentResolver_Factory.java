package com.android.systemui.dagger;

import android.app.Activity;
import android.app.Service;
import android.content.BroadcastReceiver;
import com.android.systemui.SystemUI;
import com.android.systemui.recents.RecentsImplementation;
import dagger.internal.Factory;
import java.util.Map;
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
public final class ContextComponentResolver_Factory implements Factory<ContextComponentResolver> {
  private final Provider<Map<Class<?>, Provider<Activity>>> activityCreatorsProvider;

  private final Provider<Map<Class<?>, Provider<Service>>> serviceCreatorsProvider;

  private final Provider<Map<Class<?>, Provider<SystemUI>>> systemUICreatorsProvider;

  private final Provider<Map<Class<?>, Provider<RecentsImplementation>>> recentsCreatorsProvider;

  private final Provider<Map<Class<?>, Provider<BroadcastReceiver>>> broadcastReceiverCreatorsProvider;

  public ContextComponentResolver_Factory(
      Provider<Map<Class<?>, Provider<Activity>>> activityCreatorsProvider,
      Provider<Map<Class<?>, Provider<Service>>> serviceCreatorsProvider,
      Provider<Map<Class<?>, Provider<SystemUI>>> systemUICreatorsProvider,
      Provider<Map<Class<?>, Provider<RecentsImplementation>>> recentsCreatorsProvider,
      Provider<Map<Class<?>, Provider<BroadcastReceiver>>> broadcastReceiverCreatorsProvider) {
    this.activityCreatorsProvider = activityCreatorsProvider;
    this.serviceCreatorsProvider = serviceCreatorsProvider;
    this.systemUICreatorsProvider = systemUICreatorsProvider;
    this.recentsCreatorsProvider = recentsCreatorsProvider;
    this.broadcastReceiverCreatorsProvider = broadcastReceiverCreatorsProvider;
  }

  @Override
  public ContextComponentResolver get() {
    return newInstance(activityCreatorsProvider.get(), serviceCreatorsProvider.get(), systemUICreatorsProvider.get(), recentsCreatorsProvider.get(), broadcastReceiverCreatorsProvider.get());
  }

  public static ContextComponentResolver_Factory create(
      Provider<Map<Class<?>, Provider<Activity>>> activityCreatorsProvider,
      Provider<Map<Class<?>, Provider<Service>>> serviceCreatorsProvider,
      Provider<Map<Class<?>, Provider<SystemUI>>> systemUICreatorsProvider,
      Provider<Map<Class<?>, Provider<RecentsImplementation>>> recentsCreatorsProvider,
      Provider<Map<Class<?>, Provider<BroadcastReceiver>>> broadcastReceiverCreatorsProvider) {
    return new ContextComponentResolver_Factory(activityCreatorsProvider, serviceCreatorsProvider, systemUICreatorsProvider, recentsCreatorsProvider, broadcastReceiverCreatorsProvider);
  }

  public static ContextComponentResolver newInstance(
      Map<Class<?>, Provider<Activity>> activityCreators,
      Map<Class<?>, Provider<Service>> serviceCreators,
      Map<Class<?>, Provider<SystemUI>> systemUICreators,
      Map<Class<?>, Provider<RecentsImplementation>> recentsCreators,
      Map<Class<?>, Provider<BroadcastReceiver>> broadcastReceiverCreators) {
    return new ContextComponentResolver(activityCreators, serviceCreators, systemUICreators, recentsCreators, broadcastReceiverCreators);
  }
}
