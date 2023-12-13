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
public final class MonitoringModuleProcessingStep_Factory implements Factory<MonitoringModuleProcessingStep> {
  private final Provider<Messager> messagerProvider;

  private final Provider<MonitoringModuleGenerator> monitoringModuleGeneratorProvider;

  public MonitoringModuleProcessingStep_Factory(Provider<Messager> messagerProvider,
      Provider<MonitoringModuleGenerator> monitoringModuleGeneratorProvider) {
    this.messagerProvider = messagerProvider;
    this.monitoringModuleGeneratorProvider = monitoringModuleGeneratorProvider;
  }

  @Override
  public MonitoringModuleProcessingStep get() {
    return new MonitoringModuleProcessingStep(messagerProvider.get(), monitoringModuleGeneratorProvider.get());
  }

  public static MonitoringModuleProcessingStep_Factory create(Provider<Messager> messagerProvider,
      Provider<MonitoringModuleGenerator> monitoringModuleGeneratorProvider) {
    return new MonitoringModuleProcessingStep_Factory(messagerProvider, monitoringModuleGeneratorProvider);
  }

  public static MonitoringModuleProcessingStep newInstance(Messager messager,
      Object monitoringModuleGenerator) {
    return new MonitoringModuleProcessingStep(messager, (MonitoringModuleGenerator) monitoringModuleGenerator);
  }
}
