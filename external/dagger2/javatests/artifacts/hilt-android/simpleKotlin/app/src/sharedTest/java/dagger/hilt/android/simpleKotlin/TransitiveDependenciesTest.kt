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
package dagger.hilt.android.simpleKotlin

import androidx.test.ext.junit.runners.AndroidJUnit4
import androidx.test.platform.app.InstrumentationRegistry
import dagger.hilt.android.simpleKotlin.lib.AndroidLibraryEntryPoints
import dagger.hilt.android.simpleKotlin.lib.KotlinLibraryEntryPoints
import dagger.hilt.android.testing.HiltAndroidRule
import dagger.hilt.android.testing.HiltAndroidTest
import org.junit.Rule
import org.junit.Test
import org.junit.runner.RunWith

/**
 * Tests that entry points in deep dependencies with `implementation` boundaries are available at
 * runtime.
 */
@HiltAndroidTest
@RunWith(AndroidJUnit4::class)
class TransitiveDependenciesTest {
  @get:Rule
  val rule = HiltAndroidRule(this)

  @Test
  fun testEntryPointFromAndroidLib() {
    AndroidLibraryEntryPoints.invokeEntryPoints(
      InstrumentationRegistry.getInstrumentation().targetContext.applicationContext
    )
  }

  @Test
  fun testEntryPointFromKotlinLib() {
    KotlinLibraryEntryPoints.invokeEntryPoints(
      InstrumentationRegistry.getInstrumentation().targetContext.applicationContext
    )
  }
}
