/*
 * Copyright 2021 Google LLC
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   https://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
package com.google.android.enterprise.connectedapps.internal;

import android.os.Parcel;
import android.os.Parcelable;
import com.google.android.enterprise.connectedapps.annotations.CrossProfileConfiguration;

/**
 * A {@link Bundler} is used to read and write {@link Parcel} instances without needing to use the
 * specific methods for the type of object being read/written.
 *
 * <p>Each {@link CrossProfileConfiguration} will have a {@link Bundler} which can deal with all of
 * the types used by that {@link CrossProfileConfiguration}.
 */
// TODO(158552516): Rename now this no longer concerns Bundles
public interface Bundler extends Parcelable {
  /*
   * We make {@link Bundler} instances implement {@link Parcelable} so that they can be passed
   * as part of the Parcelable Wrapper classes. This ensures the wrappers read the correct types
   * using the same {@link Bundler} that they wrote them with.
   */

  /**
   * Write a value to a {@link Parcel}.
   *
   * @throws IllegalArgumentException if the {@code value} type is unsupported.
   */
  void writeToParcel(Parcel parcel, Object value, BundlerType valueClass, int flags);

  default void writeToParcel(Parcel parcel, byte value, BundlerType valueType, int flags) {
    parcel.writeByte(value);
  }

  default void writeToParcel(Parcel parcel, short value, BundlerType valueType, int flags) {
    parcel.writeInt(value);
  }

  default void writeToParcel(Parcel parcel, int value, BundlerType valueType, int flags) {
    parcel.writeInt(value);
  }

  default void writeToParcel(Parcel parcel, long value, BundlerType valueType, int flags) {
    parcel.writeLong(value);
  }

  default void writeToParcel(Parcel parcel, char value, BundlerType valueType, int flags) {
    parcel.writeInt(value);
  }

  default void writeToParcel(Parcel parcel, float value, BundlerType valueType, int flags) {
    parcel.writeFloat(value);
  }

  default void writeToParcel(Parcel parcel, double value, BundlerType valueType, int flags) {
    parcel.writeDouble(value);
  }

  default void writeToParcel(Parcel parcel, boolean value, BundlerType valueType, int flags) {
    parcel.writeInt(value ? 1 : 0);
  }

  /**
   * Read a value from a {@link Parcel}.
   *
   * @throws IllegalArgumentException if the {@code valueClass} type is unsupported.
   */
  Object readFromParcel(Parcel parcel, BundlerType valueClass);

  /**
   * Create an array of the given type.
   *
   * @throws IllegalArgumentException if the {@code valueClass} type is unsupported.
   */
  Object[] createArray(BundlerType valueClass, int size);
}
