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

package dagger.hilt.android.internal.lifecycle;

import java.lang.annotation.ElementType;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import javax.inject.Qualifier;

/**
 * Internal qualifier for the multibinding map of ViewModels used by the {@link
 * dagger.hilt.android.lifecycle.HiltViewModelFactory}.
 */
@Qualifier
@Retention(RetentionPolicy.CLASS)
@Target({ElementType.METHOD, ElementType.PARAMETER})
public @interface HiltViewModelMap {

  /** Internal qualifier for the multibinding set of class names annotated with @ViewModelInject. */
  @Qualifier
  @Retention(RetentionPolicy.CLASS)
  @Target({ElementType.METHOD, ElementType.PARAMETER})
  @interface KeySet {}
}
