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

package dagger.hilt.processor.internal;

import javax.lang.model.element.Element;

/**
 * Exception to throw when a required {@link Element} is or inherits from an error kind.
 *
 * <p>Includes element to point to for the cause of the error
 */
public final class ErrorTypeException extends RuntimeException {
  private final Element badElement;

  public ErrorTypeException(String message, Element badElement) {
    super(message);
    this.badElement = badElement;
  }

  public Element getBadElement() {
    return badElement;
  }
}
