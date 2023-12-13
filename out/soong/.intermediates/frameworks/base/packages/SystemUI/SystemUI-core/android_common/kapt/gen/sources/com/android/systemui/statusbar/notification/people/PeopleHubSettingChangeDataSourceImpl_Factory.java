package com.android.systemui.statusbar.notification.people;

import android.content.Context;
import android.os.Handler;
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
public final class PeopleHubSettingChangeDataSourceImpl_Factory implements Factory<PeopleHubSettingChangeDataSourceImpl> {
  private final Provider<Handler> handlerProvider;

  private final Provider<Context> contextProvider;

  public PeopleHubSettingChangeDataSourceImpl_Factory(Provider<Handler> handlerProvider,
      Provider<Context> contextProvider) {
    this.handlerProvider = handlerProvider;
    this.contextProvider = contextProvider;
  }

  @Override
  public PeopleHubSettingChangeDataSourceImpl get() {
    return newInstance(handlerProvider.get(), contextProvider.get());
  }

  public static PeopleHubSettingChangeDataSourceImpl_Factory create(
      Provider<Handler> handlerProvider, Provider<Context> contextProvider) {
    return new PeopleHubSettingChangeDataSourceImpl_Factory(handlerProvider, contextProvider);
  }

  public static PeopleHubSettingChangeDataSourceImpl newInstance(Handler handler, Context context) {
    return new PeopleHubSettingChangeDataSourceImpl(handler, context);
  }
}
