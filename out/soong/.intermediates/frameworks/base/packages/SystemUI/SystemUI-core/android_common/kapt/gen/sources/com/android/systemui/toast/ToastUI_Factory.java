package com.android.systemui.toast;

import android.content.Context;
import com.android.systemui.statusbar.CommandQueue;
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
public final class ToastUI_Factory implements Factory<ToastUI> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<ToastFactory> toastFactoryProvider;

  private final Provider<ToastLogger> toastLoggerProvider;

  public ToastUI_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<ToastFactory> toastFactoryProvider,
      Provider<ToastLogger> toastLoggerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.toastFactoryProvider = toastFactoryProvider;
    this.toastLoggerProvider = toastLoggerProvider;
  }

  @Override
  public ToastUI get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), toastFactoryProvider.get(), toastLoggerProvider.get());
  }

  public static ToastUI_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<ToastFactory> toastFactoryProvider,
      Provider<ToastLogger> toastLoggerProvider) {
    return new ToastUI_Factory(contextProvider, commandQueueProvider, toastFactoryProvider, toastLoggerProvider);
  }

  public static ToastUI newInstance(Context context, CommandQueue commandQueue,
      ToastFactory toastFactory, ToastLogger toastLogger) {
    return new ToastUI(context, commandQueue, toastFactory, toastLogger);
  }
}
