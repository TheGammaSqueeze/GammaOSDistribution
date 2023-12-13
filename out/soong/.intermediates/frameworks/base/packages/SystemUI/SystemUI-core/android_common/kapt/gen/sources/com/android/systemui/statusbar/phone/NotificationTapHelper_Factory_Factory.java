package com.android.systemui.statusbar.phone;

import com.android.systemui.plugins.FalsingManager;
import com.android.systemui.util.concurrency.DelayableExecutor;
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
public final class NotificationTapHelper_Factory_Factory implements Factory<NotificationTapHelper.Factory> {
  private final Provider<FalsingManager> falsingManagerProvider;

  private final Provider<DelayableExecutor> delayableExecutorProvider;

  public NotificationTapHelper_Factory_Factory(Provider<FalsingManager> falsingManagerProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    this.falsingManagerProvider = falsingManagerProvider;
    this.delayableExecutorProvider = delayableExecutorProvider;
  }

  @Override
  public NotificationTapHelper.Factory get() {
    return newInstance(falsingManagerProvider.get(), delayableExecutorProvider.get());
  }

  public static NotificationTapHelper_Factory_Factory create(
      Provider<FalsingManager> falsingManagerProvider,
      Provider<DelayableExecutor> delayableExecutorProvider) {
    return new NotificationTapHelper_Factory_Factory(falsingManagerProvider, delayableExecutorProvider);
  }

  public static NotificationTapHelper.Factory newInstance(FalsingManager falsingManager,
      DelayableExecutor delayableExecutor) {
    return new NotificationTapHelper.Factory(falsingManager, delayableExecutor);
  }
}
