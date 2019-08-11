
# virtual inheritance

class Base
{
   public:
     int data;
};
class DerivedOne : public Base {};
class DerivedTwo : public Base {};
class Derived : public DerivedOne, public DerivedTwo {};
void main()
{
   Derived obj;
   obj.data = 5;
}
A. Inherit class Derived from DerivedOne and DerivedTwo as virtual public DerivedOne and virtual public DerivedTwo.
B. Inherit class Derived from DerivedOne and DerivedTwo as public virtual DerivedOne and public virtual DerivedTwo.
C. Inherit classes DerivedOne and DerivedTwo from Base as public virtual Base.
D. Inherit classes DerivedOne and DerivedTwo from Base as virtual public Base.
E. Inherit either class DerivedOne or class DerivedTwo from Base as virtual public Base.

The answer is C & D. This is known as the diamond Inheritance problem.


========================
Q11.: The following code will result in a memory leak.
class base {
 public: 
   base () { ptr = new int[1024]; }
   ~base () { delete [] ptr; }
 private:
   double *ptr;
};
class der : public base {
 public:
   der () { name = new char[1024]; }
   ~der () { delete [] name; }
 private:
   char *name;
};
int main () {
  base* aPointer = new derived;
  delete aPointer;
  return 0;
}

Which of the following statements can be used to solve this problem?
A. Define the destructor of the der class as virtual;
B. Define the aPointer as a pointer of the der class;

C. Define the ptr as a member of the der class, move the allocation statement from the constructor of the base class to the der constructor and finally move the deallocation statement from the base class destructor to the der class destructor;
D. Define the destructor of the base class as virtual;

The answer is C & D. The problem with the above code is due to the fact that when the der class gets destructed it will not call the destructor of the base class. Thus leaving the ptr pointer not deallocated i.e. memory leak. The solution is to add the virtual tag to the destructor of the base class. The alternative solution is to move the ptr pointer to the der class. This will still not fix the problem of calling the base destructor but since the base destructor doesn’t have the job of deallocating the ptr pointer anymore, everything will be fine.


