package com.android.keyguard;

import android.content.Context;
import com.android.systemui.unfold.util.NaturalRotationUnfoldProgressProvider;
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
public final class KeyguardUnfoldTransition_Factory implements Factory<KeyguardUnfoldTransition> {
  private final Provider<Context> contextProvider;

  private final Provider<NaturalRotationUnfoldProgressProvider> unfoldProgressProvider;

  public KeyguardUnfoldTransition_Factory(Provider<Context> contextProvider,
      Provider<NaturalRotationUnfoldProgressProvider> unfoldProgressProvider) {
    this.contextProvider = contextProvider;
    this.unfoldProgressProvider = unfoldProgressProvider;
  }

  @Override
  public KeyguardUnfoldTransition get() {
    return newInstance(contextProvider.get(), unfoldProgressProvider.get());
  }

  public static KeyguardUnfoldTransition_Factory create(Provider<Context> contextProvider,
      Provider<NaturalRotationUnfoldProgressProvider> unfoldProgressProvider) {
    return new KeyguardUnfoldTransition_Factory(contextProvider, unfoldProgressProvider);
  }

  public static KeyguardUnfoldTransition newInstance(Context context,
      NaturalRotationUnfoldProgressProvider unfoldProgressProvider) {
    return new KeyguardUnfoldTransition(context, unfoldProgressProvider);
  }
}
