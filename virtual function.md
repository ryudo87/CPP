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
