/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
A leaf is a node with no children.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*DFS recursive*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        if(!root->left && !root->right &&root->val == targetSum)
            return true;
        return hasPathSum(root->left, (targetSum-root->val)) || hasPathSum(root->right, (targetSum-root->val));
    }
};

/*iteration*/
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        stack<TreeNode*> temp;
        temp.push(root);
        while(!temp.empty()){
            TreeNode* cur = temp.top();
            temp.pop();
            if(!cur->left && !cur->right){
                if(cur->val == targetSum)
                    return true;
            }
            if(cur->right){
                cur->right->val += cur->val;
                temp.push(cur->right);
            }
            if(cur->left){
                cur->left->val += cur->val;
                temp.push(cur->left);
            }
        }
        return false;
    }
};
