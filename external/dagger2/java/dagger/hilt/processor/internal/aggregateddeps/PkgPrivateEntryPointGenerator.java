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

import com.squareup.javapoet.AnnotationSpec;
import com.squareup.javapoet.JavaFile;
import com.squareup.javapoet.TypeSpec;
import dagger.hilt.processor.internal.Processors;
import java.io.IOException;
import javax.annotation.processing.ProcessingEnvironment;
import javax.lang.model.element.Modifier;

/**
 * Generates a public Dagger entrypoint that includes a user's pkg-private entrypoint. This allows a
 * user's entrypoint to use pkg-private visibility to hide from external packages.
 */
final class PkgPrivateEntryPointGenerator {
  private final ProcessingEnvironment env;
  private final PkgPrivateMetadata metadata;

  PkgPrivateEntryPointGenerator(ProcessingEnvironment env, PkgPrivateMetadata metadata) {
    this.env = env;
    this.metadata = metadata;
  }

  // This method creates the following generated code for an EntryPoint in pkg.MyEntryPoint that is
  // package
  // private
  //
  // package pkg; //same package
  //
  // import dagger.hilt.InstallIn;
  // import dagger.hilt.EntryPoint;;
  // import javax.annotation.Generated;
  //
  // @Generated("dagger.hilt.processor.internal.aggregateddeps.PkgPrivateEntryPointGenerator")
  // @InstallIn(InstallIn.Component.ACTIVITY)
  // @EntryPoint
  // public final class HiltWrapper_MyEntryPoint extends MyEntryPoint  {
  // }
  void generate() throws IOException {

    TypeSpec.Builder entryPointInterfaceBuilder =
        TypeSpec.interfaceBuilder(metadata.generatedClassName().simpleName())
            .addOriginatingElement(metadata.getTypeElement())
            .addAnnotation(Processors.getOriginatingElementAnnotation(metadata.getTypeElement()))
            .addModifiers(Modifier.PUBLIC)
            .addSuperinterface(metadata.baseClassName())
            .addAnnotation(metadata.getAnnotation());

    Processors.addGeneratedAnnotation(entryPointInterfaceBuilder, env, getClass());

    if (metadata.getOptionalInstallInAnnotationMirror().isPresent()) {
      entryPointInterfaceBuilder.addAnnotation(
          AnnotationSpec.get(metadata.getOptionalInstallInAnnotationMirror().get()));
    }

    JavaFile.builder(
            metadata.generatedClassName().packageName(), entryPointInterfaceBuilder.build())
        .build()
        .writeTo(env.getFiler());
  }
}
