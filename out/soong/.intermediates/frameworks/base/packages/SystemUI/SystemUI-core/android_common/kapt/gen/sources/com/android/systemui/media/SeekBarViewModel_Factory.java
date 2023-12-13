package com.android.systemui.media;

import com.android.systemui.util.concurrency.RepeatableExecutor;
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
public final class SeekBarViewModel_Factory implements Factory<SeekBarViewModel> {
  private final Provider<RepeatableExecutor> bgExecutorProvider;

  public SeekBarViewModel_Factory(Provider<RepeatableExecutor> bgExecutorProvider) {
    this.bgExecutorProvider = bgExecutorProvider;
  }

  @Override
  public SeekBarViewModel get() {
    return newInstance(bgExecutorProvider.get());
  }

  public static SeekBarViewModel_Factory create(Provider<RepeatableExecutor> bgExecutorProvider) {
    return new SeekBarViewModel_Factory(bgExecutorProvider);
  }

  public static SeekBarViewModel newInstance(RepeatableExecutor bgExecutor) {
    return new SeekBarViewModel(bgExecutor);
  }
}
