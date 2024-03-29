# 成员初始化列表

更高效：少了一次调用默认构造函数的过程。
有些场合必须要用初始化列表：
常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化

constructors should catch all possible exceptions thrown by ctors , 
and then re-throw only those exceptions it cannot handle. 
And destructors should never throw; doing so could leak resources. 

构造函数中抛出异常，会导致析构函数不能被调用， 因为析构函数不能被调用，所以可能会造成内存泄露或系统资源未被释放。

Q22. In standard C++, which of the following statements, concerning the order of destruction is true?
A. The destructor for a class object is called before destructors for members and bases are called.
B. Destructors for nonstatic members are called before destructors for base classes are called.
D. Destructors for nonvirtual base classes are called before destructors for virtual base classes are called.
The answer is A, B & D.


在构造函数前加explicit 可以防止使用这个构造函数执行任何自动转换。

  
  条款15: 让operator=返回*this的引用
	当定义自己的赋值运算符时，必须返回赋值运算符左边参数的引用，*this。（非const，以便使(w1 = w2) = w3; 合法）
	如果不这样做，就会导致不能连续赋值，或导致调用时的隐式类型转换不能进行，或两种情况同时发生。

条款16: 在operator=中对所有数据成员赋值
	operator=中需要显示的对基类中的数据赋值。
	// 正确的赋值运算符
	derived& derived::operator=(const derived& rhs)
	{
	  if (this == &rhs) return *this;

	  base::operator=(rhs);    // 调用this->base::operator=
	  y = rhs.y;
	  return *this;
	}
    
# When do you call copy constructors? 

Copy constructors are called in these situations : 
1. generates a temporary object. 
2.a function returns an object  by value .
3. object is passed by value as an argument to a function .
4. When you construct an object based on another object of the same class.   

# Name the implicit member functions of a class.

1. default constructor 
2. copy constructor 
3. assignment operator 
4. default destructor 
5. move copy constructor

# Q7. Considering the following C++ code snippet, which of the following statements are true?
class MyArray
{
    int *ptr;
  public: 
    MyArray (void) {}
    MyArray (int *p) { ptr = p; }
    ~MyArray (void) { delete ptr; }
};
void main()
{
   int *p = new int; 
   MyArray a(p), b;
   b = a;
}
A. The program will terminate gracefully;
B. The program will crash when object “a” gets destructed;
C. The program will crash when object “b” gets destructed;
D. The program will crash when pointer “p” gets deallocated;
E. The program will show a compilation error at line “b = a” because class MyArray doesn’t overload a definition for the “operator=” function;


The answer is B, object “a” will be pushed first in the stack followed by “b”. The ptr member variable of both objects “a and b” will then point to the same location in memory after the execution of line “b = a”. When the program finishes, object “b” will be popped first from the stack leading to the deallocation of the memory location assigned to the pointer ptr of object “b”. Finally when object “a” gets popped it will try to deallocate the same memory location that has been deallocated by object “b” leading to a program crash.
