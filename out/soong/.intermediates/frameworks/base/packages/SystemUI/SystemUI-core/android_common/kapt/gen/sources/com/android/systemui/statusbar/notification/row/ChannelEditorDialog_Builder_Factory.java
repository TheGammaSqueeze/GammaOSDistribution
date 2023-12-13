package com.android.systemui.statusbar.notification.row;

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
public final class ChannelEditorDialog_Builder_Factory implements Factory<ChannelEditorDialog.Builder> {
  @Override
  public ChannelEditorDialog.Builder get() {
    return newInstance();
  }

  public static ChannelEditorDialog_Builder_Factory create() {
    return InstanceHolder.INSTANCE;
  }

  public static ChannelEditorDialog.Builder newInstance() {
    return new ChannelEditorDialog.Builder();
  }

  private static final class InstanceHolder {
    private static final ChannelEditorDialog_Builder_Factory INSTANCE = new ChannelEditorDialog_Builder_Factory();
  }
}
