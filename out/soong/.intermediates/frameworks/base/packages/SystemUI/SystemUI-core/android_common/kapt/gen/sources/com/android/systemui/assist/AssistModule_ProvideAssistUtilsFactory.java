package com.android.systemui.assist;

import android.content.Context;
import com.android.internal.app.AssistUtils;
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
public final class AssistModule_ProvideAssistUtilsFactory implements Factory<AssistUtils> {
  private final Provider<Context> contextProvider;

  public AssistModule_ProvideAssistUtilsFactory(Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public AssistUtils get() {
    return provideAssistUtils(contextProvider.get());
  }

  public static AssistModule_ProvideAssistUtilsFactory create(Provider<Context> contextProvider) {
    return new AssistModule_ProvideAssistUtilsFactory(contextProvider);
  }

  public static AssistUtils provideAssistUtils(Context context) {
    return Preconditions.checkNotNullFromProvides(AssistModule.provideAssistUtils(context));
  }
}
