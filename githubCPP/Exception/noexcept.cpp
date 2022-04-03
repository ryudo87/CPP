//need to inform C++(specifically vector) : move constructor and destructor doesNOT throw. Then move constructor will be called when vector grows
class MyString {
    char* _data;
    size_t _len;
public:
    MyString(MyString&& str) noexcept
    : _data(str._data), _len(str._len) {}
    //move assignment
    MyString& operator=(MyString&& str) noexcept {
        //....
        return *this;
    }
};
int main() {
    
}
