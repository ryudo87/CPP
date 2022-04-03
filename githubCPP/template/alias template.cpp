template<typename T>
using Vec = std::vector<T>;

//Alias Template



int main() {
    Vec<int> vc {1,2,3};
    std::copy(vc.begin(), vc.end(),
              std::ostream_iterator<int>(std::cout, ","));
    std::cout << "Hello World!\n";
}
