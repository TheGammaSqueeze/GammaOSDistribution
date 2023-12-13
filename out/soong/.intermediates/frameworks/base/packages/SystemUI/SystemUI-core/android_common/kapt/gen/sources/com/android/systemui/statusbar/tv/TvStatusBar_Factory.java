package com.android.systemui.statusbar.tv;

import android.content.Context;
import com.android.systemui.assist.AssistManager;
import com.android.systemui.statusbar.CommandQueue;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
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
public final class TvStatusBar_Factory implements Factory<TvStatusBar> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<AssistManager> assistManagerLazyProvider;

  public TvStatusBar_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<AssistManager> assistManagerLazyProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.assistManagerLazyProvider = assistManagerLazyProvider;
  }

  @Override
  public TvStatusBar get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), DoubleCheck.lazy(assistManagerLazyProvider));
  }

  public static TvStatusBar_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider,
      Provider<AssistManager> assistManagerLazyProvider) {
    return new TvStatusBar_Factory(contextProvider, commandQueueProvider, assistManagerLazyProvider);
  }

  public static TvStatusBar newInstance(Context context, CommandQueue commandQueue,
      Lazy<AssistManager> assistManagerLazy) {
    return new TvStatusBar(context, commandQueue, assistManagerLazy);
  }
}
