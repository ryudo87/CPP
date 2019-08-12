/*
You have an array A of N integers (N is very large) to initialize with a value K (i.e., you want A[i] = K for every 0 <= i < N). Your computer has a lot of memory, so space isn't an issue, but its cache and CPU are slow. 

Your task is to write a class, ConstantInit, that allows you to initialize the array in O(1); i.e., in constant time (O(1)). Obviously, you can't actually initialize every N value and achieve O(1). Your class must support 3 methods:
   1) Initialization/creation (taking the integer values for the size (N) and the initial value (K))
   2) int read(int index): returns the value of A[index], which should be the initial value K if the A[index] has not been written to since they ConstantInit object was created, or the last value V that was written into A[index].
   3) void write(int index, int value): writes the given value into A[index].

Hint: because space is not a constraint, use auxiliary arrays.
*/
