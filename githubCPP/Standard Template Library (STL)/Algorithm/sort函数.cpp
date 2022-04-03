//only list, forward_list has member function sort()

class B
{
public:
    int b;
    B(int c): b(c){}
    bool operator<(const B& rhs) const
    {
        return b<rhs.b;
    }
};
bool comp(const B& b1, const B& b2)
{
    return b1.b<b2.b;
}
bool comp2(B b1, B b2)
{
    return b1.b<b2.b;
}
//但sort是不支持使用类的成员函数来做比较函数的。
int main()
{
    vector<B> vec {B(3), B(1), B(2)};
    
    sort(vec.begin(),vec.end());
    sort(vec.begin(),vec.end(), comp);
    sort(vec.begin(),vec.end(), [](B b1, B b2){return b1.b > b2.b;});
    
    for(int i=0;i<vec.size();i++)
        cout<<vec[i].b<<endl;
}



bool funcObj(double value) {return value > 3;}
int main()
{
    vector<double> v {3.0, 6, 12.5, 1.9, 2.99, 5};
    cout<<count_if(v.begin(), v.end(), funcObj)<<endl;
    //用户自定义的 function object ，定义了元素被计数需满足的条件。 只带一个参数，返回 true 或 false.
    int target = 2;
    cout<<count_if(v.begin(), v.end(), [&target](double value){++target; return value > 3;})<<endl;
    cout<<" target="<<target<<endl;
}
