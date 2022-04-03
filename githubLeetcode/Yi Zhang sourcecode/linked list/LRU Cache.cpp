
//http://blog.csdn.net/doc_sgl/article/details/15378513

使用map+双向链表，复杂度是O(logN)

链表头部的表示刚刚访问过的，链表尾部的表示很久之前访问的

每次get(key)，先在map中找到这个节点，然后把这个节点放到链表头部。

每次set(key, value)，现在map中找这个节点，如果有的话就把这个节点放到链表头部，如果没有就看看cache空间是否已经满了，size>=capacity，如果未满，就生成一个新的节点放到链表头部，如果满了，就生成一个新的节点放到链表头部并且删除链表尾部的一个节点。



struct node{
	node* pre;
	int key;
	int value;
	node* next;
	node(int k, int v):key(k),value(v),pre(NULL),next(NULL){};
};

class LRUCache{
	unordered_map<int, node*> mp;
	int capacity;
	int size;
	node* head;
	node* tail;
public:
  LRUCache(int c){
    if(c<0)return;
    head = new node(-1,-1);
    tail = new node(-1,-1);
    head->next = tail;
    tail->pre = head;
    mp.clear();
    capacity = c;
    size = 0;
  }
  
  int get(int k) {
    unordered_map<int, node*>::iterator it = mp.find(k);
    if(it != mp.end()){
      node* p = it->second;
      p->pre->next = p->next;
      p->next->pre = p->pre;
      putToHead(p);
      return p->value;
    }
    else
      return -1;
  }
  
  void set(int k, int val) {
    if(capacity < 1) return;
    unordered_map<int, node*>::iterator it = mp.find(k);
    if(it != mp.end()){
      node* p = it->second;
      p->pre->next = p->next;
      p->next->pre = p->pre;
      putToHead(p);
      p->value = val;
    }else{
      node* p = new node(k, val);
      putToHead(p);
      mp[k] = p;
      size++;
      if(size>capacity){
        p = tail->pre;
        tail->pre = p->pre;
        p->pre->next = tail;
        it = mp.find(p->key);
        mp.erase(it);
        delete p;
      }
    }
  }
  
  void putToHead(node* p)
  {
    p->next = head->next;
    p->pre = head;
    head->next->pre = p;
    head->next = p;
  }
};










http://fisherlei.blogspot.com/2013/11/leetcode-lru-cache-solution.html

[Thoughts]

首先，对于cache，如果希望有O(1)的查找复杂度，肯定要用hashmap来保存key和对象的映射。对于LRU而言，问题在于如何用O(1)解决cache entry的替换问题。

简单的说，cache的存储是一个链表的话，那么只要保证从头到尾的顺序就是cache从新到旧的顺序就好了，对于任何一个节点，如果被访问了，那么就将该节点移至头部。如果cache已满，那么就把尾部的删掉，从头部插入新节点。

所以，需要用到两个数据结构

1. hashmap， 保存key和对象位置的映射

2. list，保存对象新旧程度的序列。不一定是list，也可以用vector，不过list的好处是已经实现了头尾操作的api，vector的话，还要自己写，麻烦。








// http://www.cnblogs.com/TenosDoIt/p/3417157.html