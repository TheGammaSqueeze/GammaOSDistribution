#include "callbacks/callbacks.h"
#include <cstddef>
#include <cstdint>
#include <memory>
#include <new>
#include <type_traits>
#include <utility>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_RUST_BOX
#define CXXBRIDGE1_RUST_BOX
template <typename T>
class Box final {
public:
  using element_type = T;
  using const_pointer =
      typename std::add_pointer<typename std::add_const<T>::type>::type;
  using pointer = typename std::add_pointer<T>::type;

  Box() = delete;
  Box(Box &&) noexcept;
  ~Box() noexcept;

  explicit Box(const T &);
  explicit Box(T &&);

  Box &operator=(Box &&) &noexcept;

  const T *operator->() const noexcept;
  const T &operator*() const noexcept;
  T *operator->() noexcept;
  T &operator*() noexcept;

  template <typename... Fields>
  static Box in_place(Fields &&...);

  void swap(Box &) noexcept;

  static Box from_raw(T *) noexcept;

  T *into_raw() noexcept;

  /* Deprecated */ using value_type = element_type;

private:
  class uninit;
  class allocation;
  Box(uninit) noexcept;
  void drop() noexcept;

  friend void swap(Box &lhs, Box &rhs) noexcept { lhs.swap(rhs); }

  T *ptr;
};

template <typename T>
class Box<T>::uninit {};

template <typename T>
class Box<T>::allocation {
  static T *alloc() noexcept;
  static void dealloc(T *) noexcept;

public:
  allocation() noexcept : ptr(alloc()) {}
  ~allocation() noexcept {
    if (this->ptr) {
      dealloc(this->ptr);
    }
  }
  T *ptr;
};

template <typename T>
Box<T>::Box(Box &&other) noexcept : ptr(other.ptr) {
  other.ptr = nullptr;
}

template <typename T>
Box<T>::Box(const T &val) {
  allocation alloc;
  ::new (alloc.ptr) T(val);
  this->ptr = alloc.ptr;
  alloc.ptr = nullptr;
}

template <typename T>
Box<T>::Box(T &&val) {
  allocation alloc;
  ::new (alloc.ptr) T(std::move(val));
  this->ptr = alloc.ptr;
  alloc.ptr = nullptr;
}

template <typename T>
Box<T>::~Box() noexcept {
  if (this->ptr) {
    this->drop();
  }
}

template <typename T>
Box<T> &Box<T>::operator=(Box &&other) &noexcept {
  if (this->ptr) {
    this->drop();
  }
  this->ptr = other.ptr;
  other.ptr = nullptr;
  return *this;
}

template <typename T>
const T *Box<T>::operator->() const noexcept {
  return this->ptr;
}

template <typename T>
const T &Box<T>::operator*() const noexcept {
  return *this->ptr;
}

template <typename T>
T *Box<T>::operator->() noexcept {
  return this->ptr;
}

template <typename T>
T &Box<T>::operator*() noexcept {
  return *this->ptr;
}

template <typename T>
template <typename... Fields>
Box<T> Box<T>::in_place(Fields &&...fields) {
  allocation alloc;
  auto ptr = alloc.ptr;
  ::new (ptr) T{std::forward<Fields>(fields)...};
  alloc.ptr = nullptr;
  return from_raw(ptr);
}

template <typename T>
void Box<T>::swap(Box &rhs) noexcept {
  using std::swap;
  swap(this->ptr, rhs.ptr);
}

template <typename T>
Box<T> Box<T>::from_raw(T *raw) noexcept {
  Box box = uninit{};
  box.ptr = raw;
  return box;
}

template <typename T>
T *Box<T>::into_raw() noexcept {
  T *raw = this->ptr;
  this->ptr = nullptr;
  return raw;
}

template <typename T>
Box<T>::Box(uninit) noexcept {}
#endif // CXXBRIDGE1_RUST_BOX

#ifndef CXXBRIDGE1_RUST_OPAQUE
#define CXXBRIDGE1_RUST_OPAQUE
class Opaque {
public:
  Opaque() = delete;
  Opaque(const Opaque &) = delete;
  ~Opaque() = delete;
};
#endif // CXXBRIDGE1_RUST_OPAQUE

#ifndef CXXBRIDGE1_IS_COMPLETE
#define CXXBRIDGE1_IS_COMPLETE
namespace detail {
namespace {
template <typename T, typename = std::size_t>
struct is_complete : std::false_type {};
template <typename T>
struct is_complete<T, decltype(sizeof(T))> : std::true_type {};
} // namespace
} // namespace detail
#endif // CXXBRIDGE1_IS_COMPLETE

#ifndef CXXBRIDGE1_LAYOUT
#define CXXBRIDGE1_LAYOUT
class layout {
  template <typename T>
  friend std::size_t size_of();
  template <typename T>
  friend std::size_t align_of();
  template <typename T>
  static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_size_of() {
    return T::layout::size();
  }
  template <typename T>
  static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_size_of() {
    return sizeof(T);
  }
  template <typename T>
  static
      typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
      size_of() {
    return do_size_of<T>();
  }
  template <typename T>
  static typename std::enable_if<std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_align_of() {
    return T::layout::align();
  }
  template <typename T>
  static typename std::enable_if<!std::is_base_of<Opaque, T>::value,
                                 std::size_t>::type
  do_align_of() {
    return alignof(T);
  }
  template <typename T>
  static
      typename std::enable_if<detail::is_complete<T>::value, std::size_t>::type
      align_of() {
    return do_align_of<T>();
  }
};

template <typename T>
std::size_t size_of() {
  return layout::size_of<T>();
}

template <typename T>
std::size_t align_of() {
  return layout::align_of<T>();
}
#endif // CXXBRIDGE1_LAYOUT

namespace {
template <bool> struct deleter_if {
  template <typename T> void operator()(T *) {}
};

template <> struct deleter_if<true> {
  template <typename T> void operator()(T *ptr) { ptr->~T(); }
};
} // namespace
} // namespace cxxbridge1
} // namespace rust

namespace bluetooth {
  namespace shim {
    namespace rust {
      using OnceClosure = ::bluetooth::shim::rust::OnceClosure;
      struct MessageLoopThread;
    }
  }
}

namespace bluetooth {
namespace shim {
namespace rust {
#ifndef CXXBRIDGE1_STRUCT_bluetooth$shim$rust$MessageLoopThread
#define CXXBRIDGE1_STRUCT_bluetooth$shim$rust$MessageLoopThread
struct MessageLoopThread final : public ::rust::Opaque {
  ~MessageLoopThread() = delete;

private:
  friend ::rust::layout;
  struct layout {
    static ::std::size_t size() noexcept;
    static ::std::size_t align() noexcept;
  };
};
#endif // CXXBRIDGE1_STRUCT_bluetooth$shim$rust$MessageLoopThread

extern "C" {
void bluetooth$shim$rust$cxxbridge1$OnceClosure$Run(const ::bluetooth::shim::rust::OnceClosure &self) noexcept {
  void (::bluetooth::shim::rust::OnceClosure::*Run$)() const = &::bluetooth::shim::rust::OnceClosure::Run;
  (self.*Run$)();
}
::std::size_t bluetooth$shim$rust$cxxbridge1$MessageLoopThread$operator$sizeof() noexcept;
::std::size_t bluetooth$shim$rust$cxxbridge1$MessageLoopThread$operator$alignof() noexcept;

::bluetooth::shim::rust::MessageLoopThread *bluetooth$shim$rust$cxxbridge1$main_message_loop_thread_create() noexcept;

::std::int32_t bluetooth$shim$rust$cxxbridge1$main_message_loop_thread_start(::bluetooth::shim::rust::MessageLoopThread &thread) noexcept;

void bluetooth$shim$rust$cxxbridge1$main_message_loop_thread_do_delayed(::bluetooth::shim::rust::MessageLoopThread &thread, ::bluetooth::shim::rust::OnceClosure *closure, ::std::int64_t delay_ms) noexcept;
} // extern "C"

::std::size_t MessageLoopThread::layout::size() noexcept {
  return bluetooth$shim$rust$cxxbridge1$MessageLoopThread$operator$sizeof();
}

::std::size_t MessageLoopThread::layout::align() noexcept {
  return bluetooth$shim$rust$cxxbridge1$MessageLoopThread$operator$alignof();
}

::rust::Box<::bluetooth::shim::rust::MessageLoopThread> main_message_loop_thread_create() noexcept {
  return ::rust::Box<::bluetooth::shim::rust::MessageLoopThread>::from_raw(bluetooth$shim$rust$cxxbridge1$main_message_loop_thread_create());
}

::std::int32_t main_message_loop_thread_start(::bluetooth::shim::rust::MessageLoopThread &thread) noexcept {
  return bluetooth$shim$rust$cxxbridge1$main_message_loop_thread_start(thread);
}

void main_message_loop_thread_do_delayed(::bluetooth::shim::rust::MessageLoopThread &thread, ::std::unique_ptr<::bluetooth::shim::rust::OnceClosure> closure, ::std::int64_t delay_ms) noexcept {
  bluetooth$shim$rust$cxxbridge1$main_message_loop_thread_do_delayed(thread, closure.release(), delay_ms);
}
} // namespace rust
} // namespace shim
} // namespace bluetooth

extern "C" {
::bluetooth::shim::rust::MessageLoopThread *cxxbridge1$box$bluetooth$shim$rust$MessageLoopThread$alloc() noexcept;
void cxxbridge1$box$bluetooth$shim$rust$MessageLoopThread$dealloc(::bluetooth::shim::rust::MessageLoopThread *) noexcept;
void cxxbridge1$box$bluetooth$shim$rust$MessageLoopThread$drop(::rust::Box<::bluetooth::shim::rust::MessageLoopThread> *ptr) noexcept;

static_assert(::rust::detail::is_complete<::bluetooth::shim::rust::OnceClosure>::value, "definition of OnceClosure is required");
static_assert(sizeof(::std::unique_ptr<::bluetooth::shim::rust::OnceClosure>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::bluetooth::shim::rust::OnceClosure>) == alignof(void *), "");
void cxxbridge1$unique_ptr$bluetooth$shim$rust$OnceClosure$null(::std::unique_ptr<::bluetooth::shim::rust::OnceClosure> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::bluetooth::shim::rust::OnceClosure>();
}
void cxxbridge1$unique_ptr$bluetooth$shim$rust$OnceClosure$raw(::std::unique_ptr<::bluetooth::shim::rust::OnceClosure> *ptr, ::bluetooth::shim::rust::OnceClosure *raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::bluetooth::shim::rust::OnceClosure>(raw);
}
const ::bluetooth::shim::rust::OnceClosure *cxxbridge1$unique_ptr$bluetooth$shim$rust$OnceClosure$get(const ::std::unique_ptr<::bluetooth::shim::rust::OnceClosure>& ptr) noexcept {
  return ptr.get();
}
::bluetooth::shim::rust::OnceClosure *cxxbridge1$unique_ptr$bluetooth$shim$rust$OnceClosure$release(::std::unique_ptr<::bluetooth::shim::rust::OnceClosure>& ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$bluetooth$shim$rust$OnceClosure$drop(::std::unique_ptr<::bluetooth::shim::rust::OnceClosure> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::bluetooth::shim::rust::OnceClosure>::value>{}(ptr);
}
} // extern "C"

namespace rust {
inline namespace cxxbridge1 {
template <>
::bluetooth::shim::rust::MessageLoopThread *Box<::bluetooth::shim::rust::MessageLoopThread>::allocation::alloc() noexcept {
  return cxxbridge1$box$bluetooth$shim$rust$MessageLoopThread$alloc();
}
template <>
void Box<::bluetooth::shim::rust::MessageLoopThread>::allocation::dealloc(::bluetooth::shim::rust::MessageLoopThread *ptr) noexcept {
  cxxbridge1$box$bluetooth$shim$rust$MessageLoopThread$dealloc(ptr);
}
template <>
void Box<::bluetooth::shim::rust::MessageLoopThread>::drop() noexcept {
  cxxbridge1$box$bluetooth$shim$rust$MessageLoopThread$drop(this);
}
} // namespace cxxbridge1
} // namespace rust
