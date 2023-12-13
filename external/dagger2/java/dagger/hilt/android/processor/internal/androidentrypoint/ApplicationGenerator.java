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

package dagger.hilt.android.processor.internal.androidentrypoint;


import com.squareup.javapoet.ClassName;
import com.squareup.javapoet.CodeBlock;
import com.squareup.javapoet.FieldSpec;
import com.squareup.javapoet.JavaFile;
import com.squareup.javapoet.MethodSpec;
import com.squareup.javapoet.ParameterSpec;
import com.squareup.javapoet.TypeName;
import com.squareup.javapoet.TypeSpec;
import com.squareup.javapoet.TypeVariableName;
import dagger.hilt.android.processor.internal.AndroidClassNames;
import dagger.hilt.processor.internal.ComponentNames;
import dagger.hilt.processor.internal.Processors;
import java.io.IOException;
import javax.annotation.processing.ProcessingEnvironment;
import javax.lang.model.element.Modifier;

/** Generates an Hilt Application for an @AndroidEntryPoint app class. */
public final class ApplicationGenerator {
  private final ProcessingEnvironment env;
  private final AndroidEntryPointMetadata metadata;
  private final ClassName wrapperClassName;

  public ApplicationGenerator(ProcessingEnvironment env, AndroidEntryPointMetadata metadata) {
    this.env = env;
    this.metadata = metadata;
    wrapperClassName = metadata.generatedClassName();
  }

  // @Generated("ApplicationGenerator")
  // abstract class Hilt_$APP extends $BASE implements ComponentManager<ApplicationComponent> {
  //   ...
  // }
  public void generate() throws IOException {
    TypeSpec.Builder typeSpecBuilder =
        TypeSpec.classBuilder(wrapperClassName.simpleName())
            .addOriginatingElement(metadata.element())
            .superclass(metadata.baseClassName())
            .addModifiers(metadata.generatedClassModifiers())
            .addField(componentManagerField())
            .addMethod(componentManagerMethod());

    Generators.addGeneratedBaseClassJavadoc(typeSpecBuilder, AndroidClassNames.HILT_ANDROID_APP);
    Processors.addGeneratedAnnotation(typeSpecBuilder, env, getClass());

    metadata.baseElement().getTypeParameters().stream()
        .map(TypeVariableName::get)
        .forEachOrdered(typeSpecBuilder::addTypeVariable);

    Generators.copyLintAnnotations(metadata.element(), typeSpecBuilder);
    Generators.addComponentOverride(metadata, typeSpecBuilder);

      typeSpecBuilder.addMethod(onCreateMethod());

    JavaFile.builder(metadata.elementClassName().packageName(), typeSpecBuilder.build())
        .build()
        .writeTo(env.getFiler());
  }

  // private final ApplicationComponentManager<ApplicationComponent> componentManager =
  //     new ApplicationComponentManager(/* creatorType */);
  private FieldSpec componentManagerField() {
    ParameterSpec managerParam = metadata.componentManagerParam();
    return FieldSpec.builder(managerParam.type, managerParam.name)
        .addModifiers(Modifier.PRIVATE, Modifier.FINAL)
        .initializer("new $T($L)", AndroidClassNames.APPLICATION_COMPONENT_MANAGER, creatorType())
        .build();
  }

  // protected ApplicationComponentManager<ApplicationComponent> componentManager() {
  //   return componentManager();
  // }
  private MethodSpec componentManagerMethod() {
    return MethodSpec.methodBuilder("componentManager")
        .addAnnotation(Override.class)
        .addModifiers(Modifier.PUBLIC, Modifier.FINAL)
        .returns(metadata.componentManagerParam().type)
        .addStatement("return $N", metadata.componentManagerParam())
        .build();
  }

  // new Supplier<ApplicationComponent>() {
  //   @Override
  //   public ApplicationComponent get() {
  //     return DaggerApplicationComponent.builder()
  //         .applicationContextModule(new ApplicationContextModule(Hilt_$APP.this))
  //         .build();
  //   }
  // }
  private TypeSpec creatorType() {
    ClassName component =
        ComponentNames.generatedComponent(
            metadata.elementClassName(), AndroidClassNames.SINGLETON_COMPONENT);
    return TypeSpec.anonymousClassBuilder("")
        .addSuperinterface(AndroidClassNames.COMPONENT_SUPPLIER)
        .addMethod(
            MethodSpec.methodBuilder("get")
                .addAnnotation(Override.class)
                .addModifiers(Modifier.PUBLIC)
                .returns(TypeName.OBJECT)
                .addStatement(
                    "return $T.builder()\n"
                        + ".applicationContextModule(new $T($T.this))\n"
                        + ".build()",
                    Processors.prepend(Processors.getEnclosedClassName(component), "Dagger"),
                    AndroidClassNames.APPLICATION_CONTEXT_MODULE,
                    wrapperClassName)
                .build())
        .build();
  }

  // @CallSuper
  // @Override
  // public void onCreate() {
  //   // This is a known unsafe cast but should be fine if the only use is
  //   // $APP extends Hilt_$APP
  //   generatedComponent().inject(($APP) this);
  //   super.onCreate();
  // }
  private MethodSpec onCreateMethod() {
    return MethodSpec.methodBuilder("onCreate")
        .addAnnotation(AndroidClassNames.CALL_SUPER)
        .addAnnotation(Override.class)
        .addModifiers(Modifier.PUBLIC)
        .addCode(injectCodeBlock())
        .addStatement("super.onCreate()")
        .build();
  }

  //   // This is a known unsafe cast but should be fine if the only use is
  //   // $APP extends Hilt_$APP
  //   generatedComponent().inject$APP(($APP) this);
  private CodeBlock injectCodeBlock() {
    return CodeBlock.builder()
        .add("// This is a known unsafe cast, but is safe in the only correct use case:\n")
        .add("// $T extends $T\n", metadata.elementClassName(), metadata.generatedClassName())
        .addStatement(
            "(($T) generatedComponent()).$L($L)",
            metadata.injectorClassName(),
            metadata.injectMethodName(),
            Generators.unsafeCastThisTo(metadata.elementClassName()))
        .build();
  }
}
