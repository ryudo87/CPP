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
    
    
}
