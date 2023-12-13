package com.android.systemui.statusbar.notification.stack;

import android.content.Context;
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
public final class AmbientState_Factory implements Factory<AmbientState> {
  private final Provider<Context> contextProvider;

  private final Provider<StackScrollAlgorithm.SectionProvider> sectionProvider;

  private final Provider<StackScrollAlgorithm.BypassController> bypassControllerProvider;

  public AmbientState_Factory(Provider<Context> contextProvider,
      Provider<StackScrollAlgorithm.SectionProvider> sectionProvider,
      Provider<StackScrollAlgorithm.BypassController> bypassControllerProvider) {
    this.contextProvider = contextProvider;
    this.sectionProvider = sectionProvider;
    this.bypassControllerProvider = bypassControllerProvider;
  }

  @Override
  public AmbientState get() {
    return newInstance(contextProvider.get(), sectionProvider.get(), bypassControllerProvider.get());
  }

  public static AmbientState_Factory create(Provider<Context> contextProvider,
      Provider<StackScrollAlgorithm.SectionProvider> sectionProvider,
      Provider<StackScrollAlgorithm.BypassController> bypassControllerProvider) {
    return new AmbientState_Factory(contextProvider, sectionProvider, bypassControllerProvider);
  }

  public static AmbientState newInstance(Context context,
      StackScrollAlgorithm.SectionProvider sectionProvider,
      StackScrollAlgorithm.BypassController bypassController) {
    return new AmbientState(context, sectionProvider, bypassController);
  }
}
