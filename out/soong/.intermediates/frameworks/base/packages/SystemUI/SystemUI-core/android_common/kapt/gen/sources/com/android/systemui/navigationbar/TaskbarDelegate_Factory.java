package com.android.systemui.navigationbar;

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
public final class TaskbarDelegate_Factory implements Factory<TaskbarDelegate> {
  private final Provider<Context> contextProvider;

  public TaskbarDelegate_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public TaskbarDelegate get() {
    return newInstance(contextProvider.get());
  }

  public static TaskbarDelegate_Factory create(Provider<Context> contextProvider) {
    return new TaskbarDelegate_Factory(contextProvider);
  }

  public static TaskbarDelegate newInstance(Context context) {
    return new TaskbarDelegate(context);
  }
}
