template<typename T>
struct _list_node {
    _list_node<T>* prev;
    _list_node<T>* next;
    T data;
};
template<typename T>
class MyList {
protected:
    _list_node<T>* node;
};
template<typename T>
struct _list_iterator {
    _list_node<T>* node;
    
    T& operator*() const {return node->data;}
    T* operator->() const {return &(operator*());}
    
    _list_iterator<T>& operator++() //prefix ++
    {node = node->next;return *this;}
    _list_iterator<T>  operator++(int) //postfix
    {auto myself (*this); ++*this; return myself;}
};


int main() {
    
    list<char> l;
    list<char>::iterator it=l.insert(l.begin(),'b');
    cout<<*it<<endl;
    l.insert(l.begin(),'a');
    l.insert(l.end(),2,'c');
    std::copy(l.begin(), l.end(), std::ostream_iterator<char>(std::cout, ","));
    
    string s="dong";
    l.insert(l.end(),s.begin(),s.end());
}
