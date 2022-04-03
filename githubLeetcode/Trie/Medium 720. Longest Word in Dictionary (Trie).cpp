class Solution {//Brute Force: for every word, check every of its prefixes
public:
    string longestWord(vector<string>& words) {
        string best;
        unordered_set<string> dict(words.begin(), words.end());
        
        for (const string& word : words) {
            if (word.length() < best.length()) continue;
            if (word.length() == best.length() && word>best) continue;
            
            string prefix;
            bool valid = true;
            for(int i=0;i<word.length()-1;++i) {
                prefix += word[i];
                if (0 == dict.count(prefix)) {
                    valid = false;
                    break;
                }
            }
            if (valid) best = word;
        }
        
        return best;
    }
};


class Solution {//Sort first
public:
    string longestWord(vector<string>& words) {
        //sort by length DESC, if same , sort by lexical order
        std::sort(words.begin(), words.end(),
                  [](const string& w1, const string& w2){
                      if (w1.length() == w2.length()) return w1<w2;
                      return w1.length() > w2.length();
                  });
        
        unordered_set<string> dict(words.begin(), words.end());
        for (const string& word : words) {
            string prefix;
            bool valid = true;
            for(int i=0;i<word.length()-1;++i) {
                prefix += word[i];
                if (0 == dict.count(prefix)) {
                    valid = false;
                    break;
                }
            }
            if (valid) return word;
        }
        
        return "";
    }
};




//Trie: for every word : Time: O(w1+w2+...wn) Space: O(26*n*w)
//leetcode 208 Implement Trie

class Solution {//Trie + Sort
    class Trie {
        struct TrieNode {
            TrieNode():is_word(false), children(26, nullptr){}
            ~TrieNode() {
                for (auto node : children) delete node;
            }
            bool is_word;
            vector<TrieNode*> children;
        };
        
        std::unique_ptr<TrieNode> root_;
    public:
        Trie(): root_(std::make_unique<TrieNode>()) {}
        
        void insert(const string& word) {
            TrieNode* p = root_.get();
            for (const char c:word) {
                if (!p->children[c-'a']) p->children[c-'a'] = new TrieNode();
                p=p->children[c-'a'];
            }
            p->is_word = true;
        }
        
        bool hasAllPrefixes(const string& word) {
            const TrieNode* p = root_.get();
            for (const char c: word) {
                if (nullptr == p->children[c-'a']) return false;
                p = p->children[c-'a'];
                if (false == p->is_word) return false;
            }
            return true;
        }
    };//end Class Trie
    
    
public:
    string longestWord(vector<string>& words) {
        //sort by length DESC, if same , sort by lexical order
        std::sort(words.begin(), words.end(),
                  [](const string& w1, const string& w2){
                      if (w1.length() == w2.length()) return w1<w2;
                      return w1.length() > w2.length();
                  });
        
        Trie trie;
        for (const string& word : words) trie.insert(word);
        for (const string& word : words)
            if (trie.hasAllPrefixes(word)) return word;
        
        return "";
    }
};

