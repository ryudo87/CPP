#include <algorithm>
bool mycomp(int i, int j) {return i>j;}
struct mystruct {
    bool operator() (int i, int j) {return i>j;}
} myobject;

vector<int> a{2,1,3};
sort(a.begin(), a.end(), less<int>());
sort(a.begin(), a.end(), [](int a, int b) {return a>b;});
sort(a.begin()+1, a.end(), mycomp);
sort(a.begin(), a.end(), myobject);

std::fill(v.begin(), v.end(), -2);

a.insert(a.begin(),  33); //insert 33 before begin()
a.insert(a.begin(), 2, 44);//insert two 44
a.erase(a.begin(), a.begin()+2); //remove from begin() -> begin()+2
a.erase(a.begin()+1);//remove 2nd element


std::copy(a.begin(), a.end(), std::ostream_iterator<int>(std::cout, ","));
//C++20 introduced ranges
std::ranges::copy(a, std::ostream_iterator<int>(std::cout, " "));
