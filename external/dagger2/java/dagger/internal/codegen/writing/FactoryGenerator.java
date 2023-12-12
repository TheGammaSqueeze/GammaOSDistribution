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

package dagger.internal.codegen.writing;

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.collect.Maps.transformValues;
import static com.squareup.javapoet.MethodSpec.constructorBuilder;
import static com.squareup.javapoet.MethodSpec.methodBuilder;
import static com.squareup.javapoet.TypeSpec.classBuilder;
import static dagger.internal.codegen.binding.AssistedInjectionAnnotations.assistedParameters;
import static dagger.internal.codegen.binding.ContributionBinding.FactoryCreationStrategy.DELEGATE;
import static dagger.internal.codegen.binding.ContributionBinding.FactoryCreationStrategy.SINGLETON_INSTANCE;
import static dagger.internal.codegen.binding.SourceFiles.bindingTypeElementTypeVariableNames;
import static dagger.internal.codegen.binding.SourceFiles.frameworkFieldUsages;
import static dagger.internal.codegen.binding.SourceFiles.frameworkTypeUsageStatement;
import static dagger.internal.codegen.binding.SourceFiles.generateBindingFieldsForDependencies;
import static dagger.internal.codegen.binding.SourceFiles.generatedClassNameForBinding;
import static dagger.internal.codegen.binding.SourceFiles.parameterizedGeneratedTypeNameForBinding;
import static dagger.internal.codegen.extension.DaggerStreams.toImmutableList;
import static dagger.internal.codegen.javapoet.AnnotationSpecs.Suppression.RAWTYPES;
import static dagger.internal.codegen.javapoet.AnnotationSpecs.Suppression.UNCHECKED;
import static dagger.internal.codegen.javapoet.AnnotationSpecs.suppressWarnings;
import static dagger.internal.codegen.javapoet.CodeBlocks.makeParametersCodeBlock;
import static dagger.internal.codegen.javapoet.TypeNames.factoryOf;
import static dagger.internal.codegen.writing.GwtCompatibility.gwtIncompatibleAnnotation;
import static dagger.model.BindingKind.PROVISION;
import static javax.lang.model.element.Modifier.FINAL;
import static javax.lang.model.element.Modifier.PRIVATE;
import static javax.lang.model.element.Modifier.PUBLIC;
import static javax.lang.model.element.Modifier.STATIC;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableMap;
import com.google.common.collect.Lists;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.CodeBlock;
import com.squareup.javapoet.FieldSpec;
import com.squareup.javapoet.MethodSpec;
import com.squareup.javapoet.ParameterSpec;
import com.squareup.javapoet.TypeName;
import com.squareup.javapoet.TypeSpec;
import dagger.internal.Factory;
import dagger.internal.codegen.base.SourceFileGenerator;
import dagger.internal.codegen.base.UniqueNameSet;
import dagger.internal.codegen.binding.ProvisionBinding;
import dagger.internal.codegen.compileroption.CompilerOptions;
import dagger.internal.codegen.javapoet.CodeBlocks;
import dagger.internal.codegen.kotlin.KotlinMetadataUtil;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import dagger.internal.codegen.writing.InjectionMethods.InjectionSiteMethod;
import dagger.internal.codegen.writing.InjectionMethods.ProvisionMethod;
import dagger.model.BindingKind;
import dagger.model.DependencyRequest;
import java.util.List;
import java.util.Optional;
import javax.annotation.processing.Filer;
import javax.inject.Inject;
import javax.lang.model.SourceVersion;
import javax.lang.model.element.Element;

/**
 * Generates {@link Factory} implementations from {@link ProvisionBinding} instances for {@link
 * Inject} constructors.
 */
public final class FactoryGenerator extends SourceFileGenerator<ProvisionBinding> {
  private final DaggerTypes types;
  private final CompilerOptions compilerOptions;
  private final KotlinMetadataUtil metadataUtil;

  @Inject
  FactoryGenerator(
      Filer filer,
      SourceVersion sourceVersion,
      DaggerTypes types,
      DaggerElements elements,
      CompilerOptions compilerOptions,
      KotlinMetadataUtil metadataUtil) {
    super(filer, elements, sourceVersion);
    this.types = types;
    this.compilerOptions = compilerOptions;
    this.metadataUtil = metadataUtil;
  }

  @Override
  public ClassName nameGeneratedType(ProvisionBinding binding) {
    return generatedClassNameForBinding(binding);
  }

  @Override
  public Element originatingElement(ProvisionBinding binding) {
    // we only create factories for bindings that have a binding element
    return binding.bindingElement().get();
  }

  @Override
  public Optional<TypeSpec.Builder> write(ProvisionBinding binding) {
    // We don't want to write out resolved bindings -- we want to write out the generic version.
    checkArgument(!binding.unresolved().isPresent());
    checkArgument(binding.bindingElement().isPresent());

    if (binding.factoryCreationStrategy().equals(DELEGATE)) {
      return Optional.empty();
    }

    return Optional.of(factoryBuilder(binding));
  }

  private TypeSpec.Builder factoryBuilder(ProvisionBinding binding) {
    TypeSpec.Builder factoryBuilder =
        classBuilder(nameGeneratedType(binding))
            .addModifiers(PUBLIC, FINAL)
            .addTypeVariables(bindingTypeElementTypeVariableNames(binding));

    factoryTypeName(binding).ifPresent(factoryBuilder::addSuperinterface);
    addConstructorAndFields(binding, factoryBuilder);
    factoryBuilder.addMethod(getMethod(binding));
    addCreateMethod(binding, factoryBuilder);

    factoryBuilder.addMethod(ProvisionMethod.create(binding, compilerOptions, metadataUtil));
    gwtIncompatibleAnnotation(binding).ifPresent(factoryBuilder::addAnnotation);

    return factoryBuilder;
  }

  private void addConstructorAndFields(ProvisionBinding binding, TypeSpec.Builder factoryBuilder) {
    if (binding.factoryCreationStrategy().equals(SINGLETON_INSTANCE)) {
      return;
    }
    // TODO(bcorso): Make the constructor private?
    MethodSpec.Builder constructor = constructorBuilder().addModifiers(PUBLIC);
    constructorParams(binding).forEach(
        param -> {
          constructor.addParameter(param).addStatement("this.$1N = $1N", param);
          factoryBuilder.addField(
              FieldSpec.builder(param.type, param.name, PRIVATE, FINAL).build());
        });
    factoryBuilder.addMethod(constructor.build());
  }

  private ImmutableList<ParameterSpec> constructorParams(ProvisionBinding binding) {
    ImmutableList.Builder<ParameterSpec> params = ImmutableList.builder();
    moduleParameter(binding).ifPresent(params::add);
    frameworkFields(binding).values().forEach(field -> params.add(toParameter(field)));
    return params.build();
  }

  private Optional<ParameterSpec> moduleParameter(ProvisionBinding binding) {
    if (binding.requiresModuleInstance()) {
      // TODO(bcorso, dpb): Should this use contributingModule()?
      TypeName type = TypeName.get(binding.bindingTypeElement().get().asType());
      return Optional.of(ParameterSpec.builder(type, "module").build());
    }
    return Optional.empty();
  }

  private ImmutableMap<DependencyRequest, FieldSpec> frameworkFields(ProvisionBinding binding) {
    UniqueNameSet uniqueFieldNames = new UniqueNameSet();
    // TODO(bcorso, dpb): Add a test for the case when a Factory parameter is named "module".
    moduleParameter(binding).ifPresent(module -> uniqueFieldNames.claim(module.name));
    return ImmutableMap.copyOf(
        transformValues(
            generateBindingFieldsForDependencies(binding),
            field ->
                FieldSpec.builder(
                        field.type(), uniqueFieldNames.getUniqueName(field.name()), PRIVATE, FINAL)
                    .build()));
  }

  private void addCreateMethod(ProvisionBinding binding, TypeSpec.Builder factoryBuilder) {
    // If constructing a factory for @Inject or @Provides bindings, we use a static create method
    // so that generated components can avoid having to refer to the generic types
    // of the factory.  (Otherwise they may have visibility problems referring to the types.)
    MethodSpec.Builder createMethodBuilder =
        methodBuilder("create")
            .addModifiers(PUBLIC, STATIC)
            .returns(parameterizedGeneratedTypeNameForBinding(binding))
            .addTypeVariables(bindingTypeElementTypeVariableNames(binding));

    switch (binding.factoryCreationStrategy()) {
      case SINGLETON_INSTANCE:
        FieldSpec.Builder instanceFieldBuilder =
            FieldSpec.builder(nameGeneratedType(binding), "INSTANCE", PRIVATE, STATIC, FINAL)
                .initializer("new $T()", nameGeneratedType(binding));

        if (!bindingTypeElementTypeVariableNames(binding).isEmpty()) {
          // If the factory has type parameters, ignore them in the field declaration & initializer
          instanceFieldBuilder.addAnnotation(suppressWarnings(RAWTYPES));
          createMethodBuilder.addAnnotation(suppressWarnings(UNCHECKED));
        }

        ClassName instanceHolderName = nameGeneratedType(binding).nestedClass("InstanceHolder");
        createMethodBuilder.addStatement("return $T.INSTANCE", instanceHolderName);
        factoryBuilder.addType(
            TypeSpec.classBuilder(instanceHolderName)
                .addModifiers(PRIVATE, STATIC, FINAL)
                .addField(instanceFieldBuilder.build())
                .build());
        break;
      case CLASS_CONSTRUCTOR:
        List<ParameterSpec> params = constructorParams(binding);
        createMethodBuilder.addParameters(params);
        createMethodBuilder.addStatement(
            "return new $T($L)",
            parameterizedGeneratedTypeNameForBinding(binding),
            makeParametersCodeBlock(Lists.transform(params, input -> CodeBlock.of("$N", input))));
        break;
      default:
        throw new AssertionError();
    }
    factoryBuilder.addMethod(createMethodBuilder.build());
  }

  private MethodSpec getMethod(ProvisionBinding binding) {
    TypeName providedTypeName = providedTypeName(binding);
    MethodSpec.Builder getMethod =
        methodBuilder("get")
            .addModifiers(PUBLIC)
            .returns(providedTypeName)
            .addParameters(
                // The 'get' method for an assisted injection type takes in the assisted parameters.
                assistedParameters(binding).stream()
                    .map(ParameterSpec::get)
                    .collect(toImmutableList()));

    if (factoryTypeName(binding).isPresent()) {
      getMethod.addAnnotation(Override.class);
    }

    ImmutableMap<DependencyRequest, FieldSpec> frameworkFields = frameworkFields(binding);
    CodeBlock invokeNewInstance =
        ProvisionMethod.invoke(
            binding,
            request ->
                frameworkTypeUsageStatement(
                    CodeBlock.of("$N", frameworkFields.get(request)), request.kind()),
            nameGeneratedType(binding),
            moduleParameter(binding).map(module -> CodeBlock.of("$N", module)),
            compilerOptions,
            metadataUtil);

    if (binding.kind().equals(PROVISION)) {
      binding
          .nullableType()
          .ifPresent(nullableType -> CodeBlocks.addAnnotation(getMethod, nullableType));
      getMethod.addStatement("return $L", invokeNewInstance);
    } else if (!binding.injectionSites().isEmpty()) {
      CodeBlock instance = CodeBlock.of("instance");
      getMethod
          .addStatement("$T $L = $L", providedTypeName, instance, invokeNewInstance)
          .addCode(
              InjectionSiteMethod.invokeAll(
                  binding.injectionSites(),
                  nameGeneratedType(binding),
                  instance,
                  binding.key().type(),
                  frameworkFieldUsages(binding.dependencies(), frameworkFields)::get,
                  types,
                  metadataUtil))
          .addStatement("return $L", instance);
    } else {
      getMethod.addStatement("return $L", invokeNewInstance);
    }
    return getMethod.build();
  }

  private static TypeName providedTypeName(ProvisionBinding binding) {
    return TypeName.get(binding.contributedType());
  }

  private static Optional<TypeName> factoryTypeName(ProvisionBinding binding) {
    return binding.kind() == BindingKind.ASSISTED_INJECTION
        ? Optional.empty()
        : Optional.of(factoryOf(providedTypeName(binding)));
  }

  private static ParameterSpec toParameter(FieldSpec field) {
    return ParameterSpec.builder(field.type, field.name).build();
  }
}
