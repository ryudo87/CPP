# storage class
A class that specifies the life and scope of its variables and functions is called a storage class.

storage classes are supported: static, extern, and mutable

# What are the advantages of using friend classes?

- Friend classes are useful when a class wants to hide features from users which are needed only by another, tightly coupled class. 
- Implementation details can be kept safe by providing friend status to a tightly cohesive class.




# NAME MANGLE （How can a C function be called in a C++ program? extern "C")

Since C++ has overloading of function names and C does not, so it mangles the name by adding information about the arguments. A C compiler does not need to mangle the name since you can not overload function names in C. 
 When you state that a function has extern "C" linkage in C++,
the C++ compiler does not add argument/parameter type information to the name used for linkage.

extern "C" makes a function-name in C++ have 'C' linkage (compiler does not mangle the name)  


in c++ to indicate a C function

#ifdef __cplusplus

extern "C"{

#endif

#ifdef __cplusplus

}

#endif


### static keyword

  在c++中，全局静态对象的构造函数顺是在main之前调用的。因而可以使程序在进入main之前执行一段代码。
  一个被声明为static的对象或名字对出现声明的.cpp文件来说是局部于该单元的。
  一旦进入局部变量，static就不会再改变变量的可见性，只改变其存储类型。
  对于函数名，static和extern只改变它们的可见性。所以 extern void f(); 与void f();一样。而static void f(); 则f只在本翻译单元内可见，称为：文件静态。
  类的静态数据成员 的定义只能出现在类的外部，而且只能定义一次。
  
## Item 20:  Facilitate the return value optimization. 
class Rational {
public:
  Rational(int numerator = 0, int denominator = 1);
  int numerator() const;
  int denominator() const;
};

  // an efficient and correct way to implement a function that returns an object
const Rational operator*(const Rational& lhs, const Rational& rhs)
{
  return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}


you pay for only one constructor call — the one to create c. 
// the most efficient way to write a function returning an object
inline const Rational operator*(const Rational& lhs, const Rational& rhs)
{  return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator()); }

# 构造函数的 using 声明

在 C++11 中，派生类能够重用其直接基类定义的构造函数。

class Derived : Base {
public:
    using Base::Base;
    /* ... */
};
如上 using 声明，对于基类的每个构造函数，编译器都生成一个与之对应（形参列表完全相同）的派生类构造函数。生成如下类型构造函数：

Derived(parms) : Base(args) { }
