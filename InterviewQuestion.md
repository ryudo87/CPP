https://eli.thegreenplace.net/2008/08/23/initializing-an-array-in-constant-time
/*
You have an array A of N integers (N is very large) to initialize with a value K (i.e., you want A[i] = K for every 0 <= i < N). Your computer has a lot of memory, so space isn't an issue, but its cache and CPU are slow. 

Your task is to write a class, ConstantInit, that allows you to initialize the array in O(1); i.e., in constant time (O(1)). Obviously, you can't actually initialize every N value and achieve O(1). Your class must support 3 methods:
   1) Initialization/creation (taking the integer values for the size (N) and the initial value (K))
   2) int read(int index): returns the value of A[index], which should be the initial value K if the A[index] has not been written to since they ConstantInit object was created, or the last value V that was written into A[index].
   3) void write(int index, int value): writes the given value into A[index].

Hint: because space is not a constraint, use auxiliary arrays.
*/

# Explain storage qualifiers in C++.

1. Const : This variable means that if the memory is initialised once, it should not be altered by a program. 
2. Volatile : This variable means that the value in the memory location can be altered even though nothing in the program code modifies the contents. 
3. Mutable : This variable means that a particular member of a structure or class can be altered even if a particular structure variable, class or class member function is constant.

# In what situations do you have to use initialization list rather than assignment in constructors?

- When you want to use non-static const data members and reference data members 

# Stack unwinding.

Stack unwinding is a process during exception handling when the destructor is called for all local objects between the place where the exception was thrown and where it is caught.
