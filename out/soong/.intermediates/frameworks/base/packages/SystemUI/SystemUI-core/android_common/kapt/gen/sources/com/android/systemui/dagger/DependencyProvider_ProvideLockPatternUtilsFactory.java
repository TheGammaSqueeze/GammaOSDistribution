package com.android.systemui.dagger;

import android.content.Context;
import com.android.internal.widget.LockPatternUtils;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class DependencyProvider_ProvideLockPatternUtilsFactory implements Factory<LockPatternUtils> {
  private final DependencyProvider module;

  private final Provider<Context> contextProvider;

  public DependencyProvider_ProvideLockPatternUtilsFactory(DependencyProvider module,
      Provider<Context> contextProvider) {
    this.module = module;
    this.contextProvider = contextProvider;
  }

  @Override
  public LockPatternUtils get() {
    return provideLockPatternUtils(module, contextProvider.get());
  }

  public static DependencyProvider_ProvideLockPatternUtilsFactory create(DependencyProvider module,
      Provider<Context> contextProvider) {
    return new DependencyProvider_ProvideLockPatternUtilsFactory(module, contextProvider);
  }

  public static LockPatternUtils provideLockPatternUtils(DependencyProvider instance,
      Context context) {
    return Preconditions.checkNotNullFromProvides(instance.provideLockPatternUtils(context));
  }
}
