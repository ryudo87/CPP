A virtual function allows **derived classes to replace the implementation of the base class**. 
The compiler makes sure the replacement is always called whenever the object in question is actually of the derived class

调用虚函数的时候，首先根据对象里存储的虚函数表指针，找到虚函数表，再根据偏移量找到哪一项，再找到虚函数地址

## When should my destructor be virtual?

When you may delete a derived object via a base pointer.



虚函数影响效率有两点原因，第一，Cache命中率不够好，一般函数可能编译后的指令就在当前函数地址附近，这样很可能在调用前目标函数代码已经被载入指令cache. 但是虚拟函数不在cache中的概率高。
 第二点编译器不好优化。因为编译器只知道你要调用的是一个不确定的地址处的函数，也就没法替你做更多优化。


虚函数慢的原因主要有三个：

		多了几条汇编指令（运行时得到对应类的函数的地址）
		影响cpu流水线
		编译器不能内联优化（仅在用父类引用或者指针调用时，不能内联）


cache比较小，级别比较少，加上RAM的速度普遍很慢、延迟较高，一旦发生cache miss的开销很惊人。




类的长度：带虚函数的类的长度要多一个void指针的长度。它指向虚表。
         若类没有数据成员，会有一个哑成员（长度为1），若有虚函数，哑成员的位置就被占用了。
构造函数和拷贝构造函数负责初始化VPTR 使其指向虚表vtable。


在析构函数中调用虚函数时， 也是调用的是函数的本地版本。虚机制不起作用。
   这是因为，虽然类型信息（VPTR）存在，但不可靠，因为派生类的析构函数已经调用了，对象可能删除了。
   
   
//Effect of calling virtual function in C++ constructor
//Virtual table is not created when constructor is called.. 
//calls local version of the function
class C
{public:
	C(){f();}
	virtual void f(){cout<<"C::f"<<endl;}
};
class D:public C
{
public:
	D(){}
	void f(){cout<<"D::f"<<endl;}
};

int main()
{
	C* d=new D();  //C::f
}



42. 	
In which of the following a virtual call is resolved at the time of compilation?

A.	From inside the destructor.
B.	From inside the constructor.
C.	From inside the main().
D.	Both A and B.
Answer: Option D

虚函数（virtual）可以是内联函数（inline）吗？

Are "inline virtual" member functions ever actually "inlined"?
虚函数可以是内联函数，内联是可以修饰虚函数的，但是当虚函数表现多态性的时候不能内联。
内联是在编译器建议编译器内联，而虚函数的多态性在运行期，编译器无法知道运行期调用哪个代码，因此虚函数表现为多态性时（运行期）不可以内联。
inline virtual 唯一可以内联的时候是：编译器知道所调用的对象是哪个类（如 Base::who()），这只有在编译器具有实际对象而不是对象的指针或引用时才会发生。
