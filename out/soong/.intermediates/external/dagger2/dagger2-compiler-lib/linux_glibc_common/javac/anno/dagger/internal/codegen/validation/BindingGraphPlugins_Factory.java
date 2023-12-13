package dagger.internal.codegen.validation;

import com.google.common.collect.ImmutableSet;
import dagger.internal.Factory;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.spi.BindingGraphPlugin;
import java.util.Map;
import javax.annotation.Generated;
import javax.annotation.processing.Filer;
import javax.inject.Provider;

@Generated(
    value = "dagger.internal.codegen.ComponentProcessor",
    comments = "https://dagger.dev"
)
@SuppressWarnings({
    "unchecked",
    "rawtypes"
})
public final class BindingGraphPlugins_Factory implements Factory<BindingGraphPlugins> {
  private final Provider<ImmutableSet<BindingGraphPlugin>> validationPluginsProvider;

  private final Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider;

  private final Provider<Filer> filerProvider;

  private final Provider<DaggerTypes> typesProvider;

  private final Provider<DaggerElements> elementsProvider;

  private final Provider<Map<String, String>> processingOptionsProvider;

  public BindingGraphPlugins_Factory(
      Provider<ImmutableSet<BindingGraphPlugin>> validationPluginsProvider,
      Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider,
      Provider<Filer> filerProvider, Provider<DaggerTypes> typesProvider,
      Provider<DaggerElements> elementsProvider,
      Provider<Map<String, String>> processingOptionsProvider) {
    this.validationPluginsProvider = validationPluginsProvider;
    this.externalPluginsProvider = externalPluginsProvider;
    this.filerProvider = filerProvider;
    this.typesProvider = typesProvider;
    this.elementsProvider = elementsProvider;
    this.processingOptionsProvider = processingOptionsProvider;
  }

  @Override
  public BindingGraphPlugins get() {
    return new BindingGraphPlugins(validationPluginsProvider.get(), externalPluginsProvider.get(), filerProvider.get(), typesProvider.get(), elementsProvider.get(), processingOptionsProvider.get());
  }

  public static BindingGraphPlugins_Factory create(
      Provider<ImmutableSet<BindingGraphPlugin>> validationPluginsProvider,
      Provider<ImmutableSet<BindingGraphPlugin>> externalPluginsProvider,
      Provider<Filer> filerProvider, Provider<DaggerTypes> typesProvider,
      Provider<DaggerElements> elementsProvider,
      Provider<Map<String, String>> processingOptionsProvider) {
    return new BindingGraphPlugins_Factory(validationPluginsProvider, externalPluginsProvider, filerProvider, typesProvider, elementsProvider, processingOptionsProvider);
  }

  public static BindingGraphPlugins newInstance(ImmutableSet<BindingGraphPlugin> validationPlugins,
      ImmutableSet<BindingGraphPlugin> externalPlugins, Filer filer, DaggerTypes types,
      DaggerElements elements, Map<String, String> processingOptions) {
    return new BindingGraphPlugins(validationPlugins, externalPlugins, filer, types, elements, processingOptions);
  }
}
