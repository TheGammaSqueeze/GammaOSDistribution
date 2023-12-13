package com.android.systemui.power;

import android.content.Context;
import com.android.systemui.plugins.ActivityStarter;
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
public final class PowerNotificationWarnings_Factory implements Factory<PowerNotificationWarnings> {
  private final Provider<Context> contextProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  public PowerNotificationWarnings_Factory(Provider<Context> contextProvider,
      Provider<ActivityStarter> activityStarterProvider) {
    this.contextProvider = contextProvider;
    this.activityStarterProvider = activityStarterProvider;
  }

  @Override
  public PowerNotificationWarnings get() {
    return newInstance(contextProvider.get(), activityStarterProvider.get());
  }

  public static PowerNotificationWarnings_Factory create(Provider<Context> contextProvider,
      Provider<ActivityStarter> activityStarterProvider) {
    return new PowerNotificationWarnings_Factory(contextProvider, activityStarterProvider);
  }

  public static PowerNotificationWarnings newInstance(Context context,
      ActivityStarter activityStarter) {
    return new PowerNotificationWarnings(context, activityStarter);
  }
}
