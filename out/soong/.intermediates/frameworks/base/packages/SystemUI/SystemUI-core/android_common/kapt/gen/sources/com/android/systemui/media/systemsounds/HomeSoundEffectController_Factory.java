package com.android.systemui.media.systemsounds;

import android.content.Context;
import android.content.pm.PackageManager;
import android.media.AudioManager;
import com.android.systemui.shared.system.ActivityManagerWrapper;
import com.android.systemui.shared.system.TaskStackChangeListeners;
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
public final class HomeSoundEffectController_Factory implements Factory<HomeSoundEffectController> {
  private final Provider<Context> contextProvider;

  private final Provider<AudioManager> audioManagerProvider;

  private final Provider<TaskStackChangeListeners> taskStackChangeListenersProvider;

  private final Provider<ActivityManagerWrapper> activityManagerWrapperProvider;

  private final Provider<PackageManager> packageManagerProvider;

  public HomeSoundEffectController_Factory(Provider<Context> contextProvider,
      Provider<AudioManager> audioManagerProvider,
      Provider<TaskStackChangeListeners> taskStackChangeListenersProvider,
      Provider<ActivityManagerWrapper> activityManagerWrapperProvider,
      Provider<PackageManager> packageManagerProvider) {
    this.contextProvider = contextProvider;
    this.audioManagerProvider = audioManagerProvider;
    this.taskStackChangeListenersProvider = taskStackChangeListenersProvider;
    this.activityManagerWrapperProvider = activityManagerWrapperProvider;
    this.packageManagerProvider = packageManagerProvider;
  }

  @Override
  public HomeSoundEffectController get() {
    return newInstance(contextProvider.get(), audioManagerProvider.get(), taskStackChangeListenersProvider.get(), activityManagerWrapperProvider.get(), packageManagerProvider.get());
  }

  public static HomeSoundEffectController_Factory create(Provider<Context> contextProvider,
      Provider<AudioManager> audioManagerProvider,
      Provider<TaskStackChangeListeners> taskStackChangeListenersProvider,
      Provider<ActivityManagerWrapper> activityManagerWrapperProvider,
      Provider<PackageManager> packageManagerProvider) {
    return new HomeSoundEffectController_Factory(contextProvider, audioManagerProvider, taskStackChangeListenersProvider, activityManagerWrapperProvider, packageManagerProvider);
  }

  public static HomeSoundEffectController newInstance(Context context, AudioManager audioManager,
      TaskStackChangeListeners taskStackChangeListeners,
      ActivityManagerWrapper activityManagerWrapper, PackageManager packageManager) {
    return new HomeSoundEffectController(context, audioManager, taskStackChangeListeners, activityManagerWrapper, packageManager);
  }
}
