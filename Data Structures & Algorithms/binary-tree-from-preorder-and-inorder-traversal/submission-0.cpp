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
    int pre_idx =0;
    unordered_map<int,int>mp;
    TreeNode*dfs(vector<int>&preorder,int l,int r){
        if(l>r){
            return NULL;
        }
        TreeNode*root = new TreeNode(preorder[pre_idx]);
        int mid = mp[preorder[pre_idx]];
        pre_idx++;
        root->left = dfs(preorder,l,mid-1);
        root->right = dfs(preorder,mid+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // first node in the preorder shows the root of th tree ..
        //the position of this preorder is the inorder shows the left and right subtree
        int n = inorder.size();
        for(int i =0;i<n;i++){
            mp[inorder[i]]=i;
        }  
        return dfs(preorder,0,preorder.size()-1);
    }
};
