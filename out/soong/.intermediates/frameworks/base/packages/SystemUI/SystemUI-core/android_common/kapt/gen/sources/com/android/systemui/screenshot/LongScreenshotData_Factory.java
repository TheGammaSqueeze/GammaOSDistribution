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
public final class LongScreenshotData_Factory implements Factory<LongScreenshotData> {
  @Override
  public LongScreenshotData get() {
    return newInstance();
  }

  public static LongScreenshotData_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static LongScreenshotData newInstance() {
    return new LongScreenshotData();
  }

  private static final class InstanceHolder {
    private static final LongScreenshotData_Factory INSTANCE = new LongScreenshotData_Factory();
  }
}
