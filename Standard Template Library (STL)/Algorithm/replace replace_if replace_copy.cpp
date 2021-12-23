namespace {
    template <typename InputIterator, typename T>
    void replace(InputIterator first, InputIterator last, const T& old_value, const T& new_value){
        for (;first!=last;++first){
            if (*first == old_value) *first = new_value;
        }
    }
    
    template <typename InputIterator, typename Predicate, typename T>
    void replace_if(InputIterator first, InputIterator last, Predicate pred, const T& new_value){
        for (;first!=last;++first){
            if (pred(*first))   *first = new_value;
        }
    }
}

bool myfunc(double x) {return x>11;}

int main()
{
    list<double> v {3.0, 6, 12.5};
    
    std::replace(v.begin(), v.end(), 6.0, 9.9);
    copy(v.begin(), v.end(), ostream_iterator<double>(cout, ","));cout<<endl;
    std::replace_if(v.begin(), v.end(), myfunc, 44.4);
    copy(v.begin(), v.end(), ostream_iterator<double>(cout, ","));cout<<endl;
    
    list<double> newList(5, 0);
    std::replace_copy(v.begin(), v.end(), newList.begin(), 44.4, 78.2);
    copy(newList.begin(), newList.end(), ostream_iterator<double>(cout, ","));cout<<endl;
}

