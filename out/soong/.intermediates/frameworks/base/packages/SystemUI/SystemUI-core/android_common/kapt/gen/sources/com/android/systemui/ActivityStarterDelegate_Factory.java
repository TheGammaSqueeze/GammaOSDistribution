package com.android.systemui;

import com.android.systemui.statusbar.phone.StatusBar;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class ActivityStarterDelegate_Factory implements Factory<ActivityStarterDelegate> {
  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  public ActivityStarterDelegate_Factory(
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
  }

  @Override
  public ActivityStarterDelegate get() {
    return newInstance(DoubleCheck.lazy(statusBarOptionalLazyProvider));
  }

  public static ActivityStarterDelegate_Factory create(
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    return new ActivityStarterDelegate_Factory(statusBarOptionalLazyProvider);
  }

  public static ActivityStarterDelegate newInstance(
      Lazy<Optional<StatusBar>> statusBarOptionalLazy) {
    return new ActivityStarterDelegate(statusBarOptionalLazy);
  }
}
