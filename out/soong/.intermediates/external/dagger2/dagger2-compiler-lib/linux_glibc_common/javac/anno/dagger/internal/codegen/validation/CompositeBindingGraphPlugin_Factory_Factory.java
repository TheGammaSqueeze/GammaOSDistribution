package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import javax.annotation.Generated;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class CompositeBindingGraphPlugin_Factory_Factory implements Factory<CompositeBindingGraphPlugin.Factory> {
  private final Provider<DiagnosticMessageGenerator.Factory> messageGeneratorFactoryProvider;

  public CompositeBindingGraphPlugin_Factory_Factory(
      Provider<DiagnosticMessageGenerator.Factory> messageGeneratorFactoryProvider) {
    this.messageGeneratorFactoryProvider = messageGeneratorFactoryProvider;
  }

  @Override
  public CompositeBindingGraphPlugin.Factory get() {
    return new CompositeBindingGraphPlugin.Factory(messageGeneratorFactoryProvider.get());
  }

  public static CompositeBindingGraphPlugin_Factory_Factory create(
      Provider<DiagnosticMessageGenerator.Factory> messageGeneratorFactoryProvider) {
    return new CompositeBindingGraphPlugin_Factory_Factory(messageGeneratorFactoryProvider);
  }

  public static CompositeBindingGraphPlugin.Factory newInstance(
      DiagnosticMessageGenerator.Factory messageGeneratorFactory) {
    return new CompositeBindingGraphPlugin.Factory(messageGeneratorFactory);
  }
}
