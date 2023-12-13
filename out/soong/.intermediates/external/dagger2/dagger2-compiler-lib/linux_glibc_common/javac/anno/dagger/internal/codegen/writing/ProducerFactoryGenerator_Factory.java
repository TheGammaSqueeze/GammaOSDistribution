package dagger.internal.codegen.writing;

import dagger.internal.Factory;
import dagger.internal.codegen.binding.KeyFactory;
import dagger.internal.codegen.compileroption.CompilerOptions;
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
public final class ProducerFactoryGenerator_Factory implements Factory<ProducerFactoryGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  private final Provider<CompilerOptions> compilerOptionsProvider;

  private final Provider<KeyFactory> keyFactoryProvider;

  public ProducerFactoryGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<CompilerOptions> compilerOptionsProvider, Provider<KeyFactory> keyFactoryProvider) {
    this.filerProvider = filerProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
    this.compilerOptionsProvider = compilerOptionsProvider;
    this.keyFactoryProvider = keyFactoryProvider;
  }

  @Override
  public ProducerFactoryGenerator get() {
    return new ProducerFactoryGenerator(filerProvider.get(), elementsProvider.get(), sourceVersionProvider.get(), compilerOptionsProvider.get(), keyFactoryProvider.get());
  }

  public static ProducerFactoryGenerator_Factory create(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<CompilerOptions> compilerOptionsProvider, Provider<KeyFactory> keyFactoryProvider) {
    return new ProducerFactoryGenerator_Factory(filerProvider, elementsProvider, sourceVersionProvider, compilerOptionsProvider, keyFactoryProvider);
  }

  public static ProducerFactoryGenerator newInstance(Filer filer, DaggerElements elements,
      SourceVersion sourceVersion, CompilerOptions compilerOptions, KeyFactory keyFactory) {
    return new ProducerFactoryGenerator(filer, elements, sourceVersion, compilerOptions, keyFactory);
  }
}
