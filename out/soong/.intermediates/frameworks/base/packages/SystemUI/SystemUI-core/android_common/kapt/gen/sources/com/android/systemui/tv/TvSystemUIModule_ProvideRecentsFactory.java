package com.android.systemui.tv;

import android.content.Context;
import com.android.systemui.recents.Recents;
import com.android.systemui.recents.RecentsImplementation;
import com.android.systemui.statusbar.CommandQueue;
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
public final class TvSystemUIModule_ProvideRecentsFactory implements Factory<Recents> {
  private final Provider<Context> contextProvider;

  private final Provider<RecentsImplementation> recentsImplementationProvider;

  private final Provider<CommandQueue> commandQueueProvider;

  public TvSystemUIModule_ProvideRecentsFactory(Provider<Context> contextProvider,
      Provider<RecentsImplementation> recentsImplementationProvider,
      Provider<CommandQueue> commandQueueProvider) {
    this.contextProvider = contextProvider;
    this.recentsImplementationProvider = recentsImplementationProvider;
    this.commandQueueProvider = commandQueueProvider;
  }

  @Override
  public Recents get() {
    return provideRecents(contextProvider.get(), recentsImplementationProvider.get(), commandQueueProvider.get());
  }

  public static TvSystemUIModule_ProvideRecentsFactory create(Provider<Context> contextProvider,
      Provider<RecentsImplementation> recentsImplementationProvider,
      Provider<CommandQueue> commandQueueProvider) {
    return new TvSystemUIModule_ProvideRecentsFactory(contextProvider, recentsImplementationProvider, commandQueueProvider);
  }

  public static Recents provideRecents(Context context, RecentsImplementation recentsImplementation,
      CommandQueue commandQueue) {
    return Preconditions.checkNotNullFromProvides(TvSystemUIModule.provideRecents(context, recentsImplementation, commandQueue));
  }
}
