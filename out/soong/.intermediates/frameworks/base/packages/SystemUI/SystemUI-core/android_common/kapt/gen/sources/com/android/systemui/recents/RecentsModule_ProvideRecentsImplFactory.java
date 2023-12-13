package com.android.systemui.recents;

import android.content.Context;
import com.android.systemui.dagger.ContextComponentHelper;
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
public final class RecentsModule_ProvideRecentsImplFactory implements Factory<RecentsImplementation> {
  private final Provider<Context> contextProvider;

  private final Provider<ContextComponentHelper> componentHelperProvider;

  public RecentsModule_ProvideRecentsImplFactory(Provider<Context> contextProvider,
      Provider<ContextComponentHelper> componentHelperProvider) {
    this.contextProvider = contextProvider;
    this.componentHelperProvider = componentHelperProvider;
  }

  @Override
  public RecentsImplementation get() {
    return provideRecentsImpl(contextProvider.get(), componentHelperProvider.get());
  }

  public static RecentsModule_ProvideRecentsImplFactory create(Provider<Context> contextProvider,
      Provider<ContextComponentHelper> componentHelperProvider) {
    return new RecentsModule_ProvideRecentsImplFactory(contextProvider, componentHelperProvider);
  }

  public static RecentsImplementation provideRecentsImpl(Context context,
      ContextComponentHelper componentHelper) {
    return Preconditions.checkNotNullFromProvides(RecentsModule.provideRecentsImpl(context, componentHelper));
  }
}
