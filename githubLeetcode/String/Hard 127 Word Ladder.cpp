
//old 2019, better
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;
        
        queue<string> q{{beginWord}};
        int level = 0;
        while (!q.empty()) {
            ++level;
            for (int k = q.size(); k > 0; --k) {
                string word = q.front(); q.pop();
                if (word == endWord) return level; // reach the end, return
                for (int i = 0; i < word.size(); ++i) {
                    string newWord = word;
                    // try 'a' to 'z'
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        newWord[i] = ch;
                        if (wordSet.count(newWord) && newWord != word) {
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
            }
        }
        return 0;
    }
};

////
class Solution {//BFS (shortest path)  O(n*26^l) l=len(word)
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (wordList.size() == 0) return 0;
        unordered_set<string> dict(wordList.begin(), wordList.end());//also dedup
        if (0==dict.count(endWord)) return 0; // endWord must be in dict
        
        queue<string> q;
        unordered_map<string, int> word2ChangeIndex;//record this word is from which char
        word2ChangeIndex[beginWord] = -1;
        q.push(beginWord);
        
        int step = 0;
        while (!q.empty()) {
            ++step;
            for (int size=q.size();size>0;--size) {
                string currentWord = q.front(); q.pop();
                int loc = word2ChangeIndex[currentWord];
                for (int i=0;i<currentWord.size();++i) {
                    if (i == loc) continue;
                    string tempWord = currentWord;
                    for (int j='a';j<='z';++j) {//at i, try a->z
                        tempWord[i] = j;
                        
                        if (tempWord==endWord) return step+1;//found solution
                        if (0 == dict.count(tempWord)) continue;//not in dict
                        
                        word2ChangeIndex[tempWord] = i;
                        dict.erase(tempWord);//shouldn't reuse word
                        q.push(tempWord);
                    }
                }
            }
        }
        
        //not found return 0
        return 0;
    }
};
