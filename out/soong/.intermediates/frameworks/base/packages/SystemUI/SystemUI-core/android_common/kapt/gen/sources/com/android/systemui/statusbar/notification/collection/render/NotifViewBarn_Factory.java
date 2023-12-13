package com.android.systemui.statusbar.notification.collection.render;

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
public final class NotifViewBarn_Factory implements Factory<NotifViewBarn> {
  @Override
  public NotifViewBarn get() {
    return newInstance();
  }

  public static NotifViewBarn_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static NotifViewBarn newInstance() {
    return new NotifViewBarn();
  }

  private static final class InstanceHolder {
    private static final NotifViewBarn_Factory INSTANCE = new NotifViewBarn_Factory();
  }
}
