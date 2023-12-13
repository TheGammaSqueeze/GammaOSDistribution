package dagger.internal.codegen.validation;

import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
import javax.annotation.Generated;
import javax.annotation.processing.Filer;
import javax.inject.Provider;
import javax.lang.model.SourceVersion;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class MonitoringModuleGenerator_Factory implements Factory<MonitoringModuleGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  public MonitoringModuleGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider) {
    this.filerProvider = filerProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
  }

  @Override
  public MonitoringModuleGenerator get() {
    return new MonitoringModuleGenerator(filerProvider.get(), elementsProvider.get(), sourceVersionProvider.get());
  }

  public static MonitoringModuleGenerator_Factory create(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider) {
    return new MonitoringModuleGenerator_Factory(filerProvider, elementsProvider, sourceVersionProvider);
  }

  public static MonitoringModuleGenerator newInstance(Filer filer, DaggerElements elements,
      SourceVersion sourceVersion) {
    return new MonitoringModuleGenerator(filer, elements, sourceVersion);
  }
}
