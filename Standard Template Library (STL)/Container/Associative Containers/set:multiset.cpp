int main() {
    set<string> myset; multiset<string> mymulset;
    myset.insert("aa");//call RB_tree insert_unique()
    mymulset.insert("aa");//call RB_tree insert_equal()
    mymulset.insert("aa");
    
    for (auto str : mymulset) {
        std::cout << str <<", ";
    }
    std::cout << "\n";
    cout<<mymulset.count("aa");
}
