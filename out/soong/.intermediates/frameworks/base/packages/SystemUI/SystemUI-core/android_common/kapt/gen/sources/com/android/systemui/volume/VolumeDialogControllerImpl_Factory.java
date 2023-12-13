package com.android.systemui.volume;

import android.app.NotificationManager;
import android.content.Context;
import android.content.pm.PackageManager;
import android.media.AudioManager;
import android.media.IAudioService;
import android.os.Vibrator;
import android.view.accessibility.AccessibilityManager;
import com.android.systemui.broadcast.BroadcastDispatcher;
import com.android.systemui.keyguard.WakefulnessLifecycle;
import com.android.systemui.util.RingerModeTracker;
import com.android.systemui.util.concurrency.ThreadFactory;
import dagger.internal.Factory;
import java.util.Optional;
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
public final class VolumeDialogControllerImpl_Factory implements Factory<VolumeDialogControllerImpl> {
  private final Provider<Context> contextProvider;

  private final Provider<BroadcastDispatcher> broadcastDispatcherProvider;

  private final Provider<RingerModeTracker> ringerModeTrackerProvider;

  private final Provider<ThreadFactory> theadFactoryProvider;

  private final Provider<AudioManager> audioManagerProvider;

  private final Provider<NotificationManager> notificationManagerProvider;

  private final Provider<Optional<Vibrator>> optionalVibratorProvider;

  private final Provider<IAudioService> iAudioServiceProvider;

  private final Provider<AccessibilityManager> accessibilityManagerProvider;

  private final Provider<PackageManager> packageManagerProvider;

  private final Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider;

  public VolumeDialogControllerImpl_Factory(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<ThreadFactory> theadFactoryProvider, Provider<AudioManager> audioManagerProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<Optional<Vibrator>> optionalVibratorProvider,
      Provider<IAudioService> iAudioServiceProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider) {
    this.contextProvider = contextProvider;
    this.broadcastDispatcherProvider = broadcastDispatcherProvider;
    this.ringerModeTrackerProvider = ringerModeTrackerProvider;
    this.theadFactoryProvider = theadFactoryProvider;
    this.audioManagerProvider = audioManagerProvider;
    this.notificationManagerProvider = notificationManagerProvider;
    this.optionalVibratorProvider = optionalVibratorProvider;
    this.iAudioServiceProvider = iAudioServiceProvider;
    this.accessibilityManagerProvider = accessibilityManagerProvider;
    this.packageManagerProvider = packageManagerProvider;
    this.wakefulnessLifecycleProvider = wakefulnessLifecycleProvider;
  }

  @Override
  public VolumeDialogControllerImpl get() {
    return newInstance(contextProvider.get(), broadcastDispatcherProvider.get(), ringerModeTrackerProvider.get(), theadFactoryProvider.get(), audioManagerProvider.get(), notificationManagerProvider.get(), optionalVibratorProvider.get(), iAudioServiceProvider.get(), accessibilityManagerProvider.get(), packageManagerProvider.get(), wakefulnessLifecycleProvider.get());
  }

  public static VolumeDialogControllerImpl_Factory create(Provider<Context> contextProvider,
      Provider<BroadcastDispatcher> broadcastDispatcherProvider,
      Provider<RingerModeTracker> ringerModeTrackerProvider,
      Provider<ThreadFactory> theadFactoryProvider, Provider<AudioManager> audioManagerProvider,
      Provider<NotificationManager> notificationManagerProvider,
      Provider<Optional<Vibrator>> optionalVibratorProvider,
      Provider<IAudioService> iAudioServiceProvider,
      Provider<AccessibilityManager> accessibilityManagerProvider,
      Provider<PackageManager> packageManagerProvider,
      Provider<WakefulnessLifecycle> wakefulnessLifecycleProvider) {
    return new VolumeDialogControllerImpl_Factory(contextProvider, broadcastDispatcherProvider, ringerModeTrackerProvider, theadFactoryProvider, audioManagerProvider, notificationManagerProvider, optionalVibratorProvider, iAudioServiceProvider, accessibilityManagerProvider, packageManagerProvider, wakefulnessLifecycleProvider);
  }

  public static VolumeDialogControllerImpl newInstance(Context context,
      BroadcastDispatcher broadcastDispatcher, RingerModeTracker ringerModeTracker,
      ThreadFactory theadFactory, AudioManager audioManager,
      NotificationManager notificationManager, Optional<Vibrator> optionalVibrator,
      IAudioService iAudioService, AccessibilityManager accessibilityManager,
      PackageManager packageManager, WakefulnessLifecycle wakefulnessLifecycle) {
    return new VolumeDialogControllerImpl(context, broadcastDispatcher, ringerModeTracker, theadFactory, audioManager, notificationManager, optionalVibrator, iAudioService, accessibilityManager, packageManager, wakefulnessLifecycle);
  }
}
