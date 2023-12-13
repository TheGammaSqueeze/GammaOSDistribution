package com.android.systemui.dagger;

import com.android.internal.appwidget.IAppWidgetService;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class FrameworkServicesModule_ProvideIAppWidgetServiceFactory implements Factory<IAppWidgetService> {
  @Override
  public IAppWidgetService get() {
    return provideIAppWidgetService();
  }

  public static FrameworkServicesModule_ProvideIAppWidgetServiceFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static IAppWidgetService provideIAppWidgetService() {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideIAppWidgetService());
  }

  private static final class InstanceHolder {
    private static final FrameworkServicesModule_ProvideIAppWidgetServiceFactory INSTANCE = new FrameworkServicesModule_ProvideIAppWidgetServiceFactory();
  }
}
