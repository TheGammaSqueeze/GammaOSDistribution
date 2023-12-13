package com.android.systemui.recents;

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
public final class OverviewProxyRecentsImpl_Factory implements Factory<OverviewProxyRecentsImpl> {
  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  public OverviewProxyRecentsImpl_Factory(
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
  }

  @Override
  public OverviewProxyRecentsImpl get() {
    return newInstance(DoubleCheck.lazy(statusBarOptionalLazyProvider));
  }

  public static OverviewProxyRecentsImpl_Factory create(
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    return new OverviewProxyRecentsImpl_Factory(statusBarOptionalLazyProvider);
  }

  public static OverviewProxyRecentsImpl newInstance(
      Lazy<Optional<StatusBar>> statusBarOptionalLazy) {
    return new OverviewProxyRecentsImpl(statusBarOptionalLazy);
  }
}
