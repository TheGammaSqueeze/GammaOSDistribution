package com.android.systemui.statusbar.phone;

import android.content.Context;
import com.android.systemui.dump.DumpManager;
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
public final class DarkIconDispatcherImpl_Factory implements Factory<DarkIconDispatcherImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public DarkIconDispatcherImpl_Factory(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.commandQueueProvider = commandQueueProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public DarkIconDispatcherImpl get() {
    return newInstance(contextProvider.get(), commandQueueProvider.get(), dumpManagerProvider.get());
  }

  public static DarkIconDispatcherImpl_Factory create(Provider<Context> contextProvider,
      Provider<CommandQueue> commandQueueProvider, Provider<DumpManager> dumpManagerProvider) {
    return new DarkIconDispatcherImpl_Factory(contextProvider, commandQueueProvider, dumpManagerProvider);
  }

  public static DarkIconDispatcherImpl newInstance(Context context, CommandQueue commandQueue,
      DumpManager dumpManager) {
    return new DarkIconDispatcherImpl(context, commandQueue, dumpManager);
  }
}
