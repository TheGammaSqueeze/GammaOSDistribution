package com.android.systemui.qs;

import android.os.Handler;
import android.os.Looper;
import android.view.View;
import com.android.systemui.plugins.ActivityStarter;
import com.android.systemui.settings.UserTracker;
import com.android.systemui.statusbar.policy.SecurityController;
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
public final class QSSecurityFooter_Factory implements Factory<QSSecurityFooter> {
  private final Provider<View> rootViewProvider;

  private final Provider<UserTracker> userTrackerProvider;

  private final Provider<Handler> mainHandlerProvider;

  private final Provider<ActivityStarter> activityStarterProvider;

  private final Provider<SecurityController> securityControllerProvider;

  private final Provider<Looper> bgLooperProvider;

  public QSSecurityFooter_Factory(Provider<View> rootViewProvider,
      Provider<UserTracker> userTrackerProvider, Provider<Handler> mainHandlerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<SecurityController> securityControllerProvider, Provider<Looper> bgLooperProvider) {
    this.rootViewProvider = rootViewProvider;
    this.userTrackerProvider = userTrackerProvider;
    this.mainHandlerProvider = mainHandlerProvider;
    this.activityStarterProvider = activityStarterProvider;
    this.securityControllerProvider = securityControllerProvider;
    this.bgLooperProvider = bgLooperProvider;
  }

  @Override
  public QSSecurityFooter get() {
    return newInstance(rootViewProvider.get(), userTrackerProvider.get(), mainHandlerProvider.get(), activityStarterProvider.get(), securityControllerProvider.get(), bgLooperProvider.get());
  }

  public static QSSecurityFooter_Factory create(Provider<View> rootViewProvider,
      Provider<UserTracker> userTrackerProvider, Provider<Handler> mainHandlerProvider,
      Provider<ActivityStarter> activityStarterProvider,
      Provider<SecurityController> securityControllerProvider, Provider<Looper> bgLooperProvider) {
    return new QSSecurityFooter_Factory(rootViewProvider, userTrackerProvider, mainHandlerProvider, activityStarterProvider, securityControllerProvider, bgLooperProvider);
  }

  public static QSSecurityFooter newInstance(View rootView, UserTracker userTracker,
      Handler mainHandler, ActivityStarter activityStarter, SecurityController securityController,
      Looper bgLooper) {
    return new QSSecurityFooter(rootView, userTracker, mainHandler, activityStarter, securityController, bgLooper);
  }
}
