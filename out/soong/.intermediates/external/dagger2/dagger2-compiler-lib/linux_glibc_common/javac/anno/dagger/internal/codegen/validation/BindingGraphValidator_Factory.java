package dagger.internal.codegen.validation;

import com.google.common.collect.ImmutableSet;
import dagger.internal.Factory;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.spi.BindingGraphPlugin;
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
public final class BindingGraphValidator_Factory implements Factory<BindingGraphValidator> {
  private final Provider<ImmutableSet<BindingGraphPlugin>> validationPluginsProvider;

  private final Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider;

  private final Provider<DiagnosticReporterFactory> diagnosticReporterFactoryProvider;

  private final Provider<CompilerOptions> compilerOptionsProvider;

  public BindingGraphValidator_Factory(
      Provider<ImmutableSet<BindingGraphPlugin>> validationPluginsProvider,
      Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider,
      Provider<DiagnosticReporterFactory> diagnosticReporterFactoryProvider,
      Provider<CompilerOptions> compilerOptionsProvider) {
    this.validationPluginsProvider = validationPluginsProvider;
    this.externalPluginsProvider = externalPluginsProvider;
    this.diagnosticReporterFactoryProvider = diagnosticReporterFactoryProvider;
    this.compilerOptionsProvider = compilerOptionsProvider;
  }

  @Override
  public BindingGraphValidator get() {
    return new BindingGraphValidator(validationPluginsProvider.get(), externalPluginsProvider.get(), diagnosticReporterFactoryProvider.get(), compilerOptionsProvider.get());
  }

  public static BindingGraphValidator_Factory create(
      Provider<ImmutableSet<BindingGraphPlugin>> validationPluginsProvider,
      Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider,
      Provider<DiagnosticReporterFactory> diagnosticReporterFactoryProvider,
      Provider<CompilerOptions> compilerOptionsProvider) {
    return new BindingGraphValidator_Factory(validationPluginsProvider, externalPluginsProvider, diagnosticReporterFactoryProvider, compilerOptionsProvider);
  }

  public static BindingGraphValidator newInstance(
      ImmutableSet<BindingGraphPlugin> validationPlugins,
      ImmutableSet<BindingGraphPlugin> externalPlugins, Object diagnosticReporterFactory,
      CompilerOptions compilerOptions) {
    return new BindingGraphValidator(validationPlugins, externalPlugins, (DiagnosticReporterFactory) diagnosticReporterFactory, compilerOptions);
  }
}
