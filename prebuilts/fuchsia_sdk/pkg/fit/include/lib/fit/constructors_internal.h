// Copyright 2019 The Fuchsia Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef LIB_FIT_CONSTRUCTORS_INTERNAL_H_
#define LIB_FIT_CONSTRUCTORS_INTERNAL_H_

#include <type_traits>
#include <utility>

#include "utility_internal.h"

namespace fit {
namespace internal {

// Mixin that implicitly deletes the subclass default constructor when type T
// is not default constructible.
template <typename T, bool = std::is_default_constructible<T>::value>
struct modulate_default_constructor {};
template <typename T>
struct modulate_default_constructor<T, false> {
  constexpr modulate_default_constructor() = delete;
};

// Mixin that implicitly deletes the subclass copy constructor when type T is
// not copy constructible.
template <size_t Index, typename T, bool = std::is_copy_constructible<T>::value>
struct modulate_copy_constructor {};
template <size_t Index, typename T>
struct modulate_copy_constructor<Index, T, false> {
  constexpr modulate_copy_constructor() = default;
  constexpr modulate_copy_constructor(const modulate_copy_constructor&) = delete;
  constexpr modulate_copy_constructor& operator=(const modulate_copy_constructor&) = default;
  constexpr modulate_copy_constructor(modulate_copy_constructor&&) = default;
  constexpr modulate_copy_constructor& operator=(modulate_copy_constructor&&) = default;
};

// Mixin that implicitly deletes the subclass copy assignment operator when type
// T is not copy assignable.
template <size_t Index, typename T, bool = std::is_copy_assignable<T>::value>
struct modulate_copy_assignment {};
template <size_t Index, typename T>
struct modulate_copy_assignment<Index, T, false> {
  constexpr modulate_copy_assignment() = default;
  constexpr modulate_copy_assignment(const modulate_copy_assignment&) = default;
  constexpr modulate_copy_assignment& operator=(const modulate_copy_assignment&) = delete;
  constexpr modulate_copy_assignment(modulate_copy_assignment&&) = default;
  constexpr modulate_copy_assignment& operator=(modulate_copy_assignment&&) = default;
};

// Mixin that implicitly deletes the subclass move constructor when type T is
// not move constructible.
template <size_t Index, typename T, bool = std::is_move_constructible<T>::value>
struct modulate_move_constructor {};
template <size_t Index, typename T>
struct modulate_move_constructor<Index, T, false> {
  constexpr modulate_move_constructor() = default;
  constexpr modulate_move_constructor(const modulate_move_constructor&) = default;
  constexpr modulate_move_constructor& operator=(const modulate_move_constructor&) = default;
  constexpr modulate_move_constructor(modulate_move_constructor&&) = delete;
  constexpr modulate_move_constructor& operator=(modulate_move_constructor&&) = default;
};

// Mixin that implicitly deletes the subclass move assignment operator when type
// T is not move assignable.
template <size_t Index, typename T, bool = std::is_move_assignable<T>::value>
struct modulate_move_assignment {};
template <size_t Index, typename T>
struct modulate_move_assignment<Index, T, false> {
  constexpr modulate_move_assignment() = default;
  constexpr modulate_move_assignment(const modulate_move_assignment&) = default;
  constexpr modulate_move_assignment& operator=(const modulate_move_assignment&) = default;
  constexpr modulate_move_assignment(modulate_move_assignment&&) = default;
  constexpr modulate_move_assignment& operator=(modulate_move_assignment&&) = delete;
};

// Utility that takes an index sequence and an equally sized parameter pack and
// mixes in each of the above copy/move construction/assignment modulators for
// each type in Ts. The indices are used to avoid duplicate direct base errors
// by ensuring that each mixin type is unique, even when there are duplicate
// types within the parameter pack Ts.
template <typename IndexSequence, typename... Ts>
struct modulate_copy_and_move_index;

template <size_t... Is, typename... Ts>
struct modulate_copy_and_move_index<std::index_sequence<Is...>, Ts...>
    : modulate_copy_constructor<Is, Ts>...,
      modulate_copy_assignment<Is, Ts>...,
      modulate_move_constructor<Is, Ts>...,
      modulate_move_assignment<Is, Ts>... {};

// Mixin that modulates the subclass copy/move constructors and assignment
// operators based on the copy/move characteristics of each type in Ts.
template <typename... Ts>
struct modulate_copy_and_move
    : modulate_copy_and_move_index<std::index_sequence_for<Ts...>, Ts...> {};

}  // namespace internal
}  // namespace fit

#endif  //  LIB_FIT_CONSTRUCTORS_INTERNAL_H_
