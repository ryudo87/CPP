namespace {
    template <typename T>
    struct less : public binary_function<T, T, bool> {
        bool operator()(const T& x, const T& y) const {
            return x<y;
        }
    };
}

int main() {
    
}
