typedef void (*FUNC)(int, int);
using MYFUNC = void(*)(int, int);
void example(int, int) {cout<<"example"<<endl;}

template <typename T>
struct Conatainer {
    typedef T VALUE_TYPE;
    using MY_VALUE_TYPE=T;
    void prnt(MY_VALUE_TYPE&& mvt){cout<<mvt<<endl;}
};
int main() {
    FUNC fn = example;
    auto myfunc = example;
    fn(2, 3);myfunc(2,4);
    //
    Conatainer<int>::MY_VALUE_TYPE tmp = 3;
    Conatainer<string>::VALUE_TYPE vt = "abc";
    
    Conatainer<string>().prnt("ddd");//temp object
}
