package dagger.internal.codegen.writing;

import dagger.internal.Factory;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
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
public final class ModuleProxies_ModuleConstructorProxyGenerator_Factory implements Factory<ModuleProxies.ModuleConstructorProxyGenerator> {
  private final Provider<Filer> filerProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<SourceVersion> sourceVersionProvider;

  private final Provider<ModuleProxies> moduleProxiesProvider;

  private final Provider<KotlinMetadataUtil> metadataUtilProvider;

  public ModuleProxies_ModuleConstructorProxyGenerator_Factory(Provider<Filer> filerProvider,
      Provider<DaggerElements> elementsProvider, Provider<SourceVersion> sourceVersionProvider,
      Provider<ModuleProxies> moduleProxiesProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    this.filerProvider = filerProvider;
    this.elementsProvider = elementsProvider;
    this.sourceVersionProvider = sourceVersionProvider;
    this.moduleProxiesProvider = moduleProxiesProvider;
    this.metadataUtilProvider = metadataUtilProvider;
  }

  @Override
  public ModuleProxies.ModuleConstructorProxyGenerator get() {
    return new ModuleProxies.ModuleConstructorProxyGenerator(filerProvider.get(), elementsProvider.get(), sourceVersionProvider.get(), moduleProxiesProvider.get(), metadataUtilProvider.get());
  }

  public static ModuleProxies_ModuleConstructorProxyGenerator_Factory create(
      Provider<Filer> filerProvider, Provider<DaggerElements> elementsProvider,
      Provider<SourceVersion> sourceVersionProvider, Provider<ModuleProxies> moduleProxiesProvider,
      Provider<KotlinMetadataUtil> metadataUtilProvider) {
    return new ModuleProxies_ModuleConstructorProxyGenerator_Factory(filerProvider, elementsProvider, sourceVersionProvider, moduleProxiesProvider, metadataUtilProvider);
  }

  public static ModuleProxies.ModuleConstructorProxyGenerator newInstance(Filer filer,
      DaggerElements elements, SourceVersion sourceVersion, ModuleProxies moduleProxies,
      KotlinMetadataUtil metadataUtil) {
    return new ModuleProxies.ModuleConstructorProxyGenerator(filer, elements, sourceVersion, moduleProxies, metadataUtil);
  }
}
