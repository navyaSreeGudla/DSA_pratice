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
    int dfs(TreeNode*root,int maxSoFar){
        if(root==NULL){
            return 0;
        }
        int count = 0;
        if(root->val>=maxSoFar){
            count++;
        }
        maxSoFar = max(root->val,maxSoFar);
        return count+dfs(root->left,maxSoFar)+dfs(root->right,maxSoFar);
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        return dfs(root,root->val);
    }
};
