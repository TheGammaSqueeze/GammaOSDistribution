package com.android.systemui.qs;

import android.content.Context;
import com.android.systemui.qs.customize.QSCustomizerController;
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
public final class QSTileRevealController_Factory_Factory implements Factory<QSTileRevealController.Factory> {
  private final Provider<Context> contextProvider;

  private final Provider<QSCustomizerController> qsCustomizerControllerProvider;

  public QSTileRevealController_Factory_Factory(Provider<Context> contextProvider,
      Provider<QSCustomizerController> qsCustomizerControllerProvider) {
    this.contextProvider = contextProvider;
    this.qsCustomizerControllerProvider = qsCustomizerControllerProvider;
  }

  @Override
  public QSTileRevealController.Factory get() {
    return newInstance(contextProvider.get(), qsCustomizerControllerProvider.get());
  }

  public static QSTileRevealController_Factory_Factory create(Provider<Context> contextProvider,
      Provider<QSCustomizerController> qsCustomizerControllerProvider) {
    return new QSTileRevealController_Factory_Factory(contextProvider, qsCustomizerControllerProvider);
  }

  public static QSTileRevealController.Factory newInstance(Context context,
      QSCustomizerController qsCustomizerController) {
    return new QSTileRevealController.Factory(context, qsCustomizerController);
  }
}
