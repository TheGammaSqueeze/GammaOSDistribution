package com.android.systemui.dagger;

import android.content.Context;
import android.view.inputmethod.InputMethodManager;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class FrameworkServicesModule_ProvideInputMethodManagerFactory implements Factory<InputMethodManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideInputMethodManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public InputMethodManager get() {
    return provideInputMethodManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideInputMethodManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideInputMethodManagerFactory(contextProvider);
  }

  public static InputMethodManager provideInputMethodManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideInputMethodManager(context));
  }
}
