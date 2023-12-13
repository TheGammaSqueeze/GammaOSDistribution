package com.android.systemui.statusbar.phone;

import android.app.IWallpaperManager;
import android.app.WallpaperManager;
import android.os.Handler;
import com.android.keyguard.KeyguardUpdateMonitor;
import com.android.systemui.dump.DumpManager;
import com.android.systemui.statusbar.NotificationMediaManager;
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
public final class LockscreenWallpaper_Factory implements Factory<LockscreenWallpaper> {
  private final Provider<WallpaperManager> wallpaperManagerProvider;

  private final Provider<IWallpaperManager> iWallpaperManagerProvider;

  private final Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider;

  private final Provider<DumpManager> dumpManagerProvider;

  private final Provider<NotificationMediaManager> mediaManagerProvider;

  private final Provider<Handler> mainHandlerProvider;

  public LockscreenWallpaper_Factory(Provider<WallpaperManager> wallpaperManagerProvider,
      Provider<IWallpaperManager> iWallpaperManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<NotificationMediaManager> mediaManagerProvider,
      Provider<Handler> mainHandlerProvider) {
    this.wallpaperManagerProvider = wallpaperManagerProvider;
    this.iWallpaperManagerProvider = iWallpaperManagerProvider;
    this.keyguardUpdateMonitorProvider = keyguardUpdateMonitorProvider;
    this.dumpManagerProvider = dumpManagerProvider;
    this.mediaManagerProvider = mediaManagerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
  }

  @Override
  public LockscreenWallpaper get() {
    return newInstance(wallpaperManagerProvider.get(), iWallpaperManagerProvider.get(), keyguardUpdateMonitorProvider.get(), dumpManagerProvider.get(), mediaManagerProvider.get(), mainHandlerProvider.get());
  }

  public static LockscreenWallpaper_Factory create(
      Provider<WallpaperManager> wallpaperManagerProvider,
      Provider<IWallpaperManager> iWallpaperManagerProvider,
      Provider<KeyguardUpdateMonitor> keyguardUpdateMonitorProvider,
      Provider<DumpManager> dumpManagerProvider,
      Provider<NotificationMediaManager> mediaManagerProvider,
      Provider<Handler> mainHandlerProvider) {
    return new LockscreenWallpaper_Factory(wallpaperManagerProvider, iWallpaperManagerProvider, keyguardUpdateMonitorProvider, dumpManagerProvider, mediaManagerProvider, mainHandlerProvider);
  }

  public static LockscreenWallpaper newInstance(WallpaperManager wallpaperManager,
      IWallpaperManager iWallpaperManager, KeyguardUpdateMonitor keyguardUpdateMonitor,
      DumpManager dumpManager, NotificationMediaManager mediaManager, Handler mainHandler) {
    return new LockscreenWallpaper(wallpaperManager, iWallpaperManager, keyguardUpdateMonitor, dumpManager, mediaManager, mainHandler);
  }
}
