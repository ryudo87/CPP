
struct BaseC {
    virtual void vfunc(float) {std::cout << "Base\n";}
    virtual void f() final {};//only virtual function
};
struct DerivedC : BaseC {
    void vfunc(float) override //only virtual member functions can be marked 'override'
    {std::cout << "Derived\n";}
};

struct Base1 final {}; // cannot be derived

int main() {
    BaseC b;
    b.vfunc(2.3);
    unique_ptr<BaseC> bp = make_unique<DerivedC>();
    bp->vfunc(2.3);
}
