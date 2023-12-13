package com.android.systemui.dagger;

import android.content.Context;
import android.telephony.SubscriptionManager;
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
public final class FrameworkServicesModule_ProvideSubcriptionManagerFactory implements Factory<SubscriptionManager> {
  private final Provider<Context> contextProvider;

  public FrameworkServicesModule_ProvideSubcriptionManagerFactory(
      Provider<Context> contextProvider) {
    this.contextProvider = contextProvider;
  }

  @Override
  public SubscriptionManager get() {
    return provideSubcriptionManager(contextProvider.get());
  }

  public static FrameworkServicesModule_ProvideSubcriptionManagerFactory create(
      Provider<Context> contextProvider) {
    return new FrameworkServicesModule_ProvideSubcriptionManagerFactory(contextProvider);
  }

  public static SubscriptionManager provideSubcriptionManager(Context context) {
    return Preconditions.checkNotNullFromProvides(FrameworkServicesModule.provideSubcriptionManager(context));
  }
}
