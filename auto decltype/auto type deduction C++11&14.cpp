template<typename T>
auto count_things(const vector<T>& vec, T value)
{
    const auto cnt = std::count(begin(vec), end(vec), value);
    return cnt;
}

int main() {
    vector<long> v{1,2,3,4};
    
    std::cout << count_things<long>(v, 3);
    
    auto lambda = [](int x) -> bool {return x>3;};
}
