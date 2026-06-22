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

class Codec {
public:
    
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string>res;
        dfsSerialize(root,res);
        return join(res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string>ans = split(data);
        int i =0;
        return dfsDeserialize(i,ans);

    }
private:
 void dfsSerialize(TreeNode*node,vector<string>& res){
    if(node==NULL){
        res.push_back("N");
        return;
    }
    res.push_back(to_string(node->val));
    dfsSerialize(node->left,res);
    dfsSerialize(node->right,res);
 }
 TreeNode* dfsDeserialize(int& i,vector<string>& ans){
   if(ans[i]=="N"){
    i++;
    return NULL;
   }
   TreeNode*node = new TreeNode(stoi(ans[i]));
   i++;
   node->left = dfsDeserialize(i,ans);
   node->right = dfsDeserialize(i,ans);
   return node;
 }
 vector<string> split(string s){
    vector<string>ans;
    stringstream ss(s);
    string token;
    while(getline(ss,token,',')){
        ans.push_back(token);
    }
    return ans;
 }
 string join(vector<string>ans){
    if(ans.size()==0){
        return "";
    }
    int n = ans.size();
    string s = ans[0];
    for(int i =1;i<n;i++){
        s = s+","+ans[i];
    }
    return s;
 }
};
