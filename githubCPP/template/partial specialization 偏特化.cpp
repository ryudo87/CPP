template <class Key> struct MyHash {};

inline size_t __stl_hash_string(const char* s) {
    size_t h=0;
    for (;*s;++s) {h = 5*h + *s;}
    return h;
}
template <> struct MyHash<char*> {
    size_t operator()(const char* s) const { return __stl_hash_string(s);}
};
template <> struct MyHash<char> {
    size_t operator()(char x) const { return x;}
};
template <> struct MyHash<short> {
    size_t operator()(char x) const { return x;}
};

int main() {
    MyHash<char> myhash;
    MyHash<char*> myhash;
    
}
