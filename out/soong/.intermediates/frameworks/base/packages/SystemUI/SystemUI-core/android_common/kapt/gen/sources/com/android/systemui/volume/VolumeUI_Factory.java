package com.android.systemui.volume;

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
public final class VolumeUI_Factory implements Factory<VolumeUI> {
  private final Provider<Context> contextProvider;

  private final Provider<VolumeDialogComponent> volumeDialogComponentProvider;

  public VolumeUI_Factory(Provider<Context> contextProvider,
      Provider<VolumeDialogComponent> volumeDialogComponentProvider) {
    this.contextProvider = contextProvider;
    this.volumeDialogComponentProvider = volumeDialogComponentProvider;
  }

  @Override
  public VolumeUI get() {
    return newInstance(contextProvider.get(), volumeDialogComponentProvider.get());
  }

  public static VolumeUI_Factory create(Provider<Context> contextProvider,
      Provider<VolumeDialogComponent> volumeDialogComponentProvider) {
    return new VolumeUI_Factory(contextProvider, volumeDialogComponentProvider);
  }

  public static VolumeUI newInstance(Context context, VolumeDialogComponent volumeDialogComponent) {
    return new VolumeUI(context, volumeDialogComponent);
  }
}
