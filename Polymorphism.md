# static Polymorphism
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
