// Compile this with:
//  g++ -Wall -g -shared -Wl,--version-script=test3-fn-removed-version-script-1 -o libtest3-fn-removed-v1.so test3-fn-removed-v1.cc 

int
_internal_fun0()
{return 0;}

asm(".symver _Z14_internal_fun0v,_Z4fun0v@@VERSION_1.0");

void
_internal_fun1()
{
}

asm(".symver _Z14_internal_fun1v,_Z4fun1v@@VERSION_2.0");
