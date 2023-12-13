package com.android.systemui.statusbar.phone.panelstate;

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
public final class PanelExpansionStateManager_Factory implements Factory<PanelExpansionStateManager> {
  @Override
  public PanelExpansionStateManager get() {
    return newInstance();
  }

  public static PanelExpansionStateManager_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static PanelExpansionStateManager newInstance() {
    return new PanelExpansionStateManager();
  }

  private static final class InstanceHolder {
    private static final PanelExpansionStateManager_Factory INSTANCE = new PanelExpansionStateManager_Factory();
  }
}
