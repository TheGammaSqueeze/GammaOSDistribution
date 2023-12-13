package com.android.systemui.statusbar.dagger;

import android.content.Context;
import com.android.systemui.statusbar.CommandQueue;
import com.android.systemui.statusbar.commandline.CommandRegistry;
import com.android.systemui.tracing.ProtoTracer;
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
public final class StatusBarDependenciesModule_ProvideCommandQueueFactory implements Factory<CommandQueue> {
  private final Provider<Context> contextProvider;

  private final Provider<ProtoTracer> protoTracerProvider;

  private final Provider<CommandRegistry> registryProvider;

  public StatusBarDependenciesModule_ProvideCommandQueueFactory(Provider<Context> contextProvider,
      Provider<ProtoTracer> protoTracerProvider, Provider<CommandRegistry> registryProvider) {
    this.contextProvider = contextProvider;
    this.protoTracerProvider = protoTracerProvider;
    this.registryProvider = registryProvider;
  }

  @Override
  public CommandQueue get() {
    return provideCommandQueue(contextProvider.get(), protoTracerProvider.get(), registryProvider.get());
  }

  public static StatusBarDependenciesModule_ProvideCommandQueueFactory create(
      Provider<Context> contextProvider, Provider<ProtoTracer> protoTracerProvider,
      Provider<CommandRegistry> registryProvider) {
    return new StatusBarDependenciesModule_ProvideCommandQueueFactory(contextProvider, protoTracerProvider, registryProvider);
  }

  public static CommandQueue provideCommandQueue(Context context, ProtoTracer protoTracer,
      CommandRegistry registry) {
    return Preconditions.checkNotNullFromProvides(StatusBarDependenciesModule.provideCommandQueue(context, protoTracer, registry));
  }
}
