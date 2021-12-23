//only list, forward_list has member function sort()

bool greater10(double value) {return value > 3;}
int main()
{
    vector<double> v {3.0, 6, 12.5, 1.9, 2.99, 5};
    cout<<count_if(v.begin(), v.end(), greater10)<<endl;//用户自定义的 function object ，定义了元素被计数需满足的条件。 只带一个参数，返回 true 或 false.
    
    //sort() cannot apply to list<>
    sort(v.begin(), v.end(), greater<double>());
    copy(v.begin(), v.end(), ostream_iterator<double>(cout, ","));
}

