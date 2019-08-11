# NAME MANGLE

Since C++ has overloading of function names and C does not, so it mangles the name by adding information about the arguments. A C compiler does not need to mangle the name since you can not overload function names in C. 
 When you state that a function has extern "C" linkage in C++,
the C++ compiler does not add argument/parameter type information to the name used for linkage.

extern "C" makes a function-name in C++ have 'C' linkage (compiler does not mangle the name)  

final class: private constructor
-----extern c----
in c++ to indicate a C function
#ifdef __cplusplus
extern "C"{
#endif

#ifdef __cplusplus
}
#endif
