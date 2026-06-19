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

class Solution {
public:
    bool dfs(TreeNode*root,long long low,long long high){
        if(root==NULL){
            return true;
        }
        if(root->val<=low || root->val>=high){
            return false;
        }
        return dfs(root->right,root->val,high) && dfs(root->left,low,root->val);
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return root;
        }
        return dfs(root,LLONG_MIN,LLONG_MAX);
    }
};
