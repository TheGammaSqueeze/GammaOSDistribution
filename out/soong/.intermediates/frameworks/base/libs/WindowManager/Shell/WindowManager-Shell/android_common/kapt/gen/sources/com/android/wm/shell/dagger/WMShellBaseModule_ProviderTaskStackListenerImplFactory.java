package com.android.wm.shell.dagger;

import android.os.Handler;
import com.android.wm.shell.common.TaskStackListenerImpl;
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
public final class WMShellBaseModule_ProviderTaskStackListenerImplFactory implements Factory<TaskStackListenerImpl> {
  private final Provider<Handler> mainHandlerProvider;

  public WMShellBaseModule_ProviderTaskStackListenerImplFactory(
      Provider<Handler> mainHandlerProvider) {
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public TaskStackListenerImpl get() {
    return providerTaskStackListenerImpl(mainHandlerProvider.get());
  }

  public static WMShellBaseModule_ProviderTaskStackListenerImplFactory create(
      Provider<Handler> mainHandlerProvider) {
    return new WMShellBaseModule_ProviderTaskStackListenerImplFactory(mainHandlerProvider);
  }

  public static TaskStackListenerImpl providerTaskStackListenerImpl(Handler mainHandler) {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.providerTaskStackListenerImpl(mainHandler));
  }
}
