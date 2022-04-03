# 1
Implement a template boolean IsSameClass() that takes class A and B as template parameters. It should compare class A and B and return false when they are different classes and true if they are the same class.

template <typename T, typename U>
struct is_same
{
    static const bool value = false;
};

template <typename T>
struct is_same<T, T>
{
    static const bool value = true;
};


template <class A, class B>
bool IsSameClass() {
    return is_same<A, B>::value;
}

# 2 
Implement a template function IsDerivedFrom() that takes class C and class P as template parameters. 
It should return true when class C is derived from class P and false otherwise.


template<typename D, typename B>
class IsDerivedFromHelper
{
    class No { };
    class Yes { No no[3]; };
    
    static Yes Test( B* );
    static No Test( ... );
public:
    enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };
    
};


template <class C, class P> 
bool IsDerivedFrom() {
    return IsDerivedFromHelper<C, P>::Is;
}


class No { }; - defines a class, which will have an undefined size, which won't be zero (mandated by the standard)

class Yes { No no[3]; }; - defines another class, Yes which will be at least 3 times as big as a No. So they are guaranteed to be different sizes.

static Yes Test( B* ); - declare a function which returns a Yes, but don't give it a definition (we don't need one). It will match any pointer argument which is pointing to an object derived from B.

static No Test( ... ); - declare a function which returns a No (smaller, remember?). It's an overload which will be selected if the more specific one (above) cannot be satisfied. It accepts any argument (but the other version will be selected by overload resolution in preference if the argument is derived from B).

sizeof(Test(static_cast<D*>(0))) deduces the size of the object returned by Test when passes a pointer to a D. If D is derived from B, it will be a Yes, otherwise it will be a No.

Because the 'call' is made in a non-deduced context, it is not evaluated (called), just selected and return type deduced.

The rest is probably self-explanatory. turns out it wasn't :)

So this all gets put together here:

enum { Is = sizeof(Test(static_cast<D*>(0))) == sizeof(Yes) };

What this is doing in a nutshell, is saying:

"declare a constant called Is, which will be true if the result of calling Test with a D* is a type that happens to be the same size as a Yes. And it will be false if the result of the call happens to be a type which is a different size. Because of the two overloads, above, when D is a B, or anything derived from it, Test(D*) will select the Yes version, which will return a Yes, which is obviously the same size as a Yes. If this overload is not selected, the more permissive (but lower priority) one will be. That one returns a No, which obviously won't be the same size as a Yes (by definition)."


# 3
How can you make sure a C++ function can be called as e.g. void foo(int, int) but not as any other type like void foo(long, long)?
void foo(int a, int b) {
// whatever
}
template <typename T1, typename T2> void foo(T1 a, T2 b) = delete;


### Or without the delete keyword:

template <class T, class U> 
void f(T arg1, U arg2);

template <>
void f(int arg1, int arg2)
{
    //...    
}
