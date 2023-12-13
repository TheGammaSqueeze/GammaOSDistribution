/*
 * Copyright (C) 2019 The Dagger Authors.
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

package dagger.hilt.processor.internal.aggregateddeps;

import com.google.common.collect.ImmutableSet;
import com.squareup.javapoet.AnnotationSpec;
import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.JavaFile;
import com.squareup.javapoet.TypeSpec;
import dagger.hilt.processor.internal.Processors;
import java.io.IOException;
import java.util.Optional;
import javax.annotation.processing.ProcessingEnvironment;
import javax.lang.model.element.TypeElement;

/**
 * Generates the @AggregatedDeps annotated class used to pass information
 * about modules and entry points through multiple javac runs.
 */
final class AggregatedDepsGenerator {
  static final String AGGREGATING_PACKAGE = "hilt_aggregated_deps";
  private static final ClassName AGGREGATED_DEPS =
      ClassName.get("dagger.hilt.processor.internal.aggregateddeps", "AggregatedDeps");

  private final String dependencyType;
  private final TypeElement dependency;
  private final Optional<ClassName> testName;
  private final ImmutableSet<ClassName> components;
  private final ImmutableSet<ClassName> replacedDependencies;
  private final ProcessingEnvironment processingEnv;

  AggregatedDepsGenerator(
      String dependencyType,
      TypeElement dependency,
      Optional<ClassName> testName,
      ImmutableSet<ClassName> components,
      ImmutableSet<ClassName> replacedDependencies,
      ProcessingEnvironment processingEnv) {
    this.dependencyType = dependencyType;
    this.dependency = dependency;
    this.testName = testName;
    this.components = components;
    this.replacedDependencies = replacedDependencies;
    this.processingEnv = processingEnv;
  }

  void generate() throws IOException {
    ClassName name =
        ClassName.get(
            AGGREGATING_PACKAGE, Processors.getFullEnclosedName(dependency) + "ModuleDeps");
    TypeSpec.Builder generator =
        TypeSpec.classBuilder(name.simpleName())
            .addOriginatingElement(dependency)
            .addAnnotation(aggregatedDepsAnnotation())
            .addJavadoc("Generated class to pass information through multiple javac runs.\n");

    Processors.addGeneratedAnnotation(generator, processingEnv, getClass());

    JavaFile.builder(name.packageName(), generator.build())
        .build()
        .writeTo(processingEnv.getFiler());
  }

  private AnnotationSpec aggregatedDepsAnnotation() {
    AnnotationSpec.Builder annotationBuilder = AnnotationSpec.builder(AGGREGATED_DEPS);
    components.forEach(component -> annotationBuilder.addMember("components", "$S", component));
    replacedDependencies.forEach(dep -> annotationBuilder.addMember("replaces", "$S", dep));
    testName.ifPresent(test -> annotationBuilder.addMember("test", "$S", test));
    annotationBuilder.addMember(dependencyType, "$S", dependency.getQualifiedName());
    return annotationBuilder.build();
  }
}
