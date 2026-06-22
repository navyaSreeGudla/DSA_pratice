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
private:
void serializeHelper(TreeNode*node,string &s){
    if(node==NULL){
        s = s+"N,";
        return;
    }
    s = s+to_string(node->val)+",";
    serializeHelper(node->left,s);
    serializeHelper(node->right,s);
}
TreeNode*deserializeHelper(stringstream& ss){
    string val;
    getline(ss,val,',');
    if(val=="N"){
        return NULL;
    }
    TreeNode*node = new TreeNode(stoi(val));
    node->left = deserializeHelper(ss);
    node->right = deserializeHelper(ss);
    return node;
}
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};
