Analysis:
At the first look, this problem seems wired. Remind the Copy Constructor of a class object, when the class member contains pointers, the direct copy is shadow, we need deep copy. For this problem, there are two major tasks:
(1)  Traverse the graph
(2)  Construct the new graph at the same time.

Traverse the graph is similar to the tree traversal, both DFS and  BFS can be used. Slight difference  is to consider the loop in the graph (e.g., the 2-->2 in the above figure), thus we need store the visited vertex information. If the neighbor of current node has not been visited, then search that node.

Only one point should be noticed for constructing the new graph, in the code below, I used a map< int, node*> to store the visited information, so that if the node has been visited, just add the map[int] to the current node's neighbor list. Be careful the current node is the node you "newed", but not the node in the original graph (line 12 and 13 in the code below. If you set visited[v->label] = v, it is not correct.).




这里使用深度优先搜索。这样可以递归实现，如果是宽度优先，就要额外使用queue容器。
关键点：
1 这里的clone需要深度拷贝，就是要使用new操作了
2 防止回路无限循环，就要使用hash表，这里使用unordered_map记录访问过的节点。因为这里的label应该是唯一的才对，所以可以直接使用label作为关键字就可以。


#include <unordered_map>
struct UndirectedGraphNode {
  int label;
  vector<UndirectedGraphNode* > neighbors;
  UndirectedGraphNode(int x) : label(x) {};
};
class Solution {
public:
  UndirectedGraphNode* dfs(UndirectedGraphNode *v, map<int, UndirectedGraphNode*> &visited){
    UndirectedGraphNode* res = new UndirectedGraphNode(v->label);
    visited[v->label]=res;
    for (int i=0;i<v->neighbors.size();i++){
      if (!visited[v->neighbors[i]->label]){
        res->neighbors.push_back(dfs(v->neighbors[i],visited));
      }else{
        res->neighbors.push_back(visited[v->neighbors[i]->label]);
      }
    }
    return res;
  }
  
  UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    if (node==NULL){
      return NULL;
    }
    
    map<int, UndirectedGraphNode*> visited;
    UndirectedGraphNode* res = dfs(node, visited);
    return res;
  }
};




