package com.android.systemui.qs.dagger;

import android.view.View;
import com.android.systemui.qs.QSPanel;
import dagger.internal.Factory;
import dagger.internal.Preconditions;
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
public final class QSFragmentModule_ProvideQSPanelFactory implements Factory<QSPanel> {
  private final Provider<View> viewProvider;

  public QSFragmentModule_ProvideQSPanelFactory(Provider<View> viewProvider) {
    this.viewProvider = viewProvider;
  }

  @Override
  public QSPanel get() {
    return provideQSPanel(viewProvider.get());
  }

  public static QSFragmentModule_ProvideQSPanelFactory create(Provider<View> viewProvider) {
    return new QSFragmentModule_ProvideQSPanelFactory(viewProvider);
  }

  public static QSPanel provideQSPanel(View view) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.provideQSPanel(view));
  }
}
