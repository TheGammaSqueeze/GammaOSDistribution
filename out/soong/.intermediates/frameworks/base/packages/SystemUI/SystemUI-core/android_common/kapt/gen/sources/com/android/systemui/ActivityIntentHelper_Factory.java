package com.android.systemui;

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
public final class ActivityIntentHelper_Factory implements Factory<ActivityIntentHelper> {
  private final Provider<Context> contextProvider;

  public ActivityIntentHelper_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ActivityIntentHelper get() {
    return newInstance(contextProvider.get());
  }

  public static ActivityIntentHelper_Factory create(Provider<Context> contextProvider) {
    return new ActivityIntentHelper_Factory(contextProvider);
  }

  public static ActivityIntentHelper newInstance(Context context) {
    return new ActivityIntentHelper(context);
  }
}
