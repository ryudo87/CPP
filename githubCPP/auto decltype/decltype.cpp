//use 1) declare return type C++11
template<typename T1, typename T2>
auto add(T1 x, T2 y) -> decltype(x+y) {return x+y;}
//       declare return type C++14
template<typename T1, typename T2>
auto minus(T1 x, T2 y)  {return x-y;}

int main() {
    map<string, float> coll {{"aa", 1.5}, {"bb", 2.5}};
    auto it = coll.begin();
    std::cout << it->first<<std::endl;
    for (const auto&[key, val] : coll)
        std::cout <<key<< ":"<<val<<std::endl;
    
    //use 2) metaprogramming
    decltype(coll)::value_type elem = {"c", 3.2};
    std::cout << elem.first<<std::endl;
    
    //use 3) decltype in lambda
    auto cmp = [](int a, int b){return a>b;};//==greater<int>
    set<int, decltype(cmp)> coll(cmp);
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
}


