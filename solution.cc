// Given a binary tree, return the postorder traversal of its nodes' values.

// For example:
// Given binary tree {1,#,2,3},
//    1
//     \
//      2
//     /
//    3
// return [3,2,1].

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode*> myStack;
        TreeNode *cur = root, *prev = NULL;
        while(cur || !myStack.empty()) {
            if(cur) {
                if(!cur->left && !cur->right) {
                    res.push_back(cur->val);
                    prev = cur;
                    cur = NULL;
                } else {
                    myStack.push(cur);
                    if(cur->right) myStack.push(cur->right);
                    cur = cur->left;
                }
            } else {
                cur = myStack.top();
                myStack.pop();
                if(prev && (prev == cur->left || prev == cur->right)) {
                    res.push_back(cur->val);
                    prev = cur;
                    cur = NULL;
                } 
            }
        }
        return res;
    }
};
