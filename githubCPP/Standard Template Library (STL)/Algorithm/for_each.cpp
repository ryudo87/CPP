template <typename InputIterator, typename Function>
Function my_for_each(InputIterator first, InputIterator last, Function f){
    for (;first!=last;++first){
        f(*first);
    }
    return f;
}

struct mystruct {
    void operator()(double x){cout<<" "<<x;}
} myobj;

void myfunc(double x) {cout<<" "<<x;}

int main()
{
    list<double> v {3.0, 6, 12.5};
    //copy(v.begin(), v.end(), ostream_iterator<double>(cout, ","));
    
    for_each(v.begin(), v.end(), myfunc);
    cout<<endl;
    for_each(v.begin(), v.end(), myobj);
    cout<<endl;
    for_each(v.begin(), v.end(), mystruct());
    
    
}

