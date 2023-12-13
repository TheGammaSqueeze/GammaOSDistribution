/*
 * Copyright 2021 Google Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except
 * in compliance with the License. You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License
 * is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
 * or implied. See the License for the specific language governing permissions and limitations under
 * the License.
 */

package com.google.testing.junit.testparameterinjector;

import static com.google.common.truth.Truth.assertThat;

import com.google.protobuf.ByteString;

import org.junit.Ignore;
import org.junit.Test;
import org.junit.runner.RunWith;

@RunWith(TestParameterInjector.class)
public class ParameterValueParsingTest {

  @Test
  public void parseEnum_success() throws Exception {
    Enum<?> result = ParameterValueParsing.parseEnum("BBB", TestEnum.class);

    assertThat(result).isEqualTo(TestEnum.BBB);
  }

  @Test
  @TestParameters({
    "{yamlString: '{a: b, c: 15}', valid: true}",
    "{yamlString: '{a: b c: 15',   valid: false}",
    "{yamlString: 'a: b c: 15',    valid: false}",
  })
  @Ignore("b/195657808 @TestParameters is not supported on Android")
  public void isValidYamlString_success(String yamlString, boolean valid) throws Exception {
    boolean result = ParameterValueParsing.isValidYamlString(yamlString);

    assertThat(result).isEqualTo(valid);
  }

  enum ParseYamlValueToJavaTypeCases {
    STRING_TO_STRING(
        /* yamlString= */ "abc", /* javaClass= */ String.class, /* expectedResult= */ "abc"),
    BOOLEAN_TO_STRING(
        /* yamlString= */ "true", /* javaClass= */ String.class, /* expectedResult= */ "true"),
    INT_TO_STRING(
        /* yamlString= */ "123", /* javaClass= */ String.class, /* expectedResult= */ "123"),
    LONG_TO_STRING(
        /* yamlString= */ "442147483648",
        /* javaClass= */ String.class,
        /* expectedResult= */ "442147483648"),
    DOUBLE_TO_STRING(
        /* yamlString= */ "1.23", /* javaClass= */ String.class, /* expectedResult= */ "1.23"),

    BOOLEAN_TO_BOOLEAN(
        /* yamlString= */ "true", /* javaClass= */ Boolean.class, /* expectedResult= */ true),

    INT_TO_INT(/* yamlString= */ "123", /* javaClass= */ int.class, /* expectedResult= */ 123),

    LONG_TO_LONG(
        /* yamlString= */ "442147483648",
        /* javaClass= */ long.class,
        /* expectedResult= */ 442147483648L),
    INT_TO_LONG(/* yamlString= */ "123", /* javaClass= */ Long.class, /* expectedResult= */ 123L),

    DOUBLE_TO_DOUBLE(
        /* yamlString= */ "1.23", /* javaClass= */ Double.class, /* expectedResult= */ 1.23),
    INT_TO_DOUBLE(
        /* yamlString= */ "123", /* javaClass= */ Double.class, /* expectedResult= */ 123.0),
    LONG_TO_DOUBLE(
        /* yamlString= */ "442147483648",
        /* javaClass= */ Double.class,
        /* expectedResult= */ 442147483648.0),

    DOUBLE_TO_FLOAT(
        /* yamlString= */ "1.23", /* javaClass= */ Float.class, /* expectedResult= */ 1.23F),
    INT_TO_FLOAT(/* yamlString= */ "123", /* javaClass= */ Float.class, /* expectedResult= */ 123F),

    STRING_TO_ENUM(
        /* yamlString= */ "AAA",
        /* javaClass= */ TestEnum.class,
        /* expectedResult= */ TestEnum.AAA),

    STRING_TO_BYTES(
        /* yamlString= */ "data",
        /* javaClass= */ byte[].class,
        /* expectedResult= */ "data".getBytes()),

    BYTES_TO_BYTES(
        /* yamlString= */ "!!binary 'ZGF0YQ=='",
        /* javaClass= */ byte[].class,
        /* expectedResult= */ "data".getBytes()),

    STRING_TO_BYTESTRING(
        /* yamlString= */ "'data'",
        /* javaClass= */ ByteString.class,
        /* expectedResult= */ ByteString.copyFromUtf8("data")),

    BINARY_TO_BYTESTRING(
        /* yamlString= */ "!!binary 'ZGF0YQ=='",
        /* javaClass= */ ByteString.class,
        /* expectedResult= */ ByteString.copyFromUtf8("data"));

    final String yamlString;
    final Class<?> javaClass;
    final Object expectedResult;

    ParseYamlValueToJavaTypeCases(String yamlString, Class<?> javaClass, Object expectedResult) {
      this.yamlString = yamlString;
      this.javaClass = javaClass;
      this.expectedResult = expectedResult;
    }
  }

  @Test
  public void parseYamlStringToJavaType_success(
      @TestParameter ParseYamlValueToJavaTypeCases parseYamlValueToJavaTypeCases) throws Exception {
    Object result =
        ParameterValueParsing.parseYamlStringToJavaType(
            parseYamlValueToJavaTypeCases.yamlString, parseYamlValueToJavaTypeCases.javaClass);

    assertThat(result).isEqualTo(parseYamlValueToJavaTypeCases.expectedResult);
  }

  private enum TestEnum {
    AAA,
    BBB;
  }
}
