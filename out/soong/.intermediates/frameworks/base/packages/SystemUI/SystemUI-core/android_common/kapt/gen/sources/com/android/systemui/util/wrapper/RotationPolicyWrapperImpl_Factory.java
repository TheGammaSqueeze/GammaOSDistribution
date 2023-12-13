package com.android.systemui.util.wrapper;

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
public final class RotationPolicyWrapperImpl_Factory implements Factory<RotationPolicyWrapperImpl> {
  private final Provider<Context> contextProvider;

  public RotationPolicyWrapperImpl_Factory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public RotationPolicyWrapperImpl get() {
    return newInstance(contextProvider.get());
  }

  public static RotationPolicyWrapperImpl_Factory create(Provider<Context> contextProvider) {
    return new RotationPolicyWrapperImpl_Factory(contextProvider);
  }

  public static RotationPolicyWrapperImpl newInstance(Context context) {
    return new RotationPolicyWrapperImpl(context);
  }
}
