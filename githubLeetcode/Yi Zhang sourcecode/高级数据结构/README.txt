I moved the declarations(.h) of Trie and the definitions of member functions into .cpp files for your convinence. 

The differnces between the two files are:
1in Trie_no_string.cpp I used string  instead of char array to store results. 
2in  Trie_no_string.cpp, the return value is the array of char array(char**) 
while in Trie_use_string.cpp it is the actual number of words and the result array is passed in by the caller. 
3 in  Trie_no_string.cpp, the macro MAX_WORD_LEN defines the maximum length of a word.
in Trie_use_string.cpp, the maximum length of a word is limited by string type.

This Trie structure saves space because each node does not contain all 26 pointers. Instead a pointer sibling is added
to each node pointing to its next node. In each level the nodes are sorted alphabetically.

The max number of words can be specified as an argument in search function. 
I used recursion similar to DFS to search for words in alphabetical order which may consume more memory or cause 
stack overflow. Another way to do the search is to mark each node after we visit it. 

