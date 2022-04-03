
int main() {
    vector<double> v{11.2, 29.2, 2.3, 0.5, -1.3};
    sort(v.begin(), v.end(), less<double>());
    copy(v.begin(), v.end(), ostream_iterator<double>(cout, " "));cout<<endl;
    
    cout<<binary_search(v.begin(), v.end(), 11.2)<<endl;
    vector<double>::iterator it = lower_bound(v.begin(), v.end(), 11.2);
    std::cout << *it;
    it = upper_bound(v.begin(), v.end(), 11.2);
    std::cout << *it;
    
    cout<<"distance="<<distance(v.begin(), it)<<endl;
    cout<<"(it-v.begin())="<<(it-v.begin())<<endl;
    
    
}
