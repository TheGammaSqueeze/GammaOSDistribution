package com.android.wm.shell.dagger;

import android.content.Context;
import com.android.wm.shell.freeform.FreeformTaskListener;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class WMShellBaseModule_ProvideFreeformTaskListenerFactory implements Factory<Optional<FreeformTaskListener>> {
  private final Provider<Optional<FreeformTaskListener>> freeformTaskListenerProvider;

  private final Provider<Context> contextProvider;

  public WMShellBaseModule_ProvideFreeformTaskListenerFactory(
      Provider<Optional<FreeformTaskListener>> freeformTaskListenerProvider,
      Provider<Context> contextProvider) {
    this.freeformTaskListenerProvider = freeformTaskListenerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public Optional<FreeformTaskListener> get() {
    return provideFreeformTaskListener(freeformTaskListenerProvider.get(), contextProvider.get());
  }

  public static WMShellBaseModule_ProvideFreeformTaskListenerFactory create(
      Provider<Optional<FreeformTaskListener>> freeformTaskListenerProvider,
      Provider<Context> contextProvider) {
    return new WMShellBaseModule_ProvideFreeformTaskListenerFactory(freeformTaskListenerProvider, contextProvider);
  }

  public static Optional<FreeformTaskListener> provideFreeformTaskListener(
      Optional<FreeformTaskListener> freeformTaskListener, Context context) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideFreeformTaskListener(freeformTaskListener, context));
  }
}
