package com.android.systemui.qs.dagger;

import android.content.Context;
import android.view.LayoutInflater;
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
public final class QSFragmentModule_ProvideThemedLayoutInflaterFactory implements Factory<LayoutInflater> {
  private final Provider<Context> contextProvider;

  public QSFragmentModule_ProvideThemedLayoutInflaterFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public LayoutInflater get() {
    return provideThemedLayoutInflater(contextProvider.get());
  }

  public static QSFragmentModule_ProvideThemedLayoutInflaterFactory create(
      Provider<Context> contextProvider) {
    return new QSFragmentModule_ProvideThemedLayoutInflaterFactory(contextProvider);
  }

  public static LayoutInflater provideThemedLayoutInflater(Context context) {
    return Preconditions.checkNotNullFromProvides(QSFragmentModule.provideThemedLayoutInflater(context));
  }
}
