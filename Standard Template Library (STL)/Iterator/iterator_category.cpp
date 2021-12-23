//5 iterator category
// namespace {
// struct input_iterator_tag {};
// struct output_iterator_tag {};
// struct forward_iterator_tag : public input_iterator_tag {};
// struct bidirectional_iterator_tag : public forward_iterator_tag {};
// struct random_access_iterator_tag : public bidirectional_iterator_tag {};
// }
void _display_category(random_access_iterator_tag) {cout<<"random_access_iterator"<<endl;}
void _display_category(bidirectional_iterator_tag) {cout<<"bidirectional_iterator_tag"<<endl;}
void _display_category(forward_iterator_tag) {cout<<"forward_iterator_tag"<<endl;}
void _display_category(output_iterator_tag) {cout<<"output_iterator_tag"<<endl;}
void _display_category(input_iterator_tag) {cout<<"input_iterator_tag"<<endl;}

template<typename IteratorType>
void display_category(IteratorType itr) {
    typename iterator_traits<IteratorType>::iterator_category cagy;
    cout<<"typeid(itr).name()="<<typeid(itr).name()<<"--";
    _display_category(cagy);
}

int main() {
    display_category(array<int, 10>::iterator());
    
    cout<<endl;
    _display_category(vector<int>::iterator::iterator_category());
    _display_category(deque<int>::iterator::iterator_category());
    _display_category(list<int>::iterator::iterator_category());
    
    cout<<endl;
    _display_category(set<int>::iterator::iterator_category());
    _display_category(multiset<int>::iterator::iterator_category());
    _display_category(map<int, int>::iterator::iterator_category());
    _display_category(multimap<int, int>::iterator::iterator_category());
    
    cout<<endl;
    _display_category(unordered_set<int>::iterator::iterator_category());
    _display_category(unordered_multiset<int>::iterator::iterator_category());
    _display_category(unordered_map<int, int>::iterator::iterator_category());
    _display_category(unordered_multimap<int, int>::iterator::iterator_category());
    
    cout<<endl;
    _display_category(istream_iterator<int>::iterator_category());
    _display_category(ostream_iterator<int>::iterator_category());
    display_category(ostream_iterator<int>(cout,""));
    
    
    
}
