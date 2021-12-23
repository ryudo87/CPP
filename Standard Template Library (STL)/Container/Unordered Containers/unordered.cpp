
int main() {
    unordered_set<string> c;
    char buf[10];
    for (int i=0;i<100;++i) {
        snprintf(buf, 10, "%d", rand());
        c.insert(string(buf));
    }
    
    cout<<"unordered_set.size()="<<c.size()<<endl;
    cout<<"unordered_set.max_size()="<<c.max_size()<<endl;
    cout<<"unordered_set.bucket_count()="<<c.bucket_count()<<endl;
    cout<<"unordered_set.max_bucket_count()="<<c.max_bucket_count()<<endl;
    cout<<"unordered_set.load_factor()="<<c.load_factor()<<endl;
    cout<<"unordered_set.max_load_factor()="<<c.max_load_factor()<<endl;
    
    for (int i=0;i<c.bucket_count();++i) {
        cout<<"unordered_set.bucket_size("<<i<<")="<<c.bucket_size(i)<<endl;
    }
}
