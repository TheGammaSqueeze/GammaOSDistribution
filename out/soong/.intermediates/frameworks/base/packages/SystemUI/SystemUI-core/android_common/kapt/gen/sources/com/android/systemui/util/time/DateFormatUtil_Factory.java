package com.android.systemui.util.time;

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
public final class DateFormatUtil_Factory implements Factory<DateFormatUtil> {
  private final Provider<Context> contextProvider;

  public DateFormatUtil_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public DateFormatUtil get() {
    return newInstance(contextProvider.get());
  }

  public static DateFormatUtil_Factory create(Provider<Context> contextProvider) {
    return new DateFormatUtil_Factory(contextProvider);
  }

  public static DateFormatUtil newInstance(Context context) {
    return new DateFormatUtil(context);
  }
}
