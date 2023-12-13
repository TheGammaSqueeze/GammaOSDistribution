package com.android.systemui.media;

import android.content.Context;
import com.android.systemui.media.dialog.MediaOutputDialogFactory;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.statusbar.phone.KeyguardDismissUtil;
import com.android.systemui.util.time.SystemClock;
import dagger.Lazy;
import dagger.internal.DoubleCheck;
import dagger.internal.Factory;
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
public final class MediaControlPanel_Factory implements Factory<MediaControlPanel> {
  private final Provider<Context> contextProvider;

  private final Provider<Executor> backgroundExecutorProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<MediaViewController> mediaViewControllerProvider;

  private final Provider<SeekBarViewModel> seekBarViewModelProvider;

  private final Provider<MediaDataManager> mediaDataManagerProvider;

  private final Provider<KeyguardDismissUtil> keyguardDismissUtilProvider;

  private final Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider;

  private final Provider<MediaCarouselController> mediaCarouselControllerProvider;

  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<SystemClock> systemClockProvider;

  public MediaControlPanel_Factory(Provider<Context> contextProvider,
      Provider<Executor> backgroundExecutorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<MediaViewController> mediaViewControllerProvider,
      Provider<SeekBarViewModel> seekBarViewModelProvider,
      Provider<MediaDataManager> mediaDataManagerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider,
      Provider<MediaCarouselController> mediaCarouselControllerProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<SystemClock> systemClockProvider) {
    this.contextProvider = contextProvider;
    this.backgroundExecutorProvider = backgroundExecutorProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.mediaViewControllerProvider = mediaViewControllerProvider;
    this.seekBarViewModelProvider = seekBarViewModelProvider;
    this.mediaDataManagerProvider = mediaDataManagerProvider;
    this.keyguardDismissUtilProvider = keyguardDismissUtilProvider;
    this.mediaOutputDialogFactoryProvider = mediaOutputDialogFactoryProvider;
    this.mediaCarouselControllerProvider = mediaCarouselControllerProvider;
    this.falsingManagerProvider = falsingManagerProvider;
    this.systemClockProvider = systemClockProvider;
  }

  @Override
  public MediaControlPanel get() {
    return newInstance(contextProvider.get(), backgroundExecutorProvider.get(), activityStarterProvider.get(), mediaViewControllerProvider.get(), seekBarViewModelProvider.get(), DoubleCheck.lazy(mediaDataManagerProvider), keyguardDismissUtilProvider.get(), mediaOutputDialogFactoryProvider.get(), mediaCarouselControllerProvider.get(), falsingManagerProvider.get(), systemClockProvider.get());
  }

  public static MediaControlPanel_Factory create(Provider<Context> contextProvider,
      Provider<Executor> backgroundExecutorProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<MediaViewController> mediaViewControllerProvider,
      Provider<SeekBarViewModel> seekBarViewModelProvider,
      Provider<MediaDataManager> mediaDataManagerProvider,
      Provider<KeyguardDismissUtil> keyguardDismissUtilProvider,
      Provider<MediaOutputDialogFactory> mediaOutputDialogFactoryProvider,
      Provider<MediaCarouselController> mediaCarouselControllerProvider,
      Provider<FalsingManager> falsingManagerProvider, Provider<SystemClock> systemClockProvider) {
    return new MediaControlPanel_Factory(contextProvider, backgroundExecutorProvider, activityStarterProvider, mediaViewControllerProvider, seekBarViewModelProvider, mediaDataManagerProvider, keyguardDismissUtilProvider, mediaOutputDialogFactoryProvider, mediaCarouselControllerProvider, falsingManagerProvider, systemClockProvider);
  }

  public static MediaControlPanel newInstance(Context context, Executor backgroundExecutor,
      ActivityStarter activityStarter, MediaViewController mediaViewController,
      SeekBarViewModel seekBarViewModel, Lazy<MediaDataManager> lazyMediaDataManager,
      KeyguardDismissUtil keyguardDismissUtil, MediaOutputDialogFactory mediaOutputDialogFactory,
      MediaCarouselController mediaCarouselController, FalsingManager falsingManager,
      SystemClock systemClock) {
    return new MediaControlPanel(context, backgroundExecutor, activityStarter, mediaViewController, seekBarViewModel, lazyMediaDataManager, keyguardDismissUtil, mediaOutputDialogFactory, mediaCarouselController, falsingManager, systemClock);
  }
}
