constexpr int get_value()
{
    int a = 4, b = 5;
    return a*b;
}
int main() {
    constexpr auto i = 3*5;//value available in compile time
    vector<int> v (i, i+1);
    std::cout << get_value();
}
