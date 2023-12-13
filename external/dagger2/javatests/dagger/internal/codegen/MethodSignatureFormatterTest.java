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

import static com.google.common.truth.Truth.assertThat;
import static javax.lang.model.util.ElementFilter.methodsIn;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.Iterables;
import com.google.testing.compile.CompilationRule;
import dagger.BindsInstance;
import dagger.Component;
import dagger.Module;
import dagger.Provides;
import dagger.internal.codegen.MethodSignatureFormatterTest.OuterClass.InnerClass;
import dagger.internal.codegen.binding.InjectionAnnotations;
import dagger.internal.codegen.binding.MethodSignatureFormatter;
import dagger.internal.codegen.langmodel.DaggerElements;
import dagger.internal.codegen.langmodel.DaggerTypes;
import javax.inject.Inject;
import javax.inject.Singleton;
import javax.lang.model.element.ExecutableElement;
import javax.lang.model.element.TypeElement;
import org.junit.Before;
import org.junit.Rule;
import org.junit.Test;
import org.junit.runner.RunWith;
import org.junit.runners.JUnit4;

@RunWith(JUnit4.class)
public class MethodSignatureFormatterTest {
  @Rule public CompilationRule compilationRule = new CompilationRule();

  @Inject DaggerElements elements;
  @Inject DaggerTypes types;
  @Inject InjectionAnnotations injectionAnnotations;

  static class OuterClass {
    @interface Foo {
       Class<?> bar();
    }

    static class InnerClass {
      @Foo(bar = String.class)
      @Singleton
      String foo(
          @SuppressWarnings("unused") int a,
          @SuppressWarnings("unused") ImmutableList<Boolean> blah) {
        return "foo";
      }
    }
  }

  @Before
  public void setUp() {
    DaggerMethodSignatureFormatterTest_TestComponent.factory().create(compilationRule).inject(this);
  }

  @Test public void methodSignatureTest() {
    TypeElement inner = elements.getTypeElement(InnerClass.class);
    ExecutableElement method = Iterables.getOnlyElement(methodsIn(inner.getEnclosedElements()));
    String formatted = new MethodSignatureFormatter(types, injectionAnnotations).format(method);
    // This is gross, but it turns out that annotation order is not guaranteed when getting
    // all the AnnotationMirrors from an Element, so I have to test this chopped-up to make it
    // less brittle.
    assertThat(formatted).contains("@Singleton");
    assertThat(formatted).doesNotContain("@javax.inject.Singleton"); // maybe more importantly
    assertThat(formatted)
        .contains("@dagger.internal.codegen.MethodSignatureFormatterTest.OuterClass.Foo"
            + "(bar=String.class)");
    assertThat(formatted).contains(" String "); // return type compressed
    assertThat(formatted).contains("int, ImmutableList<Boolean>)"); // parameters compressed.
  }

  @Singleton
  @Component(modules = TestModule.class)
  interface TestComponent {
    void inject(MethodSignatureFormatterTest test);

    @Component.Factory
    interface Factory {
      TestComponent create(@BindsInstance CompilationRule compilationRule);
    }
  }

  @Module
  static class TestModule {
    @Provides
    static DaggerElements elements(CompilationRule compilationRule) {
      return new DaggerElements(compilationRule.getElements(), compilationRule.getTypes());
    }

    @Provides
    static DaggerTypes types(CompilationRule compilationRule, DaggerElements elements) {
      return new DaggerTypes(compilationRule.getTypes(), elements);
    }
  }
}
