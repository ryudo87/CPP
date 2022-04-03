
# virtual inheritance 虚继承


虚继承用于解决多继承条件下的菱形继承问题（浪费存储空间、存在二义性）。

底层实现原理与编译器相关，一般通过虚基类指针和虚基类表实现，每个虚继承的子类都有一个虚基类指针（占用一个指针的存储空间，4字节）和虚基类表（不占用类对象的存储空间）（需要强调的是，虚基类依旧会在子类里面存在拷贝，只是仅仅最多存在一份而已，并不是不在子类里面了）；当虚继承的子类被当做父类继承时，虚基类指针也会被继承。

实际上，vbptr 指的是虚基类表指针（virtual base table pointer），该指针指向了一个虚基类表（virtual table），虚表中记录了虚基类与本类的偏移地址；通过偏移地址，这样就找到了虚基类成员，而虚继承也不用像普通多继承那样维持着公共基类（虚基类）的两份同样的拷贝，节省了存储空间。

那么类D对象的内存布局就变成如下的样子：



vbptr：继承自父类B中的指针

int dataB：继承自父类B的成员变量

vbptr：继承自父类C的指针

int dataC：继承自父类C的成员变量

int dataD：D自己的成员变量

int A：继承自父类A的成员变量



显然，虚继承之所以能够实现在多重派生子类中只保存一份共有基类的拷贝，关键在于vbptr指针。那vbptr到底指的是什么？又是如何实现虚继承的呢？其实上面的类D内存布局图中已经给出答案：

实际上，vbptr指的是虚基类表指针（virtual base table pointer），该指针指向了一个虚表（virtual table），虚表中记录了vbptr与本类的偏移地址；第二项是vbptr到共有基类元素之间的偏移量。在这个例子中，类B中的vbptr指向了虚表D::$vbtable@B@，虚表表明公共基类A的成员变量dataA距离类B开始处的位移为20，这样就找到了成员变量dataA，而虚继承也不用像普通多继承那样维持着公共基类的两份同样的拷贝，节省了存储空间




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


