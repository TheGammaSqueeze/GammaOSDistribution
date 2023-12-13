/*
 * Copyright (C) 2015 The Dagger Authors.
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

import com.google.common.base.Joiner;

/**
 * Common lines outputted during code generation.
 */
public final class GeneratedLines {
  public static final String GENERATED_ANNOTATION =
     "@Generated("
        + "value = \"dagger.internal.codegen.ComponentProcessor\", "
        + "comments = \"https://dagger.dev\")";

  private static final String SUPPRESS_WARNINGS_ANNOTATION =
      "@SuppressWarnings({\"unchecked\", \"rawtypes\"})";

  public static final String GENERATED_CODE_ANNOTATIONS =
      Joiner.on('\n').join(GENERATED_ANNOTATION, SUPPRESS_WARNINGS_ANNOTATION);

  public static final String IMPORT_GENERATED_ANNOTATION =
      isBeforeJava9()
          ? "import javax.annotation.Generated;"
          : "import javax.annotation.processing.Generated;";

  static final String GENERATION_OPTIONS_ANNOTATION = "@GenerationOptions(fastInit = false)";

  private static boolean isBeforeJava9() {
    try {
      Class.forName("java.lang.Module");
      return false;
    } catch (ClassNotFoundException e) {
      return true;
    }
  }
}
