package com.android.systemui.statusbar.notification.row;

import android.app.INotificationManager;
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
public final class ChannelEditorDialogController_Factory implements Factory<ChannelEditorDialogController> {
  private final Provider<Context> cProvider;

  private final Provider<INotificationManager> noManProvider;

  private final Provider<ChannelEditorDialog.Builder> dialogBuilderProvider;

  public ChannelEditorDialogController_Factory(Provider<Context> cProvider,
      Provider<INotificationManager> noManProvider,
      Provider<ChannelEditorDialog.Builder> dialogBuilderProvider) {
    this.cProvider = cProvider;
    this.noManProvider = noManProvider;
    this.dialogBuilderProvider = dialogBuilderProvider;
  }

  @Override
  public ChannelEditorDialogController get() {
    return newInstance(cProvider.get(), noManProvider.get(), dialogBuilderProvider.get());
  }

  public static ChannelEditorDialogController_Factory create(Provider<Context> cProvider,
      Provider<INotificationManager> noManProvider,
      Provider<ChannelEditorDialog.Builder> dialogBuilderProvider) {
    return new ChannelEditorDialogController_Factory(cProvider, noManProvider, dialogBuilderProvider);
  }

  public static ChannelEditorDialogController newInstance(Context c, INotificationManager noMan,
      ChannelEditorDialog.Builder dialogBuilder) {
    return new ChannelEditorDialogController(c, noMan, dialogBuilder);
  }
}
