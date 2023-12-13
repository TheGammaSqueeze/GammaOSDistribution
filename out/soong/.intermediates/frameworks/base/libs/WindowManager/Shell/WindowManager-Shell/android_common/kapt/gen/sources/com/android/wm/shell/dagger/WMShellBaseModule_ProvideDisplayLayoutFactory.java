package com.android.wm.shell.dagger;

import com.android.wm.shell.common.DisplayLayout;
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
public final class WMShellBaseModule_ProvideDisplayLayoutFactory implements Factory<DisplayLayout> {
  @Override
  public DisplayLayout get() {
    return provideDisplayLayout();
  }

  public static WMShellBaseModule_ProvideDisplayLayoutFactory create() {
    return InstanceHolder.INSTANCE;
  }

  public static DisplayLayout provideDisplayLayout() {
    return Preconditions.checkNotNullFromProvides(WMShellBaseModule.provideDisplayLayout());
  }

  private static final class InstanceHolder {
    private static final WMShellBaseModule_ProvideDisplayLayoutFactory INSTANCE = new WMShellBaseModule_ProvideDisplayLayoutFactory();
  }
}
