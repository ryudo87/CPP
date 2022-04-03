int main() {
    map<string, int> m {{"a", 1}, {"b", 2}};
    m.insert({"c", 3});
    m.erase("a");
    for (const auto kv : m) {
        cout<<" key:"<<kv.first<<" value:"<<kv.second<<endl;
    }
    for (const auto [key, value] : m) {
        std::cout << key <<":"<<value<<","<< "\n";
    }
    
    unordered_map<string, int> mymap;
    mymap["ab"] = 2;
    cout<<mymap.count("ab")<<endl;
    
    
    
    
    
    multimap<string, int> mymulmap;
    mymulmap.insert({"aa", 1});//call RB_tree insert_equal()
    mymulmap.insert({"aa", 2});
    // mymulmap["aa"] = 3;//no overloaded operator[] for multimap
    for (auto [key, value] : mymulmap) {
        std::cout << key <<":"<<value<<","<< "\n";
    }
    cout<<mymulmap.count("aa");
}
