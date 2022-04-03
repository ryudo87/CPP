
int main() {
    deque<int> de{1,2,3,4};
    cout<<de[1]<<endl;
    cout<<de.front()<<endl;
    cout<<de.back()<<endl;
    cout<<de.size()<<endl;
    cout<<de.empty()<<endl;
    
    deque<int>::iterator it = de.begin();
    it+=3;
    cout<<*it<<endl;
    it+=1;
    if (it!=de.end()) {
        cout<<"it!=de.end()"<<endl;
        cout<<*it<<endl;
    }
}
