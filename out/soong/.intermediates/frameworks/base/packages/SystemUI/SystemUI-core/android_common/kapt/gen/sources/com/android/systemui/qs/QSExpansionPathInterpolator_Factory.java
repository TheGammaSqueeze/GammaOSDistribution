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
public final class QSExpansionPathInterpolator_Factory implements Factory<QSExpansionPathInterpolator> {
  @Override
  public QSExpansionPathInterpolator get() {
    return newInstance();
  }

  public static QSExpansionPathInterpolator_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static QSExpansionPathInterpolator newInstance() {
    return new QSExpansionPathInterpolator();
  }

  private static final class InstanceHolder {
    private static final QSExpansionPathInterpolator_Factory INSTANCE = new QSExpansionPathInterpolator_Factory();
  }
}
