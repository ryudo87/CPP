void printX(){}

template<typename T, typename... Types>
void printX(const T& firstArg, const Types&... args)
{
    cout<<firstArg<<","<<endl;
    printX(args...);
}

int main() {
    printX(7.5, "hi", bitset<16>(377), 42);
}
