package com.android.systemui.statusbar.phone.dagger;

import android.view.View;
import com.android.systemui.statusbar.phone.StatusIconContainer;
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
public final class StatusBarViewModule_ProvidesStatusIconContainerFactory implements Factory<StatusIconContainer> {
  private final Provider<View> headerProvider;

  public StatusBarViewModule_ProvidesStatusIconContainerFactory(Provider<View> headerProvider) {
    this.headerProvider = headerProvider;
  }

  @Override
  public StatusIconContainer get() {
    return providesStatusIconContainer(headerProvider.get());
  }

  public static StatusBarViewModule_ProvidesStatusIconContainerFactory create(
      Provider<View> headerProvider) {
    return new StatusBarViewModule_ProvidesStatusIconContainerFactory(headerProvider);
  }

  public static StatusIconContainer providesStatusIconContainer(View header) {
    return Preconditions.checkNotNullFromProvides(StatusBarViewModule.providesStatusIconContainer(header));
  }
}
