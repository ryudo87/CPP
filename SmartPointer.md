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

