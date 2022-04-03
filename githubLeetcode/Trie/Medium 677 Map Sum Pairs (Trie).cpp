/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */


//Hash table solution
// 建立前缀和一个pair之间的映射，这里的pair的第一个值表示该词的值，第二个值表示将该词作为前缀的所有词的累加值，那么我们的sum函数就异常的简单了，直接将pair中的两个值相加即可。

// 首先我们suppose原本这个key是有值的，我们更新的时候只需要加上它的差值即可，就算key不存在默认就是0，算差值也没问题。然后我们将first值更新为val，然后就是遍历其所有的前缀了，给每个前缀的second都加上diff即可

class MapSum {
    unordered_map<string, int> _key2vals;
    unordered_map<string, int> _prefix2sum;
public:
    /** Initialize your data structure here. */
    MapSum() {}
    
    void insert(string key, int val) {
        int diff = val - _key2vals[key];
        _key2vals[key] = val;
        for (int len=1;len<=key.length();++len) {
            _prefix2sum[key.substr(0, len)] += diff;
        }
    }
    
    int sum(string prefix) {
        return _prefix2sum[prefix];
    }
};



//Trie by shared_ptr
class MapSum {
public:
    MapSum() {
        root = make_shared<TrieNode>();
    }
    void insert(string key, int val) {
        int inc = val - vals_[key];//vals_[key] is old,  by default value is 0
        vals_[key] = val;//update vals_[key]
        shared_ptr<TrieNode> p(root);
        for (const char c:key) {
            if (nullptr == p->children[c]) p->children[c] = std::make_shared<TrieNode>();
            p->children[c]->sum += inc;
            p = p->children[c];
        }
    }
    
    int sum(string prefix) {
        shared_ptr<TrieNode> p (root);
        for (const char c:prefix) {
            if (nullptr == p->children[c]) return 0;
            p = p->children[c];
        }
        return p->sum;
    }
private:
    struct TrieNode {
        TrieNode():children(128), sum(0){}
        ~TrieNode() {}
        vector<shared_ptr<TrieNode>> children;
        int sum;
    };
    
    shared_ptr<TrieNode> root;
    unordered_map<string, int> vals_; //key -> val
};


//Trie

class MapSum {
public:
    MapSum() {
        
    }
    void insert(string key, int val) {
        int inc = val - vals_[key];//vals_[key] is old,  by default value is 0
        vals_[key] = val;//update vals_[key]
        TrieNode* p = &root;
        for (const char c:key) {
            if (nullptr == p->children[c]) p->children[c] = new TrieNode();
            p->children[c]->sum += inc;
            p = p->children[c];
        }
    }
    
    int sum(string prefix) {
        TrieNode* p = &root;
        for (const char c:prefix) {
            if (nullptr == p->children[c]) return 0;
            p = p->children[c];
        }
        return p->sum;
    }
private:
    struct TrieNode {
        TrieNode():children(128, nullptr), sum(0){}
        ~TrieNode() {
            for (TrieNode* child : children) {
                if (child) delete child;
            }
        }
        vector<TrieNode*> children;
        int sum;
    };
    
    TrieNode root;
    unordered_map<string, int> vals_; //key -> val
};
