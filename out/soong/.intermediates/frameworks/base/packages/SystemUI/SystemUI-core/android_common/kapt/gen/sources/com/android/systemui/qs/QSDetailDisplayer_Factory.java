package com.android.systemui.qs;

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
public final class QSDetailDisplayer_Factory implements Factory<QSDetailDisplayer> {
  @Override
  public QSDetailDisplayer get() {
    return newInstance();
  }

  public static QSDetailDisplayer_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static QSDetailDisplayer newInstance() {
    return new QSDetailDisplayer();
  }

  private static final class InstanceHolder {
    private static final QSDetailDisplayer_Factory INSTANCE = new QSDetailDisplayer_Factory();
  }
}
