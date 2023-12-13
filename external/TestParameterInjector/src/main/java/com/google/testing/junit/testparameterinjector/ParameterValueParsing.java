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

import static com.google.common.base.Preconditions.checkArgument;
import static com.google.common.base.Preconditions.checkNotNull;
import static com.google.common.base.Preconditions.checkState;
import static java.util.function.Function.identity;

import com.google.common.collect.Lists;
import com.google.common.collect.Maps;
import com.google.common.primitives.Primitives;
import com.google.common.reflect.TypeToken;
import com.google.protobuf.ByteString;
import com.google.protobuf.MessageLite;
import java.lang.reflect.ParameterizedType;
import java.nio.charset.StandardCharsets;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import javax.annotation.Nullable;
import org.yaml.snakeyaml.Yaml;
import org.yaml.snakeyaml.constructor.SafeConstructor;

/** A helper class for parsing parameter values from strings. */
final class ParameterValueParsing {

  @SuppressWarnings("unchecked")
  static <E extends Enum<E>> Enum<?> parseEnum(String str, Class<?> enumType) {
    return Enum.valueOf((Class<E>) enumType, str);
  }

  static MessageLite parseTextprotoMessage(String textprotoString, Class<?> javaType) {
    return getProtoValueParser().parseTextprotoMessage(textprotoString, javaType);
  }

  static boolean isValidYamlString(String yamlString) {
    try {
      new Yaml(new SafeConstructor()).load(yamlString);
      return true;
    } catch (RuntimeException e) {
      return false;
    }
  }

  static Object parseYamlStringToJavaType(String yamlString, Class<?> javaType) {
    return parseYamlObjectToJavaType(parseYamlStringToObject(yamlString), TypeToken.of(javaType));
  }

  static Object parseYamlStringToObject(String yamlString) {
    return new Yaml(new SafeConstructor()).load(yamlString);
  }

  @SuppressWarnings("unchecked")
  static Object parseYamlObjectToJavaType(Object parsedYaml, TypeToken<?> javaType) {
    // Pass along null so we don't have to worry about it below
    if (parsedYaml == null) {
      return null;
    }

    YamlValueTransformer yamlValueTransformer =
        new YamlValueTransformer(parsedYaml, javaType.getRawType());

    yamlValueTransformer
        .ifJavaType(String.class)
        .supportParsedType(String.class, identity())
        // Also support other primitives because it's easy to accidentally write e.g. a number when
        // a string was intended in YAML
        .supportParsedType(Boolean.class, Object::toString)
        .supportParsedType(Integer.class, Object::toString)
        .supportParsedType(Long.class, Object::toString)
        .supportParsedType(Double.class, Object::toString);

    yamlValueTransformer.ifJavaType(Boolean.class).supportParsedType(Boolean.class, identity());

    yamlValueTransformer.ifJavaType(Integer.class).supportParsedType(Integer.class, identity());

    yamlValueTransformer
        .ifJavaType(Long.class)
        .supportParsedType(Long.class, identity())
        .supportParsedType(Integer.class, Integer::longValue);

    yamlValueTransformer
        .ifJavaType(Float.class)
        .supportParsedType(Float.class, identity())
        .supportParsedType(Double.class, Double::floatValue)
        .supportParsedType(Integer.class, Integer::floatValue);

    yamlValueTransformer
        .ifJavaType(Double.class)
        .supportParsedType(Double.class, identity())
        .supportParsedType(Integer.class, Integer::doubleValue)
        .supportParsedType(Long.class, Long::doubleValue);

    yamlValueTransformer
        .ifJavaType(Enum.class)
        .supportParsedType(
            String.class, str -> ParameterValueParsing.parseEnum(str, javaType.getRawType()));

    yamlValueTransformer
        .ifJavaType(MessageLite.class)
        .supportParsedType(String.class, str -> parseTextprotoMessage(str, javaType.getRawType()))
        .supportParsedType(
            Map.class,
            map ->
                getProtoValueParser()
                    .parseProtobufMessage((Map<String, Object>) map, javaType.getRawType()));

    yamlValueTransformer
        .ifJavaType(byte[].class)
        .supportParsedType(byte[].class, identity())
        .supportParsedType(String.class, s -> s.getBytes(StandardCharsets.UTF_8));

    yamlValueTransformer
        .ifJavaType(ByteString.class)
        .supportParsedType(String.class, ByteString::copyFromUtf8)
        .supportParsedType(byte[].class, ByteString::copyFrom);

    // Added mainly for protocol buffer parsing
    yamlValueTransformer
        .ifJavaType(List.class)
        .supportParsedType(
            List.class,
            list ->
                Lists.transform(
                    list,
                    e ->
                        parseYamlObjectToJavaType(
                            e, getGenericParameterType(javaType, /* parameterIndex= */ 0))));
    yamlValueTransformer
        .ifJavaType(Map.class)
        .supportParsedType(
            Map.class,
            map ->
                Maps.transformValues(
                    map,
                    v ->
                        parseYamlObjectToJavaType(
                            v, getGenericParameterType(javaType, /* parameterIndex= */ 1))));

    return yamlValueTransformer.transformedJavaValue();
  }

  private static TypeToken<?> getGenericParameterType(TypeToken<?> typeToken, int parameterIndex) {
    checkArgument(
        typeToken.getType() instanceof ParameterizedType,
        "Could not parse the generic parameter of type %s",
        typeToken);

    ParameterizedType parameterizedType = (ParameterizedType) typeToken.getType();
    return TypeToken.of(parameterizedType.getActualTypeArguments()[parameterIndex]);
  }

  private static final class YamlValueTransformer {
    private final Object parsedYaml;
    private final Class<?> javaType;
    @Nullable private Object transformedJavaValue;

    YamlValueTransformer(Object parsedYaml, Class<?> javaType) {
      this.parsedYaml = parsedYaml;
      this.javaType = javaType;
    }

    <JavaT> SupportedJavaType<JavaT> ifJavaType(Class<JavaT> supportedJavaType) {
      return new SupportedJavaType<>(supportedJavaType);
    }

    Object transformedJavaValue() {
      checkArgument(
          transformedJavaValue != null,
          "Could not map YAML value %s (class = %s) to java class %s",
          parsedYaml,
          parsedYaml.getClass(),
          javaType);
      return transformedJavaValue;
    }

    final class SupportedJavaType<JavaT> {

      private final Class<JavaT> supportedJavaType;

      private SupportedJavaType(Class<JavaT> supportedJavaType) {
        this.supportedJavaType = supportedJavaType;
      }

      @SuppressWarnings("unchecked")
      <ParsedYamlT> SupportedJavaType<JavaT> supportParsedType(
          Class<ParsedYamlT> parsedYamlType, Function<ParsedYamlT, JavaT> transformation) {
        if (Primitives.wrap(supportedJavaType).isAssignableFrom(Primitives.wrap(javaType))) {
          if (Primitives.wrap(parsedYamlType).isInstance(parsedYaml)) {
            checkState(
                transformedJavaValue == null,
                "This case is already handled. This is a bug in"
                    + " testparameterinjector.TestParametersMethodProcessor.");
            transformedJavaValue = checkNotNull(transformation.apply((ParsedYamlT) parsedYaml));
          }
        }

        return this;
      }
    }
  }

  static ProtoValueParsing getProtoValueParser() {
    try {
      // This is called reflectively so that the android target doesn't have to build in
      // ProtoValueParsing, which has no Android-compatible target.
      Class<?> clazz =
          Class.forName("com.google.testing.junit.testparameterinjector.ProtoValueParsingImpl");
      return (ProtoValueParsing) clazz.getDeclaredConstructor().newInstance();
    } catch (ClassNotFoundException unused) {
      throw new UnsupportedOperationException(
          "Textproto support is not available when using the Android version of"
              + " testparameterinjector.");
    } catch (ReflectiveOperationException e) {
      throw new AssertionError(e);
    }
  }

  private ParameterValueParsing() {}
}
