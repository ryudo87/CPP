
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
