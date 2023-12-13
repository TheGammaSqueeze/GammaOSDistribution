package com.android.systemui.dagger;

import android.content.Context;
import android.content.pm.ShortcutManager;
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
public final class FrameworkServicesModule_ProvideShortcutManagerFactory implements Factory<ShortcutManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideShortcutManagerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public ShortcutManager get() {
    return provideShortcutManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideShortcutManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideShortcutManagerFactory(contextProvider);
  }

  public static ShortcutManager provideShortcutManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideShortcutManager(context));
  }
}
