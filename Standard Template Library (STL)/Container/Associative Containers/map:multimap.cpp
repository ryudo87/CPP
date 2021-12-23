int main() {
    map<string, int> mymap; multimap<string, int> mymulmap;
    mymap.insert({"aa", 1});//call RB_tree insert_unique()
    mymap.insert({"aa", 1});
    for (auto [key, value] : mymap) {
        std::cout << key <<":"<<value<<",";
    }
    std::cout << "\n";
    
    mymulmap.insert({"aa", 1});//call RB_tree insert_equal()
    mymulmap.insert({"aa", 2});
    // mymulmap["aa"] = 3;//no overloaded operator[] for multimap
    for (auto [key, value] : mymulmap) {
        std::cout << key <<":"<<value<<",";
    }
    std::cout << "\n";
    cout<<mymulmap.count("aa");
}
