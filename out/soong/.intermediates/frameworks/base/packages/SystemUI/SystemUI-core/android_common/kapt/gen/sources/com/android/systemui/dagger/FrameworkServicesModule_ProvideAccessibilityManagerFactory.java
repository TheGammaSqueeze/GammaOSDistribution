package com.android.systemui.dagger;

import android.content.Context;
import android.view.accessibility.AccessibilityManager;
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
public final class FrameworkServicesModule_ProvideAccessibilityManagerFactory implements Factory<AccessibilityManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideAccessibilityManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AccessibilityManager get() {
    return provideAccessibilityManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideAccessibilityManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideAccessibilityManagerFactory(contextProvider);
  }

  public static AccessibilityManager provideAccessibilityManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideAccessibilityManager(context));
  }
}
