package com.android.systemui.qs.tiles.dialog;

import android.content.Context;
import android.os.Handler;
import com.android.internal.logging.UiEventLogger;
import com.android.systemui.animation.DialogLaunchAnimator;
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
public final class InternetDialogFactory_Factory implements Factory<InternetDialogFactory> {
  private final Provider<Handler> handlerProvider;

  private final Provider<Executor> executorProvider;

  private final Provider<InternetDialogController> internetDialogControllerProvider;

  private final Provider<Context> contextProvider;

  private final Provider<UiEventLogger> uiEventLoggerProvider;

  private final Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider;

  public InternetDialogFactory_Factory(Provider<Handler> handlerProvider,
      Provider<Executor> executorProvider,
      Provider<InternetDialogController> internetDialogControllerProvider,
      Provider<Context> contextProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    this.handlerProvider = handlerProvider;
    this.executorProvider = executorProvider;
    this.internetDialogControllerProvider = internetDialogControllerProvider;
    this.contextProvider = contextProvider;
    this.uiEventLoggerProvider = uiEventLoggerProvider;
    this.dialogLaunchAnimatorProvider = dialogLaunchAnimatorProvider;
  }

  @Override
  public InternetDialogFactory get() {
    return newInstance(handlerProvider.get(), executorProvider.get(), internetDialogControllerProvider.get(), contextProvider.get(), uiEventLoggerProvider.get(), dialogLaunchAnimatorProvider.get());
  }

  public static InternetDialogFactory_Factory create(Provider<Handler> handlerProvider,
      Provider<Executor> executorProvider,
      Provider<InternetDialogController> internetDialogControllerProvider,
      Provider<Context> contextProvider, Provider<UiEventLogger> uiEventLoggerProvider,
      Provider<DialogLaunchAnimator> dialogLaunchAnimatorProvider) {
    return new InternetDialogFactory_Factory(handlerProvider, executorProvider, internetDialogControllerProvider, contextProvider, uiEventLoggerProvider, dialogLaunchAnimatorProvider);
  }

  public static InternetDialogFactory newInstance(Handler handler, Executor executor,
      InternetDialogController internetDialogController, Context context,
      UiEventLogger uiEventLogger, DialogLaunchAnimator dialogLaunchAnimator) {
    return new InternetDialogFactory(handler, executor, internetDialogController, context, uiEventLogger, dialogLaunchAnimator);
  }
}
