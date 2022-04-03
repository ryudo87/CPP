
//Submission Result: Accepted

vector<TreeNode *> genSubTree(int start, int end) {
  vector<TreeNode *> result ;
  if (start > end) {
    result.push_back(NULL);
    return result;
  }
  for (int root=start; root<=end; ++root) {
    vector<TreeNode *> vec_left = genSubTree(start, root-1);
    vector<TreeNode *> vec_right = genSubTree(root+1, end);
    
    for (int i=0; i<vec_left.size(); ++i) {
      
      for (int j=0; j<vec_right.size(); ++j) {
        TreeNode* tmp = new TreeNode(root);
        
        tmp->left = vec_left[i];
        tmp->right = vec_right[j];
        result.push_back(tmp);
      }
    }
  }
  
  return result;
}

vector<TreeNode *> generateTrees(int n) {
  vector<TreeNode *> result = genSubTree(1, n);
  return result;
}

/**
 * Definition for binary tree
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; left = null; right = null; }
 * }
 */
//public class Solution {
//  public ArrayList<TreeNode> generateTrees(int n) {
//    return dfs(1,n);
//  }
//  private ArrayList<TreeNode> dfs(int start,int end){
//    ArrayList<TreeNode> result = new ArrayList<>();
//    if(start>end){
//      result.add(null);
//      return result;
//    }
//    for(int i=start;i<=end;i++){
//      ArrayList<TreeNode> lefts = dfs(start,i-1);
//      ArrayList<TreeNode> rights = dfs(i+1,end);
//      for(TreeNode left:lefts){
//        for(TreeNode right:rights){
//          TreeNode node = new TreeNode(i);
//          node.left = left;
//          node.right = right;
//          result.add(node);
//        }
//      }
//    }
//    return result;
//  }
//}
