#include <dlfcn.h>
#include <stdio.h>

// Mark foo and bar weak so that Clang allows the run-time linker to decide which DSO's symbol to
// use.

__attribute__((weak)) extern "C" void foo() {
  printf("foo lib3\n");
  void (*next)(void) = reinterpret_cast<void (*)()>(dlsym(RTLD_NEXT, "foo"));
  if (next != nullptr) next();
}

__attribute__((weak)) extern "C" void bar() {
  printf("bar lib3\n");
  void (*next)(void) = reinterpret_cast<void (*)()>(dlsym(RTLD_NEXT, "bar"));
  if (next != nullptr) next();
}

void lib3_call_funcs() {
  printf("lib3_call_funcs\n");
  foo();
  bar();
}
