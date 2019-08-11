# dynamic Polymorphism
Overriding is Dynamic polymorphism
如果真的要完全移除虚函数，那么如果要实现运行时多态，则要用到函数指针

C++ allows static type checking.
C++ allows dynamic type checking.


Dynamic type checking occurs when type information is used at runtime. C++ uses a mechanism called RTTI (runtime type information) to implement this. The most common example where RTTI is used is the dynamic_cast operator 


# static Polymorphism
Overloading is static polymorphic

## 奇异递归模板模式（curiously recurring template pattern，CRTP)
**a class X derives from a class template instantiation using X itself as template argument.**
把派生类作为基类的模板参数。更一般地被称作F-bound polymorphism

## CRTP的特点

继承自模板类；inherit from template class  使用派生类作为模板参数  特化基类；





CRTP所带来的静态多态
#### **CRTP的存在是为了消除vtable，避免动态查找vfunc的开销**，用到多态的地方都可以用CRTP来改写

template<typename Derived>
class Animal
{
public:
    void eat() { static_cast<Derived*>(this)->eat(); }
};

class Lion : public Animal<Lion> { void eat(); }
class Cat : public Animal<Cat> { void eat(); }

template <typename T>
void func(Animal<T>& animal) { animal.eat(); }

// 使用：
Lion a; Cat b;
func(a);
func(b);

#### CRTP另外的用处就是定义抽象方法





Q23. Which of the following statements describe the use of the terms overloading and overriding in C++?

B. Overloading is used to give special meaning to operators, when they are used with user-defined classes.

D. Overriding is a concept used in inheritance which involves a method with one implementation in the base class and a different implementation in the derived class.
E. Overloading involves functions with the same name but with either a different arguments or a return type while overriding involves functions with the same name, arguments and return type but a different implementation.

The answer is B, D & E.

