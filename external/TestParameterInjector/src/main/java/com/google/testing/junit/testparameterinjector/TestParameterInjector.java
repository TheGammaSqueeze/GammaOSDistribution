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

import java.util.List;
import org.junit.runners.model.InitializationError;

/**
 * A JUnit test runner which knows how to instantiate and run test classes where each test case may
 * be parameterized with its own unique set of test parameters (as opposed to {@link
 * org.junit.runners.Parameterized} where each test case in a test class is invoked with the exact
 * same set of parameters).
 */
public final class TestParameterInjector extends PluggableTestRunner {

  public TestParameterInjector(Class<?> testClass) throws InitializationError {
    super(testClass);
  }

  @Override
  protected List<TestMethodProcessor> createTestMethodProcessorList() {
    return TestMethodProcessors.createNewParameterizedProcessorsWithLegacyFeatures(getTestClass());
  }
}
