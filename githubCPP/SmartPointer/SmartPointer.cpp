template <class T>
  
class auto_ptr 
{
  T* pointee;
public:
  auto_ptr(const auto_ptr<T>& rhs) {
    pointee = rhs.pointee;
    rhs.pointee = nullptr;
  }
  auto_ptr<T>& operator=(const auto_ptr<T>& rhs) {
    if (this == &rhs) return *this;
    delete pointee; 
    pointee = rhs.pointee;
    rhs.pointee = nullptr;
    return *this;
  }
  T* operator->() const {
    return pointee;
  }
};
 
template<class T>
class SmartPointer
{
  T* ref;
  unsigned* ref_count;
public:
  SmartPointer(T* t) {
    ref = t;
    ref_count = new unsigned(1);
  }
  SmartPointer(const SmartPointer<T>& rhs) {
    ref_count = rhs.ref_count;
    *ref_count++;
    ref = rhs.ref;
  }
  
  SmartPointer<T>& operator=(const SmartPointer<T>& rhs) {
    if (this == &rhs) return *this;
    if (ref_count ** --*ref_count == 0) {
      delete ref; ref=nullptr;
      delete ref_count; ref_count=nullptr;
    }
    ref = rhs.ref;
    ref_count = rhs.ref_count;
    ++*ref_count;
    return *this;
  }
  ~SmartPointer() {
    --*ref_count;
    if (*ref_count == 0) {
      delete ref; ref=nullptr;
      delete ref_count; ref_count=nullptr;
    }
  }
  T* operator->() const {
    return ref;
  }
  T& operator*(){return *ref;}
};
  

# unique_ptr 是一个独享所有权的智能指针，它提供了严格意义上的所有权，包括：

1、拥有它指向的对象

2、无法进行复制构造，无法进行复制赋值操作。即无法使两个unique_ptr指向同一个对象。但是可以进行移动构造和移动赋值操作
另外注意的是当把它当做参数传递给函数时（使用值传递，应用传递时不用这样），传实参时也要使用std::move

std::unique_ptr<int> p1(new int(5));
std::unique_ptr<int> p2 = p1; // 编译会出错
std::unique_ptr<int> p3 = std::move (p1); // 转移所有权，现在那块内存归p3所有, p1成为无效的指针。

p3.reset(); //释放内存。
p1.reset(); //实际上什么都没做。

# weak_ptr
std::shared_ptr使用引用计数，所以有循环计数的问题。为了打破循环，可以使用std::weak_ptr.顾名思义, weak_ptr是一个弱引用，只引用，不计数。如果一块内存被shared_ptr和weak_ptr同时引用，当所有shared_ptr析构了之后，不管还有没有weak_ptr引用该内存，内存也会被释放。所以weak_ptr不保证它指向的内存一定是有效的，在使用之前需要检查。

std::shared_ptr<int> p1(new int(5));
std::weak_ptr<int> wp1 = p1; // 还是只有p1有所有权。

{
  std::shared_ptr<int> p2 = wp1.lock(); // p1和p2都有所有权
  if (p2) // 使用前需要检查
  { 
    // 使用p2
  }
} // p2析构了，现在只有p1有所有权。

p1.reset(); // 内存被释放。

std::shared_ptr<int> p3 = wp1.lock(); // 因为内存已经被释放了，所以得到的是空指针。
if（p3）
{
  // 不会执行到这。
}

# std::make_shared performs one heap-allocation, whereas calling the std::shared_ptr constructor performs two.
Where do the heap-allocations happen?
std::shared_ptr manages two entities:

the control block (stores meta data such as ref-counts, type-erased deleter, etc)
the object being managed
std::make_shared performs a single heap-allocation accounting for the space necessary for both the control block and the data. In the other case, new Obj("foo") invokes a heap-allocation for the managed data and the std::shared_ptr constructor performs another one for the control block.

## Update I: Exception-Safety

Since the OP seem to be wondering about the exception-safety side of things, I've updated my answer.

Consider this example,

void F(const std::shared_ptr<Lhs> &lhs, const std::shared_ptr<Rhs> &rhs) { /* ... */ }

F(std::shared_ptr<Lhs>(new Lhs("foo")),
  std::shared_ptr<Rhs>(new Rhs("bar")));
Because C++ allows arbitrary order of evaluation of subexpressions, one possible ordering is:

new Lhs("foo"))
new Rhs("bar"))
std::shared_ptr<Lhs>
std::shared_ptr<Rhs>
Now, suppose we get an exception thrown at step 2 (e.g., out of memory exception, Rhs constructor threw some exception). We then lose memory allocated at step 1, since nothing will have had a chance to clean it up. The core of the problem here is that the raw pointer didn't get passed to the std::shared_ptr constructor immediately.
