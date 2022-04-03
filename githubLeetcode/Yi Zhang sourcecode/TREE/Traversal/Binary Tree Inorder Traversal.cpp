//Binary Tree Inorder Traversal Total Accepted: 16886 Total Submissions: 48552 My Submissions
//Given a binary tree, return the inorder traversal of its nodes' values.
//
//For example:
//Given binary tree {1,#,2,3},
//1
//\
//2
///
//3
//return [1,3,2].
//
//Note: Recursive solution is trivial, could you do it iteratively?
//
//confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//
//
//OJ's Binary Tree Serialization:
//The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
//
//Here's an example:
//1
/// \
//2   3
///
//4
//\
//5
//The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".




    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> sk;
        TreeNode* p=root;
        while(p || !sk.empty()){
            while(p){
                sk.push(p);
                p=p->left;
            }
            p=sk.top();sk.pop();
            res.push_back(p->val);
            p=p->right;
        }

        return res;
    }
