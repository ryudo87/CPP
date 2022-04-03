template <typename InputIterator, typename T, typename BinaryOperation>
T my_accumulate(InputIterator first, InputIterator last, T init, BinaryOperation binary_op){
    for (;first!=last;++first){
        init = binary_op(init, *first);//callable entity
    }
    return init;
}

struct mystruct {
    double operator()(double x, double y){return x+2*y;}
};
double myfunc(double x, double y) {return x+y;}
int main()
{
    list<double> v {3.0, 6, 12};
    copy(v.begin(), v.end(), ostream_iterator<double>(cout, ","));
    
    double init=0;
    cout<<accumulate(v.begin(), v.end(), init)<<endl;
    cout<<accumulate(v.begin(), v.end(), init, minus<double>())<<endl;
    cout<<accumulate(v.begin(), v.end(), init, myfunc)<<endl;
    cout<<accumulate(v.begin(), v.end(), init, mystruct())<<endl;//function object
    
}

