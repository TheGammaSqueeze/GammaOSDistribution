package com.android.systemui.qs.dagger;

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
public final class QSFragmentModule_ProvidesQSUsingMediaPlayerFactory implements Factory<Boolean> {
  private final Provider<Context> contextProvider;

  public QSFragmentModule_ProvidesQSUsingMediaPlayerFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public Boolean get() {
    return providesQSUsingMediaPlayer(contextProvider.get());
  }

  public static QSFragmentModule_ProvidesQSUsingMediaPlayerFactory create(
      Provider<Context> contextProvider) {
    return new QSFragmentModule_ProvidesQSUsingMediaPlayerFactory(contextProvider);
  }

  public static boolean providesQSUsingMediaPlayer(Context context) {
    return QSFragmentModule.providesQSUsingMediaPlayer(context);
  }
}
