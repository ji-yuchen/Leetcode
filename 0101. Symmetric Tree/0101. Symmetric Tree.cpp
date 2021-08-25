/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
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
/*
Recursive
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return root == NULL || isSymmetricHelp(root->left, root->right);
    }
    bool isSymmetricHelp(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left==right;
        }
        if(left->val!=right->val){
            return false;
        }
        return isSymmetricHelp(left->left, right->right) && isSymmetricHelp(left->right, right->left);
    }
};

/*
Iteration
*/
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* left, * right;
        if(!root)
            return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while(!q1.empty() && !q2.empty()){
            left = q1.front();
            q1.pop();
            right = q2.front();
            q2.pop();
            if(left == NULL && right == NULL){
                continue;
            }
            if(left == NULL || right == NULL){
                return false;
            }
            if(left->val != right->val){
                return false;
            }
            //equal val
            q1.push(left->left);
            q1.push(left->right);
            q2.push(right->right);
            q2.push(right->left);
        }
        return true;
    }
