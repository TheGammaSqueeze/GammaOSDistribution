package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import javax.annotation.Generated;
import javax.annotation.processing.Messager;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class DiagnosticReporterFactory_Factory implements Factory<DiagnosticReporterFactory> {
  private final Provider<Messager> messagerProvider;

  private final Provider<DiagnosticMessageGenerator.Factory> diagnosticMessageGeneratorFactoryProvider;

  public DiagnosticReporterFactory_Factory(Provider<Messager> messagerProvider,
      Provider<DiagnosticMessageGenerator.Factory> diagnosticMessageGeneratorFactoryProvider) {
    this.messagerProvider = messagerProvider;
    this.diagnosticMessageGeneratorFactoryProvider = diagnosticMessageGeneratorFactoryProvider;
  }

  @Override
  public DiagnosticReporterFactory get() {
    return new DiagnosticReporterFactory(messagerProvider.get(), diagnosticMessageGeneratorFactoryProvider.get());
  }

  public static DiagnosticReporterFactory_Factory create(Provider<Messager> messagerProvider,
      Provider<DiagnosticMessageGenerator.Factory> diagnosticMessageGeneratorFactoryProvider) {
    return new DiagnosticReporterFactory_Factory(messagerProvider, diagnosticMessageGeneratorFactoryProvider);
  }

  public static DiagnosticReporterFactory newInstance(Messager messager,
      DiagnosticMessageGenerator.Factory diagnosticMessageGeneratorFactory) {
    return new DiagnosticReporterFactory(messager, diagnosticMessageGeneratorFactory);
  }
}
