package com.android.systemui.recents;

import android.content.Context;
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
public final class ScreenPinningRequest_Factory implements Factory<ScreenPinningRequest> {
  private final Provider<Context> contextProvider;

  private final Provider<Optional<StatusBar>> statusBarOptionalLazyProvider;

  public ScreenPinningRequest_Factory(Provider<Context> contextProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    this.contextProvider = contextProvider;
    this.statusBarOptionalLazyProvider = statusBarOptionalLazyProvider;
  }

  @Override
  public ScreenPinningRequest get() {
    return newInstance(contextProvider.get(), DoubleCheck.lazy(statusBarOptionalLazyProvider));
  }

  public static ScreenPinningRequest_Factory create(Provider<Context> contextProvider,
      Provider<Optional<StatusBar>> statusBarOptionalLazyProvider) {
    return new ScreenPinningRequest_Factory(contextProvider, statusBarOptionalLazyProvider);
  }

  public static ScreenPinningRequest newInstance(Context context,
      Lazy<Optional<StatusBar>> statusBarOptionalLazy) {
    return new ScreenPinningRequest(context, statusBarOptionalLazy);
  }
}
