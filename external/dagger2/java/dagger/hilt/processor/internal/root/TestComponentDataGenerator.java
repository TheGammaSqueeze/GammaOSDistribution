/*
 * Copyright (C) 2020 The Dagger Authors.
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

package dagger.hilt.processor.internal.root;

import static dagger.internal.codegen.extension.DaggerStreams.toImmutableSet;
import static java.util.stream.Collectors.joining;
import static javax.lang.model.element.Modifier.FINAL;
import static javax.lang.model.element.Modifier.PRIVATE;
import static javax.lang.model.element.Modifier.PUBLIC;
import static javax.lang.model.element.Modifier.STATIC;
import static javax.lang.model.util.ElementFilter.constructorsIn;

import com.google.common.collect.ImmutableSet;
import com.squareup.javapoet.AnnotationSpec;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.CodeBlock;
import com.squareup.javapoet.JavaFile;
import com.squareup.javapoet.MethodSpec;
import com.squareup.javapoet.TypeSpec;
import dagger.hilt.processor.internal.ClassNames;
import dagger.hilt.processor.internal.ComponentNames;
import dagger.hilt.processor.internal.Processors;
import java.io.IOException;
import java.util.List;
import javax.annotation.processing.ProcessingEnvironment;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;

/** Generates an implementation of {@link dagger.hilt.android.internal.TestComponentData}. */
public final class TestComponentDataGenerator {
  private final ProcessingEnvironment processingEnv;
  private final RootMetadata rootMetadata;
  private final ClassName name;

  public TestComponentDataGenerator(
      ProcessingEnvironment processingEnv,
      RootMetadata rootMetadata) {
    this.processingEnv = processingEnv;
    this.rootMetadata = rootMetadata;
    this.name =
        Processors.append(
            Processors.getEnclosedClassName(rootMetadata.testRootMetadata().testName()),
            "_ComponentDataHolder");
  }

  /**
   *
   *
   * <pre><code>{@code
   * public final class FooTest_ComponentDataHolder {
   *   public static TestComponentData get() {
   *     return new TestComponentData(
   *         false, // waitForBindValue
   *         testInstance -> injectInternal(($1T) testInstance),
   *         Arrays.asList(FooTest.TestModule.class, ...),
   *         modules ->
   *             DaggerFooTest_ApplicationComponent.builder()
   *                 .applicationContextModule(
   *                     new ApplicationContextModule(ApplicationProvider.getApplicationContext()))
   *                 .testModule((FooTest.TestModule) modules.get(FooTest.TestModule.class))
   *                 .testModule(modules.containsKey(FooTest.TestModule.class)
   *                   ? (FooTest.TestModule) modules.get(FooTest.TestModule.class)
   *                   : ((TestInstace) testInstance).new TestModule())
   *                 .build());
   *   }
   * }
   * }</code></pre>
   */
  public void generate() throws IOException {
    TypeSpec.Builder generator =
        TypeSpec.classBuilder(name)
            .addModifiers(PUBLIC, FINAL)
            .addMethod(MethodSpec.constructorBuilder().addModifiers(PRIVATE).build())
            .addMethod(getMethod())
            .addMethod(getTestInjectInternalMethod());

    Processors.addGeneratedAnnotation(
        generator, processingEnv, ClassNames.ROOT_PROCESSOR.toString());

    JavaFile.builder(rootMetadata.testRootMetadata().testName().packageName(), generator.build())
        .build()
        .writeTo(processingEnv.getFiler());
  }

  private MethodSpec getMethod() {
    TypeElement testElement = rootMetadata.testRootMetadata().testElement();
    ClassName component =
        ComponentNames.generatedComponent(
            ClassName.get(testElement), ClassNames.SINGLETON_COMPONENT);
    ImmutableSet<TypeElement> daggerRequiredModules =
        rootMetadata.modulesThatDaggerCannotConstruct(ClassNames.SINGLETON_COMPONENT);
    ImmutableSet<TypeElement> hiltRequiredModules =
        daggerRequiredModules.stream()
            .filter(module -> !canBeConstructedByHilt(module, testElement))
            .collect(toImmutableSet());

    return MethodSpec.methodBuilder("get")
        .addModifiers(PUBLIC, STATIC)
        .returns(ClassNames.TEST_COMPONENT_DATA)
        .addStatement(
            "return new $T($L, $L, $L, $L, $L)",
            ClassNames.TEST_COMPONENT_DATA,
            rootMetadata.waitForBindValue(),
            CodeBlock.of("testInstance -> injectInternal(($1T) testInstance)", testElement),
            getElementsListed(daggerRequiredModules),
            getElementsListed(hiltRequiredModules),
            CodeBlock.of(
                "(modules, testInstance, autoAddModuleEnabled) -> $T.builder()\n"
                    + ".applicationContextModule(new $T($T.getApplicationContext()))\n"
                    + "$L"
                    + ".build()",
                Processors.prepend(Processors.getEnclosedClassName(component), "Dagger"),
                ClassNames.APPLICATION_CONTEXT_MODULE,
                ClassNames.APPLICATION_PROVIDER,
                daggerRequiredModules.stream()
                    .map(module -> getAddModuleStatement(module, testElement))
                    .collect(joining("\n"))))
        .build();
  }

  /**
   *
   *
   * <pre><code>
   * .testModule(modules.get(FooTest.TestModule.class))
   * </code></pre>
   *
   * <pre><code>
   * .testModule(autoAddModuleEnabled
   *     ? ((FooTest) testInstance).new TestModule()
   *     : (FooTest.TestModule) modules.get(FooTest.TestModule.class))
   * </code></pre>
   */
  private static String getAddModuleStatement(TypeElement module, TypeElement testElement) {
    ClassName className = ClassName.get(module);
    return canBeConstructedByHilt(module, testElement)
        ? CodeBlock.of(
                ".$1L(autoAddModuleEnabled\n"
                    // testInstance can never be null if we reach here, because this flag can be
                    // turned on only when testInstance is not null
                    + "    ? (($3T) testInstance).new $4L()\n"
                    + "    : ($2T) modules.get($2T.class))",
                Processors.upperToLowerCamel(className.simpleName()),
                className,
                className.enclosingClassName(),
                className.simpleName())
            .toString()
        : CodeBlock.of(
                ".$1L(($2T) modules.get($2T.class))",
                Processors.upperToLowerCamel(className.simpleName()),
                className)
            .toString();
  }

  private static boolean canBeConstructedByHilt(TypeElement module, TypeElement testElement) {
    return hasOnlyAccessibleNoArgConstructor(module)
        && module.getEnclosingElement().equals(testElement);
  }

  private static boolean hasOnlyAccessibleNoArgConstructor(TypeElement module) {
    List<ExecutableElement> declaredConstructors = constructorsIn(module.getEnclosedElements());
    return declaredConstructors.isEmpty()
        || (declaredConstructors.size() == 1
            && !declaredConstructors.get(0).getModifiers().contains(PRIVATE)
            && declaredConstructors.get(0).getParameters().isEmpty());
  }

  /* Arrays.asList(FooTest.TestModule.class, ...) */
  private static CodeBlock getElementsListed(ImmutableSet<TypeElement> modules) {
    return modules.isEmpty()
        ? CodeBlock.of("$T.emptySet()", ClassNames.COLLECTIONS)
        : CodeBlock.of(
            "new $T<>($T.asList($L))",
            ClassNames.HASH_SET,
            ClassNames.ARRAYS,
            modules.stream()
                .map(module -> CodeBlock.of("$T.class", module).toString())
                .collect(joining(",")));
  }

  private MethodSpec getTestInjectInternalMethod() {
    TypeElement testElement = rootMetadata.testRootMetadata().testElement();
    ClassName testName = ClassName.get(testElement);
    return MethodSpec.methodBuilder("injectInternal")
        .addModifiers(PRIVATE, STATIC)
        .addParameter(testName, "testInstance")
        .addAnnotation(
            AnnotationSpec.builder(SuppressWarnings.class)
                .addMember("value", "$S", "unchecked")
                .build())
        .addStatement("$L.injectTest(testInstance)", getInjector(testElement))
        .build();
  }

  private static CodeBlock getInjector(TypeElement testElement) {
    return CodeBlock.of(
        "(($T) (($T) $T.getApplicationContext()).generatedComponent())",
        ClassNames.TEST_INJECTOR,
        ClassNames.GENERATED_COMPONENT_MANAGER,
        ClassNames.APPLICATION_PROVIDER);
  }
}
