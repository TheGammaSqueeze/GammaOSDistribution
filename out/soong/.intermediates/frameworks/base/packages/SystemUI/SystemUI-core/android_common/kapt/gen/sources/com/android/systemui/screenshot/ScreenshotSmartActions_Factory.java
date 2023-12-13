package com.android.systemui.screenshot;

import dagger.internal.Factory;
import javax.annotation.processing.Generated;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class ScreenshotSmartActions_Factory implements Factory<ScreenshotSmartActions> {
  @Override
  public ScreenshotSmartActions get() {
    return newInstance();
  }

  public static ScreenshotSmartActions_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ScreenshotSmartActions newInstance() {
    return new ScreenshotSmartActions();
  }

  private static final class InstanceHolder {
    private static final ScreenshotSmartActions_Factory INSTANCE = new ScreenshotSmartActions_Factory();
  }
}
