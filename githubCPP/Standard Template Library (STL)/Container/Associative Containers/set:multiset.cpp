int main() {
    set<string> myset;
    myset.insert("aa");//call RB_tree insert_unique()
    
    unordered_set<int> inset {4, 3, 5, 3};
    inset.insert(-2);
    cout<<inset.count(3)<<endl;
    
    
    
    multiset<string> mymulset;
    mymulset.insert("aa");//call RB_tree insert_equal()
    mymulset.insert("aa");
    
    for (auto str : mymulset) {
        std::cout << str <<", ";
    }
    std::cout << "\n";
    cout<<mymulset.count("aa");
}
