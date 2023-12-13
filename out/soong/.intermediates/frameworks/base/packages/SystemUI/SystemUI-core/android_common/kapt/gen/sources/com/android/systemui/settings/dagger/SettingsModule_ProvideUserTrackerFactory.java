package com.android.systemui.settings.dagger;

import android.content.Context;
import android.os.Handler;
import android.os.UserManager;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.settings.UserTracker;
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
public final class SettingsModule_ProvideUserTrackerFactory implements Factory<UserTracker> {
  private final Provider<Context> contextProvider;

  private final Provider<UserManager> userManagerProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<Handler> handlerProvider;

  public SettingsModule_ProvideUserTrackerFactory(Provider<Context> contextProvider,
      Provider<UserManager> userManagerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<Handler> handlerProvider) {
    this.contextProvider = contextProvider;
    this.userManagerProvider = userManagerProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.handlerProvider = handlerProvider;
  }

  @Override
  public UserTracker get() {
    return provideUserTracker(contextProvider.get(), userManagerProvider.get(), dumpManagerProvider.get(), handlerProvider.get());
  }

  public static SettingsModule_ProvideUserTrackerFactory create(Provider<Context> contextProvider,
      Provider<UserManager> userManagerProvider, Provider<DumpManager> dumpManagerProvider,
      Provider<Handler> handlerProvider) {
    return new SettingsModule_ProvideUserTrackerFactory(contextProvider, userManagerProvider, dumpManagerProvider, handlerProvider);
  }

  public static UserTracker provideUserTracker(Context context, UserManager userManager,
      DumpManager dumpManager, Handler handler) {
    return Preconditions.checkNotNullFromProvides(SettingsModule.provideUserTracker(context, userManager, dumpManager, handler));
  }
}
