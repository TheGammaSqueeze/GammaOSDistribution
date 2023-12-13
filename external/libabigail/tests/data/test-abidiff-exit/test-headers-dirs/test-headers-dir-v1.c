/*
 * Compile this test with:
 *   gcc -c -g test-headers-dir-v1.c
 *
 *   This test exhibits changes that are redundant in a weird way.
 *   The redundant path through the diff graph involves typedefs,
 *   function types and function parameter diff nodes.
 *
 */

#include "headers-b/header-b-v1.h"
#include "headers-a/header-a-v1.h"

struct opaque_struct
{
  int m0;
  int m1;
  struct public_struct_type *m2;
  char m3;
};

struct second_opaque_struct
{
  int m0;
  char m1;
};

void foo(public_struct_pointer_type p __attribute__((unused)))
{
}

void
bar(second_public_struct_pointer_type p1 __attribute__((unused)),
    second_opaque_struct_pointer_type p2 __attribute__((unused)))
{
}
