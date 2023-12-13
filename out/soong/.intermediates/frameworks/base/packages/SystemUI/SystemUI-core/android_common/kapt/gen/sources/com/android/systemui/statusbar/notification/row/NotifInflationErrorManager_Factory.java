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
public final class NotifInflationErrorManager_Factory implements Factory<NotifInflationErrorManager> {
  @Override
  public NotifInflationErrorManager get() {
    return newInstance();
  }

  public static NotifInflationErrorManager_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static NotifInflationErrorManager newInstance() {
    return new NotifInflationErrorManager();
  }

  private static final class InstanceHolder {
    private static final NotifInflationErrorManager_Factory INSTANCE = new NotifInflationErrorManager_Factory();
  }
}
