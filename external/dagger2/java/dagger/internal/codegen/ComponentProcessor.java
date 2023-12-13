/*
 * Copyright (C) 2014 The Dagger Authors.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package dagger.internal.codegen;

import static net.ltgt.gradle.incap.IncrementalAnnotationProcessorType.ISOLATING;

import com.google.auto.common.BasicAnnotationProcessor;
import com.google.auto.service.AutoService;
import com.google.common.annotations.VisibleForTesting;
import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.collect.Sets;
import com.google.errorprone.annotations.CheckReturnValue;
import dagger.BindsInstance;
import dagger.Component;
import dagger.Module;
import dagger.Provides;
import dagger.internal.codegen.SpiModule.TestingPlugins;
import dagger.internal.codegen.base.ClearableCache;
import dagger.internal.codegen.base.SourceFileGenerationException;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.binding.InjectBindingRegistry;
import dagger.internal.codegen.binding.MembersInjectionBinding;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.bindinggraphvalidation.BindingGraphValidationModule;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.compileroption.ProcessingEnvironmentCompilerOptions;
import dagger.internal.codegen.componentgenerator.ComponentGeneratorModule;
import dagger.internal.codegen.validation.BindingGraphPlugins;
import dagger.internal.codegen.validation.BindingMethodProcessingStep;
import dagger.internal.codegen.validation.BindingMethodValidatorsModule;
import dagger.internal.codegen.validation.BindsInstanceProcessingStep;
import dagger.internal.codegen.validation.InjectBindingRegistryModule;
import dagger.internal.codegen.validation.MonitoringModuleProcessingStep;
import dagger.internal.codegen.validation.MultibindingAnnotationsProcessingStep;
import dagger.spi.BindingGraphPlugin;
import java.util.Arrays;
import java.util.Optional;
import java.util.Set;
import javax.annotation.processing.ProcessingEnvironment;
import javax.annotation.processing.Processor;
import javax.annotation.processing.RoundEnvironment;
import javax.inject.Inject;
import javax.inject.Singleton;
import javax.lang.model.SourceVersion;
import net.ltgt.gradle.incap.IncrementalAnnotationProcessor;

/**
 * The annotation processor responsible for generating the classes that drive the Dagger 2.0
 * implementation.
 *
 * <p>TODO(gak): give this some better documentation
 */
@IncrementalAnnotationProcessor(ISOLATING)
@AutoService(Processor.class)
public class ComponentProcessor extends BasicAnnotationProcessor {
  private final Optional<ImmutableSet<BindingGraphPlugin>> testingPlugins;

  @Inject InjectBindingRegistry injectBindingRegistry;
  @Inject SourceFileGenerator<ProvisionBinding> factoryGenerator;
  @Inject SourceFileGenerator<MembersInjectionBinding> membersInjectorGenerator;
  @Inject ImmutableList<ProcessingStep> processingSteps;
  @Inject BindingGraphPlugins bindingGraphPlugins;
  @Inject Set<ClearableCache> clearableCaches;

  public ComponentProcessor() {
    this.testingPlugins = Optional.empty();
  }

  private ComponentProcessor(Iterable<BindingGraphPlugin> testingPlugins) {
    this.testingPlugins = Optional.of(ImmutableSet.copyOf(testingPlugins));
  }

  /**
   * Creates a component processor that uses given {@link BindingGraphPlugin}s instead of loading
   * them from a {@link java.util.ServiceLoader}.
   */
  @VisibleForTesting
  public static ComponentProcessor forTesting(BindingGraphPlugin... testingPlugins) {
    return forTesting(Arrays.asList(testingPlugins));
  }

  /**
   * Creates a component processor that uses given {@link BindingGraphPlugin}s instead of loading
   * them from a {@link java.util.ServiceLoader}.
   */
  @VisibleForTesting
  public static ComponentProcessor forTesting(Iterable<BindingGraphPlugin> testingPlugins) {
    return new ComponentProcessor(testingPlugins);
  }

  @Override
  public SourceVersion getSupportedSourceVersion() {
    return SourceVersion.latestSupported();
  }

  @Override
  public Set<String> getSupportedOptions() {
    return Sets.union(
            ProcessingEnvironmentCompilerOptions.supportedOptions(),
            bindingGraphPlugins.allSupportedOptions())
        .immutableCopy();
  }

  @Override
  protected Iterable<? extends ProcessingStep> initSteps() {
    ProcessorComponent.factory().create(processingEnv, testingPlugins).inject(this);

    bindingGraphPlugins.initializePlugins();

    return processingSteps;
  }

  @Singleton
  @Component(
      modules = {
        BindingGraphValidationModule.class,
        BindingMethodValidatorsModule.class,
        ComponentGeneratorModule.class,
        InjectBindingRegistryModule.class,
        ProcessingEnvironmentModule.class,
        ProcessingRoundCacheModule.class,
        ProcessingStepsModule.class,
        SourceFileGeneratorsModule.class,
        SpiModule.class
      })
  interface ProcessorComponent {
    void inject(ComponentProcessor processor);

    static Factory factory() {
      return DaggerComponentProcessor_ProcessorComponent.factory();
    }

    @Component.Factory
    interface Factory {
      @CheckReturnValue
      ProcessorComponent create(
          @BindsInstance ProcessingEnvironment processingEnv,
          @BindsInstance @TestingPlugins Optional<ImmutableSet<BindingGraphPlugin>> testingPlugins);
    }
  }

  @Module
  interface ProcessingStepsModule {
    @Provides
    static ImmutableList<ProcessingStep> processingSteps(
        MapKeyProcessingStep mapKeyProcessingStep,
        InjectProcessingStep injectProcessingStep,
        AssistedInjectProcessingStep assistedInjectProcessingStep,
        AssistedFactoryProcessingStep assistedFactoryProcessingStep,
        AssistedProcessingStep assistedProcessingStep,
        MonitoringModuleProcessingStep monitoringModuleProcessingStep,
        MultibindingAnnotationsProcessingStep multibindingAnnotationsProcessingStep,
        BindsInstanceProcessingStep bindsInstanceProcessingStep,
        ModuleProcessingStep moduleProcessingStep,
        ComponentProcessingStep componentProcessingStep,
        ComponentHjarProcessingStep componentHjarProcessingStep,
        BindingMethodProcessingStep bindingMethodProcessingStep,
        CompilerOptions compilerOptions) {
      return ImmutableList.of(
          mapKeyProcessingStep,
          injectProcessingStep,
          assistedInjectProcessingStep,
          assistedFactoryProcessingStep,
          assistedProcessingStep,
          monitoringModuleProcessingStep,
          multibindingAnnotationsProcessingStep,
          bindsInstanceProcessingStep,
          moduleProcessingStep,
          compilerOptions.headerCompilation()
              ? componentHjarProcessingStep
              : componentProcessingStep,
          bindingMethodProcessingStep);
    }
  }

  @Override
  protected void postRound(RoundEnvironment roundEnv) {
    if (!roundEnv.processingOver()) {
      try {
        injectBindingRegistry.generateSourcesForRequiredBindings(
            factoryGenerator, membersInjectorGenerator);
      } catch (SourceFileGenerationException e) {
        e.printMessageTo(processingEnv.getMessager());
      }
    }
    clearableCaches.forEach(ClearableCache::clearCache);
  }
}
