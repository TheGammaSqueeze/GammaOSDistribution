package com.android.systemui.power;

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
public final class EnhancedEstimatesImpl_Factory implements Factory<EnhancedEstimatesImpl> {
  @Override
  public EnhancedEstimatesImpl get() {
    return newInstance();
  }

  public static EnhancedEstimatesImpl_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static EnhancedEstimatesImpl newInstance() {
    return new EnhancedEstimatesImpl();
  }

  private static final class InstanceHolder {
    private static final EnhancedEstimatesImpl_Factory INSTANCE = new EnhancedEstimatesImpl_Factory();
  }
}
