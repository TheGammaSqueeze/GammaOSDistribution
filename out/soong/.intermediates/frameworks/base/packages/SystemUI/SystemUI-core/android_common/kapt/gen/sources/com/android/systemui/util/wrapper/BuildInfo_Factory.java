package com.android.systemui.util.wrapper;

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
public final class BuildInfo_Factory implements Factory<BuildInfo> {
  @Override
  public BuildInfo get() {
    return newInstance();
  }

  public static BuildInfo_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static BuildInfo newInstance() {
    return new BuildInfo();
  }

  private static final class InstanceHolder {
    private static final BuildInfo_Factory INSTANCE = new BuildInfo_Factory();
  }
}
