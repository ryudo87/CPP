template <typename T, class Sequence=deque<T>>
class STLStack {
    Sequence c;
public:
    typedef typename Sequence::value_type value_type;
    typedef typename Sequence::size_type  size_type;
    typedef typename Sequence::reference  reference;
    typedef typename Sequence::const_reference const_reference;
    
    size_type size() const {return c.size();}
    reference top() {return c.back();}
    const_reference top() const {return c.back();}
    void push(const value_type& x) {c.push_back(x);}
    void pop(){c.pop_back();}
    bool empty() const {return c.empty();}
};

int main() {
    //stack can use list/deque/vector as underlying structure
    stack<string, list<string>> listStack;
    stack<string, deque<string>> dequeStack;
    stack<string, vector<string>> vectorStack;
    //queue can use list/deque as underlying structure
    queue<string, list<string>> listQueue;
    queue<string, deque<string>> dequeQueue;
    //
    //queue<string, vector<string>> vectorQueue;//not ok with pop()
    //vectorQueue.push("aa");
    //vectorQueue.pop();//error: no member named 'pop_front' in 'std::vector'
}
