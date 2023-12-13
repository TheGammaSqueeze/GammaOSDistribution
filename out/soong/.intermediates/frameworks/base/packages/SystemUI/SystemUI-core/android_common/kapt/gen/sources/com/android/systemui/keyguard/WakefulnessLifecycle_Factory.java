package com.android.systemui.keyguard;

import android.app.IWallpaperManager;
import android.content.Context;
import com.android.systemui.dump.DumpManager;
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
public final class WakefulnessLifecycle_Factory implements Factory<WakefulnessLifecycle> {
  private final Provider<Context> contextProvider;

  private final Provider<IWallpaperManager> wallpaperManagerServiceProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  public WakefulnessLifecycle_Factory(Provider<Context> contextProvider,
      Provider<IWallpaperManager> wallpaperManagerServiceProvider,
      Provider<DumpManager> dumpManagerProvider) {
    this.contextProvider = contextProvider;
    this.wallpaperManagerServiceProvider = wallpaperManagerServiceProvider;
    this.dumpManagerProvider = dumpManagerProvider;
  }

  @Override
  public WakefulnessLifecycle get() {
    return newInstance(contextProvider.get(), wallpaperManagerServiceProvider.get(), dumpManagerProvider.get());
  }

  public static WakefulnessLifecycle_Factory create(Provider<Context> contextProvider,
      Provider<IWallpaperManager> wallpaperManagerServiceProvider,
      Provider<DumpManager> dumpManagerProvider) {
    return new WakefulnessLifecycle_Factory(contextProvider, wallpaperManagerServiceProvider, dumpManagerProvider);
  }

  public static WakefulnessLifecycle newInstance(Context context,
      IWallpaperManager wallpaperManagerService, DumpManager dumpManager) {
    return new WakefulnessLifecycle(context, wallpaperManagerService, dumpManager);
  }
}
