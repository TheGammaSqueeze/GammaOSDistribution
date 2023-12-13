package com.android.systemui.statusbar.notification.row;

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
public final class RowInflaterTask_Factory implements Factory<RowInflaterTask> {
  @Override
  public RowInflaterTask get() {
    return newInstance();
  }

  public static RowInflaterTask_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static RowInflaterTask newInstance() {
    return new RowInflaterTask();
  }

  private static final class InstanceHolder {
    private static final RowInflaterTask_Factory INSTANCE = new RowInflaterTask_Factory();
  }
}
