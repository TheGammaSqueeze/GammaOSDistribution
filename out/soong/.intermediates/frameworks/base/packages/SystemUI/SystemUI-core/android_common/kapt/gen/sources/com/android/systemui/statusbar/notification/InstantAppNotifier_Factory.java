package com.android.systemui.statusbar.notification;

import android.content.Context;
import com.android.systemui.statusbar.CommandQueue;
import com.android.wm.shell.legacysplitscreen.LegacySplitScreen;
import dagger.internal.Factory;
import java.util.Optional;
import java.util.concurrent.Executor;
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
public final class InstantAppNotifier_Factory implements Factory<InstantAppNotifier> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<Executor> uiBgExecutorProvider;

  private final Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider;

  public InstantAppNotifier_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<Executor> uiBgExecutorProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.uiBgExecutorProvider = uiBgExecutorProvider;
    this.splitScreenOptionalProvider = splitScreenOptionalProvider;
  }

  @Override
  public InstantAppNotifier get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), uiBgExecutorProvider.get(), splitScreenOptionalProvider.get());
  }

  public static InstantAppNotifier_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<Executor> uiBgExecutorProvider,
      Provider<Optional<LegacySplitScreen>> splitScreenOptionalProvider) {
    return new InstantAppNotifier_Factory(contextProvider, commandQueueProvider, uiBgExecutorProvider, splitScreenOptionalProvider);
  }

  public static InstantAppNotifier newInstance(Context context, CommandQueue commandQueue,
      Executor uiBgExecutor, Optional<LegacySplitScreen> splitScreenOptional) {
    return new InstantAppNotifier(context, commandQueue, uiBgExecutor, splitScreenOptional);
  }
}
