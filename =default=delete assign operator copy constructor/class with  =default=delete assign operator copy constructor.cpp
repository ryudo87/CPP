class Zoo
{
public:
    Zoo(int i){}
    Zoo()=default;//use compiler's default constructor
    Zoo(const Zoo&)=delete;
    Zoo(Zoo&&)=default;
    Zoo& operator=(const Zoo&)=default;d
    Zoo& operator=(const Zoo&&)=delete;
    ~Zoo()=default;
};
