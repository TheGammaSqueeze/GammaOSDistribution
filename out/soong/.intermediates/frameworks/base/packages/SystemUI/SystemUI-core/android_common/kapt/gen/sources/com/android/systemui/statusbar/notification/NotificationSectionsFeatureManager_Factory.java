package com.android.systemui.statusbar.notification;

import android.content.Context;
import com.android.systemui.util.DeviceConfigProxy;
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
public final class NotificationSectionsFeatureManager_Factory implements Factory<NotificationSectionsFeatureManager> {
  private final Provider<DeviceConfigProxy> proxyProvider;

  private final Provider<Context> contextProvider;

  public NotificationSectionsFeatureManager_Factory(Provider<DeviceConfigProxy> proxyProvider,
      Provider<Context> contextProvider) {
    this.proxyProvider = proxyProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public NotificationSectionsFeatureManager get() {
    return newInstance(proxyProvider.get(), contextProvider.get());
  }

  public static NotificationSectionsFeatureManager_Factory create(
      Provider<DeviceConfigProxy> proxyProvider, Provider<Context> contextProvider) {
    return new NotificationSectionsFeatureManager_Factory(proxyProvider, contextProvider);
  }

  public static NotificationSectionsFeatureManager newInstance(DeviceConfigProxy proxy,
      Context context) {
    return new NotificationSectionsFeatureManager(proxy, context);
  }
}
