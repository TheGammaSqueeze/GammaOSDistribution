#include "callbacks/callbacks.h"
#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <iterator>
#include <memory>
#include <new>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>

namespace rust {
inline namespace cxxbridge1 {
// #include "rust/cxx.h"

#ifndef CXXBRIDGE1_PANIC
#define CXXBRIDGE1_PANIC
template <typename Exception>
void panic [[noreturn]] (const char *msg);
#endif // CXXBRIDGE1_PANIC

struct unsafe_bitcopy_t;

namespace {
template <typename T>
class impl;
} // namespace

template <typename T>
::std::size_t size_of();
template <typename T>
::std::size_t align_of();

#ifndef CXXBRIDGE1_RUST_STRING
#define CXXBRIDGE1_RUST_STRING
class String final {
public:
  String() noexcept;
  String(const String &) noexcept;
  String(String &&) noexcept;
  ~String() noexcept;

  String(const std::string &);
  String(const char *);
  String(const char *, std::size_t);

  String &operator=(const String &) &noexcept;
  String &operator=(String &&) &noexcept;

  explicit operator std::string() const;

  const char *data() const noexcept;
  std::size_t size() const noexcept;
  std::size_t length() const noexcept;

  const char *c_str() noexcept;

  using iterator = char *;
  iterator begin() noexcept;
  iterator end() noexcept;

  using const_iterator = const char *;
  const_iterator begin() const noexcept;
  const_iterator end() const noexcept;
  const_iterator cbegin() const noexcept;
  const_iterator cend() const noexcept;

  bool operator==(const String &) const noexcept;
  bool operator!=(const String &) const noexcept;
  bool operator<(const String &) const noexcept;
  bool operator<=(const String &) const noexcept;
  bool operator>(const String &) const noexcept;
  bool operator>=(const String &) const noexcept;

  void swap(String &) noexcept;

  String(unsafe_bitcopy_t, const String &) noexcept;

private:
  friend void swap(String &lhs, String &rhs) noexcept { lhs.swap(rhs); }

  std::array<std::uintptr_t, 3> repr;
};
#endif // CXXBRIDGE1_RUST_STRING

#ifndef CXXBRIDGE1_RUST_SLICE
#define CXXBRIDGE1_RUST_SLICE
namespace detail {
template <bool>
struct copy_assignable_if {};

template <>
struct copy_assignable_if<false> {
  copy_assignable_if() noexcept = default;
  copy_assignable_if(const copy_assignable_if &) noexcept = default;
  copy_assignable_if &operator=(const copy_assignable_if &) &noexcept = delete;
  copy_assignable_if &operator=(copy_assignable_if &&) &noexcept = default;
};
} // namespace detail

template <typename T>
class Slice final
    : private detail::copy_assignable_if<std::is_const<T>::value> {
public:
  using value_type = T;

  Slice() noexcept;
  Slice(T *, std::size_t count) noexcept;

  Slice &operator=(const Slice<T> &) &noexcept = default;
  Slice &operator=(Slice<T> &&) &noexcept = default;

  T *data() const noexcept;
  std::size_t size() const noexcept;
  std::size_t length() const noexcept;
  bool empty() const noexcept;

  T &operator[](std::size_t n) const noexcept;
  T &at(std::size_t n) const;
  T &front() const noexcept;
  T &back() const noexcept;

  Slice(const Slice<T> &) noexcept = default;
  ~Slice() noexcept = default;

  class iterator;
  iterator begin() const noexcept;
  iterator end() const noexcept;

  void swap(Slice &) noexcept;

private:
  class uninit;
  Slice(uninit) noexcept;
  friend impl<Slice>;
  friend void sliceInit(void *, const void *, std::size_t) noexcept;
  friend void *slicePtr(const void *) noexcept;
  friend std::size_t sliceLen(const void *) noexcept;

  std::array<std::uintptr_t, 2> repr;
};

template <typename T>
class Slice<T>::iterator final {
public:
  using iterator_category = std::random_access_iterator_tag;
  using value_type = T;
  using difference_type = std::ptrdiff_t;
  using pointer = typename std::add_pointer<T>::type;
  using reference = typename std::add_lvalue_reference<T>::type;

  reference operator*() const noexcept;
  pointer operator->() const noexcept;
  reference operator[](difference_type) const noexcept;

  iterator &operator++() noexcept;
  iterator operator++(int) noexcept;
  iterator &operator--() noexcept;
  iterator operator--(int) noexcept;

  iterator &operator+=(difference_type) noexcept;
  iterator &operator-=(difference_type) noexcept;
  iterator operator+(difference_type) const noexcept;
  iterator operator-(difference_type) const noexcept;
  difference_type operator-(const iterator &) const noexcept;

  bool operator==(const iterator &) const noexcept;
  bool operator!=(const iterator &) const noexcept;
  bool operator<(const iterator &) const noexcept;
  bool operator<=(const iterator &) const noexcept;
  bool operator>(const iterator &) const noexcept;
  bool operator>=(const iterator &) const noexcept;

private:
  friend class Slice;
  void *pos;
  std::size_t stride;
};

template <typename T>
Slice<T>::Slice() noexcept {
  sliceInit(this, reinterpret_cast<void *>(align_of<T>()), 0);
}

template <typename T>
Slice<T>::Slice(T *s, std::size_t count) noexcept {
  assert(s != nullptr || count == 0);
  sliceInit(this,
            s == nullptr && count == 0
                ? reinterpret_cast<void *>(align_of<T>())
                : const_cast<typename std::remove_const<T>::type *>(s),
            count);
}

template <typename T>
T *Slice<T>::data() const noexcept {
  return reinterpret_cast<T *>(slicePtr(this));
}

template <typename T>
std::size_t Slice<T>::size() const noexcept {
  return sliceLen(this);
}

template <typename T>
std::size_t Slice<T>::length() const noexcept {
  return this->size();
}

template <typename T>
bool Slice<T>::empty() const noexcept {
  return this->size() == 0;
}

template <typename T>
T &Slice<T>::operator[](std::size_t n) const noexcept {
  assert(n < this->size());
  auto pos = static_cast<char *>(slicePtr(this)) + size_of<T>() * n;
  return *reinterpret_cast<T *>(pos);
}

template <typename T>
T &Slice<T>::at(std::size_t n) const {
  if (n >= this->size()) {
    panic<std::out_of_range>("rust::Slice index out of range");
  }
  return (*this)[n];
}

template <typename T>
T &Slice<T>::front() const noexcept {
  assert(!this->empty());
  return (*this)[0];
}

template <typename T>
T &Slice<T>::back() const noexcept {
  assert(!this->empty());
  return (*this)[this->size() - 1];
}

template <typename T>
typename Slice<T>::iterator::reference
Slice<T>::iterator::operator*() const noexcept {
  return *static_cast<T *>(this->pos);
}

template <typename T>
typename Slice<T>::iterator::pointer
Slice<T>::iterator::operator->() const noexcept {
  return static_cast<T *>(this->pos);
}

template <typename T>
typename Slice<T>::iterator::reference Slice<T>::iterator::operator[](
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto pos = static_cast<char *>(this->pos) + this->stride * n;
  return *reinterpret_cast<T *>(pos);
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator++() noexcept {
  this->pos = static_cast<char *>(this->pos) + this->stride;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator++(int) noexcept {
  auto ret = iterator(*this);
  this->pos = static_cast<char *>(this->pos) + this->stride;
  return ret;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator--() noexcept {
  this->pos = static_cast<char *>(this->pos) - this->stride;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator--(int) noexcept {
  auto ret = iterator(*this);
  this->pos = static_cast<char *>(this->pos) - this->stride;
  return ret;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator+=(
    typename Slice<T>::iterator::difference_type n) noexcept {
  this->pos = static_cast<char *>(this->pos) + this->stride * n;
  return *this;
}

template <typename T>
typename Slice<T>::iterator &Slice<T>::iterator::operator-=(
    typename Slice<T>::iterator::difference_type n) noexcept {
  this->pos = static_cast<char *>(this->pos) - this->stride * n;
  return *this;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator+(
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ret = iterator(*this);
  ret.pos = static_cast<char *>(this->pos) + this->stride * n;
  return ret;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::iterator::operator-(
    typename Slice<T>::iterator::difference_type n) const noexcept {
  auto ret = iterator(*this);
  ret.pos = static_cast<char *>(this->pos) - this->stride * n;
  return ret;
}

template <typename T>
typename Slice<T>::iterator::difference_type
Slice<T>::iterator::operator-(const iterator &other) const noexcept {
  auto diff = std::distance(static_cast<char *>(other.pos),
                            static_cast<char *>(this->pos));
  return diff / this->stride;
}

template <typename T>
bool Slice<T>::iterator::operator==(const iterator &other) const noexcept {
  return this->pos == other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator!=(const iterator &other) const noexcept {
  return this->pos != other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator<(const iterator &other) const noexcept {
  return this->pos < other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator<=(const iterator &other) const noexcept {
  return this->pos <= other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator>(const iterator &other) const noexcept {
  return this->pos > other.pos;
}

template <typename T>
bool Slice<T>::iterator::operator>=(const iterator &other) const noexcept {
  return this->pos >= other.pos;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::begin() const noexcept {
  iterator it;
  it.pos = slicePtr(this);
  it.stride = size_of<T>();
  return it;
}

template <typename T>
typename Slice<T>::iterator Slice<T>::end() const noexcept {
  iterator it = this->begin();
  it.pos = static_cast<char *>(it.pos) + it.stride * this->size();
  return it;
}

template <typename T>
void Slice<T>::swap(Slice &rhs) noexcept {
  std::swap(*this, rhs);
}
#endif // CXXBRIDGE1_RUST_SLICE

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

namespace detail {
template <typename T, typename = void *>
struct operator_new {
  void *operator()(::std::size_t sz) { return ::operator new(sz); }
};

template <typename T>
struct operator_new<T, decltype(T::operator new(sizeof(T)))> {
  void *operator()(::std::size_t sz) { return T::operator new(sz); }
};
} // namespace detail

template <typename T>
union MaybeUninit {
  T value;
  void *operator new(::std::size_t sz) { return detail::operator_new<T>{}(sz); }
  MaybeUninit() {}
  ~MaybeUninit() {}
};

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
      struct Stack;
      struct Hci;
      struct Controller;
      using u8SliceCallback = ::bluetooth::shim::rust::u8SliceCallback;
      using u8SliceOnceCallback = ::bluetooth::shim::rust::u8SliceOnceCallback;
    }
  }
}

namespace bluetooth {
namespace shim {
namespace rust {
#ifndef CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Stack
#define CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Stack
struct Stack final : public ::rust::Opaque {
  ~Stack() = delete;

private:
  friend ::rust::layout;
  struct layout {
    static ::std::size_t size() noexcept;
    static ::std::size_t align() noexcept;
  };
};
#endif // CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Stack

#ifndef CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Hci
#define CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Hci
struct Hci final : public ::rust::Opaque {
  ~Hci() = delete;

private:
  friend ::rust::layout;
  struct layout {
    static ::std::size_t size() noexcept;
    static ::std::size_t align() noexcept;
  };
};
#endif // CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Hci

#ifndef CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Controller
#define CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Controller
struct Controller final : public ::rust::Opaque {
  ~Controller() = delete;

private:
  friend ::rust::layout;
  struct layout {
    static ::std::size_t size() noexcept;
    static ::std::size_t align() noexcept;
  };
};
#endif // CXXBRIDGE1_STRUCT_bluetooth$shim$rust$Controller

extern "C" {
::std::size_t bluetooth$shim$rust$cxxbridge1$Stack$operator$sizeof() noexcept;
::std::size_t bluetooth$shim$rust$cxxbridge1$Stack$operator$alignof() noexcept;
::std::size_t bluetooth$shim$rust$cxxbridge1$Hci$operator$sizeof() noexcept;
::std::size_t bluetooth$shim$rust$cxxbridge1$Hci$operator$alignof() noexcept;
::std::size_t bluetooth$shim$rust$cxxbridge1$Controller$operator$sizeof() noexcept;
::std::size_t bluetooth$shim$rust$cxxbridge1$Controller$operator$alignof() noexcept;

::bluetooth::shim::rust::Stack *bluetooth$shim$rust$cxxbridge1$stack_create() noexcept;

void bluetooth$shim$rust$cxxbridge1$stack_start(::bluetooth::shim::rust::Stack &stack) noexcept;

void bluetooth$shim$rust$cxxbridge1$stack_stop(::bluetooth::shim::rust::Stack &stack) noexcept;

::bluetooth::shim::rust::Hci *bluetooth$shim$rust$cxxbridge1$get_hci(::bluetooth::shim::rust::Stack &stack) noexcept;

::bluetooth::shim::rust::Controller *bluetooth$shim$rust$cxxbridge1$get_controller(::bluetooth::shim::rust::Stack &stack) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_set_acl_callback(::bluetooth::shim::rust::Hci &hci, ::bluetooth::shim::rust::u8SliceCallback *callback) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_set_evt_callback(::bluetooth::shim::rust::Hci &hci, ::bluetooth::shim::rust::u8SliceCallback *callback) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_set_le_evt_callback(::bluetooth::shim::rust::Hci &hci, ::bluetooth::shim::rust::u8SliceCallback *callback) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_send_command(::bluetooth::shim::rust::Hci &hci, ::rust::Slice<const ::std::uint8_t> data, ::bluetooth::shim::rust::u8SliceOnceCallback *callback) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_send_acl(::bluetooth::shim::rust::Hci &hci, ::rust::Slice<const ::std::uint8_t> data) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_register_event(::bluetooth::shim::rust::Hci &hci, ::std::uint8_t event) noexcept;

void bluetooth$shim$rust$cxxbridge1$hci_register_le_event(::bluetooth::shim::rust::Hci &hci, ::std::uint8_t subevent) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_simple_pairing(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_secure_connections(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_simultaneous_le_bredr(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_interlaced_inquiry_scan(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_rssi_with_inquiry_results(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_extended_inquiry_response(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_role_switch(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_three_slot_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_five_slot_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_classic_2m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_classic_3m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_three_slot_edr_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_five_slot_edr_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_sco(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_hv2_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_hv3_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ev3_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ev4_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ev5_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_esco_2m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_esco_3m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_three_slot_esco_edr_packets(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_hold_mode(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_sniff_mode(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_park_mode(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_non_flushable_pb(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_sniff_subrating(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_encryption_pause(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ble(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_privacy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_packet_extension(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_connection_parameters_request(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ble_2m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ble_coded_phy(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_extended_advertising(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_periodic_advertising(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_peripheral_initiated_feature_exchange(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_connection_parameter_request(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_periodic_advertising_sync_transfer_sender(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_periodic_advertising_sync_transfer_recipient(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_connected_iso_stream_central(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_connected_iso_stream_peripheral(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_iso_broadcaster(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_synchronized_receiver(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_reading_remote_extended_features(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_enhanced_setup_synchronous_connection(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_enhanced_accept_synchronous_connection(const ::bluetooth::shim::rust::Controller &c) noexcept;

bool bluetooth$shim$rust$cxxbridge1$controller_supports_ble_set_privacy_mode(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_acl_buffer_length(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_le_buffer_length(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_iso_buffer_length(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_le_suggested_default_data_length(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_le_maximum_tx_data_length(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_le_maximum_tx_time(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_le_max_advertising_data_length(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint8_t bluetooth$shim$rust$cxxbridge1$controller_get_le_supported_advertising_sets(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint8_t bluetooth$shim$rust$cxxbridge1$controller_get_le_periodic_advertiser_list_size(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint16_t bluetooth$shim$rust$cxxbridge1$controller_get_acl_buffers(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint8_t bluetooth$shim$rust$cxxbridge1$controller_get_le_buffers(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint8_t bluetooth$shim$rust$cxxbridge1$controller_get_iso_buffers(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint8_t bluetooth$shim$rust$cxxbridge1$controller_get_le_connect_list_size(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint8_t bluetooth$shim$rust$cxxbridge1$controller_get_le_resolving_list_size(const ::bluetooth::shim::rust::Controller &c) noexcept;

::std::uint64_t bluetooth$shim$rust$cxxbridge1$controller_get_le_supported_states(const ::bluetooth::shim::rust::Controller &c) noexcept;

void bluetooth$shim$rust$cxxbridge1$controller_get_address(const ::bluetooth::shim::rust::Controller &c, ::rust::String *return$) noexcept;

void bluetooth$shim$rust$cxxbridge1$u8SliceCallback$Run(const ::bluetooth::shim::rust::u8SliceCallback &self, ::rust::Slice<const ::std::uint8_t> data) noexcept {
  void (::bluetooth::shim::rust::u8SliceCallback::*Run$)(::rust::Slice<const ::std::uint8_t>) const = &::bluetooth::shim::rust::u8SliceCallback::Run;
  (self.*Run$)(data);
}

void bluetooth$shim$rust$cxxbridge1$u8SliceOnceCallback$Run(const ::bluetooth::shim::rust::u8SliceOnceCallback &self, ::rust::Slice<const ::std::uint8_t> data) noexcept {
  void (::bluetooth::shim::rust::u8SliceOnceCallback::*Run$)(::rust::Slice<const ::std::uint8_t>) const = &::bluetooth::shim::rust::u8SliceOnceCallback::Run;
  (self.*Run$)(data);
}
} // extern "C"

::std::size_t Stack::layout::size() noexcept {
  return bluetooth$shim$rust$cxxbridge1$Stack$operator$sizeof();
}

::std::size_t Stack::layout::align() noexcept {
  return bluetooth$shim$rust$cxxbridge1$Stack$operator$alignof();
}

::std::size_t Hci::layout::size() noexcept {
  return bluetooth$shim$rust$cxxbridge1$Hci$operator$sizeof();
}

::std::size_t Hci::layout::align() noexcept {
  return bluetooth$shim$rust$cxxbridge1$Hci$operator$alignof();
}

::std::size_t Controller::layout::size() noexcept {
  return bluetooth$shim$rust$cxxbridge1$Controller$operator$sizeof();
}

::std::size_t Controller::layout::align() noexcept {
  return bluetooth$shim$rust$cxxbridge1$Controller$operator$alignof();
}

::rust::Box<::bluetooth::shim::rust::Stack> stack_create() noexcept {
  return ::rust::Box<::bluetooth::shim::rust::Stack>::from_raw(bluetooth$shim$rust$cxxbridge1$stack_create());
}

void stack_start(::bluetooth::shim::rust::Stack &stack) noexcept {
  bluetooth$shim$rust$cxxbridge1$stack_start(stack);
}

void stack_stop(::bluetooth::shim::rust::Stack &stack) noexcept {
  bluetooth$shim$rust$cxxbridge1$stack_stop(stack);
}

::rust::Box<::bluetooth::shim::rust::Hci> get_hci(::bluetooth::shim::rust::Stack &stack) noexcept {
  return ::rust::Box<::bluetooth::shim::rust::Hci>::from_raw(bluetooth$shim$rust$cxxbridge1$get_hci(stack));
}

::rust::Box<::bluetooth::shim::rust::Controller> get_controller(::bluetooth::shim::rust::Stack &stack) noexcept {
  return ::rust::Box<::bluetooth::shim::rust::Controller>::from_raw(bluetooth$shim$rust$cxxbridge1$get_controller(stack));
}

void hci_set_acl_callback(::bluetooth::shim::rust::Hci &hci, ::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback> callback) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_set_acl_callback(hci, callback.release());
}

void hci_set_evt_callback(::bluetooth::shim::rust::Hci &hci, ::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback> callback) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_set_evt_callback(hci, callback.release());
}

void hci_set_le_evt_callback(::bluetooth::shim::rust::Hci &hci, ::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback> callback) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_set_le_evt_callback(hci, callback.release());
}

void hci_send_command(::bluetooth::shim::rust::Hci &hci, ::rust::Slice<const ::std::uint8_t> data, ::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback> callback) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_send_command(hci, data, callback.release());
}

void hci_send_acl(::bluetooth::shim::rust::Hci &hci, ::rust::Slice<const ::std::uint8_t> data) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_send_acl(hci, data);
}

void hci_register_event(::bluetooth::shim::rust::Hci &hci, ::std::uint8_t event) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_register_event(hci, event);
}

void hci_register_le_event(::bluetooth::shim::rust::Hci &hci, ::std::uint8_t subevent) noexcept {
  bluetooth$shim$rust$cxxbridge1$hci_register_le_event(hci, subevent);
}

bool controller_supports_simple_pairing(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_simple_pairing(c);
}

bool controller_supports_secure_connections(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_secure_connections(c);
}

bool controller_supports_simultaneous_le_bredr(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_simultaneous_le_bredr(c);
}

bool controller_supports_interlaced_inquiry_scan(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_interlaced_inquiry_scan(c);
}

bool controller_supports_rssi_with_inquiry_results(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_rssi_with_inquiry_results(c);
}

bool controller_supports_extended_inquiry_response(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_extended_inquiry_response(c);
}

bool controller_supports_role_switch(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_role_switch(c);
}

bool controller_supports_three_slot_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_three_slot_packets(c);
}

bool controller_supports_five_slot_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_five_slot_packets(c);
}

bool controller_supports_classic_2m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_classic_2m_phy(c);
}

bool controller_supports_classic_3m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_classic_3m_phy(c);
}

bool controller_supports_three_slot_edr_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_three_slot_edr_packets(c);
}

bool controller_supports_five_slot_edr_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_five_slot_edr_packets(c);
}

bool controller_supports_sco(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_sco(c);
}

bool controller_supports_hv2_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_hv2_packets(c);
}

bool controller_supports_hv3_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_hv3_packets(c);
}

bool controller_supports_ev3_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ev3_packets(c);
}

bool controller_supports_ev4_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ev4_packets(c);
}

bool controller_supports_ev5_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ev5_packets(c);
}

bool controller_supports_esco_2m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_esco_2m_phy(c);
}

bool controller_supports_esco_3m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_esco_3m_phy(c);
}

bool controller_supports_three_slot_esco_edr_packets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_three_slot_esco_edr_packets(c);
}

bool controller_supports_hold_mode(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_hold_mode(c);
}

bool controller_supports_sniff_mode(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_sniff_mode(c);
}

bool controller_supports_park_mode(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_park_mode(c);
}

bool controller_supports_non_flushable_pb(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_non_flushable_pb(c);
}

bool controller_supports_sniff_subrating(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_sniff_subrating(c);
}

bool controller_supports_encryption_pause(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_encryption_pause(c);
}

bool controller_supports_ble(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ble(c);
}

bool controller_supports_privacy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_privacy(c);
}

bool controller_supports_packet_extension(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_packet_extension(c);
}

bool controller_supports_connection_parameters_request(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_connection_parameters_request(c);
}

bool controller_supports_ble_2m_phy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ble_2m_phy(c);
}

bool controller_supports_ble_coded_phy(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ble_coded_phy(c);
}

bool controller_supports_extended_advertising(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_extended_advertising(c);
}

bool controller_supports_periodic_advertising(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_periodic_advertising(c);
}

bool controller_supports_peripheral_initiated_feature_exchange(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_peripheral_initiated_feature_exchange(c);
}

bool controller_supports_connection_parameter_request(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_connection_parameter_request(c);
}

bool controller_supports_periodic_advertising_sync_transfer_sender(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_periodic_advertising_sync_transfer_sender(c);
}

bool controller_supports_periodic_advertising_sync_transfer_recipient(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_periodic_advertising_sync_transfer_recipient(c);
}

bool controller_supports_connected_iso_stream_central(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_connected_iso_stream_central(c);
}

bool controller_supports_connected_iso_stream_peripheral(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_connected_iso_stream_peripheral(c);
}

bool controller_supports_iso_broadcaster(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_iso_broadcaster(c);
}

bool controller_supports_synchronized_receiver(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_synchronized_receiver(c);
}

bool controller_supports_reading_remote_extended_features(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_reading_remote_extended_features(c);
}

bool controller_supports_enhanced_setup_synchronous_connection(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_enhanced_setup_synchronous_connection(c);
}

bool controller_supports_enhanced_accept_synchronous_connection(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_enhanced_accept_synchronous_connection(c);
}

bool controller_supports_ble_set_privacy_mode(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_supports_ble_set_privacy_mode(c);
}

::std::uint16_t controller_get_acl_buffer_length(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_acl_buffer_length(c);
}

::std::uint16_t controller_get_le_buffer_length(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_buffer_length(c);
}

::std::uint16_t controller_get_iso_buffer_length(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_iso_buffer_length(c);
}

::std::uint16_t controller_get_le_suggested_default_data_length(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_suggested_default_data_length(c);
}

::std::uint16_t controller_get_le_maximum_tx_data_length(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_maximum_tx_data_length(c);
}

::std::uint16_t controller_get_le_maximum_tx_time(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_maximum_tx_time(c);
}

::std::uint16_t controller_get_le_max_advertising_data_length(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_max_advertising_data_length(c);
}

::std::uint8_t controller_get_le_supported_advertising_sets(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_supported_advertising_sets(c);
}

::std::uint8_t controller_get_le_periodic_advertiser_list_size(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_periodic_advertiser_list_size(c);
}

::std::uint16_t controller_get_acl_buffers(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_acl_buffers(c);
}

::std::uint8_t controller_get_le_buffers(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_buffers(c);
}

::std::uint8_t controller_get_iso_buffers(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_iso_buffers(c);
}

::std::uint8_t controller_get_le_connect_list_size(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_connect_list_size(c);
}

::std::uint8_t controller_get_le_resolving_list_size(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_resolving_list_size(c);
}

::std::uint64_t controller_get_le_supported_states(const ::bluetooth::shim::rust::Controller &c) noexcept {
  return bluetooth$shim$rust$cxxbridge1$controller_get_le_supported_states(c);
}

::rust::String controller_get_address(const ::bluetooth::shim::rust::Controller &c) noexcept {
  ::rust::MaybeUninit<::rust::String> return$;
  bluetooth$shim$rust$cxxbridge1$controller_get_address(c, &return$.value);
  return ::std::move(return$.value);
}
} // namespace rust
} // namespace shim
} // namespace bluetooth

extern "C" {
::bluetooth::shim::rust::Stack *cxxbridge1$box$bluetooth$shim$rust$Stack$alloc() noexcept;
void cxxbridge1$box$bluetooth$shim$rust$Stack$dealloc(::bluetooth::shim::rust::Stack *) noexcept;
void cxxbridge1$box$bluetooth$shim$rust$Stack$drop(::rust::Box<::bluetooth::shim::rust::Stack> *ptr) noexcept;

::bluetooth::shim::rust::Hci *cxxbridge1$box$bluetooth$shim$rust$Hci$alloc() noexcept;
void cxxbridge1$box$bluetooth$shim$rust$Hci$dealloc(::bluetooth::shim::rust::Hci *) noexcept;
void cxxbridge1$box$bluetooth$shim$rust$Hci$drop(::rust::Box<::bluetooth::shim::rust::Hci> *ptr) noexcept;

::bluetooth::shim::rust::Controller *cxxbridge1$box$bluetooth$shim$rust$Controller$alloc() noexcept;
void cxxbridge1$box$bluetooth$shim$rust$Controller$dealloc(::bluetooth::shim::rust::Controller *) noexcept;
void cxxbridge1$box$bluetooth$shim$rust$Controller$drop(::rust::Box<::bluetooth::shim::rust::Controller> *ptr) noexcept;

static_assert(::rust::detail::is_complete<::bluetooth::shim::rust::u8SliceCallback>::value, "definition of u8SliceCallback is required");
static_assert(sizeof(::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback>) == alignof(void *), "");
void cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceCallback$null(::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback>();
}
void cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceCallback$raw(::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback> *ptr, ::bluetooth::shim::rust::u8SliceCallback *raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback>(raw);
}
const ::bluetooth::shim::rust::u8SliceCallback *cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceCallback$get(const ::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback>& ptr) noexcept {
  return ptr.get();
}
::bluetooth::shim::rust::u8SliceCallback *cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceCallback$release(::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback>& ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceCallback$drop(::std::unique_ptr<::bluetooth::shim::rust::u8SliceCallback> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::bluetooth::shim::rust::u8SliceCallback>::value>{}(ptr);
}

static_assert(::rust::detail::is_complete<::bluetooth::shim::rust::u8SliceOnceCallback>::value, "definition of u8SliceOnceCallback is required");
static_assert(sizeof(::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback>) == sizeof(void *), "");
static_assert(alignof(::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback>) == alignof(void *), "");
void cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceOnceCallback$null(::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback> *ptr) noexcept {
  ::new (ptr) ::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback>();
}
void cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceOnceCallback$raw(::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback> *ptr, ::bluetooth::shim::rust::u8SliceOnceCallback *raw) noexcept {
  ::new (ptr) ::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback>(raw);
}
const ::bluetooth::shim::rust::u8SliceOnceCallback *cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceOnceCallback$get(const ::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback>& ptr) noexcept {
  return ptr.get();
}
::bluetooth::shim::rust::u8SliceOnceCallback *cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceOnceCallback$release(::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback>& ptr) noexcept {
  return ptr.release();
}
void cxxbridge1$unique_ptr$bluetooth$shim$rust$u8SliceOnceCallback$drop(::std::unique_ptr<::bluetooth::shim::rust::u8SliceOnceCallback> *ptr) noexcept {
  ::rust::deleter_if<::rust::detail::is_complete<::bluetooth::shim::rust::u8SliceOnceCallback>::value>{}(ptr);
}
} // extern "C"

namespace rust {
inline namespace cxxbridge1 {
template <>
::bluetooth::shim::rust::Stack *Box<::bluetooth::shim::rust::Stack>::allocation::alloc() noexcept {
  return cxxbridge1$box$bluetooth$shim$rust$Stack$alloc();
}
template <>
void Box<::bluetooth::shim::rust::Stack>::allocation::dealloc(::bluetooth::shim::rust::Stack *ptr) noexcept {
  cxxbridge1$box$bluetooth$shim$rust$Stack$dealloc(ptr);
}
template <>
void Box<::bluetooth::shim::rust::Stack>::drop() noexcept {
  cxxbridge1$box$bluetooth$shim$rust$Stack$drop(this);
}
template <>
::bluetooth::shim::rust::Hci *Box<::bluetooth::shim::rust::Hci>::allocation::alloc() noexcept {
  return cxxbridge1$box$bluetooth$shim$rust$Hci$alloc();
}
template <>
void Box<::bluetooth::shim::rust::Hci>::allocation::dealloc(::bluetooth::shim::rust::Hci *ptr) noexcept {
  cxxbridge1$box$bluetooth$shim$rust$Hci$dealloc(ptr);
}
template <>
void Box<::bluetooth::shim::rust::Hci>::drop() noexcept {
  cxxbridge1$box$bluetooth$shim$rust$Hci$drop(this);
}
template <>
::bluetooth::shim::rust::Controller *Box<::bluetooth::shim::rust::Controller>::allocation::alloc() noexcept {
  return cxxbridge1$box$bluetooth$shim$rust$Controller$alloc();
}
template <>
void Box<::bluetooth::shim::rust::Controller>::allocation::dealloc(::bluetooth::shim::rust::Controller *ptr) noexcept {
  cxxbridge1$box$bluetooth$shim$rust$Controller$dealloc(ptr);
}
template <>
void Box<::bluetooth::shim::rust::Controller>::drop() noexcept {
  cxxbridge1$box$bluetooth$shim$rust$Controller$drop(this);
}
} // namespace cxxbridge1
} // namespace rust
