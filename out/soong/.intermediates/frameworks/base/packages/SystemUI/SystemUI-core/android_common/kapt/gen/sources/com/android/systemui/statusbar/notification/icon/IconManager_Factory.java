package com.android.systemui.statusbar.notification.icon;

import android.content.pm.LauncherApps;
import com.android.systemui.statusbar.notification.collection.notifcollection.CommonNotifCollection;
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
public final class IconManager_Factory implements Factory<IconManager> {
  private final Provider<CommonNotifCollection> notifCollectionProvider;

  private final Provider<LauncherApps> launcherAppsProvider;

  private final Provider<IconBuilder> iconBuilderProvider;

  public IconManager_Factory(Provider<CommonNotifCollection> notifCollectionProvider,
      Provider<LauncherApps> launcherAppsProvider, Provider<IconBuilder> iconBuilderProvider) {
    this.notifCollectionProvider = notifCollectionProvider;
    this.launcherAppsProvider = launcherAppsProvider;
    this.iconBuilderProvider = iconBuilderProvider;
  }

  @Override
  public IconManager get() {
    return newInstance(notifCollectionProvider.get(), launcherAppsProvider.get(), iconBuilderProvider.get());
  }

  public static IconManager_Factory create(Provider<CommonNotifCollection> notifCollectionProvider,
      Provider<LauncherApps> launcherAppsProvider, Provider<IconBuilder> iconBuilderProvider) {
    return new IconManager_Factory(notifCollectionProvider, launcherAppsProvider, iconBuilderProvider);
  }

  public static IconManager newInstance(CommonNotifCollection notifCollection,
      LauncherApps launcherApps, IconBuilder iconBuilder) {
    return new IconManager(notifCollection, launcherApps, iconBuilder);
  }
}
